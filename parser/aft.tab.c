/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "parser/aft.y"

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

#line 87 "parser/aft.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "aft.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_COMPLEX = 5,                    /* COMPLEX  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_TRUE = 8,                       /* TRUE  */
  YYSYMBOL_FALSE = 9,                      /* FALSE  */
  YYSYMBOL_PI = 10,                        /* PI  */
  YYSYMBOL_LET = 11,                       /* LET  */
  YYSYMBOL_CONST = 12,                     /* CONST  */
  YYSYMBOL_FUNCTION = 13,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_IN = 19,                        /* IN  */
  YYSYMBOL_REPEAT = 20,                    /* REPEAT  */
  YYSYMBOL_STRUCT = 21,                    /* STRUCT  */
  YYSYMBOL_ENUM = 22,                      /* ENUM  */
  YYSYMBOL_AS = 23,                        /* AS  */
  YYSYMBOL_CONTINUE = 24,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 25,                     /* BREAK  */
  YYSYMBOL_STATIC = 26,                    /* STATIC  */
  YYSYMBOL_I8 = 27,                        /* I8  */
  YYSYMBOL_I16 = 28,                       /* I16  */
  YYSYMBOL_I32 = 29,                       /* I32  */
  YYSYMBOL_I64 = 30,                       /* I64  */
  YYSYMBOL_I128 = 31,                      /* I128  */
  YYSYMBOL_U8 = 32,                        /* U8  */
  YYSYMBOL_U16 = 33,                       /* U16  */
  YYSYMBOL_U32 = 34,                       /* U32  */
  YYSYMBOL_U64 = 35,                       /* U64  */
  YYSYMBOL_U128 = 36,                      /* U128  */
  YYSYMBOL_F32 = 37,                       /* F32  */
  YYSYMBOL_F64 = 38,                       /* F64  */
  YYSYMBOL_C32 = 39,                       /* C32  */
  YYSYMBOL_C64 = 40,                       /* C64  */
  YYSYMBOL_BOOL = 41,                      /* BOOL  */
  YYSYMBOL_STR = 42,                       /* STR  */
  YYSYMBOL_PLUS = 43,                      /* PLUS  */
  YYSYMBOL_MINUS = 44,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 45,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 46,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 47,                    /* MODULO  */
  YYSYMBOL_EXPONENTIATE = 48,              /* EXPONENTIATE  */
  YYSYMBOL_EQUALS = 49,                    /* EQUALS  */
  YYSYMBOL_NOTEQUAL = 50,                  /* NOTEQUAL  */
  YYSYMBOL_LESSTHAN = 51,                  /* LESSTHAN  */
  YYSYMBOL_GREATERTHAN = 52,               /* GREATERTHAN  */
  YYSYMBOL_LESSTHANEQUAL = 53,             /* LESSTHANEQUAL  */
  YYSYMBOL_GREATERTHANEQUAL = 54,          /* GREATERTHANEQUAL  */
  YYSYMBOL_AND = 55,                       /* AND  */
  YYSYMBOL_OR = 56,                        /* OR  */
  YYSYMBOL_XOR = 57,                       /* XOR  */
  YYSYMBOL_NOT = 58,                       /* NOT  */
  YYSYMBOL_BITWISEAND = 59,                /* BITWISEAND  */
  YYSYMBOL_BITWISEOR = 60,                 /* BITWISEOR  */
  YYSYMBOL_LEFTSHIFT = 61,                 /* LEFTSHIFT  */
  YYSYMBOL_RIGHTSHIFT = 62,                /* RIGHTSHIFT  */
  YYSYMBOL_CONVOLUTION = 63,               /* CONVOLUTION  */
  YYSYMBOL_REVERSE = 64,                   /* REVERSE  */
  YYSYMBOL_RANGE = 65,                     /* RANGE  */
  YYSYMBOL_RANGEUPTO = 66,                 /* RANGEUPTO  */
  YYSYMBOL_ASSIGN = 67,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 68,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 69,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 70,                     /* COLON  */
  YYSYMBOL_DOT = 71,                       /* DOT  */
  YYSYMBOL_LEFTBRACE = 72,                 /* LEFTBRACE  */
  YYSYMBOL_RIGHTBRACE = 73,                /* RIGHTBRACE  */
  YYSYMBOL_LEFTPAREN = 74,                 /* LEFTPAREN  */
  YYSYMBOL_RIGHTPAREN = 75,                /* RIGHTPAREN  */
  YYSYMBOL_LEFTSQUARE = 76,                /* LEFTSQUARE  */
  YYSYMBOL_RIGHTSQUARE = 77,               /* RIGHTSQUARE  */
  YYSYMBOL_UNARY_PLUS = 78,                /* UNARY_PLUS  */
  YYSYMBOL_UNARY_MINUS = 79,               /* UNARY_MINUS  */
  YYSYMBOL_YYACCEPT = 80,                  /* $accept  */
  YYSYMBOL_program = 81,                   /* program  */
  YYSYMBOL_struct_decl = 82,               /* struct_decl  */
  YYSYMBOL_function_decl = 83,             /* function_decl  */
  YYSYMBOL_parameter_list = 84,            /* parameter_list  */
  YYSYMBOL_parameter = 85,                 /* parameter  */
  YYSYMBOL_return_type_list = 86,          /* return_type_list  */
  YYSYMBOL_type_list = 87,                 /* type_list  */
  YYSYMBOL_type = 88,                      /* type  */
  YYSYMBOL_primitive_type = 89,            /* primitive_type  */
  YYSYMBOL_vector_type = 90,               /* vector_type  */
  YYSYMBOL_statement_block = 91,           /* statement_block  */
  YYSYMBOL_statement_list = 92,            /* statement_list  */
  YYSYMBOL_statement = 93,                 /* statement  */
  YYSYMBOL_let_decl = 94,                  /* let_decl  */
  YYSYMBOL_const_decl = 95,                /* const_decl  */
  YYSYMBOL_identifier_list = 96,           /* identifier_list  */
  YYSYMBOL_assignment = 97,                /* assignment  */
  YYSYMBOL_if_stmt = 98,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 99,                /* while_stmt  */
  YYSYMBOL_for_stmt = 100,                 /* for_stmt  */
  YYSYMBOL_repeat_stmt = 101,              /* repeat_stmt  */
  YYSYMBOL_return_stmt = 102,              /* return_stmt  */
  YYSYMBOL_function_call = 103,            /* function_call  */
  YYSYMBOL_argument_list = 104,            /* argument_list  */
  YYSYMBOL_unary_expression = 105,         /* unary_expression  */
  YYSYMBOL_expression = 106,               /* expression  */
  YYSYMBOL_expression_list = 107,          /* expression_list  */
  YYSYMBOL_literal = 108,                  /* literal  */
  YYSYMBOL_vector_literal = 109,           /* vector_literal  */
  YYSYMBOL_vector_elements = 110,          /* vector_elements  */
  YYSYMBOL_range_expr = 111                /* range_expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   812

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  249

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   334


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   111,   111,   113,   116,   119,   125,   128,   139,   152,
     162,   166,   173,   179,   182,   186,   195,   199,   206,   209,
     212,   219,   222,   225,   228,   232,   235,   238,   241,   244,
     247,   250,   253,   256,   259,   262,   265,   270,   278,   287,
     293,   297,   304,   307,   311,   315,   318,   322,   325,   329,
     333,   337,   340,   348,   356,   364,   380,   405,   414,   439,
     446,   453,   462,   478,   494,   503,   511,   522,   531,   542,
     551,   561,   568,   581,   584,   590,   594,   598,   604,   607,
     610,   614,   617,   620,   623,   626,   629,   632,   635,   638,
     641,   644,   647,   650,   653,   656,   659,   662,   665,   668,
     671,   674,   677,   680,   683,   686,   689,   695,   701,   708,
     712,   717,   722,   726,   729,   732,   735,   741,   752,   759,
     764,   771,   774
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "FLOAT",
  "COMPLEX", "IDENTIFIER", "STRING", "TRUE", "FALSE", "PI", "LET", "CONST",
  "FUNCTION", "RETURN", "IF", "ELSE", "WHILE", "FOR", "IN", "REPEAT",
  "STRUCT", "ENUM", "AS", "CONTINUE", "BREAK", "STATIC", "I8", "I16",
  "I32", "I64", "I128", "U8", "U16", "U32", "U64", "U128", "F32", "F64",
  "C32", "C64", "BOOL", "STR", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "MODULO", "EXPONENTIATE", "EQUALS", "NOTEQUAL", "LESSTHAN",
  "GREATERTHAN", "LESSTHANEQUAL", "GREATERTHANEQUAL", "AND", "OR", "XOR",
  "NOT", "BITWISEAND", "BITWISEOR", "LEFTSHIFT", "RIGHTSHIFT",
  "CONVOLUTION", "REVERSE", "RANGE", "RANGEUPTO", "ASSIGN", "COMMA",
  "SEMICOLON", "COLON", "DOT", "LEFTBRACE", "RIGHTBRACE", "LEFTPAREN",
  "RIGHTPAREN", "LEFTSQUARE", "RIGHTSQUARE", "UNARY_PLUS", "UNARY_MINUS",
  "$accept", "program", "struct_decl", "function_decl", "parameter_list",
  "parameter", "return_type_list", "type_list", "type", "primitive_type",
  "vector_type", "statement_block", "statement_list", "statement",
  "let_decl", "const_decl", "identifier_list", "assignment", "if_stmt",
  "while_stmt", "for_stmt", "repeat_stmt", "return_stmt", "function_call",
  "argument_list", "unary_expression", "expression", "expression_list",
  "literal", "vector_literal", "vector_elements", "range_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -132,    29,  -132,    13,     4,     7,  -132,  -132,   -48,   -32,
      51,    19,    23,  -132,   346,    37,   -61,    11,    17,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,   346,    42,  -132,  -132,
     111,   134,    71,    80,   330,   -59,  -132,  -132,    66,    72,
     218,  -132,  -132,    77,   346,   346,    81,  -132,   146,   330,
    -132,  -132,  -132,  -132,  -132,    83,  -132,  -132,  -132,  -132,
     218,   218,   218,   218,   218,   115,  -132,  -132,   555,  -132,
    -132,  -132,   346,  -132,   -57,  -132,   193,  -132,  -132,    81,
     218,    78,    78,    78,    78,   450,  -132,   555,   -62,   346,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   -44,   346,  -132,   -28,    14,   218,   218,
     218,   154,   218,    94,    96,  -132,   280,   235,  -132,    97,
      98,    99,  -132,  -132,  -132,  -132,   101,   485,  -132,   100,
     555,   103,  -132,   218,  -132,  -132,   -20,   -20,    79,    79,
      79,    79,    85,    85,    85,    85,    85,    85,   660,   625,
     695,   701,   257,   736,   736,    79,   590,   590,   380,   105,
    -132,   218,    -9,    51,   103,   520,   520,   157,   520,  -132,
    -132,   -19,   -24,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
     218,  -132,   218,   555,  -132,   104,   555,   218,   346,   -21,
     161,  -132,   218,  -132,   113,   415,   555,   218,   555,   114,
      68,   -13,   520,   108,   116,   -15,   218,   110,   112,  -132,
    -132,  -132,   218,   218,  -132,   555,   218,   346,    21,   555,
      36,    38,  -132,  -132,   118,   119,   218,    39,  -132
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     5,     3,     0,     0,
       0,     0,     0,     4,     0,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,    18,    19,
       0,     0,     0,     0,    13,     0,    10,     6,     0,     0,
       0,    59,    60,     0,     0,     0,     0,    14,     0,    13,
       7,    37,   109,   110,   111,    80,   116,   112,   113,   114,
       0,     0,     0,     0,     0,     0,    79,    82,    57,   106,
     115,    78,     0,    12,     0,    16,     0,     9,    11,     0,
      74,    75,    76,    98,    77,     0,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    80,     0,    71,     0,
       0,     0,     0,     0,     0,    39,     0,     0,    40,     0,
       0,     0,    46,    47,    48,    49,     0,     0,     8,     0,
     107,    73,    81,     0,   117,   105,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    99,   100,   101,   102,   103,   121,   122,     0,     0,
      17,     0,     0,     0,    70,     0,     0,     0,     0,    52,
      51,    80,     0,    38,    41,    42,    43,    44,    50,    45,
       0,    72,     0,   120,   104,     0,    61,     0,     0,     0,
      64,    67,     0,    69,     0,     0,   108,     0,    53,     0,
       0,     0,     0,     0,   104,     0,     0,     0,     0,    65,
      66,    68,     0,     0,    58,    54,     0,     0,     0,    63,
       0,     0,    62,    55,     0,     0,     0,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,  -132,   169,   132,   147,   -81,   -14,  -132,
    -132,   -85,  -132,    75,  -132,   208,  -131,  -132,    -7,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,   -38,  -120,  -132,  -132,
    -132,  -132
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     6,     7,    45,    46,    56,    84,    85,    38,
      39,    87,   137,   138,   139,   140,    16,   141,   142,   143,
     144,   145,   146,    76,   149,    77,   150,   151,    79,    80,
      98,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,   123,   129,    99,   148,   192,   153,    41,   184,    58,
      11,   124,    78,    12,    42,   154,    59,    43,   125,     9,
     182,    13,    49,    43,   124,   102,   103,   104,   105,     2,
      57,   179,    91,    92,    93,    94,    95,    97,    14,   181,
      83,     3,     4,   119,    41,    57,    90,    41,   147,    40,
       5,   214,   209,   202,   220,    90,   122,    15,   207,    86,
     234,   208,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   155,    44,    10,   183,   202,
      47,   185,   186,    17,   188,    18,   242,   225,    95,   147,
     210,   211,    99,   213,   202,    40,   124,   202,    99,    50,
     180,   243,   238,   244,   248,   203,   240,    51,    62,    63,
      64,    65,    66,    67,    68,    69,   247,   105,   100,   101,
     102,   103,   104,   105,    58,   227,   229,   231,   228,    60,
      52,    53,   114,   206,   115,   116,   117,   118,   119,    61,
      54,    82,    43,    86,   122,   122,   241,    90,    70,    71,
     187,   122,   215,   189,   216,   190,   195,   196,   197,   218,
     198,   202,   205,    72,   222,   201,   212,   221,   217,    73,
     223,   226,   232,   233,   236,   245,   237,    48,   235,    74,
      88,    75,    96,   246,   219,   239,    62,    63,    64,   126,
      66,    67,    68,    69,   127,     3,    89,   128,   129,     8,
     130,   131,   194,   132,   230,     0,     0,   133,   134,     0,
       0,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    62,    63,
      64,   126,    66,    67,    68,    69,   127,     3,     0,   128,
     129,    72,   130,   131,     0,   132,     0,    73,     0,   133,
     134,    70,    71,     0,     0,     0,   135,   136,     0,    75,
       0,     0,     0,     0,     0,     0,    72,     0,    70,    71,
      99,     0,    73,    62,    63,    64,   191,    66,    67,    68,
      69,     0,    74,    72,    75,     0,     0,     0,     0,    73,
     100,   101,   102,   103,   104,   105,     0,     0,   193,   136,
       0,    75,     0,     0,   114,     0,   115,     0,   117,   118,
     119,     0,     0,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,   122,     0,     0,    19,     0,    72,     0,
       0,     0,     0,     0,    73,     0,     0,     0,     0,     0,
       0,     0,    19,     0,    74,     0,    75,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,    55,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    99,   115,
     116,   117,   118,   119,     0,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,   204,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    99,   115,   116,   117,   118,   119,     0,
     120,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   224,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    99,   115,
     116,   117,   118,   119,     0,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,   152,   122,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    99,   115,   116,   117,   118,   119,     0,
     120,   121,     0,     0,   199,     0,     0,     0,     0,     0,
       0,   200,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    99,   115,
     116,   117,   118,   119,     0,   120,   121,     0,     0,     0,
       0,     0,    86,     0,     0,     0,   122,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    99,   115,   116,   117,   118,   119,     0,
     120,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    99,   115,
     116,   117,   118,   119,     0,    -1,    -1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   114,    99,   115,   116,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,     0,   114,    99,   115,
     116,   117,   118,   119,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,   100,   101,
     102,   103,   104,   105,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,   115,     0,   117,   118,   119,    99,
       0,     0,   117,   118,   119,     0,     0,     0,     0,     0,
       0,   122,     0,     0,     0,     0,     0,   122,     0,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122
};

static const yytype_int16 yycheck[] =
{
      14,    82,    15,    23,    89,   136,    68,    68,   128,    68,
       6,    68,    50,     6,    75,    77,    75,     6,    75,     6,
       6,    69,    36,     6,    68,    45,    46,    47,    48,     0,
      44,    75,    70,    71,    72,    73,    74,    75,    70,    67,
      54,    12,    13,    63,    68,    59,    74,    68,    86,    68,
      21,    75,   183,    68,    75,    74,    76,     6,    67,    72,
      75,    70,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    99,    75,    74,    74,    68,
      73,   129,   130,    74,   132,    72,    75,   217,   136,   137,
     185,   186,    23,   188,    68,    68,    68,    68,    23,    67,
     124,    75,   232,    75,    75,   153,   236,     6,     3,     4,
       5,     6,     7,     8,     9,    10,   246,    48,    43,    44,
      45,    46,    47,    48,    68,    67,   221,   222,    70,    73,
       6,    70,    57,   181,    59,    60,    61,    62,    63,    77,
      70,    74,     6,    72,    76,    76,   237,    74,    43,    44,
       6,    76,   200,    69,   202,    69,    69,    69,    69,   207,
      69,    68,    67,    58,   212,    75,    19,    16,    74,    64,
      67,    67,    74,    67,    74,    67,    74,    18,   226,    74,
      58,    76,    77,    74,   208,   233,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    59,    14,    15,     1,
      17,    18,   137,    20,   221,    -1,    -1,    24,    25,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    58,    17,    18,    -1,    20,    -1,    64,    -1,    24,
      25,    43,    44,    -1,    -1,    -1,    73,    74,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    43,    44,
      23,    -1,    64,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    74,    58,    76,    -1,    -1,    -1,    -1,    64,
      43,    44,    45,    46,    47,    48,    -1,    -1,    73,    74,
      -1,    76,    -1,    -1,    57,    -1,    59,    -1,    61,    62,
      63,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,     6,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    74,    -1,    76,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    74,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    23,    59,
      60,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    23,    59,    60,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    23,    59,
      60,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    23,    59,    60,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    23,    59,
      60,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    23,    59,    60,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    23,    59,
      60,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    23,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    57,    23,    59,
      60,    61,    62,    63,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    43,    44,
      45,    46,    47,    48,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    59,    -1,    61,    62,    63,    23,
      -1,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    76,    -1,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    81,     0,    12,    13,    21,    82,    83,    95,     6,
      74,     6,     6,    69,    70,     6,    96,    74,    72,     6,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    76,    88,    89,    90,
      68,    68,    75,     6,    75,    84,    85,    73,    84,    88,
      67,     6,     6,    70,    70,    74,    86,    88,    68,    75,
      73,    77,     3,     4,     5,     6,     7,     8,     9,    10,
      43,    44,    58,    64,    74,    76,   103,   105,   106,   108,
     109,   111,    74,    88,    87,    88,    72,    91,    85,    86,
      74,   106,   106,   106,   106,   106,    77,   106,   110,    23,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    59,    60,    61,    62,    63,
      65,    66,    76,    87,    68,    75,     6,    11,    14,    15,
      17,    18,    20,    24,    25,    73,    74,    92,    93,    94,
      95,    97,    98,    99,   100,   101,   102,   106,    91,   104,
     106,   107,    75,    68,    77,    88,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,    75,
      88,    67,     6,    74,   107,   106,   106,     6,   106,    69,
      69,     6,    96,    73,    93,    69,    69,    69,    69,    69,
      76,    75,    68,   106,    77,    67,   106,    67,    70,    96,
      91,    91,    19,    91,    75,   106,   106,    74,   106,    88,
      75,    16,   106,    67,    77,   107,    67,    67,    70,    91,
      98,    91,    74,    67,    75,   106,    74,    74,   107,   106,
     107,    87,    75,    75,    75,    67,    74,   107,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    80,    81,    81,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    86,    86,    86,    87,    87,    88,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    91,    91,
      92,    92,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    98,    98,    98,    99,   100,   101,
     102,   102,   103,   104,   104,   105,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   110,
     110,   111,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     2,     4,     5,     7,     6,
       1,     3,     3,     0,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       1,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       2,     2,     2,     4,     6,     8,    12,     6,    12,     3,
       3,     3,     7,     6,     3,     5,     5,     3,     5,     3,
       2,     1,     4,     1,     0,     2,     2,     2,     1,     1,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     4,     3,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: %empty  */
