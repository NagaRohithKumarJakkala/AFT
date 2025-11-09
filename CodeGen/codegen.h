#include "../AST_gen/AST.h"
#include "../SemanticAnalyser/semanticAnalyzer.h"
using namespace llvm;
using namespace std;

struct CodeGen{
    LLVMContext ctx;
    unique_ptr<Module>mod;
    IRBuilder<> builder;
    SymbolTable &sym_table;
    
    CodeGen(SymbolTable &sym, string moduleName)
    : mod(std::make_unique<Module>(moduleName,ctx)),
        builder(ctx),
        sym_table(sym){}
    AllocaInst* createEntryAlloca(Function *fn, llvm::Type *ty, const Twine &name);
    llvm::Type* lower_type(const ::Type* t);
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
    unordered_map<string,Function*> functions;
    unordered_map<string,llvm::StructType*> structs;
};



