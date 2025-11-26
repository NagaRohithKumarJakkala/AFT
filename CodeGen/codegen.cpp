#include "codegen.h"
#include "../external_functions/elem_ids.h"

int CodeGen::typeIdFromLLVM(llvm::Type *T) {
    if (T->isIntegerTy(1)) return E_BOOL;
    if (T->isIntegerTy(8)) return E_I8;
    if (T->isIntegerTy(16)) return E_I16;
    if (T->isIntegerTy(32)) return E_I32;
    if (T->isIntegerTy(64)) return E_I64;
    if (auto *IT = llvm::dyn_cast<llvm::IntegerType>(T))
        if (IT->getBitWidth() == 128) return E_I128;

    if (T->isFloatTy()) return E_F32;
    if (T->isDoubleTy()) return E_F64;

    if (auto *ST = llvm::dyn_cast<llvm::StructType>(T)) {
        if (!ST->isLiteral()) return E_UNKNOWN;  

        if (ST->getNumElements() == 2) {
            llvm::Type *a = ST->getElementType(0);
            llvm::Type *b = ST->getElementType(1);

            if (a->isFloatTy() && b->isFloatTy()) return E_C32;
            if (a->isDoubleTy() && b->isDoubleTy()) return E_C64;
        }
    }

    if (T->isPointerTy()) return E_STR; 

    return E_UNKNOWN;
}


int CodeGen::primitive_type_id(const Types* t) {
    if (!t) return E_UNKNOWN;

    if (auto *p = dynamic_cast<const PrimitiveType*>(t)) {
        switch (p->type) {
            case PrimitiveTypeEnum::I8:   return E_I8;
            case PrimitiveTypeEnum::I16:  return E_I16;
            case PrimitiveTypeEnum::I32:  return E_I32;
            case PrimitiveTypeEnum::I64:  return E_I64;
            case PrimitiveTypeEnum::I128: return E_I128;

            case PrimitiveTypeEnum::U8:   return E_U8;
            case PrimitiveTypeEnum::U16:  return E_U16;
            case PrimitiveTypeEnum::U32:  return E_U32;
            case PrimitiveTypeEnum::U64:  return E_U64;
            case PrimitiveTypeEnum::U128: return E_U128;

            case PrimitiveTypeEnum::F32:  return E_F32;
            case PrimitiveTypeEnum::F64:  return E_F64;

            case PrimitiveTypeEnum::C32:  return E_C32;
            case PrimitiveTypeEnum::C64:  return E_C64;

            case PrimitiveTypeEnum::BOOL: return E_BOOL;
            case PrimitiveTypeEnum::STR:  return E_STR;

            default: return E_UNKNOWN;
        }
    }

    return E_UNKNOWN;
}

llvm::Type* CodeGen::elemTypeFromId(int id) {
    switch (id) {
        case E_I8:   return llvm::Type::getInt8Ty(ctx);
        case E_I16:  return llvm::Type::getInt16Ty(ctx);
        case E_I32:  return llvm::Type::getInt32Ty(ctx);
        case E_I64:  return llvm::Type::getInt64Ty(ctx);
        case E_I128: return llvm::IntegerType::get(ctx, 128);

        case E_U8:   return llvm::Type::getInt8Ty(ctx);
        case E_U16:  return llvm::Type::getInt16Ty(ctx);
        case E_U32:  return llvm::Type::getInt32Ty(ctx);
        case E_U64:  return llvm::Type::getInt64Ty(ctx);
        case E_U128: return llvm::IntegerType::get(ctx, 128);

        case E_F32: return llvm::Type::getFloatTy(ctx);
        case E_F64: return llvm::Type::getDoubleTy(ctx);

        case E_C32:
            return llvm::StructType::get(
                ctx,
                { llvm::Type::getFloatTy(ctx),
                  llvm::Type::getFloatTy(ctx) }
            );

        case E_C64:
            return llvm::StructType::get(
                ctx,
                { llvm::Type::getDoubleTy(ctx),
                  llvm::Type::getDoubleTy(ctx) }
            );

        case E_BOOL: return llvm::Type::getInt1Ty(ctx);
        case E_STR:  return llvm::PointerType::get(llvm::Type::getInt8Ty(ctx), 0);

        default: return nullptr;
    }
}



AllocaInst* CodeGen::createEntryAlloca(Function *F, llvm::Type *Ty, const Twine &name) {
    IRBuilder<> tmp(&F->getEntryBlock(), F->getEntryBlock().begin());
    return tmp.CreateAlloca(Ty, nullptr, name);
}

llvm::Type* CodeGen::lower_type(const ::Types* t){
    if(!t) return llvm::Type::getInt64Ty(ctx);
    if(auto * pt = dynamic_cast<const PrimitiveType*>(t)){
        return prim_to_LLVM(pt->type);
    }
    if(auto *vt = dynamic_cast<const ::VectorType*>(t)){
        return llvm::PointerType::get(llvm::Type::getInt8Ty(ctx), 0);
    }
    return nullptr;
}