#line 111 "parser/aft.y"
                {
    }
#line 1473 "parser/aft.tab.c"
    break;

  case 3: /* program: program function_decl  */
#line 113 "parser/aft.y"
                            {
        ast_root->Blocks.emplace_back(std::unique_ptr<FunctionDecl>((yyvsp[0].function_decl)));
    }
#line 1481 "parser/aft.tab.c"
    break;

  case 4: /* program: program const_decl SEMICOLON  */
#line 116 "parser/aft.y"
                                   {
        ast_root->Blocks.emplace_back(std::unique_ptr<ConstDecl>((yyvsp[-1].const_decl)));
    }
#line 1489 "parser/aft.tab.c"
    break;

  case 5: /* program: program struct_decl  */
#line 119 "parser/aft.y"
                          {
        ast_root->Blocks.emplace_back(std::unique_ptr<StructDecl>((yyvsp[0].struct_decl)));
    }
#line 1497 "parser/aft.tab.c"
    break;

  case 6: /* struct_decl: STRUCT IDENTIFIER LEFTBRACE RIGHTBRACE  */
#line 125 "parser/aft.y"
                                           {
        (yyval.struct_decl) = new StructDecl((yyvsp[-2].sval), {});
    }
#line 1505 "parser/aft.tab.c"
    break;

  case 7: /* struct_decl: STRUCT IDENTIFIER LEFTBRACE parameter_list RIGHTBRACE  */
