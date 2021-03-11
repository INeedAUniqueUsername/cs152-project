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


//TO DO: FIX TEMP DECLARATIONS
//to do: check var type matches (single vs array)
//to do: check var exists in symbol table
//to do: check array indexing
//to do: check advanced programs
//to do: syntax errors
//to do: re-entrant error

#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<string>
#include<string.h>
#include<sstream>
#include<utility>
#include<string>
#include<iostream>
using namespace std;
	
	int yylex();
	void yyerror(const char *msg);
	extern int currLine;
	extern int currPos;
	
	map<string, string> symbols;
	
	string make_label() {
		static unsigned count;
		ostringstream s;
		s << "__label__" << count;
		count++;
		return s.str();
	}
	string make_temp() {
		static unsigned count;
		ostringstream s;
		s << "__temp__" << count;
		count++;
		return s.str();
	}

#line 111 "y.tab.c" /* yacc.c:339  */

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
#line 46 "862012666-862083506.y" /* yacc.c:355  */

  int ival;
  char* ident;

	struct {
		char* IR;
	} Statement;
	
	struct {
		char* IR;
		char* ret_name;
	} Expression;

	struct {
		char* IR;
		char* ret_names;
	} FunctionArgs;
	
	struct {
		char* identifier;
		char* index;
	} Var;
	
	struct Identifier {
		char* identifier;
	} Identifier;
	
	struct IdentifierBlock {
		char* identifiers;
	} IdentifierBlock;
	
	struct {
		char* IR;
		char* identifiers;
	} DeclarationBlock;
	
	struct {
		char* IR;
		char* identifiers;
		unsigned size;
	} Declaration;
	
	struct {
		unsigned size;
	} DeclarationType;
	
	struct {
		char* op;
	} Operator;
	
	struct {
		char* IR;
	} Program;

#line 260 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 277 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

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
       0,   120,   120,   124,   127,   135,   170,   173,   179,   183,
     195,   196,   201,   204,   213,   216,   224,   229,   241,   257,
     279,   282,   289,   294,   304,   314,   339,   369,   404,   438,
     441,   444,   452,   457,   462,   468,   476,   481,   486,   492,
     500,   504,   517,   521,   534,   538,   551,   562,   565,   568,
     575,   576,   577,   578,   579,   580,   583,   587,   599,   613,
     617,   629,   641,   655,   659,   670,   689,   695,   701,   712,
     718,   722
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
  "loop-statement-block", "declaration", "identifier-block", "identifier",
  "statement", "read-block", "write-block", "bool-expr",
  "relation-and-expr", "relation-expr", "relation-expr-body", "comp",
  "expression", "multiplicative-expr", "term", "term-body",
  "function-args", YY_NULLPTR
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

