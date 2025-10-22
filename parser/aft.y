%{
    #include<stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "AST.h"
    extern int yylex();
    extern int yylineno;

    void yyerror(const char*s);
%}

%union {
    char* sval;
}

%token <sval> INTEGER FLOAT COMPLEX IDENTIFIER
%token  TRUE FALSE
%token  PI

%token LET CONST FUNCTION RETURN IF ELSE WHILE FOR IN REPEAT
%token STRUCT ENUM AS CONTINUE BREAK STATIC

%token I8 I16 I32 I64 I128
%token U8 U16 U32 U64 U128
%token F32 F64 C32 C64 BOOL

%token PLUS MINUS MULTIPLY DIVIDE MODULO EXPONENTIATE
%token EQUALS NOTEQUAL LESSTHAN GREATERTHAN LESSTHANEQUAL GREATERTHANEQUAL
%token AND OR XOR NOT
%token BITWISEAND BITWISEOR LEFTSHIFT RIGHTSHIFT
%token CONVOLUTION
%token RANGE RANGEUPTO

%token ASSIGN COMMA SEMICOLON COLON DOT
%token LEFTBRACE RIGHTBRACE LEFTPAREN RIGHTPAREN LEFTSQUAREBRACE RIGHTSQUAREBRACE

%token EOL
%start S

%%
    S:
    ;
%%

int main(){
    yyparse();
    return 0;
}

void yyerror(const char*s){
    fprintf(stderr,"error: %s\n",s);
}