#line 128 "parser/aft.y"
                                                            {
        std::vector<ParameterPtr> members;
        for (auto* p : *(yyvsp[-1].param_list))
        members.push_back(ParameterPtr(p));
        delete (yyvsp[-1].param_list);

        (yyval.struct_decl) = new StructDecl((yyvsp[-3].sval), std::move(members));
    }
#line 1518 "parser/aft.tab.c"
    break;

  case 8: /* function_decl: FUNCTION IDENTIFIER LEFTPAREN parameter_list RIGHTPAREN return_type_list statement_block  */
#line 139 "parser/aft.y"
                                                                                             {
        std::vector<ParameterPtr> params;
        for (auto* p : *(yyvsp[-3].param_list))
            params.push_back(ParameterPtr(p));
        delete (yyvsp[-3].param_list);

        std::vector<TypePtr> rets;
        for (auto* t : *(yyvsp[-1].type_list))
            rets.push_back(TypePtr(t));
        delete (yyvsp[-1].type_list);
        (yyval.function_decl) = new FunctionDecl((yyvsp[-5].sval), std::move(params), std::move(rets), std::unique_ptr<StatementBlock>((yyvsp[0].stmt_block)));
    }
#line 1535 "parser/aft.tab.c"
    break;

  case 9: /* function_decl: FUNCTION IDENTIFIER LEFTPAREN RIGHTPAREN return_type_list statement_block  */
