#include "semanticAnalyzer.h"

SymbolTable::SymbolTable(){
    enterScope();
};

void SymbolTable:: enterScope(){
    scopes.emplace_back();
}

void SymbolTable:: leaveScope(){
    scopes.pop_back();
}

bool SymbolTable::addSymbol(Symbol sym){
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


void SemanticAnalyzer::handleNode(ASTNode* node){
    if( auto func_decl = dynamic_cast<FunctionDecl*>(node)){
        handleFunction(func_decl);
    } else if(auto struct_decl = dynamic_cast<StructDecl*>(node)) {
        handleStruct(struct_decl);
    } else if(auto stmt = dynamic_cast<Statement*>(node)) {
        handleStatement(stmt);
    } else if(auto expr = dynamic_cast<Expression*>(node)){
        handleExpression(expr);
    }
}

void SemanticAnalyzer::handleFunction(FunctionDecl* func_decl){
    // TODO: handle function
}

void handleStruct(StructDecl* struct_decl){
    //TODO: handle struct
}

void handleStatement(Statement* stmt){
    //TODO: handle statement
}

void handleExpression(Expression* expr){
    //TODO: handle Expression
}

TypePtr inferType(Expression* expr){
    //TODO: handle Expression
    return nullptr;
}