llvm::Type* CodeGen::prim_to_LLVM( PrimitiveTypeEnum p){
    switch (p) {
        case PrimitiveTypeEnum::I8: return llvm::Type::getInt8Ty(ctx);
        case PrimitiveTypeEnum::I16: return llvm::Type::getInt16Ty(ctx);
        case PrimitiveTypeEnum::I32: return llvm::Type::getInt32Ty(ctx);
        case PrimitiveTypeEnum::I64: return llvm::Type::getInt64Ty(ctx);
        case PrimitiveTypeEnum::I128: return IntegerType::get(ctx, 128);
        case PrimitiveTypeEnum::U8: return llvm::Type::getInt8Ty(ctx);
        case PrimitiveTypeEnum::U16: return llvm::Type::getInt16Ty(ctx);
        case PrimitiveTypeEnum::U32: return llvm::Type::getInt32Ty(ctx);
        case PrimitiveTypeEnum::U64: return llvm::Type::getInt64Ty(ctx);
        case PrimitiveTypeEnum::U128: return IntegerType::get(ctx, 128);
        case PrimitiveTypeEnum::F32: return llvm::Type::getFloatTy(ctx);
        case PrimitiveTypeEnum::F64: return llvm::Type::getDoubleTy(ctx);
        case PrimitiveTypeEnum::C32: return llvm::StructType::get(ctx, {llvm::Type::getFloatTy(ctx), llvm::Type::getFloatTy(ctx)});
        case PrimitiveTypeEnum::C64: return llvm::StructType::get(ctx, {llvm::Type::getDoubleTy(ctx), llvm::Type::getDoubleTy(ctx)});
        case PrimitiveTypeEnum::BOOL: return llvm::Type::getInt1Ty(ctx);
        case PrimitiveTypeEnum::STR:return llvm::PointerType::get(llvm::Type::getInt8Ty(ctx), 0);
}
return nullptr;
}

Value* CodeGen::boolToI1(IRBuilder<> &B, Value *v) {
    if (!v) return nullptr;
    if (v->getType()->isIntegerTy(1)) return v;
    if (v->getType()->isIntegerTy()) return B.CreateICmpNE(v, ConstantInt::get(v->getType(), 0));
    if (v->getType()->isFloatingPointTy()) return B.CreateFCmpONE(v, ConstantFP::get(v->getType(), 0.0));
    return nullptr;
}

