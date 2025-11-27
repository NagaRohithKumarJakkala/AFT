#include "semanticAnalyzer.h"
#include <iostream>

static bool can_implicitly_convert_primitive(PrimitiveTypeEnum from,
                                             PrimitiveTypeEnum to) {
    if (from == to) return true;

    auto is_int = [](PrimitiveTypeEnum t) {
        switch (t) {
            case PrimitiveTypeEnum::I8:
            case PrimitiveTypeEnum::I16:
            case PrimitiveTypeEnum::I32:
            case PrimitiveTypeEnum::I64:
            case PrimitiveTypeEnum::I128:
            case PrimitiveTypeEnum::U8:
            case PrimitiveTypeEnum::U16:
            case PrimitiveTypeEnum::U32:
            case PrimitiveTypeEnum::U64:
            case PrimitiveTypeEnum::U128:
                return true;
            default:
                return false;
        }
    };

    auto is_float = [](PrimitiveTypeEnum t) {
        return t == PrimitiveTypeEnum::F32 || t == PrimitiveTypeEnum::F64;
    };

    auto is_complex = [](PrimitiveTypeEnum t) {
        return t == PrimitiveTypeEnum::C32 || t == PrimitiveTypeEnum::C64;
    };

    if (is_int(from) && is_float(to))  return true;
    if (is_int(from) && is_complex(to)) return true;

    if (is_float(from) && is_complex(to)) return true;

    if (from == PrimitiveTypeEnum::F32 && to == PrimitiveTypeEnum::F64)
        return true;

    if (from == PrimitiveTypeEnum::C32 && to == PrimitiveTypeEnum::C64)
        return true;

    return false;
}


SymbolTable::SymbolTable(){
    enter_scope();
}

void SymbolTable::enter_scope(){
    scopes.emplace_back();
}

void SymbolTable::leave_scope(){
    scopes.pop_back();
}

bool SymbolTable::add_symbol(const Symbol& sym){
    auto& currentScope = scopes.back();
    if(currentScope.count(sym.name)){
        return false;
    }

    Symbol copy;
    copy.name = sym.name;
    copy.kind = sym.kind;
    if(sym.type){
        copy.type = sym.type->clone();
    }
    for (const auto &p : sym.parameter_types) {
        if (p) {
            copy.parameter_types.push_back(p->clone());
        } else {
            copy.parameter_types.push_back(nullptr);
        }
    }
    copy.irValue = sym.irValue;
    copy.is_const = sym.is_const;
    copy.line_number = sym.line_number;

    currentScope.emplace(copy.name, std::move(copy));
    return true;
}

Symbol* SymbolTable::find(const std::string& name){
    for(auto it = scopes.rbegin(); it != scopes.rend(); ++it){
        auto found = it->find(name);
        if(found != it->end()){
            return &found->second;
        }
    }
    return nullptr;
}

Symbol* SymbolTable::find_in_current_scope(const std::string& name){
    auto& currentScope = scopes.back();
    auto found = currentScope.find(name);
    if(found != currentScope.end()){
        return &found->second;
    }
    return nullptr;
}
void SymbolTable::clear() {
    scopes.clear();
    enter_scope();
}
void SemanticAnalyzer::add_builtin(const std::string& name,
                                   const std::vector<TypePtr>& params,
                                   TypePtr return_type)
{
    Symbol s;
    s.name = name;
    s.kind = SymbolKind::FUNCTION;

    for (const auto &p : params) {
        if (p)
            s.parameter_types.push_back(p->clone());
        else
            s.parameter_types.push_back(nullptr);
    }

    if (return_type)
        s.type = return_type->clone();
    else
        s.type = nullptr;

    sym_table.add_symbol(s);
}

