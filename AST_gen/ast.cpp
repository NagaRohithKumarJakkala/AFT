#include <iomanip>
#include <memory>
#include "AST.h"

static void indent(int level) {
    for (int i = 0; i < level; ++i)
        std::cout << (i == level - 1 ? "|- " : "│   ");
}

void ASTNode::print(int level) {
    std::cout << "<ASTNode>\n";
}

void Program::print(int level) {
    std::cout << "Program\n";
    for (auto &b : Blocks)
        b->print(level + 1);
}

void PrimitiveType::print(int level) {
    indent(level);
    std::cout << "PrimitiveType: " << static_cast<int>(type) << "\n";
}

void VectorType::print(int level) {
    indent(level);
    std::cout << "VectorType:\n";
    if (element_type)
        element_type->print(level + 1);
}

void StructType::print(int level) {
    indent(level);
    std::cout << "StructType: " << name << "\n";
}

void Parameter::print(int level) {
    indent(level);
    std::cout << "Parameter: " << name << " ";
    if (type) type->print(level + 1);
}

void StatementBlock::print(int level) {
    indent(level);
    std::cout << "StatementBlock\n";
    for (auto &stmt : statements)
        stmt->print(level + 1);
}

void LetDecl::print(int level) {
    indent(level);
    std::cout << "LetDecl:\n";
    for (size_t i = 0; i < names.size(); ++i) {
        indent(level + 1);
        std::cout << names[i] << "\n";
        if (i < types.size() && types[i])
            types[i]->print(level + 2);
        if (i < values.size() && values[i])
            values[i]->print(level + 2);
    }
}

void ConstDecl::print(int level) {
    indent(level);
    std::cout << "ConstDecl:\n";
    for (size_t i = 0; i < names.size(); ++i) {
        indent(level + 1);
        //TODO: handle this later
        //std::cout << names[i] << "\n";
        if (i < types.size() && types[i])
            types[i]->print(level + 2);
        if (i < values.size() && values[i])
            values[i]->print(level + 2);
    }
}

void Assignment::print(int level) {
    indent(level);
    std::cout << "Assignment:\n";
    for (size_t i = 0; i < targets.size(); ++i) {
        indent(level + 1);
        //std::cout << "Target: " << targets[i] << "\n";
        if (i < values.size() && values[i])
            values[i]->print(level + 2);
    }
}

void ExprStmt::print(int level) {
    indent(level);
    std::cout << "ExprStmt:\n";
    if (expr)
        expr->print(level + 1);
}

void IfStmt::print(int level) {
    indent(level);
    std::cout << "IfStmt:\n";
    indent(level + 1);
    std::cout << "Condition:\n";
    condition->print(level + 2);
    indent(level + 1);
    std::cout << "Then:\n";
    if (then_block) then_block->print(level + 2);
    if (else_block && else_block.value()) {
        indent(level + 1);
        std::cout << "Else:\n";
        (*else_block)->print(level + 2);
    }
    if (else_if && else_if.value()) {
        indent(level + 1);
        std::cout << "ElseIf:\n";
        (*else_if)->print(level + 2);
    }
}

void WhileStmt::print(int level) {
    indent(level);
    std::cout << "WhileStmt:\n";
    indent(level + 1);
    std::cout << "Condition:\n";
    condition->print(level + 2);
    indent(level + 1);
    std::cout << "Body:\n";
    if (body) body->print(level + 2);
}

void ForStmt::print(int level) {
    indent(level);
    std::cout << "ForStmt: iterator=" << iterator << "\n";
    indent(level + 1);
    std::cout << "Iterable:\n";
    iterable->print(level + 2);
    indent(level + 1);
    std::cout << "Body:\n";
    if (body) body->print(level + 2);
}

void RepeatStmt::print(int level) {
    indent(level);
    std::cout << "RepeatStmt:\n";
    indent(level + 1);
    std::cout << "Count:\n";
    count->print(level + 2);
    indent(level + 1);
    std::cout << "Body:\n";
    if (body) body->print(level + 2);
}

void ReturnStmt::print(int level) {
    indent(level);
    std::cout << "ReturnStmt:\n";
    for (auto &v : values) {
        v->print(level + 1);
    }
}

