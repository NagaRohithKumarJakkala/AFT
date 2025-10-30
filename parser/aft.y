%code requires{
    #include<vector>
    #include<memory>
    #include<string>
    #include "../AST_gen/AST.h"

}
%{
    #include<stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include<vector>
    #include<memory>
    #include<string>
    #include "../AST_gen/AST.h"
    extern int yylex();
    extern int yylineno;
    extern char *yytext;
    void yyerror(const char*s);
    Program* ast_root =new Program();
%}

%union {
    char* sval;
    struct ASTNode* Node;
    struct Program* program;
    struct FunctionDecl* function_decl;
    struct StructDecl* struct_decl;
    struct LetDecl* let_decl;
    struct ConstDecl* const_decl;
    struct Statement* statement;
    struct IfStmt* if_stmt;
    struct Expression* expression;
    struct Type* type;
    struct StatementBlock* stmt_block;
    struct Parameter* parameter;
    struct FunctionCallExpr* function_call;
    std::vector<struct Expression*>* expr_list;
    std::vector<struct Statement*>* stmt_list;
    std::vector<struct Type*>* type_list;
    std::vector<struct Parameter*>* param_list;
    std::vector<std::string>* identifier_list;
}

%token <sval> INTEGER FLOAT COMPLEX IDENTIFIER STRING
%token  TRUE FALSE
%token  PI

%token LET CONST FUNCTION RETURN IF ELSE WHILE FOR IN REPEAT
%token STRUCT ENUM AS CONTINUE BREAK STATIC

%token I8 I16 I32 I64 I128
%token U8 U16 U32 U64 U128
%token F32 F64 C32 C64 BOOL
%token STR

%token PLUS MINUS MULTIPLY DIVIDE MODULO EXPONENTIATE
%token EQUALS NOTEQUAL LESSTHAN GREATERTHAN LESSTHANEQUAL GREATERTHANEQUAL
%token AND OR XOR NOT
%token BITWISEAND BITWISEOR LEFTSHIFT RIGHTSHIFT
%token CONVOLUTION REVERSE
%token RANGE RANGEUPTO

%token ASSIGN COMMA SEMICOLON COLON DOT
%token LEFTBRACE RIGHTBRACE LEFTPAREN RIGHTPAREN LEFTSQUARE RIGHTSQUARE

%type <program> program
%type <function_decl> function_decl
%type <let_decl> let_decl
%type <const_decl> const_decl
%type <statement> statement assignment while_stmt for_stmt repeat_stmt return_stmt
%type <if_stmt> if_stmt
%type <stmt_list> statement_list
%type <stmt_block> statement_block
%type <expression> expression unary_expression
%type <expression> literal vector_literal range_expr
%type <expr_list> expression_list argument_list vector_elements
%type <type> type primitive_type vector_type
%type <type_list> type_list return_type_list
%type <parameter> parameter
%type <param_list> parameter_list
%type <identifier_list> identifier_list
%type <struct_decl> struct_decl
%type <function_call> function_call

%nonassoc RETURN
%left COMMA
%right ASSIGN
%nonassoc RANGE RANGEUPTO
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
%left AS
%right NOT
%right UNARY_PLUS UNARY_MINUS REVERSE
%left LEFTPAREN LEFTSQUARE DOT

%start program

%%

program:
    /* empty */ {
    }
    | program function_decl {
        ast_root->Blocks.emplace_back(std::unique_ptr<FunctionDecl>($2));
    }
    | program const_decl SEMICOLON {
        ast_root->Blocks.emplace_back(std::unique_ptr<ConstDecl>($2));
    }
    | program struct_decl {
        ast_root->Blocks.emplace_back(std::unique_ptr<StructDecl>($2));
    }
    ;

struct_decl:
    STRUCT IDENTIFIER LEFTBRACE RIGHTBRACE {
        $$ = new StructDecl($2, {});
    }
    | STRUCT IDENTIFIER LEFTBRACE parameter_list RIGHTBRACE {
        std::vector<ParameterPtr> members;
        for (auto* p : *$4)
        members.push_back(ParameterPtr(p));
        delete $4;

        $$ = new StructDecl($2, std::move(members));
    }
    ;

