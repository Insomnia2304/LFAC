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
#line 1 "compiler.y"

#include <iostream>
#include "compiler.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);



#line 83 "compiler.tab.c"

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

#include "compiler.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RETURN = 3,                     /* RETURN  */
  YYSYMBOL_CLASS = 4,                      /* CLASS  */
  YYSYMBOL_CONST = 5,                      /* CONST  */
  YYSYMBOL_MAIN = 6,                       /* MAIN  */
  YYSYMBOL_EVAL = 7,                       /* EVAL  */
  YYSYMBOL_TYPEOF = 8,                     /* TYPEOF  */
  YYSYMBOL_TYPE = 9,                       /* TYPE  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_ID = 11,                        /* ID  */
  YYSYMBOL_ASSIGN = 12,                    /* ASSIGN  */
  YYSYMBOL_VAR_CHAR = 13,                  /* VAR_CHAR  */
  YYSYMBOL_VAR_STRING = 14,                /* VAR_STRING  */
  YYSYMBOL_VAR_INT = 15,                   /* VAR_INT  */
  YYSYMBOL_VAR_FLOAT = 16,                 /* VAR_FLOAT  */
  YYSYMBOL_VAR_BOOL = 17,                  /* VAR_BOOL  */
  YYSYMBOL_LESS = 18,                      /* LESS  */
  YYSYMBOL_GR = 19,                        /* GR  */
  YYSYMBOL_LEQ = 20,                       /* LEQ  */
  YYSYMBOL_GEQ = 21,                       /* GEQ  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_NEQ = 23,                       /* NEQ  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_DO = 30,                        /* DO  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '%'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_progr = 47,                     /* progr  */
  YYSYMBOL_SECTIONS = 48,                  /* SECTIONS  */
  YYSYMBOL_SECT1_USER_DEFINED_DATA = 49,   /* SECT1_USER_DEFINED_DATA  */
  YYSYMBOL_USER_DEFINED_TYPE = 50,         /* USER_DEFINED_TYPE  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_INSIDE_CLASS = 52,              /* INSIDE_CLASS  */
  YYSYMBOL_SECT2_GLOBAL_VARIABLES = 53,    /* SECT2_GLOBAL_VARIABLES  */
  YYSYMBOL_SECT3_GLOBAL_FUNCTIONS = 54,    /* SECT3_GLOBAL_FUNCTIONS  */
  YYSYMBOL_SECT4_MAIN = 55,                /* SECT4_MAIN  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_VAR_DECL = 57,                  /* VAR_DECL  */
  YYSYMBOL_FUNC_DECL = 58,                 /* FUNC_DECL  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_PARAM_LIST = 60,                /* PARAM_LIST  */
  YYSYMBOL_61_4 = 61,                      /* $@4  */
  YYSYMBOL_INSTR_LIST = 62,                /* INSTR_LIST  */
  YYSYMBOL_INSTR = 63,                     /* INSTR  */
  YYSYMBOL_LVALUE = 64,                    /* LVALUE  */
  YYSYMBOL_MULTIDIM = 65,                  /* MULTIDIM  */
  YYSYMBOL_EXPR = 66,                      /* EXPR  */
  YYSYMBOL_COND = 67,                      /* COND  */
  YYSYMBOL_if = 68,                        /* if  */
  YYSYMBOL_while = 69,                     /* while  */
  YYSYMBOL_do = 70,                        /* do  */
  YYSYMBOL_for = 71,                       /* for  */
  YYSYMBOL_ARGS_LIST = 72,                 /* ARGS_LIST  */
  YYSYMBOL_73_5 = 73                       /* $@5  */
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   814

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  225

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
       2,     2,     2,     2,     2,     2,     2,    36,     2,     2,
      40,    41,    34,    32,    44,    33,    45,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    49,    49,    50,    67,    68,    69,    70,    73,    76,
      76,    79,    80,    81,    84,    87,    90,    90,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   106,   106,   109,
     109,   110,   111,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   126,   127,   128,   129,   132,   133,   134,
     135,   146,   146,   147,   148,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   179,   183,   184,   187,   190,   193,   196,   196,   197,
     198
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
  "\"end of file\"", "error", "\"invalid token\"", "RETURN", "CLASS",
  "CONST", "MAIN", "EVAL", "TYPEOF", "TYPE", "VOID", "ID", "ASSIGN",
  "VAR_CHAR", "VAR_STRING", "VAR_INT", "VAR_FLOAT", "VAR_BOOL", "LESS",
  "GR", "LEQ", "GEQ", "EQ", "NEQ", "NOT", "AND", "OR", "IF", "ELSE", "FOR",
  "DO", "WHILE", "'+'", "'-'", "'*'", "'/'", "'%'", "'{'", "'}'", "';'",
  "'('", "')'", "'['", "']'", "','", "'.'", "$accept", "progr", "SECTIONS",
  "SECT1_USER_DEFINED_DATA", "USER_DEFINED_TYPE", "$@1", "INSIDE_CLASS",
  "SECT2_GLOBAL_VARIABLES", "SECT3_GLOBAL_FUNCTIONS", "SECT4_MAIN", "$@2",
  "VAR_DECL", "FUNC_DECL", "$@3", "PARAM_LIST", "$@4", "INSTR_LIST",
  "INSTR", "LVALUE", "MULTIDIM", "EXPR", "COND", "if", "while", "do",
  "for", "ARGS_LIST", "$@5", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-50)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      96,    -3,    67,    64,    62,    81,    16,    96,  -141,    96,
      96,  -141,    44,  -141,  -141,    76,  -141,    29,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,    51,    79,    54,    82,    82,
      63,    -2,    82,    85,    21,  -141,  -141,  -141,  -141,  -141,
      68,    82,   759,   413,     1,    93,    89,    90,    -2,   759,
      94,    82,    82,   122,    82,   641,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    95,
     134,    98,   106,   109,    -2,  -141,  -141,   393,   111,   432,
      14,   665,  -141,   192,   192,   192,   192,   660,   660,   356,
     778,   128,   128,  -141,  -141,  -141,    82,    38,   115,   113,
    -141,  -141,   127,  -141,  -141,  -141,    82,    82,  -141,   451,
       1,  -141,    82,   121,   129,    32,   130,   132,   118,   133,
    -141,   135,   137,   156,   170,   759,  -141,  -141,  -141,  -141,
      82,   143,   470,   148,  -141,   172,   737,    82,    82,    82,
     180,    82,   370,  -141,    82,  -141,  -141,    82,   382,  -141,
    -141,  -141,    82,  -141,  -141,   689,   713,   489,    50,   759,
     152,     7,   155,   206,   154,   759,    83,  -141,   759,   508,
     158,   159,    15,   163,    82,   173,   168,    82,   164,  -141,
    -141,    82,   196,  -141,   169,   176,  -141,   527,    82,   546,
      22,  -141,   240,   370,    82,   274,   187,   565,   189,    82,
     207,   204,   193,   197,  -141,  -141,    82,   584,  -141,   202,
     203,   211,   603,   213,  -141,  -141,  -141,   199,   308,   342,
      82,  -141,  -141,   622,  -141
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       0,     7,     0,    15,     9,     0,    16,    18,    23,     1,
       3,     4,     5,     6,    14,     0,    19,     0,     0,     0,
       0,    13,     0,     0,    76,    64,    65,    61,    62,    63,
       0,     0,    20,     0,    32,     0,     0,     0,    13,    21,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,    29,     0,     0,    13,    12,    33,    89,     0,     0,
      79,     0,    60,    68,    69,    70,    71,    72,    73,    66,
      67,    55,    56,    57,    58,    59,     0,    18,     0,     0,
      10,    11,    51,    87,    75,    77,    90,     0,    74,     0,
      32,    33,     0,     0,     0,    76,     0,     0,     0,     0,
      17,     0,     0,     0,     0,    46,    36,    37,    38,    39,
      90,     0,     0,    24,    30,    51,     0,     0,     0,     0,
       0,     0,    51,    33,     0,    34,    35,     0,    51,    88,
      78,    80,     0,    28,    40,     0,     0,     0,    79,    81,
       0,    76,     0,    51,     0,    43,    76,    44,    45,     0,
       0,     0,    77,     0,     0,     0,     0,     0,    25,    41,
      42,     0,     0,    33,     0,     0,    33,     0,     0,     0,
      47,    50,    51,    51,     0,    51,    77,     0,    52,     0,
       0,    82,     0,     0,    84,    26,     0,     0,    49,     0,
       0,     0,     0,    48,    33,    33,    85,    53,    51,    51,
       0,    83,    86,     0,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,   105,  -141,  -141,  -141,   -23,  -141,  -141,  -141,
    -141,    11,   -26,  -141,   142,  -141,   -97,  -140,    60,   112,
     -28,  -129,  -141,  -141,  -141,  -141,   -48,  -141
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    25,    46,     9,    10,    11,
      27,   121,    13,    30,    72,    98,   102,   122,   123,   124,
     125,   160,   126,   127,   128,   129,    78,   130
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    43,   162,     2,    49,    48,     2,    45,    14,     4,
      70,    12,     4,    55,   135,   164,    -2,    20,    12,   -47,
      12,    12,    48,    77,    79,    75,    81,   -48,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    28,    47,    18,   -47,   184,   163,    51,    48,   139,
      28,   101,   140,   202,   106,    71,   107,   181,   131,    47,
     182,    51,   -49,    52,   199,   203,    53,   200,   109,   -27,
      16,    29,    51,    18,   139,    17,    15,   140,    77,   132,
      29,    19,   149,    24,   136,    47,   192,    26,    31,   195,
     106,    32,   107,    34,    33,    35,    36,    37,    38,    39,
       1,     2,    77,    44,    17,     3,    40,     4,    54,   155,
     156,   157,    21,   159,    22,    23,   159,   218,   219,   165,
     168,    71,    41,    51,   169,   177,    50,    73,    53,    74,
     112,    76,     2,    80,   113,   114,    70,    96,   115,   -31,
      35,    36,    37,    38,    39,    97,   159,    99,   100,   187,
     111,    40,   104,   189,   116,   143,   117,   118,   119,   110,
     197,   137,    66,    67,    68,   120,   159,    41,   147,   138,
     141,   207,   142,   144,   145,   112,   146,     2,   212,   113,
     114,    70,   148,   115,   150,    35,    36,    37,    38,    39,
     152,   158,   223,   173,   174,   176,    40,   179,   180,   116,
     183,   117,   118,   119,   185,   186,   188,   190,   193,   112,
     153,     2,    41,   113,   114,    70,   194,   115,   208,    35,
      36,    37,    38,    39,    64,    65,    66,    67,    68,   181,
      40,   206,   209,   116,   210,   117,   118,   119,   211,   214,
     215,   220,   191,   112,   175,     2,    41,   113,   114,    70,
     216,   115,   134,    35,    36,    37,    38,    39,   182,     0,
     167,     0,     0,     0,    40,     0,     0,   116,     0,   117,
     118,   119,     0,     0,     0,     0,     0,   112,   201,     2,
      41,   113,   114,    70,     0,   115,     0,    35,    36,    37,
      38,    39,     0,     0,     0,     0,     0,     0,    40,     0,
       0,   116,     0,   117,   118,   119,     0,     0,     0,     0,
       0,   112,   204,     2,    41,   113,   114,    70,     0,   115,
       0,    35,    36,    37,    38,    39,     0,     0,     0,     0,
       0,     0,    40,     0,     0,   116,     0,   117,   118,   119,
       0,     0,     0,     0,     0,   112,   221,     2,    41,   113,
     114,    70,     0,   115,     0,    35,    36,    37,    38,    39,
       0,     0,     0,     0,     0,     0,    40,     0,     0,   116,
       0,   117,   118,   119,    56,    57,    58,    59,    60,    61,
     222,   161,    41,    35,    36,    37,    38,    39,    64,    65,
      66,    67,    68,   166,    40,    35,    36,    37,    38,    39,
       0,     0,     0,     0,     0,     0,    40,     0,     0,     0,
      41,    56,    57,    58,    59,    60,    61,     0,    62,    63,
       0,     0,    41,     0,     0,    64,    65,    66,    67,    68,
       0,    56,    57,    58,    59,    60,    61,   103,    62,    63,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      56,    57,    58,    59,    60,    61,    69,    62,    63,     0,
       0,     0,     0,     0,    64,    65,    66,    67,    68,    56,
      57,    58,    59,    60,    61,   105,    62,    63,     0,     0,
       0,     0,     0,    64,    65,    66,    67,    68,    56,    57,
      58,    59,    60,    61,   133,    62,    63,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    56,    57,    58,
      59,    60,    61,   151,    62,    63,     0,     0,     0,     0,
       0,    64,    65,    66,    67,    68,    56,    57,    58,    59,
      60,    61,   172,    62,    63,     0,     0,     0,     0,     0,
      64,    65,    66,    67,    68,    56,    57,    58,    59,    60,
      61,   178,    62,    63,     0,     0,     0,     0,     0,    64,
      65,    66,    67,    68,    56,    57,    58,    59,    60,    61,
     196,    62,    63,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    56,    57,    58,    59,    60,    61,   198,
      62,    63,     0,     0,     0,     0,     0,    64,    65,    66,
      67,    68,    56,    57,    58,    59,    60,    61,   205,    62,
      63,     0,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    56,    57,    58,    59,    60,    61,   213,    62,    63,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      56,    57,    58,    59,    60,    61,   217,    62,    63,     0,
       0,     0,     0,     0,    64,    65,    66,    67,    68,    56,
      57,    58,    59,    60,    61,   224,    62,    63,     0,     0,
       0,     0,     0,    64,    65,    66,    67,    68,    56,    57,
      58,    59,    82,    56,    57,    58,    59,    60,    61,     0,
      62,    63,    64,    65,    66,    67,    68,    64,    65,    66,
      67,    68,     0,     0,     0,     0,   108,    56,    57,    58,
      59,    60,    61,     0,    62,    63,     0,     0,     0,     0,
       0,    64,    65,    66,    67,    68,     0,     0,     0,     0,
     170,    56,    57,    58,    59,    60,    61,     0,    62,    63,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
       0,     0,     0,     0,   171,    56,    57,    58,    59,    60,
      61,     0,    62,    63,     0,     0,     0,     0,     0,    64,
      65,    66,    67,    68,     0,     0,   154,    56,    57,    58,
      59,    60,    61,     0,    62,    63,     0,     0,     0,     0,
       0,    64,    65,    66,    67,    68,    56,    57,    58,    59,
      60,    61,     0,    62,     0,     0,     0,     0,     0,     0,
      64,    65,    66,    67,    68
};