void BreakStmt::print(int level) {
    indent(level);
    std::cout << "BreakStmt\n";
}

void ContinueStmt::print(int level) {
    indent(level);
    std::cout << "ContinueStmt\n";
}

void IdentifierExpr::print(int level) {
    indent(level);
    std::cout << "IdentifierExpr: " << name << "\n";
}

void IntegerLiteral::print(int level) {
    indent(level);
    std::cout << "IntegerLiteral: " << text << "\n";
}

void FloatLiteral::print(int level) {
    indent(level);
    std::cout << "FloatLiteral: " << text << "\n";
}

void ComplexLiteral::print(int level) {
    indent(level);
    std::cout << "ComplexLiteral: " << text << "\n";
}

void BoolLiteral::print(int level) {
    indent(level);
    std::cout << "BoolLiteral: " << (value ? "true" : "false") << "\n";
}

void PiLiteral::print(int level) {
    indent(level);
    std::cout << "PiLiteral\n";
}

void StringLiteral::print(int level) {
    indent(level);
    std::cout << "StringLiteral: \"" << value << "\"\n";
}

void VectorLiteralExpr::print(int level) {
    indent(level);
    std::cout << "VectorLiteralExpr:\n";
    for (auto &e : elements)
        e->print(level + 1);
}

void RangeExpr::print(int level) {
    indent(level);
    std::cout << "RangeExpr (" << (inclusive ? "inclusive" : "exclusive") << ")\n";
    indent(level + 1);
    std::cout << "Left:\n";
    left->print(level + 2);
    indent(level + 1);
    std::cout << "Right:\n";
    right->print(level + 2);
}

void UnaryExpression::print(int level) {
    indent(level);
    std::cout << "UnaryExpression: op=" << static_cast<int>(op) << "\n";
    operand->print(level + 1);
}

void BinaryExpression::print(int level) {
    indent(level);
    std::cout << "BinaryExpression: op=" << static_cast<int>(op) << "\n";
    indent(level + 1);
    std::cout << "Left:\n";
    left->print(level + 2);
    indent(level + 1);
    std::cout << "Right:\n";
    right->print(level + 2);
}

void IndexExpression::print(int level) {
    indent(level);
    std::cout << "IndexExpression:\n";
    indent(level + 1);
    std::cout << "Object:\n";
    object->print(level + 2);
    indent(level + 1);
    std::cout << "Index:\n";
    index->print(level + 2);
}

void TypeCastExpr::print(int level) {
    indent(level);
    std::cout << "TypeCastExpr:\n";
    indent(level + 1);
    std::cout << "Expr:\n";
    expr->print(level + 2);
    indent(level + 1);
    std::cout << "Type:\n";
    type->print(level + 2);
}

void FunctionCallExpr::print(int level) {
    indent(level);
    std::cout << "FunctionCallExpr: " << callee << "\n";
    for (auto &a : arguments)
        a->print(level + 1);
}

void FunctionDecl::print(int level) {
    indent(level);
    std::cout << "FunctionDecl: " << name << "\n";
    indent(level + 1);
    std::cout << "Params:\n";
    for (auto &p : params)
        p->print(level + 2);
    indent(level + 1);
    std::cout << "Return types:\n";
    for (auto &r : return_types)
        r->print(level + 2);
    indent(level + 1);
    std::cout << "Body:\n";
    if (body) body->print(level + 2);
}

void StructDecl::print(int level) {
    indent(level);
    std::cout << "StructDecl: " << name << "\n";
    for (auto &m : members)
        m->print(level + 1);
}

std::unique_ptr<Types> PrimitiveType::clone() const{
    return std::make_unique<PrimitiveType>(*this);
}
std::unique_ptr<Types> VectorType::clone() const {
        return std::make_unique<VectorType>(element_type->clone());
}

std::unique_ptr<Types> StructType::clone() const {
    auto s = std::make_unique<StructType>(this->name);
    //TODO: implement after completion of type

    // for (auto const& f : fields) {
    //     s->fields.push_back(f->clone());
    // }
    return s;

}