void SemanticAnalyzer::add_builtins() {

    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::STR)); add_builtin("print", p, nullptr); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::STR)); add_builtin("printf", p, nullptr); }
    { std::vector<TypePtr> p; add_builtin("dbg", p, nullptr); }

    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("sin", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("cos", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("sqrt", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("exp", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("log", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("ln", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("log10", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("log2", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("tan", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("arcsin", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("arccos", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("arctan", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("sec", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("cosec", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("cot", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }

    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("abs", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }

    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); add_builtin("pow", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }

    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::C64)); add_builtin("magnitude", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::C64)); add_builtin("conj", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::C64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::C64)); add_builtin("arg", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64)); }

    { std::vector<TypePtr> p; p.push_back(std::make_unique<VectorType>(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64))); add_builtin("len", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::I64)); }
    { std::vector<TypePtr> p; p.push_back(std::make_unique<VectorType>(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64))); add_builtin("isempty", p, std::make_unique<PrimitiveType>(PrimitiveTypeEnum::BOOL)); }

    Symbol pi_const;
    pi_const.name = "PI";
    pi_const.kind = SymbolKind::VARIABLE;
    pi_const.type = std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64);
    pi_const.is_const = true;
    sym_table.add_symbol(pi_const);
}


SemanticAnalyzer::SemanticAnalyzer(){

}




SymbolTable& SemanticAnalyzer::get_symbol_table(){
    return sym_table;
}

void SemanticAnalyzer::check(Program* program){
    if(!program) return;

    sym_table.clear();
    add_builtins();

    for(auto& block : program->Blocks){
        handle_node(block.get());
    }

    if(has_errors()){
        print_errors();
    }
}



void SemanticAnalyzer::handle_node(ASTNode* node){
    if(auto func_decl = dynamic_cast<FunctionDecl*>(node)){
        handle_function(func_decl);
    } else if(auto struct_decl = dynamic_cast<StructDecl*>(node)){
        handle_struct(struct_decl);
    } else if(auto stmt = dynamic_cast<Statement*>(node)){
        handle_statement(stmt);
    }
}

void SemanticAnalyzer::handle_function(FunctionDecl* funcDecl){
    Symbol func_sym;
    func_sym.name = funcDecl->name;
    func_sym.kind = SymbolKind::FUNCTION;
    func_sym.line_number = current_line;

    for(auto& param : funcDecl->params){
        if(param->type){
            func_sym.parameter_types.push_back(param->type->clone());
        }
    }

    if(!funcDecl->return_types.empty()){
        current_function_return_types.clear();
        for(const auto& ret_type : funcDecl->return_types){
            current_function_return_types.push_back(ret_type->clone());
        }
    }

    if(!sym_table.add_symbol(func_sym)){
        report_error("Function '" + funcDecl->name + "' already declared");
    }

    sym_table.enter_scope();

    for(auto& param : funcDecl->params){
        Symbol param_sym;
        param_sym.name = param->name;
        param_sym.kind = SymbolKind::PARAMETER;
        if(param->type){
            param_sym.type = param->type->clone();
        }
        param_sym.line_number = current_line;

        if(!sym_table.add_symbol(param_sym)){
            report_error("Parameter '" + param->name + "' already declared");
        }
    }

    if(funcDecl->body){
        handle_statement(funcDecl->body.get());
    }

    sym_table.leave_scope();
    current_function_return_types.clear();

}

void SemanticAnalyzer::handle_struct(StructDecl* structDecl){
    Symbol struct_sym;
    struct_sym.name = structDecl->name;
    struct_sym.kind = SymbolKind::STRUCT;
    struct_sym.line_number = current_line;

    if(!sym_table.add_symbol(struct_sym)){
        report_error("Struct '" + structDecl->name + "' already declared");
    }
}

void SemanticAnalyzer::handle_statement(Statement* stmt){
    if(!stmt) return;

    if(auto blk = dynamic_cast<StatementBlock*>(stmt)){
        sym_table.enter_scope();
        for(auto& s : blk->statements){
            handle_statement(s.get());
        }
        sym_table.leave_scope();
        return;
    }

    if(auto let = dynamic_cast<LetDecl*>(stmt)){
        for(size_t i = 0; i < let->names.size(); ++i){
            Symbol var_sym;
            var_sym.name = let->names[i];
            var_sym.kind = SymbolKind::VARIABLE;
            var_sym.is_const = false;
            var_sym.line_number = current_line;

            if(i < let->types.size() && let->types[i]){
                var_sym.type = let->types[i]->clone();
            } else if(i < let->values.size() && let->values[i]){
                var_sym.type = infer_type(let->values[i].get());
            } else {
                report_error("Variable '" + let->names[i] + "' declared without type or initializer");
                continue;
            }

            if(i < let->values.size() && let->values[i]){
                handle_expression(let->values[i].get());
                TypePtr value_type = infer_type(let->values[i].get());
                if(!check_type_compatibility(var_sym.type, value_type)){
                    report_error("Type mismatch in initialization of '" + let->names[i] + 
                                 "': expected " + type_to_string(var_sym.type) + 
                                 ", got " + type_to_string(value_type));
                }
            }

            if(!sym_table.add_symbol(var_sym)){
                Symbol* existing = sym_table.find_in_current_scope(let->names[i]);
                if(existing){
                    report_error("Variable '" + let->names[i] + "' already declared in this scope");
                }
            }
        }
        return;
    }

    if(auto const_decl = dynamic_cast<ConstDecl*>(stmt)){
        for(size_t i = 0; i < const_decl->names.size(); ++i){
            if(i >= const_decl->values.size() || !const_decl->values[i]){
                report_error("Const variable '" + const_decl->names[i] + "' must be initialized");
                continue;
            }

            Symbol var_sym;
            var_sym.name = const_decl->names[i];
            var_sym.kind = SymbolKind::VARIABLE;
            var_sym.is_const = true;
            var_sym.line_number = current_line;

            if(i < const_decl->types.size() && const_decl->types[i]){
                var_sym.type = const_decl->types[i]->clone();
            } else {
                var_sym.type = infer_type(const_decl->values[i].get());
            }

            handle_expression(const_decl->values[i].get());

            TypePtr value_type = infer_type(const_decl->values[i].get());
            if(!check_type_compatibility(var_sym.type, value_type)){
                report_error("Type mismatch in initialization of const '" + const_decl->names[i] + 
                             "': expected " + type_to_string(var_sym.type) + 
                             ", got " + type_to_string(value_type));
            }

            if(!sym_table.add_symbol(var_sym)){
                report_error("Const '" + const_decl->names[i] + "' already declared");
            }
        }
        return;
    }

    if (auto asgn = dynamic_cast<Assignment*>(stmt)) {
        for (size_t i = 0; i < asgn->targets.size(); ++i) {

            Expression* target = asgn->targets[i].get();
            Expression* value  = asgn->values[i].get();

            if (auto* id = dynamic_cast<IdentifierExpr*>(target)) {

                Symbol* sym = sym_table.find(id->name);
                if (!sym) {
                    report_error("Undeclared variable '" + id->name + "'");
                    continue;
                }

                if (sym->is_const) {
                    report_error("Cannot assign to const variable '" + id->name + "'");
                    continue;
                }

                handle_expression(value);
                TypePtr rhs_type = infer_type(value);

                if (!check_type_compatibility(sym->type, rhs_type)) {
                    report_error(
                        "Type mismatch in assignment to '" + id->name +
                        "': expected " + type_to_string(sym->type) +
                        ", got " + type_to_string(rhs_type));
                }

                continue;
            }

            if (auto* idx = dynamic_cast<IndexExpression*>(target)) {

                handle_expression(idx->object.get());
                TypePtr obj_type = infer_type(idx->object.get());

                auto* vec_type = dynamic_cast<VectorType*>(obj_type.get());
                if (!vec_type) {
                    report_error("Left-hand side of indexed assignment must be a vector");
                    continue;
                }

                handle_expression(idx->index.get());
                TypePtr index_type = infer_type(idx->index.get());
                if (!is_integer_type(index_type)) {
                    report_error("Vector index must be an integer type");
                    continue;
                }

                handle_expression(value);
                TypePtr rhs_type = infer_type(value);
                if (!check_type_compatibility(vec_type->element_type, rhs_type)) {
                    report_error(
                        "Type mismatch in vector element assignment: expected " +
                        type_to_string(vec_type->element_type) +
                        ", got " + type_to_string(rhs_type));
                }

                continue;
            }

            report_error("Invalid assignment target: not an assignable expression");
        }
        return;
    }
    if(auto ifs = dynamic_cast<IfStmt*>(stmt)){
        handle_expression(ifs->condition.get());
        TypePtr cond_type = infer_type(ifs->condition.get());
        auto prim_type = dynamic_cast<PrimitiveType*>(cond_type.get());
        if(!prim_type || prim_type->type != PrimitiveTypeEnum::BOOL){
            report_error("If condition must be boolean type, got " + type_to_string(cond_type));
        }

        if(ifs->then_block){
            handle_statement(ifs->then_block.get());
        }
        if(ifs->else_block.has_value()){
            handle_statement(ifs->else_block.value().get());
        }
        if(ifs->else_if.has_value()){
            handle_statement(ifs->else_if.value().get());
        }
        return;
    }

    if(auto wh = dynamic_cast<WhileStmt*>(stmt)){
        handle_expression(wh->condition.get());
        TypePtr cond_type = infer_type(wh->condition.get());
        auto prim_type = dynamic_cast<PrimitiveType*>(cond_type.get());
        if(!prim_type || prim_type->type != PrimitiveTypeEnum::BOOL){
            report_error("While condition must be boolean type, got " + type_to_string(cond_type));
        }

        bool was_in_loop = in_loop;
        in_loop = true;
        if(wh->body){
            handle_statement(wh->body.get());
        }
        in_loop = was_in_loop;
        return;
    }

    if(auto forst = dynamic_cast<ForStmt*>(stmt)){
        handle_expression(forst->iterable.get());
        TypePtr iter_type = infer_type(forst->iterable.get());

        bool is_valid_iterable = false;
        TypePtr element_type = nullptr;

        if(is_vector_type(iter_type)){
            is_valid_iterable = true;
            if(auto vec_type = dynamic_cast<VectorType*>(iter_type.get())){
                if(vec_type->element_type){
                    element_type = vec_type->element_type->clone();
                }
            }
        } else if(auto range_expr = dynamic_cast<RangeExpr*>(forst->iterable.get())){
            is_valid_iterable = true;
            element_type = std::make_unique<PrimitiveType>(PrimitiveTypeEnum::I64);
        }

        if(!is_valid_iterable){
            report_error("For loop iterable must be a vector or range type, got " + type_to_string(iter_type));
        }

        sym_table.enter_scope();

        Symbol iter_sym;
        iter_sym.name = forst->iterator;
        iter_sym.kind = SymbolKind::VARIABLE;
        iter_sym.line_number = current_line;

        if(element_type){
            iter_sym.type = element_type->clone();
        } else {
            iter_sym.type = std::make_unique<PrimitiveType>(PrimitiveTypeEnum::I64);
        }

        sym_table.add_symbol(iter_sym);

        bool was_in_loop = in_loop;
        in_loop = true;
        if(forst->body){
            handle_statement(forst->body.get());
        }
        in_loop = was_in_loop;

        sym_table.leave_scope();
        return;
    }


    if(auto repeat_stmt = dynamic_cast<RepeatStmt*>(stmt)){
        handle_expression(repeat_stmt->count.get());
        TypePtr count_type = infer_type(repeat_stmt->count.get());

        if(!is_integer_type(count_type)){
            report_error("Repeat count must be an integer type, got " + type_to_string(count_type));
        }

        bool was_in_loop = in_loop;
        in_loop = true;
        if(repeat_stmt->body){
            handle_statement(repeat_stmt->body.get());
        }
        in_loop = was_in_loop;
        return;
    }

    if(auto ret = dynamic_cast<ReturnStmt*>(stmt)){

        if(current_function_return_types.empty()){
            report_error("Return statement outside of function");
            return;
        }

        if(ret->values.size() != current_function_return_types.size()){
            report_error("Return statement expects " + std::to_string(current_function_return_types.size()) + 
                         " values, got " + std::to_string(ret->values.size()));
            return;
        }

        for(size_t i = 0; i < current_function_return_types.size(); ++i){
            if(i >= ret->values.size() || !ret->values[i]){
                report_error("Return value " + std::to_string(i+1) + " is missing");
                continue;
            }
            handle_expression(ret->values[i].get());
            TypePtr return_type = infer_type(ret->values[i].get());

            if(!check_type_compatibility(current_function_return_types[i], return_type)){
                report_error("Return type mismatch for value " + std::to_string(i+1) + ": expected " +
                             type_to_string(current_function_return_types[i]) + ", got " + type_to_string(return_type));
            }
        }
        return;

    }

    if(auto break_stmt = dynamic_cast<BreakStmt*>(stmt)){
        if(!in_loop){
            report_error("Break statement outside of loop");
        }
        return;
    }

    if(auto continue_stmt = dynamic_cast<ContinueStmt*>(stmt)){
        if(!in_loop){
            report_error("Continue statement outside of loop");
        }
        return;
    }

    if(auto exprs = dynamic_cast<ExprStmt*>(stmt)){
        if(exprs->expr){
            handle_expression(exprs->expr.get());
        }
        return;
    }
}

void SemanticAnalyzer::handle_expression(Expression* expr){
    if(!expr) return;

    if(auto id = dynamic_cast<IdentifierExpr*>(expr)){
        if(!sym_table.find(id->name)){
            llvm::errs() << "[semantic] warning: undeclared identifier: " << id->name << "\n";
        }
        return;
    }

    if(auto lit = dynamic_cast<LiteralExpr*>(expr)){
        return;
    }

    if(auto call = dynamic_cast<FunctionCallExpr*>(expr)){
        Symbol* fn = sym_table.find(call->callee);
        if (!fn) {
            report_error("Undeclared function '" + call->callee + "'");
        }

        for(auto& a : call->arguments){
            handle_expression(a.get());
        }
        return;
    }

    if(auto un = dynamic_cast<UnaryExpression*>(expr)){
        TypePtr operand_type = infer_type(un->operand.get());
        check_unary_operation(un->op, operand_type, current_line);
        handle_expression(un->operand.get());
        return;
    }

    if(auto bin = dynamic_cast<BinaryExpression*>(expr)){
        TypePtr left_type = infer_type(bin->left.get());
        TypePtr right_type = infer_type(bin->right.get());
        check_binary_operation(bin->op, left_type, right_type, current_line);
        handle_expression(bin->left.get());
        handle_expression(bin->right.get());
        return;
    }

    if(auto cast_expr = dynamic_cast<TypeCastExpr*>(expr)){
        TypePtr from_type = infer_type(cast_expr->expr.get());
        TypePtr to_type = cast_expr->type->clone();

        if(!can_cast_to(from_type, to_type)){
            report_error("Cannot cast from " + type_to_string(from_type) + " to " + type_to_string(to_type));
        }
        handle_expression(cast_expr->expr.get());
        return;
    }
}

TypePtr SemanticAnalyzer::infer_type(Expression* expr){
    if(!expr){
        return nullptr;
    }

    if(auto int_lit = dynamic_cast<IntegerLiteral*>(expr)){
        return std::make_unique<PrimitiveType>(PrimitiveTypeEnum::I64);
    }

    if(auto float_lit = dynamic_cast<FloatLiteral*>(expr)){
        return std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64);
    }

    if(auto complex_lit = dynamic_cast<ComplexLiteral*>(expr)){
        return std::make_unique<PrimitiveType>(PrimitiveTypeEnum::C64);
    }

    if(auto bool_lit = dynamic_cast<BoolLiteral*>(expr)){
        return std::make_unique<PrimitiveType>(PrimitiveTypeEnum::BOOL);
    }

    if(auto str_lit = dynamic_cast<StringLiteral*>(expr)){
        return std::make_unique<PrimitiveType>(PrimitiveTypeEnum::STR);
    }

    if(auto pi_lit = dynamic_cast<PiLiteral*>(expr)){
        return std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64);
    }

    if (auto vec_lit = dynamic_cast<VectorLiteralExpr*>(expr)) {

        // If we inferred before, reuse it
        if (vec_lit->inferred_type) {
            return vec_lit->inferred_type->clone();
        }

        // Empty vector → default element type = i64
        TypePtr element_type;
        if (vec_lit->elements.empty()) {
            element_type = std::make_unique<PrimitiveType>(PrimitiveTypeEnum::I64);
        } else {
            element_type = infer_type(vec_lit->elements[0].get());
        }

        // Build vector type with element type + fixed size
        auto vec_type = std::make_unique<VectorType>(element_type->clone());
        vec_type->fixed_length = vec_lit->elements.size();

        // Cache inside literal
        vec_lit->inferred_type = vec_type->clone();

        return vec_type;
    }
    if (auto id = dynamic_cast<IdentifierExpr*>(expr)) {

        Symbol* sym = sym_table.find(id->name);
        if (!sym) {
            report_error("Undeclared identifier '" + id->name + "'");
            return nullptr;
        }
        if (!sym->type) {
            report_error("Identifier '" + id->name + "' has no type");
            return nullptr;
        }

        if (auto* vt = dynamic_cast<VectorType*>(sym->type.get())) {

            auto cloned = std::make_unique<VectorType>(vt->element_type->clone());
            cloned->fixed_length = vt->fixed_length;

            return cloned;
        }

        return sym->type->clone();
    }


    if (auto un = dynamic_cast<UnaryExpression*>(expr)) {
        TypePtr operand_type = infer_type(un->operand.get());

        if (operand_type) {
            return operand_type->clone();
        }
        return std::make_unique<PrimitiveType>(PrimitiveTypeEnum::I64);
    }


    if(auto bin = dynamic_cast<BinaryExpression*>(expr)){
        TypePtr left_type = infer_type(bin->left.get());
        TypePtr right_type = infer_type(bin->right.get());

        switch(bin->op){
            case BinaryOp::EQUALS:
            case BinaryOp::NOTEQUAL:
            case BinaryOp::LESSTHAN:
            case BinaryOp::GREATERTHAN:
            case BinaryOp::LESSTHANEQUAL:
            case BinaryOp::GREATERTHANEQUAL:
            case BinaryOp::AND:
            case BinaryOp::OR:
                return std::make_unique<PrimitiveType>(PrimitiveTypeEnum::BOOL);
            default:
                if (is_vector_type(left_type)) {
                    auto* LV = dynamic_cast<VectorType*>(left_type.get());
                    auto out = std::make_unique<VectorType>(LV->element_type->clone());
                    out->fixed_length = 0;
                    return out;
                }
                return left_type ? left_type->clone()
                : std::make_unique<PrimitiveType>(PrimitiveTypeEnum::I64);

        }
    }

    if(auto cast_expr = dynamic_cast<TypeCastExpr*>(expr)){
        return cast_expr->type->clone();
    }

    if(auto call = dynamic_cast<FunctionCallExpr*>(expr)){
        Symbol* sym = sym_table.find(call->callee);
        if(sym && sym->kind == SymbolKind::FUNCTION){
            if(sym->type){
                return sym->type->clone();
            }
        }
    }

    if (auto* idx = dynamic_cast<const IndexExpression*>(expr)) {
        TypePtr t = get_index_expr_type(idx);
        if (!t) {
            report_error("Indexing non-vector type");
        }
        return t;
    }


    return std::make_unique<PrimitiveType>(PrimitiveTypeEnum::I64);
}

