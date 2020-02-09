/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "EzCompiler.yacc" /* yacc.c:339  */

#include "lex.yy.c"
#include "SymbolTable.h"
#include "CodeContainer.h"
#include "FillBack.h"
#include "fstream"
static SymbolTable::SymbolTable* symbolTable;
static FillBack * fillBack;
static CodeContainer *codeContainer;
static int offset,preSize;
static bool createDomainTable;
void yyerror(char const *){
CodeContainer::codeContainer->Clear();
}

#line 82 "EzCompiler.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "EzCompiler.h".  */
#ifndef YY_YY_EZCOMPILER_H_INCLUDED
# define YY_YY_EZCOMPILER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    S_LBRACE = 258,
    S_RBRACE = 259,
    S_LPAREN = 260,
    S_RPAREN = 261,
    S_SEM = 262,
    S_POINT = 263,
    S_DCOLON = 264,
    S_COM = 265,
    S_ADD = 266,
    S_SUB = 267,
    S_MUL = 268,
    S_DIV = 269,
    S_AND = 270,
    S_OR = 271,
    S_XOR = 272,
    S_NOT = 273,
    S_ASSIGN = 274,
    S_MOD = 275,
    S_LEQ = 276,
    S_LLT = 277,
    S_LGT = 278,
    S_LNE = 279,
    S_LLE = 280,
    S_LGE = 281,
    S_LNOT = 282,
    S_LAND = 283,
    S_LOR = 284,
    V_INT = 285,
    V_DOUBLE = 286,
    V_CHAR = 287,
    K_TRUE = 288,
    K_FALSE = 289,
    V_STRING = 290,
    V_ID = 291,
    K_CLASS = 292,
    K_DEF = 293,
    K_CONTINUE = 294,
    K_BREAK = 295,
    K_RETURN = 296,
    K_IF = 297,
    K_WHILE = 298,
    K_ELSE = 299,
    K_INT = 300,
    K_DOUBLE = 301,
    K_BOOL = 302,
    K_CHAR = 303,
    K_STRING = 304,
    K_NEW = 305,
    NEGATIVE = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{

  /* exp  */
  ExpInfo exp;
  /* formal_args  */
  ExpInfoArray formal_args;
  /* exps  */
  ExpInfoArray exps;
  /* V_STRING  */
  String V_STRING;
  /* V_ID  */
  String V_ID;
  /* val_type  */
  String val_type;
  /* id_list  */
  StringArray id_list;
  /* informal_args  */
  StringArray informal_args;
  /* val_types  */
  StringArray val_types;
  /* K_TRUE  */
  bool K_TRUE;
  /* K_FALSE  */
  bool K_FALSE;
  /* V_CHAR  */
  char V_CHAR;
  /* V_DOUBLE  */
  double V_DOUBLE;
  /* V_INT  */
  int V_INT;
#line 203 "EzCompiler.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EZCOMPILER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 220 "EzCompiler.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   359

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    66,    72,    71,    86,    88,    94,    93,
     126,   133,   139,   143,   147,   151,   155,   159,   165,   167,
     178,   173,   235,   239,   244,   252,   264,   266,   268,   270,
     275,   281,   356,   274,   388,   394,   466,   478,   488,   387,
     502,   517,   532,   532,   656,   656,   678,   678,   692,   694,
     697,   702,   702,   713,   903,   902,  1165,  1164,  1254,  2009,
    2765,  3521,  4277,  5066,  5854,  6675,  7499,  7503,  8031,  8559,
    9087,  9615,  9985, 10357, 10728, 11098, 11213, 11316, 11322, 11331,
   11340, 11349, 11358, 11367, 11376, 11385, 11389, 11394, 11399
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "S_LBRACE", "S_RBRACE", "S_LPAREN",
  "S_RPAREN", "S_SEM", "S_POINT", "S_DCOLON", "S_COM", "S_ADD", "S_SUB",
  "S_MUL", "S_DIV", "S_AND", "S_OR", "S_XOR", "S_NOT", "S_ASSIGN", "S_MOD",
  "S_LEQ", "S_LLT", "S_LGT", "S_LNE", "S_LLE", "S_LGE", "S_LNOT", "S_LAND",
  "S_LOR", "V_INT", "V_DOUBLE", "V_CHAR", "K_TRUE", "K_FALSE", "V_STRING",
  "V_ID", "K_CLASS", "K_DEF", "K_CONTINUE", "K_BREAK", "K_RETURN", "K_IF",
  "K_WHILE", "K_ELSE", "K_INT", "K_DOUBLE", "K_BOOL", "K_CHAR", "K_STRING",
  "K_NEW", "NEGATIVE", "$accept", "program", "class", "$@1", "dec_vars",
  "dec_var", "$@2", "id_list", "val_type", "dec_funs", "dec_fun", "$@3",
  "informal_args", "val_types", "stat", "ctrl_stat", "$@4", "$@5", "$@6",
  "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "cmpd_stat", "$@14",
  "stats_decs", "exp", "$@15", "$@16", "$@17", "formal_args", "exps", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF -60

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define YYTABLE_NINF -45

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -60,    18,   -60,   -31,   -60,   -60,     5,   -60,   -19,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -27,    19,   -60,     6,
     -60,   -19,   -60,   -21,    26,    -2,   -60,   -60,    31,   -19,
       1,    52,    51,   -60,   -60,   -19,    63,    32,   -60,   -60,
     -60,   -60,    60,   -60,   141,   -60,   141,   141,   141,   -60,
     -60,   -60,   -60,   -60,   -60,    -4,    64,    70,    74,    78,
      79,   -60,   -60,   -60,   -60,   -60,   196,    81,   173,    61,
      61,    61,   -60,   -60,   -60,   141,    82,   -60,   -60,   141,
     -60,   -60,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   -60,
     141,   219,   -60,   141,   141,   -60,   141,   104,   104,    61,
      61,   333,   295,   314,   238,    61,    -1,    62,    62,    -1,
      62,    62,   276,   257,   238,    91,    88,   -60,   238,   238,
     -60,   -60,   141,    98,   110,   238,   -60,   -60,   108,   108,
     -60,   -60,    75,   -60,   108,   -60
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     3,     4,     0,     6,    18,    17,
      13,    12,    15,    14,    16,     7,     0,     0,    11,     8,
       5,     0,    19,     0,     0,     0,    10,     9,     0,    22,
       0,     0,    23,    24,    20,     0,     0,     0,    46,    21,
      25,    48,     0,    47,     0,    26,     0,     0,     0,    78,
      79,    81,    82,    83,    80,    84,     0,     0,    42,     0,
       0,    51,    50,    49,    28,    29,     0,    84,     0,    75,
      76,    66,    54,    41,    40,     0,     0,    34,    30,     0,
      27,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      85,     0,    45,     0,     0,    52,     0,    67,    68,    69,
      70,    73,    72,    71,    53,    74,    63,    58,    60,    62,
      59,    61,    64,    65,    87,     0,    86,    43,    35,    31,
      57,    55,     0,     0,     0,    88,    36,    32,     0,     0,
      37,    33,     0,    38,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,   -60,   -60,    72,   -60,   -60,   -15,   -60,
     -60,   -60,   -60,   -60,   -59,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,    85,   -60,   -60,   -44,
     -60,   -60,   -60,   -60,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,     6,     8,    15,    24,    19,    16,    17,
      22,    36,    31,    32,    63,    64,   104,   134,   139,   103,
     133,   138,   142,   144,    75,    76,    65,    41,    42,    66,
      79,   100,   106,   125,   126
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    72,    69,    70,    71,     5,    25,    81,     7,    18,
      82,    83,    84,    85,    30,    26,    23,     9,     2,    90,
      37,    92,    93,    20,    95,    96,    10,    11,    12,    13,
      14,   101,   -17,    27,    28,   105,    29,    33,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     3,   124,    21,    34,   128,
     129,    35,   130,    38,    43,    44,    38,    45,    40,    81,
      81,    73,    46,    82,    83,    84,    85,    74,    47,   140,
     141,   -44,    90,    77,    78,   145,    72,    48,   135,   102,
      49,    50,    51,    52,    53,    54,    55,   131,   132,    56,
      57,    58,    59,    60,   136,    10,    11,    12,    13,    14,
      61,    38,    81,    44,    62,    45,   137,    84,    85,   143,
      46,    39,     0,     0,    90,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,    49,    50,
      51,    52,    53,    54,    67,     0,    44,    56,    57,    58,
      59,    60,     0,    46,     0,     0,     0,     0,    61,    47,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,    49,    50,    51,    52,    53,    54,    67,     0,    99,
       0,    81,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    61,    89,    90,    91,    92,    93,    94,    95,    96,
       0,    97,    98,    80,    81,     0,     0,    82,    83,    84,
      85,    86,    87,    88,     0,    89,    90,    91,    92,    93,
      94,    95,    96,     0,    97,    98,   127,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    88,     0,    89,    90,
      91,    92,    93,    94,    95,    96,    81,    97,    98,    82,
      83,    84,    85,    86,    87,    88,     0,    89,    90,    91,
      92,    93,    94,    95,    96,    81,    97,    98,    82,    83,
      84,    85,    86,    87,    88,     0,     0,    90,    91,    92,
      93,    94,    95,    96,    81,    97,     0,    82,    83,    84,
      85,    86,    87,    88,     0,     0,    90,    91,    92,    93,
      94,    95,    96,    81,     0,     0,    82,    83,    84,    85,
      86,     0,    88,     0,     0,    90,    91,    92,    93,    94,
      95,    96,    81,     0,     0,    82,    83,    84,    85,    86,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
      96,    81,     0,     0,    82,    83,    84,    85,     0,     0,
       0,     0,     0,    90,    91,    92,    93,    94,    95,    96
};

