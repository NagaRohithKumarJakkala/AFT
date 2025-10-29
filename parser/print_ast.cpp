#include <iomanip>
#include "AST.h"

static void indent(int level) {
    for (int i = 0; i < level; ++i) std::cout << "  ";
}

void ASTNode::print() {
    std::cout << "<ASTNode>\n";
}

void Program::print() {
    std::cout << "Program\n";
    for (auto &b : Blocks)
        b->print();
}

void PrimitiveType::print() {
    std::cout << "PrimitiveType: " << static_cast<int>(type) << "\n";
}

void VectorType::print() {
    std::cout << "VectorType:\n";
    indent(1);
    if (element_type)
        element_type->print();
}

void StructType::print() {
    std::cout << "StructType: " << name << "\n";
}

void Parameter::print() {
    std::cout << "Parameter: " << name << " ";
    if (type) type->print();
}

void StatementBlock::print() {
    std::cout << "StatementBlock\n";
    for (auto &stmt : statements)
        stmt->print();
}

void LetDecl::print() {
    std::cout << "LetDecl:\n";
    for (size_t i = 0; i < names.size(); ++i) {
        indent(1);
        std::cout << names[i];
        if (i < types.size() && types[i])
            types[i]->print();
        if (i < values.size() && values[i])
            values[i]->print();
    }
}

void ConstDecl::print() {
    std::cout << "ConstDecl:\n";
    for (size_t i = 0; i < names.size(); ++i) {
        indent(1);
        std::cout << names[i];
        if (i < types.size() && types[i])
            types[i]->print();
        if (i < values.size() && values[i])
            values[i]->print();
    }
}

void Assignment::print() {
    std::cout << "Assignment:\n";
    for (size_t i = 0; i < targets.size(); ++i) {
        indent(1);
        std::cout << "Target: " << targets[i] << "\n";
        if (i < values.size() && values[i])
            values[i]->print();
    }
}

void ExprStmt::print() {
    std::cout << "ExprStmt:\n";
    if (expr)
        expr->print();
}

void IfStmt::print() {
    std::cout << "IfStmt:\n";
    indent(1);
    std::cout << "Condition:\n";
    condition->print();
    indent(1);
    std::cout << "Then:\n";
    if (then_block) then_block->print();
    if (else_block && else_block.value()) {
        indent(1);
        std::cout << "Else:\n";
        (*else_block)->print();
    }
    if (else_if && else_if.value()) {
        indent(1);
        std::cout << "ElseIf:\n";
        (*else_if)->print();
    }
}

void WhileStmt::print() {
    std::cout << "WhileStmt:\n";
    indent(1);
    std::cout << "Condition:\n";
    condition->print();
    indent(1);
    std::cout << "Body:\n";
    if (body) body->print();
}

void ForStmt::print() {
    std::cout << "ForStmt: iterator=" << iterator << "\n";
    indent(1);
    std::cout << "Iterable:\n";
    iterable->print();
    indent(1);
    std::cout << "Body:\n";
    if (body) body->print();
}

void RepeatStmt::print() {
    std::cout << "RepeatStmt:\n";
    indent(1);
    std::cout << "Count:\n";
    count->print();
    indent(1);
    std::cout << "Body:\n";
    if (body) body->print();
}

void ReturnStmt::print() {
    std::cout << "ReturnStmt:\n";
    for (auto &v : values) {
        indent(1);
        v->print();
    }
}

void BreakStmt::print() {
    std::cout << "BreakStmt\n";
}

void ContinueStmt::print() {
    std::cout << "ContinueStmt\n";
}

void IdentifierExpr::print() {
    std::cout << "IdentifierExpr: " << name << "\n";
}

void IntegerLiteral::print() {
    std::cout << "IntegerLiteral: " << text << "\n";
}

void FloatLiteral::print() {
    std::cout << "FloatLiteral: " << text << "\n";
}

void ComplexLiteral::print() {
    std::cout << "ComplexLiteral: " << text << "\n";
}

void BoolLiteral::print() {
    std::cout << "BoolLiteral: " << (value ? "true" : "false") << "\n";
}

void PiLiteral::print() {
    std::cout << "PiLiteral\n";
}

void StringLiteral::print() {
    std::cout << "StringLiteral: \"" << value << "\"\n";
}

void VectorLiteralExpr::print() {
    std::cout << "VectorLiteralExpr:\n";
    for (auto &e : elements) {
        indent(1);
        e->print();
    }
}

void RangeExpr::print() {
    std::cout << "RangeExpr (" << (inclusive ? "inclusive" : "exclusive") << ")\n";
    indent(1);
    std::cout << "Left:\n";
    left->print();
    indent(1);
    std::cout << "Right:\n";
    right->print();
}

void UnaryExpression::print() {
    std::cout << "UnaryExpression: op=" << static_cast<int>(op) << "\n";
    indent(1);
    operand->print();
}

void BinaryExpression::print() {
    std::cout << "BinaryExpression: op=" << static_cast<int>(op) << "\n";
    indent(1);
    std::cout << "Left:\n";
    left->print();
    indent(1);
    std::cout << "Right:\n";
    right->print();
}

void IndexExpression::print() {
    std::cout << "IndexExpression:\n";
    indent(1);
    std::cout << "Object:\n";
    object->print();
    indent(1);
    std::cout << "Index:\n";
    index->print();
}

void TypeCastExpr::print() {
    std::cout << "TypeCastExpr:\n";
    indent(1);
    std::cout << "Expr:\n";
    expr->print();
    indent(1);
    std::cout << "Type:\n";
    type->print();
}

void FunctionCallExpr::print() {
    std::cout << "FunctionCallExpr: " << callee << "\n";
    for (auto &a : arguments) {
        indent(1);
        a->print();
    }
}

void FunctionDecl::print() {
    std::cout << "FunctionDecl: " << name << "\n";
    std::cout << "  Params:\n";
    for (auto &p : params) {
        indent(2);
        p->print();
    }
    std::cout << "  Return types:\n";
    for (auto &r : return_types) {
        indent(2);
        r->print();
    }
    std::cout << "  Body:\n";
    if (body) body->print();
}

void StructDecl::print() {
    std::cout << "StructDecl: " << name << "\n";
    for (auto &m : members) {
        indent(1);
        m->print();
    }
}