bool SemanticAnalyzer::check_type_compatibility(const TypePtr& left, const TypePtr& right){
    if(!left || !right){
        return false;
    }

    if (auto Lp = dynamic_cast<PrimitiveType*>(left.get())) {
        auto Rp = dynamic_cast<PrimitiveType*>(right.get());
        if (!Rp) return false;


        if (Lp->type == Rp->type)
            return true;

        bool left_is_complex =
            (Lp->type == PrimitiveTypeEnum::C32 ||
            Lp->type == PrimitiveTypeEnum::C64);

        bool right_is_int_or_float =
            is_integer_type(right) || is_float_type(right);

        if (left_is_complex && right_is_int_or_float)
            return true;

        if (Lp->type == PrimitiveTypeEnum::C64 &&
            Rp->type == PrimitiveTypeEnum::C32)
            return true;

        return false;

    }

    if (auto Ls = dynamic_cast<StructType*>(left.get())) {
        auto Rs = dynamic_cast<StructType*>(right.get());
        if (!Rs) return false;

        return Ls->name == Rs->name;
    }

    if (auto Lv = dynamic_cast<VectorType*>(left.get())) {
        auto Rv = dynamic_cast<VectorType*>(right.get());
        if (!Rv) return false;

        if (!check_type_compatibility(Lv->element_type, Rv->element_type))
            return false;

        if (Lv->fixed_length != 0 &&
            Rv->fixed_length != 0 &&
            Lv->fixed_length != Rv->fixed_length)
            return false;

        return true;
    }
    return false;
}