static const yytype_int16 yycheck[] =
{
      28,    29,   142,     5,    32,    31,     5,     9,    11,    11,
       9,     0,    11,    41,   111,   144,     0,     1,     7,    12,
       9,    10,    48,    51,    52,    48,    54,    12,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    12,    31,    11,    12,   174,   143,    40,    74,    42,
      12,    74,    45,   193,    40,    44,    42,    42,   106,    48,
      45,    40,    12,    42,    42,   194,    45,    45,    96,    40,
       6,    42,    40,    11,    42,    11,     9,    45,   106,   107,
      42,     0,   130,    39,   112,    74,   183,    11,    37,   186,
      40,    12,    42,    11,    40,    13,    14,    15,    16,    17,
       4,     5,   130,    40,    11,     9,    24,    11,    40,   137,
     138,   139,     7,   141,     9,    10,   144,   214,   215,   147,
     148,   110,    40,    40,   152,    42,    41,    38,    45,    39,
       3,    37,     5,    11,     7,     8,     9,    42,    11,    41,
      13,    14,    15,    16,    17,    11,   174,    41,    39,   177,
      37,    24,    41,   181,    27,    37,    29,    30,    31,    44,
     188,    40,    34,    35,    36,    38,   194,    40,    12,    40,
      40,   199,    40,    40,    39,     3,    39,     5,   206,     7,
       8,     9,    12,    11,    41,    13,    14,    15,    16,    17,
      42,    11,   220,    41,    39,    41,    24,    39,    39,    27,
      37,    29,    30,    31,    31,    37,    42,    11,    39,     3,
      38,     5,    40,     7,     8,     9,    40,    11,    11,    13,
      14,    15,    16,    17,    32,    33,    34,    35,    36,    42,
      24,    42,    28,    27,    41,    29,    30,    31,    41,    37,
      37,    42,   182,     3,    38,     5,    40,     7,     8,     9,
      39,    11,   110,    13,    14,    15,    16,    17,    45,    -1,
     148,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,     3,    38,     5,
      40,     7,     8,     9,    -1,    11,    -1,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    27,    -1,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,     3,    38,     5,    40,     7,     8,     9,    -1,    11,
      -1,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    27,    -1,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,     3,    38,     5,    40,     7,
       8,     9,    -1,    11,    -1,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    27,
      -1,    29,    30,    31,    18,    19,    20,    21,    22,    23,
      38,    11,    40,    13,    14,    15,    16,    17,    32,    33,
      34,    35,    36,    11,    24,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      40,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      -1,    -1,    40,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    18,    19,    20,    21,    22,    23,    44,    25,    26,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      18,    19,    20,    21,    22,    23,    43,    25,    26,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    18,
      19,    20,    21,    22,    23,    43,    25,    26,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    18,    19,
      20,    21,    22,    23,    43,    25,    26,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    18,    19,    20,
      21,    22,    23,    43,    25,    26,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    18,    19,    20,    21,
      22,    23,    43,    25,    26,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    18,    19,    20,    21,    22,
      23,    43,    25,    26,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    18,    19,    20,    21,    22,    23,
      43,    25,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    18,    19,    20,    21,    22,    23,    43,
      25,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    18,    19,    20,    21,    22,    23,    43,    25,
      26,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    18,    19,    20,    21,    22,    23,    43,    25,    26,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      18,    19,    20,    21,    22,    23,    43,    25,    26,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    18,
      19,    20,    21,    22,    23,    43,    25,    26,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    18,    19,
      20,    21,    41,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    32,    33,    34,    35,    36,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    41,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      41,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    39,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    18,    19,    20,    21,
      22,    23,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     9,    11,    47,    48,    49,    50,    53,
      54,    55,    57,    58,    11,     9,     6,    11,    11,     0,
       1,    48,    48,    48,    39,    51,    11,    56,    12,    42,
      59,    37,    12,    40,    11,    13,    14,    15,    16,    17,
      24,    40,    66,    66,    40,     9,    52,    57,    58,    66,
      41,    40,    42,    45,    40,    66,    18,    19,    20,    21,
      22,    23,    25,    26,    32,    33,    34,    35,    36,    43,
       9,    57,    60,    38,    39,    52,    37,    66,    72,    66,
      11,    66,    41,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    42,    11,    61,    41,
      39,    52,    62,    44,    41,    43,    40,    42,    41,    66,
      44,    37,     3,     7,     8,    11,    27,    29,    30,    31,
      38,    57,    63,    64,    65,    66,    68,    69,    70,    71,
      73,    72,    66,    43,    60,    62,    66,    40,    40,    42,
      45,    40,    40,    37,    40,    39,    39,    12,    12,    72,
      41,    43,    42,    38,    39,    66,    66,    66,    11,    66,
      67,    11,    63,    62,    67,    66,    11,    65,    66,    66,
      41,    41,    43,    41,    39,    38,    41,    42,    43,    39,
      39,    42,    45,    37,    67,    31,    37,    66,    42,    66,
      11,    64,    62,    39,    40,    62,    43,    66,    43,    42,
      45,    38,    63,    67,    38,    43,    42,    66,    11,    28,
      41,    41,    66,    43,    37,    37,    39,    43,    62,    62,
      42,    38,    38,    66,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    49,    51,
      50,    52,    52,    52,    53,    54,    56,    55,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    59,    58,    61,
      60,    60,    60,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    68,    68,    69,    70,    71,    73,    72,    72,
      72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     1,     1,     0,
       7,     3,     2,     0,     2,     1,     0,     8,     2,     3,
       4,     5,     5,     2,     8,    11,    14,     0,     9,     0,
       4,     1,     0,     0,     3,     3,     2,     2,     2,     2,
       4,     6,     6,     3,     3,     3,     1,     1,     4,     3,
       6,     0,     7,    10,    13,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     4,     1,     4,     6,     3,
       6,     1,     7,    11,     7,     9,    11,     0,     4,     1,
       0
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
  case 2: /* progr: SECTIONS  */
#line 49 "compiler.y"
                 { printf("The program is correct!\n"); }
#line 1400 "compiler.tab.c"
    break;

  case 3: /* progr: SECTIONS error  */
#line 50 "compiler.y"
                     { printf("Unexpected text after end of program!\n"); }
#line 1406 "compiler.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 76 "compiler.y"
                              { strcpy(domain,(yyvsp[0].string)); addClass((yyvsp[0].string),yylineno); strcpy(functionDomain,(yyvsp[0].string));}
#line 1412 "compiler.tab.c"
    break;

  case 10: /* USER_DEFINED_TYPE: CLASS ID $@1 '{' INSIDE_CLASS '}' ';'  */
#line 76 "compiler.y"
                                                                                                                                { strcpy(domain,"global"); strcpy(functionDomain,"global");}
#line 1418 "compiler.tab.c"
    break;

  case 16: /* $@2: %empty  */
#line 90 "compiler.y"
                       { strcpy(domain,"main"); }
#line 1424 "compiler.tab.c"
    break;

  case 18: /* VAR_DECL: TYPE ID  */
#line 93 "compiler.y"
                   {  AST* aux=buildTree(strcmp((yyvsp[-1].string),"bool")==0? "false": "0",convertStringToEnum((yyvsp[-1].string)),NULL,NULL,yylineno); addVar((yyvsp[-1].string), (yyvsp[0].string), evaluateTree(aux,yylineno),domain, 0, yylineno); }
#line 1430 "compiler.tab.c"
    break;

  case 19: /* VAR_DECL: CONST TYPE ID  */
#line 94 "compiler.y"
                    { AST* aux=buildTree(strcmp((yyvsp[-1].string),"bool")==0? "false": "0",convertStringToEnum((yyvsp[-1].string)),NULL,NULL,yylineno); addVar((yyvsp[-1].string), (yyvsp[0].string), evaluateTree(aux,yylineno),domain, 1, yylineno); }
#line 1436 "compiler.tab.c"
    break;

  case 20: /* VAR_DECL: TYPE ID ASSIGN EXPR  */
#line 95 "compiler.y"
                          { addVar((yyvsp[-3].string),(yyvsp[-2].string),evaluateTree((yyvsp[0].tree),yylineno),domain,0,yylineno); }
#line 1442 "compiler.tab.c"
    break;

  case 21: /* VAR_DECL: CONST TYPE ID ASSIGN EXPR  */
#line 96 "compiler.y"
                                { addVar((yyvsp[-3].string),(yyvsp[-2].string),evaluateTree((yyvsp[0].tree),yylineno),domain,1,yylineno); }
#line 1448 "compiler.tab.c"
    break;

  case 22: /* VAR_DECL: TYPE ID '[' EXPR ']'  */
#line 97 "compiler.y"
                            { int size=checkSize(evaluateTree((yyvsp[-1].tree),yylineno),yylineno); addArray((yyvsp[-4].string),(yyvsp[-3].string),size,domain,0,yylineno);}
#line 1454 "compiler.tab.c"
    break;

  case 23: /* VAR_DECL: ID ID  */
#line 98 "compiler.y"
              { checkClass((yyvsp[-1].string),yylineno); AST* aux=buildTree("0",OTHER,NULL,NULL,yylineno); addVar((yyvsp[-1].string), (yyvsp[0].string), evaluateTree(aux,yylineno),domain, 0, yylineno);}
#line 1460 "compiler.tab.c"
    break;

  case 27: /* $@3: %empty  */
#line 106 "compiler.y"
                    {strcpy(domain,(yyvsp[0].string));}
#line 1466 "compiler.tab.c"
    break;

  case 28: /* FUNC_DECL: TYPE ID $@3 '(' PARAM_LIST ')' '{' INSTR_LIST '}'  */
#line 106 "compiler.y"
                                                                                { addFunction((yyvsp[-8].string),(yyvsp[-7].string),functionDomain,yylineno); strcpy(domain,"global"); }
#line 1472 "compiler.tab.c"
    break;

  case 29: /* $@4: %empty  */
#line 109 "compiler.y"
                      { addParameter(); }
#line 1478 "compiler.tab.c"
    break;

  case 31: /* PARAM_LIST: VAR_DECL  */
#line 110 "compiler.y"
               { addParameter(); }
#line 1484 "compiler.tab.c"
    break;

  case 41: /* INSTR_LIST: INSTR_LIST EVAL '(' EXPR ')' ';'  */
#line 122 "compiler.y"
                                       { Eval(evaluateTree((yyvsp[-2].tree),yylineno),yylineno); }
#line 1490 "compiler.tab.c"
    break;

  case 42: /* INSTR_LIST: INSTR_LIST TYPEOF '(' EXPR ')' ';'  */
#line 123 "compiler.y"
                                         { TypeOf(evaluateTree((yyvsp[-2].tree),yylineno),yylineno); }
#line 1496 "compiler.tab.c"
    break;

  case 43: /* INSTR: LVALUE ASSIGN EXPR  */
#line 126 "compiler.y"
                           { updateVarValue(lvalue,evaluateTree((yyvsp[0].tree),yylineno),yylineno); }
#line 1502 "compiler.tab.c"
    break;

  case 47: /* LVALUE: ID  */
#line 132 "compiler.y"
            { strcpy(lvalue,(yyvsp[0].string)); }
#line 1508 "compiler.tab.c"
    break;

  case 48: /* LVALUE: ID '[' EXPR ']'  */
#line 133 "compiler.y"
                      { strcpy(lvalue,(yyvsp[-3].string)); strcat(strcat(strcat(lvalue,"["),evaluateTree((yyvsp[-1].tree),yylineno).resultStr),"]");}
#line 1514 "compiler.tab.c"
    break;

  case 55: /* EXPR: EXPR '+' EXPR  */
#line 151 "compiler.y"
                     { (yyval.tree)=buildTree("+", OPERATOR, (yyvsp[-2].tree), (yyvsp[0].tree),yylineno); }
#line 1520 "compiler.tab.c"
    break;

  case 56: /* EXPR: EXPR '-' EXPR  */
#line 152 "compiler.y"
                    { (yyval.tree)=buildTree("-", OPERATOR, (yyvsp[-2].tree), (yyvsp[0].tree),yylineno); }
#line 1526 "compiler.tab.c"
    break;

  case 57: /* EXPR: EXPR '*' EXPR  */
#line 153 "compiler.y"
                    { (yyval.tree)=buildTree("*", OPERATOR, (yyvsp[-2].tree), (yyvsp[0].tree),yylineno); }
#line 1532 "compiler.tab.c"
    break;

  case 58: /* EXPR: EXPR '/' EXPR  */
#line 154 "compiler.y"
                    { (yyval.tree)=buildTree("/", OPERATOR, (yyvsp[-2].tree), (yyvsp[0].tree),yylineno); }
#line 1538 "compiler.tab.c"
    break;

  case 59: /* EXPR: EXPR '%' EXPR  */
#line 155 "compiler.y"
                    { (yyval.tree)=buildTree("%", OPERATOR, (yyvsp[-2].tree), (yyvsp[0].tree),yylineno); }
#line 1544 "compiler.tab.c"
    break;

  case 60: /* EXPR: '(' EXPR ')'  */
#line 156 "compiler.y"
                   { (yyval.tree)=(yyvsp[-1].tree); }
#line 1550 "compiler.tab.c"
    break;

  case 61: /* EXPR: VAR_INT  */
#line 157 "compiler.y"
              { (yyval.tree)=buildTree(itoaCustom((yyvsp[0].int_val)), NUMBER_INT, NULL, NULL,yylineno); }
#line 1556 "compiler.tab.c"
    break;

  case 62: /* EXPR: VAR_FLOAT  */
#line 158 "compiler.y"
                { (yyval.tree)=buildTree(ftoaCustom((yyvsp[0].float_val)), NUMBER_FLOAT, NULL, NULL,yylineno); }
#line 1562 "compiler.tab.c"
    break;

  case 63: /* EXPR: VAR_BOOL  */
#line 159 "compiler.y"
               { (yyval.tree)=buildTree((yyvsp[0].string), NUMBER_BOOL, NULL, NULL,yylineno); }
#line 1568 "compiler.tab.c"
    break;

  case 64: /* EXPR: VAR_CHAR  */
#line 160 "compiler.y"
               {  (yyval.tree)=buildTree((yyvsp[0].string), CHAR, NULL, NULL,yylineno); }
#line 1574 "compiler.tab.c"
    break;

  case 65: /* EXPR: VAR_STRING  */
#line 161 "compiler.y"
                 { (yyval.tree)=buildTree((yyvsp[0].string), STRING, NULL, NULL,yylineno); }
#line 1580 "compiler.tab.c"
    break;

  case 66: /* EXPR: EXPR AND EXPR  */
#line 162 "compiler.y"
                    { (yyval.tree)=buildTree("&&",NUMBER_BOOL,(yyvsp[-2].tree),(yyvsp[0].tree),yylineno); }
#line 1586 "compiler.tab.c"
    break;

  case 67: /* EXPR: EXPR OR EXPR  */
#line 163 "compiler.y"
                   { (yyval.tree)=buildTree("||",NUMBER_BOOL,(yyvsp[-2].tree),(yyvsp[0].tree),yylineno); }
#line 1592 "compiler.tab.c"
    break;

  case 68: /* EXPR: EXPR LESS EXPR  */
#line 164 "compiler.y"
                     { (yyval.tree)=buildTree("<",NUMBER_BOOL,(yyvsp[-2].tree),(yyvsp[0].tree),yylineno); }
#line 1598 "compiler.tab.c"
    break;

  case 69: /* EXPR: EXPR GR EXPR  */
#line 165 "compiler.y"
                   { (yyval.tree)=buildTree(">",NUMBER_BOOL,(yyvsp[-2].tree),(yyvsp[0].tree),yylineno); }
#line 1604 "compiler.tab.c"
    break;

  case 70: /* EXPR: EXPR LEQ EXPR  */
#line 166 "compiler.y"
                    { (yyval.tree)=buildTree("<=",NUMBER_BOOL,(yyvsp[-2].tree),(yyvsp[0].tree),yylineno); }
#line 1610 "compiler.tab.c"
    break;

  case 71: /* EXPR: EXPR GEQ EXPR  */
#line 167 "compiler.y"
                    { (yyval.tree)=buildTree(">=",NUMBER_BOOL,(yyvsp[-2].tree),(yyvsp[0].tree),yylineno); }
#line 1616 "compiler.tab.c"
    break;

  case 72: /* EXPR: EXPR EQ EXPR  */
#line 168 "compiler.y"
                   { (yyval.tree)=buildTree("==",NUMBER_BOOL,(yyvsp[-2].tree),(yyvsp[0].tree),yylineno); }
#line 1622 "compiler.tab.c"
    break;

  case 73: /* EXPR: EXPR NEQ EXPR  */
#line 169 "compiler.y"
                    { (yyval.tree)=buildTree("!=",NUMBER_BOOL,(yyvsp[-2].tree),(yyvsp[0].tree),yylineno); }
#line 1628 "compiler.tab.c"
    break;

  case 74: /* EXPR: NOT '(' EXPR ')'  */
#line 170 "compiler.y"
                       { (yyval.tree)=buildTree("!",NUMBER_BOOL,(yyvsp[-1].tree),NULL,yylineno);}
#line 1634 "compiler.tab.c"
    break;

  case 75: /* EXPR: ID '(' ARGS_LIST ')'  */
#line 171 "compiler.y"
                            { compareParamWithArgs((yyvsp[-3].string),args,"global",yylineno); (yyval.tree)=buildTree((yyvsp[-3].string),convertStringToEnum(getFuncType((yyvsp[-3].string))),NULL,NULL,yylineno);}
#line 1640 "compiler.tab.c"
    break;

  case 76: /* EXPR: ID  */
#line 172 "compiler.y"
         { (yyval.tree)=buildTree((yyvsp[0].string),IDENTIFIER, NULL,NULL,yylineno); }
#line 1646 "compiler.tab.c"
    break;

  case 77: /* EXPR: ID '[' EXPR ']'  */
#line 173 "compiler.y"
                      { char rvalue[1024]; strcpy(rvalue,(yyvsp[-3].string)); strcat(strcat(strcat(rvalue,"["),evaluateTree((yyvsp[-1].tree),yylineno).resultStr),"]"); (yyval.tree)=buildTree(rvalue,IDENTIFIER,NULL,NULL,yylineno);}
#line 1652 "compiler.tab.c"
    break;

  case 78: /* EXPR: ID '.' ID '(' ARGS_LIST ')'  */
#line 174 "compiler.y"
                                  { compareParamWithArgs((yyvsp[-3].string),args,getTypeOfObject((yyvsp[-5].string),yylineno),yylineno); isMemberInClass((yyvsp[-5].string),(yyvsp[-3].string),yylineno); (yyval.tree)=buildTree((yyvsp[-5].string),OTHER,NULL,NULL,yylineno);}
#line 1658 "compiler.tab.c"
    break;

  case 79: /* EXPR: ID '.' ID  */
#line 175 "compiler.y"
                {  isIdInClass((yyvsp[-2].string),(yyvsp[0].string),yylineno); (yyval.tree)=buildTree("0",OTHER,NULL,NULL,yylineno);}
#line 1664 "compiler.tab.c"
    break;

  case 80: /* EXPR: ID '.' ID '[' EXPR ']'  */
#line 176 "compiler.y"
                             { }
#line 1670 "compiler.tab.c"
    break;

  case 87: /* $@5: %empty  */
#line 196 "compiler.y"
                     { strcat(strcat(args, convertEnumToString(evaluateTree((yyvsp[-1].tree),yylineno).treeType)),", "); }
#line 1676 "compiler.tab.c"
    break;

  case 89: /* ARGS_LIST: EXPR  */
#line 197 "compiler.y"
           { strcat(args, convertEnumToString(evaluateTree((yyvsp[0].tree),yylineno).treeType)); }
#line 1682 "compiler.tab.c"
    break;

  case 90: /* ARGS_LIST: %empty  */
#line 198 "compiler.y"
                    { strcat(args,"-"); }
#line 1688 "compiler.tab.c"
    break;


#line 1692 "compiler.tab.c"

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

#line 204 "compiler.y"


void yyerror(const char * s) {
    printf("{error} %s at line: %d :(\n", s, yylineno);
}

int main(int argc, char **argv) {
    FILE *fvar, *ffunc;
    fvar = fopen("variables.txt", "w");
    ffunc= fopen("functions.txt", "w");
    yyin = fopen(argv[1], "r");
    yyparse();
    //print();
    printVar(fvar);
    printFunc(ffunc);
    fclose(fvar);
    fclose(ffunc);
}
