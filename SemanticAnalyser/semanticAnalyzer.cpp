#include "semanticAnalyzer.h"

SymbolTable::SymbolTable(){
    enter_scope();
};

void SymbolTable:: enter_scope(){
    scopes.emplace_back();
}

void SymbolTable:: leave_scope(){
    scopes.pop_back();
}

bool SymbolTable::add_symbol(Symbol sym){
    auto& currentScope = scopes.back();
    if(currentScope.count(sym.name)) return false;
    currentScope[sym.name]=std::move(sym);
    return true;
}

Symbol* SymbolTable::find(const std::string& name){
    for(auto it = scopes.rbegin();it!=scopes.rend();++it){
        auto found = it->find(name);
        if(found!=it->end()) return &found->second;
    }
    return nullptr;
}


SymbolTable& SemanticAnalyzer::get_symbol_table(){
    return sym_table;
}


void SemanticAnalyzer::handle_node(ASTNode* node){
    if( auto func_decl = dynamic_cast<FunctionDecl*>(node)){
        handle_function(func_decl);
    } else if(auto struct_decl = dynamic_cast<StructDecl*>(node)) {
        handle_struct(struct_decl);
    } else if(auto stmt = dynamic_cast<Statement*>(node)) {
        handle_statement(stmt);
    } else if(auto expr = dynamic_cast<Expression*>(node)){
        handle_expression(expr);
    }
}

void SemanticAnalyzer::handle_function(FunctionDecl* funcDecl){
    Symbol sym;
    sym.name = funcDecl->name;
    sym.kind = SymbolKind::FUNCTION;
    for ( auto& param : funcDecl->params) {
        sym.parameter_types.push_back(param->type);
    }
    sym.type =nullptr;
    sym_table.add_symbol(sym);
    sym_table.enter_scope();
    for (auto &p : funcDecl->params) {
        Symbol ps; ps.name = p->name;
         ps.kind = SymbolKind::PARAMETER;
         ps.type = p->type->clone();
        sym_table.add_symbol(ps);
    }
    if (funcDecl->body) {
        handle_statement(funcDecl->body);
    }
    sym_table.leave_scope();
    
}

void SemanticAnalyzer::handle_struct(StructDecl* structDecl){
    Symbol sym; 
    sym.name = structDecl->name; 
    sym.kind = SymbolKind::STRUCT;
    sym.type = nullptr;
    sym_table.add_symbol(sym);
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
        for(size_t i=0;i<let->names.size();++i){
            Symbol sym; 
            sym.name = let->names[i]; 
            sym.kind = SymbolKind::VARIABLE;
            if(let->types.size()>i)
                sym.type = let->types[i]->clone();
            sym_table.add_symbol(sym);
            if(let->values.size()>i)
                handle_expression(let->values[i].get());   
        }
        return;
}
if(auto *exprs = dynamic_cast<ExprStmt*>(stmt)){
        handle_expression(exprs->expr.get());
        return;
    }

if(auto *ifs = dynamic_cast<IfStmt*>(stmt)) {
        handle_expression(ifs->condition.get());
        handle_statement(ifs->then_block.get());
        if(ifs->else_block.has_value())
            handle_statement(ifs->else_block.value().get());
        return;
    }
    if(auto *ret = dynamic_cast<ReturnStmt*>(stmt)){
        for(auto &v : ret->values)
            handle_expression(v.get());
        return;
    }
    if(auto *asgn = dynamic_cast<Assignment*>(stmt)){
        for(auto &v : asgn->values)
            handle_expression(v.get());
        return;
    }
    if(auto *forst = dynamic_cast<ForStmt*>(stmt)){
        handle_expression(forst->iterable.get());
        handle_statement(forst->body.get());
        return;
    }
    if(auto *wh = dynamic_cast<WhileStmt*>(stmt)){
        handle_expression(wh->condition.get());
        handle_statement(wh->body.get());
        return;
    }
}

