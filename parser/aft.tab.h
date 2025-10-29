/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_AFT_TAB_H_INCLUDED
# define YY_YY_AFT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "aft.y"

    #include<vector>
    #include<memory>
    #include<string>
    #include "AST.h"


#line 57 "aft.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    FLOAT = 259,                   /* FLOAT  */
    COMPLEX = 260,                 /* COMPLEX  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    STRING = 262,                  /* STRING  */
    TRUE = 263,                    /* TRUE  */
    FALSE = 264,                   /* FALSE  */
    PI = 265,                      /* PI  */
    LET = 266,                     /* LET  */
    CONST = 267,                   /* CONST  */
    FUNCTION = 268,                /* FUNCTION  */
    RETURN = 269,                  /* RETURN  */
    IF = 270,                      /* IF  */
    ELSE = 271,                    /* ELSE  */
    WHILE = 272,                   /* WHILE  */
    FOR = 273,                     /* FOR  */
    IN = 274,                      /* IN  */
    REPEAT = 275,                  /* REPEAT  */
    STRUCT = 276,                  /* STRUCT  */
    ENUM = 277,                    /* ENUM  */
    AS = 278,                      /* AS  */
    CONTINUE = 279,                /* CONTINUE  */
    BREAK = 280,                   /* BREAK  */
    STATIC = 281,                  /* STATIC  */
    I8 = 282,                      /* I8  */
    I16 = 283,                     /* I16  */
    I32 = 284,                     /* I32  */
    I64 = 285,                     /* I64  */
    I128 = 286,                    /* I128  */
    U8 = 287,                      /* U8  */
    U16 = 288,                     /* U16  */
    U32 = 289,                     /* U32  */
    U64 = 290,                     /* U64  */
    U128 = 291,                    /* U128  */
    F32 = 292,                     /* F32  */
    F64 = 293,                     /* F64  */
    C32 = 294,                     /* C32  */
    C64 = 295,                     /* C64  */
    BOOL = 296,                    /* BOOL  */
    STR = 297,                     /* STR  */
    PLUS = 298,                    /* PLUS  */
    MINUS = 299,                   /* MINUS  */
    MULTIPLY = 300,                /* MULTIPLY  */
    DIVIDE = 301,                  /* DIVIDE  */
    MODULO = 302,                  /* MODULO  */
    EXPONENTIATE = 303,            /* EXPONENTIATE  */
    EQUALS = 304,                  /* EQUALS  */
    NOTEQUAL = 305,                /* NOTEQUAL  */
    LESSTHAN = 306,                /* LESSTHAN  */
    GREATERTHAN = 307,             /* GREATERTHAN  */
    LESSTHANEQUAL = 308,           /* LESSTHANEQUAL  */
    GREATERTHANEQUAL = 309,        /* GREATERTHANEQUAL  */
    AND = 310,                     /* AND  */
    OR = 311,                      /* OR  */
    XOR = 312,                     /* XOR  */
    NOT = 313,                     /* NOT  */
    BITWISEAND = 314,              /* BITWISEAND  */
    BITWISEOR = 315,               /* BITWISEOR  */
    LEFTSHIFT = 316,               /* LEFTSHIFT  */
    RIGHTSHIFT = 317,              /* RIGHTSHIFT  */
    CONVOLUTION = 318,             /* CONVOLUTION  */
    REVERSE = 319,                 /* REVERSE  */
    RANGE = 320,                   /* RANGE  */
    RANGEUPTO = 321,               /* RANGEUPTO  */
    ASSIGN = 322,                  /* ASSIGN  */
    COMMA = 323,                   /* COMMA  */
    SEMICOLON = 324,               /* SEMICOLON  */
    COLON = 325,                   /* COLON  */
    DOT = 326,                     /* DOT  */
    LEFTBRACE = 327,               /* LEFTBRACE  */
    RIGHTBRACE = 328,              /* RIGHTBRACE  */
    LEFTPAREN = 329,               /* LEFTPAREN  */
    RIGHTPAREN = 330,              /* RIGHTPAREN  */
    LEFTSQUARE = 331,              /* LEFTSQUARE  */
    RIGHTSQUARE = 332,             /* RIGHTSQUARE  */
    UNARY_PLUS = 333,              /* UNARY_PLUS  */
    UNARY_MINUS = 334              /* UNARY_MINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "aft.y"

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

#line 175 "aft.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_AFT_TAB_H_INCLUDED  */
