/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "1705067.y"

#include<bits/stdc++.h>
#include "1705067_ST.cpp"
using namespace std;



int yyparse(void);
int yylex(void);
extern FILE *yyin;

int line_count=1;
int error_calc=0;
ofstream logout;
ofstream errorfile;
vector<SymbolInfo*> parameter;
SymbolTable *table = new SymbolTable(30,logout);


void yyerror(char *s)
{
	logout<<"Syntax error at line no: "<< line_count<<endl;
}



#line 97 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    IF = 258,
    FOR = 259,
    WHILE = 260,
    INT = 261,
    FLOAT = 262,
    VOID = 263,
    RETURN = 264,
    CONST_INT = 265,
    CONST_FLOAT = 266,
    ID = 267,
    MULOP = 268,
    INCOP = 269,
    DECOP = 270,
    ADDOP = 271,
    RELOP = 272,
    ASSIGNOP = 273,
    LOGICOP = 274,
    NOT = 275,
    LPAREN = 276,
    RPAREN = 277,
    LCURL = 278,
    RCURL = 279,
    LTHIRD = 280,
    RTHIRD = 281,
    COMMA = 282,
    SEMICOLON = 283,
    PRINTLN = 284,
    LOWER_THAN_ELSE = 285,
    ELSE = 286
  };
#endif
/* Tokens.  */
#define IF 258
#define FOR 259
#define WHILE 260
#define INT 261
#define FLOAT 262
#define VOID 263
#define RETURN 264
#define CONST_INT 265
#define CONST_FLOAT 266
#define ID 267
#define MULOP 268
#define INCOP 269
#define DECOP 270
#define ADDOP 271
#define RELOP 272
#define ASSIGNOP 273
#define LOGICOP 274
#define NOT 275
#define LPAREN 276
#define RPAREN 277
#define LCURL 278
#define RCURL 279
#define LTHIRD 280
#define RTHIRD 281
#define COMMA 282
#define SEMICOLON 283
#define PRINTLN 284
#define LOWER_THAN_ELSE 285
#define ELSE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "1705067.y"

	int ival;
	SymbolInfo* si;
	vector<SymbolInfo*>* vs;

#line 217 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    62,    81,    95,   107,   119,   132,   187,
     235,   234,   354,   353,   430,   485,   521,   544,   568,   567,
     604,   603,   635,   703,   713,   723,   735,   768,   810,   835,
     871,   884,   906,   919,   931,   943,   987,  1016,  1055,  1084,
    1114,  1135,  1145,  1163,  1195,  1278,  1291,  1482,  1495,  1585,
    1598,  1685,  1698,  1787,  1800,  1978,  2026,  2074,  2088,  2100,
    2274,  2291,  2300,  2309,  2324,  2341,  2353,  2360,  2381
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "FOR", "WHILE", "INT", "FLOAT",
  "VOID", "RETURN", "CONST_INT", "CONST_FLOAT", "ID", "MULOP", "INCOP",
  "DECOP", "ADDOP", "RELOP", "ASSIGNOP", "LOGICOP", "NOT", "LPAREN",
  "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON",
  "PRINTLN", "LOWER_THAN_ELSE", "ELSE", "$accept", "start", "program",
  "unit", "func_declaration", "func_definition", "$@1", "$@2",
  "parameter_list", "compound_statement", "$@3", "$@4", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      52,   -73,   -73,   -73,     9,    52,   -73,   -73,   -73,   -73,
      10,   -73,   -73,    29,    64,     8,    15,    25,   -73,    14,
      12,    28,    23,    27,   -73,    44,    56,    52,   -73,   -73,
      78,    69,   -73,   -73,    44,   100,    82,    93,    91,   -73,
     -73,   -73,    97,    98,    99,    45,   -73,   -73,    60,    45,
      45,    45,   -73,   102,   -73,   -73,   105,    66,   -73,   -73,
      65,   101,   -73,   106,    90,   111,   -73,   -73,   -73,    45,
       7,    45,   103,    45,    45,    96,   -73,   -73,   104,   115,
     107,   -73,   -73,   -73,   -73,    45,   -73,    45,    45,    45,
      45,   108,     7,   112,   -73,   -73,   113,   109,   114,   -73,
     116,   -73,   -73,   111,   117,   -73,    93,    45,    93,   -73,
      45,   -73,   118,   110,   120,   -73,   -73,   -73,    93,    93,
     -73,   -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,     0,     0,     0,    22,    12,
       0,    17,     0,    26,     9,     0,    10,     0,    16,    29,
       0,    18,    13,     8,     0,    15,     0,     0,     0,    11,
      14,    27,     0,     0,     0,     0,    61,    62,    43,     0,
       0,     0,    41,     0,    34,    32,     0,     0,    30,    33,
      58,     0,    45,    47,    49,    51,    53,    57,    21,     0,
       0,     0,     0,    66,     0,    58,    55,    56,     0,     0,
      28,    19,    31,    63,    64,     0,    42,     0,     0,     0,
       0,     0,     0,     0,    40,    68,     0,    65,     0,    60,
       0,    46,    48,    52,    50,    54,     0,     0,     0,    59,
       0,    44,     0,    36,     0,    38,    67,    39,     0,     0,
      37,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,   -73,   123,   -73,   -73,   -73,   -73,   -73,   -13,
     -73,   -73,    36,     5,   -73,   -73,   -55,   -59,   -42,   -45,
     -72,    50,    54,    51,   -46,   -73,   -73,   -73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    34,    25,    20,    54,
      37,    38,    55,    56,    14,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    96,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      72,    95,    82,    76,    77,    10,    78,    75,    75,    11,
      10,    92,    32,   101,     1,     2,     3,    46,    47,    48,
      21,    39,    13,    49,    91,    22,    93,    50,    51,    98,
      19,    75,    35,   107,    26,    52,     9,    23,   116,    27,
      28,     9,    24,    75,   105,    75,    75,    75,    75,    29,
      15,   113,    30,   115,    16,    46,    47,    48,     1,     2,
       3,    49,   114,   120,   121,    50,    51,    31,    75,    42,
      43,    44,     1,     2,     3,    45,    46,    47,    48,    83,
      84,    73,    49,    85,    33,    74,    50,    51,    36,    31,
      81,    17,    18,   -20,    52,    53,    42,    43,    44,     1,
       2,     3,    45,    46,    47,    48,    88,    89,    41,    49,
      83,    84,    40,    50,    51,    68,    31,    80,    69,    70,
      71,    52,    53,    79,    90,    87,    99,   100,    12,    86,
     106,    94,    16,    88,   108,   109,   110,   102,   112,   103,
     111,   118,   119,   104,     0,     0,   117
};

static const yytype_int8 yycheck[] =
{
      45,    73,    57,    49,    50,     0,    51,    49,    50,     0,
       5,    70,    25,    85,     6,     7,     8,    10,    11,    12,
      15,    34,    12,    16,    69,    10,    71,    20,    21,    74,
      22,    73,    27,    92,    22,    28,     0,    12,   110,    27,
      12,     5,    28,    85,    90,    87,    88,    89,    90,    26,
      21,   106,    25,   108,    25,    10,    11,    12,     6,     7,
       8,    16,   107,   118,   119,    20,    21,    23,   110,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    14,
      15,    21,    16,    18,    28,    25,    20,    21,    10,    23,
      24,    27,    28,    24,    28,    29,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    16,    17,    26,    16,
      14,    15,    12,    20,    21,    24,    23,    12,    21,    21,
      21,    28,    29,    21,    13,    19,    22,    12,     5,    28,
      22,    28,    25,    16,    22,    22,    27,    87,    22,    88,
      26,    31,    22,    89,    -1,    -1,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,    33,    34,    35,    36,    37,    44,
      45,     0,    35,    12,    46,    21,    25,    27,    28,    22,
      40,    45,    10,    12,    28,    39,    22,    27,    12,    26,
      25,    23,    41,    28,    38,    45,    10,    42,    43,    41,
      12,    26,     3,     4,     5,     9,    10,    11,    12,    16,
      20,    21,    28,    29,    41,    44,    45,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    24,    21,
      21,    21,    51,    21,    25,    50,    56,    56,    51,    21,
      12,    24,    48,    14,    15,    18,    28,    19,    16,    17,
      13,    51,    49,    51,    28,    52,    58,    59,    51,    22,
      12,    52,    53,    55,    54,    56,    22,    49,    22,    22,
      27,    26,    22,    48,    51,    48,    52,    28,    31,    22,
      48,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    36,    36,
      38,    37,    39,    37,    40,    40,    40,    40,    42,    41,
      43,    41,    44,    45,    45,    45,    46,    46,    46,    46,
      47,    47,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    59,    59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     0,     4,
       0,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       1,     2,     1,     1,     1,     7,     5,     7,     5,     5,
       3,     1,     2,     1,     4,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     2,     1,     1,     4,
       3,     1,     1,     2,     2,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 50 "1705067.y"
        {
		logout<<"Line "<< line_count<<": start : program "<<endl;
		logout<<endl;
		table->PrintAll(logout);
		errorfile<<"Total error: "<<error_calc<<endl;

		logout<<"Total lines: "<<line_count<<endl;
		logout<<"Total errors: "<<error_calc<<endl;
		
	}
#line 1489 "y.tab.c"
    break;

  case 3:
#line 62 "1705067.y"
                      {
		int i;
		logout<<"Line "<< line_count<<": program : program unit "<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for( i = 0; i < (yyvsp[-1].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-1].vs)->at(i));
			logout<<(yyvsp[-1].vs)->at(i)->getName();
			
		}

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;

		}