Value* CodeGen::gen_expr(const Expression* e) {
    if (!e) return nullptr;
    if (auto *id = dynamic_cast<const IdentifierExpr*>(e)) {
        if (auto *A = lookup_var(id->name)) {
            return builder.CreateLoad(A->getAllocatedType(), A, id->name.c_str());
        }
        return nullptr;
    }
    if (auto *litI = dynamic_cast<const IntegerLiteral*>(e)) {
        long long v = std::stoll(litI->text);
        return ConstantInt::get(llvm::Type::getInt64Ty(ctx), v, true);
    }
    if (auto *litF = dynamic_cast<const FloatLiteral*>(e)) {
        double v = std::stod(litF->text);
        return ConstantFP::get(llvm::Type::getDoubleTy(ctx), v);
    }
    if (auto *litB = dynamic_cast<const BoolLiteral*>(e)) {
        return ConstantInt::get(llvm::Type::getInt1Ty(ctx), litB->value);
    }
    if (dynamic_cast<const PiLiteral*>(e)) {
        return ConstantFP::get(llvm::Type::getDoubleTy(ctx), 3.141592653589793);
    }
    if (auto *vec = dynamic_cast<const VectorLiteralExpr*>(e)) {
    size_t n = vec->elements.size();
    if (n == 0) {
        errs() << "Empty vector literal not supported yet\n";
        return nullptr;
    }

    Value *firstElem = gen_expr(vec->elements[0].get());
    llvm::Type *elemTy = firstElem->getType();
    int elemId = typeIdFromLLVM(elemTy);
    Value *elemIdVal = ConstantInt::get(Type::getInt32Ty(ctx), elemId);

    Function *vecCreate = functions["vec_create"];
    Function *indexFn    = functions["vec_index_ptr"];
    Value *vecPtr = builder.CreateCall(
        vecCreate,
        { elemIdVal, ConstantInt::get(Type::getInt64Ty(ctx), n) }
    );

    for (size_t i = 0; i < n; i++) {
        Value *elem = gen_expr(vec->elements[i].get());

        Value *idxVal = ConstantInt::get(Type::getInt64Ty(ctx), i);
        Value *elemPtr = builder.CreateCall(indexFn, { vecPtr, idxVal });


        llvm::Type* T = elem->getType();
        Value* typedPtr = builder.CreateBitCast(elemPtr, llvm::PointerType::get(T, 0));
        builder.CreateStore(elem, typedPtr);
    }

    // llvm::StructType *vecTy = llvm::StructType::get(
    //     ctx,
    //     {
    //         llvm::PointerType::get(ctx, 0),
    //         Type::getInt64Ty(ctx),
    //         Type::getInt32Ty(ctx),
    //         Type::getInt64Ty(ctx)
    //     }
    // );
    //
    // Value *header = UndefValue::get(vecTy);
    //
    // header = builder.CreateInsertValue(header, vecPtr, {0});
    // header = builder.CreateInsertValue(header, ConstantInt::get(Type::getInt64Ty(ctx), n), {1});
    // header = builder.CreateInsertValue(header, elemIdVal, {2});
    // header = builder.CreateInsertValue(header, ConstantInt::get(Type::getInt64Ty(ctx), n), {3});
    //
    // return header;
    return vecPtr;
}

           
    if (auto *str = dynamic_cast<const ::StringLiteral*>(e)){
        return builder.CreateGlobalString(str->value);
    }
    if (auto *un = dynamic_cast<const UnaryExpression*>(e)) {
        Value *v = gen_expr(un->operand.get()); 
        if (!v) return nullptr;
        switch (un->op) {
            case UnaryOp::PLUS: return v;
            case UnaryOp::MINUS: return v->getType()->isFloatingPointTy() ? builder.CreateFNeg(v) : builder.CreateNeg(v);
            case UnaryOp::NOT: {
                Value *b = boolToI1(builder, v);
                return builder.CreateNot(b);
            }
            case UnaryOp::REVERSE:{
            if (v->getType()->isPointerTy()) {
                errs()<<"reverse for vectors not implemented yet";
                return nullptr;
            }
            else{
                errs()<<"reverse will not work for non vectors";
                return nullptr;
                    exit(1);
            }
            }
            default: return v;
        }
    }
    if (auto *bin = dynamic_cast<const BinaryExpression*>(e)) {
        Value *L = gen_expr(bin->left.get());
        Value *R = gen_expr(bin->right.get());
        if (!L||!R){
            return nullptr;
        }
        if (bin->op == BinaryOp::OR) {
            if (auto *LStructTy = llvm::dyn_cast<llvm::StructType>(L->getType())) {
                if (auto *RStructTy = llvm::dyn_cast<llvm::StructType>(R->getType())) {
                    Value *dataPtr = builder.CreateExtractValue(L, {0});
                    llvm::Type *elemTy = dataPtr->getType();
            
                    Function* concatFn;
                    if (elemTy->isIntegerTy(64)) {
                        auto it = functions.find("vector_concat_i64");
                        if (it == functions.end()) {
                            errs() << "Internal error: vector_concat_i64 not declared\n";
                            return nullptr;
                        }
                        concatFn = it->second;
                    } else if (elemTy->isDoubleTy()) {
                        auto it = functions.find("vector_concat_f64");
                        if (it == functions.end()) {
                            errs() << "Internal error: vector_concat_f64 not declared\n";
                            return nullptr;
                        }
                        concatFn = it->second;
                    } else {
                        errs() << "Unsupported vector element type for concatenation\n";
                        return nullptr;
                    }
            
                    std::vector<Value*> argsV = {L, R};
                    return builder.CreateCall(concatFn, argsV, "concat.result");
                }
            }
        }
        if(bin->op == BinaryOp::CONVOLUTION){
            if (L->getType()->isPointerTy() && R->getType()->isPointerTy()) {
                //TODO: implement convulution
                //Function* concatFn = functions["vector_concat"];
                errs() << "Vector convulution not yet implemented\n";
                //return builder.CreateCall(concatFn, { L, R });
                return nullptr;
                auto it = functions.find("vector_convulution");
                if (it == functions.end()) {
                    errs() << "Internal error: builtin vector_concat not declared\n";
                    return nullptr;
                }

                Function* convolveFn = it->second;

                std::vector<Value*> argsV;
                argsV.push_back(L);
                argsV.push_back(R);

                return builder.CreateCall(convolveFn,argsV,convolveFn->getReturnType()->isVoidTy() ? "" : "concat.calltmp");
            }

            
        }
        if(bin->op == BinaryOp::EXPONENTIATE){
            if (L->getType()->isIntegerTy() && R->getType()->isIntegerTy()) {
                //TODO: implement convulution
                //Function* concatFn = functions["vector_concat"];
                errs() << "Vector convulution not yet implemented\n";
                //return builder.CreateCall(concatFn, { L, R });
                return nullptr;
                auto it = functions.find("integer_exponentiation");
                if (it == functions.end()) {
                    errs() << "Internal error: builtin vector_concat not declared\n";
                    return nullptr;
                }

                Function* expFn = it->second;

                std::vector<Value*> argsV;
                argsV.push_back(L);
                argsV.push_back(R);

                return builder.CreateCall(expFn,argsV,expFn->getReturnType()->isVoidTy() ? "" : "concat.calltmp");
            }
        }

        bool fp = L->getType()->isFloatingPointTy() || R->getType()->isFloatingPointTy();
        if (fp) {
            if (!L->getType()->isFloatingPointTy())
                L = builder.CreateSIToFP(L, llvm::Type::getDoubleTy(ctx));
            if (!R->getType()->isFloatingPointTy())
                R = builder.CreateSIToFP(R, llvm::Type::getDoubleTy(ctx));
        }
        switch (bin->op) {
            case BinaryOp::PLUS: return fp ? builder.CreateFAdd(L,R) : builder.CreateAdd(L,R);
            case BinaryOp::MINUS: return fp ? builder.CreateFSub(L,R) : builder.CreateSub(L,R);
            case BinaryOp::MULTIPLY: return fp ? builder.CreateFMul(L,R) : builder.CreateMul(L,R);
            case BinaryOp::DIVIDE: return fp ? builder.CreateFDiv(L,R) : builder.CreateSDiv(L,R);
            case BinaryOp::MODULO: return fp ? nullptr : builder.CreateSRem(L,R);
            case BinaryOp::EQUALS: return fp ? builder.CreateFCmpOEQ(L,R) : builder.CreateICmpEQ(L,R);
            case BinaryOp::NOTEQUAL: return fp ? builder.CreateFCmpONE(L,R) : builder.CreateICmpNE(L,R);
            case BinaryOp::LESSTHAN: return fp ? builder.CreateFCmpOLT(L,R) : builder.CreateICmpSLT(L,R);
            case BinaryOp::GREATERTHAN: return fp ? builder.CreateFCmpOGT(L,R) : builder.CreateICmpSGT(L,R);
            case BinaryOp::LESSTHANEQUAL: return fp ? builder.CreateFCmpOLE(L,R) : builder.CreateICmpSLE(L,R);
            case BinaryOp::GREATERTHANEQUAL: return fp ? builder.CreateFCmpOGE(L,R) : builder.CreateICmpSGE(L,R);
            case BinaryOp::AND: return builder.CreateAnd(boolToI1(builder,L), boolToI1(builder,R));
            case BinaryOp::OR: return builder.CreateOr(boolToI1(builder,L), boolToI1(builder,R));
            case BinaryOp::XOR: return builder.CreateXor(L,R);
            case BinaryOp::BITWISEAND: return builder.CreateAnd(L,R);
            case BinaryOp::BITWISEOR: return builder.CreateOr(L,R);
            case BinaryOp::LEFTSHIFT: return builder.CreateShl(L,R);
            case BinaryOp::RIGHTSHIFT: return builder.CreateAShr(L,R);
            default: return nullptr;
        }
    }
    if (auto *idx = dynamic_cast<const IndexExpression*>(e)) {
        TypePtr resultTy = sem->get_index_expr_type(idx);
        Value *vecPtr = gen_expr(idx->object.get());
        Value *index  = gen_expr(idx->index.get());

        Value *elemPtr = builder.CreateCall(
            functions["vec_index_ptr"],
            { vecPtr, index }
        );

        llvm::Type *elemTy = lower_type(resultTy.get());
        elemPtr = builder.CreateBitCast(elemPtr, llvm::PointerType::get(elemTy, 0));

        return builder.CreateLoad(elemTy, elemPtr);
    }
         
    if (auto *cast = dynamic_cast<const TypeCastExpr*>(e)) {
        Value *v = gen_expr(cast->expr.get()); 
        llvm::Type *dst = lower_type(cast->type.get());
        if (!v||!dst) return nullptr;
        llvm::Type *src = v->getType();
        if (src == dst) return v;
        if (src->isIntegerTy() && dst->isIntegerTy()) 
            return builder.CreateIntCast(v, dst, true);
        if (src->isIntegerTy() && dst->isFloatingPointTy()) 
            return builder.CreateSIToFP(v, dst);
        if (src->isFloatingPointTy() && dst->isIntegerTy())
            return builder.CreateFPToSI(v, dst);
        if (src->isFloatingPointTy() && dst->isFloatingPointTy()) 
            return builder.CreateFPCast(v, dst);
        return nullptr;
    }
    if (auto *call = dynamic_cast<const FunctionCallExpr*>(e)) {

        if (call->callee == "len") {
            Value *vecVal = gen_expr(call->arguments[0].get());
            VectorInfo V = unpackVector(vecVal);
            return V.length;
        }

        if (call->callee == "isempty") {
            Value *vecVal = gen_expr(call->arguments[0].get());
            VectorInfo V = unpackVector(vecVal);
            return builder.CreateICmpEQ(
                V.length,
                ConstantInt::get(Type::getInt64Ty(ctx), 0)
            );

        }

        if (call->callee == "print" || call->callee=="dbg") {
            auto printfFn = functions["print"];

            std::vector<Value*> args;

            Expression* argExpr = call->arguments[0].get();
            Value* val = gen_expr(argExpr);

            if (!val) return nullptr;

            if (val->getType()->isIntegerTy()) {
                Value *fmt = builder.CreateGlobalString("%lld\n");
                args.push_back(fmt);
                args.push_back(val);
            }
            else if (val->getType()->isDoubleTy()) {
                Value *fmt = builder.CreateGlobalString("%f\n");
                args.push_back(fmt);
                args.push_back(val);
            }
            else if (val->getType()->isPointerTy()) {
                Value *fmt = builder.CreateGlobalString("%s\n");
                args.push_back(fmt);
                args.push_back(val);
            }
            else {
                errs() << "Unsupported type for print\n";
                return nullptr;
            }
            return builder.CreateCall(printfFn, args);
        }

        auto it = functions.find(call->callee);
        if (it == functions.end()) return nullptr;
        Function *F = it->second;
        vector<Value*> argsV;
        for (auto &a : call->arguments){
            argsV.push_back(gen_expr(a.get()));
        }

        if (std::any_of(argsV.begin(), argsV.end(), [](Value* v){
            return v==nullptr;
        }))
            return nullptr;
        return builder.CreateCall(F, argsV, F->getReturnType()->isVoidTy()? "" : "calltmp");
    }
    // if (auto *vec = dynamic_cast<const VectorLiteralExpr*>(e)) {
    //     if (vec->elements.empty()) {
    //         return ConstantPointerNull::get(llvm::PointerType::get(ctx,0));
    //     }
    //     Value *first = gen_expr(vec->elements[0].get());
    //     llvm::Type *elemTy = first->getType(); 
    //     size_t n = vec->elements.size();
    //     llvm::Type *arrTy = ArrayType::get(elemTy, n);
    //     Function *curF = builder.GetInsertBlock()->getParent();
    //     AllocaInst *tmp = createEntryAlloca(curF, arrTy, "vec.lit");
    //     for (size_t i=0;i<n;++i) {
    //         Value *vi = gen_expr(vec->elements[i].get()); 
    //         Value *idxs[] = {ConstantInt::get(llvm::Type::getInt32Ty(ctx), 0),
    //                             ConstantInt::get(llvm::Type::getInt32Ty(ctx), 
    //                             (uint32_t)i)};
    //         Value *ptr = builder.CreateInBoundsGEP(arrTy, tmp, idxs);
    //         builder.CreateStore(vi, ptr);
    //     }
    //     Value *zero = ConstantInt::get(llvm::Type::getInt32Ty(ctx), 0);
    //     Value *ptr0 = builder.CreateInBoundsGEP(arrTy, tmp, {zero, zero});
    //     return ptr0;
    // }
    if (auto *rng = dynamic_cast<const RangeExpr*>(e)) {
        llvm::StructType *RT = llvm::StructType::get(ctx,
                                                     {llvm::Type::getInt64Ty(ctx),
                                                        llvm::Type::getInt64Ty(ctx),
                                                     llvm::Type::getInt1Ty(ctx)});
        Value *start = gen_expr(rng->left.get());
        Value *end = gen_expr(rng->right.get());
        if (!start||!end)
            return nullptr;
        if (!start->getType()->isIntegerTy()) 
            start = builder.CreateFPToSI(start, llvm::Type::getInt64Ty(ctx));
        if (!end->getType()->isIntegerTy())
            end = builder.CreateFPToSI(end, llvm::Type::getInt64Ty(ctx));
        if (start->getType()->isIntegerTy() && start->getType() != llvm::Type::getInt64Ty(ctx)){
            start = builder.CreateIntCast(start, llvm::Type::getInt64Ty(ctx),true);
        }
        if (end->getType()->isIntegerTy() && end->getType() != llvm::Type::getInt64Ty(ctx)){
            end = builder.CreateIntCast(end, llvm::Type::getInt64Ty(ctx),true);
        }

        Value *incl = ConstantInt::get(llvm::Type::getInt1Ty(ctx), rng->inclusive);
        Value *aggUndef = UndefValue::get(RT);
        aggUndef = builder.CreateInsertValue(aggUndef, start, {0});
        aggUndef = builder.CreateInsertValue(aggUndef, end,   {1});
        aggUndef = builder.CreateInsertValue(aggUndef, incl,  {2});
        return aggUndef;
    }
    return nullptr;
}