#line 152 "parser/aft.y"
                                                                              {
        std::vector<TypePtr> rets;
        for (auto* t : *(yyvsp[-1].type_list)) rets.emplace_back(TypePtr(t));
        delete (yyvsp[-1].type_list);
 
        (yyval.function_decl) = new FunctionDecl((yyvsp[-4].sval), {}, std::move(rets), std::unique_ptr<StatementBlock>((yyvsp[0].stmt_block)));
    }
#line 1547 "parser/aft.tab.c"
    break;

  case 10: /* parameter_list: parameter  */
#line 162 "parser/aft.y"
              {
        (yyval.param_list) = new std::vector<Parameter*>();
        (yyval.param_list)->push_back((yyvsp[0].parameter));
    }
#line 1556 "parser/aft.tab.c"
    break;

  case 11: /* parameter_list: parameter_list COMMA parameter  */
#line 166 "parser/aft.y"
                                     {
        (yyval.param_list) = (yyvsp[-2].param_list);
        (yyval.param_list)->push_back((yyvsp[0].parameter));
    }
#line 1565 "parser/aft.tab.c"
    break;

  case 12: /* parameter: IDENTIFIER COLON type  */
#line 173 "parser/aft.y"
                          {
        (yyval.parameter) = new Parameter((yyvsp[-2].sval), std::unique_ptr<Types>((yyvsp[0].type)));
    }
#line 1573 "parser/aft.tab.c"
    break;

  case 13: /* return_type_list: %empty  */
#line 179 "parser/aft.y"
                {
        (yyval.type_list) = new std::vector<Types*>();
    }
#line 1581 "parser/aft.tab.c"
    break;

  case 14: /* return_type_list: type  */
#line 182 "parser/aft.y"
           {
        (yyval.type_list) = new std::vector<Types*>();
        (yyval.type_list)->push_back((yyvsp[0].type));
    }
#line 1590 "parser/aft.tab.c"
    break;

  case 15: /* return_type_list: LEFTPAREN type_list RIGHTPAREN  */
#line 186 "parser/aft.y"
                                     {
        (yyval.type_list) = new std::vector<Types*>();
        for (auto* type : *(yyvsp[-1].type_list)) {
            (yyval.type_list)->push_back(type);
        }
    }
#line 1601 "parser/aft.tab.c"
    break;

  case 16: /* type_list: type  */
#line 195 "parser/aft.y"
         {
(yyval.type_list) = new std::vector<Types*>();
        (yyval.type_list)->push_back((yyvsp[0].type));
    }
#line 1610 "parser/aft.tab.c"
    break;

  case 17: /* type_list: type_list COMMA type  */
#line 199 "parser/aft.y"
                           {
        (yyval.type_list) = (yyvsp[-2].type_list);
        (yyval.type_list)->push_back((yyvsp[0].type));
    }
#line 1619 "parser/aft.tab.c"
    break;

  case 18: /* type: primitive_type  */
#line 206 "parser/aft.y"
                   {
        (yyval.type)=(yyvsp[0].type);
    }
#line 1627 "parser/aft.tab.c"
    break;

  case 19: /* type: vector_type  */
#line 209 "parser/aft.y"
                  {
        (yyval.type)=(yyvsp[0].type);
    }
#line 1635 "parser/aft.tab.c"
    break;

  case 20: /* type: IDENTIFIER  */
#line 212 "parser/aft.y"
                 { 
        (yyval.type)= new StructType(std::string((yyvsp[0].sval)));
        free((yyvsp[0].sval));
    }
#line 1644 "parser/aft.tab.c"
    break;

  case 21: /* primitive_type: I8  */
#line 219 "parser/aft.y"
       {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::I8);
    }
#line 1652 "parser/aft.tab.c"
    break;

  case 22: /* primitive_type: I16  */
#line 222 "parser/aft.y"
          {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::I16);
    }
#line 1660 "parser/aft.tab.c"
    break;

  case 23: /* primitive_type: I32  */
#line 225 "parser/aft.y"
          {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::I32);
    }
#line 1668 "parser/aft.tab.c"
    break;

  case 24: /* primitive_type: I64  */
#line 228 "parser/aft.y"
          {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::I64);

    }
#line 1677 "parser/aft.tab.c"
    break;

  case 25: /* primitive_type: I128  */
#line 232 "parser/aft.y"
           {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::I128);
    }
#line 1685 "parser/aft.tab.c"
    break;

  case 26: /* primitive_type: U8  */
#line 235 "parser/aft.y"
         {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::U8);
    }
#line 1693 "parser/aft.tab.c"
    break;

  case 27: /* primitive_type: U16  */
#line 238 "parser/aft.y"
          {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::U16);
    }
#line 1701 "parser/aft.tab.c"
    break;

  case 28: /* primitive_type: U32  */
#line 241 "parser/aft.y"
          {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::U32);
    }
#line 1709 "parser/aft.tab.c"
    break;

  case 29: /* primitive_type: U64  */
#line 244 "parser/aft.y"
          {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::U64);
    }
#line 1717 "parser/aft.tab.c"
    break;

  case 30: /* primitive_type: U128  */
#line 247 "parser/aft.y"
           {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::U128);
    }
#line 1725 "parser/aft.tab.c"
    break;

  case 31: /* primitive_type: F32  */
#line 250 "parser/aft.y"
          {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::F32);
    }
#line 1733 "parser/aft.tab.c"
    break;

  case 32: /* primitive_type: F64  */
#line 253 "parser/aft.y"
          {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::F64);
    }