bool SemanticAnalyzer::is_assignable(const TypePtr& left, const TypePtr& right){
    return check_type_compatibility(left, right);
}

bool SemanticAnalyzer::can_cast_to(const TypePtr& from, const TypePtr& to){
    if(!from || !to) return false;

    auto from_prim = dynamic_cast<PrimitiveType*>(from.get());
    auto to_prim = dynamic_cast<PrimitiveType*>(to.get());

    if(!from_prim || !to_prim) return false;

    if(is_numeric_type(from) && is_numeric_type(to)){
        return true;
    }

    return false;
}

void SemanticAnalyzer::check_binary_operation(BinaryOp op, const TypePtr& left, const TypePtr& right, int line){
    if(!left || !right) return;

    bool left_is_vector = is_vector_type(left);
    bool right_is_vector = is_vector_type(right);

    switch(op){
        case BinaryOp::PLUS:
        case BinaryOp::MINUS:
            if(left_is_vector && right_is_vector){
                auto left_vec = dynamic_cast<VectorType*>(left.get());
                auto right_vec = dynamic_cast<VectorType*>(right.get());
                if(!check_type_compatibility(left_vec->element_type, right_vec->element_type)){
                    report_error("Vector operation requires compatible element types");
                }
            } else if(!left_is_vector && !right_is_vector){
                if(!is_numeric_type(left) || !is_numeric_type(right)){
                    report_error("Arithmetic operation requires numeric types or vector types(same element type)");
                }
            } else {
                report_error("Cannot mix vector and scalar in addition/subtraction");
            }
            break;

        case BinaryOp::MULTIPLY:
        case BinaryOp::DIVIDE:
            if(left_is_vector && !right_is_vector){
                if(!is_numeric_type(right)){
                    report_error("Scalar must be numeric type");
                }
            } else if(!left_is_vector && right_is_vector){
                // Scalar multiplication
                if(op == BinaryOp::DIVIDE){
                    report_error("Cannot divide scalar by vector");
                }
                if(!is_numeric_type(left)){
                    report_error("Scalar must be numeric type");
                }
            } else if(left_is_vector && right_is_vector){
                report_error("Element-wise multiplication not supported, use convolution (.) for vectors");
            } else {
                if(!is_numeric_type(left) || !is_numeric_type(right)){
                    report_error("Arithmetic operation requires numeric types");
                }
            }
            break;

        case BinaryOp::CONVOLUTION:
            if(!left_is_vector || !right_is_vector){
                report_error("Convolution requires vector types");
            } else {
                auto left_vec = dynamic_cast<VectorType*>(left.get());
                auto right_vec = dynamic_cast<VectorType*>(right.get());
                if(!check_type_compatibility(left_vec->element_type, right_vec->element_type)){
                    report_error("Convolution requires vectors with compatible element types");
                }
            }
            break;

        case BinaryOp::MODULO:
        case BinaryOp::BITWISEAND:
        case BinaryOp::BITWISEOR:
        case BinaryOp::XOR:
        case BinaryOp::LEFTSHIFT:
        case BinaryOp::RIGHTSHIFT:
            if(!is_integer_type(left) || !is_integer_type(right)){
                report_error("Bitwise operation requires integer types");
            }
            break;

        case BinaryOp::AND:
        case BinaryOp::OR:
            if(!dynamic_cast<PrimitiveType*>(left.get()) || 
                !dynamic_cast<PrimitiveType*>(right.get())){
                report_error("Logical operation requires boolean types");
            }
            break;

        default:
            break;
    }
}

