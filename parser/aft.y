%{
    #include<stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "AST.h"
    extern int yylex();
    extern int yylineno;
    extern char *yytext;

    void yyerror(const char*s);
%}

%union {
    char* sval;
}

%token <sval> INTEGER FLOAT COMPLEX IDENTIFIER STRING
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
%token CONVOLUTION REVERSE
%token RANGE RANGEUPTO

%token ASSIGN COMMA SEMICOLON COLON DOT
%token LEFTBRACE RIGHTBRACE LEFTPAREN RIGHTPAREN LEFTSQUARE RIGHTSQUARE

%token EOL


%type program
%type function_decl
%type statement let_decl const_decl assignment if_stmt while_stmt for_stmt repeat_stmt return_stmt
%type statement_list statement_block
%type expression
%type literal vector_literal range_expr
%type expression_list vector_elements
%type type primitive_type vector_type
%type type_list return_type_list
%type parameter
%type parameter_list

%left RETURN
%left COMMA
%right ASSIGN
%left OR
%left AND
%left EQUALS NOTEQUAL LESSTHAN GREATERTHAN LESSTHANEQUAL GREATERTHANEQUAL
%left BITWISEOR
%left XOR
%left BITWISEAND
%left LEFTSHIFT RIGHTSHIFT
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO CONVOLUTION
%right EXPONENTIATE
%right AS
%right NOT
%left LEFTPAREN LEFTSQUAREBRACE DOT

%start program

%%

program:
    /* empty */ {
    }
    | program function_decl {
    }
    | program const_decl {
    }
    | program struct_decl {
    }
    ;

struct_decl:
    STRUCT IDENTIFIER LEFTBRACE RIGHTBRACE {}
    | STRUCT IDENTIFIER LEFTBRACE parameter_list RIGHTBRACE {}
    ;

function_decl:
    FUNCTION IDENTIFIER LEFTPAREN parameter_list RIGHTPAREN return_type_list statement_block {
    }
    |
    FUNCTION IDENTIFIER LEFTPAREN RIGHTPAREN return_type_list statement_block {

    }
    ;

parameter_list:
    parameter {

    }
    | parameter_list COMMA parameter {

    }
    ;

parameter:
    IDENTIFIER COLON type {

    }
    ;

return_type_list:
    /* empty */ {

    }
    | type {

    }
    | LEFTPAREN type_list RIGHTPAREN {

    }
    ;

type_list:
    type {

    }
    | type_list COMMA type {

    }
    ;

type:
    primitive_type {

    }
    | vector_type {

    }
    | IDENTIFIER { // Struct
    }
    ;

primitive_type:
    I8 {

    }
    | I16 {

    }
    | I32 {

    }
    | I64 {

    }
    | I128 {

    }
    | U8 {

    }
    | U16 {

    }
    | U32 {

    }
    | U64 {

    }
    | U128 {

    }
    | F32 {

    }
    | F64 {

    }
    | C32 {

    }
    | C64 {

    }
    | BOOL {

    }

vector_type:
    LEFTSQUARE type RIGHTSQUARE {

    }
    ;

statement_block:
    LEFTBRACE statement_list RIGHTBRACE {

    }
    | LEFTBRACE RIGHTBRACE {

    }
    ;

statement_list:
    statement {

    }
    | statement_list statement {

    }
    ;

statement :
    let_decl SEMICOLON {

    }
    | const_decl SEMICOLON {

    }
    | assignment SEMICOLON {

    }
    | expression SEMICOLON {

    }
    | if_stmt {

    }
    | while_stmt {

    }
    | for_stmt {

    }
    | repeat_stmt {

    }
    | return_stmt SEMICOLON {

    }
    | BREAK SEMICOLON {

    }
    | CONTINUE SEMICOLON {

    }
    ;



let_decl:
    LET IDENTIFIER ASSIGN expression {

    }
    | LET IDENTIFIER COLON type ASSIGN expression {

    }
    | LET LEFTPAREN identifier_list RIGHTPAREN ASSIGN expression_list {

    }
    | LET LEFTPAREN identifier_list RIGHTPAREN COLON LEFTPAREN type_list RIGHTPAREN ASSIGN expression_list {

    }
    ;

const_decl:
    CONST IDENTIFIER COLON type ASSIGN expression {

    }
    | CONST LEFTPAREN identifier_list RIGHTPAREN COLON LEFTPAREN type_list RIGHTPAREN ASSIGN expression_list {

    }
    ;

identifier_list:
    IDENTIFIER COMMA IDENTIFIER {

    }
    | identifier_list COMMA IDENTIFIER {

    }
    ;

assignment:
    IDENTIFIER ASSIGN expression {

    }
    | LEFTPAREN identifier_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN {

    }
    ;

if_stmt:
    IF expression statement_block {

    }
    | IF expression statement_block ELSE statement_block {

    }
    | IF expression statement_block ELSE if_stmt {

    }
    ;

while_stmt:
    WHILE expression statement_block {

    }
    ;

for_stmt:
    FOR IDENTIFIER IN expression statement_block {

    }
    ;

repeat_stmt:
    REPEAT expression statement_block {

    }
    ;

return_stmt:
    RETURN expression_list {

    }
    | RETURN {

    }
    ;

expression:
    /* empty */  {
        // write the grammer for expression later
    }

expression_list:
    expression {

    }
    | expression_list COMMA expression {

    }
    ;

literal:
    INTEGER {

    }
    | FLOAT {

    }
    | COMPLEX {

    }
    | TRUE {

    }
    | FALSE {

    }
    | PI {

    }
    | vector_literal {

    }
    | STRING {}
    ;

vector_literal:
    LEFTSQUARE vector_elements RIGHTSQUARE {}
    | LEFTSQUARE RIGHTSQUARE {}

vector_elements:
    expression {

    }
    | vector_elements COMMA expression {

    }
    ;

range_expr:
    expression RANGE expression {

    }
    | expression RANGEUPTO expression {

    }
    ;

%%

int main(int argc, char** argv) {
    if (argc > 1) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
            return 1;
        }
        extern FILE* yyin;
        yyin = file;
    }

    yyparse();

    return 0;
}

void yyerror(const char*s) {
    fprintf(stderr, "Parse error at line %d: %s\n", yylineno, s);
    fprintf(stderr, "Near token: %s\n", yytext);
}