function_decl:
    FUNCTION IDENTIFIER LEFTPAREN parameter_list RIGHTPAREN return_type_list statement_block {
        std::vector<ParameterPtr> params;
        for (auto* p : *$4)
            params.push_back(ParameterPtr(p));
        delete $4;

        std::vector<TypePtr> rets;
        for (auto* t : *$6)
            rets.push_back(TypePtr(t));
        delete $6;
        $$ = new FunctionDecl($2, std::move(params), std::move(rets), std::unique_ptr<StatementBlock>($7));
    }
    |
    FUNCTION IDENTIFIER LEFTPAREN RIGHTPAREN return_type_list statement_block {
        std::vector<TypePtr> rets;
        for (auto* t : *$5) rets.emplace_back(TypePtr(t));
        delete $5;
 
        $$ = new FunctionDecl($2, {}, std::move(rets), std::unique_ptr<StatementBlock>($6));
    }
    ;

parameter_list:
    parameter {
        $$ = new std::vector<Parameter*>();
        $$->push_back($1);
    }
    | parameter_list COMMA parameter {
        $$ = $1;
        $$->push_back($3);
    }
    ;

parameter:
    IDENTIFIER COLON type {
        $$ = new Parameter($1, std::unique_ptr<Type>($3));
    }
    ;

return_type_list:
    /* empty */ {
        $$ = new std::vector<Type*>();
    }
    | type {
        $$ = new std::vector<Type*>();
        $$->push_back($1);
    }
    | LEFTPAREN type_list RIGHTPAREN {
        $$ = new std::vector<Type*>();
        for (auto* type : *$2) {
            $$->push_back(type);
        }
    }
    ;

type_list:
    type {
$$ = new std::vector<Type*>();
        $$->push_back($1);
    }
    | type_list COMMA type {
        $$ = $1;
        $$->push_back($3);
    }
    ;

type:
    primitive_type {
        $$=$1;
    }
    | vector_type {
        $$=$1;
    }
    | IDENTIFIER { 
        $$= new StructType(std::string($1));
        free($1);
    }
    ;

primitive_type:
    I8 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::I8);
    }
    | I16 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::I16);
    }
    | I32 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::I32);
    }
    | I64 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::I64);

    }
    | I128 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::I128);
    }
    | U8 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::U8);
    }
    | U16 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::U16);
    }
    | U32 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::U32);
    }
    | U64 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::U64);
    }
    | U128 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::U128);
    }
    | F32 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::F32);
    }
    | F64 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::F64);
    }
    | C32 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::C32);
    }
    | C64 {
        $$ = new PrimitiveType(PrimitiveTypeEnum::C64);
    }
    | BOOL {
        $$ = new PrimitiveType(PrimitiveTypeEnum::BOOL);
    }
    | STR {
        $$ = new PrimitiveType(PrimitiveTypeEnum::STR);
    }

vector_type:
    LEFTSQUARE type RIGHTSQUARE {
        $$ = new VectorType(TypePtr($2));
    }
    ;

statement_block:
    LEFTBRACE statement_list RIGHTBRACE {
        $$ = new StatementBlock();
        if ($2) {
            for (auto* s : *$2) {
                $$->statements.push_back(std::unique_ptr<Statement>(s));
            }
            delete $2;
        }
    }
    | LEFTBRACE RIGHTBRACE {
        $$ = new StatementBlock();
    }
    ;

statement_list:
    statement {
        $$ = new std::vector<Statement*>();
        $$->push_back($1);
    }
    | statement_list statement {
        $$ = $1;
        $$->push_back($2);
    }
    ;

statement :
    let_decl SEMICOLON {
        $$ = $1;
    }
    | const_decl SEMICOLON {
        $$ = $1;

    }
    | assignment SEMICOLON {
        $$ = $1;

    }
    | expression SEMICOLON {
         $$ = new ExprStmt(ExprPtr($1));
    }
    | if_stmt {
        $$ = $1;

    }
    | while_stmt {
        $$ = $1;
    }
    | for_stmt {
        $$ = $1;

    }
    | repeat_stmt {
        $$ = $1;

    }
    | return_stmt SEMICOLON {
        $$ = $1;

    }
    | BREAK SEMICOLON {
        $$ = new BreakStmt();
    }
    | CONTINUE SEMICOLON {
        $$ = new ContinueStmt();
    }
    ;



