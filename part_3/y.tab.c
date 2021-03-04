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
#line 1 "862012666-862083506.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<map.h>
using namespace std;
	
	void yyerror(const char *msg);
	extern int currLine;
	extern int currPos;
	FILE * yyin;
	
	map<string, pair<string, unsigned>> symbols;
	
	string make_label() {
		static unsigned count;
		ostringstream s;
		s << "l" << count << endl;
		count++;
		return s.str();
	}
	string make_temp() {
		static unsigned count;
		ostringstream s;
		s << "t" << count << endl;
		count++;
		return s.str();
	}
	
	struct Statement {
		std::string IR;
	};
	struct Expression {
		std::string IR;
		std::string ret_name;
	};
	struct ExpressionBlock {
		vector<Expression> expressions;
	};
	
	struct Var {
		std::string identifier;
		std::string index;
	};
	struct VarBlock {
		std::vector<std::pair<std::string, std::string>> variables;
	};
	
	struct Identifier {
		std::string identifier;
	};
	struct IdentifierBlock {
		vector<std::string> identifiers;
	};
	struct DeclarationBlock {
		std::string IR;
		std::vector<std::tuple<std::string, std::string, unsigned>> variables;
	};
	struct Declaration {
		std::string IR;
		std::vector<std::string> identifiers;
		std::string type;
		unsigned size;
	};
	struct DeclarationType {
		std::string type;
		unsigned size;
	};
	struct Operator {
		string op;
	};
	struct Program {
		string IR;
	};

#line 141 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    FUNCTION = 258,
    IF = 259,
    ELSE = 260,
    THEN = 261,
    RETURN = 262,
    ENDIF = 263,
    WHILE = 264,
    DO = 265,
    BEGINLOOP = 266,
    ENDLOOP = 267,
    BREAK = 268,
    ARRAY = 269,
    OF = 270,
    BEGIN_PARAMS = 271,
    END_PARAMS = 272,
    BEGIN_LOCALS = 273,
    END_LOCALS = 274,
    BEGIN_BODY = 275,
    END_BODY = 276,
    INTEGER = 277,
    READ = 278,
    WRITE = 279,
    ASSIGN = 280,
    COMMA = 281,
    SEMICOLON = 282,
    COLON = 283,
    LTE = 284,
    GTE = 285,
    LT = 286,
    GT = 287,
    SUB = 288,
    ADD = 289,
    MULT = 290,
    DIV = 291,
    MOD = 292,
    EQ = 293,
    NEQ = 294,
    L_PAREN = 295,
    R_PAREN = 296,
    L_SQUARE_BRACKET = 297,
    R_SQUARE_BRACKET = 298,
    TRUE = 299,
    FALSE = 300,
    AND = 301,
    OR = 302,
    NOT = 303,
    IDENT = 304,
    NUMBER = 305,
    PLUS = 306,
    MINUS = 307,
    UMINUS = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 76 "862012666-862083506.y" /* yacc.c:355  */

  double dval;
  int ival;
  char* ident;

