#ifndef AST
#define AST

#include <iomanip>

#include <vector>
#include <string>
#include <memory>
#include <optional>
#include <iostream>

struct Program;
struct FunctionDecl;
struct StructDecl;
struct Parameter;
struct Statement;
struct Expression;
struct Type;

using NodePtr = std::unique_ptr<struct ASTNode>;
using StmtPtr = std::unique_ptr<Statement>;
using ExprPtr = std::unique_ptr<Expression>;
using TypePtr = std::unique_ptr<Type>;
using ParameterPtr = std::unique_ptr<Parameter>;


enum class PrimitiveTypeEnum{
    I8, I16, I32, I64, I128,
    U8, U16, U32, U64, U128,
    F32, F64, C32, C64,
    BOOL,STR
};

enum class BinaryOp {
    PLUS, MINUS, MULTIPLY, DIVIDE, MODULO, EXPONENTIATE,
    EQUALS, NOTEQUAL, LESSTHAN, GREATERTHAN, LESSTHANEQUAL, GREATERTHANEQUAL,
    AND, OR, XOR,
    BITWISEAND, BITWISEOR, LEFTSHIFT, RIGHTSHIFT,
    CONVOLUTION,
    AS,
    INDEX
};


enum class UnaryOp {
    PLUS, MINUS, NOT, REVERSE,
};




struct ASTNode{
    virtual ~ASTNode() = default;
    virtual void print();
};




struct Program : public ASTNode {
    std::vector<std::unique_ptr<ASTNode>> Blocks;
    void print() override;

};

struct Type: public ASTNode{
    virtual ~Type() = default;
};

struct PrimitiveType: public Type{
    PrimitiveTypeEnum type;
    PrimitiveType(PrimitiveTypeEnum t):type(t){}
    void print() override;
};


struct VectorType : public Type {
    TypePtr element_type;
    VectorType(TypePtr elem) : element_type(std::move(elem)) {}
    void print() override;
};


struct StructType : public Type {
    std::string name;
    explicit StructType(std::string n) : name(std::move(n)) {}
    void print() override;
};

struct Parameter : public ASTNode {
    std::string name;
    TypePtr type;
    Parameter(std::string n, TypePtr t) : name(std::move(n)), type(std::move(t)) {}
    void print() override;
};

struct Statement : public ASTNode {
    virtual ~Statement() = default;
};

struct StatementBlock : public Statement {
    std::vector<StmtPtr> statements;
    StatementBlock() = default; 
    explicit StatementBlock(std::vector<StmtPtr> t) : statements(std::move(t)) {}
    void print() override;
};

struct LetDecl : public Statement {
    std::vector<std::string> names;
    std::vector<TypePtr> types;
    std::vector<ExprPtr> values;
    void print() override;
};

struct ConstDecl : public Statement {
    std::vector<std::string> names;
    std::vector<TypePtr> types;
    std::vector<ExprPtr> values;
    void print() override;
};

struct Assignment : public Statement {
    std::vector<std::string> targets;
    std::vector<ExprPtr> values;
    void print() override;
};

struct ExprStmt : public Statement {
    ExprPtr expr;
    explicit ExprStmt(ExprPtr e) : expr(std::move(e)) {}
    void print() override;
};

struct IfStmt : public Statement {
    ExprPtr condition;
    std::unique_ptr<StatementBlock> then_block;
    std::optional<std::unique_ptr<StatementBlock>> else_block;
    std::optional<std::unique_ptr<IfStmt>> else_if;
    void print() override;
};

struct WhileStmt : public Statement {
    ExprPtr condition;
    std::unique_ptr<StatementBlock> body;
    void print() override;
};

struct ForStmt : public Statement {
    std::string iterator;
    ExprPtr iterable;
    std::unique_ptr<StatementBlock> body;
    void print() override;
};

struct RepeatStmt : public Statement {
    ExprPtr count;
    std::unique_ptr<StatementBlock> body;
    void print() override;
};

