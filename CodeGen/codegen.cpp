#include "codegen.h"

AllocaInst* CodeGen::createEntryAlloca(Function *F, llvm::Type *Ty, const Twine &name) {
    IRBuilder<> tmp(&F->getEntryBlock(), F->getEntryBlock().begin());
    return tmp.CreateAlloca(Ty, nullptr, name);
}

llvm::Type* CodeGen::lower_type(const ::Type* t){
    if(!t) return llvm::Type::getInt64Ty(ctx);
    if(auto * pt = dynamic_cast<const PrimitiveType*>(t)) return prim_to_LLVM(pt->type);
    if(auto *vt = dynamic_cast<const ::VectorType*>(t)){
        llvm::Type* elem = lower_type(vt->element_type.get());
        return PointerType::getUnqual(elem);
    }
    if(auto * st = dynamic_cast<const ::StructType*>(t)){
        auto it = structs.find(st->name);
        if( it == structs.end()){
            auto* opaq = llvm::StructType::create(ctx,st->name);
            structs[st->name]=opaq;
            return opaq;
        }
        return it->second;
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
        // TODO:: do for the STR differently
    
        //case PrimitiveTypeEnum::STR: return llvm::Type::getInt8PtrTy(ctx);
        case PrimitiveTypeEnum::STR: return nullptr;
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
    return nullptr;
}


void gen_stmt(const Statement* s,Function* fn){

}
void gen_block(const StatementBlock* block, Function* fn){

}
void register_struct(StructDecl* structDecl){

}
Function* declare_function(const FunctionDecl* funcDecl){
    return nullptr;
}
void define_function(const FunctionDecl* funcDecl){

}
void gen_program(const Program* prog){

}