void SemanticAnalyzer::check_unary_operation(UnaryOp op, const TypePtr& operand, int line){
    if(!operand) return;

    switch(op){
        case UnaryOp::MINUS:
        case UnaryOp::PLUS:
            if(!is_numeric_type(operand)){
                report_error("Unary +/- requires numeric type");
            }
            break;

        case UnaryOp::NOT:
            if(auto prim = dynamic_cast<PrimitiveType*>(operand.get())){
                if(prim->type != PrimitiveTypeEnum::BOOL){
                    report_error("Unary ! requires boolean type");
                }
            }
            break;

        case UnaryOp::REVERSE:
            if(!is_vector_type(operand)){
                report_error("Reverse operator @ requires vector type");
            }
            break;
    }
}

bool SemanticAnalyzer::is_numeric_type(const TypePtr& type){
    return is_integer_type(type) || is_float_type(type) || is_complex_type(type);
}

bool SemanticAnalyzer::is_integer_type(const TypePtr& type){
    auto prim = dynamic_cast<PrimitiveType*>(type.get());
    if(!prim) return false;

    switch(prim->type){
        case PrimitiveTypeEnum::I8:
        case PrimitiveTypeEnum::I16:
        case PrimitiveTypeEnum::I32:
        case PrimitiveTypeEnum::I64:
        case PrimitiveTypeEnum::I128:
        case PrimitiveTypeEnum::U8:
        case PrimitiveTypeEnum::U16:
        case PrimitiveTypeEnum::U32:
        case PrimitiveTypeEnum::U64:
        case PrimitiveTypeEnum::U128:
            return true;
        default:
            return false;
    }
}