let_decl:
    LET IDENTIFIER ASSIGN expression {
        LetDecl* node = new LetDecl();
        node->names.push_back(std::string($2));
        free($2);
        node->types.clear();
        node->values.push_back(ExprPtr($4));
        $$ = node;
    }
    | LET IDENTIFIER COLON type ASSIGN expression {
        LetDecl* node = new LetDecl();
        node->names.push_back(std::string($2));
        free($2);
        node->types.push_back(TypePtr($4));
        node->values.push_back(ExprPtr($6));
        $$ = node;
    }
    | LET LEFTPAREN identifier_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN {
        LetDecl* node = new LetDecl();
        if ($3) {
            for (auto name : *$3) {
                node->names.push_back(name);
            }
            delete $3;
        }
        if ($7) {
            for (auto* e : *$7) {
                node->values.push_back(ExprPtr(e));
            }
            delete $7;
        }
        $$ = node;
    }
    | LET LEFTPAREN identifier_list RIGHTPAREN COLON LEFTPAREN type_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN {
        LetDecl* node = new LetDecl();
        if ($3) {
            for (auto name : *$3) {
                node->names.push_back(name);
            }
            delete $3;
        }
        if ($7) {
            for (auto* t : *$7) {
                node->types.push_back(TypePtr(t));
            }
            delete $7;
        }
        if ($11) {
            for (auto* e : *$11) {
                node->values.push_back(ExprPtr(e));
            }
            delete $11;
        }
        $$ = node;
    }
    ;

const_decl:
    CONST IDENTIFIER COLON type ASSIGN expression {
        ConstDecl* node = new ConstDecl();
        node->names.push_back(std::string($2));
        free($2);
        node->types.push_back(TypePtr($4));
        node->values.push_back(ExprPtr($6));
        $$ = node;

    }
    | CONST LEFTPAREN identifier_list RIGHTPAREN COLON LEFTPAREN type_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN {
        ConstDecl* node = new ConstDecl();
        if ($3) {
            for (auto name : *$3) {
                node->names.push_back(name);
            }
            delete $3;
        }
        if ($7) {
            for (auto* t : *$7) {
                node->types.push_back(TypePtr(t));
            }
            delete $7;
        }
        if ($11) {
            for (auto* e : *$11) {
                node->values.push_back(ExprPtr(e));
            }
            delete $11;
        }
        $$ = node;
    }
    ;

identifier_list:
    IDENTIFIER COMMA IDENTIFIER {
        $$ = new std::vector<std::string>();
        $$->push_back(std::string($1));
        free($1);
        $$->push_back(std::string($3));
        free($3);
    }
    | identifier_list COMMA IDENTIFIER {
        $$ = $1;
        $$->push_back($3);
    }
    ;

assignment:
    IDENTIFIER ASSIGN expression {
        Assignment* node = new Assignment();
        node->targets.push_back(std::string($1));
        free($1);
        node->values.push_back(ExprPtr($3));
        $$ = node;


    }
    | LEFTPAREN identifier_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN {
        Assignment* node = new Assignment();
        if ($2) {
            for (auto name : *$2) {
                node->targets.push_back(name);
            }
            delete $2;
        }
        if ($6) {
            for (auto* e : *$6) {
                node->values.push_back(ExprPtr(e));
            }
            delete $6;
        }
        $$ = node;
    }
    ;

if_stmt:
    IF expression statement_block {
        IfStmt* node = new IfStmt();
        node->condition = ExprPtr($2);
        node->then_block = std::unique_ptr<StatementBlock>($3);
        node->else_block = std::nullopt;
        node->else_if = std::nullopt;
        $$ = node;

    }
    | IF expression statement_block ELSE statement_block {
        IfStmt* node = new IfStmt();
        node->condition = ExprPtr($2);
        node->then_block = std::unique_ptr<StatementBlock>($3);
        node->else_block = std::optional<std::unique_ptr<StatementBlock>>(std::unique_ptr<StatementBlock>($5));
        node->else_if = std::nullopt;
        $$ = node;
    }
    | IF expression statement_block ELSE if_stmt {
        IfStmt* node = new IfStmt();
        node->condition = ExprPtr($2);
        node->then_block = std::unique_ptr<StatementBlock>($3);
        node->else_block = std::nullopt;
        node->else_if = std::make_optional<std::unique_ptr<IfStmt>>(std::unique_ptr<IfStmt>($5));
        $$ = node;
    }
    ;

