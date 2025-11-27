#ifndef SEMANTIC
#define SEMANTIC

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
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
    bool is_const = false;
    int line_number = 0;
};

struct SymbolTable{
private:
    std::vector<std::unordered_map<std::string, Symbol>> scopes;

public:
    SymbolTable();
    void enter_scope();
    void leave_scope();
    bool add_symbol(const Symbol& sym);
    Symbol* find(const std::string& name);
    Symbol* find_in_current_scope(const std::string& name);
    void clear();
};

class SemanticAnalyzer{
    SymbolTable sym_table;
    std::vector<std::string> errors;
    int current_line = 0;
    bool in_loop = false;
    std::vector<TypePtr> current_function_return_types;
    
    void handle_node(ASTNode* node);
    void handle_function(FunctionDecl* funcDecl);
    void handle_struct(StructDecl* structDecl);
    void handle_statement(Statement* stmt);
    void handle_expression(Expression* expr);
    
    TypePtr infer_type(Expression* expr);
    bool check_type_compatibility(const TypePtr& left, const TypePtr& right);
    bool is_assignable(const TypePtr& left, const TypePtr& right);
    bool can_cast_to(const TypePtr& from, const TypePtr& to);
    
    std::string type_to_string(const TypePtr& type);
    std::string primitive_type_to_string(PrimitiveTypeEnum type);
    
    void report_error(const std::string& msg);
    void check_binary_operation(BinaryOp op, const TypePtr& left, const TypePtr& right, int line);
    void check_unary_operation(UnaryOp op, const TypePtr& operand, int line);

    bool is_numeric_type(const TypePtr& type);
    bool is_integer_type(const TypePtr& type);
    bool is_float_type(const TypePtr& type);
    bool is_complex_type(const TypePtr& type);
    bool is_vector_type(const TypePtr& type);
    

public:
    SemanticAnalyzer();
    void check(Program* program);
    SymbolTable& get_symbol_table();
    bool has_errors() const;
    void print_errors() const;
    TypePtr get_index_expr_type(const IndexExpression* idx);
    void add_builtin(const std::string& name,
                 const std::vector<TypePtr>& params,
                 TypePtr return_type);
    void add_builtins();

};

#endif