bool SemanticAnalyzer::is_float_type(const TypePtr& type){
    auto prim = dynamic_cast<PrimitiveType*>(type.get());
    if(!prim) return false;
    return prim->type == PrimitiveTypeEnum::F32 || prim->type == PrimitiveTypeEnum::F64;
}

bool SemanticAnalyzer::is_complex_type(const TypePtr& type){
    auto prim = dynamic_cast<PrimitiveType*>(type.get());
    if(!prim) return false;
    return prim->type == PrimitiveTypeEnum::C32 || prim->type == PrimitiveTypeEnum::C64;
}

bool SemanticAnalyzer::is_vector_type(const TypePtr& type){
    return dynamic_cast<VectorType*>(type.get()) != nullptr;
}

std::string SemanticAnalyzer::type_to_string(const TypePtr& type){
    if(!type) return "unknown";

    if(auto prim = dynamic_cast<PrimitiveType*>(type.get())){
        return primitive_type_to_string(prim->type);
    } else if(auto vec = dynamic_cast<VectorType*>(type.get())){
        return "vec<" + type_to_string(vec->element_type) + ">";
    } else if(auto struct_type = dynamic_cast<StructType*>(type.get())){
        return "struct " + struct_type->name;
    }

    return "unknown";
}

std::string SemanticAnalyzer::primitive_type_to_string(PrimitiveTypeEnum type){
    switch(type){
        case PrimitiveTypeEnum::I8: return "i8";
        case PrimitiveTypeEnum::I16: return "i16";
        case PrimitiveTypeEnum::I32: return "i32";
        case PrimitiveTypeEnum::I64: return "i64";
        case PrimitiveTypeEnum::I128: return "i128";
        case PrimitiveTypeEnum::U8: return "u8";
        case PrimitiveTypeEnum::U16: return "u16";
        case PrimitiveTypeEnum::U32: return "u32";
        case PrimitiveTypeEnum::U64: return "u64";
        case PrimitiveTypeEnum::U128: return "u128";
        case PrimitiveTypeEnum::F32: return "f32";
        case PrimitiveTypeEnum::F64: return "f64";
        case PrimitiveTypeEnum::C32: return "c32";
        case PrimitiveTypeEnum::C64: return "c64";
        case PrimitiveTypeEnum::BOOL: return "bool";
        case PrimitiveTypeEnum::STR: return "str";
        default: return "unknown";
    }
}

void SemanticAnalyzer::report_error(const std::string& msg){
    errors.push_back("[semantic] error: " + msg);
}

bool SemanticAnalyzer::has_errors() const{
    return !errors.empty();
}

void SemanticAnalyzer::print_errors() const{
    for(const auto& err : errors){
        std::cerr << err << std::endl;
    }
}

TypePtr SemanticAnalyzer::get_index_expr_type(const IndexExpression* idx) {

    if (auto* id = dynamic_cast<IdentifierExpr*>(idx->object.get())) {
        Symbol* sym = sym_table.find(id->name);
        if (sym && sym->type) {
            if (auto* vt = dynamic_cast<VectorType*>(sym->type.get())) {
                return vt->element_type->clone();
            }
        }
    }

    TypePtr t = infer_type(idx->object.get());
    if (auto* vt = dynamic_cast<VectorType*>(t.get())) {
        auto out = vt->element_type->clone();
        return out;
    }
    report_error("Indexing a non-vector type");
    return nullptr;
}