void CodeGen::gen_stmt(const Statement* s,Function* fn){
    if (auto *blk = dynamic_cast<const StatementBlock*>(s)) {
        gen_block(blk, fn);
        return;
    }
    if (auto *let = dynamic_cast<const LetDecl*>(s)) {
        for (size_t i=0;i<let->names.size();++i) {
            const std::string &nm = let->names[i];
            llvm::Type *ty = nullptr; 
            Value *initV = nullptr;
            if (let->types.size()>i) ty = lower_type(let->types[i].get());
            if (let->values.size()>i) initV = gen_expr(let->values[i].get());
            if (!ty) ty = initV? initV->getType(): llvm::Type::getInt64Ty(ctx);
            AllocaInst *A = createEntryAlloca(fn, ty, nm);
            bind_var(nm, A);
            if (initV) {
                if (initV->getType() != ty) {
                    if (initV->getType()->isIntegerTy() && ty->isFloatingPointTy()) 
                        initV = builder.CreateSIToFP(initV, ty);
                    else if (initV->getType()->isFloatingPointTy() && ty->isIntegerTy())
                        initV = builder.CreateFPToSI(initV, ty);
                }
                builder.CreateStore(initV, A);
            }
        }
        return;
    }
    if (auto *cnst = dynamic_cast<const ConstDecl*>(s)) {
        for (size_t i=0;i<cnst->names.size();++i) {
            const std::string &nm = cnst->names[i];
            llvm::Type *ty = nullptr; 
            Value *initV = nullptr;
            if (cnst->types.size()>i) ty = lower_type(cnst->types[i].get());
            if (cnst->values.size()>i) initV = gen_expr(cnst->values[i].get());
            if (!initV) continue;
            if (!ty) ty = initV->getType();
            AllocaInst *A = createEntryAlloca(fn, ty, nm); 
            builder.CreateStore(initV, A);
            bind_var(nm, A);
        }
        return;
    }
    if (auto *asgn = dynamic_cast<const Assignment*>(s)) {
        for (size_t i = 0; i < asgn->targets.size(); ++i) {

            Expression* target = asgn->targets[i].get();
            Value* rhs = gen_expr(asgn->values[i].get());
            if (!rhs) continue;

            if (auto* id = dynamic_cast<IdentifierExpr*>(target)) {
                AllocaInst* A = lookup_var(id->name);
                if (!A) {
                    errs() << "Undefined variable: " << id->name << "\n";
                    continue;
                }

                if (rhs->getType() != A->getAllocatedType()) {
                    if (rhs->getType()->isIntegerTy() &&
                        A->getAllocatedType()->isFloatingPointTy())
                        rhs = builder.CreateSIToFP(rhs, A->getAllocatedType());
                    else if (rhs->getType()->isFloatingPointTy() &&
                         A->getAllocatedType()->isIntegerTy())
                        rhs = builder.CreateFPToSI(rhs, A->getAllocatedType());
                }

                builder.CreateStore(rhs, A);
                continue;
            }
            if (auto *idx = dynamic_cast<IndexExpression*>(target)) {
                Value* vecHeader = gen_expr(idx->object.get());
                Value* index     = gen_expr(idx->index.get());

                VectorInfo V = unpackVector(vecHeader);
                storeVectorElement(V, index, rhs);
                continue;
            }
            errs() << "Invalid assignment target (not lvalue)\n";
        }
        return;
    }

    if (auto *es = dynamic_cast<const ExprStmt*>(s)) {
        gen_expr(es->expr.get());
        return; 
    }
    if (auto *ifs = dynamic_cast<const IfStmt*>(s)) {
        Value *cond = gen_expr(ifs->condition.get());
        cond = boolToI1(builder, cond);
        Function *curF = builder.GetInsertBlock()->getParent();
        BasicBlock *ThenBB = BasicBlock::Create(ctx, "then", curF); 
        BasicBlock *ElseBB = BasicBlock::Create(ctx, "else",curF);
        BasicBlock *MergeBB = BasicBlock::Create(ctx, "ifend",curF); 
        builder.CreateCondBr(cond, ThenBB, ElseBB);
        builder.SetInsertPoint(ThenBB);
        push_scope();
        gen_block(ifs->then_block.get(), curF);
        pop_scope();
        if (!builder.GetInsertBlock()->getTerminator())
            builder.CreateBr(MergeBB);

        builder.SetInsertPoint(ElseBB);

        if (ifs->else_if.has_value() && ifs->else_if.value()) {
            gen_stmt(ifs->else_if.value().get(), curF);
        }
        else if (ifs->else_block.has_value() && ifs->else_block.value()) {
            push_scope();
            gen_block(ifs->else_block.value().get(), curF);
            pop_scope();
        }

        if (!builder.GetInsertBlock()->getTerminator())
            builder.CreateBr(MergeBB);

        builder.SetInsertPoint(MergeBB);
        return;
    }
    if (auto *wh = dynamic_cast<const WhileStmt*>(s)) {
        Function *curF = builder.GetInsertBlock()->getParent();
        BasicBlock *CondBB = BasicBlock::Create(ctx, "while.cond", curF); 
        BasicBlock *BodyBB = BasicBlock::Create(ctx, "while.body",curF); 
        BasicBlock *EndBB  = BasicBlock::Create(ctx, "while.end",curF); 

        builder.CreateBr(CondBB); 

        builder.SetInsertPoint(CondBB); 
        Value *cond = gen_expr(wh->condition.get()); 
        cond = boolToI1(builder, cond); 
        builder.CreateCondBr(cond, BodyBB, EndBB); 

        builder.SetInsertPoint(BodyBB);
        push_scope(); 
        gen_block(wh->body.get(), curF); 
        pop_scope(); 
        if (!builder.GetInsertBlock()->getTerminator()) 
            builder.CreateBr(CondBB); 

        builder.SetInsertPoint(EndBB);
        return;
    }
    if (auto *ret = dynamic_cast<const ReturnStmt*>(s)) {
        if (ret->values.empty()) { 
            builder.CreateRetVoid(); 
            return;
        }
        Value *v = gen_expr(ret->values[0].get()); 
        builder.CreateRet(v); return; 
    }
    if (auto *fr = dynamic_cast<const ForStmt*>(s)) {
        auto *rng = dynamic_cast<const RangeExpr*>(fr->iterable.get()); 
        if (!rng) return; 
        Function *curF = builder.GetInsertBlock()->getParent(); 
        BasicBlock *CondBB = BasicBlock::Create(ctx, "for.cond", curF); 
        BasicBlock *BodyBB = BasicBlock::Create(ctx, "for.body",curF); 
        BasicBlock *StepBB = BasicBlock::Create(ctx, "for.step",curF); 
        BasicBlock *EndBB  = BasicBlock::Create(ctx, "for.end",curF); 

        Value *rngVal = gen_expr(fr->iterable.get()); 
        Value *start = builder.CreateExtractValue(rngVal, {0}); 
        Value *end   = builder.CreateExtractValue(rngVal, {1});
        Value *incl  = builder.CreateExtractValue(rngVal, {2}); 

        AllocaInst *iAlloca = createEntryAlloca(curF, llvm::Type::getInt64Ty(ctx), fr->iterator); 
        bind_var(fr->iterator, iAlloca); 
        builder.CreateStore(start, iAlloca);

        builder.CreateBr(CondBB); 

        builder.SetInsertPoint(CondBB); 
        Value *iVal = builder.CreateLoad(llvm::Type::getInt64Ty(ctx), iAlloca); 
        Value *cmp  = builder.CreateICmpSLE(iVal, end); 
        builder.CreateCondBr(cmp, BodyBB, EndBB); 

        builder.SetInsertPoint(BodyBB);
        push_scope(); 
        gen_block(fr->body.get(), curF); 
        pop_scope(); 
        if (!builder.GetInsertBlock()->getTerminator()) 
            builder.CreateBr(StepBB); 

        builder.SetInsertPoint(StepBB); 
        iVal = builder.CreateLoad(llvm::Type::getInt64Ty(ctx), iAlloca); 
        Value *inc = builder.CreateAdd(iVal, ConstantInt::get(llvm::Type::getInt64Ty(ctx), 1));
        builder.CreateStore(inc, iAlloca); 
        builder.CreateBr(CondBB); 

        builder.SetInsertPoint(EndBB);
        return; 
    }
}
void CodeGen::gen_block(const StatementBlock* block, Function* fn){
 for (auto &sp : block->statements) {
    gen_stmt(sp.get(), fn);
    if (builder.GetInsertBlock()->getTerminator())
        break;
    } 
}
void CodeGen::register_struct(StructDecl* structDecl){
 auto it = structs.find(structDecl->name);
    llvm::StructType *ST; 
    if (it == structs.end()) { 
        ST = llvm::StructType::create(ctx, structDecl->name);
        structs[structDecl->name] = ST;
    } else
        ST = it->second;
    vector<llvm::Type*> fields;
    for (auto &m : structDecl->members) {
        fields.push_back(lower_type(m->type.get()));
    }
    ST->setBody(fields, false); 

}
Function* CodeGen::declare_function(const FunctionDecl* funcDecl){

    vector<llvm::Type*> argTys;
    for (auto &p : funcDecl->params) argTys.push_back(lower_type(p->type.get()));
    llvm::Type *retTy;
    if (funcDecl->return_types.empty()) {
        retTy = llvm::Type::getVoidTy(ctx);
    }
    else if (funcDecl->return_types.size()==1){
        retTy = lower_type(funcDecl->return_types[0].get());
    } else {
        vector<llvm::Type*> rts;
        for (auto &rt : funcDecl->return_types){
            rts.push_back(lower_type(rt.get()));
        }
        retTy = llvm::StructType::get(ctx, rts);
    }
    FunctionType *FT = FunctionType::get(retTy, argTys, false);
    Function *F = Function::Create(FT, Function::ExternalLinkage, funcDecl->name, mod.get());
    unsigned idx = 0;
    for (auto &Arg : F->args()){
        Arg.setName(funcDecl->params[idx++]->name);
    }
    functions[funcDecl->name] = F;
    return F;
    return nullptr;
}