#line 1513 "y.tab.c"
    break;

  case 4:
#line 81 "1705067.y"
               {
		logout<< "Line "<< line_count<<": program : unit "<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		
		}
#line 1530 "y.tab.c"
    break;

  case 5:
#line 95 "1705067.y"
                       {
		logout<< "Line "<< line_count<<": unit : var_declaration"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
#line 1547 "y.tab.c"
    break;

  case 6:
#line 107 "1705067.y"
                       {
		logout<< "Line "<< line_count<<": unit : func_declaration"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
#line 1564 "y.tab.c"
    break;

  case 7:
#line 119 "1705067.y"
                      {
		logout<< "Line "<< line_count<<": unit : func_definition"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		}
#line 1580 "y.tab.c"
    break;

  case 8:
#line 132 "1705067.y"
                                                                           {
  			
			int i;
			SymbolInfo *sym = new SymbolInfo();
			SymbolInfo *temp = new SymbolInfo();
			temp = table->lookup((yyvsp[-4].si)->getName());
			if(temp == NULL){
				sym->setName((yyvsp[-4].si)->getName());
				sym->setType((yyvsp[-4].si)->getType());
				string iden = (yyvsp[-5].si)->getName();
				iden.pop_back();
				sym->setIdentity(iden);
				sym->setFunction(1);

				for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
					sym->pushParam((yyvsp[-2].vs)->at(i));
				}
				
				table->insert(sym);
			}
			else{
				errorfile<<"Error at line "<<line_count<<": Multiple declaration of "<<(yyvsp[-4].si)->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple declaration of "<<(yyvsp[-4].si)->getName()<<endl<<endl;
				error_calc++;
			}
			
			
			logout<<"Line "<< line_count<<": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON"<<endl;
			logout<<endl;
			(yyval.vs) = new vector<SymbolInfo*>();

			(yyval.vs)->push_back((yyvsp[-5].si));
			logout<<(yyvsp[-5].si)->getName();

			(yyval.vs)->push_back((yyvsp[-4].si));
			logout<<(yyvsp[-4].si)->getName();

			(yyval.vs)->push_back((yyvsp[-3].si));
			logout<<(yyvsp[-3].si)->getName();

			for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
				(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
				logout<<(yyvsp[-2].vs)->at(i)->getName();
			}

			(yyval.vs)->push_back((yyvsp[-1].si));
			logout<<(yyvsp[-1].si)->getName();
			
			(yyvsp[0].si)->setName((yyvsp[0].si)->getName()+"\n");
			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
			table->enterScope(logout);
			table->exitScope(logout);
		   	}
#line 1640 "y.tab.c"
    break;

  case 9:
#line 187 "1705067.y"
                                                           {

			SymbolInfo *sym = new SymbolInfo();
			SymbolInfo *temp = new SymbolInfo();
			temp = table->lookup((yyvsp[-3].si)->getName());
			if(temp == NULL){
				sym->setName((yyvsp[-3].si)->getName());
				sym->setType((yyvsp[-3].si)->getType());
				string iden = (yyvsp[-4].si)->getName();
				iden.pop_back();
				sym->setIdentity(iden);
				sym->setFunction(1);
				table->insert(sym);
			}
			else{
				errorfile<<"Error at line "<<line_count<<": Multiple declaration of "<<(yyvsp[-3].si)->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple declaration of "<<(yyvsp[-3].si)->getName()<<endl<<endl;
				error_calc++;
			}
			
			

			logout<<"Line "<< line_count<<": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON"<<endl;
			logout<<endl;
			(yyval.vs) = new vector<SymbolInfo*>();

			(yyval.vs)->push_back((yyvsp[-4].si));
			logout<<(yyvsp[-4].si)->getName();

			(yyval.vs)->push_back((yyvsp[-3].si));
			logout<<(yyvsp[-3].si)->getName();

			(yyval.vs)->push_back((yyvsp[-2].si));
			logout<<(yyvsp[-2].si)->getName();
			
			(yyval.vs)->push_back((yyvsp[-1].si));
			logout<<(yyvsp[-1].si)->getName();
			
			(yyvsp[0].si)->setName((yyvsp[0].si)->getName()+"\n");
			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
			table->enterScope(logout);
			table->exitScope(logout);
		   	}
#line 1690 "y.tab.c"
    break;

  case 10:
#line 235 "1705067.y"
        { 
		int i;
		bool match = true;
		bool found;
		SymbolInfo *temp = new SymbolInfo();
		SymbolInfo *sym = new SymbolInfo();
		temp = table->lookup((yyvsp[-3].si)->getName());
		string iden = (yyvsp[-4].si)->getName();
		iden.pop_back();
		if(temp == NULL){
			
			sym->setName((yyvsp[-3].si)->getName());
			sym->setType((yyvsp[-3].si)->getType());
			string iden = (yyvsp[-4].si)->getName();
			iden.pop_back();
			sym->setIdentity(iden);
			sym->setFunction(1);
			sym->setDefined(1);
			for( i = 0; i < (yyvsp[-1].vs)->size(); i++){
				sym->pushParam((yyvsp[-1].vs)->at(i));
			}
			table->insert(sym);
		}
		else{
			if(temp->getFunction() == 0){
				errorfile<<"Error at line "<<line_count<<": Multiple declaration of "<<(yyvsp[-3].si)->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple declaration of "<<(yyvsp[-3].si)->getName()<<endl<<endl;
				error_calc++;
			}
			else {
				if(temp->getDefined() == 1){
					errorfile<<"Error at line "<<line_count<<": Multiple declaration of "<<(yyvsp[-3].si)->getName()<<endl<<endl;
					logout<<"Error at line "<<line_count<<": Multiple declaration of "<<(yyvsp[-3].si)->getName()<<endl<<endl;
					error_calc++;
				}
				else{
					(yyvsp[-3].si)->setIdentity(temp->getIdentity());
					(yyvsp[-3].si)->setFunction(1);
					(yyvsp[-3].si)->setDefined(1);
					for( i = 0; i < temp->returnVector().size(); i++){
						(yyvsp[-3].si)->pushParam(temp->returnVector().at(i));
					}
					found = table->remove(temp->getName());
					if(found){
						table->insert((yyvsp[-3].si));
					}
					
					
					if(temp->getIdentity() != iden){
						errorfile<<"Error at line "<<line_count<<": Return type mismatch with function declaration in function "<<(yyvsp[-3].si)->getName()<<endl<<endl;
						logout<<"Error at line "<<line_count<<": Return type mismatch with function declaration in function "<<(yyvsp[-3].si)->getName()<<endl<<endl;
						error_calc++;
					}

					if((yyvsp[-1].vs)->size() == temp->returnVector().size()){
						for( i = 0; i < temp->returnVector().size(); i++){
						}
						for( i = 0; i < temp->returnVector().size(); i++){
							if((yyvsp[-1].vs)->at(i)->getName() != temp->returnVector().at(i)->getName()){
								errorfile<<"Error at line "<<line_count<<": Total number of arguments mismatch with declaration in function "<<(yyvsp[-3].si)->getName()<<endl<<endl;
								logout<<"Error at line "<<line_count<<": Total number of arguments mismatch with declaration in function "<<(yyvsp[-3].si)->getName()<<endl<<endl;
								error_calc++;
								break;
							}
						}
					}
					else{
						errorfile<<"Error at line "<<line_count<<": Total number of arguments mismatch with declaration in function "<<(yyvsp[-3].si)->getName()<<endl<<endl;
						logout<<"Error at line "<<line_count<<": Total number of arguments mismatch with declaration in function "<<(yyvsp[-3].si)->getName()<<endl<<endl;
						error_calc++;
					}
					
				}
					
			}
		}
		
		for(i = 0; i < (yyvsp[-1].vs)->size(); i++){
			if((yyvsp[-1].vs)->at(i)->getType() == "ID"){
				iden = (yyvsp[-1].vs)->at(i-1)->getName();
				iden.pop_back();
				(yyvsp[-1].vs)->at(i)->setIdentity(iden);
				parameter.push_back((yyvsp[-1].vs)->at(i));
			}
		}
		logout<<endl;
		
	}
#line 1783 "y.tab.c"
    break;

  case 11:
#line 324 "1705067.y"
        {
		int i;
		logout<<"Line "<< line_count<<": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		(yyval.vs)->push_back((yyvsp[-6].si));
		logout<<(yyvsp[-6].si)->getName();

		(yyval.vs)->push_back((yyvsp[-5].si));
		logout<<(yyvsp[-5].si)->getName();

		(yyval.vs)->push_back((yyvsp[-4].si));
		logout<<(yyvsp[-4].si)->getName();
		for(i = 0; i < (yyvsp[-3].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-3].vs)->at(i));
			logout<<(yyvsp[-3].vs)->at(i)->getName();
			
		}
		(yyval.vs)->push_back((yyvsp[-2].si));
		logout<<(yyvsp[-2].si)->getName();
		
		for(i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
			
		}
		logout<<endl;
	}
#line 1817 "y.tab.c"
    break;

  case 12:
#line 354 "1705067.y"
                { 
			SymbolInfo *temp = new SymbolInfo();;
			SymbolInfo *sym = new SymbolInfo();
			temp = table->lookup((yyvsp[-2].si)->getName());
			string iden = (yyvsp[-3].si)->getName();
			iden.pop_back();
			if(temp == NULL){
				sym->setName((yyvsp[-2].si)->getName());
				sym->setType((yyvsp[-2].si)->getType());
				
				sym->setIdentity(iden);
				sym->setFunction(1);
				sym->setDefined(1);
				table->insert(sym);
			}
			else{
				if(temp->getFunction() == 0){
					errorfile<<"Error at line "<<line_count<<": Multiple declaration of "<<(yyvsp[-2].si)->getName()<<endl<<endl;
					logout<<"Error at line "<<line_count<<": Multiple declaration of "<<(yyvsp[-2].si)->getName()<<endl<<endl;
					error_calc++;
				}
				else{
					if(temp->getDefined() == 1){
						errorfile<<"Error at line "<<line_count<<": Multiple declaration of "<<(yyvsp[-2].si)->getName()<<endl<<endl;
						logout<<"Error at line "<<line_count<<": Multiple declaration of "<<(yyvsp[-2].si)->getName()<<endl<<endl;
						error_calc++;
					}
					else{
						(yyvsp[-2].si)->setIdentity(temp->getIdentity());
						(yyvsp[-2].si)->setFunction(1);
						(yyvsp[-2].si)->setDefined(1);
						table->remove(temp->getName());
						table->insert((yyvsp[-2].si));

						if(temp->getIdentity() != iden){
							errorfile<<"Error at line "<<line_count<<": Return type mismatch with function declaration in function "<<(yyvsp[-2].si)->getName()<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Return type mismatch with function declaration in function "<<(yyvsp[-2].si)->getName()<<endl<<endl;
							error_calc++;
						}
					}
				}
				
			}
			
		}
#line 1867 "y.tab.c"
    break;

  case 13:
