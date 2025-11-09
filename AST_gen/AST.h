#ifndef AST
#define AST


#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>

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
    virtual void print(int level);
};




struct Program : public ASTNode {
    std::vector<std::unique_ptr<ASTNode>> Blocks;
    void print(int level) override;

};

struct Type: public ASTNode{
    virtual ~Type() = default;
};

struct PrimitiveType: public Type{
    PrimitiveTypeEnum type;
    PrimitiveType(PrimitiveTypeEnum t):type(t){}
    void print(int level) override;
};


struct VectorType : public Type {
    TypePtr element_type;
    VectorType(TypePtr elem) : element_type(std::move(elem)) {}
    void print(int level) override;
};


struct StructType : public Type {
    std::string name;
    explicit StructType(std::string n) : name(std::move(n)) {}
    void print(int level) override;
};

struct Parameter : public ASTNode {
    std::string name;
    TypePtr type;
    Parameter(std::string n, TypePtr t) : name(std::move(n)), type(std::move(t)) {}
    void print(int level) override;
};

struct Statement : public ASTNode {
    virtual ~Statement() = default;
};

struct StatementBlock : public Statement {
    std::vector<StmtPtr> statements;
    StatementBlock() = default; 
    explicit StatementBlock(std::vector<StmtPtr> t) : statements(std::move(t)) {}
    void print(int level) override;
};

struct LetDecl : public Statement {
    std::vector<std::string> names;
    std::vector<TypePtr> types;
    std::vector<ExprPtr> values;
    void print(int level) override;
};

struct ConstDecl : public Statement {
    std::vector<std::string> names;
    std::vector<TypePtr> types;
    std::vector<ExprPtr> values;
    void print(int level) override;
};

struct Assignment : public Statement {
    std::vector<std::string> targets;
    std::vector<ExprPtr> values;
    void print(int level) override;
};

struct ExprStmt : public Statement {
    ExprPtr expr;
    explicit ExprStmt(ExprPtr e) : expr(std::move(e)) {}
    void print(int level) override;
};

struct IfStmt : public Statement {
    ExprPtr condition;
    std::unique_ptr<StatementBlock> then_block;
    std::optional<std::unique_ptr<StatementBlock>> else_block;
    std::optional<std::unique_ptr<IfStmt>> else_if;
    void print(int level) override;
};

struct WhileStmt : public Statement {
    ExprPtr condition;
    std::unique_ptr<StatementBlock> body;
    void print(int level) override;
};

struct ForStmt : public Statement {
    std::string iterator;
    ExprPtr iterable;
    std::unique_ptr<StatementBlock> body;
    void print(int level) override;
};

struct RepeatStmt : public Statement {
    ExprPtr count;
    std::unique_ptr<StatementBlock> body;
    void print(int level) override;
};

struct ReturnStmt : public Statement {
    std::vector<ExprPtr> values;
    void print(int level) override;
};

struct BreakStmt : public Statement {
    void print(int level) override;
};

struct ContinueStmt : public Statement {
    void print(int level) override;

};

struct Expression : public ASTNode {
    virtual ~Expression() = default;
};

struct IdentifierExpr : public Expression {
    std::string name;
    explicit IdentifierExpr(std::string n) : name(std::move(n)) {}
    void print(int level) override;
};

struct LiteralExpr : public Expression {
    virtual ~LiteralExpr() = default;
};

struct IntegerLiteral : public LiteralExpr {
    std::string text;
    IntegerLiteral(std::string t) : text(std::move(t)) {}
    void print(int level) override;
};

struct FloatLiteral : public LiteralExpr {
    std::string text;
    FloatLiteral(std::string t) : text(std::move(t)) {}
    void print(int level) override;
};

struct ComplexLiteral : public LiteralExpr {
    std::string text;
    ComplexLiteral(std::string t) : text(std::move(t)) {}
    void print(int level) override;
};

struct BoolLiteral : public LiteralExpr {
    bool value;
    BoolLiteral(bool v) : value(v) {}
    void print(int level) override;
};

struct PiLiteral : public LiteralExpr {
    PiLiteral() = default;
    void print(int level) override;
};

struct StringLiteral : public LiteralExpr {
    std::string value;
    explicit StringLiteral(std::string v) : value(std::move(v)) {}
    void print(int level) override;
};

struct VectorLiteralExpr : public LiteralExpr {
    std::vector<ExprPtr> elements;
    void print(int level) override;
};

struct RangeExpr : public Expression {
    ExprPtr left;
    ExprPtr right;
    bool inclusive = false;
    RangeExpr(ExprPtr l, ExprPtr r, bool inc) : left(std::move(l)), right(std::move(r)), inclusive(inc) {}
    void print(int level) override;
};

struct UnaryExpression : public Expression {
    UnaryOp op;
    ExprPtr operand;
    UnaryExpression(UnaryOp o, ExprPtr e) : op(o), operand(std::move(e)) {}
    void print(int level) override;
};

struct BinaryExpression : public Expression {
    BinaryOp op;
    ExprPtr left;
    ExprPtr right;
    BinaryExpression(BinaryOp o, ExprPtr l, ExprPtr r) : op(o), left(std::move(l)), right(std::move(r)) {}
    void print(int level) override;
};

struct IndexExpression : public Expression {
    ExprPtr object;
    ExprPtr index;
    IndexExpression(ExprPtr o, ExprPtr i) : object(std::move(o)), index(std::move(i)) {}
    void print(int level) override;
};

struct TypeCastExpr : public Expression {
    ExprPtr expr;
    TypePtr type;
    TypeCastExpr(ExprPtr e,TypePtr t) : expr(std::move(e)), type(std::move(t)){}
    void print(int level) override;
};

struct FunctionCallExpr : public Expression {
    std::string callee;
    std::vector<ExprPtr> arguments;
    FunctionCallExpr(std::string c, std::vector<ExprPtr> args) : callee(std::move(c)), arguments(std::move(args)) {}
    void print(int level) override;
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
    void print(int level) override;

};

struct StructDecl : public ASTNode {
    std::string name;
    std::vector<ParameterPtr> members;
    StructDecl(std::string n, std::vector<ParameterPtr> m)
        : name(std::move(n)), members(std::move(m)) {}
    void print(int level) override;
};

#endif