void SemanticAnalyzer::handle_expression(Expression* expr){
    if(!expr) return;
    if(auto *id = dynamic_cast<IdentifierExpr*>(expr)){
        if(!sym_table.find(id->name)){
            errs() << "[semantic] warning: undeclared identifier: " << id->name << "";
        }
        return;
    }

    if(auto *lit = dynamic_cast<LiteralExpr*>(expr)){
        return;
    }
    if(auto *call = dynamic_cast<FunctionCallExpr*>(expr)){
        handle_expression(call->function.get());
        for(auto &a : call->arguments)
            handle_expression(a.get());
        return;
    }
    if(auto *un = dynamic_cast<UnaryExpression*>(expr)){
        handle_expression(un->operand.get());
        return;
    }
}

void SemanticAnalyzer::check(Program* program){
    for(auto &B : program->Blocks){
        handle_node(B.get());
    }

}

TypePtr SemanticAnalyzer::infer_type(Expression* expr){
      if(!expr){
         return nullptr;
      }
       if(auto *id = dynamic_cast<IdentifierExpr*>(expr)){
            Symbol* sym = sym_table.find(id->name);
            if(sym){
                return sym->type->clone();
             }  else {   
                return nullptr;
            }
     }
    if(auto *lit = dynamic_cast<LiteralExpr*>(expr)){
            if(auto *intLit = dynamic_cast<IntegerLiteral*>(lit)){
                 return TypePtr(new PrimitiveType(PrimitiveTypeEnum::I64));
            } else if(auto *floatLit = dynamic_cast<FloatLiteral*>(lit)){
                    return TypePtr(new PrimitiveType(PrimitiveTypeEnum::F64));
            } else if(auto *complexLit = dynamic_cast<ComplexLiteral*>(lit)){
                    return TypePtr(new PrimitiveType(PrimitiveTypeEnum::C64));
           }      
        return nullptr;
    }
    if(auto *un = dynamic_cast<UnaryExpression*>(expr)){
        return infer_type(un->operand.get());
    }
    if(auto *bin = dynamic_cast<BinaryExpression*>(expr)){
        TypePtr leftType = infer_type(bin->left.get());
        TypePtr rightType = infer_type(bin->right.get());
        if(check_type_compatibility(leftType, rightType)){
            return leftType;
        } else {
            return nullptr;
        }
    }
    if(auto *call = dynamic_cast<FunctionCallExpr*>(expr)){
        Symbol* sym = sym_table.find(call->callee);
        if(sym && sym->kind == SymbolKind::FUNCTION){
            return sym->type->clone();
        } else {
            return nullptr;
        }
    }
    return nullptr;
}


bool SemanticAnalyzer::check_type_compatibility(TypePtr left, TypePtr right){
    if(!left || !right) {
        return false;
    }
    if(typeid(*left) == typeid(*right)){
        return true;
    }
    if(auto *leftPrim = dynamic_cast<PrimitiveType*>(left.get())){
        auto *rightPrim = dynamic_cast<PrimitiveType*>(right.get());
        if(leftPrim->type == rightPrim->type){
            return true;
        }
    }
    if(auto *leftStruct = dynamic_cast<StructType*>(left.get())){
        auto *rightStruct = dynamic_cast<StructType*>(right.get());
        if(leftStruct->name == rightStruct->name){
            return true;
        }
    }
    if(auto *leftVec = dynamic_cast<VectorType*>(left.get())){
        auto *rightVec = dynamic_cast<VectorType*>(right.get());
        if(check_type_compatibility(leftVec->element_type, rightVec->element_type)){
            return true;
        }
    }
    return false;
}
bool SemanticAnalyzer::is_assignable(TypePtr left, TypePtr right){
    // if(check_type_compatibility(left, right)){
    //     return true;
    // }
    //  if(auto *leftPrim = dynamic_cast<PrimitiveType*>(left.get())){
    //     auto *rightPrim = dynamic_cast<PrimitiveType*>(right.get());
    //     if(leftPrim->type == PrimitiveTypeEnum::F64 &&
    //        (rightPrim->type == PrimitiveTypeEnum::I64 || rightPrim->type == PrimitiveTypeEnum::F32)){
    //         return true;
    //     }
    // }   
    return false;
}