#line 400 "1705067.y"
                {
			logout<<endl;

			int i;
			logout<<"Line "<< line_count<<": func_definition : type_specifier ID LPAREN RPAREN compound_statement"<<endl;
			logout<<endl;
			(yyval.vs) = new vector<SymbolInfo*>();

			(yyval.vs)->push_back((yyvsp[-5].si));
			logout<<(yyvsp[-5].si)->getName();

			(yyval.vs)->push_back((yyvsp[-4].si));
			logout<<(yyvsp[-4].si)->getName();

			(yyval.vs)->push_back((yyvsp[-3].si));
			logout<<(yyvsp[-3].si)->getName();
			
			(yyval.vs)->push_back((yyvsp[-2].si));
			logout<<(yyvsp[-2].si)->getName();

			for(i = 0; i < (yyvsp[0].vs)->size(); i++){
				(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
				logout<<(yyvsp[0].vs)->at(i)->getName();
		
			}
			logout<<endl;
		   	}
#line 1899 "y.tab.c"
    break;

  case 14:
#line 430 "1705067.y"
                                                        {
			int i;
			(yyval.vs) = new vector<SymbolInfo*>();
			bool error_count = false;
			for( i = 0; i < (yyvsp[-3].vs)->size(); i++){
				if((yyvsp[-3].vs)->at(i)->getType() == "Error"){
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					(yyval.vs)->push_back(point);
				}
			}
			if(error_count == false && (yyvsp[-1].si)->getType() == "VOID"){
				errorfile<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
			
			SymbolInfo *temp = new SymbolInfo();
			for(i = 0; i < (yyvsp[-3].vs)->size(); i++){
				if((yyvsp[-3].vs)->at(i)->getType() == "ID" && (yyvsp[-3].vs)->at(i)->getName() == (yyvsp[0].si)->getName() && error_count == false){
					errorfile<<"Error at line "<<line_count<<": Multiple Declaration of "<<(yyvsp[0].si)->getName()<<" in parameter"<<endl<<endl;
				 	logout<<"Error at line "<<line_count<<": Multiple Declaration of "<<(yyvsp[0].si)->getName()<<" in parameter"<<endl<<endl;
					error_calc++;
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					(yyval.vs)->push_back(point);
					break;
				}
			}
			
			logout<<"Line "<< line_count<<": parameter_list  : parameter_list COMMA type_specifier ID"<<endl;
			logout<<endl;
			

			for(i = 0; i < (yyvsp[-3].vs)->size(); i++){
				(yyval.vs)->push_back((yyvsp[-3].vs)->at(i));
				logout<<(yyvsp[-3].vs)->at(i)->getName();
			}

			(yyval.vs)->push_back((yyvsp[-2].si));
			logout<<(yyvsp[-2].si)->getName();

			(yyval.vs)->push_back((yyvsp[-1].si));
			logout<<(yyvsp[-1].si)->getName();
			
			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
		   	}
#line 1959 "y.tab.c"
    break;

  case 15:
#line 485 "1705067.y"
                                                     {
			int i;
			(yyval.vs) = new vector<SymbolInfo*>();
			bool error_count = false;
			for( i = 0; i < (yyvsp[-2].vs)->size(); i++){
				if((yyvsp[-2].vs)->at(i)->getType() == "Error"){
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					(yyval.vs)->push_back(point);
				}
			}
			if(error_count == false && (yyvsp[0].si)->getType() == "VOID"){
				errorfile<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
			logout<<"Line "<< line_count<<": parameter_list  : parameter_list COMMA type_specifier"<<endl;
			logout<<endl;

			for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
				(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
				logout<<(yyvsp[-2].vs)->at(i)->getName();
			}

			(yyval.vs)->push_back((yyvsp[-1].si));
			logout<<(yyvsp[-1].si)->getName();

			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
		   	}
#line 2000 "y.tab.c"
    break;

  case 16:
#line 521 "1705067.y"
                                   {
			(yyval.vs) = new vector<SymbolInfo*>();
			bool error_count = false;
			
			if(error_count == false && (yyvsp[-1].si)->getType() == "VOID"){
				errorfile<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
			logout<<"Line "<< line_count<<": parameter_list  : type_specifier ID"<<endl;
			logout<<endl;

			(yyval.vs)->push_back((yyvsp[-1].si));
			logout<<(yyvsp[-1].si)->getName();

			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
		   	}
#line 2028 "y.tab.c"
    break;

  case 17:
#line 544 "1705067.y"
                                {
			(yyval.vs) = new vector<SymbolInfo*>();
			bool error_count = false;
			
			if(error_count == false && (yyvsp[0].si)->getType() == "VOID"){
				errorfile<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
			logout<<"Line "<< line_count<<": parameter_list  : type_specifier"<<endl;
			logout<<endl;

			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
		   	}
#line 2053 "y.tab.c"
    break;

  case 18:
#line 568 "1705067.y"
                        {
				int i;
				table->enterScope(logout); 
				if(parameter.size() != 0){
					for(i = 0; i < parameter.size(); i++){
						table->insert(parameter.at(i));
					}
					logout<<endl;
				}
				parameter.clear();
				
			}
#line 2070 "y.tab.c"
    break;

  case 19:
#line 580 "1705067.y"
                                         {
			logout<<"Line "<< line_count<<": compound_statement : LCURL statements RCURL"<<endl;
			logout<<endl;
			(yyval.vs) = new vector<SymbolInfo*>();

			(yyvsp[-3].si)->setName((yyvsp[-3].si)->getName()+"\n");
			(yyval.vs)->push_back((yyvsp[-3].si));
			logout<<(yyvsp[-3].si)->getName()<<endl;

			for(int i = 0; i < (yyvsp[-1].vs)->size(); i++){
				(yyval.vs)->push_back((yyvsp[-1].vs)->at(i));
				logout<<(yyvsp[-1].vs)->at(i)->getName();
			}

			(yyvsp[0].si)->setName((yyvsp[0].si)->getName()+"\n");
			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;

			table->PrintAll(logout);
			table->exitScope(logout);

		   	}
#line 2098 "y.tab.c"
    break;

  case 20:
#line 604 "1705067.y"
                        {
				int i;
				table->enterScope(logout); 
				if(parameter.size() != 0){
					for(i = 0; i < parameter.size(); i++){
						table->insert(parameter.at(i));
					}
					logout<<endl;
				}
				parameter.clear();
				
			}
#line 2115 "y.tab.c"
    break;

  case 21:
#line 616 "1705067.y"
                              {
			logout<<"Line "<< line_count<<": compound_statement : LCURL RCURL"<<endl;
			logout<<endl;
			(yyval.vs) = new vector<SymbolInfo*>();

			(yyvsp[-2].si)->setName((yyvsp[-2].si)->getName()+"\n");
			(yyval.vs)->push_back((yyvsp[-2].si));
			logout<<(yyvsp[-2].si)->getName()<<endl;

			(yyvsp[0].si)->setName((yyvsp[0].si)->getName()+"\n");
			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;

			table->PrintAll(logout);
			table->exitScope(logout);
		   	}
#line 2137 "y.tab.c"
    break;

  case 22:
#line 635 "1705067.y"
                                                            { 
			bool error_count = false;
			int i;
			(yyval.vs) = new vector<SymbolInfo*>();
			logout<<"Line "<< line_count<<": var_declaration : type_specifier declaration_list SEMICOLON " <<endl;
			logout<<endl;
			for( i = 0; i < (yyvsp[-1].vs)->size(); i++){
				if((yyvsp[-1].vs)->at(i)->getType() == "Error"){
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					(yyval.vs)->push_back(point);
				}
			}
			if((yyvsp[-2].si)->getType() == "VOID" && error_count == false){
				errorfile<<"Error at line "<<line_count<<": Variable type cannot be void "<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Variable type cannot be void "<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
			

			(yyval.vs)->push_back((yyvsp[-2].si));
			logout<<(yyvsp[-2].si)->getName();

			SymbolInfo *temp = new SymbolInfo();;
			SymbolInfo *sym = new SymbolInfo();

			string iden;

			for( i = 0; i < (yyvsp[-1].vs)->size(); i++){
				(yyval.vs)->push_back((yyvsp[-1].vs)->at(i));
				logout<<(yyvsp[-1].vs)->at(i)->getName();
				if((yyvsp[-1].vs)->at(i)->getType() == "ID")
				{	
					temp = table->getCurrScope()->lookup((yyvsp[-1].vs)->at(i)->getName());
					if(temp == NULL && (yyvsp[-2].si)->getType() != "VOID" ){
						iden = (yyvsp[-2].si)->getName();
						iden.pop_back();
						(yyvsp[-1].vs)->at(i)->setIdentity(iden);
						if( (i+1)<(yyvsp[-1].vs)->size() && (i+3)<(yyvsp[-1].vs)->size() && (yyvsp[-1].vs)->at(i+1)->getType() == "LTHIRD" && (yyvsp[-1].vs)->at(i+3)->getType() == "RTHIRD"){
							(yyvsp[-1].vs)->at(i)->setArray(1);
							(yyvsp[-1].vs)->at(i)->setFunction(0);
						}
						else{
							(yyvsp[-1].vs)->at(i)->setArray(0);
							(yyvsp[-1].vs)->at(i)->setFunction(0);
						}
						sym->setName((yyvsp[-1].vs)->at(i)->getName());
						sym->setType((yyvsp[-1].vs)->at(i)->getType());
						sym->setIdentity((yyvsp[-1].vs)->at(i)->getIdentity());
						sym->setArray((yyvsp[-1].vs)->at(i)->getArray());
						table->insert(sym);
					}
					
				}
			}

			(yyvsp[0].si)->setName((yyvsp[0].si)->getName()+"\n");
			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
			}
#line 2208 "y.tab.c"
    break;

  case 23:
#line 703 "1705067.y"
                      { 
			logout<<"Line "<< line_count<<": type_specifier : INT"<<endl;
			logout<<endl;

			(yyvsp[0].si)->setName((yyvsp[0].si)->getName()+" ");
			logout<<(yyvsp[0].si)->getName() <<endl;
			(yyval.si) =(yyvsp[0].si);

			logout<<endl;
			}
#line 2223 "y.tab.c"
    break;

  case 24:
#line 713 "1705067.y"
                        { 
			logout<< "Line "<<  line_count<<": type_specifier : FLOAT"<<endl;
			logout<<endl;

			(yyvsp[0].si)->setName((yyvsp[0].si)->getName()+" ");
			logout<<(yyvsp[0].si)->getName() <<endl;
			(yyval.si) =(yyvsp[0].si);

			logout<<endl;
			}
#line 2238 "y.tab.c"
    break;

  case 25:
#line 723 "1705067.y"
                       { 
			logout<< "Line "<< line_count<<": type_specifier : VOID" <<endl;
			logout<<endl;

			(yyvsp[0].si)->setName((yyvsp[0].si)->getName()+" ");
			logout<<(yyvsp[0].si)->getName() <<endl;
			(yyval.si) =(yyvsp[0].si);

			logout<<endl;
			}
#line 2253 "y.tab.c"
    break;

  case 26:
#line 735 "1705067.y"
                                            {
			bool error_count = false;
			SymbolInfo *temp;
			temp = table->getCurrScope()->lookup((yyvsp[0].si)->getName());
			if(temp != NULL){
				errorfile<<"Error at line "<<line_count<<": Multiple Declaration of "<<(yyvsp[0].si)->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple Declaration of "<<(yyvsp[0].si)->getName()<<endl<<endl;
				error_calc++;
				error_count = true;
			}

			logout<< "Line "<< line_count<<": declaration_list : declaration_list COMMA ID"<<endl;
			logout<<endl;
			(yyval.vs) = new vector<SymbolInfo*>();

			if(error_count == true){
				SymbolInfo *temp1 = new SymbolInfo();
				temp1->setType("Error");
				(yyval.vs)->push_back(temp1);
			}

			for(int i = 0; i < (yyvsp[-2].vs)->size(); i++){
				(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
				logout<<(yyvsp[-2].vs)->at(i)->getName();
			}

			(yyval.vs)->push_back((yyvsp[-1].si));
			logout<<(yyvsp[-1].si)->getName();

			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
			}
#line 2291 "y.tab.c"
    break;

  case 27:
#line 768 "1705067.y"
                                                                     {
			bool error_count = false;
			SymbolInfo *temp;
			temp = table->getCurrScope()->lookup((yyvsp[-3].si)->getName());
			if(temp != NULL){
				errorfile<<"Error at line "<<line_count<<": Multiple Declaration of "<<(yyvsp[-3].si)->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple Declaration of "<<(yyvsp[-3].si)->getName()<<endl<<endl;
				error_calc++;
				error_count = true;
			}

			logout<< "Line "<< line_count<<": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"<<endl;
			logout<<endl;
			(yyval.vs) = new vector<SymbolInfo*>();

			if(error_count == true){
				SymbolInfo *temp1 = new SymbolInfo();
				temp1->setType("Error");
				(yyval.vs)->push_back(temp1);
			}

			for(int i = 0; i < (yyvsp[-5].vs)->size(); i++){
				(yyval.vs)->push_back((yyvsp[-5].vs)->at(i));
				logout<<(yyvsp[-5].vs)->at(i)->getName();
			}

			(yyval.vs)->push_back((yyvsp[-4].si));
			logout<<(yyvsp[-4].si)->getName();

			(yyval.vs)->push_back((yyvsp[-3].si));
			logout<<(yyvsp[-3].si)->getName();

			(yyval.vs)->push_back((yyvsp[-2].si));
			logout<<(yyvsp[-2].si)->getName();

			(yyval.vs)->push_back((yyvsp[-1].si));
			logout<<(yyvsp[-1].si)->getName();

			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
			}
#line 2338 "y.tab.c"
    break;

  case 28:
#line 810 "1705067.y"
                       { 
			bool error_count = false;
			SymbolInfo *temp = new SymbolInfo();
			temp = table->getCurrScope()->lookup((yyvsp[0].si)->getName());
			if(temp != NULL){
				errorfile<<"Error at line "<<line_count<<": Multiple Declaration of "<<(yyvsp[0].si)->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple Declaration of "<<(yyvsp[0].si)->getName()<<endl<<endl;
				error_calc++;
				error_count = true;
			}

 		  	logout<< "Line "<< line_count<<": declaration_list : ID"<<endl;
			logout<<endl;
			(yyval.vs) = new vector<SymbolInfo*>();

			if(error_count == true){
				SymbolInfo *temp1 = new SymbolInfo();
				temp1->setType("Error");
				(yyval.vs)->push_back(temp1);
			}

			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName() <<endl;
			logout<<endl;
			}
#line 2368 "y.tab.c"
    break;

  case 29:
#line 835 "1705067.y"
                                              {
			bool error_count = false;
			SymbolInfo *temp = new SymbolInfo();
			temp = table->getCurrScope()->lookup((yyvsp[-3].si)->getName());
			if(temp != NULL){
				errorfile<<"Error at line "<<line_count<<": Multiple Declaration of "<<(yyvsp[-3].si)->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple Declaration of "<<(yyvsp[-3].si)->getName()<<endl<<endl;
				error_calc++;
				error_count = true;
			}

			logout<<"Line "<< line_count<<": declaration_list : ID LTHIRD CONST_INT RTHIRD"<<endl;
			logout<<endl;
			(yyval.vs) = new vector<SymbolInfo*>();

			if(error_count == true){
				SymbolInfo *temp1 = new SymbolInfo();
				temp1->setType("Error");
				(yyval.vs)->push_back(temp1);
			}

			(yyval.vs)->push_back((yyvsp[-3].si));
			logout<<(yyvsp[-3].si)->getName();

			(yyval.vs)->push_back((yyvsp[-2].si));
			logout<<(yyvsp[-2].si)->getName();

			(yyval.vs)->push_back((yyvsp[-1].si));
			logout<<(yyvsp[-1].si)->getName();

			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
		   	}
#line 2407 "y.tab.c"
    break;

  case 30:
#line 871 "1705067.y"
                      {
		logout<< "Line "<< line_count<<": statements : statement"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
#line 2425 "y.tab.c"
    break;

  case 31:
#line 884 "1705067.y"
                                 {
		int i;
		logout<< "Line "<< line_count<<": statements : statements statement"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for( i = 0; i < (yyvsp[-1].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-1].vs)->at(i));
			logout<<(yyvsp[-1].vs)->at(i)->getName();
			
		}

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
#line 2450 "y.tab.c"
    break;

  case 32:
#line 906 "1705067.y"
                           {
		logout<< "Line "<< line_count<<": statement : var_declaration"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
#line 2468 "y.tab.c"
    break;

  case 33:
#line 919 "1705067.y"
                                {
		logout<< "Line "<< line_count<<": statement : expression_statement"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
#line 2485 "y.tab.c"
    break;

  case 34:
#line 931 "1705067.y"
                              {
		logout<< "Line "<< line_count<<": statement : compound_statement"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
			
		}
		logout<<endl;
		}
#line 2502 "y.tab.c"
    break;

  case 35:
#line 943 "1705067.y"
                                                                                            {
		int i;
		logout<< "Line "<< line_count<<": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		(yyval.vs)->push_back((yyvsp[-6].si));
		logout<<(yyvsp[-6].si)->getName();

		(yyval.vs)->push_back((yyvsp[-5].si));
		logout<<(yyvsp[-5].si)->getName();

		for(i = 0; i < (yyvsp[-4].vs)->size(); i++){	
			if((yyvsp[-4].vs)->at(i)->getType() == "SEMICOLON"){
				(yyvsp[-4].vs)->at(i)->setName(";");
			}
			(yyval.vs)->push_back((yyvsp[-4].vs)->at(i));
			logout<<(yyvsp[-4].vs)->at(i)->getName();
		}

		for(i = 0; i < (yyvsp[-3].vs)->size(); i++){
			if((yyvsp[-3].vs)->at(i)->getType() == "SEMICOLON"){
				(yyvsp[-3].vs)->at(i)->setName(";");
			}
			(yyval.vs)->push_back((yyvsp[-3].vs)->at(i));
			logout<<(yyvsp[-3].vs)->at(i)->getName();
		}
		
		for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
			logout<<(yyvsp[-2].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[-1].si));
		logout<<(yyvsp[-1].si)->getName();

		for(i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
#line 2551 "y.tab.c"
    break;

  case 36:
#line 987 "1705067.y"
                                                                       {
		int i;
		logout<< "Line "<< line_count<<": statement : IF LPAREN expression RPAREN statement"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		(yyvsp[-4].si)->setName((yyvsp[-4].si)->getName()+" ");
		(yyval.vs)->push_back((yyvsp[-4].si));
		logout<<(yyvsp[-4].si)->getName();

		(yyval.vs)->push_back((yyvsp[-3].si));
		logout<<(yyvsp[-3].si)->getName();

		for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
			logout<<(yyvsp[-2].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[-1].si));
		logout<<(yyvsp[-1].si)->getName();

		for(i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
#line 2585 "y.tab.c"
    break;

  case 37:
#line 1016 "1705067.y"
                                                                {
		int i;
		logout<< "Line "<< line_count<<": statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();
		
		(yyvsp[-6].si)->setName((yyvsp[-6].si)->getName()+" ");
		(yyval.vs)->push_back((yyvsp[-6].si));
		logout<<(yyvsp[-6].si)->getName();

		(yyval.vs)->push_back((yyvsp[-5].si));
		logout<<(yyvsp[-5].si)->getName();

		for(i = 0; i < (yyvsp[-4].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-4].vs)->at(i));
			logout<<(yyvsp[-4].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[-3].si));
		logout<<(yyvsp[-3].si)->getName();

		for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
			logout<<(yyvsp[-2].vs)->at(i)->getName();
			
		}

		(yyvsp[-1].si)->setName((yyvsp[-1].si)->getName()+"\n");
		(yyval.vs)->push_back((yyvsp[-1].si));
		logout<<(yyvsp[-1].si)->getName();

		for(i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
#line 2629 "y.tab.c"
    break;

  case 38:
#line 1055 "1705067.y"
                                                    {
		int i;
		logout<< "Line "<< line_count<<": statement : WHILE LPAREN expression RPAREN statement"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		(yyvsp[-4].si)->setName((yyvsp[-4].si)->getName()+" ");
		(yyval.vs)->push_back((yyvsp[-4].si));
		logout<<(yyvsp[-4].si)->getName();

		(yyval.vs)->push_back((yyvsp[-3].si));
		logout<<(yyvsp[-3].si)->getName();

		for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
			logout<<(yyvsp[-2].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[-1].si));
		logout<<(yyvsp[-1].si)->getName();

		for(i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
#line 2663 "y.tab.c"
    break;

  case 39:
#line 1084 "1705067.y"
                                              {
			logout<<"Line "<< line_count<<": statement : PRINTLN LPAREN ID RPAREN SEMICOLON"<<endl;
			logout<<endl;
			(yyval.vs) = new vector<SymbolInfo*>();

			SymbolInfo *temp = new SymbolInfo();
			temp = table->lookup((yyvsp[-2].si)->getName());
			if(temp == NULL){
				errorfile<<"Error at line "<<line_count<<": Undeclared variable "<<(yyvsp[-2].si)->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Undeclared variable "<<(yyvsp[-2].si)->getName()<<endl<<endl;
				error_calc++;
			}

			(yyval.vs)->push_back((yyvsp[-4].si));
			logout<<(yyvsp[-4].si)->getName();

			(yyval.vs)->push_back((yyvsp[-3].si));
			logout<<(yyvsp[-3].si)->getName();

			(yyval.vs)->push_back((yyvsp[-2].si));
			logout<<(yyvsp[-2].si)->getName();

			(yyval.vs)->push_back((yyvsp[-1].si));
			logout<<(yyvsp[-1].si)->getName();
			
			(yyvsp[0].si)->setName((yyvsp[0].si)->getName()+"\n");
			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
		   	}
#line 2698 "y.tab.c"
    break;

  case 40:
#line 1114 "1705067.y"
                                       {
			logout<<"Line "<< line_count<<": statement : RETURN expression SEMICOLON"<<endl;
			logout<<endl;
			(yyval.vs) = new vector<SymbolInfo*>();

			(yyvsp[-2].si)->setName((yyvsp[-2].si)->getName()+" ");
			(yyval.vs)->push_back((yyvsp[-2].si));
			logout<<(yyvsp[-2].si)->getName();

			for(int i = 0; i < (yyvsp[-1].vs)->size(); i++){
				(yyval.vs)->push_back((yyvsp[-1].vs)->at(i));
				logout<<(yyvsp[-1].vs)->at(i)->getName();
			}

			(yyvsp[0].si)->setName((yyvsp[0].si)->getName()+"\n");
			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
		   	}
#line 2722 "y.tab.c"
    break;

  case 41:
#line 1135 "1705067.y"
                                   { 
		logout<< "Line "<< line_count<<": expression_statement 	: SEMICOLON"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		(yyvsp[0].si)->setName((yyvsp[0].si)->getName()+"\n");
		(yyval.vs)->push_back((yyvsp[0].si));
		logout<<(yyvsp[0].si)->getName() <<endl;
		logout<<endl;
		}
#line 2737 "y.tab.c"
    break;

  case 42:
#line 1145 "1705067.y"
                                      {

			logout<< "Line "<< line_count<<": expression_statement 	: expression SEMICOLON"<<endl;
			logout<<endl;
			(yyval.vs) = new vector<SymbolInfo*>();

			for(int i = 0; i < (yyvsp[-1].vs)->size(); i++){
				(yyval.vs)->push_back((yyvsp[-1].vs)->at(i));
				logout<<(yyvsp[-1].vs)->at(i)->getName();
			}

			(yyvsp[0].si)->setName((yyvsp[0].si)->getName()+"\n");
			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
		}
#line 2758 "y.tab.c"
    break;

  case 43:
#line 1163 "1705067.y"
             { 
		logout<< "Line "<< line_count<<": variable : ID"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();
		bool error_count = false;
		SymbolInfo *temp = new SymbolInfo();
		temp = table->lookup((yyvsp[0].si)->getName());
		if(temp == NULL){
			errorfile<<"Error at line "<<line_count<<": Undeclared variable "<<(yyvsp[0].si)->getName()<<endl<<endl;
			logout<<"Error at line "<<line_count<<": Undeclared variable "<<(yyvsp[0].si)->getName()<<endl<<endl;
			error_calc++;
			error_count = true;
			SymbolInfo *point = new SymbolInfo();
			point->setType("Error");
			(yyval.vs)->push_back(point);
		}
		else {
			if(temp->getArray() == 1){
				errorfile<<"Error at line "<<line_count<<": Type mismatch, "<<(yyvsp[0].si)->getName()<<" is an array"<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Type mismatch, "<<(yyvsp[0].si)->getName()<<" is an array"<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);	
			}
		}

		(yyval.vs)->push_back((yyvsp[0].si));
		logout<<(yyvsp[0].si)->getName() <<endl;
		logout<<endl;
		}
#line 2795 "y.tab.c"
    break;

  case 44:
#line 1195 "1705067.y"
                                      {
		 	int i;
			(yyval.vs) = new vector<SymbolInfo*>();
			bool error_count = false;
			logout<< "Line "<< line_count<<": variable : ID LTHIRD expression RTHIRD"<<endl;
			logout<<endl;
			for( i = 0; i < (yyvsp[-1].vs)->size(); i++){
				if((yyvsp[-1].vs)->at(i)->getType() == "Error"){
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					(yyval.vs)->push_back(point);
				}
			}

			SymbolInfo *temp = new SymbolInfo();
			temp = table->lookup((yyvsp[-3].si)->getName());
			if(temp == NULL){
				if(error_count == false){
					errorfile<<"Error at line "<<line_count<<": Undeclared variable "<<(yyvsp[-3].si)->getName()<<endl<<endl;
					logout<<"Error at line "<<line_count<<": Undeclared variable "<<(yyvsp[-3].si)->getName()<<endl<<endl;
					error_calc++;
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					(yyval.vs)->push_back(point);
				}
				
			}
			else {
				if(temp->getArray() == 0 && error_count == false){
					errorfile<<"Error at line "<<line_count<<": "<<(yyvsp[-3].si)->getName()<<" is not an array"<<endl<<endl;
					logout<<"Error at line "<<line_count<<": "<<(yyvsp[-3].si)->getName()<<" is not an array"<<endl<<endl;	
					error_calc++;
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					(yyval.vs)->push_back(point);
				}
			}
			for(i = 0; i < (yyvsp[-1].vs)->size(); i++){
				if((yyvsp[-1].vs)->at(i)->getType() == "ID"){
					temp = table->lookup((yyvsp[-1].vs)->at(i)->getName());
					if(temp->getIdentity() != "int" && error_count == false){
						errorfile<<"Error at line "<<line_count<<": Expression inside third brackets not an integer"<<endl<<endl;
						logout<<"Error at line "<<line_count<<": Expression inside third brackets not an integer"<<endl<<endl;
						error_calc++;
						error_count = true;
						SymbolInfo *point = new SymbolInfo();
						point->setType("Error");
						(yyval.vs)->push_back(point);
						break;
					}
				}
				if((yyvsp[-1].vs)->at(i)->getType() == "CONST_FLOAT"  && error_count == false){
					errorfile<<"Error at line "<<line_count<<": Expression inside third brackets not an integer"<<endl<<endl;
					logout<<"Error at line "<<line_count<<": Expression inside third brackets not an integer"<<endl<<endl;
					error_calc++;
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					(yyval.vs)->push_back(point);
					break;
				}
			}

			(yyval.vs)->push_back((yyvsp[-3].si));
			logout<<(yyvsp[-3].si)->getName();

			(yyval.vs)->push_back((yyvsp[-2].si));
			logout<<(yyvsp[-2].si)->getName();

			for(i = 0; i < (yyvsp[-1].vs)->size(); i++){
				(yyval.vs)->push_back((yyvsp[-1].vs)->at(i));
				logout<<(yyvsp[-1].vs)->at(i)->getName();
			}

			(yyval.vs)->push_back((yyvsp[0].si));
			logout<<(yyvsp[0].si)->getName()<<endl;
			logout<<endl;
		}
#line 2881 "y.tab.c"
    break;

  case 45:
#line 1278 "1705067.y"
                             {
		logout<< "Line "<< line_count<<": expression : logic_expression"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		
		}
#line 2899 "y.tab.c"
    break;

  case 46:
#line 1291 "1705067.y"
                                               {
		int i,j;
		(yyval.vs) = new vector<SymbolInfo*>();
		bool error_count = false;
		logout<< "Line "<< line_count<<": expression : variable ASSIGNOP logic_expression"<<endl;
		logout<<endl;

		for( i = 0; i < (yyvsp[-2].vs)->size(); i++){
			if((yyvsp[-2].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}

		SymbolInfo *temp = new SymbolInfo();
		SymbolInfo *temp2 = new SymbolInfo();
		for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
			if((yyvsp[-2].vs)->at(i)->getType() == "ID"){
				temp = table->lookup((yyvsp[-2].vs)->at(i)->getName());
				if(temp != NULL && temp->getArray() == 1){
					if((i+1)< (yyvsp[-2].vs)->size() && (yyvsp[-2].vs)->at(i+1)->getType() == "LTHIRD"){
						while((yyvsp[-2].vs)->at(i)->getType() != "RTHIRD"){
							i++;
						}
					}
					
				}
				for(j = 0; j < (yyvsp[0].vs)->size(); j++){
					if(temp != NULL && temp->getIdentity() == "int"){
						if((yyvsp[0].vs)->at(j)->getType() == "CONST_FLOAT" && error_count == false){
							if((yyvsp[0].vs)->at(j)->getIdentity() == "INTEGER"){
								continue;
							}
							errorfile<<"Error at line "<<line_count<<": Type Mismatch "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Type Mismatch "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							(yyval.vs)->push_back(point);
							break;
						}
						if((yyvsp[0].vs)->at(j)->getType() == "ID"){
							if((yyvsp[0].vs)->at(j)->getIdentity() == "INTEGER"){
								continue;
							}
							temp2 = table->lookup((yyvsp[0].vs)->at(j)->getName());

							if(temp2 != NULL && temp2->getArray() == 1){
								if((j+1)< (yyvsp[0].vs)->size() && (yyvsp[0].vs)->at(j+1)->getType() == "LTHIRD"){
									while((yyvsp[0].vs)->at(j)->getType() != "RTHIRD"){
										j++;
									}
								}
								
							}
							else if(temp2 != NULL && temp2->getFunction() == 1){
								if((j+1)< (yyvsp[0].vs)->size() && (yyvsp[0].vs)->at(j+1)->getType() == "LPAREN"){
									while((yyvsp[0].vs)->at(j)->getType() != "RPAREN"){
										j++;
									}
								}
								
							}

							if(temp2 != NULL && temp2->getIdentity() == "void"){
								if( error_count == false){
									errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
									logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
									error_calc++;
									error_count = true;
									SymbolInfo *point = new SymbolInfo();
									point->setType("Error");
									(yyval.vs)->push_back(point);
									break;
								}
								
							}
							else if(temp2 != NULL && temp2->getIdentity() != "int"){
								if( error_count == false){
									errorfile<<"Error at line "<<line_count<<": Type Mismatch "<<endl<<endl;
									logout<<"Error at line "<<line_count<<": Type Mismatch "<<endl<<endl;
									error_calc++;
									error_count = true;
									SymbolInfo *point = new SymbolInfo();
									point->setType("Error");
									(yyval.vs)->push_back(point);
									break;
								}
								
							}
						}
						
					}
					else if(temp != NULL && temp->getIdentity() == "float"){
						if((yyvsp[0].vs)->at(j)->getType() == "CONST_INT" && error_count == false){
							if((yyvsp[0].vs)->at(j)->getIdentity() == "INTEGER"){
								continue;
							}
							
						}
						if((yyvsp[0].vs)->at(j)->getType() == "ID"){
							if((yyvsp[0].vs)->at(j)->getIdentity() == "INTEGER"){
								continue;
							}
							temp2 = table->lookup((yyvsp[0].vs)->at(j)->getName());

							if(temp2 != NULL && temp2->getArray() == 1){
								if((j+1)< (yyvsp[0].vs)->size() && (yyvsp[0].vs)->at(j+1)->getType() == "LTHIRD"){
									while((yyvsp[0].vs)->at(j)->getType() != "RTHIRD"){
										j++;
									}
								}
							}
							else if(temp2 != NULL && temp2->getFunction() == 1){
								if((j+1)< (yyvsp[0].vs)->size() && (yyvsp[0].vs)->at(j+1)->getType() == "LPAREN"){
									while((yyvsp[0].vs)->at(j)->getType() != "RPAREN"){
										j++;
									}
								}
								
							}

							if(temp2 != NULL && temp2->getIdentity() == "void"){
								if(error_count == false){
									errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
									logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
									error_calc++;
									error_count = true;
									SymbolInfo *point = new SymbolInfo();
									point->setType("Error");
									(yyval.vs)->push_back(point);
									break;
								}
								
							}
							else if(temp2 != NULL && temp2->getIdentity() != "float"){
								if(error_count == false){
									if(temp2->getIdentity() != "int"){
										
										errorfile<<"Error at line "<<line_count<<": Type Mismatch "<<endl<<endl;
										logout<<"Error at line "<<line_count<<": Type Mismatch "<<endl<<endl;
										error_calc++;
										error_count = true;
										SymbolInfo *point = new SymbolInfo();
										point->setType("Error");
										(yyval.vs)->push_back(point);
										break;
									}
									
								}
								
							}
						}
						
					}
				}
			}
		}

		

		for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
			logout<<(yyvsp[-2].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[-1].si));
		logout<<(yyvsp[-1].si)->getName();

		for(i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
#line 3093 "y.tab.c"
    break;

  case 47:
#line 1482 "1705067.y"
                                 {
		logout<< "Line "<< line_count<<": logic_expression : rel_expression"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		
		}
#line 3111 "y.tab.c"
    break;

  case 48:
#line 1495 "1705067.y"
                                                       {
		 int i;
		 (yyval.vs) = new vector<SymbolInfo*>();
		 bool error_count = false;

		

		for( i = 0; i < (yyvsp[-2].vs)->size(); i++){
			if((yyvsp[-2].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}
		SymbolInfo *temp = new SymbolInfo();

		for( i = 0; i < (yyvsp[-2].vs)->size(); i++){
			if((yyvsp[-2].vs)->at(i)->getType() == "ID"){
				temp = table->lookup((yyvsp[-2].vs)->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							(yyval.vs)->push_back(point);
						}
					}
				}
				
			}
		}

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "ID"){
				temp = table->lookup((yyvsp[0].vs)->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							(yyval.vs)->push_back(point);
						}
					}
				}
				
			}
		}
		

		logout<< "Line "<< line_count<<": logic_expression : rel_expression LOGICOP rel_expression"<<endl;
		logout<<endl;

		for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
			(yyvsp[-2].vs)->at(i)->setIdentity("INTEGER");
			(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
			logout<<(yyvsp[-2].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[-1].si));
		logout<<(yyvsp[-1].si)->getName();

		for(i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyvsp[0].vs)->at(i)->setIdentity("INTEGER");
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
#line 3204 "y.tab.c"
    break;

  case 49:
#line 1585 "1705067.y"
                                   {
		logout<< "Line "<< line_count<<": rel_expression	: simple_expression"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		
		}
#line 3222 "y.tab.c"
    break;

  case 50:
#line 1598 "1705067.y"
                                                           {
		int i;
		(yyval.vs) = new vector<SymbolInfo*>();
		bool error_count = false;

		for( i = 0; i < (yyvsp[-2].vs)->size(); i++){
			if((yyvsp[-2].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}
		SymbolInfo *temp = new SymbolInfo();

		for( i = 0; i < (yyvsp[-2].vs)->size(); i++){
			if((yyvsp[-2].vs)->at(i)->getType() == "ID"){
				temp = table->lookup((yyvsp[-2].vs)->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							(yyval.vs)->push_back(point);
						}
					}
				}
				
			}
		}

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "ID"){
				temp = table->lookup((yyvsp[0].vs)->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							(yyval.vs)->push_back(point);
						}
					}
				}
				
			}
		}
				 
		logout<< "Line "<< line_count<<": rel_expression	: simple_expression RELOP simple_expression"<<endl;
		logout<<endl;

		for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
			(yyvsp[-2].vs)->at(i)->setIdentity("INTEGER");
			(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
			logout<<(yyvsp[-2].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[-1].si));
		logout<<(yyvsp[-1].si)->getName();

		for(i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyvsp[0].vs)->at(i)->setIdentity("INTEGER");
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
#line 3312 "y.tab.c"
    break;

  case 51:
#line 1685 "1705067.y"
                        {
		logout<< "Line "<< line_count<<": simple_expression : term"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
#line 3330 "y.tab.c"
    break;

  case 52:
#line 1698 "1705067.y"
                                              {
		int i;
		(yyval.vs) = new vector<SymbolInfo*>();
		bool error_count = false;

		

		for( i = 0; i < (yyvsp[-2].vs)->size(); i++){
			if((yyvsp[-2].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}
		SymbolInfo *temp = new SymbolInfo();

		for( i = 0; i < (yyvsp[-2].vs)->size(); i++){
			if((yyvsp[-2].vs)->at(i)->getType() == "ID"){
				temp = table->lookup((yyvsp[-2].vs)->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							(yyval.vs)->push_back(point);
						}
					}
				}
				
			}
		}

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "ID"){
				temp = table->lookup((yyvsp[0].vs)->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							(yyval.vs)->push_back(point);
						}
					}
				}
				
			}
		}
		

		logout<< "Line "<< line_count<<": simple_expression : simple_expression ADDOP term"<<endl;
		logout<<endl;
		

		for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
			logout<<(yyvsp[-2].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[-1].si));
		logout<<(yyvsp[-1].si)->getName();

		for(i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
#line 3422 "y.tab.c"
    break;

  case 53:
#line 1787 "1705067.y"
                        {
		logout<< "Line "<< line_count<<": term :	unary_expression"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
#line 3440 "y.tab.c"
    break;

  case 54:
#line 1800 "1705067.y"
                                   {
		int i;
		(yyval.vs) = new vector<SymbolInfo*>();
		bool error_count = false;

		for( i = 0; i < (yyvsp[-2].vs)->size(); i++){
			if((yyvsp[-2].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}
		SymbolInfo *temp = new SymbolInfo();

		for( i = 0; i < (yyvsp[-2].vs)->size(); i++){
			if((yyvsp[-2].vs)->at(i)->getType() == "ID"){
				temp = table->lookup((yyvsp[-2].vs)->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							(yyval.vs)->push_back(point);
						}
					}
				}
				
			}
		}

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "ID"){
				temp = table->lookup((yyvsp[0].vs)->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							(yyval.vs)->push_back(point);
						}
					}
				}
				
			}
		}

		logout<< "Line "<< line_count<<": term :	term MULOP unary_expression"<<endl;
		logout<<endl;


		if((yyvsp[-1].si)->getName() == "%"){
			
			for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
				if((yyvsp[-2].vs)->at(i)->getType() == "ID"){
					temp = table->lookup((yyvsp[-2].vs)->at(i)->getName());
					if(temp != NULL){
						if(temp->getIdentity() == "float"  || temp->getIdentity() == "void"){
							if(error_count == false){
								errorfile<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
								logout<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
								error_calc++;
								error_count = true;
								SymbolInfo *point = new SymbolInfo();
								point->setType("Error");
								(yyval.vs)->push_back(point);
							}
						}
					}
				}
				else{
					if((yyvsp[-2].vs)->at(i)->getType() == "CONST_FLOAT" && error_count == false){
						errorfile<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
						logout<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
						error_calc++;
						error_count = true;
						SymbolInfo *point = new SymbolInfo();
						point->setType("Error");
						(yyval.vs)->push_back(point);
						break;
					}
				}
				
			}
		
			
			for(i = 0; i < (yyvsp[0].vs)->size(); i++){
				if((yyvsp[0].vs)->size() == 1 && (yyvsp[0].vs)->at(i)->getName() == "0" && error_count == false){
					errorfile<<"Error at line "<<line_count<<": Modulus by Zero "<<endl<<endl;
					logout<<"Error at line "<<line_count<<": Modulus by Zero "<<endl<<endl;
					error_calc++;
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					(yyval.vs)->push_back(point);
					break;
				}
				if((yyvsp[0].vs)->at(i)->getType() == "ID"){
					temp = table->lookup((yyvsp[0].vs)->at(i)->getName());
					if(temp != NULL){
						if(temp->getIdentity() == "float"  || temp->getIdentity() == "void"){
							if(error_count == false){
								errorfile<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
								logout<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
								error_calc++;
								error_count = true;
								SymbolInfo *point = new SymbolInfo();
								point->setType("Error");
								(yyval.vs)->push_back(point);
							}
						}
					}
				}
				else{
					if((yyvsp[0].vs)->at(i)->getType() == "CONST_FLOAT" && error_count == false){
						errorfile<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
						logout<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
						error_calc++;
						error_count = true;
						SymbolInfo *point = new SymbolInfo();
						point->setType("Error");
						(yyval.vs)->push_back(point);
						break;
					}
				}
				
			}
		}
		
		if((yyvsp[-1].si)->getName() == "/"){
			if((yyvsp[0].vs)->size() == 1 && (yyvsp[0].vs)->at(0)->getName() == "0"  && error_count == false){
				errorfile<<"Error at line "<<line_count<<": Divided by Zero "<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Divided by Zero "<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
				break;
			}
		}
		

		for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
			logout<<(yyvsp[-2].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[-1].si));
		logout<<(yyvsp[-1].si)->getName();

		for(i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
#line 3621 "y.tab.c"
    break;

  case 55:
#line 1978 "1705067.y"
                                         { 
		int i;
		(yyval.vs) = new vector<SymbolInfo*>();
		bool error_count = false;
		
		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}
		SymbolInfo *temp = new SymbolInfo();

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "ID"){
				temp = table->lookup((yyvsp[0].vs)->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							(yyval.vs)->push_back(point);
						}
					}
				}
				
			}
		}

		logout<< "Line "<< line_count<<": unary_expression : ADDOP unary_expression "<<endl;
		logout<<endl;

		(yyval.vs)->push_back((yyvsp[-1].si));
		logout<<(yyvsp[-1].si)->getName();

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
#line 3674 "y.tab.c"
    break;

  case 56:
#line 2026 "1705067.y"
                                       { 
		int i;
		(yyval.vs) = new vector<SymbolInfo*>();
		bool error_count = false;
		
		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}
		SymbolInfo *temp = new SymbolInfo();

		for( i = 0; i < (yyvsp[0].vs)->size(); i++){
			if((yyvsp[0].vs)->at(i)->getType() == "ID"){
				temp = table->lookup((yyvsp[0].vs)->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							(yyval.vs)->push_back(point);
						}
					}
				}
				
			}
		}
		logout<< "Line "<< line_count<<": unary_expression : NOT unary_expression "<<endl;
		logout<<endl;
		

		(yyval.vs)->push_back((yyvsp[-1].si));
		logout<<(yyvsp[-1].si)->getName();

		for(i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
#line 3727 "y.tab.c"
    break;

  case 57:
#line 2074 "1705067.y"
                         { 
		logout<< "Line "<< line_count<<": unary_expression : factor "<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
#line 3744 "y.tab.c"
    break;

  case 58:
#line 2088 "1705067.y"
                  { 
		logout<< "Line "<< line_count<<": factor : variable"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
#line 3761 "y.tab.c"
    break;

  case 59:
#line 2100 "1705067.y"
                                        { 
		int i,j;
		logout<< "Line "<< line_count<<": factor : ID LPAREN argument_list RPAREN"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();
		bool error_count = false;

		for( i = 0; i < (yyvsp[-1].vs)->size(); i++){
			if((yyvsp[-1].vs)->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
		}
		
		SymbolInfo *temp = new SymbolInfo();
		SymbolInfo *temp1 = new SymbolInfo();
		SymbolInfo *temp2 = new SymbolInfo();
		temp = table->lookup((yyvsp[-3].si)->getName());
		if(temp == NULL){
			if(error_count == false){
				errorfile<<"Error at line "<<line_count<<": Undeclared function "<<(yyvsp[-3].si)->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Undeclared function "<<(yyvsp[-3].si)->getName()<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				(yyval.vs)->push_back(point);
			}
			
		}
		else{
			if(temp->getFunction() != 1){
				if(error_count == false){
					errorfile<<"Error at line "<<line_count<<": Undeclared function "<<(yyvsp[-3].si)->getName()<<endl<<endl;
					logout<<"Error at line "<<line_count<<": Undeclared function "<<(yyvsp[-3].si)->getName()<<endl<<endl;
					error_calc++;
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					(yyval.vs)->push_back(point);
				}
			}
			else{
				vector<SymbolInfo*> param_count;
				for(i = 0; i < temp->returnVector().size(); i++ ){
					
					if(temp->returnVector().at(i)->getType() == "INT" || temp->returnVector().at(i)->getType() == "FLOAT"){
						param_count.push_back(temp->returnVector().at(i));
					}
				}
				int j = 0;
				for(i = 0; i < (yyvsp[-1].vs)->size(); i++){
					if((yyvsp[-1].vs)->at(i)->getType() == "COMMA"){
						j++;				
					}
				}
				if(param_count.size() != (j+1) ){
					if(error_count == false){
						if(param_count.size()==0 && j == 0 && (yyvsp[-1].vs)->size() == 0){
						}
						else{
							errorfile<<"Error at line "<<line_count<<": Total number of arguments mismatch in function "<<temp->getName()<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Total number of arguments mismatch in function "<<temp->getName()<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							(yyval.vs)->push_back(point);
						}
						
					}
					
				}
				else{
					j = 0;
					for(i = 0; i < (yyvsp[-1].vs)->size(); i++){
						if((yyvsp[-1].vs)->at(i)->getType() == "COMMA"){
							j++;				
						}
						else{
							if((yyvsp[-1].vs)->at(i)->getType() == "ID"){
								temp1 = table->lookup((yyvsp[-1].vs)->at(i)->getName());
								if(temp1 != NULL ){
									if(temp1->getArray() == 1){
										if((i+1)< (yyvsp[-1].vs)->size() && (yyvsp[-1].vs)->at(i+1)->getType() == "LTHIRD"){
											while((yyvsp[-1].vs)->at(i)->getType() != "RTHIRD"){
												i++;
											}
										}
									}
									if(temp1->getFunction() == 1){
										if((i+1)< (yyvsp[-1].vs)->size() && (yyvsp[-1].vs)->at(i+1)->getType() == "LPAREN"){
											while((yyvsp[-1].vs)->at(i)->getType() != "RPAREN"){
												i++;
											}
										}
									}
									
									if((temp1->getIdentity() == "float" || temp1->getIdentity() == "void" ) && param_count.at(j)->getType() == "INT"){
										if(error_count == false){
											errorfile<<"Error at line "<<line_count<<": "<<j+1<<"th argument mismatch in function "<<temp->getName()<<endl<<endl;
											logout<<"Error at line "<<line_count<<": "<<j+1<<"th argument mismatch in function "<<temp->getName()<<endl<<endl;
											error_calc++;
											error_count = true;
											SymbolInfo *point = new SymbolInfo();
											point->setType("Error");
											(yyval.vs)->push_back(point);
											break;
										}
									}
									else if(temp1->getIdentity() == "void" &&  param_count.at(j)->getType() == "FLOAT"){
										if(error_count == false){
										
												errorfile<<"Error at line "<<line_count<<": "<<j+1<<"th argument mismatch in function "<<temp->getName()<<endl<<endl;
												logout<<"Error at line "<<line_count<<": "<<j+1<<"th argument mismatch in function "<<temp->getName()<<endl<<endl;
												error_calc++;
												error_count = true;
												SymbolInfo *point = new SymbolInfo();
												point->setType("Error");
												(yyval.vs)->push_back(point);
												break;
											
											
										}
									}
									
								}
								
							}
							else{
								if((yyvsp[-1].vs)->at(i)->getType() == "CONST_FLOAT" && param_count.at(j)->getType() == "INT"){
									if(error_count == false){
										errorfile<<"Error at line "<<line_count<<": "<<j+1<<"th argument mismatch in function "<<temp->getName()<<endl<<endl;
										logout<<"Error at line "<<line_count<<": "<<j+1<<"th argument mismatch in function "<<temp->getName()<<endl<<endl;
										error_calc++;
										error_count = true;
										SymbolInfo *point = new SymbolInfo();
										point->setType("Error");
										(yyval.vs)->push_back(point);
										break;
									}
	
								}
								
							}
							
						}
						
					}
				}
			}
			
			
			
		}

		(yyval.vs)->push_back((yyvsp[-3].si));
		logout<<(yyvsp[-3].si)->getName();

		(yyval.vs)->push_back((yyvsp[-2].si));
		logout<<(yyvsp[-2].si)->getName();

		if((yyvsp[-1].vs)->size() > 0){
			for( i = 0; i < (yyvsp[-1].vs)->size(); i++){
				(yyval.vs)->push_back((yyvsp[-1].vs)->at(i));
				logout<<(yyvsp[-1].vs)->at(i)->getName();
			}
		}
		(yyval.vs)->push_back((yyvsp[0].si));
		logout<<(yyvsp[0].si)->getName()<<endl;
		logout<<endl;
		}
#line 3940 "y.tab.c"
    break;

  case 60:
#line 2274 "1705067.y"
                                  { 
		logout<< "Line "<< line_count<<": factor : LPAREN expression RPAREN"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		(yyval.vs)->push_back((yyvsp[-2].si));
		logout<<(yyvsp[-2].si)->getName();

		for(int i = 0; i < (yyvsp[-1].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-1].vs)->at(i));
			logout<<(yyvsp[-1].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[0].si));
		logout<<(yyvsp[0].si)->getName()<<endl;
		logout<<endl;
		}
#line 3962 "y.tab.c"
    break;

  case 61:
#line 2291 "1705067.y"
                   { 
		logout<<  "Line "<< line_count<<": factor : CONST_INT"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		(yyval.vs)->push_back((yyvsp[0].si));
		logout<<(yyvsp[0].si)->getName() <<endl;
		logout<<endl;
		}
#line 3976 "y.tab.c"
    break;

  case 62:
#line 2300 "1705067.y"
                     { 
		logout<< "Line "<< line_count<<": factor : CONST_FLOAT"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		(yyval.vs)->push_back((yyvsp[0].si));
		logout<<(yyvsp[0].si)->getName() <<endl;
		logout<<endl;
		}
#line 3990 "y.tab.c"
    break;

  case 63:
#line 2309 "1705067.y"
                        { 
		logout<< "Line "<< line_count<<": factor : variable INCOP"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[-1].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-1].vs)->at(i));
			logout<<(yyvsp[-1].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[0].si));
		logout<<(yyvsp[0].si)->getName() <<endl;

		logout<<endl;
		}