static const yytype_int16 yycheck[] =
{
      44,     5,    46,    47,    48,    36,    21,     8,     3,    36,
      11,    12,    13,    14,    29,    36,    10,    36,     0,    20,
      35,    22,    23,     4,    25,    26,    45,    46,    47,    48,
      49,    75,    36,     7,    36,    79,     5,    36,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    37,   100,    38,     6,   103,
     104,    10,   106,     3,     4,     5,     3,     7,    36,     8,
       8,     7,    12,    11,    12,    13,    14,     7,    18,   138,
     139,     7,    20,     5,     5,   144,     5,    27,   132,     7,
      30,    31,    32,    33,    34,    35,    36,     6,    10,    39,
      40,    41,    42,    43,     6,    45,    46,    47,    48,    49,
      50,     3,     8,     5,    42,     7,     6,    13,    14,    44,
      12,    36,    -1,    -1,    20,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,     5,    39,    40,    41,
      42,    43,    -1,    12,    -1,    -1,    -1,    -1,    50,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,     6,
      -1,     8,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    50,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,     7,     8,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,     7,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,     8,    28,    29,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,     8,    28,    29,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,     8,    28,    -1,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,     8,    -1,    -1,    11,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,     8,    -1,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,     8,    -1,    -1,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,     0,    37,    54,    36,    55,     3,    56,    36,
      45,    46,    47,    48,    49,    57,    60,    61,    36,    59,
       4,    38,    62,    10,    58,    60,    36,     7,    36,     5,
      60,    64,    65,    36,     6,    10,    63,    60,     3,    78,
      36,    79,    80,     4,     5,     7,    12,    18,    27,    30,
      31,    32,    33,    34,    35,    36,    39,    40,    41,    42,
      43,    50,    57,    66,    67,    78,    81,    36,    81,    81,
      81,    81,     5,     7,     7,    76,    77,     5,     5,    82,
       7,     8,    11,    12,    13,    14,    15,    16,    17,    19,
      20,    21,    22,    23,    24,    25,    26,    28,    29,     6,
      83,    81,     7,    71,    68,    81,    84,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    85,    86,     7,    81,    81,
      81,     6,    10,    72,    69,    81,     6,     6,    73,    70,
      66,    66,    74,    44,    75,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    55,    54,    56,    56,    58,    57,
      59,    59,    60,    60,    60,    60,    60,    60,    61,    61,
      63,    62,    64,    64,    65,    65,    66,    66,    66,    66,
      68,    69,    70,    67,    71,    72,    73,    74,    75,    67,
      67,    67,    76,    67,    77,    67,    79,    78,    80,    80,
      80,    82,    81,    81,    83,    81,    84,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    85,    85,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     7,     0,     2,     0,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       0,     8,     0,     1,     2,     4,     1,     2,     1,     1,
       0,     0,     0,     8,     0,     0,     0,     0,     0,    12,
       2,     2,     0,     4,     0,     3,     0,     4,     0,     2,
       2,     0,     3,     3,     0,     5,     0,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 4:
#line 72 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if (!symbolTable->CreateClassTable((*(String*)(&yyvsp[0])))) {
        printf("Error:Class <%s> already exists\n", (*(String*)(&yyvsp[0])));
        CodeContainer::codeContainer->Clear();YYERROR;
    }
}
#line 1452 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 5:
#line 81 "EzCompiler.yacc" /* yacc.c:1646  */
    {
}
#line 1459 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 8:
#line 94 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if (symbolTable->InDomain()) {
        for (int i = 0; i < (*(StringArray*)(&yyvsp[0])).size; i++) {
            if (symbolTable->InsertIntoCurrentDomainTable((*(StringArray*)(&yyvsp[0])).strings[i], (*(String*)(&yyvsp[-1]))) == nullptr) {
		if(symbolTable->TestClass((*(String*)(&yyvsp[-1])))){
		printf("Error:Domain variable <%s> already exists.\n",(*(StringArray*)(&yyvsp[0])).strings[i]);
		}else{
                printf("Error:Class <%s> is not defined.\n",(*(String*)(&yyvsp[-1])));
		}
                CodeContainer::codeContainer->Clear();YYERROR;
            }
        }
    } else {
        for (int i = 0; i < (*(StringArray*)(&yyvsp[0])).size; i++) {
            if (symbolTable->InsertIntoCurrentVarTable((*(StringArray*)(&yyvsp[0])).strings[i], SymbolTable::ClassTableItem::Field, (*(String*)(&yyvsp[-1]))) ==
                nullptr) {
		if(symbolTable->TestClass((*(String*)(&yyvsp[-1])))){
		printf("Error:Class variable <%s> already exists.\n",(*(StringArray*)(&yyvsp[0])).strings[i]);
		}else{
                printf("Error:Class <%s> is not defined.\n",(*(String*)(&yyvsp[-1])));
		}
                CodeContainer::codeContainer->Clear();YYERROR;
            }
        }
    }
}
#line 1490 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 10:
#line 128 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    (*(StringArray*)(&yyval)) = (*(StringArray*)(&yyvsp[-2]));
    strcpy((*(StringArray*)(&yyval)).strings[(*(StringArray*)(&yyval)).size++], (*(String*)(&yyvsp[0])));
}
#line 1499 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 11:
#line 133 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    strcpy((*(StringArray*)(&yyval)).strings[(*(StringArray*)(&yyval)).size++],(*(String*)(&yyvsp[0])));
}
#line 1507 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 12:
#line 139 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    strcpy((*(String*)(&yyval)),"double");
}
#line 1515 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 13:
#line 143 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    strcpy((*(String*)(&yyval)),"int");
}
#line 1523 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 14:
#line 147 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    strcpy((*(String*)(&yyval)),"char");
}
#line 1531 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 15:
#line 151 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    strcpy((*(String*)(&yyval)),"bool");
}
#line 1539 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 16:
#line 155 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    strcpy((*(String*)(&yyval)),"string");
}
#line 1547 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 17:
#line 159 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    strcpy((*(String*)(&yyval)),(*(String*)(&yyvsp[0])));
}
#line 1555 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 20:
#line 178 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    symbolTable->CreateDomainTable();
    createDomainTable = false;
    SymbolTable::ClassTableItem *item = symbolTable->InsertIntoCurrentFunTable((*(String*)(&yyvsp[-3])), SymbolTable::ClassTableItem::Field,
                                                                               (*(String*)(&yyvsp[-4])), CodeContainer::codeContainer->Size());
    preSize=CodeContainer::codeContainer->Size();
    FillBack::fillBack->CreateReturnList(item);
    if (item == nullptr) {
        if(symbolTable->TestClass((*(String*)(&yyvsp[-4])))){
            printf("Error:class function <%s> already exists.\n",(*(String*)(&yyvsp[-3])));
        }else{
            printf("Error:class <%s> is not defined.\n",(*(String*)(&yyvsp[-4])));
        }
        CodeContainer::codeContainer->Clear();YYERROR;
    }
    for (int i = 0; i < (*(StringArray*)(&yyvsp[-1])).size; i +=2) {
        if(strcmp((*(StringArray*)(&yyvsp[-1])).strings[i],"void")==0){
            printf("Error:<void> type cannot be used as a parameter type.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        item->AddArg((*(StringArray*)(&yyvsp[-1])).strings[i]);
        if (symbolTable->InsertIntoCurrentDomainTable((*(StringArray*)(&yyvsp[-1])).strings[i+1], (*(StringArray*)(&yyvsp[-1])).strings[i]) == nullptr) {
            if(symbolTable->TestClass((*(StringArray*)(&yyvsp[-1])).strings[i])){
                printf("Error:variable <%s> already exists in the formal parameter list.\n",(*(StringArray*)(&yyvsp[-1])).strings[i+1]);
            }else{
                printf("Error:class <%s> is not defined.\n",(*(StringArray*)(&yyvsp[-1])).strings[i]);
            }
            CodeContainer::codeContainer->Clear();YYERROR;
        }

    }	
}
#line 1592 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 21:
#line 210 "EzCompiler.yacc" /* yacc.c:1646  */
    {
printf("func name %s\n",(*(String*)(&yyvsp[-5])));
    if(strcmp((*(String*)(&yyvsp[-5])),"main")==0){
	if (FillBack::fillBack->GetHeader() != nullptr) {
        printf("ERROR:main function redefinition.\n");
        CodeContainer::codeContainer->Clear();
        YYERROR;
    } else {
        FillBack::fillBack->SetHeader(symbolTable->FindFunFromClassTable("main")->GetEntryPoint(),symbolTable->GetClassSize());
    }

    }
    FillBack::fillBack->DistoryReturnList(CodeContainer::codeContainer->Size());
    if (CodeContainer::codeContainer->Size() == preSize ||
        CodeContainer::codeContainer->At(CodeContainer::codeContainer->Size() - 1)->op != RET) {
        printf("ERROR:missing return statement.\n");
        CodeContainer::codeContainer->Clear();YYERROR;

    }
}
#line 1617 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 22:
#line 235 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(StringArray*)(&yyval)).size=0;
}
#line 1625 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 23:
#line 239 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(StringArray*)(&yyval))=(*(StringArray*)(&yyvsp[0]));
}
#line 1633 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 24:
#line 245 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    (*(StringArray*)(&yyval)).size=0;
    strcpy((*(StringArray*)(&yyval)).strings[(*(StringArray*)(&yyval)).size++],(*(String*)(&yyvsp[-1])));
    strcpy((*(StringArray*)(&yyval)).strings[(*(StringArray*)(&yyval)).size++],(*(String*)(&yyvsp[0])));
}
#line 1643 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 25:
#line 255 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    (*(StringArray*)(&yyval))=(*(StringArray*)(&yyvsp[-3]));
    strcpy((*(StringArray*)(&yyval)).strings[(*(StringArray*)(&yyval)).size++],(*(String*)(&yyvsp[-1])));
    strcpy((*(StringArray*)(&yyval)).strings[(*(StringArray*)(&yyval)).size++],(*(String*)(&yyvsp[0])));
}
#line 1653 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 27:
#line 266 "EzCompiler.yacc" /* yacc.c:1646  */
    {symbolTable->ClearTempVarTable();}
