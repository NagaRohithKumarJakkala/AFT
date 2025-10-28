#ifndef AST
#define AST

#include <vector>
#include <string>
#include <memory>
#include <optional>

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
    BOOL
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
};




struct Program : public ASTNode {
    std::vector<std::unique_ptr<ASTNode>> Blocks;
};

struct Type: public ASTNode{
    virtual ~Type() = default;
};

struct PrimitiveType: public Type{
    PrimitiveTypeEnum type;
    PrimitiveType(PrimitiveTypeEnum t):type(t){}
};


struct VectorType : public Type {
    TypePtr element_type;
    VectorType(TypePtr elem) : element_type(std::move(elem)) {}
};


struct StructType : public Type {
    std::string name;
    explicit StructType(std::string n) : name(std::move(n)) {}
};

struct Parameter : public ASTNode {
    std::string name;
    TypePtr type;
    Parameter(std::string n, TypePtr t) : name(std::move(n)), type(std::move(t)) {}
};

struct Statement : public ASTNode {
    virtual ~Statement() = default;
};

struct StatementBlock : public Statement {
    std::vector<StmtPtr> statements;
};

struct LetDecl : public Statement {
    std::vector<std::string> names;
    std::vector<TypePtr> types;
    std::vector<ExprPtr> values;
};

struct ConstDecl : public Statement {
    std::vector<std::string> names;
    std::vector<TypePtr> types;
    std::vector<ExprPtr> values;
};

struct Assignment : public Statement {
    std::vector<std::string> targets;
    std::vector<ExprPtr> values;
};

struct IfStmt : public Statement {
    ExprPtr condition;
    std::unique_ptr<StatementBlock> then_block;
    std::optional<std::unique_ptr<StatementBlock>> else_block;
    std::optional<std::unique_ptr<IfStmt>> else_if;
};

struct WhileStmt : public Statement {
    ExprPtr condition;
    std::unique_ptr<StatementBlock> body;
};

struct ForStmt : public Statement {
    std::string iterator;
    ExprPtr iterable;
    std::unique_ptr<StatementBlock> body;
};

struct RepeatStmt : public Statement {
    ExprPtr count;
    std::unique_ptr<StatementBlock> body;
};

struct ReturnStmt : public Statement {
    std::vector<ExprPtr> values;
};

struct BreakStmt : public Statement {};

struct ContinueStmt : public Statement {};

struct Expression : public ASTNode {
    virtual ~Expression() = default;
};

struct IdentifierExpr : public Expression {
    std::string name;
    explicit IdentifierExpr(std::string n) : name(std::move(n)) {}
};

struct LiteralExpr : public Expression {
    virtual ~LiteralExpr() = default;
};

struct IntegerLiteral : public LiteralExpr {
    std::string text;
    IntegerLiteral(std::string t) : text(std::move(t)) {}
};

struct FloatLiteral : public LiteralExpr {
    std::string text;
    FloatLiteral(std::string t) : text(std::move(t)) {}
};

struct ComplexLiteral : public LiteralExpr {
    std::string text;
    ComplexLiteral(std::string t) : text(std::move(t)) {}
};

struct BoolLiteral : public LiteralExpr {
    bool value;
    BoolLiteral(bool v) : value(v) {}
};

struct PiLiteral : public LiteralExpr {
    PiLiteral() = default;
};

struct VectorLiteralExpr : public LiteralExpr {
    std::vector<ExprPtr> elements;
};

struct RangeExpr : public Expression {
    ExprPtr left;
    ExprPtr right;
    bool inclusive = false;
    RangeExpr(ExprPtr l, ExprPtr r, bool inc) : left(std::move(l)), right(std::move(r)), inclusive(inc) {}
};

struct UnaryExpression : public Expression {
    UnaryOp op;
    ExprPtr operand;
    UnaryExpression(UnaryOp o, ExprPtr e) : op(o), operand(std::move(e)) {}
};

struct BinaryExpression : public Expression {
    BinaryOp op;
    ExprPtr left;
    ExprPtr right;
    BinaryExpression(BinaryOp o, ExprPtr l, ExprPtr r) : op(o), left(std::move(l)), right(std::move(r)) {}
};

struct IndexExpression : public Expression {
    ExprPtr object;
    ExprPtr index;
    IndexExpression(ExprPtr o, ExprPtr i) : object(std::move(o)), index(std::move(i)) {}
};

struct FunctionCallExpr : public Expression {
    std::string callee;
    std::vector<ExprPtr> arguments;
    FunctionCallExpr(std::string c, std::vector<ExprPtr> args) : callee(std::move(c)), arguments(std::move(args)) {}
};

struct FunctionDecl : public ASTNode {
    std::string name;
    std::vector<ParameterPtr> params;
    std::vector<TypePtr> return_types;
    std::unique_ptr<StatementBlock> body;
};

struct StructDecl : public ASTNode {
    std::string name;
    std::vector<ParameterPtr> members;
};

#endif
