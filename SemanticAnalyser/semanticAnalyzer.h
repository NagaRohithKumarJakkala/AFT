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
};

struct SymbolTable{
private:
    std::vector<std::unordered_map<std::string, Symbol>>scopes;
public:
    SymbolTable();
    void enterScope();
    void leaveScope();
    bool addSymbol(Symbol sym);
    Symbol* find(const std::string& name);
};

class SemanticAnalyzer{
    SymbolTable sym_table;

    void handleNode(ASTNode* node);

    void handleFunction(FunctionDecl* func_decl);
    void handleStruct(StructDecl* struct_decl);
    void handleStatement(Statement* stmt);
    void handleExpression(Expression* expr);

    TypePtr inferType(Expression* expr);

public:
    void check(Program* program);
    SymbolTable& get_symbol_table();
};

#endif
