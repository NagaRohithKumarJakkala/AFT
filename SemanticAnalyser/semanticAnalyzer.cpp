#include "semanticAnalyzer.h"
#include <iostream>

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

SemanticAnalyzer::SemanticAnalyzer(){
    builtin_functions.insert("print");
    builtin_functions.insert("printf");
    builtin_functions.insert("sin");
    builtin_functions.insert("cos");
    builtin_functions.insert("sqrt");
    builtin_functions.insert("pow");
    builtin_functions.insert("exp");
    builtin_functions.insert("log");
    builtin_functions.insert("dbg");

    Symbol pi_const;
    pi_const.name = "PI";
    pi_const.kind = SymbolKind::VARIABLE;
    pi_const.type = std::make_unique<PrimitiveType>(PrimitiveTypeEnum::F64);
    pi_const.is_const = true;
    sym_table.add_symbol(pi_const);
    
}

bool SemanticAnalyzer::is_builtin_function(const std::string& name){
    return builtin_functions.count(name) > 0;
}

SymbolTable& SemanticAnalyzer::get_symbol_table(){
    return sym_table;
}

void SemanticAnalyzer::check(Program* program){
    if(!program) return;
    
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
        func_sym.type = funcDecl->return_types[0]->clone();
        current_function_return_type = funcDecl->return_types[0]->clone();
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
    current_function_return_type = nullptr;
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
    
    if(auto asgn = dynamic_cast<Assignment*>(stmt)){
        for(size_t i = 0; i < asgn->targets.size(); ++i){
            Symbol* sym = sym_table.find(asgn->targets[i]);
            if(!sym){
                report_error("Undeclared variable '" + asgn->targets[i] + "'");
                continue;
            }
            
            if(sym->is_const){
                report_error("Cannot assign to const variable '" + asgn->targets[i] + "'");
                continue;
            }
            
            if(i < asgn->values.size() && asgn->values[i]){
                TypePtr value_type = infer_type(asgn->values[i].get());
                if(!check_type_compatibility(sym->type, value_type)){
                    report_error("Type mismatch in assignment to '" + asgn->targets[i] + 
                              "': expected " + type_to_string(sym->type) + 
                              ", got " + type_to_string(value_type));
                }
            }
        }
        return;
    }
    
    if(auto ifs = dynamic_cast<IfStmt*>(stmt)){
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
        if(!current_function_return_type){
            report_error("Return statement outside of function");
            return;
        }
        
        if(ret->values.empty() && current_function_return_type){
            report_error("Function expects return value of type " + type_to_string(current_function_return_type));
        } else if(!ret->values.empty()){
            TypePtr return_type = infer_type(ret->values[0].get());
            if(!check_type_compatibility(current_function_return_type, return_type)){
                report_error("Return type mismatch: expected " + type_to_string(current_function_return_type) + 
                          ", got " + type_to_string(return_type));
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
        if(!is_builtin_function(call->callee)){
            Symbol* fn = sym_table.find(call->callee);
            if(!fn){
                report_error("Undeclared function '" + call->callee + "'");
            }
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
    
    if(auto vec_lit = dynamic_cast<VectorLiteralExpr*>(expr)){
        if(!vec_lit->elements.empty()){
            TypePtr elem_type = infer_type(vec_lit->elements[0].get());
            return std::make_unique<VectorType>(elem_type->clone());
        }
        return std::make_unique<VectorType>(std::make_unique<PrimitiveType>(PrimitiveTypeEnum::I64));
    }
    
    if(auto id = dynamic_cast<IdentifierExpr*>(expr)){
        Symbol* sym = sym_table.find(id->name);
        if(!sym){
            report_error("Undeclared identifier '" + id->name + "'");
            return std::make_unique<PrimitiveType>(PrimitiveTypeEnum::I64);
        }
        if(sym->type){
            return sym->type->clone();
        }
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
                if(left_type){
                    return left_type->clone();
                }
                return std::make_unique<PrimitiveType>(PrimitiveTypeEnum::I64);
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
    
    return std::make_unique<PrimitiveType>(PrimitiveTypeEnum::I64);
}

bool SemanticAnalyzer::check_type_compatibility(const TypePtr& left, const TypePtr& right){
    if(!left || !right){
        return false;
    }
    
    Types& L = *left;
    Types& R = *right;
    
    if(typeid(L) != typeid(R)){
        return false;
    }
    
    if(auto left_prim = dynamic_cast<PrimitiveType*>(left.get())){
        auto right_prim = dynamic_cast<PrimitiveType*>(right.get());
        if(left_prim->type == right_prim->type){
            return true;
        }
    }
    
    if(auto left_struct = dynamic_cast<StructType*>(left.get())){
        auto right_struct = dynamic_cast<StructType*>(right.get());
        if(left_struct->name == right_struct->name){
            return true;
        }
    }
    
    if(auto left_vec = dynamic_cast<VectorType*>(left.get())){
        auto right_vec = dynamic_cast<VectorType*>(right.get());
        if(check_type_compatibility(left_vec->element_type, right_vec->element_type)){
            return true;
        }
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
    
    switch(op){
        case BinaryOp::PLUS:
        case BinaryOp::MINUS:
        case BinaryOp::MULTIPLY:
        case BinaryOp::DIVIDE:
            if(!is_numeric_type(left) || !is_numeric_type(right)){
                report_error("Arithmetic operation requires numeric types");
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
            
        case BinaryOp::CONVOLUTION:
            if(!is_vector_type(left) || !is_vector_type(right)){
                report_error("Convolution requires vector types");
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