#line 1659 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 30:
#line 275 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    /*清空临时符号表*/
    symbolTable->ClearTempVarTable();
    /*开始进入翻译状态*/
    FillBack::fillBack->SetBoolTranslateState();
}
#line 1670 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 31:
#line 281 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    /*如果不是过度表达式,将在此处被处理*/
    if ((*(ExpInfo*)(&yyvsp[0])).expType != ETRANSIT) {
    	if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            YYERROR;
        }
    	}
        Map newMap;
        newMap.startPointInReal = (*(ExpInfo*)(&yyvsp[0])).startPoint + (*(ExpInfo*)(&yyvsp[0])).length;
        /*因为要生成2条转换代码*/
        newMap.lengthInReal = 2;
        (*(ExpInfo*)(&yyvsp[0])).length += 2;
        /*注意,不会在备份代码容器中生成代码*/
        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo = new BoolExpInfo();
        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(newMap);
        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.push_back(newMap.startPointInReal);
        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.push_back(newMap.startPointInReal + 1);
        CodeContainer::codeContainer->Insert(newMap.startPointInReal);
        CodeContainer::codeContainer->FillInOp(JNE, newMap.startPointInReal);
        switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
            case StringValue:
                printf("ERROR : while(string) is illegal.\n");
                YYERROR;
                break;
            case Void:
                printf("ERROR : while(void) is illegal.\n");
                YYERROR;
                break;
            case RefInStack:
                printf("ERROR : while(reference) is illegal.\n");
                YYERROR;
                break;
            case BoolInStack:
            case CharInStack:
            case IntInStack:
            case DoubleInStack:
            case BoolInHeap:
            case CharInHeap:
            case IntInHeap:
            case DoubleInHeap:
                CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod, newMap.startPointInReal);
                offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *), newMap.startPointInReal);
                break;
            case BoolValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool), newMap.startPointInReal);
                break;
            case CharValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char), newMap.startPointInReal);
                break;
            case IntValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int), newMap.startPointInReal);
                break;
            case DoubleValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double), newMap.startPointInReal);
                break;
            default:;
        }
        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool, newMap.startPointInReal);
        offset = false;
        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(bool), newMap.startPointInReal);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal);
        CodeContainer::codeContainer->Insert(newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInOp(JMP, newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod, newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod, newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal + 1);
    }
}
#line 1750 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 32:
#line 356 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    /*关闭翻译状态*/
    FillBack::fillBack->ResetBoolTranslateState();
    FillBack::codeContainer->Clear();
    /*回填写表达式(真出口)*/
    for (int idx:(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->tList) {
        offset = CodeContainer::codeContainer->Size();
        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
    }
    /*启动break，continue翻译机制*/
    FillBack::fillBack->CreateBreakList();
    FillBack::fillBack->CreateContinueList();
}
#line 1768 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 33:
#line 369 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    /*填入loop*/
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(JMP);
    CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    CodeContainer::codeContainer->FillInArg3(&(*(ExpInfo*)(&yyvsp[-4])).startPoint, sizeof(int));
    /*回填表达式(假出口)*/
    for (int idx:(*(ExpInfo*)(&yyvsp[-4])).boolExpInfo->fList) {
        offset = CodeContainer::codeContainer->Size();
        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
    }
    /*回填break,continue*/
    FillBack::fillBack->DistoryBreakList(CodeContainer::codeContainer->Size());
    FillBack::fillBack->DistoryContinueList((*(ExpInfo*)(&yyvsp[-4])).startPoint);
}
#line 1790 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 34:
#line 388 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    /*清空临时符号表*/
    symbolTable->ClearTempVarTable();
    /*开始进入翻译状态*/
    FillBack::fillBack->SetBoolTranslateState();
}
#line 1801 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 35:
#line 394 "EzCompiler.yacc" /* yacc.c:1646  */
    {

    /*如果不是过度表达式,将在此处被处理*/

    if ((*(ExpInfo*)(&yyvsp[0])).expType != ETRANSIT) {
        Map newMap;
        newMap.startPointInReal = (*(ExpInfo*)(&yyvsp[0])).startPoint + (*(ExpInfo*)(&yyvsp[0])).length;
        /*因为要生成2条转换代码*/
        newMap.lengthInReal = 2;
        (*(ExpInfo*)(&yyvsp[0])).length += 2;
        /*注意,不会在备份代码容器中生成代码*/
        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo = new BoolExpInfo();
        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(newMap);
        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.push_back(newMap.startPointInReal);
        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.push_back(newMap.startPointInReal + 1);
        CodeContainer::codeContainer->Insert(newMap.startPointInReal);
        CodeContainer::codeContainer->FillInOp(JNE, newMap.startPointInReal);
        switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
            case StringValue:
                printf("ERROR : while(string) is illegal.\n");
                YYERROR;
                break;
            case Void:
                printf("ERROR : while(void) is illegal.\n");
                YYERROR;
                break;
            case RefInStack:
                printf("ERROR : while(reference) is illegal.\n");
                YYERROR;
                break;
            case BoolInStack:
            case CharInStack:
            case IntInStack:
            case DoubleInStack:
            case BoolInHeap:
            case CharInHeap:
            case IntInHeap:
            case DoubleInHeap:
                CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod, newMap.startPointInReal);
                offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *), newMap.startPointInReal);
                break;
            case BoolValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool), newMap.startPointInReal);
                break;
            case CharValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char), newMap.startPointInReal);
                break;
            case IntValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int), newMap.startPointInReal);
                break;
            case DoubleValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double), newMap.startPointInReal);
                break;
            default:;
        }
        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool, newMap.startPointInReal);
        offset = false;
        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(bool), newMap.startPointInReal);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal);
        CodeContainer::codeContainer->Insert(newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInOp(JMP, newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod, newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod, newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal + 1);
    }

}
#line 1878 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 36:
#line 466 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    /*关闭翻译状态*/
    FillBack::fillBack->ResetBoolTranslateState();
    FillBack::codeContainer->Clear();
    /*回填写表达式(真出口)*/
    for (int idx:(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->tList) {
        offset = CodeContainer::codeContainer->Size();
        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
    }
    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->tList.clear();
    
}
#line 1895 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 37:
#line 478 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    /*生成一条jmp语句,并借用已经清空的tList*/
    (*(ExpInfo*)(&yyvsp[-4])).boolExpInfo->tList.push_back(CodeContainer::codeContainer->Size());
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(JMP);
    CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

}
#line 1910 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 38:
#line 488 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    /*回填表达式(假出口)*/
    for (int idx:(*(ExpInfo*)(&yyvsp[-6])).boolExpInfo->fList) {
        offset = CodeContainer::codeContainer->Size();
        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
    }
}
#line 1922 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 39:
#line 495 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    for (int idx:(*(ExpInfo*)(&yyvsp[-8])).boolExpInfo->tList) {
        offset = CodeContainer::codeContainer->Size();
        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
    }
}
#line 1933 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 40:
#line 503 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if (!FillBack::fillBack->AddIntoBreakList(CodeContainer::codeContainer->Size())) {
        CodeContainer::codeContainer->Clear();
        printf("ERROR:The break statement must be in the while statement.\n");
        YYERROR;
    }
    /*语句生成*/
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(JMP);
    CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
}
#line 1951 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 41:
#line 518 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if (!FillBack::fillBack->AddIntoContinueList(CodeContainer::codeContainer->Size())) {
        CodeContainer::codeContainer->Clear();
        printf("ERROR:The continue statement must be in the while statement.\n");
        YYERROR;
    }
    /*语句生成*/
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(JMP);
    CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
}
#line 1969 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 42:
#line 532 "EzCompiler.yacc" /* yacc.c:1646  */
    {
symbolTable->ClearTempVarTable();
}
#line 1977 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 43:
#line 536 "EzCompiler.yacc" /* yacc.c:1646  */
    {
        if ((*(ExpInfo*)(&yyvsp[-1])).expType == EUNKNOW) {
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-1])).stringValue, &(*(ExpInfo*)(&yyvsp[-1])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-1])).stringValue);
            YYERROR;
        }
    	}
    if (!FillBack::fillBack->AddIntoReturnList(CodeContainer::codeContainer->Size())) {
        CodeContainer::codeContainer->Clear();
        printf("ERROR:The return statement must be in the function.\n");
        YYERROR;
    }
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(RET);
    switch ((*(ExpInfo*)(&yyvsp[-1])).expValueType) {
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-1])).boolValue, sizeof(bool));
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-1])).charValue, sizeof(char));
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-1])).intValue, sizeof(bool));
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-1])).doubleValue, sizeof(double));
            break;
        case StringValue:
            break;
        default:
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-1])).agrParseMethod);
            offset = (*(ExpInfo*)(&yyvsp[-1])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
    }

    if (FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType() == "bool") {
        if ((*(ExpInfo*)(&yyvsp[-1])).expValueType == RefInStack) {
            printf("Unable to convert <%s> type to <bool> type.\n",
                   (*(ExpInfo*)(&yyvsp[-1])).domainTableItem->GetType().data());
            YYERROR;
        }
        CodeContainer::codeContainer->FillInArg2ParseMethod(CallToBool);

    } else if (FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType() == "char") {
        if ((*(ExpInfo*)(&yyvsp[-1])).expValueType == RefInStack) {
            printf("Unable to convert <%s> type to <char> type.\n",
                   (*(ExpInfo*)(&yyvsp[-1])).domainTableItem->GetType().data());
            YYERROR;
        }
        CodeContainer::codeContainer->FillInArg2ParseMethod(CallToChar);

    } else if (FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType() == "int") {
        if ((*(ExpInfo*)(&yyvsp[-1])).expValueType == RefInStack) {
            printf("Unable to convert <%s> type to <int> type.\n",
                   (*(ExpInfo*)(&yyvsp[-1])).domainTableItem->GetType().data());
            YYERROR;
        }
        CodeContainer::codeContainer->FillInArg2ParseMethod(CallToInt);

    } else if (FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType() == "double") {
        if ((*(ExpInfo*)(&yyvsp[-1])).expValueType == RefInStack) {
            printf("Unable to convert <%s> type to <double> type.\n",
                   (*(ExpInfo*)(&yyvsp[-1])).domainTableItem->GetType().data());
            YYERROR;
        }
        CodeContainer::codeContainer->FillInArg2ParseMethod(CallToDouble);

    } else if (FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType() == "void") {
        printf("ERROR:return value type is <void>.\n");
        YYERROR;
    } else {
        switch ((*(ExpInfo*)(&yyvsp[-1])).expValueType) {
            case RefInStack:
                if ((*(ExpInfo*)(&yyvsp[-1])).domainTableItem->GetType() != FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType()) {
                    printf("Unable to convert <%s> type to <%s> type.\n",
                           (*(ExpInfo*)(&yyvsp[-1])).domainTableItem->GetType().data(),
                           FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType().data());
                    YYERROR;
                    break;
                }
                CodeContainer::codeContainer->FillInArg2ParseMethod(CallToRef);
                break;
            case BoolValue:
            case BoolInStack:
            case BoolInHeap:
                printf("Unable to convert <bool> type to <%s> type.\n",
                       FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType().data());
                break;
            case CharValue:
            case CharInStack:
            case CharInHeap:
                printf("Unable to convert <char> type to <%s> type.\n",
                       FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType().data());
                break;
            case IntValue:
            case IntInStack:
            case IntInHeap:
                printf("Unable to convert <int> type to <%s> type.\n",
                       FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType().data());
                break;
            case DoubleValue:
            case DoubleInHeap:
            case DoubleInStack:
                printf("Unable to convert <double> type to <%s> type.\n",
                       FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType().data());
                break;
            case StringValue:
                break;
            default:

                YYERROR;
        }
    }
    CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
}
#line 2101 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 44:
#line 656 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    symbolTable->ClearTempVarTable();
    if (!FillBack::fillBack->AddIntoReturnList(CodeContainer::codeContainer->Size())) {
        CodeContainer::codeContainer->Clear();
        printf("ERROR:The return statement must be in the function.\n");
        YYERROR;
    }
    if(FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType() != "void"){
        printf("ERROR:return value type is <void>.\n");
        CodeContainer::codeContainer->Clear();
        YYERROR;
    }
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(RET);
    CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
}
#line 2124 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 46:
#line 678 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if(createDomainTable==false){
        createDomainTable=true;
    } else {
        symbolTable->CreateDomainTable();
    }
}
#line 2136 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 47:
#line 686 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    symbolTable->PopDomainTableStack();
}
#line 2144 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 51:
#line 702 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    FillBack::fillBack->SetNewTranslateState();
}
#line 2152 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 52:
#line 705 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    FillBack::fillBack->ResetNewTranslateState();
    (*(ExpInfo*)(&yyval))=(*(ExpInfo*)(&yyvsp[0]));
    (*(ExpInfo*)(&yyval)).expType=ENEW;
}
#line 2162 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 53:
#line 715 "EzCompiler.yacc" /* yacc.c:1646  */
    {
   int preLength = CodeContainer::codeContainer->Size();
    switch ((*(ExpInfo*)(&yyvsp[-2])).expType) {
        case EUNKNOW:

            if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
                printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            if (preLength < CodeContainer::codeContainer->Size()) {
                CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
                (*(ExpInfo*)(&yyvsp[-2])).length++;
                (*(ExpInfo*)(&yyvsp[0])).startPoint++;
                /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
                stack<Map> updateStack;
                while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                    updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
                }
                while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                    updateStack.pop();
                }
                /*真假链条同时也需要更新*/
                if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                    list<int>::iterator it;
                    for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                        (*it)++;
                    }
                    for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                        (*it)++;
                    }
                }
            }
            break;
        case ECALL:
            printf("Error:left value of the = operation cannot be expression <call>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case ENEW:
            printf("Error:left value of the = operation cannot be expression <new>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case EARITH:
            printf("Error:left value of the = operation cannot be expression <arith>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case ETRANSIT:
            printf("Error:left value of the = operation cannot be expression <arith>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case EVALUE:
            printf("Error:left value of the = operation cannot be expression <value>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[0])).length -=
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

        }
    }
    (*(ExpInfo*)(&yyval)).expType = EASSIGN;
    (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[0])).length + 1;
    (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(ASG);
    offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
    CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
    CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case RefInStack:
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case RefInStack:
                    if ((*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetType() != (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetType()) {
                        printf("Error:If the lvalue type of the operation = is <reference>, the rvalue type of the operation = should be the same as the lvalue type.\n");
                        CodeContainer::codeContainer->Clear();YYERROR;
                        break;
                    }
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar((*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetType(), &(*(ExpInfo*)(&yyval)));
                    break;
                default:
                    printf("If the lvalue type of the operation = is <reference>, then the rvalue type of the operation = should be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
            }
            offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            break;
        case BoolInStack:
        case BoolInHeap:
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
            break;
        case CharInStack:
        case CharInHeap:
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("char", &(*(ExpInfo*)(&yyval)));
            break;
        case IntInStack:
        case IntInHeap:
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
            break;
        case DoubleInStack:
        case DoubleInHeap:
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
            break;
        default:;
    }

    switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
        case Void:
            printf("Error:the right value type of the = operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            if ((*(ExpInfo*)(&yyvsp[-2])).expValueType != RefInStack) {
                printf("Error:the right value type of the = operation cannot be <reference>.\n");
                CodeContainer::codeContainer->Clear();YYERROR;
            }

        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
            break;
        case StringValue:
            printf("Error:the right value type of the = operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));

}
#line 2353 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 54:
#line 903 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    FillBack::fillBack->SetInterruptState();
}
#line 2361 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 55:
#line 907 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if (FillBack::fillBack->IsInterruptedTranslating()) {
        FillBack::fillBack->ResetInterrupt();
    }
    ExpInfo expInfo = symbolTable->GetExpItem();
    SymbolTable::DomainTableItem *domainTableItem = nullptr;
    SymbolTable::ClassTableItem *classTableItem = nullptr;
    (*(ExpInfo*)(&yyval)).expType = ECALL;

    if (expInfo.length >= 0) {
        /*如果潜在环境是一个变量*/
        if (expInfo.expType == EUNKNOW) {

            if (!symbolTable->SearchVarInDomainAndClassTable(expInfo.stringValue, &expInfo)) {
                printf("ERROR:variable \"%s\" must be defined before use\n", expInfo.stringValue);
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            if (expInfo.startPoint + 1 == CodeContainer::codeContainer->Size()) {
                expInfo.length++;
                symbolTable->SetExpItem(expInfo);
            }
            domainTableItem=expInfo.domainTableItem;
            classTableItem = symbolTable->FindFunFromClassTable((*(String*)(&yyvsp[-4])),
                                                                expInfo.domainTableItem->GetType());

            /*如果没找到,那么进行错误处理*/
            if (!classTableItem) {
                if (SymbolTable::JudgeTypeSize(expInfo.domainTableItem->GetType()) != -1) {
                    printf("ERROR:An expression of the form <%s>.%s(...) is not a call expression.\n",
                           expInfo.domainTableItem->GetType().data(), (*(String*)(&yyvsp[-4])));
                    CodeContainer::codeContainer->Clear();YYERROR;
                } else if (!symbolTable->TestClass(expInfo.domainTableItem->GetType())) {
                    printf("ERROR:Class <%s> is not defined.\n", expInfo.domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                } else {
                    printf("ERROR:Member function <%s> is not found in class <%s>.\n", (*(String*)(&yyvsp[-4])),
                           expInfo.domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                }
            }

        } else {

            domainTableItem = expInfo.domainTableItem;
            classTableItem = symbolTable->FindFunFromClassTable((*(String*)(&yyvsp[-4])),
                                                                domainTableItem->GetType());
            if (!classTableItem) {
                if (SymbolTable::JudgeTypeSize(domainTableItem->GetType()) != -1) {
                    printf("ERROR:An expression of the form <%s>(...) is not a call expression.\n",
                           domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                } else if (!symbolTable->TestClass(domainTableItem->GetType())) {
                    printf("ERROR:Class <%s> is not defined.\n", domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                } else {
                    printf("ERROR:Member function <%s> is not found in class <%s>.\n", (*(String*)(&yyvsp[-4])),
                           domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                }
            }
        }

    } else {
        /*没有潜在环境,但是也有可能是new表达式环境*/
        if (FillBack::fillBack->IsNewExpTranslating()) {
            if (!(classTableItem = symbolTable->FindFunFromClassTable((*(String*)(&yyvsp[-4])), (*(String*)(&yyvsp[-4]))))) {
                printf("ERROR:Constructor function <%s> is not found\n", (*(String*)(&yyvsp[-4])));
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            /*生成NEW表达式*/
            CodeContainer::codeContainer->PushBackCode();
            CodeContainer::codeContainer->FillInOp(NEW);
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            offset = symbolTable->GetClassSize((*(String*)(&yyvsp[-4])));
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(int));
            domainTableItem = symbolTable->CreateTempVar((*(String*)(&yyvsp[-4])));
            offset = domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2ParseMethod(StackToRef_T);
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
        } else {
            if (!(classTableItem = symbolTable->FindFunFromClassTable((*(String*)(&yyvsp[-4]))))) {
                printf("ERROR:function <%s> is not found.\n", (*(String*)(&yyvsp[-4])));
                CodeContainer::codeContainer->Clear();YYERROR;
            }
        }
    }
    if (classTableItem->GetAuth() == SymbolTable::ClassTableItem::Private) {
        printf("member function <%s> is of private and therefore cannot be accessed.\n", (*(String*)(&yyvsp[-4])));
        CodeContainer::codeContainer->Clear();YYERROR;
    }

    if (classTableItem->GetArgc() != (*(ExpInfoArray*)(&yyvsp[-1])).size) {
        printf("The number of arguments to the <call> expression does not match.\n");
        CodeContainer::codeContainer->Clear();YYERROR;
    }
    if (expInfo.length < 0) {
        if (FillBack::fillBack->IsNewExpTranslating()) {
            (*(ExpInfo*)(&yyval)).startPoint = CodeContainer::codeContainer->Size() - 1;
            (*(ExpInfo*)(&yyval)).length = (*(ExpInfoArray*)(&yyvsp[-1])).size + 2;
        } else {
            (*(ExpInfo*)(&yyval)).startPoint = CodeContainer::codeContainer->Size();
            (*(ExpInfo*)(&yyval)).length = (*(ExpInfoArray*)(&yyvsp[-1])).size + 1;
        }

    } else {
        (*(ExpInfo*)(&yyval)).startPoint = expInfo.startPoint;
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfoArray*)(&yyvsp[-1])).size + 1 + expInfo.length;
    }
    for (int i = 0; i < (*(ExpInfoArray*)(&yyvsp[-1])).size; i++) {

        if ((*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].expType == EUNKNOW &&
            !symbolTable->SearchVarInDomainAndClassTable((*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].stringValue,
                                                         &(*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i])) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        }
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(PARAM);
        switch ((*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].expValueType) {
            case BoolValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].boolValue, sizeof(bool));
                break;
            case CharValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].charValue, sizeof(char));
                break;
            case IntValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].intValue, sizeof(bool));
                break;
            case DoubleValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].doubleValue, sizeof(double));
                break;
            case StringValue:
                break;
            default:
                CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].agrParseMethod);
                offset = (*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].domainTableItem->GetOffsetInStack();
                CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
        }

        if (classTableItem->GetArg(i) == "bool") {
            if ((*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].expValueType == RefInStack) {
                printf("Unable to convert <%s> type to <bool> type.\n",
                       (*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].domainTableItem->GetType().data());
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(CallToBool);

        } else if (classTableItem->GetArg(i) == "char") {
            if ((*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].expValueType == RefInStack) {
                printf("Unable to convert <%s> type to <char> type.\n",
                       (*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].domainTableItem->GetType().data());
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(CallToChar);

        } else if (classTableItem->GetArg(i) == "int") {
            if ((*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].expValueType == RefInStack) {
                printf("Unable to convert <%s> type to <int> type.\n",
                       (*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].domainTableItem->GetType().data());
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(CallToInt);

        } else if (classTableItem->GetArg(i) == "double") {
            if ((*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].expValueType == RefInStack) {
                printf("Unable to convert <%s> type to <double> type.\n",
                       (*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].domainTableItem->GetType().data());
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(CallToDouble);

        } else if (classTableItem->GetArg(i) == "void") {
            printf("ERROR:<void> type cannot be used as a parameter type.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
        } else {
            switch ((*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].expValueType) {
                case RefInStack:
                    if ((*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].domainTableItem->GetType() != classTableItem->GetArg(i)) {
                        printf("Unable to convert <%s> type to <%s> type.\n",
                               (*(ExpInfoArray*)(&yyvsp[-1])).expInfos[i].domainTableItem->GetType().data(), classTableItem->GetArg(i).data());
                        CodeContainer::codeContainer->Clear();YYERROR;
                        break;
                    }
                    CodeContainer::codeContainer->FillInArg2ParseMethod(CallToRef);
                    break;
                case BoolValue:
                case BoolInStack:
                case BoolInHeap:
                    printf("Unable to convert <bool> type to <%s> type.\n", classTableItem->GetArg(i).data());
                    break;
                case CharValue:
                case CharInStack:
                case CharInHeap:
                    printf("Unable to convert <char> type to <%s> type.\n", classTableItem->GetArg(i).data());
                    break;
                case IntValue:
                case IntInStack:
                case IntInHeap:
                    printf("Unable to convert <int> type to <%s> type.\n", classTableItem->GetArg(i).data());
                    break;
                case DoubleValue:
                case DoubleInHeap:
                case DoubleInStack:
                    printf("Unable to convert <double> type to <%s> type.\n", classTableItem->GetArg(i).data());
                    break;
                case StringValue:
                    break;
                default:

                    CodeContainer::codeContainer->Clear();YYERROR;
            }
        }
    }

    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(CALL);
    CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
    offset = classTableItem->GetEntryPoint();
    CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
    offset = classTableItem->GetArgc();
    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
    if (FillBack::fillBack->IsNewExpTranslating()) {
        (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar((*(String*)(&yyvsp[-4])), &(*(ExpInfo*)(&yyval)));
    } else {
        if (classTableItem->GetReturnType() == "bool") {
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
        } else if (classTableItem->GetReturnType() == "char") {
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("char", &(*(ExpInfo*)(&yyval)));
        } else if (classTableItem->GetReturnType() == "int") {
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
        } else if (classTableItem->GetReturnType() == "double") {
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
        } else if (classTableItem->GetReturnType() == "void") {
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("void", &(*(ExpInfo*)(&yyval)));
        } else {
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar(classTableItem->GetReturnType(), &(*(ExpInfo*)(&yyval)));
        }
    }
    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
    if (!domainTableItem) {
        CodeContainer::codeContainer->FillInArg4ParseMethod(StackToRef);
        CodeContainer::codeContainer->FillInArg4(0);
    } else {
        CodeContainer::codeContainer->FillInArg4ParseMethod(StackToRef_T);
        CodeContainer::codeContainer->FillInArg4(domainTableItem->GetOffsetInStack());
    }

}
#line 2622 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1165 "EzCompiler.yacc" /* yacc.c:1646  */
    {
symbolTable->SetExpItem((*(ExpInfo*)(&yyvsp[-1])));
}
#line 2630 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1168 "EzCompiler.yacc" /* yacc.c:1646  */
    {

ExpInfo expInfo=symbolTable->GetExpItemAndClear();
    switch ((*(ExpInfo*)(&yyvsp[-3])).expType) {
        case EUNKNOW:
            if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-3])).stringValue, &(*(ExpInfo*)(&yyvsp[-3])))) {
                printf("ERROR:variable <%s> must be defined before use\n", (*(ExpInfo*)(&yyvsp[-3])).stringValue);
                CodeContainer::codeContainer->Clear();YYERROR;
            }
	    if(expInfo.length==1){
		CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size()-1);
	    }
            break;
        case EARITH:
            printf("ERROR:left value of the . operation cannot be expression <arith>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case EVALUE:
            printf("ERROR:left value of the . operation cannot be expression <value>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    switch ((*(ExpInfo*)(&yyvsp[0])).expType) {
        case EUNKNOW:
            (*(ExpInfo*)(&yyval)).expType = EVISIT;
            (*(ExpInfo*)(&yyvsp[0])).classTableItem = symbolTable->FindVarFromClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, (*(ExpInfo*)(&yyvsp[-3])).domainTableItem->GetType());
            if ((*(ExpInfo*)(&yyvsp[0])).classTableItem == nullptr) {
                if (SymbolTable::JudgeTypeSize((*(ExpInfo*)(&yyvsp[-3])).domainTableItem->GetType()) != -1) {
                    printf("ERROR:left value of the . operation cannot be Basic type <%s>.\n",
                           (*(ExpInfo*)(&yyvsp[-3])).domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                } else if (!symbolTable->TestClass((*(ExpInfo*)(&yyvsp[-3])).domainTableItem->GetType())) {
                    printf("ERROR:Class <%s> is not defined.\n", (*(ExpInfo*)(&yyvsp[-3])).domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                } else {
                    printf("ERROR:Member variable <%s> is not found in class <%s>.\n", (*(ExpInfo*)(&yyvsp[0])).stringValue,
                           (*(ExpInfo*)(&yyvsp[-3])).domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                }
            }
            if ((*(ExpInfo*)(&yyvsp[0])).classTableItem->GetAuth() == SymbolTable::ClassTableItem::Private) {
                printf("member variable <%s> is of private and therefore cannot be accessed.\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            CodeContainer::codeContainer->PushBackCode();
            CodeContainer::codeContainer->FillInOp(ADD);
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-3])).agrParseMethod);
            offset = (*(ExpInfo*)(&yyvsp[-3])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
            offset = (*(ExpInfo*)(&yyvsp[0])).classTableItem->GetOffset();
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));

            if ((*(ExpInfo*)(&yyvsp[0])).classTableItem->GetVarType() == "bool") {
                (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("@r-bool", &(*(ExpInfo*)(&yyval)));
                CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToBool_T);
            } else if ((*(ExpInfo*)(&yyvsp[0])).classTableItem->GetVarType() == "char") {
                (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("@r-char", &(*(ExpInfo*)(&yyval)));
                CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToChar_T);
            } else if ((*(ExpInfo*)(&yyvsp[0])).classTableItem->GetVarType() == "int") {
                (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("@r-int", &(*(ExpInfo*)(&yyval)));
                CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToInt_T);
            } else if ((*(ExpInfo*)(&yyvsp[0])).classTableItem->GetVarType() == "double") {
                (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("@r-double", &(*(ExpInfo*)(&yyval)));
                CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToDouble_T);
            } else {
                (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar((*(ExpInfo*)(&yyvsp[0])).classTableItem->GetVarType(), &(*(ExpInfo*)(&yyval)));
                CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToRef_T);
            }

            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case ECALL:
            (*(ExpInfo*)(&yyval)) = (*(ExpInfo*)(&yyvsp[0]));
            (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-3])).startPoint;
            (*(ExpInfo*)(&yyval)).length += (*(ExpInfo*)(&yyvsp[-3])).length;
            break;
        default:
            printf("ERROR:right value of the . operation must be <identifier>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;

    }
}
#line 2720 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1256 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
        if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
            while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                     (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                               (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                               (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
                (*(ExpInfo*)(&yyvsp[0])).length -=
                        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

            }
        }
        if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
            while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                     (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                               (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                               (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
                (*(ExpInfo*)(&yyvsp[-2])).length -=
                        (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
            }
        }
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 2;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        /*实例化*/
        (*(ExpInfo*)(&yyval)).boolExpInfo = new BoolExpInfo();
        /*填充信息,表示此表达式从CodeContainer的当前位置开始翻译,并且一定会生成两条代码*/
        Map newMap;
        newMap.startPointInReal = CodeContainer::codeContainer->Size();
        newMap.lengthInReal = 2;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.push(newMap);
        /*算术计算代码翻译到备用代码容器*/
        FillBack::codeContainer->PushBackCode();
        /*<=*/
        FillBack::codeContainer->FillInOp(LLT);
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(JLT);
        /*之后会再生成一条无条件转移指令*/

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        (*(ExpInfo*)(&yyval)).expType = EARITH;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LLT);
        /*之后不会生成无条件转移指令*/
    }
    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the < operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the < operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the < operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the < operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the < operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the < operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the < operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue < (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue < (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue < (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }
                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue < (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the < operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the < operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the < operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue < (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue < (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue < (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue < (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the < operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the < operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the < operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue < (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue < (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue < (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue < (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the < operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the < operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the < operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue < (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue < (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue < (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue < (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the < operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the < operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if (FillBack::fillBack->IsTranslating()) {
        /*真出口*/
        (*(ExpInfo*)(&yyval)).boolExpInfo->tList.push_back((*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().startPointInReal);
        (*(ExpInfo*)(&yyval)).boolExpInfo->fList.push_back((*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().startPointInReal + 1);
        /*生成无条件转移语句*/
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(JMP);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    }
}
#line 3477 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 59:
#line 2011 "EzCompiler.yacc" /* yacc.c:1646  */
    {
   if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
        if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
            while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                     (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                               (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                               (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
                (*(ExpInfo*)(&yyvsp[0])).length -=
                        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

            }
        }
        if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
            while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                     (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                               (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                               (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
                (*(ExpInfo*)(&yyvsp[-2])).length -=
                        (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
            }
        }
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 2;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        /*实例化*/
        (*(ExpInfo*)(&yyval)).boolExpInfo = new BoolExpInfo();
        /*填充信息,表示此表达式从CodeContainer的当前位置开始翻译,并且一定会生成两条代码*/
        Map newMap;
        newMap.startPointInReal = CodeContainer::codeContainer->Size();
        newMap.lengthInReal = 2;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.push(newMap);
        /*算术计算代码翻译到备用代码容器*/
        FillBack::codeContainer->PushBackCode();
        /*<=*/
        FillBack::codeContainer->FillInOp(LLE);
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(JLE);
        /*之后会再生成一条无条件转移指令*/

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        (*(ExpInfo*)(&yyval)).expType = EARITH;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LLE);
        /*之后不会生成无条件转移指令*/
    }
    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the <= operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the <= operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the <= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the <= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the <= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the <= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the <= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue <= (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue <= (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue <= (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }
                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue <= (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the <= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the <= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the <= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue <= (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue <= (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue <= (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue <= (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the <= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the <= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the <= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue <= (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue <= (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue <= (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue <= (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the <= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the <= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the <= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue <= (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue <= (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue <= (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue <= (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the <= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the <= operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if (FillBack::fillBack->IsTranslating()) {
        /*真出口*/
        (*(ExpInfo*)(&yyval)).boolExpInfo->tList.push_back((*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().startPointInReal);
        (*(ExpInfo*)(&yyval)).boolExpInfo->fList.push_back((*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().startPointInReal + 1);
        /*生成无条件转移语句*/
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(JMP);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    }

}
#line 4235 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 60:
#line 2767 "EzCompiler.yacc" /* yacc.c:1646  */
    {
   if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
        if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
            while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                     (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                               (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                               (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
                (*(ExpInfo*)(&yyvsp[0])).length -=
                        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

            }
        }
        if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
            while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                     (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                               (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                               (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
                (*(ExpInfo*)(&yyvsp[-2])).length -=
                        (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
            }
        }
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 2;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        /*实例化*/
        (*(ExpInfo*)(&yyval)).boolExpInfo = new BoolExpInfo();
        /*填充信息,表示此表达式从CodeContainer的当前位置开始翻译,并且一定会生成两条代码*/
        Map newMap;
        newMap.startPointInReal = CodeContainer::codeContainer->Size();
        newMap.lengthInReal = 2;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.push(newMap);
        /*算术计算代码翻译到备用代码容器*/
        FillBack::codeContainer->PushBackCode();
        /*<=*/
        FillBack::codeContainer->FillInOp(LGT);
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(JGT);
        /*之后会再生成一条无条件转移指令*/

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        (*(ExpInfo*)(&yyval)).expType = EARITH;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LGT);
        /*之后不会生成无条件转移指令*/
    }
    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the > operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the > operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the > operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the > operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the > operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the > operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the > operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue > (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue > (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue > (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }
                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue > (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the > operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the > operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the > operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue > (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue > (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue > (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue > (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the > operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the > operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the > operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue > (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue > (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue > (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue > (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the > operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the > operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the > operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue > (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue > (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue > (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue > (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the > operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the > operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if (FillBack::fillBack->IsTranslating()) {
        /*真出口*/
        (*(ExpInfo*)(&yyval)).boolExpInfo->tList.push_back((*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().startPointInReal);
        (*(ExpInfo*)(&yyval)).boolExpInfo->fList.push_back((*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().startPointInReal + 1);
        /*生成无条件转移语句*/
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(JMP);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    }

}
#line 4993 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 61:
#line 3523 "EzCompiler.yacc" /* yacc.c:1646  */
    {

    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
        if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
            while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                     (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                               (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                               (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
                (*(ExpInfo*)(&yyvsp[0])).length -=
                        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

            }
        }
        if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
            while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                     (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                               (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                               (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
                (*(ExpInfo*)(&yyvsp[-2])).length -=
                        (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
            }
        }
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 2;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        /*实例化*/
        (*(ExpInfo*)(&yyval)).boolExpInfo = new BoolExpInfo();
        /*填充信息,表示此表达式从CodeContainer的当前位置开始翻译,并且一定会生成两条代码*/
        Map newMap;
        newMap.startPointInReal = CodeContainer::codeContainer->Size();
        newMap.lengthInReal = 2;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.push(newMap);
        /*算术计算代码翻译到备用代码容器*/
        FillBack::codeContainer->PushBackCode();
        /*<=*/
        FillBack::codeContainer->FillInOp(LGE);
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(JGE);
        /*之后会再生成一条无条件转移指令*/

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        (*(ExpInfo*)(&yyval)).expType = EARITH;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LGE);
        /*之后不会生成无条件转移指令*/
    }
    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the >= operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the >= operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the >= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the >= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the >= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the >= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the >= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue >= (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue >= (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue >= (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }
                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue >= (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the >= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the >= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the >= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue >= (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue >= (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue >= (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue >= (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the >= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the >= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the >= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue >= (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue >= (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue >= (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue >= (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the >= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the >= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the >= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue >= (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue >= (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue >= (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue >= (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the >= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the >= operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if (FillBack::fillBack->IsTranslating()) {
        /*真出口*/
        (*(ExpInfo*)(&yyval)).boolExpInfo->tList.push_back((*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().startPointInReal);
        (*(ExpInfo*)(&yyval)).boolExpInfo->fList.push_back((*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().startPointInReal + 1);
        /*生成无条件转移语句*/
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(JMP);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    }
}
#line 5751 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 62:
#line 4279 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
        if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
            while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                     (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                               (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                               (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
                (*(ExpInfo*)(&yyvsp[0])).length -=
                        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

            }
        }
        if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
            while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                     (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                               (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                               (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
                (*(ExpInfo*)(&yyvsp[-2])).length -=
                        (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
            }
        }
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 2;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        /*实例化*/
        (*(ExpInfo*)(&yyval)).boolExpInfo = new BoolExpInfo();
        /*填充信息,表示此表达式从CodeContainer的当前位置开始翻译,并且一定会生成两条代码*/
        Map newMap;
        newMap.startPointInReal = CodeContainer::codeContainer->Size();
        newMap.lengthInReal = 2;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.push(newMap);
        /*算术计算代码翻译到备用代码容器*/
        FillBack::codeContainer->PushBackCode();
        /*<=*/
        FillBack::codeContainer->FillInOp(LNE);
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(JNE);
        /*之后会再生成一条无条件转移指令*/

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        (*(ExpInfo*)(&yyval)).expType = EARITH;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LNE);
        /*之后不会生成无条件转移指令*/
    }
    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the != operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            if ((*(ExpInfo*)(&yyvsp[0])).expValueType != RefInStack) {
                printf("ERROR:left value of the != operation is <reference> , but right value is not.\n");
                CodeContainer::codeContainer->Clear();YYERROR;
                break;
            }
            if ((*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetType() != (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetType()) {
                printf("ERROR:left value of the != operation is <%s> , but right value is <%s>.\n",
                       (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetType().data(), (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetType().data());
                CodeContainer::codeContainer->Clear();YYERROR;
                break;
            }
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
            }
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the != operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the != operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the != operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the != operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the != operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue != (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue != (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue != (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }
                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue != (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the != operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the != operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the != operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue != (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue != (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue != (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue != (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the != operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the != operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the != operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue != (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue != (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue != (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue != (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the != operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the != operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the != operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue != (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue != (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue != (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue != (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the != operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the != operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if (FillBack::fillBack->IsTranslating()) {
        /*真出口*/
        (*(ExpInfo*)(&yyval)).boolExpInfo->tList.push_back((*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().startPointInReal);
        (*(ExpInfo*)(&yyval)).boolExpInfo->fList.push_back((*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().startPointInReal + 1);
        /*生成无条件转移语句*/
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(JMP);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    }

}
#line 6542 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 63:
#line 5068 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
        if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
            while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                     (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                               (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                               (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
                (*(ExpInfo*)(&yyvsp[0])).length -=
                        (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

            }
        }
        if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
            while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                     (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                               (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                               (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
                (*(ExpInfo*)(&yyvsp[-2])).length -=
                        (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
            }
        }
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 2;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        /*实例化*/
        (*(ExpInfo*)(&yyval)).boolExpInfo = new BoolExpInfo();
        /*填充信息,表示此表达式从CodeContainer的当前位置开始翻译,并且一定会生成两条代码*/
        Map newMap;
        newMap.startPointInReal = CodeContainer::codeContainer->Size();
        newMap.lengthInReal = 2;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.push(newMap);
        /*算术计算代码翻译到备用代码容器*/
        FillBack::codeContainer->PushBackCode();
        /*<=*/
        FillBack::codeContainer->FillInOp(LEQ);
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(JEQ);
        /*之后会再生成一条无条件转移指令*/

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        (*(ExpInfo*)(&yyval)).expType = EARITH;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LEQ);
        /*之后不会生成无条件转移指令*/
    }
    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the == operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            if ((*(ExpInfo*)(&yyvsp[0])).expValueType != RefInStack) {
                printf("ERROR:left value of the == operation is <reference> , but right value is not.\n");
                CodeContainer::codeContainer->Clear();YYERROR;
                break;
            }
            if ((*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetType() != (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetType()) {
                printf("ERROR:left value of the == operation is <%s> , but right value is <%s>.\n",
                       (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetType().data(), (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetType().data());
                CodeContainer::codeContainer->Clear();YYERROR;
                break;
            }
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
            }
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the == operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the == operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the == operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the == operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the == operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue == (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue == (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue == (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }
                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue == (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the == operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the == operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the == operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue == (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue == (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue == (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue == (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the == operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the == operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the == operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue == (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue == (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue == (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue == (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the == operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the == operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the == operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue == (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue == (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue == (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue == (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the == operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the == operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if (FillBack::fillBack->IsTranslating()) {
        /*真出口*/
        (*(ExpInfo*)(&yyval)).boolExpInfo->tList.push_back((*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().startPointInReal);
        (*(ExpInfo*)(&yyval)).boolExpInfo->fList.push_back((*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().startPointInReal + 1);
        /*生成无条件转移语句*/
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(JMP);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    }
}
#line 7332 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 64:
#line 5856 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
        /*实例化*/
        (*(ExpInfo*)(&yyval)).boolExpInfo = new BoolExpInfo();
        /*检测左值与右值是否为过渡态,如果不是,那么需要转换*/
        if ((*(ExpInfo*)(&yyvsp[-2])).expType != ETRANSIT) {
            Map newMap;
            newMap.startPointInReal = (*(ExpInfo*)(&yyvsp[-2])).startPoint + (*(ExpInfo*)(&yyvsp[-2])).length;
            /*因为要生成2条转换代码*/
            newMap.lengthInReal = 2;
            (*(ExpInfo*)(&yyvsp[-2])).length += 2;
            /*注意,不会在备份代码容器中生成代码*/
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo = new BoolExpInfo();
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.push(newMap);
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->tList.push_back(newMap.startPointInReal);
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->fList.push_back(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal);
            CodeContainer::codeContainer->FillInOp(JNE, newMap.startPointInReal);
            switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
                case StringValue:
                    printf("ERROR:left value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case Void:
                    printf("ERROR:left value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:left value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod, newMap.startPointInReal);
                    offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *), newMap.startPointInReal);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool), newMap.startPointInReal);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char), newMap.startPointInReal);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int), newMap.startPointInReal);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double), newMap.startPointInReal);
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool, newMap.startPointInReal);
            offset = false;
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(bool), newMap.startPointInReal);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInOp(JMP, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal + 1);
            /*因为生成了两条语句,$3的开始点需要向后推移*/
            (*(ExpInfo*)(&yyvsp[0])).startPoint += 2;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal += 2;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it) += 2;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it) += 2;
                }
            }
        }
        if ((*(ExpInfo*)(&yyvsp[0])).expType != ETRANSIT) {
            Map newMap;
            newMap.startPointInReal = (*(ExpInfo*)(&yyvsp[0])).startPoint + (*(ExpInfo*)(&yyvsp[0])).length;
            /*因为要生成2条转换代码*/
            newMap.lengthInReal = 2;
            (*(ExpInfo*)(&yyvsp[0])).length += 2;
            /*注意,不会在备份代码容器中生成代码*/
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo = new BoolExpInfo();
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(newMap);
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.push_back(newMap.startPointInReal);
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.push_back(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal);
            CodeContainer::codeContainer->FillInOp(JNE, newMap.startPointInReal);
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case StringValue:
                    printf("ERROR:left value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case Void:
                    printf("ERROR:left value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:left value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod, newMap.startPointInReal);
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *), newMap.startPointInReal);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool), newMap.startPointInReal);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char), newMap.startPointInReal);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int), newMap.startPointInReal);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double), newMap.startPointInReal);
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool, newMap.startPointInReal);
            offset = false;
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(bool), newMap.startPointInReal);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInOp(JMP, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal + 1);
        }
        /*填充信息,初始化*/
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length;

        stack<Map> transitStack;

        while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
            transitStack.push((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top());
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
        }
        while (!transitStack.empty()) {
            (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.push(transitStack.top());
            transitStack.pop();
        }

        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            transitStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
        }
        while (!transitStack.empty()) {
            (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.push(transitStack.top());
            transitStack.pop();
        }

        Map newMap;

        newMap.startPointInReal = (*(ExpInfo*)(&yyval)).startPoint + (*(ExpInfo*)(&yyval)).length;
        newMap.lengthInReal = 0;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.push(newMap);
        FillBack::codeContainer->PushBackCode();
        /*||*/
        FillBack::codeContainer->FillInOp(LAND);

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        (*(ExpInfo*)(&yyval)).expType = EARITH;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LAND);
        /*之后不会生成无条件转移指令*/
    }
    /*如果在翻译模式中,那么仅仅向备份代码容器中翻译.如果不是,那么就在真实代码容器中翻译*/
    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the && operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the && operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
                CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue && (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue && (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue && (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }
                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue && (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue && (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue && (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue && (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue && (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue && (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue && (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue && (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue && (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue && (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue && (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue && (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }
                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue && (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the && operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    //A&&B
    if (FillBack::fillBack->IsTranslating()) {
        for (int idx:(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->tList) {
            offset = (*(ExpInfo*)(&yyvsp[0])).startPoint;
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
        }
        (*(ExpInfo*)(&yyval)).boolExpInfo->tList.splice((*(ExpInfo*)(&yyval)).boolExpInfo->tList.end(), (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList);
        (*(ExpInfo*)(&yyval)).boolExpInfo->fList.splice((*(ExpInfo*)(&yyval)).boolExpInfo->fList.end(), (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->fList);
        (*(ExpInfo*)(&yyval)).boolExpInfo->fList.splice((*(ExpInfo*)(&yyval)).boolExpInfo->fList.end(), (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList);
        /*资源释放*/
        delete (*(ExpInfo*)(&yyvsp[0])).boolExpInfo;
        /*资源释放*/
        delete (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo;
    }
}
#line 8155 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 65:
#line 6677 "EzCompiler.yacc" /* yacc.c:1646  */
    {


    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
        /*实例化*/
        (*(ExpInfo*)(&yyval)).boolExpInfo = new BoolExpInfo();
        /*检测左值与右值是否为过渡态,如果不是,那么需要转换*/
        if ((*(ExpInfo*)(&yyvsp[-2])).expType != ETRANSIT) {
            Map newMap;
            newMap.startPointInReal = (*(ExpInfo*)(&yyvsp[-2])).startPoint + (*(ExpInfo*)(&yyvsp[-2])).length;
            /*因为要生成2条转换代码*/
            newMap.lengthInReal = 2;
            (*(ExpInfo*)(&yyvsp[-2])).length += 2;
            /*注意,不会在备份代码容器中生成代码*/
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo = new BoolExpInfo();
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.push(newMap);
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->tList.push_back(newMap.startPointInReal);
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->fList.push_back(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal);
            CodeContainer::codeContainer->FillInOp(JNE, newMap.startPointInReal);
            switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
                case StringValue:
                    printf("ERROR:left value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case Void:
                    printf("ERROR:left value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:left value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod, newMap.startPointInReal);
                    offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *), newMap.startPointInReal);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool), newMap.startPointInReal);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char), newMap.startPointInReal);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int), newMap.startPointInReal);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double), newMap.startPointInReal);
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool, newMap.startPointInReal);
            offset = false;
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(bool), newMap.startPointInReal);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInOp(JMP, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal + 1);
            /*因为生成了两条语句,$3的开始点需要向后推移*/
            (*(ExpInfo*)(&yyvsp[0])).startPoint += 2;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal += 2;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it) += 2;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it) += 2;
                }
            }
        }
        if ((*(ExpInfo*)(&yyvsp[0])).expType != ETRANSIT) {
            Map newMap;
            newMap.startPointInReal = (*(ExpInfo*)(&yyvsp[0])).startPoint + (*(ExpInfo*)(&yyvsp[0])).length;
            /*因为要生成2条转换代码*/
            newMap.lengthInReal = 2;
            (*(ExpInfo*)(&yyvsp[0])).length += 2;
            /*注意,不会在备份代码容器中生成代码*/
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo = new BoolExpInfo();
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(newMap);
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.push_back(newMap.startPointInReal);
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.push_back(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal);
            CodeContainer::codeContainer->FillInOp(JNE, newMap.startPointInReal);
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case StringValue:
                    printf("ERROR:left value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case Void:
                    printf("ERROR:left value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:left value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod, newMap.startPointInReal);
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *), newMap.startPointInReal);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool), newMap.startPointInReal);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char), newMap.startPointInReal);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int), newMap.startPointInReal);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double), newMap.startPointInReal);
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool, newMap.startPointInReal);
            offset = false;
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(bool), newMap.startPointInReal);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInOp(JMP, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal + 1);
        }
        /*填充信息,初始化*/
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length;

        stack<Map> transitStack;

        while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
            transitStack.push((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top());
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
        }
        while (!transitStack.empty()) {
            (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.push(transitStack.top());
            transitStack.pop();
        }

        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            transitStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
        }
        while (!transitStack.empty()) {
            (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.push(transitStack.top());
            transitStack.pop();
        }

        Map newMap;

        newMap.startPointInReal = (*(ExpInfo*)(&yyval)).startPoint + (*(ExpInfo*)(&yyval)).length;
        newMap.lengthInReal = 0;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.push(newMap);
        FillBack::codeContainer->PushBackCode();
        /*||*/
        FillBack::codeContainer->FillInOp(LOR);

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        (*(ExpInfo*)(&yyval)).expType = EARITH;
        (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
        (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LOR);
        /*之后不会生成无条件转移指令*/
    }
    /*如果在翻译模式中,那么仅仅向备份代码容器中翻译.如果不是,那么就在真实代码容器中翻译*/
    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the || operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the || operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
                CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue || (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue || (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue || (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }
                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue || (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue || (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue || (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue || (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }

                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).charValue || (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue || (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue || (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue || (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).intValue || (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
                CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            }
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("bool", &(*(ExpInfo*)(&yyval)));
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue || (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case CharValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue || (*(ExpInfo*)(&yyvsp[0])).charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }

                    break;
                case IntValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue || (*(ExpInfo*)(&yyvsp[0])).intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;

                    }
                    break;
                case DoubleValue:
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = BoolValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToBool;
                    (*(ExpInfo*)(&yyval)).boolValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue || (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).boolExpInfo->mapStack.top().lengthInBackup--;
                        (*(ExpInfo*)(&yyval)).expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        (*(ExpInfo*)(&yyval)).length--;
                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the || operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    //A||B
    if (FillBack::fillBack->IsTranslating()) {
        for (int idx:(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->fList) {
            offset = (*(ExpInfo*)(&yyvsp[0])).startPoint;
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
        }
        (*(ExpInfo*)(&yyval)).boolExpInfo->tList.splice((*(ExpInfo*)(&yyval)).boolExpInfo->tList.end(), (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->tList);
        (*(ExpInfo*)(&yyval)).boolExpInfo->tList.splice((*(ExpInfo*)(&yyval)).boolExpInfo->tList.end(), (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList);
        (*(ExpInfo*)(&yyval)).boolExpInfo->fList.splice((*(ExpInfo*)(&yyval)).boolExpInfo->fList.end(), (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList);
        /*资源释放*/
        delete (*(ExpInfo*)(&yyvsp[0])).boolExpInfo;
        /*资源释放*/
        delete (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo;
    }
}
#line 8981 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 66:
#line 7500 "EzCompiler.yacc" /* yacc.c:1646  */
    {
}
#line 8988 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 67:
#line 7505 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }

    (*(ExpInfo*)(&yyval)).expType = EARITH;
    if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[0])).length -=
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

        }
    }
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[-2])).length -=
                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
        }
    }

    (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
    (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(ADD);

    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the + operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the + operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the + operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the + operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case StringValue:
                    printf("ERROR:right value of the + operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the + operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the + operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case StringValue:
                    printf("ERROR:right value of the + operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the + operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                case RefInStack:
                    printf("ERROR:right value of the + operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue + (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue + (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue + (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue + (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the + operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the + operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the + operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue + (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue + (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue + (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).charValue + (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the + operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the + operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the + operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue + (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue + (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue + (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).intValue + (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the + operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the + operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the + operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue + (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue + (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue + (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue + (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the + operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the + operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
#line 9518 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 68:
#line 8033 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }

    (*(ExpInfo*)(&yyval)).expType = EARITH;
    if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[0])).length -=
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

        }
    }
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[-2])).length -=
                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
        }
    }

    (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
    (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(SUB);

    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the - operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the - operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the - operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the - operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case StringValue:
                    printf("ERROR:right value of the - operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the - operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the - operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case StringValue:
                    printf("ERROR:right value of the - operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the - operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                case RefInStack:
                    printf("ERROR:right value of the - operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue - (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue - (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue - (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue - (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the - operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the - operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the - operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue - (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue - (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue - (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).charValue - (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the - operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the - operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the - operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue - (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue - (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue - (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).intValue - (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the - operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the - operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the - operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue - (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue - (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue - (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue - (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the - operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the - operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
#line 10048 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 69:
#line 8561 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }

    (*(ExpInfo*)(&yyval)).expType = EARITH;
    if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[0])).length -=
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

        }
    }
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[-2])).length -=
                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
        }
    }

    (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
    (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(MUL);

    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the * operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the * operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the * operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the * operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case StringValue:
                    printf("ERROR:right value of the * operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the * operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the * operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case StringValue:
                    printf("ERROR:right value of the * operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the * operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                case RefInStack:
                    printf("ERROR:right value of the * operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue * (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue * (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue * (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue * (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the * operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the * operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the * operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue * (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue * (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue * (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).charValue * (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the * operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the * operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the * operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue * (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue * (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue * (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).intValue * (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the * operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the * operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the * operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue * (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue * (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue * (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue * (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the * operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the * operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
#line 10578 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 70:
#line 9089 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }

    (*(ExpInfo*)(&yyval)).expType = EARITH;
    if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[0])).length -=
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

        }
    }
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[-2])).length -=
                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
        }
    }

    (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
    (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(DIV);

    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the / operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the / operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the / operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the / operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case StringValue:
                    printf("ERROR:right value of the / operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the / operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the / operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).doubleValue, sizeof(double));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    break;
                case StringValue:
                    printf("ERROR:right value of the / operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the / operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                case RefInStack:
                    printf("ERROR:right value of the / operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue / (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue / (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue + (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).boolValue / (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the / operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the / operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the / operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue / (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue / (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue / (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).charValue / (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the / operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the / operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the / operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue / (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue / (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue / (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).intValue / (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the / operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).doubleValue, sizeof(double));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the / operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the / operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue / (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue / (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue / (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = DoubleValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
                    (*(ExpInfo*)(&yyval)).doubleValue = (*(ExpInfo*)(&yyvsp[-2])).doubleValue / (*(ExpInfo*)(&yyvsp[0])).doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the / operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the / operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
#line 11108 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 71:
#line 9617 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }

    (*(ExpInfo*)(&yyval)).expType = EARITH;
    if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[0])).length -=
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

        }
    }
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[-2])).length -=
                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
        }
    }

    (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
    (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(XOR);

    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the  ^ operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the  ^ operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case DoubleInStack:
        case DoubleInHeap:
        case DoubleValue:
            printf("ERROR:left value of the  ^ operation cannot be <double>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the  ^ operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the  ^ operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the  ^ operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;

                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case StringValue:
                    printf("ERROR:right value of the  ^ operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the  ^ operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the  ^ operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the  ^ operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue ^ (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue ^ (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue ^ (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the  ^ operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the  ^ operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the  ^ operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the  ^ operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue ^ (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue ^ (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue ^ (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the  ^ operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the  ^ operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the  ^ operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the  ^ operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue ^ (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue ^ (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue ^ (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the  ^ operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the  ^ operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
#line 11480 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 72:
#line 9987 "EzCompiler.yacc" /* yacc.c:1646  */
    {

    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }

    (*(ExpInfo*)(&yyval)).expType = EARITH;
    if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[0])).length -=
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

        }
    }
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[-2])).length -=
                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
        }
    }

    (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
    (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(OR);

    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the | operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the | operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case DoubleInStack:
        case DoubleInHeap:
        case DoubleValue:
            printf("ERROR:left value of the | operation cannot be <double>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the | operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the | operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the | operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;

                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case StringValue:
                    printf("ERROR:right value of the | operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the | operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the | operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the | operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue | (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue | (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue | (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the | operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the | operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the | operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the | operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue | (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue | (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue | (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the | operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the | operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the | operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the | operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue | (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue | (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue | (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the | operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the | operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
#line 11853 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 73:
#line 10359 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }

    (*(ExpInfo*)(&yyval)).expType = EARITH;
    if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[0])).length -=
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

        }
    }
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[-2])).length -=
                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
        }
    }

    (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
    (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(AND);

    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the & operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the & operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case DoubleInStack:
        case DoubleInHeap:
        case DoubleValue:
            printf("ERROR:left value of the & operation cannot be <double>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the & operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the & operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the & operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;

                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case StringValue:
                    printf("ERROR:right value of the & operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the & operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the & operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the & operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue & (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue & (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue & (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the & operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the & operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the & operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the & operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue & (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue & (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue & (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the & operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the & operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the & operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the & operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue & (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue & (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue & (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the & operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the & operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }

}
#line 12226 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 74:
#line 10730 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[-2])).stringValue, &(*(ExpInfo*)(&yyvsp[-2])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[-2])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[-2])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[-2])).length++;
            (*(ExpInfo*)(&yyvsp[0])).startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top());
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();
            }
            while ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT && !updateStack.empty()) {
                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.begin(); it != (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }

    (*(ExpInfo*)(&yyval)).expType = EARITH;
    if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[0])).length -=
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

        }
    }
    if ((*(ExpInfo*)(&yyvsp[-2])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[-2])).length -=
                    (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[-2])).boolExpInfo->mapStack.pop();
        }
    }

    (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[-2])).length + (*(ExpInfo*)(&yyvsp[0])).length + 1;
    (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[-2])).startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(MOD);

    switch ((*(ExpInfo*)(&yyvsp[-2])).expValueType) {
        case Void:
            printf("ERROR:left value of the %% operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the %% operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case DoubleInStack:
        case DoubleInHeap:
        case DoubleValue:
            printf("ERROR:left value of the %% operation cannot be <double>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = (*(ExpInfo*)(&yyvsp[-2])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[-2])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the %% operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the %% operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the %% operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;

                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).boolValue, sizeof(bool));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).charValue, sizeof(char));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&(*(ExpInfo*)(&yyvsp[0])).intValue, sizeof(int));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    break;
                case StringValue:
                    printf("ERROR:right value of the %% operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).boolValue, sizeof(bool));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the %% operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the %% operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the %% operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue % (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue % (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue % (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the %% operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).charValue, sizeof(char));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the %% operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the %% operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the %% operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue % (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue % (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).charValue % (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the %% operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&(*(ExpInfo*)(&yyvsp[-2])).intValue, sizeof(int));
            switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
                case Void:
                    printf("ERROR:right value of the %% operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the %% operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the %% operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
                    CodeContainer::codeContainer->FillInArg3ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
                    offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue % (*(ExpInfo*)(&yyvsp[0])).boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue % (*(ExpInfo*)(&yyvsp[0])).charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    (*(ExpInfo*)(&yyval)).length--;
                    (*(ExpInfo*)(&yyval)).expType = EVALUE;
                    (*(ExpInfo*)(&yyval)).expValueType = IntValue;
                    (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
                    (*(ExpInfo*)(&yyval)).intValue = (*(ExpInfo*)(&yyvsp[-2])).intValue % (*(ExpInfo*)(&yyvsp[0])).intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the %% operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the %% operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
#line 12598 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 75:
#line 11100 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }
    (*(ExpInfo*)(&yyval)).expType = EARITH;
    if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[0])).length -=
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

        }
    }

    (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[0])).length + 1;
    (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[0])).startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(NEG);

    switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
        case Void:
            printf("ERROR:left value of the - operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the - operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            (*(ExpInfo*)(&yyval)).domainTableItem=symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
            CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            break;
        case DoubleInStack:
        case DoubleInHeap:
            offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            (*(ExpInfo*)(&yyval)).domainTableItem=symbolTable->CreateTempVar("double", &(*(ExpInfo*)(&yyval)));
            CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            break;
        case BoolValue:
            (*(ExpInfo*)(&yyval)).expType = EVALUE;
            (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
            (*(ExpInfo*)(&yyval)).intValue = -(*(ExpInfo*)(&yyvsp[0])).boolValue;
            (*(ExpInfo*)(&yyval)).expValueType=IntValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            (*(ExpInfo*)(&yyval)).length--;
        case CharValue:
            (*(ExpInfo*)(&yyval)).expType = EVALUE;
            (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
            (*(ExpInfo*)(&yyval)).intValue = -(*(ExpInfo*)(&yyvsp[0])).charValue;
            (*(ExpInfo*)(&yyval)).expValueType=IntValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            (*(ExpInfo*)(&yyval)).length--;
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            (*(ExpInfo*)(&yyval)).expType = EVALUE;
            (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
            (*(ExpInfo*)(&yyval)).intValue = -(*(ExpInfo*)(&yyvsp[0])).intValue;
            (*(ExpInfo*)(&yyval)).expValueType=IntValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            (*(ExpInfo*)(&yyval)).length--;
            break;
        case DoubleValue:
            (*(ExpInfo*)(&yyval)).expType = EVALUE;
            (*(ExpInfo*)(&yyval)).agrParseMethod = ToDouble;
            (*(ExpInfo*)(&yyval)).doubleValue = -(*(ExpInfo*)(&yyvsp[0])).doubleValue;
            (*(ExpInfo*)(&yyval)).expValueType=DoubleValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            (*(ExpInfo*)(&yyval)).length--;
            break;
        case StringValue:
            printf("ERROR:left value of the - operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
#line 12715 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 76:
#line 11214 "EzCompiler.yacc" /* yacc.c:1646  */
    {
    if ((*(ExpInfo*)(&yyvsp[0])).expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable((*(ExpInfo*)(&yyvsp[0])).stringValue, &(*(ExpInfo*)(&yyvsp[0])))) {
            printf("ERROR:variable \"%s\" must be defined before use\n", (*(ExpInfo*)(&yyvsp[0])).stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move((*(ExpInfo*)(&yyvsp[0])).startPoint, preLength);
            (*(ExpInfo*)(&yyvsp[0])).length++;
        }
    }
    (*(ExpInfo*)(&yyval)).expType = EARITH;
    if ((*(ExpInfo*)(&yyvsp[0])).expType == ETRANSIT) {
        while (!(*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal +
                                                (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                                 (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase((*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup,
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().startPointInBackup +
                                           (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup);
            (*(ExpInfo*)(&yyvsp[0])).length -=
                    (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInReal - (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.top().lengthInBackup;
            (*(ExpInfo*)(&yyvsp[0])).boolExpInfo->mapStack.pop();

        }
    }

    (*(ExpInfo*)(&yyval)).length = (*(ExpInfo*)(&yyvsp[0])).length + 1;
    (*(ExpInfo*)(&yyval)).startPoint = (*(ExpInfo*)(&yyvsp[0])).startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(NOT);

    switch ((*(ExpInfo*)(&yyvsp[0])).expValueType) {
        case Void:
            printf("ERROR:left value of the ~ operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the ~ operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case DoubleInStack:
        case DoubleInHeap:
        case DoubleValue:
            printf("ERROR:left value of the ~ operation cannot be <double>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = (*(ExpInfo*)(&yyvsp[0])).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod((*(ExpInfo*)(&yyvsp[0])).agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            (*(ExpInfo*)(&yyval)).domainTableItem = symbolTable->CreateTempVar("int", &(*(ExpInfo*)(&yyval)));
            CodeContainer::codeContainer->FillInArg2ParseMethod((*(ExpInfo*)(&yyval)).agrParseMethod);
            offset = (*(ExpInfo*)(&yyval)).domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            break;

        case BoolValue:
            (*(ExpInfo*)(&yyval)).expType = EVALUE;
            (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
            (*(ExpInfo*)(&yyval)).intValue = -(*(ExpInfo*)(&yyvsp[0])).boolValue;
            (*(ExpInfo*)(&yyval)).expValueType = IntValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            (*(ExpInfo*)(&yyval)).length--;
        case CharValue:
            (*(ExpInfo*)(&yyval)).expType = EVALUE;
            (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
            (*(ExpInfo*)(&yyval)).intValue = -(*(ExpInfo*)(&yyvsp[0])).charValue;
            (*(ExpInfo*)(&yyval)).expValueType = IntValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            (*(ExpInfo*)(&yyval)).length--;
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            (*(ExpInfo*)(&yyval)).expType = EVALUE;
            (*(ExpInfo*)(&yyval)).agrParseMethod = ToInt;
            (*(ExpInfo*)(&yyval)).intValue = -(*(ExpInfo*)(&yyvsp[0])).intValue;
            (*(ExpInfo*)(&yyval)).expValueType = IntValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            (*(ExpInfo*)(&yyval)).length--;
            break;
        case StringValue:
            printf("ERROR:left value of the ~ operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
#line 12821 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 77:
#line 11318 "EzCompiler.yacc" /* yacc.c:1646  */
    {
	(*(ExpInfo*)(&yyval))=(*(ExpInfo*)(&yyvsp[-1]));
}
#line 12829 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 78:
#line 11322 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(ExpInfo*)(&yyval)).expType=EVALUE;
(*(ExpInfo*)(&yyval)).intValue=(*(int*)(&yyvsp[0]));
(*(ExpInfo*)(&yyval)).expValueType=IntValue;
(*(ExpInfo*)(&yyval)).agrParseMethod=ToInt;
(*(ExpInfo*)(&yyval)).startPoint = CodeContainer::codeContainer->Size();
(*(ExpInfo*)(&yyval)).length = 0;
}
#line 12842 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 79:
#line 11331 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(ExpInfo*)(&yyval)).expType=EVALUE;
(*(ExpInfo*)(&yyval)).doubleValue=(*(double*)(&yyvsp[0]));
(*(ExpInfo*)(&yyval)).expValueType=DoubleValue;
(*(ExpInfo*)(&yyval)).agrParseMethod=ToDouble;
(*(ExpInfo*)(&yyval)).startPoint = CodeContainer::codeContainer->Size();
(*(ExpInfo*)(&yyval)).length = 0;
}
#line 12855 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 80:
#line 11340 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(ExpInfo*)(&yyval)).expType=EVALUE;
strcpy((*(ExpInfo*)(&yyval)).stringValue,(*(String*)(&yyvsp[0])));
(*(ExpInfo*)(&yyval)).expValueType=StringValue;
(*(ExpInfo*)(&yyval)).agrParseMethod=ToString;
(*(ExpInfo*)(&yyval)).startPoint = CodeContainer::codeContainer->Size();
(*(ExpInfo*)(&yyval)).length = 0;
}
#line 12868 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 81:
#line 11349 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(ExpInfo*)(&yyval)).expType=EVALUE;
(*(ExpInfo*)(&yyval)).charValue=(*(char*)(&yyvsp[0]));
(*(ExpInfo*)(&yyval)).expValueType=CharValue;
(*(ExpInfo*)(&yyval)).agrParseMethod=ToChar;
(*(ExpInfo*)(&yyval)).startPoint = CodeContainer::codeContainer->Size();
(*(ExpInfo*)(&yyval)).length = 0;
}
#line 12881 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 82:
#line 11358 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(ExpInfo*)(&yyval)).expType=EVALUE;
(*(ExpInfo*)(&yyval)).boolValue=true;
(*(ExpInfo*)(&yyval)).expValueType=BoolValue;
(*(ExpInfo*)(&yyval)).agrParseMethod=ToBool;
(*(ExpInfo*)(&yyval)).startPoint = CodeContainer::codeContainer->Size();
(*(ExpInfo*)(&yyval)).length = 0;
}
#line 12894 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 83:
#line 11367 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(ExpInfo*)(&yyval)).expType=EVALUE;
(*(ExpInfo*)(&yyval)).boolValue=false;
(*(ExpInfo*)(&yyval)).expValueType=BoolValue;
(*(ExpInfo*)(&yyval)).agrParseMethod=ToBool;
(*(ExpInfo*)(&yyval)).startPoint = CodeContainer::codeContainer->Size();
(*(ExpInfo*)(&yyval)).length = 0;
}
#line 12907 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 84:
#line 11376 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(ExpInfo*)(&yyval)).expType=EUNKNOW;
strcpy((*(ExpInfo*)(&yyval)).stringValue,(*(String*)(&yyvsp[0])));
(*(ExpInfo*)(&yyval)).startPoint = CodeContainer::codeContainer->Size();
(*(ExpInfo*)(&yyval)).length = 0;

}
#line 12919 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 85:
#line 11385 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(ExpInfoArray*)(&yyval)).size=0;
}
#line 12927 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 86:
#line 11389 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(ExpInfoArray*)(&yyval))=(*(ExpInfoArray*)(&yyvsp[0]));
}
#line 12935 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 87:
#line 11394 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(ExpInfoArray*)(&yyval)).size=0;
(*(ExpInfoArray*)(&yyval)).expInfos[(*(ExpInfoArray*)(&yyval)).size++]=(*(ExpInfo*)(&yyvsp[0]));
}
#line 12944 "EzCompiler.c" /* yacc.c:1646  */
    break;

  case 88:
#line 11401 "EzCompiler.yacc" /* yacc.c:1646  */
    {
(*(ExpInfoArray*)(&yyval))=(*(ExpInfoArray*)(&yyvsp[-2]));
(*(ExpInfoArray*)(&yyval)).expInfos[(*(ExpInfoArray*)(&yyval)).size++]=(*(ExpInfo*)(&yyvsp[0]));
}
#line 12953 "EzCompiler.c" /* yacc.c:1646  */
    break;


#line 12957 "EzCompiler.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 11406 "EzCompiler.yacc" /* yacc.c:1906  */


int main(int argc,char** argv){

    if(argc<=1){
        printf("Please enter the file\n");
        return 0;
    }

    string inputFileName(argv[1]);
    string outputFileName;
    int pos = inputFileName.rfind('.');
    if (pos == string::npos) {
        cout << "File format is incorrect." << endl;
        return 0;
    } else {
        outputFileName = inputFileName.substr(0, pos);

        string suffix = inputFileName.substr(pos + 1, inputFileName.length() - pos - 1);

        if (suffix != "ez" && suffix != "EZ" && suffix != "eZ" && suffix != "Ez") {
            cout << "File format is incorrect." << endl;
            return 0;
        }
        outputFileName.append(".EzClass");
    }

    symbolTable=new SymbolTable::SymbolTable();
    fillBack = new FillBack();
    yyin=fopen(argv[1], "r");
    yyparse();
    if(FillBack::fillBack->GetHeader() == nullptr){
    printf("ERROR:main function is undefined.\n");
    CodeContainer::codeContainer->Clear();
    return 0;
    }
    printf("CodeContainer:\n");
    CodeContainer::codeContainer->Debug();
    printf("FillBack:\n");
    FillBack::codeContainer->Debug();

    ofstream outPutFile;

#ifdef _WIN32

#elif __linux__
    string cmd("touch ");
    cmd.append(outputFileName);
    system(cmd.data());
#endif
    outPutFile.open(outputFileName, ios::out | ios::binary);
    if (outPutFile) {
	outPutFile.write((char*)FillBack::fillBack->GetHeader(),sizeof(Header));
        for (int i = 0; i < CodeContainer::codeContainer->Size(); i++) {
            Code *item = CodeContainer::codeContainer->At(i);
            outPutFile.write((char*)item,sizeof(Code));
        }
    } else {
        cout << "Fail to open the file.";
        return 0;
    }
	
}
