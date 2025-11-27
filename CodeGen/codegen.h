#include "../AST_gen/AST.h"
#include "../SemanticAnalyser/semanticAnalyzer.h"
using namespace llvm;
using namespace std;



struct VectorInfo {
    llvm::Value* header;
    llvm::Value* dataPtr;
    llvm::Value* length;
    llvm::Value* typeId;
    llvm::Value* capacity;
};



struct CodeGen{
    LLVMContext ctx;
    unique_ptr<Module>mod;
    IRBuilder<> builder;
    SymbolTable &sym_table;
    SemanticAnalyzer* sem;

    CodeGen(SymbolTable &sym, string moduleName, SemanticAnalyzer* sem)
        : mod(std::make_unique<Module>(moduleName,ctx)),
        builder(ctx),
        sym_table(sym),
        sem(sem){}
    AllocaInst* createEntryAlloca(Function *fn, llvm::Type *ty, const Twine &name);
    llvm::Type* lower_type(const ::Types* t);
    Value* gen_expr(const Expression*e);
    void gen_stmt(const Statement* s,Function* fn);
    void gen_block(const StatementBlock* block, Function* fn);
    void register_struct(StructDecl* structDecl);
    Function* declare_function(const FunctionDecl* funcDecl);
    void define_function(const FunctionDecl* funcDecl);
    void gen_program(const Program* prog);
    llvm::Type* prim_to_LLVM(PrimitiveTypeEnum p);
    Value* boolToI1(IRBuilder<> &B, Value *v);

    vector<unordered_map<string,AllocaInst*>> varScopes;
    void push_scope();
    void pop_scope();
    void bind_var(const string&name,AllocaInst* A);
    AllocaInst* lookup_var(const std::string &name);
    unordered_map<string,Function*> functions;
    unordered_map<string,llvm::StructType*> structs;
    void declare_builtin_functions();
    Function* declare_print();
    Function* declare_dbg();
    int primitive_type_id(const Types* t);
    llvm::Type* elemTypeFromId(int id);
    int typeIdFromLLVM(llvm::Type *T);

    Function* declare_vec_create();
    Function* declare_vec_resize();
    Function* declare_vec_index_ptr();
    Function* declare_vec_free();
    Function* declare_vec_push();
    Function* declare_vector_reverse();


    VectorInfo unpackVector(Value* vecHeader);
    void storeVectorElementTyped(const VectorInfo &V,Value* index,Value* rhs,llvm::Type* elemType);
    Value* loadVectorElementTyped(const VectorInfo &V,Value* index,llvm::Type* expectedType);

    Value* promoteToComplex(Value* v) ;
    llvm::Value* gen_builtin_call(const FunctionCallExpr* call);
};