while_stmt:
    WHILE expression statement_block {
        WhileStmt* node = new WhileStmt();
        node->condition = ExprPtr($2);
        node->body = std::unique_ptr<StatementBlock>($3);
        $$ = node;
    }
    ;

for_stmt:
    FOR IDENTIFIER IN expression statement_block {
        ForStmt* node = new ForStmt();
        node->iterator = std::string($2);
        free($2);
        node->iterable = ExprPtr($4);
        node->body = std::unique_ptr<StatementBlock>($5);
        $$ = node;
    }
    ;

repeat_stmt:
    REPEAT expression statement_block {
        RepeatStmt* node = new RepeatStmt();
        node->count = ExprPtr($2);
        node->body = std::unique_ptr<StatementBlock>($3);
        $$ = node;
    }
    ;

return_stmt:
    RETURN expression_list {
        ReturnStmt* node = new ReturnStmt();
        if ($2) {
            for (auto* e : *$2) {
                node->values.push_back(ExprPtr(e));
            }
            delete $2;
        }
        $$ = node;
    }
    | RETURN {
        ReturnStmt* node = new ReturnStmt();
        $$ = node;
    }
    ;

function_call:
    IDENTIFIER LEFTPAREN argument_list RIGHTPAREN {
        FunctionCallExpr* node = new FunctionCallExpr(std::string($1), {});
        free($1);
        if ($3) {
            for (auto e : *$3) node->arguments.push_back(ExprPtr(e));
            delete $3;
        }
        $$ = node;

    }
    ;

argument_list:
    expression_list {
        $$=$1;
    }
    | /* empty */ {
        $$ = nullptr;
    }
    ;

unary_expression:
    PLUS expression %prec UNARY_PLUS {
       UnaryExpression* node = new UnaryExpression(UnaryOp::PLUS, ExprPtr($2));
        $$ = node;
    }
    | MINUS expression %prec UNARY_MINUS {
       UnaryExpression* node = new UnaryExpression(UnaryOp::MINUS, ExprPtr($2));
        $$ = node;
    }
    | REVERSE expression {
        UnaryExpression* node = new UnaryExpression(UnaryOp::REVERSE, ExprPtr($2));
        $$ = node;
    }