#line 241 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 258 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   133,   136,   144,   174,   175,   181,   187,
     201,   202,   207,   210,   218,   258,   262,   268,   271,   277,
     282,   296,   321,   351,   365,   378,   390,   402,   405,   412,
     416,   428,   432,   444,   448,   459,   469,   472,   475,   481,
     482,   483,   484,   485,   486,   489,   493,   504,   517,   521,
     532,   543,   556,   560,   570,   586,   589,   600,   606,   609,
     615,   618,   624,   632
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "IF", "ELSE", "THEN",
  "RETURN", "ENDIF", "WHILE", "DO", "BEGINLOOP", "ENDLOOP", "BREAK",
  "ARRAY", "OF", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS",
  "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER", "READ", "WRITE",
  "ASSIGN", "COMMA", "SEMICOLON", "COLON", "LTE", "GTE", "LT", "GT", "SUB",
  "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "L_PAREN", "R_PAREN",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "TRUE", "FALSE", "AND", "OR",
  "NOT", "IDENT", "NUMBER", "PLUS", "MINUS", "UMINUS", "$accept",
  "program", "function-block", "function", "declaration-block-optional",
  "declaration-block", "statement-block-optional", "statement-block",
  "declaration", "declaration-type", "identifier-block", "identifier",
  "statement", "bool-expr", "relation-and-expr", "relation-expr",
  "relation-expr-body", "comp", "expression", "multiplicative-expr",
  "term", "term-body", "expression-block", "var-block", "var", YY_NULLPTR
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
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,   -34,    18,   -62,     7,   -62,    -4,   -62,   -62,     8,
     -34,    14,   -62,    16,     4,    13,    28,   -34,   -10,   -34,
     -34,   -62,     3,   -62,   -62,   -62,    30,     1,    40,    31,
      12,    58,    27,    53,    27,    67,   -62,   -34,   -34,    59,
     -62,    39,    61,    74,    78,    27,   -62,   -62,    42,    64,
     -62,   -12,    95,    63,    65,   -62,    77,   -28,    48,   -62,
     -62,    53,   -62,   101,    12,   -62,    87,   -62,   -62,    53,
      12,    53,   -62,    73,    24,   -62,    53,   -62,    12,    27,
      27,   -62,   -62,   -62,   -62,   -62,   -62,    53,    53,    53,
      53,    53,    53,    76,    12,   106,   -34,    79,   -62,   -62,
     -62,   -62,    93,    80,    36,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   108,   114,   -62,   -62,    53,   -62,    12,
     -62,   -62,    27,   -62,   116,   -62,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,    19,     0,     1,     4,     0,
       6,     0,     7,     0,     0,    17,     0,     8,     0,     0,
       6,     9,     0,    15,    14,    18,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,    27,     0,     0,     0,
      11,    62,     0,     0,     0,     0,    36,    37,     0,    19,
      55,     0,     0,    29,    31,    33,     0,    45,    48,    52,
      56,     0,    28,     0,     0,    25,    60,    26,     5,     0,
      12,     0,    16,     0,     0,    34,     0,    53,     0,     0,
       0,    43,    44,    41,    42,    39,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    20,
      38,    57,    58,     0,     0,    30,    32,    35,    47,    46,
      49,    50,    51,     0,     0,    61,    63,     0,    54,     0,
      21,    23,     0,    59,     0,    24,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,   121,   -62,   107,   109,   -62,   -61,   -62,   -62,
     110,    10,   -62,   -32,    50,   -62,    83,   -62,   -19,     5,
     -62,    81,    11,   -37,   -30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    12,    39,    40,    13,    24,
      14,    41,    42,    52,    53,    54,    55,    87,    56,    57,
      58,    59,   103,    65,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    67,    63,    95,    22,    88,    89,    66,    66,    98,
       1,     6,    23,    73,    62,     5,    32,   104,     7,    33,
      15,    34,    35,     9,    10,    36,    74,    15,    61,    15,
      15,    16,    18,   113,    43,    37,    38,     5,    50,    19,
      43,   119,    93,    17,   120,    27,    20,   105,    43,    28,
      97,    29,    99,    81,    82,    83,    84,   102,   124,   115,
      30,     5,    85,    86,    43,   101,    66,    45,   107,   108,
     109,    46,    47,    44,    31,    48,    49,    50,    64,    51,
      68,    69,    45,    90,    91,    92,    46,    47,    70,    43,
     125,    49,    50,    61,    51,   110,   111,   112,   102,    71,
      72,    78,    49,    50,    76,    51,    81,    82,    83,    84,
      79,    80,    94,    96,   100,    85,    86,   101,   114,   117,
     121,   118,   116,   122,   126,     8,    21,    26,   123,    25,
     106,    75,    77
};

