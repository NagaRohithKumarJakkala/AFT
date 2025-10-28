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
#line 1 "aft.y"

    #include<stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "AST.h"
    extern int yylex();
    extern int yylineno;
    extern char *yytext;

    void yyerror(const char*s);

#line 83 "aft.tab.c"

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
  YYSYMBOL_PLUS = 42,                      /* PLUS  */
  YYSYMBOL_MINUS = 43,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 44,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 45,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 46,                    /* MODULO  */
  YYSYMBOL_EXPONENTIATE = 47,              /* EXPONENTIATE  */
  YYSYMBOL_EQUALS = 48,                    /* EQUALS  */
  YYSYMBOL_NOTEQUAL = 49,                  /* NOTEQUAL  */
  YYSYMBOL_LESSTHAN = 50,                  /* LESSTHAN  */
  YYSYMBOL_GREATERTHAN = 51,               /* GREATERTHAN  */
  YYSYMBOL_LESSTHANEQUAL = 52,             /* LESSTHANEQUAL  */
  YYSYMBOL_GREATERTHANEQUAL = 53,          /* GREATERTHANEQUAL  */
  YYSYMBOL_AND = 54,                       /* AND  */
  YYSYMBOL_OR = 55,                        /* OR  */
  YYSYMBOL_XOR = 56,                       /* XOR  */
  YYSYMBOL_NOT = 57,                       /* NOT  */
  YYSYMBOL_BITWISEAND = 58,                /* BITWISEAND  */
  YYSYMBOL_BITWISEOR = 59,                 /* BITWISEOR  */
  YYSYMBOL_LEFTSHIFT = 60,                 /* LEFTSHIFT  */
  YYSYMBOL_RIGHTSHIFT = 61,                /* RIGHTSHIFT  */
  YYSYMBOL_CONVOLUTION = 62,               /* CONVOLUTION  */
  YYSYMBOL_REVERSE = 63,                   /* REVERSE  */
  YYSYMBOL_RANGE = 64,                     /* RANGE  */
  YYSYMBOL_RANGEUPTO = 65,                 /* RANGEUPTO  */
  YYSYMBOL_ASSIGN = 66,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 67,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 68,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 69,                     /* COLON  */
  YYSYMBOL_DOT = 70,                       /* DOT  */
  YYSYMBOL_LEFTBRACE = 71,                 /* LEFTBRACE  */
  YYSYMBOL_RIGHTBRACE = 72,                /* RIGHTBRACE  */
  YYSYMBOL_LEFTPAREN = 73,                 /* LEFTPAREN  */
  YYSYMBOL_RIGHTPAREN = 74,                /* RIGHTPAREN  */
  YYSYMBOL_LEFTSQUARE = 75,                /* LEFTSQUARE  */
  YYSYMBOL_RIGHTSQUARE = 76,               /* RIGHTSQUARE  */
  YYSYMBOL_UNARY_PLUS = 77,                /* UNARY_PLUS  */
  YYSYMBOL_UNARY_MINUS = 78,               /* UNARY_MINUS  */
  YYSYMBOL_YYACCEPT = 79,                  /* $accept  */
  YYSYMBOL_program = 80,                   /* program  */
  YYSYMBOL_struct_decl = 81,               /* struct_decl  */
  YYSYMBOL_function_decl = 82,             /* function_decl  */
  YYSYMBOL_parameter_list = 83,            /* parameter_list  */
  YYSYMBOL_parameter = 84,                 /* parameter  */
  YYSYMBOL_return_type_list = 85,          /* return_type_list  */
  YYSYMBOL_type_list = 86,                 /* type_list  */
  YYSYMBOL_type = 87,                      /* type  */
  YYSYMBOL_primitive_type = 88,            /* primitive_type  */
  YYSYMBOL_vector_type = 89,               /* vector_type  */
  YYSYMBOL_statement_block = 90,           /* statement_block  */
  YYSYMBOL_statement_list = 91,            /* statement_list  */
  YYSYMBOL_statement = 92,                 /* statement  */
  YYSYMBOL_let_decl = 93,                  /* let_decl  */
  YYSYMBOL_const_decl = 94,                /* const_decl  */
  YYSYMBOL_identifier_list = 95,           /* identifier_list  */
  YYSYMBOL_assignment = 96,                /* assignment  */
  YYSYMBOL_if_stmt = 97,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 98,                /* while_stmt  */
  YYSYMBOL_for_stmt = 99,                  /* for_stmt  */
  YYSYMBOL_repeat_stmt = 100,              /* repeat_stmt  */
  YYSYMBOL_return_stmt = 101,              /* return_stmt  */
  YYSYMBOL_function_call = 102,            /* function_call  */
  YYSYMBOL_argument_list = 103,            /* argument_list  */
  YYSYMBOL_unary_expression = 104,         /* unary_expression  */
  YYSYMBOL_expression = 105,               /* expression  */
  YYSYMBOL_expression_list = 106,          /* expression_list  */
  YYSYMBOL_literal = 107,                  /* literal  */
  YYSYMBOL_vector_literal = 108,           /* vector_literal  */
  YYSYMBOL_vector_elements = 109,          /* vector_elements  */
  YYSYMBOL_range_expr = 110                /* range_expr  */
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
#define YYLAST   706

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  243

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   333


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
      75,    76,    77,    78
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    76,    78,    80,    85,    86,    90,    93,
      99,   102,   108,   114,   117,   120,   126,   129,   135,   138,
     141,   146,   149,   152,   155,   158,   161,   164,   167,   170,
     173,   176,   179,   182,   185,   188,   193,   199,   202,   208,
     211,   217,   220,   223,   226,   229,   232,   235,   238,   241,
     244,   247,   255,   258,   261,   264,   270,   273,   279,   282,
     288,   291,   297,   300,   303,   309,   315,   321,   327,   330,
     336,   340,   341,   345,   346,   347,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   382,   385,   391,   394,   397,
     400,   403,   406,   409,   412,   416,   417,   420,   423,   429,
     432
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
  "C32", "C64", "BOOL", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODULO",
  "EXPONENTIATE", "EQUALS", "NOTEQUAL", "LESSTHAN", "GREATERTHAN",
  "LESSTHANEQUAL", "GREATERTHANEQUAL", "AND", "OR", "XOR", "NOT",
  "BITWISEAND", "BITWISEOR", "LEFTSHIFT", "RIGHTSHIFT", "CONVOLUTION",
  "REVERSE", "RANGE", "RANGEUPTO", "ASSIGN", "COMMA", "SEMICOLON", "COLON",
  "DOT", "LEFTBRACE", "RIGHTBRACE", "LEFTPAREN", "RIGHTPAREN",
  "LEFTSQUARE", "RIGHTSQUARE", "UNARY_PLUS", "UNARY_MINUS", "$accept",
  "program", "struct_decl", "function_decl", "parameter_list", "parameter",
  "return_type_list", "type_list", "type", "primitive_type", "vector_type",
  "statement_block", "statement_list", "statement", "let_decl",
  "const_decl", "identifier_list", "assignment", "if_stmt", "while_stmt",
  "for_stmt", "repeat_stmt", "return_stmt", "function_call",
  "argument_list", "unary_expression", "expression", "expression_list",
  "literal", "vector_literal", "vector_elements", "range_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -131,    24,  -131,    12,     3,     5,  -131,  -131,   -30,   -15,
      47,   -18,   -28,  -131,   341,   -11,   -61,     9,    16,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,   341,    40,  -131,  -131,   106,
     108,    78,    79,   281,   -47,  -131,  -131,   -55,    73,   218,
    -131,  -131,    43,   341,   341,    82,  -131,   144,   281,  -131,
    -131,  -131,  -131,  -131,    83,  -131,  -131,  -131,  -131,   218,
     218,   218,   218,   218,   115,  -131,  -131,   485,  -131,  -131,
    -131,   341,  -131,   -27,  -131,   190,  -131,  -131,    82,   218,
      80,    80,    80,    80,   383,  -131,   485,   -60,   341,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   -26,   341,  -131,   -24,    13,   218,   218,   218,
     154,   218,    94,    95,  -131,   292,   231,  -131,    96,    97,
     100,  -131,  -131,  -131,  -131,   101,   417,  -131,    99,   485,
     103,  -131,   218,  -131,  -131,   631,   631,   128,   128,   128,
     128,    84,    84,    84,    84,    84,    84,   587,   553,   621,
     627,   282,    92,    92,   128,   519,   519,   343,   110,  -131,
     218,   -43,    47,   103,   451,   451,   155,   451,  -131,  -131,
     -59,   -17,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
     218,   485,  -131,   104,   485,   218,   341,   -16,   163,  -131,
     218,  -131,   114,   485,   218,   485,   116,   -41,   -12,   451,
     111,    20,   218,   112,   113,  -131,  -131,  -131,   218,  -131,
     485,   218,   341,    26,    28,    36,  -131,  -131,   121,   133,
     218,    37,  -131
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     5,     3,     0,     0,
       0,     0,     0,     4,     0,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    18,    19,     0,
       0,     0,     0,    13,     0,    10,     6,     0,     0,     0,
      58,    59,     0,     0,     0,     0,    14,     0,    13,     7,
      36,   107,   108,   109,    78,   114,   110,   111,   112,     0,
       0,     0,     0,     0,     0,    77,    80,    56,   104,   113,
      76,     0,    12,     0,    16,     0,     9,    11,     0,    72,
      73,    74,    96,    75,     0,   116,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,    78,     0,    69,     0,     0,
       0,     0,     0,     0,    38,     0,     0,    39,     0,     0,
       0,    45,    46,    47,    48,     0,     0,     8,     0,   105,
      71,    79,     0,   115,   103,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      97,    98,    99,   100,   101,   119,   120,     0,     0,    17,
       0,     0,     0,    68,     0,     0,     0,     0,    51,    50,
      78,     0,    37,    40,    41,    42,    43,    49,    44,    70,
       0,   118,   102,     0,    60,     0,     0,     0,    62,    65,
       0,    67,     0,   106,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    66,     0,    57,
      53,     0,     0,     0,     0,     0,    61,    54,     0,     0,
       0,     0,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,  -131,   171,   124,   151,   -80,   -14,  -131,
    -131,   -86,  -131,    75,  -131,   211,  -130,  -131,    -5,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,   -39,  -123,  -131,  -131,
    -131,  -131
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     6,     7,    44,    45,    55,    83,    84,    37,
      38,    86,   136,   137,   138,   139,    16,   140,   141,   142,
     143,   144,   145,    75,   148,    76,   149,   150,    78,    79,
      97,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,   122,   147,   128,   183,   191,    40,   152,    39,    11,
      77,    12,    57,    41,    89,    42,   153,    59,     9,   181,
      57,    48,    42,   205,     2,   223,   206,    58,   224,    56,
      90,    91,    92,    93,    94,    96,     3,     4,    13,    82,
     123,   123,   180,    18,    56,     5,   146,   124,   178,    89,
      40,    40,   207,    15,    14,    17,    39,   212,   217,    85,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,    43,   154,    10,   182,   200,    46,   184,
     185,   221,   187,   200,   229,   200,    94,   146,   208,   209,
     236,   211,   237,   123,   200,   233,    49,    98,   234,   179,
     238,   242,    50,   201,    51,    98,    81,   241,    61,    62,
      63,    64,    65,    66,    67,    68,    99,   100,   101,   102,
     103,   104,   225,   227,    99,   100,   101,   102,   103,   104,
     113,   204,   114,   115,   116,   117,   118,    52,    53,    60,
      42,    98,   235,    85,   118,   121,    89,    69,    70,   121,
     186,   213,   188,   189,   194,   195,   215,   121,   196,   197,
     200,   219,    71,   199,   210,   104,   203,   214,    72,   218,
     220,    87,   222,   230,   228,   231,   232,   239,    73,    47,
      74,    95,   216,    61,    62,    63,   125,    65,    66,    67,
      68,   126,     3,   121,   127,   128,   240,   129,   130,    88,
     131,   193,     8,   226,   132,   133,     0,     0,     0,     0,
       0,    61,    62,    63,    64,    65,    66,    67,    68,     0,
       0,     0,    69,    70,    61,    62,    63,   125,    65,    66,
      67,    68,   126,     3,     0,   127,   128,    71,   129,   130,
       0,   131,     0,    72,     0,   132,   133,     0,     0,     0,
      69,    70,   134,   135,     0,    74,     0,     0,     0,     0,
       0,     0,     0,    69,    70,    71,     0,     0,     0,     0,
       0,    72,     0,     0,     0,     0,     0,    19,    71,     0,
       0,    73,     0,    74,    72,    61,    62,    63,   190,    65,
      66,    67,    68,   192,   135,    98,    74,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,    99,   100,   101,   102,   103,   104,
       0,     0,     0,     0,    69,    70,     0,     0,   113,     0,
     114,     0,   116,   117,   118,     0,     0,    19,     0,    71,
       0,     0,     0,     0,    54,    72,    35,   121,     0,     0,
       0,     0,     0,     0,     0,    73,    98,    74,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       0,   114,   115,   116,   117,   118,    98,   119,   120,     0,
       0,     0,     0,     0,     0,     0,    35,     0,   121,   202,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      98,   114,   115,   116,   117,   118,     0,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,   151,   121,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    98,   114,   115,   116,   117,   118,
       0,   119,   120,     0,     0,   198,     0,     0,     0,     0,
       0,     0,   121,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    98,   114,
     115,   116,   117,   118,     0,   119,   120,     0,     0,     0,
       0,     0,    85,     0,     0,     0,   121,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    98,   114,   115,   116,   117,   118,     0,   119,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    98,   114,   115,   116,
     117,   118,     0,    -1,    -1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   113,
      98,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,     0,     0,   113,    98,   114,   115,   116,   117,   118,
      98,     0,     0,     0,    98,     0,     0,     0,     0,     0,
       0,     0,   121,    99,   100,   101,   102,   103,   104,    99,
     100,   101,   102,   103,   104,   101,   102,   103,   104,   114,
       0,   116,   117,   118,     0,     0,     0,   116,   117,   118,
       0,     0,     0,   118,     0,     0,   121,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   121
};