#line 1741 "parser/aft.tab.c"
    break;

  case 33: /* primitive_type: C32  */
#line 256 "parser/aft.y"
          {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::C32);
    }
#line 1749 "parser/aft.tab.c"
    break;

  case 34: /* primitive_type: C64  */
#line 259 "parser/aft.y"
          {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::C64);
    }
#line 1757 "parser/aft.tab.c"
    break;

  case 35: /* primitive_type: BOOL  */
#line 262 "parser/aft.y"
           {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::BOOL);
    }
#line 1765 "parser/aft.tab.c"
    break;

  case 36: /* primitive_type: STR  */
#line 265 "parser/aft.y"
          {
        (yyval.type) = new PrimitiveType(PrimitiveTypeEnum::STR);
    }
#line 1773 "parser/aft.tab.c"
    break;

  case 37: /* vector_type: LEFTSQUARE type RIGHTSQUARE  */
#line 270 "parser/aft.y"
                                {
        auto vt = new VectorType(TypePtr((yyvsp[-1].type)));
        vt->fixed_length = 0;
        (yyval.type) = vt;
    }
#line 1783 "parser/aft.tab.c"
    break;

  case 38: /* statement_block: LEFTBRACE statement_list RIGHTBRACE  */
#line 278 "parser/aft.y"
                                        {
        (yyval.stmt_block) = new StatementBlock();
        if ((yyvsp[-1].stmt_list)) {
            for (auto* s : *(yyvsp[-1].stmt_list)) {
                (yyval.stmt_block)->statements.push_back(std::unique_ptr<Statement>(s));
            }
            delete (yyvsp[-1].stmt_list);
        }
    }
#line 1797 "parser/aft.tab.c"
    break;

  case 39: /* statement_block: LEFTBRACE RIGHTBRACE  */
#line 287 "parser/aft.y"
                           {
        (yyval.stmt_block) = new StatementBlock();
    }
#line 1805 "parser/aft.tab.c"
    break;

  case 40: /* statement_list: statement  */
#line 293 "parser/aft.y"
              {
        (yyval.stmt_list) = new std::vector<Statement*>();
        (yyval.stmt_list)->push_back((yyvsp[0].statement));
    }
#line 1814 "parser/aft.tab.c"
    break;

  case 41: /* statement_list: statement_list statement  */
#line 297 "parser/aft.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        (yyval.stmt_list)->push_back((yyvsp[0].statement));
    }
#line 1823 "parser/aft.tab.c"
    break;

  case 42: /* statement: let_decl SEMICOLON  */
#line 304 "parser/aft.y"
                       {
        (yyval.statement) = (yyvsp[-1].let_decl);
    }
#line 1831 "parser/aft.tab.c"
    break;

  case 43: /* statement: const_decl SEMICOLON  */
#line 307 "parser/aft.y"
                           {
        (yyval.statement) = (yyvsp[-1].const_decl);

    }
#line 1840 "parser/aft.tab.c"
    break;

  case 44: /* statement: assignment SEMICOLON  */
#line 311 "parser/aft.y"
                           {
        (yyval.statement) = (yyvsp[-1].statement);

    }
#line 1849 "parser/aft.tab.c"
    break;

  case 45: /* statement: expression SEMICOLON  */
#line 315 "parser/aft.y"
                           {
         (yyval.statement) = new ExprStmt(ExprPtr((yyvsp[-1].expression)));
    }
#line 1857 "parser/aft.tab.c"
    break;

  case 46: /* statement: if_stmt  */
#line 318 "parser/aft.y"
              {
        (yyval.statement) = (yyvsp[0].if_stmt);

    }
#line 1866 "parser/aft.tab.c"
    break;

  case 47: /* statement: while_stmt  */
#line 322 "parser/aft.y"
                 {
        (yyval.statement) = (yyvsp[0].statement);
    }
#line 1874 "parser/aft.tab.c"
    break;

  case 48: /* statement: for_stmt  */
#line 325 "parser/aft.y"
               {
        (yyval.statement) = (yyvsp[0].statement);

    }
#line 1883 "parser/aft.tab.c"
    break;

  case 49: /* statement: repeat_stmt  */
#line 329 "parser/aft.y"
                  {
        (yyval.statement) = (yyvsp[0].statement);

    }
#line 1892 "parser/aft.tab.c"
    break;

  case 50: /* statement: return_stmt SEMICOLON  */
#line 333 "parser/aft.y"
                            {
        (yyval.statement) = (yyvsp[-1].statement);

    }
#line 1901 "parser/aft.tab.c"
    break;

  case 51: /* statement: BREAK SEMICOLON  */
#line 337 "parser/aft.y"
                      {
        (yyval.statement) = new BreakStmt();
    }
#line 1909 "parser/aft.tab.c"
    break;

  case 52: /* statement: CONTINUE SEMICOLON  */
#line 340 "parser/aft.y"
                         {
        (yyval.statement) = new ContinueStmt();
    }
#line 1917 "parser/aft.tab.c"
    break;

  case 53: /* let_decl: LET IDENTIFIER ASSIGN expression  */
#line 348 "parser/aft.y"
                                     {
        LetDecl* node = new LetDecl();
        node->names.push_back(std::string((yyvsp[-2].sval)));
        free((yyvsp[-2].sval));
        node->types.clear();
        node->values.push_back(ExprPtr((yyvsp[0].expression)));
        (yyval.let_decl) = node;
    }
#line 1930 "parser/aft.tab.c"
    break;

  case 54: /* let_decl: LET IDENTIFIER COLON type ASSIGN expression  */
#line 356 "parser/aft.y"
                                                  {
        LetDecl* node = new LetDecl();
        node->names.push_back(std::string((yyvsp[-4].sval)));
        free((yyvsp[-4].sval));
        node->types.push_back(TypePtr((yyvsp[-2].type)));
        node->values.push_back(ExprPtr((yyvsp[0].expression)));
        (yyval.let_decl) = node;
    }
#line 1943 "parser/aft.tab.c"
    break;

  case 55: /* let_decl: LET LEFTPAREN identifier_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN  */
#line 364 "parser/aft.y"
                                                                                           {
        LetDecl* node = new LetDecl();
        if ((yyvsp[-5].identifier_list)) {
            for (auto name : *(yyvsp[-5].identifier_list)) {
                node->names.push_back(name);
            }
            delete (yyvsp[-5].identifier_list);
        }
        if ((yyvsp[-1].expr_list)) {
            for (auto* e : *(yyvsp[-1].expr_list)) {
                node->values.push_back(ExprPtr(e));
            }
            delete (yyvsp[-1].expr_list);
        }
        (yyval.let_decl) = node;
    }
#line 1964 "parser/aft.tab.c"
    break;

  case 56: /* let_decl: LET LEFTPAREN identifier_list RIGHTPAREN COLON LEFTPAREN type_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN  */
#line 380 "parser/aft.y"
                                                                                                                                {
        LetDecl* node = new LetDecl();
        if ((yyvsp[-9].identifier_list)) {
            for (auto name : *(yyvsp[-9].identifier_list)) {
                node->names.push_back(name);
            }
            delete (yyvsp[-9].identifier_list);
        }
        if ((yyvsp[-5].type_list)) {
            for (auto* t : *(yyvsp[-5].type_list)) {
                node->types.push_back(TypePtr(t));
            }
            delete (yyvsp[-5].type_list);
        }
        if ((yyvsp[-1].expr_list)) {
            for (auto* e : *(yyvsp[-1].expr_list)) {
                node->values.push_back(ExprPtr(e));
            }
            delete (yyvsp[-1].expr_list);
        }
        (yyval.let_decl) = node;
    }