#line 4010 "y.tab.c"
    break;

  case 64:
#line 2324 "1705067.y"
                        { 
		logout<< "Line "<< line_count<<": factor : variable DECOP"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[-1].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-1].vs)->at(i));
			logout<<(yyvsp[-1].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[0].si));
		logout<<(yyvsp[0].si)->getName() <<endl;

		logout<<endl;
		}
#line 4030 "y.tab.c"
    break;

  case 65:
#line 2341 "1705067.y"
                         { 
		logout<< "Line "<< line_count<<": argument_list : arguments"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
#line 4047 "y.tab.c"
    break;

  case 66:
#line 2353 "1705067.y"
                           { 
		logout<< "Line "<< line_count<<": argument_list : "<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();
		}
#line 4057 "y.tab.c"
    break;

  case 67:
#line 2360 "1705067.y"
                                            { 
		int i;
		logout<< "Line "<< line_count<<": arguments : arguments COMMA logic_expression"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(i = 0; i < (yyvsp[-2].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[-2].vs)->at(i));
			logout<<(yyvsp[-2].vs)->at(i)->getName();
		}

		(yyval.vs)->push_back((yyvsp[-1].si));
		logout<<(yyvsp[-1].si)->getName();
		
		for(i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
#line 4083 "y.tab.c"
    break;

  case 68:
#line 2381 "1705067.y"
                                { 
		logout<< "Line "<< line_count<<": arguments : arguments COMMA logic_expression"<<endl;
		logout<<endl;
		(yyval.vs) = new vector<SymbolInfo*>();

		for(int i = 0; i < (yyvsp[0].vs)->size(); i++){
			(yyval.vs)->push_back((yyvsp[0].vs)->at(i));
			logout<<(yyvsp[0].vs)->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
#line 4100 "y.tab.c"
    break;


#line 4104 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 2396 "1705067.y"


int main(int argc,char *argv[]){
	
	FILE *file=fopen(argv[1],"r");
	if(file==NULL){
		cout<<"Cannot open specified file"<<endl;
		return 0;
	}
	logout.open("1705067_log.txt");
	errorfile.open("1705067_error.txt");
	yyin= file;
	yyparse();
	fclose(yyin);
	logout.close();
	errorfile.close();
	return 0;
	exit(0);
}

