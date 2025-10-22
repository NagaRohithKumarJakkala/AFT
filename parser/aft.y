%{
    #include<stdio.h>
    int yylex();
    void yyerror(const char*s);
%}

%token INTEGER
%token FLOAT
%token COMPLEX

%token IDENTIFIER

%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE
%token MODULO

%token EQUALS
%token NOTEQUAL
%token LESSTHAN
%token GREATERTHAN
%token LESSTHANEQUAL
%token GREATERTHANEQUAL

%token AND
%token OR
%token XOR
%token NOT

%token BITWISEAND
%token BITWISEOR
%token LEFTSHIFT
%token RIGHTSHIFT



%token ASSIGN
%token COMMA


%token LEFTBRACE
%token RIGHTBRACE
%token LEFTPAREN
%token RIGHTPAREN
%token LEFTSQUAREBRACE
%token RIGHTSQUAREBRACE
%token COLON
%token SEMICOLON


%token CONVOLUTION
%token EXPONENTIATE

%token I8
%token I16
%token I32
%token I64
%token I128

%token U8
%token U16
%token U32
%token U64
%token U128

%token F32
%token F64

%token C32
%token C64
%token BOOL

%token STRING

%token RANGE
%token RANGEUPTO

%token LET
%token CONST
%token FUNCTION
%token RETURN
%token IF
%token ELSE
%token WHILE
%token FOR
%token REPEAT
%token STRUCT
%token ENUM
%token TRUE
%token FALSE
%token AS
%token CONTINUE
%token BREAK
%token STATIC
%token PI


%token EOL
%start S

%%
    S:
        functions
    ;

    functions:
        functions function
        ;
    function:
        FUNCTION IDENTIFIER LEFTPAREN declaration_list_opt RIGHTPAREN return_type compound_statement
        ;
    
    declaration_list_opt:
        /*empty*/
        | declaration_list
        ;
    declaration_list:
        declaration
        declaration_list COMMA declaration
        ;
    declaration:
        IDENTIFIER COLON data_type
        ;
    return_type:
        ;
    data_type:
      I8 | I16 | I32 | I64 | I128
    | U8 | U16 | U32 | U64 | U128
    | F32 | F64
    | C32 | C64
    | BOOL | STRING
    | IDENTIFIER
    ;
    compound_statement:
        LEFTBRACE statement_list RIGHTBRACE
        ;
    statement_list:
        /*empty*/
        | statement_list statement
        ;
    statement:
        declaration_statement
        | assignment_statement
        | return_statement
        | if_statement
        | while_statement
        | for_statement
        | expression_statement
        ;
    declaration_statement:
        LET declaration ASSIGN expression SEMICOLON
        ;
    assignment_statement:
        IDENTIFIER ASSIGN expression SEMICOLON
        ;
    return_statement:
        RETURN expression SEMICOLON
        ;

    if_statement:
        IF expression compound_statement
        | IF expression compound_statement ELSE compound_statement
        ;
    while_statement:
        WHILE expression compound_statement
        ;
    for_statement:
        FOR IDENTIFIER IN expression compound_statement
        ;
    expression_statement:
        expression SEMICOLON
        ;
    expression:
        INTEGER
        | FLOAT
        | IDENTIFIER
        | expression PLUS expression
        | expression MINUS expression
        | expression MULTIPLY expression
        | expression DIVIDE expression
        | expression MODULO expression
        | expression CONVOLUTION expression
        | expression EXPONENTIATE expression
        | expression RANGE expression
        | expression RANGEUPTO expression
        | expression EQUALS expression
        | expression NOTEQUAL expression
        | expression LESSTHAN expression
        | expression GREATERTHAN expression
        | expression LESSTHANEQUAL expression
        | expression GREATERTHANEQUAL expression
        | expression AND expression
        | expression OR expression
        | expression XOR expression
        | NOT expression
        | expression BITWISEAND expression
        | expression BITWISEOR expression
        | expression LEFTSHIFT expression
        | expression RIGHTSHIFT expression
        ;
%%

int main(){
    yyparse();
    return 0;
}

void yyerror(const char*s){
    fprintf(stderr,"error: %s\n",s);
}