#line 1991 "parser/aft.tab.c"
    break;

  case 57: /* const_decl: CONST IDENTIFIER COLON type ASSIGN expression  */
#line 405 "parser/aft.y"
                                                  {
        ConstDecl* node = new ConstDecl();
        node->names.push_back(std::string((yyvsp[-4].sval)));
        free((yyvsp[-4].sval));
        node->types.push_back(TypePtr((yyvsp[-2].type)));
        node->values.push_back(ExprPtr((yyvsp[0].expression)));
        (yyval.const_decl) = node;

    }
#line 2005 "parser/aft.tab.c"
    break;

  case 58: /* const_decl: CONST LEFTPAREN identifier_list RIGHTPAREN COLON LEFTPAREN type_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN  */
#line 414 "parser/aft.y"
                                                                                                                                  {
        ConstDecl* node = new ConstDecl();
        if ((yyvsp[-9].identifier_list)) {
            for (auto name : *(yyvsp[-9].identifier_list)) {
                node->names.push_back(name);
            }
            delete (yyvsp[-9].identifier_list);
        }
        if ((yyvsp[-5].type_list)) {
            for (auto* t : *(yyvsp[-5].type_list)) {
                node->types.push_back(TypePtr(t));
            }
            delete (yyvsp[-5].type_list);
        }
        if ((yyvsp[-1].expr_list)) {
            for (auto* e : *(yyvsp[-1].expr_list)) {
                node->values.push_back(ExprPtr(e));
            }
            delete (yyvsp[-1].expr_list);
        }
        (yyval.const_decl) = node;
    }
#line 2032 "parser/aft.tab.c"
    break;

  case 59: /* identifier_list: IDENTIFIER COMMA IDENTIFIER  */
#line 439 "parser/aft.y"
                                {
        (yyval.identifier_list) = new std::vector<std::string>();
        (yyval.identifier_list)->push_back(std::string((yyvsp[-2].sval)));
        free((yyvsp[-2].sval));
        (yyval.identifier_list)->push_back(std::string((yyvsp[0].sval)));
        free((yyvsp[0].sval));
    }
#line 2044 "parser/aft.tab.c"
    break;

  case 60: /* identifier_list: identifier_list COMMA IDENTIFIER  */
#line 446 "parser/aft.y"
                                       {
        (yyval.identifier_list) = (yyvsp[-2].identifier_list);
        (yyval.identifier_list)->push_back((yyvsp[0].sval));
    }
#line 2053 "parser/aft.tab.c"
    break;

  case 61: /* assignment: IDENTIFIER ASSIGN expression  */
#line 453 "parser/aft.y"
                                 {
        Assignment* node = new Assignment();
        node->targets.push_back(ExprPtr(new IdentifierExpr(std::string((yyvsp[-2].sval)))));
        free((yyvsp[-2].sval));
        node->values.push_back(ExprPtr((yyvsp[0].expression)));
        (yyval.statement) = node;


    }
#line 2067 "parser/aft.tab.c"
    break;

  case 62: /* assignment: LEFTPAREN identifier_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN  */
#line 462 "parser/aft.y"
                                                                                       {
        Assignment* node = new Assignment();
        if ((yyvsp[-5].identifier_list)) {
            for (auto name : *(yyvsp[-5].identifier_list)) {
                node->targets.push_back(ExprPtr(new IdentifierExpr(name)));
            }
            delete (yyvsp[-5].identifier_list);
        }
        if ((yyvsp[-1].expr_list)) {
            for (auto* e : *(yyvsp[-1].expr_list)) {
                node->values.push_back(ExprPtr(e));
            }
            delete (yyvsp[-1].expr_list);
        }
        (yyval.statement) = node;
    }
#line 2088 "parser/aft.tab.c"
    break;

  case 63: /* assignment: expression LEFTSQUARE expression RIGHTSQUARE ASSIGN expression  */
#line 479 "parser/aft.y"
    {
        Assignment* node = new Assignment();
        node->targets.push_back(
            ExprPtr(new IndexExpression(
                ExprPtr((yyvsp[-5].expression)),
                ExprPtr((yyvsp[-3].expression))
            ))
        );
        node->values.push_back(ExprPtr((yyvsp[0].expression)));
        (yyval.statement) = node;
    }
#line 2104 "parser/aft.tab.c"
    break;

  case 64: /* if_stmt: IF expression statement_block  */
#line 494 "parser/aft.y"
                                  {
        IfStmt* node = new IfStmt();
        node->condition = ExprPtr((yyvsp[-1].expression));
        node->then_block = std::unique_ptr<StatementBlock>((yyvsp[0].stmt_block));
        node->else_block = std::nullopt;
        node->else_if = std::nullopt;
        (yyval.if_stmt) = node;

    }
#line 2118 "parser/aft.tab.c"
    break;

  case 65: /* if_stmt: IF expression statement_block ELSE statement_block  */
#line 503 "parser/aft.y"
                                                         {
        IfStmt* node = new IfStmt();
        node->condition = ExprPtr((yyvsp[-3].expression));
        node->then_block = std::unique_ptr<StatementBlock>((yyvsp[-2].stmt_block));
        node->else_block = std::optional<std::unique_ptr<StatementBlock>>(std::unique_ptr<StatementBlock>((yyvsp[0].stmt_block)));
        node->else_if = std::nullopt;
        (yyval.if_stmt) = node;
    }
#line 2131 "parser/aft.tab.c"
    break;

  case 66: /* if_stmt: IF expression statement_block ELSE if_stmt  */
#line 511 "parser/aft.y"
                                                 {
        IfStmt* node = new IfStmt();
        node->condition = ExprPtr((yyvsp[-3].expression));
        node->then_block = std::unique_ptr<StatementBlock>((yyvsp[-2].stmt_block));
        node->else_block = std::nullopt;
        node->else_if = std::make_optional<std::unique_ptr<IfStmt>>(std::unique_ptr<IfStmt>((yyvsp[0].if_stmt)));
        (yyval.if_stmt) = node;
    }
#line 2144 "parser/aft.tab.c"
    break;

  case 67: /* while_stmt: WHILE expression statement_block  */
#line 522 "parser/aft.y"
                                     {
        WhileStmt* node = new WhileStmt();
        node->condition = ExprPtr((yyvsp[-1].expression));
        node->body = std::unique_ptr<StatementBlock>((yyvsp[0].stmt_block));
        (yyval.statement) = node;
    }
#line 2155 "parser/aft.tab.c"
    break;

  case 68: /* for_stmt: FOR IDENTIFIER IN expression statement_block  */
#line 531 "parser/aft.y"
                                                 {
        ForStmt* node = new ForStmt();
        node->iterator = std::string((yyvsp[-3].sval));
        free((yyvsp[-3].sval));
        node->iterable = ExprPtr((yyvsp[-1].expression));
        node->body = std::unique_ptr<StatementBlock>((yyvsp[0].stmt_block));
        (yyval.statement) = node;
    }
#line 2168 "parser/aft.tab.c"
    break;

  case 69: /* repeat_stmt: REPEAT expression statement_block  */