static const yytype_uint8 yycheck[] =
{
      30,    38,    34,    64,    14,    33,    34,    37,    38,    70,
       3,     1,    22,    45,    33,    49,     4,    78,     0,     7,
      10,     9,    10,    27,    16,    13,    45,    17,    40,    19,
      20,    17,    28,    94,    64,    23,    24,    49,    50,    26,
      70,     5,    61,    27,     8,    42,    18,    79,    78,    19,
      69,    50,    71,    29,    30,    31,    32,    76,   119,    96,
      20,    49,    38,    39,    94,    41,    96,    40,    87,    88,
      89,    44,    45,    15,    43,    48,    49,    50,    11,    52,
      21,    42,    40,    35,    36,    37,    44,    45,    27,   119,
     122,    49,    50,    40,    52,    90,    91,    92,   117,    25,
      22,     6,    49,    50,    40,    52,    29,    30,    31,    32,
      47,    46,    11,    26,    41,    38,    39,    41,    12,    26,
      12,    41,    43,     9,     8,     4,    17,    20,   117,    19,
      80,    48,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    55,    56,    57,    49,    65,     0,    56,    27,
      16,    58,    59,    62,    64,    65,    17,    27,    28,    26,
      18,    59,    14,    22,    63,    64,    58,    42,    19,    50,
      20,    43,     4,     7,     9,    10,    13,    23,    24,    60,
      61,    65,    66,    78,    15,    40,    44,    45,    48,    49,
      50,    52,    67,    68,    69,    70,    72,    73,    74,    75,
      78,    40,    72,    67,    11,    77,    78,    77,    21,    42,
      27,    25,    22,    67,    72,    70,    40,    75,     6,    47,
      46,    29,    30,    31,    32,    38,    39,    71,    33,    34,
      35,    36,    37,    72,    11,    61,    26,    72,    61,    72,
      41,    41,    72,    76,    61,    67,    68,    72,    72,    72,
      73,    73,    73,    61,    12,    77,    43,    26,    41,     5,
       8,    12,     9,    76,    61,    67,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    63,    63,    64,    64,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    73,    73,
      73,    73,    74,    74,    74,    75,    75,    75,    76,    76,
      77,    77,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,    12,     0,     1,     2,     3,
       0,     1,     2,     3,     3,     1,     6,     1,     3,     1,
       3,     5,     7,     5,     6,     2,     2,     1,     2,     1,
       3,     1,     3,     1,     2,     3,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     4,     1,     1,     3,     1,     3,
       1,     3,     1,     4
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
        case 2:
#line 129 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Statement).IR = (yyvsp[0].Statement).IR;
		}
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 133 "862012666-862083506.y" /* yacc.c:1646  */
    {

			  }
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 136 "862012666-862083506.y" /* yacc.c:1646  */
    {
				ostringstream s;
				s << (yyvsp[-1].Statement).IR << endl;
				s << (yyvsp[0].Statement).IR << endl;
				(yyval.Statement).IR = s.str();
			}
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 153 "862012666-862083506.y" /* yacc.c:1646  */
    {
		
			stringstream s;
			s << (yyvsp[-10].Identifier).identifier << std::endl;
			
			s << (yyvsp[-7].DeclarationBlock).IR << std::endl;
			
			s << (yyvsp[-4].DeclarationBlock).IR << std::endl;
			
			s << (yyvsp[-1].Statement).IR<< std::endl;
			
			
			
			//Free the symbols and temps
			
			s << "endfunc" << std::endl;
			
			(yyval.Statement).IR = s.str();
		}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 174 "862012666-862083506.y" /* yacc.c:1646  */
    {}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 175 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.DeclarationBlock).IR = (yyvsp[0].DeclarationBlock).IR;
			(yyval.DeclarationBlock).variables = (yyvsp[0].DeclarationBlock).IR;
		}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 181 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.DeclarationBlock).IR = (yyvsp[-1].Declaration).IR;
			for(unsigned i = 0; i < (yyvsp[-1].Declaration).identifiers.size(); i++) {
				(yyval.DeclarationBlock).variables.push_back(make_tuple((yyvsp[-1].Declaration).identifiers[i], (yyvsp[-1].Declaration).type, (yyvsp[-1].Declaration).size));
			}
		}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 187 "862012666-862083506.y" /* yacc.c:1646  */
    {
			stringstream s;
			s << (yyvsp[-2].Declaration).IR;
			s << (yyvsp[0].DeclarationBlock).IR;
			(yyval.DeclarationBlock).IR = s.str();
			
			(yyval.DeclarationBlock).variables = (yyvsp[-2].Declaration).variables;
			
			for(unsigned i = 0; i < (yyvsp[-2].Declaration).identifiers.size(); i++) {
				(yyval.DeclarationBlock).variables.push_back(make_tuple((yyvsp[-2].Declaration).identifiers[i], (yyvsp[-2].Declaration).type, (yyvsp[-2].Declaration).size));
			}
		}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 201 "862012666-862083506.y" /* yacc.c:1646  */
    {}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 202 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Statement).IR = (yyvsp[0].Statement).IR;
		}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 207 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Statement).IR = (yyvsp[-1].Statement).IR;
		}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 210 "862012666-862083506.y" /* yacc.c:1646  */
    {
			stringstream s;
			s << (yyvsp[-2].Statement).IR;
			s << (yyvsp[0].Statement).IR;
			(yyval.Statement).IR = s.str();
		}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 218 "862012666-862083506.y" /* yacc.c:1646  */
    {
		
				(yyval.Declaration).identifiers = (yyvsp[-2].IdentifierBlock).identifiers;
				(yyval.Declaration).type = (yyvsp[0].DeclarationType).type;
				(yyval.Declaration).size = (yyvsp[0].DeclarationType).size;
				
				stringstream s;
				if((yyval.Declaration).size > 0) {
					for(unsigned i = 0; i < (yyval.Declaration).identifiers.size(); i++) {
						string identifier = (yyval.Declaration).identifiers[i];
						
						//Check if already in symbol table
						
						//Make a temp
						string temp = make_temp();
						s << ". " << temp << std::endl;
						
						//Add to symbol table
						
						//Make sure to free the symbol table entry and temp
					}
				} else {
					for(unsigned i = 0; i < (yyval.Declaration).identifiers.size(); i++) {
						string identifier = (yyval.Declaration).identifiers[i];
						
						//Check if already in symbol table
						
						//Make a temp
						string temp = make_temp();
						s << ".[] " << temp << ", " << (yyvsp[0].DeclarationType).size << std::endl;
						
						//Add to symbol table
						
						//Make sure to free the symbol table entry and temp
					}
				}
				(yyval.Declaration).IR = s.str();
		}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 258 "862012666-862083506.y" /* yacc.c:1646  */
    {
				(yyval.DeclarationType).type = "integer";
				(yyval.DeclarationType).size = 0;
		}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 262 "862012666-862083506.y" /* yacc.c:1646  */
    {
				(yyval.DeclarationType).type = "integer";
				(yyval.DeclarationType).size = atoi((yyvsp[-3].dval));
		}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 268 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.IdentifierBlock).identifiers.push_back((yyvsp[0].Identifier));
		}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 271 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.IdentifierBlock).identifiers = (yyvsp[0].IdentifierBlock).identifiers;
			(yyval.IdentifierBlock).identifiers.push_back((yyvsp[-2].Identifier));
		}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 277 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Identifier).identifier = (yyvsp[0].ident);
		}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 282 "862012666-862083506.y" /* yacc.c:1646  */
    {
			stringstream s;
			
			//Lookup from symbol table
			string temp = lookup((yyvsp[-2].Var).identifier);
			
			unsigned index = (yyvsp[-2].Var).index;
			if(index != -1) {
				s << "=[] " << temp << ", " << (yyvsp[0].Expression).ret_name << ", " << index << std::endl;
			} else {
				s << "= " << temp << ", " << (yyvsp[0].Expression).ret_name << std::endl;
			}
			(yyval.Statement).IR = s.str();
		}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 296 "862012666-862083506.y" /* yacc.c:1646  */
    {
			//TO DO: Make sure $ entries are properly indexed
			//Remove $0
			
			string label0 = make_label();
			string label1 = make_label();
			stringstream s;
			
			//Condition
			s << (yyvsp[-3].Expression).IR;
			//Jump into branch
			s << "?:=" << label0 << ", " << (yyvsp[-3].Expression).ret_name << std::endl;
			
			//Skip branch
			s << ":= " << label1 << std::endl;
			
			//Branch
			s << ":" << label0 << std::endl;
			s << (yyvsp[-1].Statement).IR;
			
			//Finally
			s << ": " << label1 << std::endl;
			
			(yyval.Statement).IR = s.str();
		}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 321 "862012666-862083506.y" /* yacc.c:1646  */
    {
			string label0 = make_label();
			string label1 = make_label();
			string label2 = make_label();
			stringstream s;
			
			//Condition
			s << (yyvsp[-5].Expression).IR;
			//Jump into branch
			s << "?:=" << label0 << ", " << (yyvsp[-5].Expression).ret_name << std::endl;
			
			//Jump into else
			s << ":= " << label1 << std::endl;
			
			//Branch
			s << ":" << label0 << std::endl;
			s << (yyvsp[-3].Statement).IR;
			
			//Jump to finally
			s << ":= " << label2 << std::endl;
			
			//Else
			s << ": " << label1 << std::endl;
			
			//Finally
			s << ": " << label2 << std::endl;
			s << (yyvsp[-1].Statement).IR;
			(yyval.Statement).IR = s.str();
			
		}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 351 "862012666-862083506.y" /* yacc.c:1646  */
    {
			string label_body = make_label();
			string label_condition = make_label();
			
			ostringstream s;
			s << ":= " << label_condition << endl;
			s << ": " << label_body << endl; 
			s << (yyvsp[-1].Statement).IR << endl;
			s << ": " << label_condition << endl;
			s << (yyvsp[-3].Expression).IR << endl;
			s << "?:= " << label_body << (yyvsp[-3].Expression).ret_name << endl;
			
			(yyval.Statement).IR = s.str();
		}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 365 "862012666-862083506.y" /* yacc.c:1646  */
    {
			string label_body = make_label();
			string label_condition = make_label();
			
			ostringstream s;
			s << ": " << label_body << endl; 
			s << (yyvsp[-3].Statement).IR << endl;
			s << ": " << label_condition << endl;
			s << (yyvsp[0].Expression).IR << endl;
			s << "?:= " << label_body << (yyvsp[0].Expression).ret_name << endl;
			
			(yyval.Statement).IR = s.str();
		}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 378 "862012666-862083506.y" /* yacc.c:1646  */
    {
			stringstream s;
			for(unsigned i = 0; i < (yyvsp[0].VarBlock).variables.size(); i++) {
				auto var = (yyvsp[0].VarBlock).variables[i];
				if(var.second == "") {
					s << ".< " << var.first << endl;
				} else {
					s << ".[]< " << var.first << ", " << var.second << std::endl;
				}
			}
			(yyval.Statement).IR = s.str();
		}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 390 "862012666-862083506.y" /* yacc.c:1646  */
    {
			stringstream s;
			for(unsigned i = 0; i < (yyvsp[0].VarBlock).variables.size(); i++) {
				auto var = (yyvsp[0].VarBlock).variables[i];
				if(var.second == "") {
					s << ".> " << var.first << std::endl;
				} else {
					s << ".[]> " << var.first << ", " << var.second << std::endl;
				}
			}
			(yyval.Statement).IR = s.str();
		}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 402 "862012666-862083506.y" /* yacc.c:1646  */
    {
	  
		}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 405 "862012666-862083506.y" /* yacc.c:1646  */
    {
			stringstream s;
			s << "ret " << (yyvsp[0].Expression).ret_name << endl;
			(yyval.Statement).IR = s.str();
		}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 412 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
			(yyval.Expression).ret_name = (yyvsp[0].Expression).ret_name;
		}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 416 "862012666-862083506.y" /* yacc.c:1646  */
    {
			string temp = make_temp();
	  
			ostringstream s;
			s << (yyvsp[-2].Expression).IR << std::endl;
			s << (yyvsp[0].Expression).IR << std::endl;
			s << "|| " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
			(yyval.Expression).IR = s.str();
			(yyval.Expression).ret_name = temp;
		}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 428 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
			(yyval.Expression).ret_name = (yyvsp[0].Expression).ret_name;
		}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 432 "862012666-862083506.y" /* yacc.c:1646  */
    {
			string temp = make_temp();
	  
			ostringstream s;
			s << (yyvsp[-2].Expression).IR << std::endl;
			s << (yyvsp[0].Expression).IR << std::endl;
			s << "&& " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
			(yyval.Expression).IR = s.str();
			(yyval.Expression).ret_name = temp;
		}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 444 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
			(yyval.Expression).ret_name = (yyvsp[0].Expression).ret_name;
		}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 448 "862012666-862083506.y" /* yacc.c:1646  */
    {
			string temp = make_temp();
	  
			ostringstream s;
			s << (yyvsp[0].Expression).IR << std::endl;
			s << "! " << temp << ", " << (yyvsp[0].Expression).ret_name << endl;
			(yyval.Expression).IR = s.str();
			(yyval.Expression).ret_name = temp;
	  }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 459 "862012666-862083506.y" /* yacc.c:1646  */
    {
			string temp = make_temp();
	  
			ostringstream s;
			s << (yyvsp[-2].Expression).IR << std::endl;
			s << (yyvsp[0].Expression).IR << std::endl;
			s << (yyvsp[-1].Operator).op << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
			(yyval.Expression).IR = s.str();
			(yyval.Expression).ret_name = temp;
		}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 469 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).ret_name = "true";
		}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 472 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).ret_name = "false";
		}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 475 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = (yyvsp[-1].Expression).IR;
			(yyval.Expression).ret_name = (yyvsp[-1].Expression).ret_name;
		}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 481 "862012666-862083506.y" /* yacc.c:1646  */
    { (yyval.Operator).op = "=="; }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 482 "862012666-862083506.y" /* yacc.c:1646  */
    { (yyval.Operator).op = "!="; }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 483 "862012666-862083506.y" /* yacc.c:1646  */
    { (yyval.Operator).op = "<"; }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 484 "862012666-862083506.y" /* yacc.c:1646  */
    { (yyval.Operator).op = ">"; }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 485 "862012666-862083506.y" /* yacc.c:1646  */
    { (yyval.Operator).op = "<="; }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 486 "862012666-862083506.y" /* yacc.c:1646  */
    { (yyval.Operator).op = ">="; }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 489 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
			(yyval.Expression).ret_name = (yyvsp[0].Expression).ret_name;
		}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 493 "862012666-862083506.y" /* yacc.c:1646  */
    { 
			ostringstream s;
			s << (yyvsp[-2].Expression).IR << endl;
			s << (yyvsp[0].Expression).IR << endl;
			
			string temp = make_temp();
			s << "+ " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
			
			(yyval.Expression).IR = s.str();
			(yyval.Expression).ret_name = temp;
		}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 504 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-2].Expression).IR << endl;
			s << (yyvsp[0].Expression).IR << endl;
			
			string temp = make_temp();
			s << "- " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
			
			(yyval.Expression).IR = s.str();
			(yyval.Expression).ret_name = temp;
		}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 517 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
			(yyval.Expression).ret_name = (yyvsp[0].Expression).ret_name;
		}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 521 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-2].Expression).IR << endl;
			s << (yyvsp[0].Expression).IR << endl;
			
			string temp = make_temp();
			s << "* " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
			
			(yyval.Expression).IR = s.str();
			(yyval.Expression).ret_name = temp;
		}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 532 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-2].Expression).IR << endl;
			s << (yyvsp[0].Expression).IR << endl;
			
			string temp = make_temp();
			s << "/ " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
			
			(yyval.Expression).IR = s.str();
			(yyval.Expression).ret_name = temp;
		}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 543 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-2].Expression).IR << endl;
			s << (yyvsp[0].Expression).IR << endl;
			
			string temp = make_temp();
			s << "% " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
			
			(yyval.Expression).IR = s.str();
			(yyval.Expression).ret_name = temp;
		}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 556 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
			(yyval.Expression).ret_name = (yyvsp[0].Expression).ret_name;
		}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 560 "862012666-862083506.y" /* yacc.c:1646  */
    {
			string temp = make_temp();
			
			ostringstream s;
			s << (yyvsp[0].Expression).IR << endl;
			s << "- " << temp << ", 0, " << (yyvsp[0].Expression).ret_name;
			
			(yyval.Expression).IR = s.str();
			(yyval.Expression).ret_name = temp;
		}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 570 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			for(const auto& e : (yyvsp[-1].ExpressionBlock).expressions) {
				s << e.IR << endl;
			}
			for(const auto& e : (yyvsp[-1].ExpressionBlock).expressions) {
				s << "param " << e.ret_name << endl;
			}
			string temp = make_temp();
			s << "call " << (yyvsp[-3].ident) << ", " << temp << endl;
			
			(yyval.Expression).IR = s.str();
			(yyval.Expression).ret_name = temp;
		}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 586 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).ret_name = (yyvsp[0].dval);
		}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 589 "862012666-862083506.y" /* yacc.c:1646  */
    {
			if((yyvsp[0].Var).index != (unsigned)-1) {
				string temp = make_temp();
				ostringstream s;
				s << "=[] " << temp << ", " << (yyvsp[0].Var).identifier << ", " << (yyvsp[0].Var).index;
				(yyval.Expression).IR = s.str();
				(yyval.Expression).ret_name = temp;
			} else {
				(yyval.Expression).ret_name = (yyvsp[0].Var).ret_name;
			}
		}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 600 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = (yyvsp[-1].Expression).IR;
			(yyval.Expression).ret_name = (yyvsp[-1].Expression).ret_name;
		}
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 606 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.ExpressionBlock).expressions.push_back((yyvsp[0].Expression));
		}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 609 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.ExpressionBlock).expressions = (yyvsp[0].ExpressionBlock).expressions;
			(yyval.ExpressionBlock).expressions.push_back((yyvsp[-2].Expression));
		}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 615 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.VarBlock).variables.push_back(make_pair((yyvsp[0].Var).identifier, (yyvsp[0].Var).index));
		}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 618 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.VarBlock).variables = (yyvsp[0].VarBlock).variables;
			(yyval.VarBlock).variables.push_back(make_pair((yyvsp[-2].Var).identifier, (yyvsp[-2].Var).index));
		}
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 624 "862012666-862083506.y" /* yacc.c:1646  */
    {
			auto pair = symbols.find((yyvsp[0].Identifier));
			if(pair != symbols.end()) {
				(yyval.Var).identifier = pair.second;
			} else {
				throw exception("invalid symbol");
			}
		}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 632 "862012666-862083506.y" /* yacc.c:1646  */
    {
			auto pair = symbols.find((yyvsp[-3].Identifier));
			if(pair != symbols.end()) {
				(yyval.Var).identifier = pair.second;
			} else {
				throw exception("invalid symbol");
			}
			
			(yyval.Var).index = (yyvsp[-1].Expression).ret_name;
		}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2196 "y.tab.c" /* yacc.c:1646  */
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
#line 643 "862012666-862083506.y" /* yacc.c:1906  */


int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
      }//end if
   }//end if
   yyparse(); // Calls yylex() for tokens.
   return 0;
}

void yyerror(const char *msg) {
   printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}
