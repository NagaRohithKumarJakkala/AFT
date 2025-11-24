#ifndef SEMANTIC
#define SEMANTIC

#include<string>
#include <unordered_map>
#include "../AST_gen/AST.h"

enum class SymbolKind{
    VARIABLE,
    FUNCTION,
    STRUCT,
    PARAMETER
};

struct Symbol {
    std::string name;
    SymbolKind kind;
    TypePtr type;
    std::vector<TypePtr> parameter_types;
    llvm::Value* irValue = nullptr;
};

struct SymbolTable{
private:
    std::vector<std::unordered_map<std::string, Symbol>>scopes;
public:
    SymbolTable();
    void enter_scope();
    void leave_scope();
    bool add_symbol(Symbol sym);
    Symbol* find(const std::string& name);
};

class SemanticAnalyzer{
    SymbolTable sym_table;

    void handle_node(ASTNode* node);

    void handle_function(FunctionDecl* funcDecl);
    void handle_struct(StructDecl* structDecl);
    void handle_statement(Statement* stmt);
    void handle_expression(Expression* expr);

    TypePtr infer__type(Expression* expr);
    bool check_type_compatibility(TypePtr left, TypePtr right);
    bool is_assignable(TypePtr left, TypePtr right);

public:
    void check(Program* program);
    SymbolTable& get_symbol_table();
};

#endif