void CodeGen::define_function(const FunctionDecl* funcDecl){
    Function *F = functions[funcDecl->name];
    BasicBlock *BB = BasicBlock::Create(ctx, "entry", F);
    builder.SetInsertPoint(BB);
    push_scope(); 
    unsigned idx=0;
    for (auto &Arg : F->args()) {
        llvm::Type *Ty = Arg.getType();
        AllocaInst *A = createEntryAlloca(F, Ty, Arg.getName());
        builder.CreateStore(&Arg, A); 
        bind_var(std::string(Arg.getName()), A);
        idx++;
    }
    if (funcDecl->body){
        gen_block(funcDecl->body.get(), F);
    }
    // if (!BB->getTerminator()) {
    //     if (F->getReturnType()->isVoidTy()){
    //         builder.CreateRetVoid();
    //     } else if (F->getReturnType()->isIntegerTy()){
    //         builder.CreateRet(ConstantInt::get(F->getReturnType(), 0));
    //     } else{
    //         builder.CreateUnreachable();
    //     }
    // }

    BasicBlock *curBB = builder.GetInsertBlock();
    if (curBB && !curBB->getTerminator()) {
        if (F->getReturnType()->isVoidTy()) {
            builder.CreateRetVoid();
        } else if (F->getReturnType()->isIntegerTy()) {
            builder.CreateRet(ConstantInt::get(F->getReturnType(), 0));
        } else {
            builder.CreateUnreachable();
        }
    }

    pop_scope();
    string err;
    raw_string_ostream rso(err);
    if (verifyFunction(*F, &rso)) {
        errs() << "Function verification failed for " << funcDecl->name << ": " << rso.str() << " ";
        F->print(errs());
    }

}
void CodeGen::gen_program(const Program* prog){
    declare_builtin_functions();


    for (auto &B : prog->Blocks){
        if (auto *S = dynamic_cast<StructDecl*>(B.get())) {
            register_struct(S);
        }
    }
    for (auto &B : prog->Blocks){
        if (auto *F = dynamic_cast<FunctionDecl*>(B.get())) {
            declare_function(F);
        }
    }
    for (auto &B : prog->Blocks) {
        if (auto *F = dynamic_cast<FunctionDecl*>(B.get())) {
            define_function(F);
        } else if (auto *S = dynamic_cast<Statement*>(B.get())) {
            if (!mod->getFunction("main")) {
                FunctionType *FT = FunctionType::get(llvm::Type::getInt32Ty(ctx), {}, false);
                Function *Main = Function::Create(FT, Function::ExternalLinkage, "main", mod.get());
                BasicBlock *BB = BasicBlock::Create(ctx, "entry", Main);
                builder.SetInsertPoint(BB);
                push_scope();
                gen_stmt(S, Main);
                if (!builder.GetInsertBlock()->getTerminator()){
                    builder.CreateRet(ConstantInt::get(llvm::Type::getInt32Ty(ctx), 0));
                }
                pop_scope();
            } else { 
                auto *Main = mod->getFunction("main");
                gen_stmt(S, Main);
            }
        }
    }

}