#line 542 "parser/aft.y"
                                      {
        RepeatStmt* node = new RepeatStmt();
        node->count = ExprPtr((yyvsp[-1].expression));
        node->body = std::unique_ptr<StatementBlock>((yyvsp[0].stmt_block));
        (yyval.statement) = node;
    }
#line 2179 "parser/aft.tab.c"
    break;

  case 70: /* return_stmt: RETURN expression_list  */
#line 551 "parser/aft.y"
                           {
        ReturnStmt* node = new ReturnStmt();
        if ((yyvsp[0].expr_list)) {
            for (auto* e : *(yyvsp[0].expr_list)) {
                node->values.push_back(ExprPtr(e));
            }
            delete (yyvsp[0].expr_list);
        }
        (yyval.statement) = node;
    }
#line 2194 "parser/aft.tab.c"
    break;

  case 71: /* return_stmt: RETURN  */
#line 561 "parser/aft.y"
             {
        ReturnStmt* node = new ReturnStmt();
        (yyval.statement) = node;
    }
#line 2203 "parser/aft.tab.c"
    break;

  case 72: /* function_call: IDENTIFIER LEFTPAREN argument_list RIGHTPAREN  */
#line 568 "parser/aft.y"
                                                  {
        FunctionCallExpr* node = new FunctionCallExpr(std::string((yyvsp[-3].sval)), {});
        free((yyvsp[-3].sval));
        if ((yyvsp[-1].expr_list)) {
            for (auto e : *(yyvsp[-1].expr_list)) node->arguments.push_back(ExprPtr(e));
            delete (yyvsp[-1].expr_list);
        }
        (yyval.function_call) = node;

    }
#line 2218 "parser/aft.tab.c"
    break;

  case 73: /* argument_list: expression_list  */
#line 581 "parser/aft.y"
                    {
        (yyval.expr_list)=(yyvsp[0].expr_list);
    }
#line 2226 "parser/aft.tab.c"
    break;

  case 74: /* argument_list: %empty  */
#line 584 "parser/aft.y"
                  {
        (yyval.expr_list) = nullptr;
    }
#line 2234 "parser/aft.tab.c"
    break;

  case 75: /* unary_expression: PLUS expression  */
#line 590 "parser/aft.y"
                                     {
       UnaryExpression* node = new UnaryExpression(UnaryOp::PLUS, ExprPtr((yyvsp[0].expression)));
        (yyval.expression) = node;
    }
#line 2243 "parser/aft.tab.c"
    break;

  case 76: /* unary_expression: MINUS expression  */
#line 594 "parser/aft.y"
                                         {
       UnaryExpression* node = new UnaryExpression(UnaryOp::MINUS, ExprPtr((yyvsp[0].expression)));
        (yyval.expression) = node;
    }
#line 2252 "parser/aft.tab.c"
    break;

  case 77: /* unary_expression: REVERSE expression  */
#line 598 "parser/aft.y"
                         {
        UnaryExpression* node = new UnaryExpression(UnaryOp::REVERSE, ExprPtr((yyvsp[0].expression)));
        (yyval.expression) = node;
    }
#line 2261 "parser/aft.tab.c"
    break;

  case 78: /* expression: range_expr  */
#line 604 "parser/aft.y"
              {
        (yyval.expression) = (yyvsp[0].expression);
    }
#line 2269 "parser/aft.tab.c"
    break;

  case 79: /* expression: function_call  */
#line 607 "parser/aft.y"
                   {
        (yyval.expression) = (yyvsp[0].function_call);
    }
#line 2277 "parser/aft.tab.c"
    break;

  case 80: /* expression: IDENTIFIER  */
#line 610 "parser/aft.y"
                {
        (yyval.expression) = new IdentifierExpr(std::string((yyvsp[0].sval)));
        free((yyvsp[0].sval));
    }
#line 2286 "parser/aft.tab.c"
    break;

  case 81: /* expression: LEFTPAREN expression RIGHTPAREN  */
#line 614 "parser/aft.y"
                                      {
        (yyval.expression) = (yyvsp[-1].expression);
    }
#line 2294 "parser/aft.tab.c"
    break;

  case 82: /* expression: unary_expression  */
#line 617 "parser/aft.y"
                       {
        (yyval.expression) = (yyvsp[0].expression);
    }
#line 2302 "parser/aft.tab.c"
    break;

  case 83: /* expression: expression PLUS expression  */
