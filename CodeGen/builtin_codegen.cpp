#include "codegen.h"

using namespace llvm;

namespace {


bool isComplex32(Type *ty) {
    if (auto *st = llvm::dyn_cast<llvm::StructType>(ty)) {
        return st->getNumElements() == 2 &&
               st->getElementType(0)->isFloatTy() &&
               st->getElementType(1)->isFloatTy();
    }
    return false;
}

bool isComplex64(Type *ty) {
    if (auto *st = llvm::dyn_cast<llvm::StructType>(ty)) {
        return st->getNumElements() == 2 &&
               st->getElementType(0)->isDoubleTy() &&
               st->getElementType(1)->isDoubleTy();
    }
    return false;
}

Value* toDouble(CodeGen &cg, Value *v) {
    if (!v) return nullptr;
    Type *ty = v->getType();
    auto &B = cg.builder;

    if (ty->isDoubleTy()) return v;
    if (ty->isFloatTy())  return B.CreateFPExt(v, Type::getDoubleTy(cg.ctx));
    if (ty->isIntegerTy() && ty->getIntegerBitWidth() > 1) {
        // Treat as signed int for now
        return B.CreateSIToFP(v, Type::getDoubleTy(cg.ctx));
    }

    errs() << "toDouble: unsupported type\n";
    return nullptr;
}

Value* promoteToC64(CodeGen &cg, Value *z) {
    if (!z) return nullptr;
    Type *ty = z->getType();
    auto &B = cg.builder;

    if (isComplex64(ty)) {
        return z;
    }
    if (!isComplex32(ty)) {
        errs() << "promoteToC64: not a complex type\n";
        return nullptr;
    }

    // z : {float, float}  -> {double, double}
    Value *re_f = B.CreateExtractValue(z, {0});
    Value *im_f = B.CreateExtractValue(z, {1});

    Value *re_d = B.CreateFPExt(re_f, Type::getDoubleTy(cg.ctx));
    Value *im_d = B.CreateFPExt(im_f, Type::getDoubleTy(cg.ctx));

    llvm::StructType *c64Ty = llvm::StructType::get(
        cg.ctx,
        {Type::getDoubleTy(cg.ctx), Type::getDoubleTy(cg.ctx)}
    );

    Value *undef = UndefValue::get(c64Ty);
    undef = B.CreateInsertValue(undef, re_d, {0});
    undef = B.CreateInsertValue(undef, im_d, {1});
    return undef;
}

Value* demoteFromC64(CodeGen &cg, Value *res64, Type *origTy) {
    auto &B = cg.builder;
    if (isComplex64(origTy)) {
        return res64;
    }
    if (!isComplex32(origTy)) {
        errs() << "demoteFromC64: orig type not complex32\n";
        return nullptr;
    }

    // res64: {double,double} -> {float,float} but as origTy
    Value *re_d = B.CreateExtractValue(res64, {0});
    Value *im_d = B.CreateExtractValue(res64, {1});

    Value *re_f = B.CreateFPTrunc(re_d, Type::getFloatTy(cg.ctx));
    Value *im_f = B.CreateFPTrunc(im_d, Type::getFloatTy(cg.ctx));

    Value *undef = UndefValue::get(origTy);
    undef = B.CreateInsertValue(undef, re_f, {0});
    undef = B.CreateInsertValue(undef, im_f, {1});
    return undef;
}

Value* callUnaryF64(CodeGen &cg, const char *fname, Value *arg) {
    if (!arg) return nullptr;
    Value *d = toDouble(cg, arg);
    if (!d) return nullptr;

    auto &B = cg.builder;
    LLVMContext &ctx = cg.ctx;
    Module &M = *cg.mod;

    Type *f64 = Type::getDoubleTy(ctx);
    FunctionType *FT = FunctionType::get(f64, {f64}, false);
    FunctionCallee F = M.getOrInsertFunction(fname, FT);

    return B.CreateCall(F, {d});
}

Value* callBinaryF64(CodeGen &cg, const char *fname, Value *a, Value *b) {
    if (!a || !b) return nullptr;
    Value *ad = toDouble(cg, a);
    Value *bd = toDouble(cg, b);
    if (!ad || !bd) return nullptr;

    auto &B = cg.builder;
    LLVMContext &ctx = cg.ctx;
    Module &M = *cg.mod;

    Type *f64 = Type::getDoubleTy(ctx);
    FunctionType *FT = FunctionType::get(f64, {f64, f64}, false);
    FunctionCallee F = M.getOrInsertFunction(fname, FT);

    return B.CreateCall(F, {ad, bd});
}

// |z| for complex
Value* magnitudeComplex(CodeGen &cg, Value *z) {
    if (!z) return nullptr;
    Type *origTy = z->getType();
    if (!isComplex32(origTy) && !isComplex64(origTy)) {
        errs() << "magnitude(): argument is not complex\n";
        return nullptr;
    }

    auto &B = cg.builder;
    LLVMContext &ctx = cg.ctx;
    Module &M = *cg.mod;

    Value *z64 = promoteToC64(cg, z);
    if (!z64) return nullptr;

    Type *c64Ty = z64->getType();
    Type *f64 = Type::getDoubleTy(ctx);

    FunctionType *FT = FunctionType::get(f64, {c64Ty}, false);
    FunctionCallee F = M.getOrInsertFunction("aft_mag_c64", FT);

    return B.CreateCall(F, {z64});
}
Value* argComplex(CodeGen &cg, Value *z) {
    if (!z) return nullptr;
    Type *origTy = z->getType();
    if (!isComplex32(origTy) && !isComplex64(origTy)) {
        errs() << "arg(): argument is not complex\n";
        return nullptr;
    }

    auto &B = cg.builder;
    LLVMContext &ctx = cg.ctx;
    Module &M = *cg.mod;

    Value *z64 = promoteToC64(cg, z);
    if (!z64) return nullptr;

    Type *c64Ty = z64->getType();
    Type *f64 = Type::getDoubleTy(ctx);

    FunctionType *FT = FunctionType::get(f64, {c64Ty}, false);
    FunctionCallee F = M.getOrInsertFunction("aft_arg_c64", FT);

    return B.CreateCall(F, {z64});
}

// conj(z) for complex
Value* conjComplex(CodeGen &cg, Value *z) {
    if (!z) return nullptr;
    Type *origTy = z->getType();
    if (!isComplex32(origTy) && !isComplex64(origTy)) {
        errs() << "conj(): argument is not complex\n";
        return nullptr;
    }

    auto &B = cg.builder;
    LLVMContext &ctx = cg.ctx;
    Module &M = *cg.mod;
    auto &Bld = cg.builder;

    Value *z64 = promoteToC64(cg, z);
    if (!z64) return nullptr;

    Type *c64Ty = z64->getType();
    FunctionType *FT = FunctionType::get(c64Ty, {c64Ty}, false);
    FunctionCallee F = M.getOrInsertFunction("aft_conj_c64", FT);

    Value *res64 = Bld.CreateCall(F, {z64});
    return demoteFromC64(cg, res64, origTy);
}

} // anonymous namespace