AllocaInst* CodeGen::lookup_var(const std::string &name) {
    for (auto it = varScopes.rbegin(); it != varScopes.rend(); ++it) {
        auto f = it->find(name);
        if (f != it->end()){ 
            return f->second;
        }
    }
    Symbol* s = sym_table.find(name);
    if (s && s->irValue){ 
        return dyn_cast<AllocaInst>(s->irValue);
    }
        return nullptr;
}

void CodeGen::push_scope(){
    varScopes.emplace_back();
}
void CodeGen::pop_scope(){
    varScopes.pop_back();

}

void CodeGen::bind_var(const std::string &name, AllocaInst* A) {
    varScopes.back()[name] = A;
    Symbol* s = sym_table.find(name);
    if (s) s->irValue = A;
}

void CodeGen::declare_builtin_functions(){
    Function* printFn = declare_print();
    functions["print"] = printFn;
    functions["dbg"] = printFn;
    functions["vec_create"]     = declare_vec_create();
    functions["vec_resize"]     = declare_vec_resize();
    functions["vec_index_ptr"]  = declare_vec_index_ptr();
    functions["vec_free"]       = declare_vec_free();
    functions["vec_push"]       = declare_vec_push();

}

Function* CodeGen::declare_print(){
        llvm::FunctionType* printfType = llvm::FunctionType::get(
        llvm::IntegerType::getInt32Ty(ctx),
        llvm::PointerType::get(llvm::Type::getInt8Ty(ctx),0),
        true
    );

    llvm::Function* printFn = llvm::Function::Create(
        printfType,
        llvm::Function::ExternalLinkage,
        "printf",
        mod.get()
    );
    return printFn;

}