#line 620 "parser/aft.y"
                                 {
        (yyval.expression) = new BinaryExpression(BinaryOp::PLUS, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2310 "parser/aft.tab.c"
    break;

  case 84: /* expression: expression MINUS expression  */
#line 623 "parser/aft.y"
                                  {
        (yyval.expression) = new BinaryExpression(BinaryOp::MINUS, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2318 "parser/aft.tab.c"
    break;

  case 85: /* expression: expression MULTIPLY expression  */
#line 626 "parser/aft.y"
                                     {
        (yyval.expression) = new BinaryExpression(BinaryOp::MULTIPLY, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2326 "parser/aft.tab.c"
    break;

  case 86: /* expression: expression DIVIDE expression  */
#line 629 "parser/aft.y"
                                   {
        (yyval.expression) = new BinaryExpression(BinaryOp::DIVIDE, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2334 "parser/aft.tab.c"
    break;

  case 87: /* expression: expression MODULO expression  */
#line 632 "parser/aft.y"
                                   {
        (yyval.expression) = new BinaryExpression(BinaryOp::MODULO, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2342 "parser/aft.tab.c"
    break;

  case 88: /* expression: expression EXPONENTIATE expression  */
#line 635 "parser/aft.y"
                                         {
        (yyval.expression) = new BinaryExpression(BinaryOp::EXPONENTIATE, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2350 "parser/aft.tab.c"
    break;

  case 89: /* expression: expression EQUALS expression  */
#line 638 "parser/aft.y"
                                   {
        (yyval.expression) = new BinaryExpression(BinaryOp::EQUALS, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2358 "parser/aft.tab.c"
    break;

  case 90: /* expression: expression NOTEQUAL expression  */
#line 641 "parser/aft.y"
                                     {
        (yyval.expression) = new BinaryExpression(BinaryOp::NOTEQUAL, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2366 "parser/aft.tab.c"
    break;

  case 91: /* expression: expression LESSTHAN expression  */
#line 644 "parser/aft.y"
                                     {
        (yyval.expression) = new BinaryExpression(BinaryOp::LESSTHAN, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2374 "parser/aft.tab.c"
    break;

  case 92: /* expression: expression GREATERTHAN expression  */
#line 647 "parser/aft.y"
                                        {
        (yyval.expression) = new BinaryExpression(BinaryOp::GREATERTHAN, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2382 "parser/aft.tab.c"
    break;

  case 93: /* expression: expression LESSTHANEQUAL expression  */
#line 650 "parser/aft.y"
                                          {
        (yyval.expression) = new BinaryExpression(BinaryOp::LESSTHANEQUAL, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2390 "parser/aft.tab.c"
    break;

  case 94: /* expression: expression GREATERTHANEQUAL expression  */
#line 653 "parser/aft.y"
                                             {
        (yyval.expression) = new BinaryExpression(BinaryOp::GREATERTHANEQUAL, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2398 "parser/aft.tab.c"
    break;

  case 95: /* expression: expression AND expression  */
#line 656 "parser/aft.y"
                                {
        (yyval.expression) = new BinaryExpression(BinaryOp::AND, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2406 "parser/aft.tab.c"
    break;

  case 96: /* expression: expression OR expression  */
#line 659 "parser/aft.y"
                               {
        (yyval.expression) = new BinaryExpression(BinaryOp::OR, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2414 "parser/aft.tab.c"
    break;

  case 97: /* expression: expression XOR expression  */
#line 662 "parser/aft.y"
                                {
        (yyval.expression) = new BinaryExpression(BinaryOp::XOR, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2422 "parser/aft.tab.c"
    break;

  case 98: /* expression: NOT expression  */
#line 665 "parser/aft.y"
                     {
        (yyval.expression) = new UnaryExpression(UnaryOp::NOT, ExprPtr((yyvsp[0].expression)));
    }
#line 2430 "parser/aft.tab.c"
    break;

  case 99: /* expression: expression BITWISEAND expression  */
#line 668 "parser/aft.y"
                                       {
        (yyval.expression) = new BinaryExpression(BinaryOp::BITWISEAND, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2438 "parser/aft.tab.c"
    break;

  case 100: /* expression: expression BITWISEOR expression  */
#line 671 "parser/aft.y"
                                      {
        (yyval.expression) = new BinaryExpression(BinaryOp::BITWISEOR, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2446 "parser/aft.tab.c"
    break;

  case 101: /* expression: expression LEFTSHIFT expression  */
#line 674 "parser/aft.y"
                                      {
        (yyval.expression) = new BinaryExpression(BinaryOp::LEFTSHIFT, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2454 "parser/aft.tab.c"
    break;

  case 102: /* expression: expression RIGHTSHIFT expression  */
#line 677 "parser/aft.y"
                                       {
        (yyval.expression) = new BinaryExpression(BinaryOp::RIGHTSHIFT, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2462 "parser/aft.tab.c"
    break;

  case 103: /* expression: expression CONVOLUTION expression  */
#line 680 "parser/aft.y"
                                        {
        (yyval.expression) = new BinaryExpression(BinaryOp::CONVOLUTION, ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)));
    }
#line 2470 "parser/aft.tab.c"
    break;

  case 104: /* expression: expression LEFTSQUARE expression RIGHTSQUARE  */
#line 683 "parser/aft.y"
                                                   {
        (yyval.expression) = new IndexExpression(ExprPtr((yyvsp[-3].expression)), ExprPtr((yyvsp[-1].expression)));
    }
#line 2478 "parser/aft.tab.c"
    break;

  case 105: /* expression: expression AS type  */
#line 686 "parser/aft.y"
                         {
        (yyval.expression) = new TypeCastExpr(ExprPtr((yyvsp[-2].expression)),TypePtr((yyvsp[0].type)));
    }
#line 2486 "parser/aft.tab.c"
    break;

  case 106: /* expression: literal  */
#line 689 "parser/aft.y"
             {
        (yyval.expression) = (yyvsp[0].expression);
    }
#line 2494 "parser/aft.tab.c"
    break;

  case 107: /* expression_list: expression  */
#line 695 "parser/aft.y"
               {
        (yyval.expr_list) = new std::vector<Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expression));


    }
#line 2505 "parser/aft.tab.c"
    break;

  case 108: /* expression_list: expression_list COMMA expression  */
#line 701 "parser/aft.y"
                                       {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expression));
    }
#line 2514 "parser/aft.tab.c"
    break;

  case 109: /* literal: INTEGER  */
#line 708 "parser/aft.y"
            {
        (yyval.expression) = new IntegerLiteral(std::string((yyvsp[0].sval)));
        free((yyvsp[0].sval));
    }
#line 2523 "parser/aft.tab.c"
    break;

  case 110: /* literal: FLOAT  */
#line 712 "parser/aft.y"
            {
        (yyval.expression) = new FloatLiteral(std::string((yyvsp[0].sval)));
        free((yyvsp[0].sval));

    }
#line 2533 "parser/aft.tab.c"
    break;

  case 111: /* literal: COMPLEX  */
#line 717 "parser/aft.y"
              {
        (yyval.expression) = new ComplexLiteral(std::string((yyvsp[0].sval)));
        free((yyvsp[0].sval));

    }
#line 2543 "parser/aft.tab.c"
    break;

  case 112: /* literal: TRUE  */
#line 722 "parser/aft.y"
           {
        (yyval.expression) = new BoolLiteral(true);

    }
#line 2552 "parser/aft.tab.c"
    break;

  case 113: /* literal: FALSE  */
#line 726 "parser/aft.y"
            {
        (yyval.expression) = new BoolLiteral(false);
    }
#line 2560 "parser/aft.tab.c"
    break;

  case 114: /* literal: PI  */
#line 729 "parser/aft.y"
         {
        (yyval.expression) = new PiLiteral();
    }
#line 2568 "parser/aft.tab.c"
    break;

  case 115: /* literal: vector_literal  */
#line 732 "parser/aft.y"
                     {
        (yyval.expression) = (yyvsp[0].expression);
    }
#line 2576 "parser/aft.tab.c"
    break;

  case 116: /* literal: STRING  */
#line 735 "parser/aft.y"
             {
        (yyval.expression) = new StringLiteral(std::string((yyvsp[0].sval)));
    }
#line 2584 "parser/aft.tab.c"
    break;

  case 117: /* vector_literal: LEFTSQUARE vector_elements RIGHTSQUARE  */
#line 741 "parser/aft.y"
                                           {
        VectorLiteralExpr* node = new VectorLiteralExpr();
        if ((yyvsp[-1].expr_list)) {
            for (auto e : *(yyvsp[-1].expr_list)) {
                node->elements.push_back(ExprPtr(e));
            }
            delete (yyvsp[-1].expr_list);
        }
        node->inferred_type = nullptr;
        (yyval.expression) = node;
    }
#line 2600 "parser/aft.tab.c"
    break;

  case 118: /* vector_literal: LEFTSQUARE RIGHTSQUARE  */
#line 752 "parser/aft.y"
                             {
        VectorLiteralExpr* node = new VectorLiteralExpr();
        node->inferred_type = nullptr;
        (yyval.expression) = node;
    }
#line 2610 "parser/aft.tab.c"
    break;

  case 119: /* vector_elements: expression  */
#line 759 "parser/aft.y"
               {
        (yyval.expr_list) = new std::vector<Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expression));

    }
#line 2620 "parser/aft.tab.c"
    break;

  case 120: /* vector_elements: vector_elements COMMA expression  */
#line 764 "parser/aft.y"
                                       {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expression));
    }
#line 2629 "parser/aft.tab.c"
    break;

  case 121: /* range_expr: expression RANGE expression  */
#line 771 "parser/aft.y"
                                {
        (yyval.expression) = new RangeExpr(ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)), false);
    }
#line 2637 "parser/aft.tab.c"
    break;

  case 122: /* range_expr: expression RANGEUPTO expression  */
#line 774 "parser/aft.y"
                                      {
        (yyval.expression) = new RangeExpr(ExprPtr((yyvsp[-2].expression)), ExprPtr((yyvsp[0].expression)), true);
    }
#line 2645 "parser/aft.tab.c"
    break;


#line 2649 "parser/aft.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 779 "parser/aft.y"


void yyerror(const char*s) {
    fprintf(stderr, "Parse error at line %d: %s\n", yylineno, s);
    fprintf(stderr, "Near token: %s\n", yytext);
}

