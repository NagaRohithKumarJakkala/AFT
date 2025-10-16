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
    ;
%%

int main(){
    yyparse();
    return 0;
}

void yyerror(const char*s){
    fprintf(stderr,"error: %s\n",s);
}