#define YYPACT_NINF -69

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-69)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,   -23,    42,   -69,    12,    19,   -69,   -69,    33,    15,
     -69,    49,   -69,    40,    43,    44,    79,    15,   -11,    15,
      15,   -69,    57,   -69,   -69,    81,    51,    84,    62,    68,
      92,     3,   -20,     3,    97,    61,    63,    86,    93,   -69,
      71,    88,    67,    69,    98,     3,   -69,   -69,    36,    -7,
     -69,    -9,   113,    74,    76,   -69,    64,   -29,    25,   -69,
     -20,   -69,   112,    14,    82,    83,   -20,   -69,   -20,    68,
      85,    87,   -69,    89,   -22,   -69,   -20,   -20,    90,   -69,
      68,     3,     3,   -69,   -69,   -69,   -69,   -69,   -69,   -20,
     -20,   -20,   -20,   -20,   -20,    94,    14,    99,   116,   104,
     -20,   -20,   -69,    91,   -69,   -20,   -20,   -69,   -69,   107,
      95,    96,    17,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   125,    68,   129,    68,   100,   101,   115,   102,   103,
     -20,   -69,   -69,    68,   -69,   -69,   -69,     3,   -69,   -69,
     -69,   -20,   -69,   -69,   -69,   133,   -69,   -69,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,     0,     1,     4,     0,     6,
      22,     0,     7,     0,     0,    20,     0,     8,     0,     0,
       6,     9,     0,    18,    21,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    22,     0,    11,
       0,     0,    29,    30,     0,     0,    47,    48,     0,    67,
      66,     0,     0,    40,    42,    44,     0,    56,    59,    63,
       0,    31,     0,     0,    32,    36,     0,     5,     0,    12,
      34,    38,    19,     0,     0,    45,     0,     0,    67,    64,
       0,     0,     0,    54,    55,    52,    53,    50,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,    13,     0,     0,    49,    69,    70,
       0,     0,     0,    41,    43,    46,    58,    57,    60,    61,
      62,     0,    16,     0,    14,     0,     0,     0,     0,     0,
       0,    65,    68,     0,    25,    27,    17,     0,    15,    33,
      37,     0,    35,    39,    71,     0,    28,    24,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   138,   -69,   127,   131,   -69,   -68,    53,   -69,
     132,    70,   -57,   -69,   -69,   -31,    72,   -69,   105,   -69,
     -32,   -10,   -69,   106,    20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    12,    38,    39,    98,    13,
      14,    40,    41,    42,    43,    52,    53,    54,    55,    89,
      56,    57,    58,    59,   110
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,   104,    62,    22,    90,    91,    99,    83,    84,    85,
      86,    23,   112,    74,    73,     1,    87,    88,    31,   108,
      60,    32,   133,    33,    34,   134,     5,    97,    95,    49,
      50,    60,    51,    76,   102,    77,   103,    35,    36,    99,
      78,    50,     6,    45,   109,   111,     8,    46,    47,     9,
     113,    48,    49,    50,   136,    51,   138,   115,   116,   117,
      92,    93,    94,    37,    10,   145,    16,    17,   125,   126,
      19,    18,    31,   128,   129,    32,    45,    33,    34,    15,
      46,    47,   118,   119,   120,    49,    50,    15,    51,    15,
      15,    35,    36,    83,    84,    85,    86,    20,   109,    26,
      27,    28,    87,    88,    29,    30,   146,    44,    63,   147,
      64,    66,    65,    68,    67,    69,    70,    37,    71,    80,
      72,    81,    82,    96,   100,   101,   122,   105,   123,   106,
     107,   124,    77,   130,   127,   108,   131,   135,   137,   132,
     141,   148,     7,   139,   140,   142,   143,    25,    21,   121,
     144,    24,     0,    75,   114,     0,     0,    79
};