expression:
    range_expr{
        $$ = $1;
    }
    | function_call{
        $$ = $1;
    }
    | IDENTIFIER{
        $$ = new IdentifierExpr(std::string($1));
        free($1);
    }
    | LEFTPAREN expression RIGHTPAREN {
        $$ = $2;
    }
    | unary_expression {
        $$ = $1;
    }
    | expression PLUS expression {
        $$ = new BinaryExpression(BinaryOp::PLUS, ExprPtr($1), ExprPtr($3));
    }
    | expression MINUS expression {
        $$ = new BinaryExpression(BinaryOp::MINUS, ExprPtr($1), ExprPtr($3));
    }
    | expression MULTIPLY expression {
        $$ = new BinaryExpression(BinaryOp::MULTIPLY, ExprPtr($1), ExprPtr($3));
    }
    | expression DIVIDE expression {
        $$ = new BinaryExpression(BinaryOp::DIVIDE, ExprPtr($1), ExprPtr($3));
    }
    | expression MODULO expression {
        $$ = new BinaryExpression(BinaryOp::MODULO, ExprPtr($1), ExprPtr($3));
    }
    | expression EXPONENTIATE expression {
        $$ = new BinaryExpression(BinaryOp::EXPONENTIATE, ExprPtr($1), ExprPtr($3));
    }
    | expression EQUALS expression {
        $$ = new BinaryExpression(BinaryOp::EQUALS, ExprPtr($1), ExprPtr($3));
    }
    | expression NOTEQUAL expression {
        $$ = new BinaryExpression(BinaryOp::NOTEQUAL, ExprPtr($1), ExprPtr($3));
    }
    | expression LESSTHAN expression {
        $$ = new BinaryExpression(BinaryOp::LESSTHAN, ExprPtr($1), ExprPtr($3));
    }
    | expression GREATERTHAN expression {
        $$ = new BinaryExpression(BinaryOp::GREATERTHAN, ExprPtr($1), ExprPtr($3));
    }
    | expression LESSTHANEQUAL expression {
        $$ = new BinaryExpression(BinaryOp::LESSTHANEQUAL, ExprPtr($1), ExprPtr($3));
    }
    | expression GREATERTHANEQUAL expression {
        $$ = new BinaryExpression(BinaryOp::GREATERTHANEQUAL, ExprPtr($1), ExprPtr($3));
    }
    | expression AND expression {
        $$ = new BinaryExpression(BinaryOp::AND, ExprPtr($1), ExprPtr($3));
    }
    | expression OR expression {
        $$ = new BinaryExpression(BinaryOp::OR, ExprPtr($1), ExprPtr($3));
    }
    | expression XOR expression {
        $$ = new BinaryExpression(BinaryOp::XOR, ExprPtr($1), ExprPtr($3));
    }
    | NOT expression {
        $$ = new UnaryExpression(UnaryOp::NOT, ExprPtr($2));
    }
    | expression BITWISEAND expression {
        $$ = new BinaryExpression(BinaryOp::BITWISEAND, ExprPtr($1), ExprPtr($3));
    }
    | expression BITWISEOR expression {
        $$ = new BinaryExpression(BinaryOp::BITWISEOR, ExprPtr($1), ExprPtr($3));
    }
    | expression LEFTSHIFT expression {
        $$ = new BinaryExpression(BinaryOp::LEFTSHIFT, ExprPtr($1), ExprPtr($3));
    }
    | expression RIGHTSHIFT expression {
        $$ = new BinaryExpression(BinaryOp::RIGHTSHIFT, ExprPtr($1), ExprPtr($3));
    }
    | expression CONVOLUTION expression {
        $$ = new BinaryExpression(BinaryOp::CONVOLUTION, ExprPtr($1), ExprPtr($3));
    }
    | expression LEFTSQUARE expression RIGHTSQUARE {
        $$ = new IndexExpression(ExprPtr($1), ExprPtr($3));
    }
    | expression AS type {
        $$ = new TypeCastExpr(ExprPtr($1),TypePtr($3));
    }
    | literal{
        $$ = $1;
    }
    ;

expression_list:
    expression {
        $$ = new std::vector<Expression*>();
        $$->push_back($1);


    }
    | expression_list COMMA expression {
        $$ = $1;
        $$->push_back($3);
    }
    ;

literal:
    INTEGER {
        $$ = new IntegerLiteral(std::string($1));
        free($1);
    }
    | FLOAT {
        $$ = new FloatLiteral(std::string($1));
        free($1);

    }
    | COMPLEX {
        $$ = new ComplexLiteral(std::string($1));
        free($1);

    }
    | TRUE {
        $$ = new BoolLiteral(true);

    }
    | FALSE {
        $$ = new BoolLiteral(false);
    }
    | PI {
        $$ = new PiLiteral();
    }
    | vector_literal {
        $$ = $1;
    }
    | STRING {
        $$ = new StringLiteral(std::string($1));
    }
    ;

vector_literal:
    LEFTSQUARE vector_elements RIGHTSQUARE {
        VectorLiteralExpr* node = new VectorLiteralExpr();
        if ($2) {
            for (auto e : *$2) {
                node->elements.push_back(ExprPtr(e));
            }
            delete $2;
        }
        $$ = node;
    }
    | LEFTSQUARE RIGHTSQUARE {
        VectorLiteralExpr* node = new VectorLiteralExpr();
        $$ = node;
    }

vector_elements:
    expression {
        $$ = new std::vector<Expression*>();
        $$->push_back($1);

    }
    | vector_elements COMMA expression {
        $$ = $1;
        $$->push_back($3);
    }
    ;

range_expr:
    expression RANGE expression {
        $$ = new RangeExpr(ExprPtr($1), ExprPtr($3), false);
    }
    | expression RANGEUPTO expression {
        $$ = new RangeExpr(ExprPtr($1), ExprPtr($3), true);
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

    ast_root->print(0);

    return 0;
}

void yyerror(const char*s) {
    fprintf(stderr, "Parse error at line %d: %s\n", yylineno, s);
    fprintf(stderr, "Near token: %s\n", yytext);
}