llvm::Value* CodeGen::gen_builtin_call(const FunctionCallExpr* call) {
    const std::string &name = call->callee;

    auto get1 = [&](Value* &a) -> bool {
        if (call->arguments.size() != 1) {
            errs() << name << "(): expected 1 argument\n";
            return false;
        }
        a = gen_expr(call->arguments[0].get());
        if (!a) {
            errs() << name << "(): argument codegen failed\n";
            return false;
        }
        return true;
    };

    auto get2 = [&](Value* &a, Value* &b) -> bool {
        if (call->arguments.size() != 2) {
            errs() << name << "(): expected 2 arguments\n";
            return false;
        }
        a = gen_expr(call->arguments[0].get());
        b = gen_expr(call->arguments[1].get());
        if (!a || !b) {
            errs() << name << "(): argument codegen failed\n";
            return false;
        }
        return true;
    };
        if (name == "re") {
        Value* z = gen_expr(call->arguments[0].get());
        if (!z) return nullptr;
        z = promoteToComplex(z);

        return builder.CreateExtractValue(z, {0});  
    }

    if (name == "im") {
        Value* z = gen_expr(call->arguments[0].get());
        if (!z) return nullptr;

        z = promoteToComplex(z);

        return builder.CreateExtractValue(z, {1});  
    }
    if (name == "abs") {
        Value *x;
        if (!get1(x)) return nullptr;
        Type *t = x->getType();

        // integers: sign-extend to i64, call aft_abs_i64, truncate back
        if (t->isIntegerTy() && t->getIntegerBitWidth() > 1) {
            Type *i64 = Type::getInt64Ty(ctx);
            Value *x64 = builder.CreateSExt(x, i64);

            FunctionType *FT = FunctionType::get(i64, {i64}, false);
            FunctionCallee F = mod->getOrInsertFunction("aft_abs_i64", FT);
            Value *y64 = builder.CreateCall(F, {x64});

            return builder.CreateTrunc(y64, t);
        }

        // floats: cast to double, call aft_abs_f64, cast back if needed
        if (t->isFloatingPointTy()) {
            Value *d = toDouble(*this, x);
            Type *f64 = Type::getDoubleTy(ctx);
            FunctionType *FT = FunctionType::get(f64, {f64}, false);
            FunctionCallee F = mod->getOrInsertFunction("aft_abs_f64", FT);
            Value *resD = builder.CreateCall(F, {d});

            if (t->isDoubleTy()) return resD;
            return builder.CreateFPTrunc(resD, t); // f32
        }

        // complex: treat abs(z) as magnitude(z) (returns f64)
        if (isComplex32(t) || isComplex64(t)) {
            return magnitudeComplex(*this, x);
        }

        errs() << "abs(): unsupported argument type\n";
        return nullptr;
    }


    if (name == "sqrt") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_sqrt_f64", x);
    }

    if (name == "exp") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_exp_f64", x);
    }

    if (name == "ln") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_ln_f64", x);
    }

    if (name == "log10") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_log10_f64", x);
    }

    if (name == "log2") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_log2_f64", x);
    }

    if (name == "pow") {
        Value *a, *b;
        if (!get2(a, b)) return nullptr;
        return callBinaryF64(*this, "aft_pow_f64", a, b);
    }


    if (name == "sin") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_sin_f64", x);
    }

    if (name == "cos") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_cos_f64", x);
    }

    if (name == "tan") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_tan_f64", x);
    }

    if (name == "arcsin") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_asin_f64", x);
    }

    if (name == "arccos") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_acos_f64", x);
    }

    if (name == "arctan") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_atan_f64", x);
    }

    if (name == "sec") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_sec_f64", x);
    }

    if (name == "cosec") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_cosec_f64", x);
    }

    if (name == "cot") {
        Value *x;
        if (!get1(x)) return nullptr;
        return callUnaryF64(*this, "aft_cot_f64", x);
    }


    if (name == "conj") {
        Value *z;
        if (!get1(z)) return nullptr;
        return conjComplex(*this, z);
    }

    if (name == "magnitude") {
        Value *z;
        if (!get1(z)) return nullptr;
        return magnitudeComplex(*this, z);
    }

    if (name == "arg") {
        Value *z;
        if (!get1(z)) return nullptr;
        return argComplex(*this, z);
    }

    return nullptr;
}