static const yytype_int16 yycheck[] =
{
      32,    69,    33,    14,    33,    34,    63,    29,    30,    31,
      32,    22,    80,    45,    45,     3,    38,    39,     4,    41,
      40,     7,     5,     9,    10,     8,    49,    13,    60,    49,
      50,    40,    52,    40,    66,    42,    68,    23,    24,    96,
      49,    50,     0,    40,    76,    77,    27,    44,    45,    16,
      81,    48,    49,    50,   122,    52,   124,    89,    90,    91,
      35,    36,    37,    49,    49,   133,    17,    27,   100,   101,
      26,    28,     4,   105,   106,     7,    40,     9,    10,     9,
      44,    45,    92,    93,    94,    49,    50,    17,    52,    19,
      20,    23,    24,    29,    30,    31,    32,    18,   130,    42,
      19,    50,    38,    39,    20,    43,   137,    15,    11,   141,
      49,    25,    49,    42,    21,    27,    49,    49,    49,     6,
      22,    47,    46,    11,    42,    42,    27,    42,    12,    42,
      41,    27,    42,    26,    43,    41,    41,    12,     9,    43,
      25,     8,     4,    43,    43,    43,    43,    20,    17,    96,
     130,    19,    -1,    48,    82,    -1,    -1,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    55,    56,    57,    49,     0,    56,    27,    16,
      49,    58,    59,    63,    64,    65,    17,    27,    28,    26,
      18,    59,    14,    22,    64,    58,    42,    19,    50,    20,
      43,     4,     7,     9,    10,    23,    24,    49,    60,    61,
      65,    66,    67,    68,    15,    40,    44,    45,    48,    49,
      50,    52,    69,    70,    71,    72,    74,    75,    76,    77,
      40,    74,    69,    11,    49,    49,    25,    21,    42,    27,
      49,    49,    22,    69,    74,    72,    40,    42,    49,    77,
       6,    47,    46,    29,    30,    31,    32,    38,    39,    73,
      33,    34,    35,    36,    37,    74,    11,    13,    62,    66,
      42,    42,    74,    74,    61,    42,    42,    41,    41,    74,
      78,    74,    61,    69,    70,    74,    74,    74,    75,    75,
      75,    62,    27,    12,    27,    74,    74,    43,    74,    74,
      26,    41,    43,     5,     8,    12,    61,     9,    61,    43,
      43,    25,    43,    43,    78,    61,    69,    74,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    68,    68,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    74,    74,    74,    75,
      75,    75,    75,    76,    76,    76,    77,    77,    77,    77,
      78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,    12,     0,     1,     2,     3,
       0,     1,     2,     3,     2,     3,     2,     3,     3,     8,
       1,     3,     1,     3,     6,     5,     7,     5,     6,     1,
       1,     2,     2,     5,     2,     5,     2,     5,     2,     5,
       1,     3,     1,     3,     1,     2,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     4,     1,     1,     4,     3,
       1,     3
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
#line 120 "862012666-862083506.y" /* yacc.c:1646  */
    {
			cout << (yyvsp[0].Statement).IR;
		}
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 124 "862012666-862083506.y" /* yacc.c:1646  */
    {

			  }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 127 "862012666-862083506.y" /* yacc.c:1646  */
    {
				std::ostringstream s;
				s << (yyvsp[-1].Statement).IR;
				s << (yyvsp[0].Statement).IR;
				(yyval.Statement).IR = strdup(s.str().c_str());
			}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 144 "862012666-862083506.y" /* yacc.c:1646  */
    {
		
			ostringstream s;

			s << "func " << (yyvsp[-10].ident) << std::endl;
			s << (yyvsp[-7].DeclarationBlock).IR;

			istringstream i((yyvsp[-7].DeclarationBlock).identifiers);
			string identifier;
			int count = 0;
			while(i >> identifier) {
				s << "= " << identifier << " $" << count << endl;
				count++;
			}

			s << (yyvsp[-4].DeclarationBlock).IR;
			s << (yyvsp[-1].Statement).IR;
			
			//Free the symbols and temps
			
			s << "endfunc" << std::endl;
			
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 170 "862012666-862083506.y" /* yacc.c:1646  */
    {	(yyval.DeclarationBlock).IR = strdup("");
			(yyval.DeclarationBlock).identifiers = strdup("");
		}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 173 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.DeclarationBlock).IR = strdup((yyvsp[0].DeclarationBlock).IR);
			(yyval.DeclarationBlock).identifiers = strdup((yyvsp[0].DeclarationBlock).identifiers);
		}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 179 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.DeclarationBlock).IR = strdup((yyvsp[-1].Declaration).IR);
			(yyval.DeclarationBlock).identifiers = strdup((yyvsp[-1].Declaration).identifiers);
		}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 183 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-2].Declaration).IR;
			s << (yyvsp[0].DeclarationBlock).IR;
			(yyval.DeclarationBlock).IR = strdup(s.str().c_str());

			ostringstream s2;
			s2 << (yyvsp[-2].Declaration).identifiers << " " << (yyvsp[0].DeclarationBlock).identifiers;
			(yyval.DeclarationBlock).identifiers = strdup(s2.str().c_str());
		}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 195 "862012666-862083506.y" /* yacc.c:1646  */
    {	(yyval.Statement).IR = strdup(""); }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 196 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Statement).IR = strdup((yyvsp[0].Statement).IR);
		}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 201 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Statement).IR = strdup((yyvsp[-1].Statement).IR);
		}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 204 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-2].Statement).IR;
			s << (yyvsp[0].Statement).IR;

			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 213 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Statement).IR = strdup((yyvsp[-1].Statement).IR);
		}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 216 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-2].Statement).IR;
			s << (yyvsp[0].Statement).IR;

			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 224 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << "__BREAK__" << endl;
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 229 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << "__BREAK__" << endl;
			s << (yyvsp[0].Statement).IR;

			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 241 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream o;
			ostringstream o2;
			istringstream i((yyvsp[-2].IdentifierBlock).identifiers);
			string identifier;
			while(i >> identifier) {
				string temp = make_temp();
				symbols[identifier] = temp;
				o << ". " << temp << endl;
				o2 << " " << temp;
			}

			(yyval.Declaration).size = 0;
			(yyval.Declaration).IR = strdup(o.str().c_str());
			(yyval.Declaration).identifiers = strdup(o2.str().c_str());
		}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 257 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream o;
			ostringstream o2;
			istringstream i((yyvsp[-7].IdentifierBlock).identifiers);

			string identifier;
			int size = (yyvsp[-3].ival);
			while(i >> identifier) {
				string temp = make_temp();
				symbols[identifier] = temp;

				o << ".[] " << temp << ", " << size << endl;
				o2 << " " << temp;
			}

			(yyval.Declaration).size = (unsigned)size;
			(yyval.Declaration).IR = strdup(o.str().c_str());
			(yyval.Declaration).identifiers = strdup(o2.str().c_str());
		}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 279 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.IdentifierBlock).identifiers = strdup((yyvsp[0].Identifier).identifier);
		}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 282 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-2].Identifier).identifier << " " << (yyvsp[0].IdentifierBlock).identifiers;
			(yyval.IdentifierBlock).identifiers = strdup(s.str().c_str());
		}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 289 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Identifier).identifier = (yyvsp[0].ident);
		}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 294 "862012666-862083506.y" /* yacc.c:1646  */
    {
			//std::string temp = lookup($1.identifier);
			string temp = symbols[(yyvsp[-2].ident)];

			ostringstream s;
			s << (yyvsp[0].Expression).IR;
			s << "= " << temp << ", " << (yyvsp[0].Expression).ret_name << std::endl;

			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 304 "862012666-862083506.y" /* yacc.c:1646  */
    {
			//Lookup from symbol table
			//std::string temp = lookup($1.identifier);
			string temp((yyvsp[-5].Identifier).identifier);

			ostringstream s;
			s << "[]= " << temp << ", " << (yyvsp[-3].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << std::endl;

			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 314 "862012666-862083506.y" /* yacc.c:1646  */
    {
			//TO DO: Make sure $ entries are properly indexed
			//Remove $0
			
			std::string label0 = make_label();
			std::string label1 = make_label();
			ostringstream s;
			
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
			
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 339 "862012666-862083506.y" /* yacc.c:1646  */
    {
			std::string label0 = make_label();
			std::string label1 = make_label();
			std::string label2 = make_label();
			ostringstream s;
			
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
			(yyval.Statement).IR = strdup(s.str().c_str());
			
		}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 369 "862012666-862083506.y" /* yacc.c:1646  */
    {
			string label_body = make_label();
			string label_condition = make_label();
			string label_end = make_label();

			std::ostringstream s;
			//Jump to condition
			s << ":= " << label_condition << endl;
			
			//Body
			s << ": " << label_body << endl; 

			//Body replace Breaks
			string line;
			istringstream body((yyvsp[-1].Statement).IR);
			while(getline(body, line)) {
				if(line == "__BREAK__") {
					s << ":= " << label_end << endl;
				} else {
					s << line << endl;
				}
			}

			//Check condition
			s << ": " << label_condition << endl;
			s << (yyvsp[-3].Expression).IR << endl;

			//Jump to body
			s << "?:= " << label_body << (yyvsp[-3].Expression).ret_name << endl;

			//End
			s << ": " << label_end << endl;

			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 404 "862012666-862083506.y" /* yacc.c:1646  */
    {
			std::string label_body = make_label();
			std::string label_condition = make_label();
			string label_end = make_label();
			
			std::ostringstream s;

			//Body
			s << ": " << label_body << std::endl; 
			
			//Body replace Breaks
			string line;
			istringstream body((yyvsp[-3].Statement).IR);
			while(getline(body, line)) {
				if(line == "__BREAK__") {
					s << ":= " << label_end << endl;
				} else {
					s << line << endl;
				}
			}
			
			//Condition
			s << ": " << label_condition << std::endl;
			s << (yyvsp[0].Expression).IR << std::endl;

			//Jump to body
			s << "?:= " << label_body << (yyvsp[0].Expression).ret_name << std::endl;

			//End
			s << ": " << label_end << endl;

			
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 438 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Statement).IR = strdup((yyvsp[0].Statement).IR);
		}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 441 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Statement).IR = strdup((yyvsp[0].Statement).IR);
		}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 444 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[0].Expression).IR;
			s << "ret " << (yyvsp[0].Expression).ret_name << endl;
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 452 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << ".< " << symbols[(yyvsp[0].ident)] << endl;
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 457 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << ".< " << symbols[(yyvsp[-3].ident)] << ", " << (yyvsp[-1].Expression).ret_name << endl;
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 462 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-1].Statement).IR;
			s << ".< " << symbols[(yyvsp[0].ident)] << endl;
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 468 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-4].Statement).IR;
			s << ".< " << symbols[(yyvsp[-3].ident)] << ", " << (yyvsp[-1].Expression).ret_name << endl;
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 476 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << ".> " << symbols[(yyvsp[0].ident)] << endl;
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 481 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << ".> " << symbols[(yyvsp[-3].ident)] << ", " << (yyvsp[-1].Expression).ret_name << endl;
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 486 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-1].Statement).IR;
			s << ".> " << symbols[(yyvsp[0].ident)] << endl;
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 492 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-4].Statement).IR;
			s << ".> " << symbols[(yyvsp[-3].ident)] << ", " << (yyvsp[-1].Expression).ret_name << endl;
			(yyval.Statement).IR = strdup(s.str().c_str());
		}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 500 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
			(yyval.Expression).ret_name = strdup((yyvsp[0].Expression).ret_name);
		}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 504 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-2].Expression).IR;
			s << (yyvsp[0].Expression).IR;

			string temp = make_temp();
			s << ". " << temp << endl;
			s << "|| " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
			(yyval.Expression).IR = strdup(s.str().c_str());
			(yyval.Expression).ret_name = strdup(temp.c_str());
		}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 517 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
			(yyval.Expression).ret_name = strdup((yyvsp[0].Expression).ret_name);
		}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 521 "862012666-862083506.y" /* yacc.c:1646  */
    {
			std::ostringstream s;
			s << (yyvsp[-2].Expression).IR;
			s << (yyvsp[0].Expression).IR;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "&& " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << std::endl;
			(yyval.Expression).IR = strdup(s.str().c_str());
			(yyval.Expression).ret_name = strdup(temp.c_str());
		}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 534 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
			(yyval.Expression).ret_name = strdup((yyvsp[0].Expression).ret_name);
		}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 538 "862012666-862083506.y" /* yacc.c:1646  */
    {
			std::ostringstream s;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;

			s << (yyvsp[0].Expression).IR;
			s << "! " << temp << ", " << (yyvsp[0].Expression).ret_name << std::endl;
			(yyval.Expression).IR = strdup(s.str().c_str());
			(yyval.Expression).ret_name = strdup(temp.c_str());
	  }
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 551 "862012666-862083506.y" /* yacc.c:1646  */
    {
		
			std::ostringstream s;
			s << (yyvsp[-2].Expression).IR;
			s << (yyvsp[0].Expression).IR;
			string temp = make_temp();
			s << ". " << temp << endl;
			s << (yyvsp[-1].Operator).op << " " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << std::endl;
			(yyval.Expression).IR = strdup(s.str().c_str());
			(yyval.Expression).ret_name = strdup(temp.c_str());
		}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 562 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).ret_name = strdup("true");
		}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 565 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).ret_name = strdup("false");
		}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 568 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = strdup((yyvsp[-1].Expression).IR);
			(yyval.Expression).ret_name = strdup((yyvsp[-1].Expression).ret_name);
		}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 575 "862012666-862083506.y" /* yacc.c:1646  */
    { (yyval.Operator).op = strdup("=="); }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 576 "862012666-862083506.y" /* yacc.c:1646  */
    { (yyval.Operator).op = strdup("!="); }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 577 "862012666-862083506.y" /* yacc.c:1646  */
    { (yyval.Operator).op = strdup("<"); }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 578 "862012666-862083506.y" /* yacc.c:1646  */
    { (yyval.Operator).op = strdup(">"); }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 579 "862012666-862083506.y" /* yacc.c:1646  */
    { (yyval.Operator).op = strdup("<="); }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 580 "862012666-862083506.y" /* yacc.c:1646  */
    { (yyval.Operator).op = strdup(">="); }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 583 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = strdup((yyvsp[0].Expression).IR);
			(yyval.Expression).ret_name = strdup((yyvsp[0].Expression).ret_name);
		}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 587 "862012666-862083506.y" /* yacc.c:1646  */
    { 
			std::ostringstream s;
			s << (yyvsp[-2].Expression).IR;
			s << (yyvsp[0].Expression).IR;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "+ " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << std::endl;
			
			(yyval.Expression).IR = strdup(s.str().c_str());
			(yyval.Expression).ret_name = strdup(temp.c_str());
		}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 599 "862012666-862083506.y" /* yacc.c:1646  */
    {
			std::ostringstream s;
			s << (yyvsp[-2].Expression).IR;
			s << (yyvsp[0].Expression).IR;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "- " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << std::endl;
			
			(yyval.Expression).IR = strdup(s.str().c_str());
			(yyval.Expression).ret_name = strdup(temp.c_str());
		}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 613 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = strdup((yyvsp[0].Expression).IR);
			(yyval.Expression).ret_name = strdup((yyvsp[0].Expression).ret_name);
		}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 617 "862012666-862083506.y" /* yacc.c:1646  */
    {
			std::ostringstream s;
			s << (yyvsp[-2].Expression).IR;
			s << (yyvsp[0].Expression).IR;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "* " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << std::endl;
			
			(yyval.Expression).IR = strdup(s.str().c_str());
			(yyval.Expression).ret_name = strdup(temp.c_str());
		}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 629 "862012666-862083506.y" /* yacc.c:1646  */
    {
			std::ostringstream s;
			s << (yyvsp[-2].Expression).IR;
			s << (yyvsp[0].Expression).IR;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "/ " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << std::endl;
			
			(yyval.Expression).IR = strdup(s.str().c_str());
			(yyval.Expression).ret_name = strdup(temp.c_str());
		}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 641 "862012666-862083506.y" /* yacc.c:1646  */
    {
			std::ostringstream s;
			s << (yyvsp[-2].Expression).IR;
			s << (yyvsp[0].Expression).IR;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "% " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << std::endl;
			
			(yyval.Expression).IR = strdup(s.str().c_str());
			(yyval.Expression).ret_name = strdup(temp.c_str());
		}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 655 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = strdup((yyvsp[0].Expression).IR);
			(yyval.Expression).ret_name = strdup((yyvsp[0].Expression).ret_name);
		}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 659 "862012666-862083506.y" /* yacc.c:1646  */
    {
			std::string temp = make_temp();
			
			std::ostringstream s;
			s << (yyvsp[0].Expression).IR;
			s << ". " << temp << endl;
			s << "- " << temp << ", 0, " << (yyvsp[0].Expression).ret_name << endl;
			
			(yyval.Expression).IR = strdup(s.str().c_str());
			(yyval.Expression).ret_name = strdup(temp.c_str());
		}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 670 "862012666-862083506.y" /* yacc.c:1646  */
    {
			std::ostringstream s;
			s << (yyvsp[-1].FunctionArgs).IR;

			istringstream i((yyvsp[-1].FunctionArgs).ret_names);
			string ret_name;
			while(i >> ret_name) {
				s << "param " << ret_name << endl;
			}

			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "call " << (yyvsp[-3].ident) << ", " << temp << endl;
			
			(yyval.Expression).IR = strdup(s.str().c_str());
			(yyval.Expression).ret_name = strdup(temp.c_str());
		}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 689 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = strdup("");
			char str[12];
			sprintf(str, "%d", (yyvsp[0].ival));
			(yyval.Expression).ret_name = strdup(str);
		}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 695 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = strdup("");

			string temp = symbols[(yyvsp[0].ident)];
			(yyval.Expression).ret_name = strdup(temp.c_str());
		}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 701 "862012666-862083506.y" /* yacc.c:1646  */
    {
			string temp = make_temp();

			string func = symbols[(yyvsp[-3].ident)];

			ostringstream s;
			s << "=[] " << temp << ", " << func << ", " << (yyvsp[-1].Expression).ret_name << endl;

			(yyval.Expression).IR = strdup(s.str().c_str());
			(yyval.Expression).ret_name = strdup(temp.c_str());
		}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 712 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.Expression).IR = strdup((yyvsp[-1].Expression).IR);
			(yyval.Expression).ret_name = strdup((yyvsp[-1].Expression).ret_name);
		}
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 718 "862012666-862083506.y" /* yacc.c:1646  */
    {
			(yyval.FunctionArgs).IR = strdup((yyvsp[0].Expression).IR);
			(yyval.FunctionArgs).ret_names = strdup((yyvsp[0].Expression).ret_name);
		}
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 722 "862012666-862083506.y" /* yacc.c:1646  */
    {
			ostringstream s;
			s << (yyvsp[-2].Expression).IR;
			s << (yyvsp[0].FunctionArgs).IR;
			(yyval.FunctionArgs).IR = strdup(s.str().c_str());

			ostringstream s2;
			s2 << (yyvsp[-2].Expression).ret_name << " " << (yyvsp[0].FunctionArgs).ret_names;
			(yyval.FunctionArgs).ret_names = strdup(s2.str().c_str());
		}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2362 "y.tab.c" /* yacc.c:1646  */
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
#line 733 "862012666-862083506.y" /* yacc.c:1906  */


int main(int argc, char **argv) {
   if (argc > 1) {
      FILE * yyin = fopen(argv[1], "r");
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