Function* CodeGen::declare_vec_create() {
    FunctionType *FT = FunctionType::get(
        PointerType::get(Type::getInt8Ty(ctx), 0),
        { Type::getInt32Ty(ctx), Type::getInt64Ty(ctx) },
        false
    );
    return Function::Create(FT, llvm::Function::ExternalLinkage, "vec_create", mod.get());
}


Function* CodeGen::declare_vec_resize() {
    FunctionType *FT = FunctionType::get(
        Type::getVoidTy(ctx),
        {
            PointerType::get(Type::getInt8Ty(ctx), 0),
            Type::getInt64Ty(ctx)
        },
        false
    );

    return Function::Create(
        FT,
        Function::ExternalLinkage,
        "vec_resize",
        mod.get()
    );
}

Function* CodeGen::declare_vec_index_ptr() {
    FunctionType *FT = FunctionType::get(
        PointerType::get(Type::getInt8Ty(ctx), 0),
        {
            PointerType::get(Type::getInt8Ty(ctx), 0),
            Type::getInt64Ty(ctx)
        },
        false
    );

    return Function::Create(
        FT,
        Function::ExternalLinkage,
        "vec_index_ptr",
        mod.get()
    );
}

Function* CodeGen::declare_vec_free() {
    FunctionType *FT = FunctionType::get(
        Type::getVoidTy(ctx),
        {
            PointerType::get(Type::getInt8Ty(ctx), 0)
        },
        false
    );

    return Function::Create(
        FT,
        Function::ExternalLinkage,
        "vec_free",
        mod.get()
    );
}

Function* CodeGen::declare_vec_push() {
    FunctionType *FT = FunctionType::get(
        Type::getVoidTy(ctx),
        {
            PointerType::get(Type::getInt8Ty(ctx), 0),
            PointerType::get(Type::getInt8Ty(ctx), 0)
        },
        false
    );

    return Function::Create(
        FT,
        Function::ExternalLinkage,
        "vec_push",
        mod.get()
    );
}