struct ReturnStmt : public Statement {
    std::vector<ExprPtr> values;
    void print() override;
};

struct BreakStmt : public Statement {
    void print() override;
};

struct ContinueStmt : public Statement {
    void print() override;

};

struct Expression : public ASTNode {
    virtual ~Expression() = default;
};

struct IdentifierExpr : public Expression {
    std::string name;
    explicit IdentifierExpr(std::string n) : name(std::move(n)) {}
    void print() override;
};

struct LiteralExpr : public Expression {
    virtual ~LiteralExpr() = default;
};

struct IntegerLiteral : public LiteralExpr {
    std::string text;
    IntegerLiteral(std::string t) : text(std::move(t)) {}
    void print() override;
};

struct FloatLiteral : public LiteralExpr {
    std::string text;
    FloatLiteral(std::string t) : text(std::move(t)) {}
    void print() override;
};

struct ComplexLiteral : public LiteralExpr {
    std::string text;
    ComplexLiteral(std::string t) : text(std::move(t)) {}
    void print() override;
};

struct BoolLiteral : public LiteralExpr {
    bool value;
    BoolLiteral(bool v) : value(v) {}
    void print() override;
};

struct PiLiteral : public LiteralExpr {
    PiLiteral() = default;
    void print() override;
};

struct StringLiteral : public LiteralExpr {
    std::string value;
    explicit StringLiteral(std::string v) : value(std::move(v)) {}
    void print() override;
};

struct VectorLiteralExpr : public LiteralExpr {
    std::vector<ExprPtr> elements;
    void print() override;
};

struct RangeExpr : public Expression {
    ExprPtr left;
    ExprPtr right;
    bool inclusive = false;
    RangeExpr(ExprPtr l, ExprPtr r, bool inc) : left(std::move(l)), right(std::move(r)), inclusive(inc) {}
    void print() override;
};

struct UnaryExpression : public Expression {
    UnaryOp op;
    ExprPtr operand;
    UnaryExpression(UnaryOp o, ExprPtr e) : op(o), operand(std::move(e)) {}
    void print() override;
};

struct BinaryExpression : public Expression {
    BinaryOp op;
    ExprPtr left;
    ExprPtr right;
    BinaryExpression(BinaryOp o, ExprPtr l, ExprPtr r) : op(o), left(std::move(l)), right(std::move(r)) {}
    void print() override;
};

struct IndexExpression : public Expression {
    ExprPtr object;
    ExprPtr index;
    IndexExpression(ExprPtr o, ExprPtr i) : object(std::move(o)), index(std::move(i)) {}
    void print() override;
};

struct TypeCastExpr : public Expression {
    ExprPtr expr;
    TypePtr type;
    TypeCastExpr(ExprPtr e,TypePtr t) : expr(std::move(e)), type(std::move(t)){}
    void print() override;
};

struct FunctionCallExpr : public Expression {
    std::string callee;
    std::vector<ExprPtr> arguments;
    FunctionCallExpr(std::string c, std::vector<ExprPtr> args) : callee(std::move(c)), arguments(std::move(args)) {}
    void print() override;
};

struct FunctionDecl : public ASTNode {
    std::string name;
    std::vector<ParameterPtr> params;
    std::vector<TypePtr> return_types;
    std::unique_ptr<StatementBlock> body;
    FunctionDecl(std::string n,
                 std::vector<ParameterPtr> p,
                 std::vector<TypePtr> r,
                 std::unique_ptr<StatementBlock> b)
        : name(std::move(n)),
          params(std::move(p)),
          return_types(std::move(r)),
          body(std::move(b)) {}
    void print() override;

};

struct StructDecl : public ASTNode {
    std::string name;
    std::vector<ParameterPtr> members;
    StructDecl(std::string n, std::vector<ParameterPtr> m)
        : name(std::move(n)), members(std::move(m)) {}
    void print() override;
};

#endif