static const yytype_int16 yycheck[] =
{
      14,    81,    88,    15,   127,   135,    67,    67,    67,     6,
      49,     6,    67,    74,    73,     6,    76,    72,     6,     6,
      67,    35,     6,    66,     0,    66,    69,    74,    69,    43,
      69,    70,    71,    72,    73,    74,    12,    13,    68,    53,
      67,    67,    66,    71,    58,    21,    85,    74,    74,    73,
      67,    67,   182,     6,    69,    73,    67,    74,    74,    71,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    74,    98,    73,    73,    67,    72,   128,
     129,   214,   131,    67,    74,    67,   135,   136,   184,   185,
      74,   187,    74,    67,    67,   228,    66,    23,   231,   123,
      74,    74,     6,   152,     6,    23,    73,   240,     3,     4,
       5,     6,     7,     8,     9,    10,    42,    43,    44,    45,
      46,    47,   218,   219,    42,    43,    44,    45,    46,    47,
      56,   180,    58,    59,    60,    61,    62,    69,    69,    76,
       6,    23,   232,    71,    62,    75,    73,    42,    43,    75,
       6,   200,    68,    68,    68,    68,   205,    75,    68,    68,
      67,   210,    57,    74,    19,    47,    66,    73,    63,    16,
      66,    57,    66,   222,    73,    73,    73,    66,    73,    18,
      75,    76,   206,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    75,    14,    15,    73,    17,    18,    58,
      20,   136,     1,   218,    24,    25,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    42,    43,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    57,    17,    18,
      -1,    20,    -1,    63,    -1,    24,    25,    -1,    -1,    -1,
      42,    43,    72,    73,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    57,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,     6,    57,    -1,
      -1,    73,    -1,    75,    63,     3,     4,     5,     6,     7,
       8,     9,    10,    72,    73,    23,    75,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    56,    -1,
      58,    -1,    60,    61,    62,    -1,    -1,     6,    -1,    57,
      -1,    -1,    -1,    -1,    73,    63,    75,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    23,    75,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    62,    23,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    75,    76,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      23,    58,    59,    60,    61,    62,    -1,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    23,    58,    59,    60,    61,    62,
      -1,    64,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    23,    58,
      59,    60,    61,    62,    -1,    64,    65,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    75,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    23,    58,    59,    60,    61,    62,    -1,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    23,    58,    59,    60,
      61,    62,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      23,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,    23,    58,    59,    60,    61,    62,
      23,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    42,    43,    44,    45,    46,    47,    42,
      43,    44,    45,    46,    47,    44,    45,    46,    47,    58,
      -1,    60,    61,    62,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,    -1,    62,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    75
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    80,     0,    12,    13,    21,    81,    82,    94,     6,
      73,     6,     6,    68,    69,     6,    95,    73,    71,     6,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    75,    87,    88,    89,    67,
      67,    74,     6,    74,    83,    84,    72,    83,    87,    66,
       6,     6,    69,    69,    73,    85,    87,    67,    74,    72,
      76,     3,     4,     5,     6,     7,     8,     9,    10,    42,
      43,    57,    63,    73,    75,   102,   104,   105,   107,   108,
     110,    73,    87,    86,    87,    71,    90,    84,    85,    73,
     105,   105,   105,   105,   105,    76,   105,   109,    23,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    58,    59,    60,    61,    62,    64,
      65,    75,    86,    67,    74,     6,    11,    14,    15,    17,
      18,    20,    24,    25,    72,    73,    91,    92,    93,    94,
      96,    97,    98,    99,   100,   101,   105,    90,   103,   105,
     106,    74,    67,    76,    87,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,    74,    87,
      66,     6,    73,   106,   105,   105,     6,   105,    68,    68,
       6,    95,    72,    92,    68,    68,    68,    68,    68,    74,
      67,   105,    76,    66,   105,    66,    69,    95,    90,    90,
      19,    90,    74,   105,    73,   105,    87,    74,    16,   105,
      66,   106,    66,    66,    69,    90,    97,    90,    73,    74,
     105,    73,    73,   106,   106,    86,    74,    74,    74,    66,
      73,   106,    74
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    79,    80,    80,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    85,    85,    85,    86,    86,    87,    87,
      87,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    89,    90,    90,    91,
      91,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    93,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    97,    98,    99,   100,   101,   101,
     102,   103,   103,   104,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   109,   109,   110,
     110
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     2,     4,     5,     7,     6,
       1,     3,     3,     0,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     2,
       2,     2,     4,     6,     8,    12,     6,    12,     3,     3,
       3,     7,     3,     5,     5,     3,     5,     3,     2,     1,
       4,     1,     0,     2,     2,     2,     1,     1,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     4,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     3,     3,
       3
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
#line 74 "aft.y"
                {
    }
#line 1446 "aft.tab.c"
    break;

  case 3: /* program: program function_decl  */
#line 76 "aft.y"
                            {
    }
#line 1453 "aft.tab.c"
    break;

  case 4: /* program: program const_decl SEMICOLON  */
#line 78 "aft.y"
                                   {
    }
#line 1460 "aft.tab.c"
    break;

  case 5: /* program: program struct_decl  */
#line 80 "aft.y"
                          {
    }
#line 1467 "aft.tab.c"
    break;

  case 6: /* struct_decl: STRUCT IDENTIFIER LEFTBRACE RIGHTBRACE  */
#line 85 "aft.y"
                                           {}
#line 1473 "aft.tab.c"
    break;

  case 7: /* struct_decl: STRUCT IDENTIFIER LEFTBRACE parameter_list RIGHTBRACE  */
#line 86 "aft.y"
                                                            {}
#line 1479 "aft.tab.c"
    break;

  case 8: /* function_decl: FUNCTION IDENTIFIER LEFTPAREN parameter_list RIGHTPAREN return_type_list statement_block  */
#line 90 "aft.y"
                                                                                             {
    }
#line 1486 "aft.tab.c"
    break;

  case 9: /* function_decl: FUNCTION IDENTIFIER LEFTPAREN RIGHTPAREN return_type_list statement_block  */
#line 93 "aft.y"
                                                                              {

    }
#line 1494 "aft.tab.c"
    break;

  case 10: /* parameter_list: parameter  */
#line 99 "aft.y"
              {

    }
#line 1502 "aft.tab.c"
    break;

  case 11: /* parameter_list: parameter_list COMMA parameter  */
#line 102 "aft.y"
                                     {

    }
#line 1510 "aft.tab.c"
    break;

  case 12: /* parameter: IDENTIFIER COLON type  */
#line 108 "aft.y"
                          {

    }
#line 1518 "aft.tab.c"
    break;

  case 13: /* return_type_list: %empty  */
#line 114 "aft.y"
                {

    }
#line 1526 "aft.tab.c"
    break;

  case 14: /* return_type_list: type  */
#line 117 "aft.y"
           {

    }
#line 1534 "aft.tab.c"
    break;

  case 15: /* return_type_list: LEFTPAREN type_list RIGHTPAREN  */
#line 120 "aft.y"
                                     {

    }
#line 1542 "aft.tab.c"
    break;

  case 16: /* type_list: type  */
#line 126 "aft.y"
         {

    }
#line 1550 "aft.tab.c"
    break;

  case 17: /* type_list: type_list COMMA type  */
#line 129 "aft.y"
                           {

    }
#line 1558 "aft.tab.c"
    break;

  case 18: /* type: primitive_type  */
#line 135 "aft.y"
                   {

    }
#line 1566 "aft.tab.c"
    break;

  case 19: /* type: vector_type  */
#line 138 "aft.y"
                  {

    }
#line 1574 "aft.tab.c"
    break;

  case 20: /* type: IDENTIFIER  */
#line 141 "aft.y"
                 { // Struct
    }
#line 1581 "aft.tab.c"
    break;

  case 21: /* primitive_type: I8  */
#line 146 "aft.y"
       {

    }
#line 1589 "aft.tab.c"
    break;

  case 22: /* primitive_type: I16  */
#line 149 "aft.y"
          {

    }
#line 1597 "aft.tab.c"
    break;

  case 23: /* primitive_type: I32  */
#line 152 "aft.y"
          {

    }
#line 1605 "aft.tab.c"
    break;

  case 24: /* primitive_type: I64  */
#line 155 "aft.y"
          {

    }
#line 1613 "aft.tab.c"
    break;

  case 25: /* primitive_type: I128  */
#line 158 "aft.y"
           {

    }
#line 1621 "aft.tab.c"
    break;

  case 26: /* primitive_type: U8  */
#line 161 "aft.y"
         {

    }
#line 1629 "aft.tab.c"
    break;

  case 27: /* primitive_type: U16  */
#line 164 "aft.y"
          {

    }
#line 1637 "aft.tab.c"
    break;

  case 28: /* primitive_type: U32  */
#line 167 "aft.y"
          {

    }
#line 1645 "aft.tab.c"
    break;

  case 29: /* primitive_type: U64  */
#line 170 "aft.y"
          {

    }
#line 1653 "aft.tab.c"
    break;

  case 30: /* primitive_type: U128  */
#line 173 "aft.y"
           {

    }
#line 1661 "aft.tab.c"
    break;

  case 31: /* primitive_type: F32  */
#line 176 "aft.y"
          {

    }
#line 1669 "aft.tab.c"
    break;

  case 32: /* primitive_type: F64  */
#line 179 "aft.y"
          {

    }
#line 1677 "aft.tab.c"
    break;

  case 33: /* primitive_type: C32  */
#line 182 "aft.y"
          {

    }
#line 1685 "aft.tab.c"
    break;

  case 34: /* primitive_type: C64  */
#line 185 "aft.y"
          {

    }
#line 1693 "aft.tab.c"
    break;

  case 35: /* primitive_type: BOOL  */
#line 188 "aft.y"
           {

    }
#line 1701 "aft.tab.c"
    break;

  case 36: /* vector_type: LEFTSQUARE type RIGHTSQUARE  */
#line 193 "aft.y"
                                {

    }
#line 1709 "aft.tab.c"
    break;

  case 37: /* statement_block: LEFTBRACE statement_list RIGHTBRACE  */
#line 199 "aft.y"
                                        {

    }
#line 1717 "aft.tab.c"
    break;

  case 38: /* statement_block: LEFTBRACE RIGHTBRACE  */
#line 202 "aft.y"
                           {

    }
#line 1725 "aft.tab.c"
    break;

  case 39: /* statement_list: statement  */
#line 208 "aft.y"
              {

    }
#line 1733 "aft.tab.c"
    break;

  case 40: /* statement_list: statement_list statement  */
#line 211 "aft.y"
                               {

    }
#line 1741 "aft.tab.c"
    break;

  case 41: /* statement: let_decl SEMICOLON  */
#line 217 "aft.y"
                       {

    }
#line 1749 "aft.tab.c"
    break;

  case 42: /* statement: const_decl SEMICOLON  */
#line 220 "aft.y"
                           {

    }
#line 1757 "aft.tab.c"
    break;

  case 43: /* statement: assignment SEMICOLON  */
#line 223 "aft.y"
                           {

    }
#line 1765 "aft.tab.c"
    break;

  case 44: /* statement: expression SEMICOLON  */
#line 226 "aft.y"
                           {

    }
#line 1773 "aft.tab.c"
    break;

  case 45: /* statement: if_stmt  */
#line 229 "aft.y"
              {

    }
#line 1781 "aft.tab.c"
    break;

  case 46: /* statement: while_stmt  */
#line 232 "aft.y"
                 {

    }
#line 1789 "aft.tab.c"
    break;

  case 47: /* statement: for_stmt  */
#line 235 "aft.y"
               {

    }
#line 1797 "aft.tab.c"
    break;

  case 48: /* statement: repeat_stmt  */
#line 238 "aft.y"
                  {

    }
#line 1805 "aft.tab.c"
    break;

  case 49: /* statement: return_stmt SEMICOLON  */
#line 241 "aft.y"
                            {

    }
#line 1813 "aft.tab.c"
    break;

  case 50: /* statement: BREAK SEMICOLON  */
#line 244 "aft.y"
                      {

    }
#line 1821 "aft.tab.c"
    break;

  case 51: /* statement: CONTINUE SEMICOLON  */
#line 247 "aft.y"
                         {

    }
#line 1829 "aft.tab.c"
    break;

  case 52: /* let_decl: LET IDENTIFIER ASSIGN expression  */
#line 255 "aft.y"
                                      {

    }
#line 1837 "aft.tab.c"
    break;

  case 53: /* let_decl: LET IDENTIFIER COLON type ASSIGN expression  */
#line 258 "aft.y"
                                                  {

    }
#line 1845 "aft.tab.c"
    break;

  case 54: /* let_decl: LET LEFTPAREN identifier_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN  */
#line 261 "aft.y"
                                                                                           {

    }
#line 1853 "aft.tab.c"
    break;

  case 55: /* let_decl: LET LEFTPAREN identifier_list RIGHTPAREN COLON LEFTPAREN type_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN  */
#line 264 "aft.y"
                                                                                                                                {

    }
#line 1861 "aft.tab.c"
    break;

  case 56: /* const_decl: CONST IDENTIFIER COLON type ASSIGN expression  */
#line 270 "aft.y"
                                                  {

    }
#line 1869 "aft.tab.c"
    break;

  case 57: /* const_decl: CONST LEFTPAREN identifier_list RIGHTPAREN COLON LEFTPAREN type_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN  */
#line 273 "aft.y"
                                                                                                                                  {

    }
#line 1877 "aft.tab.c"
    break;

  case 58: /* identifier_list: IDENTIFIER COMMA IDENTIFIER  */
#line 279 "aft.y"
                                {

    }
#line 1885 "aft.tab.c"
    break;

  case 59: /* identifier_list: identifier_list COMMA IDENTIFIER  */
#line 282 "aft.y"
                                       {

    }
#line 1893 "aft.tab.c"
    break;

  case 60: /* assignment: IDENTIFIER ASSIGN expression  */
#line 288 "aft.y"
                                 {

    }
#line 1901 "aft.tab.c"
    break;

  case 61: /* assignment: LEFTPAREN identifier_list RIGHTPAREN ASSIGN LEFTPAREN expression_list RIGHTPAREN  */
#line 291 "aft.y"
                                                                                       {

    }
#line 1909 "aft.tab.c"
    break;

  case 62: /* if_stmt: IF expression statement_block  */
#line 297 "aft.y"
                                  {

    }
#line 1917 "aft.tab.c"
    break;

  case 63: /* if_stmt: IF expression statement_block ELSE statement_block  */
#line 300 "aft.y"
                                                         {

    }
#line 1925 "aft.tab.c"
    break;

  case 64: /* if_stmt: IF expression statement_block ELSE if_stmt  */
#line 303 "aft.y"
                                                 {

    }
#line 1933 "aft.tab.c"
    break;

  case 65: /* while_stmt: WHILE expression statement_block  */
#line 309 "aft.y"
                                     {

    }
#line 1941 "aft.tab.c"
    break;

  case 66: /* for_stmt: FOR IDENTIFIER IN expression statement_block  */
#line 315 "aft.y"
                                                 {

    }
#line 1949 "aft.tab.c"
    break;

  case 67: /* repeat_stmt: REPEAT expression statement_block  */
#line 321 "aft.y"
                                      {

    }
#line 1957 "aft.tab.c"
    break;

  case 68: /* return_stmt: RETURN expression_list  */
#line 327 "aft.y"
                           {

    }
#line 1965 "aft.tab.c"
    break;

  case 69: /* return_stmt: RETURN  */
#line 330 "aft.y"
             {

    }
#line 1973 "aft.tab.c"
    break;

  case 70: /* function_call: IDENTIFIER LEFTPAREN argument_list RIGHTPAREN  */
#line 336 "aft.y"
                                                  {}
#line 1979 "aft.tab.c"
    break;

  case 71: /* argument_list: expression_list  */
#line 340 "aft.y"
                    {}
#line 1985 "aft.tab.c"
    break;

  case 72: /* argument_list: %empty  */
#line 341 "aft.y"
                  {}
#line 1991 "aft.tab.c"
    break;

  case 73: /* unary_expression: PLUS expression  */
#line 345 "aft.y"
                                     {}
#line 1997 "aft.tab.c"
    break;

  case 74: /* unary_expression: MINUS expression  */
#line 346 "aft.y"
                                         {}
#line 2003 "aft.tab.c"
    break;

  case 75: /* unary_expression: REVERSE expression  */
#line 347 "aft.y"
                         {}
#line 2009 "aft.tab.c"
    break;

  case 79: /* expression: LEFTPAREN expression RIGHTPAREN  */
#line 353 "aft.y"
                                      {}
#line 2015 "aft.tab.c"
    break;

  case 81: /* expression: expression PLUS expression  */
#line 355 "aft.y"
                                 {}
#line 2021 "aft.tab.c"
    break;

  case 82: /* expression: expression MINUS expression  */
#line 356 "aft.y"
                                  {}
#line 2027 "aft.tab.c"
    break;

  case 83: /* expression: expression MULTIPLY expression  */
#line 357 "aft.y"
                                     {}
#line 2033 "aft.tab.c"
    break;

  case 84: /* expression: expression DIVIDE expression  */
#line 358 "aft.y"
                                   {}
#line 2039 "aft.tab.c"
    break;

  case 85: /* expression: expression MODULO expression  */
#line 359 "aft.y"
                                   {}
#line 2045 "aft.tab.c"
    break;

  case 86: /* expression: expression EXPONENTIATE expression  */
#line 360 "aft.y"
                                         {}
#line 2051 "aft.tab.c"
    break;

  case 87: /* expression: expression EQUALS expression  */
#line 361 "aft.y"
                                   {}
#line 2057 "aft.tab.c"
    break;

  case 88: /* expression: expression NOTEQUAL expression  */
#line 362 "aft.y"
                                     {}
#line 2063 "aft.tab.c"
    break;

  case 89: /* expression: expression LESSTHAN expression  */
#line 363 "aft.y"
                                     {}
#line 2069 "aft.tab.c"
    break;

  case 90: /* expression: expression GREATERTHAN expression  */
#line 364 "aft.y"
                                        {}
#line 2075 "aft.tab.c"
    break;

  case 91: /* expression: expression LESSTHANEQUAL expression  */
#line 365 "aft.y"
                                          {}
#line 2081 "aft.tab.c"
    break;

  case 92: /* expression: expression GREATERTHANEQUAL expression  */
#line 366 "aft.y"
                                             {}
#line 2087 "aft.tab.c"
    break;

  case 93: /* expression: expression AND expression  */
#line 367 "aft.y"
                                {}
#line 2093 "aft.tab.c"
    break;

  case 94: /* expression: expression OR expression  */
#line 368 "aft.y"
                               {}
#line 2099 "aft.tab.c"
    break;

  case 95: /* expression: expression XOR expression  */
#line 369 "aft.y"
                                {}
#line 2105 "aft.tab.c"
    break;

  case 96: /* expression: NOT expression  */
#line 370 "aft.y"
                     {}
#line 2111 "aft.tab.c"
    break;

  case 97: /* expression: expression BITWISEAND expression  */
#line 371 "aft.y"
                                       {}
#line 2117 "aft.tab.c"
    break;

  case 98: /* expression: expression BITWISEOR expression  */
#line 372 "aft.y"
                                      {}
#line 2123 "aft.tab.c"
    break;

  case 99: /* expression: expression LEFTSHIFT expression  */
#line 373 "aft.y"
                                      {}
#line 2129 "aft.tab.c"
    break;

  case 100: /* expression: expression RIGHTSHIFT expression  */
#line 374 "aft.y"
                                       {}
#line 2135 "aft.tab.c"
    break;

  case 101: /* expression: expression CONVOLUTION expression  */
#line 375 "aft.y"
                                        {}
#line 2141 "aft.tab.c"
    break;

  case 102: /* expression: expression LEFTSQUARE expression RIGHTSQUARE  */
#line 376 "aft.y"
                                                   {}
#line 2147 "aft.tab.c"
    break;

  case 105: /* expression_list: expression  */
#line 382 "aft.y"
               {

    }
#line 2155 "aft.tab.c"
    break;

  case 106: /* expression_list: expression_list COMMA expression  */
#line 385 "aft.y"
                                       {

    }
#line 2163 "aft.tab.c"
    break;

  case 107: /* literal: INTEGER  */
#line 391 "aft.y"
            {

    }
#line 2171 "aft.tab.c"
    break;

  case 108: /* literal: FLOAT  */
#line 394 "aft.y"
            {

    }
#line 2179 "aft.tab.c"
    break;

  case 109: /* literal: COMPLEX  */
#line 397 "aft.y"
              {

    }
#line 2187 "aft.tab.c"
    break;

  case 110: /* literal: TRUE  */
#line 400 "aft.y"
           {

    }
#line 2195 "aft.tab.c"
    break;

  case 111: /* literal: FALSE  */
#line 403 "aft.y"
            {

    }
#line 2203 "aft.tab.c"
    break;

  case 112: /* literal: PI  */
#line 406 "aft.y"
         {

    }
#line 2211 "aft.tab.c"
    break;

  case 113: /* literal: vector_literal  */
#line 409 "aft.y"
                     {

    }
#line 2219 "aft.tab.c"
    break;

  case 114: /* literal: STRING  */
#line 412 "aft.y"
             {}
#line 2225 "aft.tab.c"
    break;

  case 115: /* vector_literal: LEFTSQUARE vector_elements RIGHTSQUARE  */
#line 416 "aft.y"
                                           {}
#line 2231 "aft.tab.c"
    break;

  case 116: /* vector_literal: LEFTSQUARE RIGHTSQUARE  */
#line 417 "aft.y"
                             {}
#line 2237 "aft.tab.c"
    break;

  case 117: /* vector_elements: expression  */
#line 420 "aft.y"
               {

    }
#line 2245 "aft.tab.c"
    break;

  case 118: /* vector_elements: vector_elements COMMA expression  */
#line 423 "aft.y"
                                       {

    }
#line 2253 "aft.tab.c"
    break;

  case 119: /* range_expr: expression RANGE expression  */
#line 429 "aft.y"
                                {

    }
#line 2261 "aft.tab.c"
    break;

  case 120: /* range_expr: expression RANGEUPTO expression  */
#line 432 "aft.y"
                                      {

    }
#line 2269 "aft.tab.c"
    break;


#line 2273 "aft.tab.c"

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

#line 437 "aft.y"


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