VectorInfo CodeGen::unpackVector(Value* vecPtr) {
    VectorInfo v;
    v.header = vecPtr;

    llvm::Type* i8PtrTy = llvm::PointerType::get(llvm::Type::getInt8Ty(ctx), 0);

    llvm::Type* vecHeaderTy = llvm::StructType::get(
        ctx,
        {
            i8PtrTy,                      // data
            llvm::Type::getInt64Ty(ctx), // length
            llvm::Type::getInt64Ty(ctx), // capacity
            llvm::Type::getInt32Ty(ctx)  // elemType
        }
    );

    // Cast i8* → %VecHeader*
    Value* typed = builder.CreateBitCast(
        vecPtr,
        llvm::PointerType::get(vecHeaderTy, 0)
    );

    // data
    v.dataPtr = builder.CreateLoad(
        i8PtrTy,
        builder.CreateStructGEP(vecHeaderTy, typed, 0)
    );

    // length
    v.length = builder.CreateLoad(
        llvm::Type::getInt64Ty(ctx),
        builder.CreateStructGEP(vecHeaderTy, typed, 1)
    );

    // capacity
    v.capacity = builder.CreateLoad(
        llvm::Type::getInt64Ty(ctx),
        builder.CreateStructGEP(vecHeaderTy, typed, 2)
    );

    // elemType
    v.typeId = builder.CreateLoad(
        llvm::Type::getInt32Ty(ctx),
        builder.CreateStructGEP(vecHeaderTy, typed, 3)
    );

    return v;

}

Value* CodeGen::loadVectorElement(const VectorInfo &V, Value* index) {
    Function* F = builder.GetInsertBlock()->getParent();
    Function* indexFn = functions["vec_index_ptr"];

    // Value* rawPtr = builder.CreateCall(indexFn, {V.dataPtr, index});
     Value* rawPtr = builder.CreateCall(indexFn, {V.header, index});

    BasicBlock* mergeBB = BasicBlock::Create(ctx, "vec.load.merge", F);
    AllocaInst* result = createEntryAlloca(F, Type::getInt64Ty(ctx), "vec_load_tmp");

    auto* sw = builder.CreateSwitch(V.typeId, mergeBB, 6);

    auto addCase = [&](int tag, llvm::Type* T, auto convert){
        BasicBlock* caseBB = BasicBlock::Create(ctx, "vec.load", F);
        sw->addCase(ConstantInt::get(Type::getInt32Ty(ctx), tag), caseBB);
        builder.SetInsertPoint(caseBB);

        Value* castPtr = builder.CreateBitCast(rawPtr, PointerType::get(T, 0));
        Value* loaded = builder.CreateLoad(T, castPtr);
        Value* finalV = convert(loaded);
        builder.CreateStore(finalV, result);
        builder.CreateBr(mergeBB);
    };

    addCase(E_I8, Type::getInt8Ty(ctx),
            [&](Value* x){ return builder.CreateSExt(x, Type::getInt64Ty(ctx)); });

    addCase(E_I32, Type::getInt32Ty(ctx),
            [&](Value* x){ return builder.CreateSExt(x, Type::getInt64Ty(ctx)); });

    addCase(E_I64, Type::getInt64Ty(ctx),
            [&](Value* x){ return x; });

    addCase(E_F32, Type::getFloatTy(ctx),
            [&](Value* x){ return builder.CreateFPToSI(x, Type::getInt64Ty(ctx)); });

    addCase(E_F64, Type::getDoubleTy(ctx),
            [&](Value* x){ return builder.CreateFPToSI(x, Type::getInt64Ty(ctx)); });

    addCase(E_STR, PointerType::get(Type::getInt8Ty(ctx), 0),
            [&](Value* x){ return builder.CreatePtrToInt(x, Type::getInt64Ty(ctx)); });

    builder.SetInsertPoint(mergeBB);
    return builder.CreateLoad(Type::getInt64Ty(ctx), result);
}

void CodeGen::storeVectorElement(const VectorInfo &V, Value* index, Value* rhs) {
    Function* F = builder.GetInsertBlock()->getParent();
    Function* indexFn = functions["vec_index_ptr"];
    // Value* rawPtr = builder.CreateCall(indexFn, {V.dataPtr, index});
     Value* rawPtr = builder.CreateCall(indexFn, {V.header, index});

    BasicBlock* mergeBB = BasicBlock::Create(ctx, "vec.store.merge", F);
    auto* sw = builder.CreateSwitch(V.typeId, mergeBB, 6);

    auto addCase = [&](int tag, llvm::Type* T, auto convert){
        BasicBlock* caseBB = BasicBlock::Create(ctx, "vec.store", F);
        sw->addCase(ConstantInt::get(Type::getInt32Ty(ctx), tag), caseBB);
        builder.SetInsertPoint(caseBB);

        Value* castPtr = builder.CreateBitCast(rawPtr, PointerType::get(T, 0));
        builder.CreateStore(convert(rhs), castPtr);

        builder.CreateBr(mergeBB);
    };

    addCase(E_I8, Type::getInt8Ty(ctx),
            [&](Value* x){ return builder.CreateTrunc(x, Type::getInt8Ty(ctx)); });

    addCase(E_I32, Type::getInt32Ty(ctx),
            [&](Value* x){ return builder.CreateTrunc(x, Type::getInt32Ty(ctx)); });

    addCase(E_I64, Type::getInt64Ty(ctx),
            [&](Value* x){ return builder.CreateIntCast(x, Type::getInt64Ty(ctx), true); });

    addCase(E_F32, Type::getFloatTy(ctx),
            [&](Value* x){ return builder.CreateSIToFP(x, Type::getFloatTy(ctx)); });

    addCase(E_F64, Type::getDoubleTy(ctx),
            [&](Value* x){ return builder.CreateSIToFP(x, Type::getDoubleTy(ctx)); });

    addCase(E_STR, PointerType::get(Type::getInt8Ty(ctx), 0),
            [&](Value* x){ return builder.CreateIntToPtr(x, PointerType::get(Type::getInt8Ty(ctx),0)); });

    builder.SetInsertPoint(mergeBB);
}

