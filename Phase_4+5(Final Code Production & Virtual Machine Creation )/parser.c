/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "parser.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #define offset_increment(x,y,z) ( (x == 0) ? y++ : z++ ) //if func programoffset++ else functionlocaloffset++

    
    int yyerror(const char* yaccProvidedMessage);
    extern int yylex();
    extern int yylineno;
    extern char* yytext;    
    extern FILE* yyin;  
    int scope=0;
    int local=0;
    int global=0;
    int i = 0;
    int k = 0;
    int loop=0;
    int funcNameError = 0;
    int uf=0;
    int member=0;
    int leftval=0;
    char* funcname=NULL;
    int inFunc=0;
    int inWhile=0;
    int fbreak=0;
    int fcontinue=0;
  
    
     #include "Instructions.h"
    statement* tmp_stmt=NULL;


#line 101 "parser.c" /* yacc.c:339  */

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
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    INT = 258,
    STRING = 259,
    IDENTIFIER = 260,
    FLOAT = 261,
    WHILE = 262,
    FOR = 263,
    IF = 264,
    ELSE = 265,
    FUNCTION = 266,
    RETURN = 267,
    AND = 268,
    BREAK = 269,
    CONTINUE = 270,
    OR = 271,
    NOT = 272,
    LOCAL = 273,
    TRUE = 274,
    FALSE = 275,
    NIL = 276,
    PLUS = 277,
    MINUS = 278,
    ASSIGN = 279,
    MUL = 280,
    MOD = 281,
    DIV = 282,
    EQUALS = 283,
    NOT_EQUALS = 284,
    PLUS_PLUS = 285,
    MINUS_MINUS = 286,
    GREATER_OR_EQUAL = 287,
    LESS_OR_EQUAL = 288,
    GREATER = 289,
    LESS = 290,
    L_BRACKET = 291,
    R_BRACKET = 292,
    L_CURLY_BRACKET = 293,
    R_CURLY_BRACKET = 294,
    L_PARENTHESIS = 295,
    R_PARENTHESIS = 296,
    COMMA = 297,
    SEMICOLON = 298,
    COLON = 299,
    SCOPE = 300,
    DOT = 301,
    DOUBLE_DOT = 302,
    UNDEFINED = 303,
    UMINUS = 304
  };
#endif
/* Tokens.  */
#define INT 258
#define STRING 259
#define IDENTIFIER 260
#define FLOAT 261
#define WHILE 262
#define FOR 263
#define IF 264
#define ELSE 265
#define FUNCTION 266
#define RETURN 267
#define AND 268
#define BREAK 269
#define CONTINUE 270
#define OR 271
#define NOT 272
#define LOCAL 273
#define TRUE 274
#define FALSE 275
#define NIL 276
#define PLUS 277
#define MINUS 278
#define ASSIGN 279
#define MUL 280
#define MOD 281
#define DIV 282
#define EQUALS 283
#define NOT_EQUALS 284
#define PLUS_PLUS 285
#define MINUS_MINUS 286
#define GREATER_OR_EQUAL 287
#define LESS_OR_EQUAL 288
#define GREATER 289
#define LESS 290
#define L_BRACKET 291
#define R_BRACKET 292
#define L_CURLY_BRACKET 293
#define R_CURLY_BRACKET 294
#define L_PARENTHESIS 295
#define R_PARENTHESIS 296
#define COMMA 297
#define SEMICOLON 298
#define COLON 299
#define SCOPE 300
#define DOT 301
#define DOUBLE_DOT 302
#define UNDEFINED 303
#define UMINUS 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 40 "parser.y" /* yacc.c:355  */

	int intval;
	float flval;
    char* strval;
    struct expression* expression;
    struct SymbolTableEntry* sym;
    struct statement* statement;
    struct for_struct* forval;

#line 249 "parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 264 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   585

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   109,   113,   116,   120,   123,   126,   129,
     138,   149,   152,   153,   158,   166,   176,   177,   186,   198,
     210,   222,   234,   247,   261,   276,   291,   306,   320,   329,
     338,   341,   342,   350,   357,   427,   495,   561,   628,   631,
     631,   719,   773,   774,   775,   780,   783,   791,   799,   807,
     810,   878,   955,   961,   964,   979,  1011,  1029,  1030,  1033,
    1043,  1053,  1066,  1082,  1085,  1100,  1116,  1117,  1126,  1133,
    1135,  1138,  1138,  1147,  1176,  1186,  1193,  1200,  1212,  1212,
    1223,  1241,  1247,  1257,  1266,  1272,  1279,  1286,  1297,  1314,
    1332,  1336,  1343,  1349,  1352,  1358,  1361,  1364,  1371,  1379,
    1387,  1404,  1410,  1415,  1425,  1451,  1461
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STRING", "IDENTIFIER", "FLOAT",
  "WHILE", "FOR", "IF", "ELSE", "FUNCTION", "RETURN", "AND", "BREAK",
  "CONTINUE", "OR", "NOT", "LOCAL", "TRUE", "FALSE", "NIL", "PLUS",
  "MINUS", "ASSIGN", "MUL", "MOD", "DIV", "EQUALS", "NOT_EQUALS",
  "PLUS_PLUS", "MINUS_MINUS", "GREATER_OR_EQUAL", "LESS_OR_EQUAL",
  "GREATER", "LESS", "L_BRACKET", "R_BRACKET", "L_CURLY_BRACKET",
  "R_CURLY_BRACKET", "L_PARENTHESIS", "R_PARENTHESIS", "COMMA",
  "SEMICOLON", "COLON", "SCOPE", "DOT", "DOUBLE_DOT", "UNDEFINED",
  "UMINUS", "$accept", "program", "stmt", "break", "continue", "expr",
  "term", "assignexpr", "$@1", "primary", "lvalue", "member", "call",
  "callsuffix", "methodcall", "normcall", "elist", "tabledef", "indexed",
  "indexedelem", "block_stmt", "block", "$@2", "idname", "fblock_s",
  "fblock_e", "fprefix", "fargs", "$@3", "fbody", "funcdef", "const",
  "idlist", "ifprefix", "elseprefix", "ifstmt", "loopstart", "loopend",
  "loopstmt", "whilecond", "whilestart", "whilestmt", "N", "M",
  "forprefix", "for", "returnstmt", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -165

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-165)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-40)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     114,  -165,  -165,  -165,  -165,  -165,   -31,   -13,    28,   160,
    -165,  -165,   256,    30,  -165,  -165,  -165,   256,    19,    19,
     189,  -165,   227,  -165,    33,    46,   114,     5,    12,   300,
    -165,  -165,  -165,    56,  -165,    48,  -165,  -165,    38,  -165,
    -165,   114,  -165,    43,  -165,  -165,  -165,  -165,   256,   256,
    -165,  -165,  -165,   323,  -165,  -165,  -165,    80,   100,    48,
     100,   256,   508,   -32,   -30,  -165,  -165,   369,    44,  -165,
    -165,  -165,  -165,  -165,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,  -165,  -165,  -165,
     256,   256,    88,   103,    86,  -165,  -165,  -165,   256,   256,
     119,  -165,  -165,   131,   256,  -165,   256,     1,   392,  -165,
      89,   277,  -165,   256,  -165,   111,    11,  -165,   113,   522,
     522,    36,    36,  -165,  -165,  -165,   536,   536,   550,   550,
     550,   550,   462,    16,  -165,   118,   256,   485,    57,  -165,
     155,   123,  -165,  -165,   114,   415,   114,  -165,    59,  -165,
    -165,   113,   256,   508,  -165,  -165,  -165,   256,  -165,  -165,
     256,   508,  -165,  -165,  -165,    64,  -165,  -165,  -165,  -165,
    -165,   256,   438,    71,    74,  -165,   162,  -165,  -165,   114,
     346,  -165,  -165,  -165,  -165,  -165,  -165,  -165
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    82,    84,    46,    83,    99,     0,     0,    74,     0,
      14,    15,     0,     0,    86,    87,    85,     0,     0,     0,
      63,    71,     0,    13,     0,     0,     3,     0,     0,     0,
      30,    16,    38,    41,    49,    42,    43,    11,     0,    12,
      45,     0,     5,     0,     6,   101,     7,     8,    63,     0,
      73,    77,   106,     0,    33,    47,    32,     0,    34,     0,
      36,     0,    61,     0,     0,    66,    70,     0,     0,    48,
       1,     2,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,    35,    37,
       0,    63,     0,     0,     0,    55,    58,    57,     0,    63,
       0,    78,    75,    93,     0,    95,    63,     0,     0,   105,
       0,     0,    64,     0,    65,     0,     0,    31,    44,    28,
      29,    17,    18,    19,    21,    20,    26,    27,    23,    25,
      22,    24,     0,     0,    50,     0,     0,     0,     0,    52,
      90,     0,    81,    92,     0,     0,     0,   100,     0,   102,
      91,     0,     0,    62,    67,    72,    69,    63,    51,    60,
      63,    40,    53,    54,    88,     0,    76,    94,    98,    96,
     101,     0,     0,     0,     0,    79,     0,    80,    97,     0,
       0,    68,    56,    59,    89,   101,   103,   104
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -165,   142,   -37,  -165,  -165,    -9,  -165,  -165,  -165,  -165,
     120,  -165,   137,  -165,  -165,  -165,   -46,  -165,  -165,    54,
    -165,    29,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
     -21,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,  -165,  -164,  -165,  -165,  -165,  -165
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    94,    32,
      33,    34,    35,    95,    96,    97,    63,    36,    64,    65,
     116,    37,    66,    51,   141,   177,    38,   102,   140,   142,
      39,    40,   165,    41,   144,    42,   146,   178,   147,   105,
      43,    44,   106,   171,    45,    46,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    68,   107,    54,   103,   112,   179,   114,    56,    48,
     113,    62,   115,    67,     1,     2,     3,     4,     5,     6,
       7,   187,     8,     9,     3,    10,    11,    49,    12,    13,
      14,    15,    16,    50,    17,    55,   110,    13,    69,    62,
     108,    18,    19,   113,   149,   133,    70,    20,    72,    21,
     155,    22,   111,   138,    23,    73,    24,   159,   113,    57,
     148,    78,    79,    80,    24,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   101,   156,
     -39,   132,    62,   104,    98,   118,    88,    89,    99,   137,
      62,     8,    90,   134,   100,   145,    91,    62,   163,   113,
     170,   113,    92,    93,   153,   175,   176,   167,   135,   169,
     136,   173,   182,   113,   174,   183,   113,     1,     2,     3,
       4,     5,     6,     7,   139,     8,     9,   161,    10,    11,
     151,    12,    13,    14,    15,    16,    90,    17,    58,    60,
      91,   143,   185,   172,    18,    19,    92,    93,    62,    61,
      20,    62,    21,   157,    22,    59,    59,    23,   160,    24,
     164,    21,   180,     1,     2,     3,     4,   184,    71,   154,
     166,     0,     0,     0,     0,     0,     0,    12,    13,    14,
      15,    16,     0,    17,     0,     0,     0,     0,     0,     0,
      18,    19,     1,     2,     3,     4,    20,     0,     0,     0,
      22,     0,     0,    52,     0,    24,    12,    13,    14,    15,
      16,     0,    17,     0,     0,     0,     0,     0,     0,    18,
      19,     0,     0,     0,     0,    20,     0,    61,     0,    22,
       1,     2,     3,     4,    24,     0,     0,     0,     8,     0,
       0,     0,     0,     0,    12,    13,    14,    15,    16,     0,
      17,     0,     0,     0,     0,     0,     0,    18,    19,     1,
       2,     3,     4,    20,     0,     0,     0,    22,     0,     0,
       0,     0,    24,    12,    13,    14,    15,    16,     0,    17,
       0,     0,     0,     0,     0,     0,    18,    19,     0,     0,
      74,     0,    20,    75,     0,     0,    22,     0,     0,    76,
      77,    24,    78,    79,    80,    81,    82,     0,     0,    83,
      84,    85,    86,    74,     0,     0,    75,     0,     0,     0,
       0,   152,    76,    77,     0,    78,    79,    80,    81,    82,
       0,     0,    83,    84,    85,    86,    74,     0,     0,    75,
       0,     0,     0,    87,     0,    76,    77,     0,    78,    79,
      80,    81,    82,     0,     0,    83,    84,    85,    86,    74,
       0,     0,    75,     0,     0,     0,   109,     0,    76,    77,
       0,    78,    79,    80,    81,    82,     0,     0,    83,    84,
      85,    86,    74,     0,     0,    75,     0,     0,     0,   186,
       0,    76,    77,     0,    78,    79,    80,    81,    82,     0,
       0,    83,    84,    85,    86,    74,     0,     0,    75,     0,
     117,     0,     0,     0,    76,    77,     0,    78,    79,    80,
      81,    82,     0,     0,    83,    84,    85,    86,    74,     0,
       0,    75,     0,   150,     0,     0,     0,    76,    77,     0,
      78,    79,    80,    81,    82,     0,     0,    83,    84,    85,
      86,    74,     0,     0,    75,     0,   168,     0,     0,     0,
      76,    77,     0,    78,    79,    80,    81,    82,     0,     0,
      83,    84,    85,    86,     0,    74,     0,   181,    75,     0,
       0,     0,     0,     0,    76,    77,     0,    78,    79,    80,
      81,    82,     0,     0,    83,    84,    85,    86,    74,   158,
       0,    75,     0,     0,     0,     0,     0,    76,    77,     0,
      78,    79,    80,    81,    82,     0,     0,    83,    84,    85,
      86,    74,   162,     0,    75,     0,     0,     0,     0,     0,
      76,    77,     0,    78,    79,    80,    81,    82,     0,     0,
      83,    84,    85,    86,    76,    77,     0,    78,    79,    80,
      81,    82,     0,     0,    83,    84,    85,    86,    76,    77,
       0,    78,    79,    80,   -40,   -40,     0,     0,    83,    84,
      85,    86,    76,    77,     0,    78,    79,    80,     0,     0,
       0,     0,   -40,   -40,   -40,   -40
};

static const yytype_int16 yycheck[] =
{
       9,    22,    48,    12,    41,    37,   170,    37,    17,    40,
      42,    20,    42,    22,     3,     4,     5,     6,     7,     8,
       9,   185,    11,    12,     5,    14,    15,    40,    17,    18,
      19,    20,    21,     5,    23,     5,    57,    18,     5,    48,
      49,    30,    31,    42,    43,    91,     0,    36,    43,    38,
      39,    40,    61,    99,    43,    43,    45,    41,    42,    40,
     106,    25,    26,    27,    45,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    40,   116,
      24,    90,    91,    40,    36,    41,    30,    31,    40,    98,
      99,    11,    36,     5,    46,   104,    40,   106,    41,    42,
      41,    42,    46,    47,   113,    41,    42,   144,     5,   146,
      24,   157,    41,    42,   160,    41,    42,     3,     4,     5,
       6,     7,     8,     9,     5,    11,    12,   136,    14,    15,
      41,    17,    18,    19,    20,    21,    36,    23,    18,    19,
      40,    10,   179,   152,    30,    31,    46,    47,   157,    38,
      36,   160,    38,    40,    40,    18,    19,    43,    40,    45,
       5,    38,   171,     3,     4,     5,     6,     5,    26,   115,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,     3,     4,     5,     6,    36,    -1,    -1,    -1,
      40,    -1,    -1,    43,    -1,    45,    17,    18,    19,    20,
      21,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    40,
       3,     4,     5,     6,    45,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,     3,
       4,     5,     6,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    45,    17,    18,    19,    20,    21,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      13,    -1,    36,    16,    -1,    -1,    40,    -1,    -1,    22,
      23,    45,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    13,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    44,    22,    23,    -1,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    13,    -1,    -1,    16,
      -1,    -1,    -1,    43,    -1,    22,    23,    -1,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    13,
      -1,    -1,    16,    -1,    -1,    -1,    43,    -1,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    13,    -1,    -1,    16,    -1,    -1,    -1,    43,
      -1,    22,    23,    -1,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    13,    -1,    -1,    16,    -1,
      41,    -1,    -1,    -1,    22,    23,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    13,    -1,
      -1,    16,    -1,    41,    -1,    -1,    -1,    22,    23,    -1,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    13,    -1,    -1,    16,    -1,    41,    -1,    -1,    -1,
      22,    23,    -1,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    -1,    13,    -1,    39,    16,    -1,
      -1,    -1,    -1,    -1,    22,    23,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    13,    37,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    13,    37,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    22,    23,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    22,    23,    -1,    25,    26,    27,    -1,    -1,
      -1,    -1,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    11,    12,
      14,    15,    17,    18,    19,    20,    21,    23,    30,    31,
      36,    38,    40,    43,    45,    51,    52,    53,    54,    55,
      56,    57,    59,    60,    61,    62,    67,    71,    76,    80,
      81,    83,    85,    90,    91,    94,    95,    96,    40,    40,
       5,    73,    43,    55,    55,     5,    55,    40,    60,    62,
      60,    38,    55,    66,    68,    69,    72,    55,    80,     5,
       0,    51,    43,    43,    13,    16,    22,    23,    25,    26,
      27,    28,    29,    32,    33,    34,    35,    43,    30,    31,
      36,    40,    46,    47,    58,    63,    64,    65,    36,    40,
      46,    40,    77,    52,    40,    89,    92,    66,    55,    43,
      80,    55,    37,    42,    37,    42,    70,    41,    41,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    66,     5,     5,    24,    55,    66,     5,
      78,    74,    79,    10,    84,    55,    86,    88,    66,    43,
      41,    41,    44,    55,    69,    39,    52,    40,    37,    41,
      40,    55,    37,    41,     5,    82,    71,    52,    41,    52,
      41,    93,    55,    66,    66,    41,    42,    75,    87,    92,
      55,    39,    41,    41,     5,    52,    43,    92
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    58,
      57,    59,    59,    59,    59,    59,    60,    60,    60,    60,
      61,    61,    61,    61,    62,    62,    62,    63,    63,    64,
      65,    66,    66,    66,    67,    67,    68,    68,    69,    70,
      70,    72,    71,    73,    73,    74,    75,    76,    78,    77,
      79,    80,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    83,    84,    85,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     0,
       4,     1,     1,     1,     3,     1,     1,     2,     2,     1,
       3,     4,     3,     4,     4,     2,     6,     1,     1,     5,
       3,     1,     3,     0,     3,     3,     1,     3,     5,     2,
       0,     0,     4,     1,     0,     0,     0,     2,     0,     4,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     4,     1,     2,     4,     0,     0,     3,     3,     1,
       3,     0,     0,     7,     7,     3,     2
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
        case 4:
#line 113 "parser.y" /* yacc.c:1646  */
    {
 
            }
#line 1562 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 116 "parser.y" /* yacc.c:1646  */
    {


            }
#line 1571 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 120 "parser.y" /* yacc.c:1646  */
    {

            }
#line 1579 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 123 "parser.y" /* yacc.c:1646  */
    {

            }
#line 1587 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "parser.y" /* yacc.c:1646  */
    {

            }
#line 1595 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 129 "parser.y" /* yacc.c:1646  */
    {
                    fbreak=1;
                    if(loop==0) {
                        printf(RED"ERROR"RESET" in line %d, break is defined outside of loop\n",yylineno);
                    }
                    (yyval.statement)=(yyvsp[-1].statement);
                    tmp_stmt=(yyvsp[-1].statement);

            }
#line 1609 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 138 "parser.y" /* yacc.c:1646  */
    {
               
                    fcontinue=1;
                    if(loop==0){
                        printf(RED"ERROR"RESET" in line %d, continue is defined outside of loop\n",yylineno);
                    }
                     (yyval.statement)=(yyvsp[-1].statement);
                     
                     tmp_stmt=(yyvsp[-1].statement);

            }
#line 1625 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 149 "parser.y" /* yacc.c:1646  */
    {
                   
            }
#line 1633 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 152 "parser.y" /* yacc.c:1646  */
    {}
#line 1639 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 153 "parser.y" /* yacc.c:1646  */
    {
                  
            }
#line 1647 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 159 "parser.y" /* yacc.c:1646  */
    {   
        (yyval.statement)=(statement*)malloc(sizeof(statement));
        (yyval.statement)->breaklist = insertb_list(nextquadlabel()); emit(jump,NULL,NULL,NULL,-1,currQuad);
        printf("break_add : %d\n",(yyval.statement)->breaklist->quadadd);
    }
#line 1657 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 167 "parser.y" /* yacc.c:1646  */
    {  
    (yyval.statement)=(statement*)malloc(sizeof(statement));
    (yyval.statement)->contlist = insertc_list(nextquadlabel()); emit(jump,NULL,NULL,NULL,-1,currQuad);
    printf("cont_add : %d\n",(yyval.statement)->contlist->quadadd);
}
#line 1667 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyval.expression) = (yyvsp[0].expression);}
#line 1673 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 177 "parser.y" /* yacc.c:1646  */
    {
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(add , (yyvsp[-2].expression) , (yyvsp[0].expression) , tmpexpr , -1 , currQuad);
                                (yyval.expression) = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset); //to au3anw gia to temp.
                                (yyval.expression)->sym->offset=currscopeoffset();

            }
#line 1687 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 186 "parser.y" /* yacc.c:1646  */
    {
                                if(checknumerical((yyvsp[-2].expression),(yyvsp[0].expression))==0){
                                    printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                    yyerror("numerical operation problem");  
                                }
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(sub, (yyvsp[-2].expression) , (yyvsp[0].expression) , tmpexpr , -1 , currQuad);
                                (yyval.expression) = tmpexpr; 
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1704 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 198 "parser.y" /* yacc.c:1646  */
    {
                                if(checknumerical((yyvsp[-2].expression),(yyvsp[0].expression))==0){
                                    printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                    yyerror("numerical operation problem");  
                                }
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(mul, (yyvsp[-2].expression) , (yyvsp[0].expression) , tmpexpr , -1 , currQuad);
                                (yyval.expression) = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1721 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 210 "parser.y" /* yacc.c:1646  */
    {
                                if(checknumerical((yyvsp[-2].expression),(yyvsp[0].expression))==0){
                                    printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                    yyerror("numerical operation problem");  
                                }
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(division, (yyvsp[-2].expression) , (yyvsp[0].expression) , tmpexpr , -1 , currQuad);
                                (yyval.expression) = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1738 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 222 "parser.y" /* yacc.c:1646  */
    {
                                if(checknumerical((yyvsp[-2].expression),(yyvsp[0].expression))==0){
                                    printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                    yyerror("numerical operation problem");  
                                }
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(mod, (yyvsp[-2].expression) , (yyvsp[0].expression) , tmpexpr , -1 , currQuad);
                                (yyval.expression) = tmpexpr; 
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1755 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 234 "parser.y" /* yacc.c:1646  */
    {
                                    SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
							       
							        emit(if_greater, (yyvsp[-2].expression), (yyvsp[0].expression), NULL, currQuad + 3, currQuad);
							        emit(jump, NULL, NULL, NULL, currQuad + 4, currQuad);
                                    emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                    emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); //--
                                    (yyval.expression) = tmpexpr;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1773 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 247 "parser.y" /* yacc.c:1646  */
    {
                                SymbolTableEntry *tmp = newtemp(LOKAL);
                                expr* tmpexpr = lvalue_expr(tmp);
                               
                                emit(if_greatereq, (yyvsp[-2].expression), (yyvsp[0].expression), NULL, currQuad + 3, currQuad);
                                emit(jump, NULL, NULL, NULL, currQuad + 4, currQuad);
                                emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); //-- 

                                (yyval.expression) = tmpexpr;  
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                (yyval.expression)->sym->offset=currscopeoffset();                               
            }
#line 1792 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 261 "parser.y" /* yacc.c:1646  */
    {

                                SymbolTableEntry *tmp = newtemp(LOKAL);
                                expr* tmpexpr = lvalue_expr(tmp);
                               
                                emit(if_less, (yyvsp[-2].expression), (yyvsp[0].expression), NULL, currQuad + 3, currQuad);
                                emit(jump, NULL, NULL, NULL, currQuad + 4, currQuad);
                             
                                emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); //--  
                                (yyval.expression) = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1812 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 276 "parser.y" /* yacc.c:1646  */
    {

                                        SymbolTableEntry *tmp = newtemp(LOKAL);
                                        expr* tmpexpr = lvalue_expr(tmp);
                                        
                                        emit(if_lesseq, (yyvsp[-2].expression), (yyvsp[0].expression), NULL, currQuad + 3, currQuad);
                                        emit(jump, NULL, NULL, NULL, currQuad + 4, currQuad);
                                        emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                        emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                        emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); //--  
                                        // //emit(if_lesseq, $1 , $3 , tmpexpr , -1 , currQuad);
                                        (yyval.expression) = tmpexpr;
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1832 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 291 "parser.y" /* yacc.c:1646  */
    {
                                    SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
							        
							        emit(if_eq, (yyvsp[-2].expression), (yyvsp[0].expression), NULL, currQuad + 3, currQuad);
							        emit(jump, NULL, NULL, NULL, currQuad + 4, currQuad);
                                   
                                    emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                    emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); 
                                   
                                    (yyval.expression) = tmpexpr;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1852 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 306 "parser.y" /* yacc.c:1646  */
    {
                                    SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
							       
							        emit(if_not_eq, (yyvsp[-2].expression), (yyvsp[0].expression), NULL, currQuad + 3, currQuad);
							        emit(jump, NULL, NULL, NULL, currQuad + 4, currQuad);
                                    
                                    emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                    emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); //--   
                                    (yyval.expression) = tmpexpr;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1871 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 320 "parser.y" /* yacc.c:1646  */
    {
                                
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(and, (yyvsp[-2].expression) , (yyvsp[0].expression) , tmpexpr , -1 , currQuad);
                                (yyval.expression) = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1885 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 329 "parser.y" /* yacc.c:1646  */
    {
                               
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(or, (yyvsp[-2].expression) , (yyvsp[0].expression) , tmpexpr , -1 , currQuad);
                                (yyval.expression) = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1899 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 338 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);}
#line 1905 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 341 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[-1].expression);}
#line 1911 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 342 "parser.y" /* yacc.c:1646  */
    {
                                        checkuminusexpr((yyvsp[0].expression));
                                        (yyval.expression) = newexpr(arithexpr_e);
                                        (yyval.expression)->sym = newtemp(LOKAL);
                                        (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                        emit(uminus,NULL,(yyvsp[0].expression),(yyval.expression),-1,currQuad);
                                        
            }
#line 1924 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 350 "parser.y" /* yacc.c:1646  */
    {
                              
                                (yyval.expression) = newexpr(arithexpr_e);
                                (yyval.expression)->sym = newtemp(LOKAL);
                                (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                emit(not,NULL,(yyvsp[0].expression),(yyval.expression),-1,currQuad);
            }
#line 1936 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 357 "parser.y" /* yacc.c:1646  */
    {
                                
                                if(checknumerical((yyvsp[0].expression),(yyvsp[0].expression))==0){
                                    printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                    yyerror("numerical operation problem");  
                                }

                                if(local == 1){
                                    local = 0;
                                    if( LookupForLval((yyvsp[0].expression)->strConst,scope)==0 ){ 
                                    
                                    }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==1){
                                       
                                    }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==2){ //userfunc
                                        
                                        printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==3){
                                        printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                }else if(global == 1){
                                    global = 0;
                                    if( LookupForLval((yyvsp[0].expression)->strConst,0)==0){ 
                                        printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                    else if( LookupForLval((yyvsp[0].expression)->strConst,0)==1){ 
                                    }
                                    else if( LookupForLval((yyvsp[0].expression)->strConst,0)==2){ 
                                            printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                    else if( LookupForLval((yyvsp[0].expression)->strConst,0)==3){ 
                                            printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                }else{
                                    if(LookupForLval((yyvsp[0].expression)->strConst, scope)==0) {
                                        if(LookupForLval((yyvsp[0].expression)->strConst,0)==0){
                                           
                                            offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                            Insert((yyvsp[0].expression)->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL); //quad
                                            findEntry2((yyvsp[0].expression)->strConst,scope)->offset=currscopeoffset();
                                            emit(add,(yyvsp[0].expression),newexpr_constnum(1),(yyvsp[0].expression),-1,currQuad); 
                                            (yyval.expression) = newexpr(arithexpr_e);
                                            (yyval.expression)->sym = newtemp(LOKAL);
                                            (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                            offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                            (yyval.expression)->sym->offset=currscopeoffset();
                                            emit(assign,NULL,(yyvsp[0].expression),(yyval.expression),-1,currQuad); //quad
                                        }
                                        else if(LookupForLval((yyvsp[0].expression)->strConst,0)==2){
                                            printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                        }
                                        else if(LookupForLval((yyvsp[0].expression)->strConst,0)==3){
                                            printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                        }
                                    }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==1){
                                        emit(add,(yyvsp[0].expression),newexpr_constnum(1),(yyvsp[0].expression),-1,currQuad);   
                                        (yyval.expression) = newexpr(arithexpr_e);
                                        (yyval.expression)->sym = newtemp(LOKAL);
                                        (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        (yyval.expression)->sym->offset=currscopeoffset();
                                        emit(assign,(yyvsp[0].expression),NULL,(yyval.expression),-1,currQuad);
                                    }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==2){
                                        printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    
                                    }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==3){
                                        printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                }
                              
            }
#line 2011 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 427 "parser.y" /* yacc.c:1646  */
    {
                    if(checknumerical((yyvsp[-1].expression),(yyvsp[-1].expression))==0){
                                        printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                        yyerror("numerical operation problem");  
                    }

                    if(local == 1){
                                local = 0;
                                if( LookupForLval((yyvsp[-1].expression)->strConst,scope)==0 ){ 
                                    printf(RED"ERROR"RESET" in line %d, %s is not declared\n",yylineno,(yyvsp[0].strval));
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==1){
                                    
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==2){ //userfunc
                                   
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval((yyvsp[-1].expression)->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[-1].expression)->strConst,0)==1){ 
                                }
                                else if( LookupForLval((yyvsp[-1].expression)->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[-1].expression)->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }
                            }else{
                                if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==0) {
                                    if(LookupForLval((yyvsp[-1].expression)->strConst,0)==0){
                                       Insert((yyvsp[-1].expression)->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        findEntry2((yyvsp[-1].expression)->strConst,scope)->offset=currscopeoffset();
                                        (yyval.expression) = newexpr(arithexpr_e); //quad
                                        (yyval.expression)->sym = newtemp(LOKAL);
                                        (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        (yyval.expression)->sym->offset=currscopeoffset();
                                        emit(assign,NULL,(yyvsp[-1].expression),(yyval.expression),-1,currQuad); //quad
                                        emit(add,(yyvsp[-1].expression),newexpr_constnum(1),(yyvsp[-1].expression),-1,currQuad); 
                                    }
                                    else if(LookupForLval((yyvsp[-1].expression)->strConst,0)==2){
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                    }
                                    else if(LookupForLval((yyvsp[-1].expression)->strConst,0)==3){
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                    }
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==1){
                                    (yyval.expression) = newexpr(arithexpr_e);
                                    (yyval.expression)->sym = newtemp(LOKAL);
                                    (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();
                                    emit(assign,(yyvsp[-1].expression),NULL,(yyval.expression),-1,currQuad);
                                    emit(add,(yyvsp[-1].expression),newexpr_constnum(1),(yyvsp[-1].expression),-1,currQuad);
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==2){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }
                            }
      
            }
#line 2084 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 495 "parser.y" /* yacc.c:1646  */
    {
                   if(checknumerical((yyvsp[0].expression),(yyvsp[0].expression))==0){
                                        printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                        yyerror("numerical operation problem");  
                    } 

                   if(local == 1){
                                local = 0;
                                if( LookupForLval((yyvsp[0].expression)->strConst,scope)==0 ){ 
                                    printf(RED"ERROR"RESET" in line %d, %s is not declared\n",yylineno,(yyvsp[0].expression)->strConst);
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==1){

                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==2){ //userfunc
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval((yyvsp[0].expression)->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[0].expression)->strConst,0)==1){ 
                                }
                                else if( LookupForLval((yyvsp[0].expression)->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[0].expression)->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                            }else{
                                if(LookupForLval((yyvsp[0].expression)->strConst, scope)==0) {
                                    if(LookupForLval((yyvsp[0].expression)->strConst,0)==0){
                                        Insert((yyvsp[0].expression)->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        findEntry2((yyvsp[0].expression)->strConst,scope)->offset=currscopeoffset();
                                        emit(sub,(yyvsp[0].expression),newexpr_constnum(1),(yyvsp[0].expression),-1,currQuad);//quad
                                        (yyval.expression) = newexpr(arithexpr_e);
                                        (yyval.expression)->sym = newtemp(LOKAL);
                                        (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        (yyval.expression)->sym->offset=currscopeoffset();
                                        emit(assign,NULL,(yyvsp[0].expression),(yyval.expression),-1,currQuad);
                                    }
                                    else if(LookupForLval((yyvsp[0].expression)->strConst,0)==2){
                                        printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                    else if(LookupForLval((yyvsp[0].expression)->strConst,0)==3){
                                        printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==1){
                                    emit(sub,(yyvsp[0].expression),newexpr_constnum(1),(yyvsp[0].expression),-1,currQuad);   
                                    (yyval.expression) = newexpr(arithexpr_e);
                                    (yyval.expression)->sym = newtemp(LOKAL);
                                    (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();
                                    emit(assign,(yyvsp[0].expression),NULL,(yyval.expression),-1,currQuad);
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==2){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                            }
            }
#line 2155 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 561 "parser.y" /* yacc.c:1646  */
    {
                   if(checknumerical((yyvsp[-1].expression),(yyvsp[-1].expression))==0){
                                        printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                        yyerror("numerical operation problem");  
                    } 

                   if(local == 1){
                                local = 0;
                                if( LookupForLval((yyvsp[-1].expression)->strConst,scope)==0 ){ 
                                    printf(RED"ERROR"RESET" in line %d, %s is not declared\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==1){
                                  
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==2){ //userfunc
                                   
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval((yyvsp[-1].expression)->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[-1].expression)->strConst,0)==1){ 
                                }
                                else if( LookupForLval((yyvsp[-1].expression)->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[-1].expression)->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }
                            }else{
                                if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==0) {
                                    if(LookupForLval((yyvsp[-1].expression)->strConst,0)==0){
                                        Insert((yyvsp[-1].expression)->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        findEntry2((yyvsp[-1].expression)->strConst,scope)->offset=currscopeoffset();
                                        (yyval.expression) = newexpr(arithexpr_e);
                                        (yyval.expression)->sym = newtemp(LOKAL);
                                        (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        (yyval.expression)->sym->offset=currscopeoffset();
                                        emit(assign,(yyvsp[-1].expression),NULL,(yyval.expression),-1,currQuad);
                                        emit(sub,(yyvsp[-1].expression),newexpr_constnum(1),(yyvsp[-1].expression),-1,currQuad);
                                    }
                                    else if(LookupForLval((yyvsp[-1].expression)->strConst,0)==2){
                                        printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                    }
                                    else if(LookupForLval((yyvsp[-1].expression)->strConst,0)==3){
                                        printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                    }
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==1){
                                    (yyval.expression) = newexpr(arithexpr_e);
                                    (yyval.expression)->sym = newtemp(LOKAL);
                                    (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();
                                    emit(assign,(yyvsp[-1].expression),NULL,(yyval.expression),-1,currQuad);
                                    emit(sub,(yyvsp[-1].expression),newexpr_constnum(1),(yyvsp[-1].expression),-1,currQuad);       
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==2){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }
                            }
            }
#line 2227 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 628 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);}
#line 2233 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 631 "parser.y" /* yacc.c:1646  */
    {
                            //leftval=1;
                            if(local == 1){
                                local = 0;
                                if( LookupForLval((yyvsp[0].expression)->strConst,scope)==0 ){ 
                                    Insert((yyvsp[0].expression)->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    (yyvsp[0].expression)->sym = findEntry2((yyvsp[0].expression)->strConst,scope);
                                    (yyvsp[0].expression)->type = var_e;
                                    //offset
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyvsp[0].expression)->sym->offset=currscopeoffset();

                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==1){
                                   
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==2){ //userfunc
                                   
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval((yyvsp[0].expression)->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[0].expression)->strConst,0)==1){ 
                                }
                                else if( LookupForLval((yyvsp[0].expression)->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[0].expression)->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                            }else{
                                if(LookupForLval((yyvsp[0].expression)->strConst, scope)==0) {
                                    if(LookupForLval((yyvsp[0].expression)->strConst,0)==0){
                                        Insert((yyvsp[0].expression)->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                        (yyvsp[0].expression)->sym = findEntry2((yyvsp[0].expression)->strConst,scope);
                                        (yyvsp[0].expression)->type = var_e;
                                         offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        (yyvsp[0].expression)->sym->offset=currscopeoffset();
                                    }
                                    else if(LookupForLval((yyvsp[0].expression)->strConst,0)==1){ //auth peira3aaaaa
                                        (yyvsp[0].expression)->sym=findEntry2((yyvsp[0].expression)->strConst,0);                                       
                                    }
                                    else if(LookupForLval((yyvsp[0].expression)->strConst,0)==2){
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                    else if(LookupForLval((yyvsp[0].expression)->strConst,0)==3){
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==1){
                                    
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==2){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                            }
            }
#line 2299 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 691 "parser.y" /* yacc.c:1646  */
    {
                                if((yyvsp[-3].expression)->type == tableitem_e){
                                    emit(tablesetelem,(yyvsp[0].expression),NULL,(yyvsp[-3].expression),-1,currQuad);
                                    (yyval.expression)->type = assignexpr_e;
                                } else if((yyvsp[-3].expression)->type == boolexpr_e) {
                                    SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
								    patchlabelList((yyvsp[-3].expression)->falselist,currQuad);
								    emit(assign, newexpr_constbool('0'), NULL, tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 2, currQuad);
								    patchlabelList((yyvsp[-3].expression)->truelist, currQuad);
                                    emit(assign, newexpr_constbool('1'), NULL, tmpexpr, -1, currQuad);
								    emit(assign, tmpexpr, NULL, (yyvsp[-3].expression), -1, currQuad);
                                }else{
                                    //offset
                                    emit(assign,(yyvsp[0].expression),NULL,(yyvsp[-3].expression),-1,currQuad);
                                    (yyval.expression) = newexpr(assignexpr_e);
                                    (yyval.expression)->sym = newtemp(LOKAL);
                                   
                                    (yyval.expression)->type = var_e;
                                    (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();
                                    //emit(assign,$1,NULL,$$,-1,currQuad); //gia na min yparxoyn ta tmp sta quads
                                }
            }
#line 2330 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 719 "parser.y" /* yacc.c:1646  */
    {
                            if(local == 1){
                                local = 0;
                                if( LookupForLval((yyvsp[0].expression)->strConst,scope)==0 ){ 
                                    Insert((yyvsp[0].expression)->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    (yyvsp[0].expression)->sym = findEntry2((yyvsp[0].expression)->strConst,scope);
                                    (yyvsp[0].expression)->type = var_e;
                                    (yyval.expression)=(yyvsp[0].expression);
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==1){
                                   
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==2){ //userfunc
                                   
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval((yyvsp[0].expression)->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[0].expression)->strConst,0)==1){ 
                                }
                                else if( LookupForLval((yyvsp[0].expression)->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[0].expression)->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                            }else{
                                if(LookupForLval((yyvsp[0].expression)->strConst, scope)==0) {
                                    if(LookupForLval((yyvsp[0].expression)->strConst,0)==0){
                                        Insert((yyvsp[0].expression)->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                        (yyvsp[0].expression)->sym = findEntry2((yyvsp[0].expression)->strConst,scope);
                                        (yyvsp[0].expression)->type = var_e; 
                                        (yyval.expression)=(yyvsp[0].expression);  
                                    }
                                    else if(LookupForLval((yyvsp[0].expression)->strConst,0)==2){
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                    else if(LookupForLval((yyvsp[0].expression)->strConst,0)==3){
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==1){
                                        (yyval.expression)=(yyvsp[0].expression);
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==2){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                            }    
                          
            }
#line 2389 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 773 "parser.y" /* yacc.c:1646  */
    {}
#line 2395 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 774 "parser.y" /* yacc.c:1646  */
    {(yyval.expression) = (yyvsp[0].expression);}
#line 2401 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 775 "parser.y" /* yacc.c:1646  */
    {
                                                    (yyval.expression) = newexpr(programfunc_e);
                                                    (yyval.expression)->sym = (yyvsp[-1].sym);
                                                    (yyval.expression)->strConst = (yyval.expression)->sym->name;
            }
#line 2411 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 780 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);}
#line 2417 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 783 "parser.y" /* yacc.c:1646  */
    {
                            expr* tmp = (expr*)malloc(sizeof(expr));
                            tmp->strConst = strdup((yyvsp[0].strval));
                            tmp->sym = findEntry2((yyvsp[0].strval),scope); //???
                            tmp->type=var_e; //??
                            (yyval.expression) = tmp;
                           
            }
#line 2430 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 791 "parser.y" /* yacc.c:1646  */
    {
                                    local = 1;
                                    expr* tmp = (expr*)malloc(sizeof(expr));
                                    tmp->strConst = strdup((yyvsp[0].strval));
                                    tmp->type=var_e; //??
                                    (yyval.expression) = tmp;
                              
            }
#line 2443 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 799 "parser.y" /* yacc.c:1646  */
    {
                                    global = 1;
                                    //$$ = $2;
                                    expr* tmp = (expr*)malloc(sizeof(expr));
                                    tmp->strConst = strdup((yyvsp[0].strval));
                                    tmp->type=var_e; //??
                                    (yyval.expression) = tmp;
            }
#line 2456 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 807 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);}
#line 2462 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 810 "parser.y" /* yacc.c:1646  */
    {
                            if(local == 1){
                                local = 0;
                                if( LookupForLval((yyvsp[-2].expression)->strConst,scope)==0 ){ 
                                    Insert((yyvsp[-2].expression)->strConst ,scope,yylineno,0,LOKAL);
                                    (yyvsp[-2].expression)->sym = findEntry2((yyvsp[-2].expression)->strConst,scope);
                                    (yyvsp[-2].expression)->type = var_e;
                                    (yyvsp[-2].expression)->member =1;
                                }else if(LookupForLval((yyvsp[-2].expression)->strConst, scope)==1){
                                   
                                   
                                }else if(LookupForLval((yyvsp[-2].expression)->strConst, scope)==2){ //userfunc
                                    
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-2].expression)->strConst);
                                }else if(LookupForLval((yyvsp[-2].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-2].expression)->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval((yyvsp[-2].expression)->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,(yyvsp[-2].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[-2].expression)->strConst,0)==1){
                                    
                                }
                                else if( LookupForLval((yyvsp[-2].expression)->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-2].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[-2].expression)->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-2].expression)->strConst);
                                }
                            }else{
                                if(LookupForLval((yyvsp[-2].expression)->strConst, scope)==0) {
                                    if(LookupForLval((yyvsp[-2].expression)->strConst,0)==0){
                                        Insert((yyvsp[-2].expression)->strConst ,scope,yylineno,0,LOKAL);
                                        (yyvsp[-2].expression)->sym = findEntry2((yyvsp[-2].expression)->strConst,scope);
                                        (yyvsp[-2].expression)->type = var_e;
                                        (yyvsp[-2].expression)->member =1;
                                    }
                                    else if(LookupForLval((yyvsp[-2].expression)->strConst,0)==2){
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-2].expression)->strConst);
                                    }
                                    else if(LookupForLval((yyvsp[-2].expression)->strConst,0)==3){
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-2].expression)->strConst);
                                    }
                                }else if(LookupForLval((yyvsp[-2].expression)->strConst, scope)==1){
                                  
                                }else if(LookupForLval((yyvsp[-2].expression)->strConst, scope)==2){
                                    
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-2].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[-2].expression)->strConst, scope)==3){
                                  
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-2].expression)->strConst);
                                }
                            }
                            if(LookupForLval((yyvsp[-2].expression)->strConst,scope)==1){

                                if((yyvsp[-2].expression)->type == var_e){
                                    (yyvsp[-2].expression)->type = tableitem_e;
                                    (yyvsp[-2].expression)->strConst = (yyvsp[-2].expression)->sym->name;
                                    (yyvsp[-2].expression)->member =1;
                                   
                                    }
                                    (yyval.expression) = member_item((yyvsp[-2].expression),(yyvsp[0].strval));
                            }
                            else printf(" "RED" ERROR "RESET" Table %s doesnt exist in line %d \n",(yyvsp[-2].expression)->strConst,yylineno); 
            }
#line 2535 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 878 "parser.y" /* yacc.c:1646  */
    {
                    if(local == 1){
                                local = 0;
                                if( LookupForLval((yyvsp[-3].expression)->strConst,scope)==0 ){ 
                                    
                                    Insert((yyvsp[-3].expression)->strConst ,scope,yylineno,0,LOKAL);
                                    (yyvsp[-3].expression)->sym = findEntry2((yyvsp[-3].expression)->strConst,scope);
                                    (yyvsp[-3].expression)->type = var_e;
                                    (yyvsp[-3].expression)->member =1;
                                }else if(LookupForLval((yyvsp[-3].expression)->strConst, scope)==1){
                                    
                                   
                                }else if(LookupForLval((yyvsp[-3].expression)->strConst, scope)==2){ //userfunc
                                   
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-3].expression)->strConst);
                                }else if(LookupForLval((yyvsp[-3].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-3].expression)->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval((yyvsp[-3].expression)->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,(yyvsp[-3].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[-3].expression)->strConst,0)==1){
                                    
                                }
                                else if( LookupForLval((yyvsp[-3].expression)->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-3].expression)->strConst);
                                }
                                else if( LookupForLval((yyvsp[-3].expression)->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-3].expression)->strConst);
                                }
                            }else{
                                if(LookupForLval((yyvsp[-3].expression)->strConst, scope)==0) {
                                    if(LookupForLval((yyvsp[-3].expression)->strConst,0)==0){
                                        Insert((yyvsp[-3].expression)->strConst ,scope,yylineno,0,LOKAL);
                                        (yyvsp[-3].expression)->sym = findEntry2((yyvsp[-3].expression)->strConst,scope);
                                        (yyvsp[-3].expression)->type = var_e;
                                        (yyvsp[-3].expression)->member =1;
                                    }
                                    else if(LookupForLval((yyvsp[-3].expression)->strConst,0)==2){
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-3].expression)->strConst);
                                    }
                                    else if(LookupForLval((yyvsp[-3].expression)->strConst,0)==3){
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-3].expression)->strConst);
                                    }
                                }else if(LookupForLval((yyvsp[-3].expression)->strConst, scope)==1){
                                    
                                   
                                }else if(LookupForLval((yyvsp[-3].expression)->strConst, scope)==2){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-3].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[-3].expression)->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-3].expression)->strConst);
                                }
                            }
                            if(LookupForLval((yyvsp[-3].expression)->strConst,scope) == 1){
                                printf("name: %s\n",(yyvsp[-3].expression)->strConst);
                                if((yyvsp[-3].expression)->type == var_e){
                                    (yyvsp[-3].expression)->type = tableitem_e;
                                    (yyvsp[-3].expression)->strConst = (yyvsp[-3].expression)->sym->name;
                                    (yyvsp[-3].expression)->member =1;
                                }
                                (yyvsp[-3].expression)->index = (yyvsp[-1].expression);
                                (yyvsp[-3].expression)->member =1;
                                (yyvsp[-3].expression) = emit_iftableitem((yyvsp[-3].expression));
                                expr *tmp = (expr *)malloc(sizeof(expr));
                                memset(tmp , 0 , sizeof(expr));
                                tmp->type = tableitem_e;
                                tmp->member =1;
                                (yyval.expression)=tmp;
                                (yyval.expression)->sym = (yyvsp[-3].expression)->sym;
                                (yyval.expression)->strConst = (yyvsp[-3].expression)->sym->name;
                                (yyval.expression)->index = (yyvsp[-1].expression);
                            }
                            else printf(" "RED" ERROR "RESET" Table %s doesnt exist in line %d \n",(yyvsp[-3].expression)->strConst,yylineno);
            }
#line 2617 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 955 "parser.y" /* yacc.c:1646  */
    {
                    expr* tmp = (expr*)malloc(sizeof(expr));
                    tmp->strConst = strdup((yyvsp[0].strval));
                    tmp->sym = findEntry2((yyvsp[0].strval),scope);
                    (yyval.expression) = tmp;
            }
#line 2628 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 961 "parser.y" /* yacc.c:1646  */
    {}
#line 2634 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 964 "parser.y" /* yacc.c:1646  */
    {
                                                        //printf("giorgos\n");
                                                        expr* tmp=(yyvsp[-1].expression);
                                                        while(tmp!=NULL){
                                                            emit(param,tmp,NULL,NULL,-1,currQuad);
                                                            tmp=tmp->next;
                                                        }
                                                        emit(call,(yyvsp[-3].expression),NULL,NULL,-1,currQuad);
                                                        tmp=newexpr(var_e);
                                                        tmp->sym=newtemp(LOKAL);
                                                        tmp->strConst=tmp->sym->name;
                                                        //emit()
                                                        (yyval.expression)=tmp;

            }
#line 2654 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 979 "parser.y" /* yacc.c:1646  */
    {
                        if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==0) {
                            if(LookupForLval((yyvsp[-1].expression)->strConst,0)==0)
                            {
                                if(LookupForFuncRec((yyvsp[-1].expression)->strConst,scope)==2) {}
                                else printf(RED"ERROR"RESET" in line %d There is no such a func in global\n",yylineno);
                            }
                            else if(LookupForLval((yyvsp[-1].expression)->strConst,0)==1)
                            {
                                printf(RED"ERROR"RESET" in line %d is a var \n",yylineno);
                            }
                        }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==1){ 
                            printf(RED"ERROR"RESET" in line %d , %s is a var\n",yylineno, (yyvsp[-1].expression)->strConst);
                        }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==2){
                            
                        }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==3){
                            
                        }
                       
                        expr* tmp = (yyvsp[0].expression)->next;
                        while(tmp != NULL){
                            emit(param,tmp,NULL,NULL,-1,currQuad);
                            tmp = tmp->next;
                        }
                        emit(call,(yyvsp[-1].expression),NULL,NULL,-1,currQuad);
                        tmp = newexpr(var_e);
                        tmp->sym = newtemp(LOKAL);
                        tmp->strConst = tmp->sym->name;
                        emit(getretval,tmp,NULL,NULL,-1,currQuad);
                        (yyval.expression)=tmp;

                    }
#line 2691 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1011 "parser.y" /* yacc.c:1646  */
    {
                    expr* newfunc = newexpr(programfunc_e);
                    newfunc->sym = (yyvsp[-4].sym);
                    newfunc->strConst = newfunc->sym->name;
                    expr* tmp = (yyvsp[-1].expression);
                    while(tmp != NULL){
                        emit(param,tmp,NULL,NULL,-1,currQuad);
                        tmp = tmp->next;
                    }
                    emit(call,newfunc,NULL,NULL,-1,currQuad);
                    tmp = newexpr(var_e);
                    tmp->sym = newtemp(LOKAL);
                    tmp->strConst = tmp->sym->name;
                    emit(getretval,tmp,NULL,NULL,-1,currQuad);
                    (yyval.expression)=tmp;
            }
#line 2712 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1029 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);(yyval.expression)->boolConst = 1;}
#line 2718 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1030 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);(yyval.expression)->boolConst = 0;}
#line 2724 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1034 "parser.y" /* yacc.c:1646  */
    {
                                                    expr* tmp = (expr*)malloc(sizeof(expr));
                                                    tmp->strConst = (yyvsp[-3].strval);
                                                    tmp->next = (yyvsp[-1].expression);
                                                    (yyval.expression)=tmp;       
                }
#line 2735 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1043 "parser.y" /* yacc.c:1646  */
    {
                                                    expr* tmp = (expr*)malloc(sizeof(expr));
                                                    tmp->strConst = NULL;
                                                    tmp->next = (yyvsp[-1].expression);
                                                    (yyval.expression)=tmp;
            }
#line 2746 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1053 "parser.y" /* yacc.c:1646  */
    {
                        if((yyvsp[0].expression)->type==boolexpr_e){
							SymbolTableEntry *tmp = newtemp(LOKAL);
                            expr* tmpexpr = lvalue_expr(tmp);
                            patchlabelList((yyvsp[0].expression)->falselist,currQuad);
                            emit(assign, newexpr_constbool('0'), NULL, tmpexpr, -1, currQuad);
                            emit(jump, NULL, NULL, NULL, currQuad + 2, currQuad);
                            patchlabelList((yyvsp[0].expression)->truelist,currQuad + 1);
                            emit(assign, newexpr_constbool('1'), NULL, tmpexpr, -1, currQuad);
						}
                        (yyval.expression)=(yyvsp[0].expression);
                        (yyval.expression)->next=NULL;
            }
#line 2764 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1066 "parser.y" /* yacc.c:1646  */
    {
                        if(((yyvsp[0].expression)!=NULL)&&((yyvsp[0].expression)->type==boolexpr_e)){
							SymbolTableEntry *tmp = newtemp(LOKAL);
                            expr* tmpexpr = lvalue_expr(tmp);
                            patchlabelList((yyvsp[0].expression)->falselist,currQuad);
                            emit(assign, newexpr_constbool('0'), NULL, tmpexpr, -1, currQuad);
                            emit(jump, NULL, NULL, NULL, currQuad + 2, currQuad);
                            patchlabelList((yyvsp[0].expression)->truelist,currQuad);
                            emit(assign, newexpr_constbool('1'), NULL, tmpexpr, -1, currQuad);
						}
                        (yyvsp[0].expression)->next=NULL;
                        expr* tmp=(yyvsp[-2].expression);
                        while(tmp->next!=NULL) tmp=tmp->next;
                        tmp->next=(yyvsp[0].expression);
                        (yyval.expression)=(yyvsp[-2].expression);
            }
#line 2785 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1082 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=NULL;}
#line 2791 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1085 "parser.y" /* yacc.c:1646  */
    {
                                        expr* tmp=newexpr(newtable_e);
                                        tmp->sym = newtemp(LOKAL);
                                        tmp->strConst = tmp->sym->name;
                                        emit(tablecreate,NULL,NULL,tmp,-1,currQuad);
                                        int temp=0;
                                        expr* tmp2=(yyvsp[-1].expression);
                                        while(tmp2!=NULL){
                                            emit(tablesetelem,newexpr_constnum(i),tmp2,tmp,-1,currQuad);
                                            i++;
                                            tmp2=tmp2->next;
                                        }
                                        (yyval.expression)=tmp; 

            }
#line 2811 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1100 "parser.y" /* yacc.c:1646  */
    {
                                            expr* tmp=newexpr(newtable_e);
                                            tmp->sym = newtemp(LOKAL);
                                            tmp->strConst = tmp->sym->name;
                                            emit(tablecreate,NULL,NULL,tmp,-1,currQuad);
                                            int temp=0;
                                            expr* tmp2=(yyvsp[-1].expression);
                                            while(tmp2!=NULL){
                                                emit(tablesetelem,tmp2->index,tmp2,tmp,-1,currQuad);
                                                i++;
                                                tmp2=tmp2->next;
                                            }
                                            (yyval.expression)=tmp;                         
            }
#line 2830 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1116 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);}
#line 2836 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1117 "parser.y" /* yacc.c:1646  */
    {
                                            expr* tmp=(yyvsp[-2].expression);
                                            while(tmp->next!=NULL)  tmp=tmp->next;
                                            tmp=tmp->next=(yyvsp[0].expression);
                                            (yyval.expression)=(yyvsp[-2].expression);
            }
#line 2847 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1126 "parser.y" /* yacc.c:1646  */
    {
                    (yyvsp[-1].expression)->index = (yyvsp[-3].expression);
                    (yyvsp[-1].expression)->next = NULL;
                    (yyval.expression) = (yyvsp[-1].expression);
            }
#line 2857 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1133 "parser.y" /* yacc.c:1646  */
    {}
#line 2863 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1138 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 2869 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1140 "parser.y" /* yacc.c:1646  */
    {
 
        Hide(scope--);
        }
#line 2878 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1147 "parser.y" /* yacc.c:1646  */
    {//func name
                    funcname=(yyvsp[0].strval);
                    pushFunc(funcname,scope);
                    if(LookupForLval((yyvsp[0].strval), scope)==0){
                        if(LookupForLval((yyvsp[0].strval),0)==0){
                            Insert((yyvsp[0].strval),scope,yylineno,1,USERFUNC);

                        }else if(LookupForLval((yyvsp[0].strval),0)==1){
                            printf(RED"ERROR"RESET" in line %d, %s already declared globally as var \n",yylineno,(yyvsp[0].strval));
                            funcNameError=1;
                        }else if(LookupForLval((yyvsp[0].strval),0)==2){
                            printf(RED"ERROR"RESET" in line %d, %s already declared globally as userfunc \n",yylineno,(yyvsp[0].strval));
                            funcNameError=1;
                        }else if(LookupForLval((yyvsp[0].strval),0)==3){
                            printf(RED"ERROR"RESET" in line %d, %s already declared globally as libfunc \n",yylineno,(yyvsp[0].strval));
                            funcNameError=1;
                        }
                    }else if(LookupForLval((yyvsp[0].strval),scope)==1){
                        printf(RED"ERROR"RESET" in line %d, %s already declared locally as var \n",yylineno,(yyvsp[0].strval));
                        funcNameError=1;
                    }else if(LookupForLval((yyvsp[0].strval),scope)==2){
                        printf(RED"ERROR"RESET" in line %d, %s already declared locally as userfunc \n",yylineno,(yyvsp[0].strval));
                        funcNameError=1;
                    }else if(LookupForLval((yyvsp[0].strval),scope)==3){
                        printf(RED"ERROR"RESET" in line %d, %s already declared locally as libfunc \n",yylineno,(yyvsp[0].strval));
                        funcNameError=1;
                    }
                    (yyval.strval) = (yyvsp[0].strval);
        }
#line 2912 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1176 "parser.y" /* yacc.c:1646  */
    {
                
                char uname[256];
                sprintf(uname, "$%d", uf++);
                pushFunc(uname, scope);
                Insert(uname,scope,yylineno,1,USERFUNC);
                (yyval.strval) = uname;
            }
#line 2925 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1186 "parser.y" /* yacc.c:1646  */
    { 
                enterscopespace();
                inFunc=1;
                pushLoop(loop);
                loop=0;
            }
#line 2936 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1193 "parser.y" /* yacc.c:1646  */
    {
            exitscopespace();
            exitscopespace();
            inFunc=0;
            loop=popLoop()->loopcounter;
}
#line 2947 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1200 "parser.y" /* yacc.c:1646  */
    {
                                emit(jump,NULL,NULL,NULL,-1,currQuad);
                                resetfunctionlocaloffset();
                                (yyval.sym)=findEntryFunc((yyvsp[0].strval),scope);
                                if((yyval.sym)==NULL ||funcNameError==1) {}//printf("cant emit func(same name with prev func)\n");
                                else
                                {
                                    (yyval.sym)->address= nextquadlabel();
                                    emit(funcstart , NULL , NULL ,  lvalue_expr((yyval.sym)) , -1 , currQuad);
                                }                             
}
#line 2963 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1212 "parser.y" /* yacc.c:1646  */
    {
                            scope++;
                            enterscopespace();
            }
#line 2972 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1217 "parser.y" /* yacc.c:1646  */
    {
                scope--;
                resetformalargoffset();
            }
#line 2981 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1223 "parser.y" /* yacc.c:1646  */
    {
    
                    if(funcNameError==0) 
                {
                    expr* func_e = (expr*)malloc(sizeof(expr));
                    SymbolTableEntry *tmp=findEntryFunc(popFunc()->funcname,scope);
                    tmp->totallocals=functionLocalOffset;
                    func_e = lvalue_expr(tmp);
                    emit(funcend , NULL , NULL , func_e  , -1 , currQuad);

                }
                funcNameError=0;//for sure
                resetfunctionlocaloffset();


}
#line 3002 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1247 "parser.y" /* yacc.c:1646  */
    {
                            char res[50]; 
                            expr *tmp;
                            tmp=newexpr(constnum_e);
                            tmp->numConst=(yyvsp[0].intval);
                            sprintf(res, "%d", (yyvsp[0].intval));
                            tmp->strConst=strdup(res);
                            (yyval.expression)=tmp;
                             
            }
#line 3017 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1257 "parser.y" /* yacc.c:1646  */
    {
                            char res[50]; 
                            expr *tmp;
                            tmp=newexpr(constnum_e);
                            tmp->numConst=(yyvsp[0].flval);
                            sprintf(res, "%f", (yyvsp[0].flval));
                            tmp->strConst=strdup(res);
                            (yyval.expression)=tmp;
            }
#line 3031 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1266 "parser.y" /* yacc.c:1646  */
    {
                            expr *tmp;
                            tmp=newexpr(conststring_e);
                            tmp->strConst=strdup((yyvsp[0].strval));
                            (yyval.expression)=tmp;
            }
#line 3042 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1272 "parser.y" /* yacc.c:1646  */
    {
                            expr *tmp;
                            tmp=newexpr(nil_e);
                            tmp->strConst="null";
                            tmp->boolConst=(unsigned char)0;
                            (yyval.expression)=tmp;
            }
#line 3054 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1279 "parser.y" /* yacc.c:1646  */
    {
                            expr *tmp;
                            tmp=newexpr(constbool_e);
                            tmp->strConst="true";
                            tmp->boolConst=(unsigned char)1;
                            (yyval.expression)=tmp;
            }
#line 3066 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1286 "parser.y" /* yacc.c:1646  */
    {
                            expr *tmp;
                            tmp=newexpr(constbool_e);
                            tmp->strConst="false";
                            tmp->boolConst=(unsigned char)0;
                            (yyval.expression)=tmp;
            }
#line 3078 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1297 "parser.y" /* yacc.c:1646  */
    {  //gia to prwto
                            if(LookupForLval((yyvsp[0].strval), 0)==3){
                                printf(RED"ERROR"RESET" in line %d, %s is  a lib func \n",yylineno,(yyvsp[0].strval));
                            }else{
                                Insert((yyvsp[0].strval),scope,yylineno,0,FORMAL);
                                formalArgOffset++;
                                expr* tmp = (expr*)malloc(sizeof(expr));
                                tmp->strConst = strdup((yyvsp[0].strval));
                                tmp->sym = findEntry2((yyvsp[0].strval),scope); //???
                                tmp->type=var_e; //??
                                tmp->sym->type=FORMAL;
                                tmp->sym->offset=formalArgOffset;
                                tmp->sym->space=scopeSpaceCounter;
                                (yyval.expression) = tmp;

                            }
            }
#line 3100 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1314 "parser.y" /* yacc.c:1646  */
    { //gia ta upoloipa
                            if(LookupForLval((yyvsp[0].strval),0)==3){
                                printf(RED"ERROR"RESET" in line %d, %s is a lib func \n",yylineno,(yyvsp[0].strval));
                            }else if(LookupForLval((yyvsp[0].strval), scope)==1){
                                printf(RED"ERROR"RESET" in line %d, %s already declared as func \n",yylineno,(yyvsp[0].strval));
                            }else{
                                Insert((yyvsp[0].strval),scope,yylineno,0,FORMAL);
                                formalArgOffset++;
                                expr* tmp = (expr*)malloc(sizeof(expr));
                                tmp->strConst = strdup((yyvsp[0].strval));
                                tmp->sym = findEntry2((yyvsp[0].strval),scope); //???
                                tmp->type=var_e; //??
                                tmp->sym->type=FORMAL;
                                tmp->sym->offset=formalArgOffset;
                                tmp->sym->space=scopeSpaceCounter;
                                (yyval.expression) = tmp;
                            }
            }
#line 3123 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1332 "parser.y" /* yacc.c:1646  */
    {}
#line 3129 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1336 "parser.y" /* yacc.c:1646  */
    {														
								emit(if_eq, (yyvsp[-1].expression), newexpr_constbool('1'), NULL, nextquadlabel() + 3, currQuad);
				    			(yyval.intval) = nextquadlabel();
                                emit(jump, NULL, NULL, NULL, -1, currQuad);
								}
#line 3139 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1343 "parser.y" /* yacc.c:1646  */
    {
    (yyval.intval)=nextquadlabel();
    emit(jump , NULL , NULL , NULL , 0 , currQuad);
}
#line 3148 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1349 "parser.y" /* yacc.c:1646  */
    {
            patchlabel((yyvsp[-1].intval),nextquadlabel()+1);
        }
#line 3156 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1352 "parser.y" /* yacc.c:1646  */
    {
            patchlabel((yyvsp[-3].intval),(yyvsp[-1].intval)+2);
            patchlabel((yyvsp[-1].intval),nextquadlabel()+1);
		}
#line 3165 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1358 "parser.y" /* yacc.c:1646  */
    {++loop;}
#line 3171 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1361 "parser.y" /* yacc.c:1646  */
    {--loop;}
#line 3177 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1364 "parser.y" /* yacc.c:1646  */
    {
    (yyval.statement)=tmp_stmt;
}
#line 3185 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1371 "parser.y" /* yacc.c:1646  */
    {
            emit(if_eq, (yyvsp[-1].expression), newexpr_constbool('1'), NULL, nextquadlabel() + 3, currQuad);
            (yyval.intval)=nextquadlabel();
            emit(jump, NULL, NULL, NULL, -1, currQuad);

}
#line 3196 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1379 "parser.y" /* yacc.c:1646  */
    {//inWhile++;                    
                        (yyval.intval)=nextquadlabel()+1;
                        
}
#line 3205 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1387 "parser.y" /* yacc.c:1646  */
    {

                emit(jump, NULL, NULL, NULL, (yyvsp[-2].intval), currQuad);
                patchlabel((yyvsp[-1].intval),nextquadlabel()+1);
                if(tmp_stmt!=NULL && fbreak==1){    
                    patchlabel((yyvsp[0].statement)->breaklist->quadadd,nextquadlabel()+1);
                    tmp_stmt=NULL;
                    fbreak=0;
                }
                else if(tmp_stmt!=NULL && fcontinue==1){  
                    patchlabel((yyvsp[0].statement)->contlist->quadadd,(yyvsp[-2].intval));
                    tmp_stmt=NULL;
                    fcontinue=0;
                }
            }
#line 3225 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1404 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.intval) = nextquadlabel(); 
        emit(jump, NULL, NULL, NULL, -1, currQuad); 
    }
#line 3234 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1410 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.intval) = nextquadlabel(); 
    }
#line 3242 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1415 "parser.y" /* yacc.c:1646  */
    {
            for_struct* tmp=(for_struct*)malloc(sizeof(for_struct));
            loop++;
            tmp->test=(yyvsp[-2].intval);
            tmp->enter=nextquadlabel();
            emit(if_eq,(yyvsp[-1].expression), newexpr_constbool('1'), NULL, -1, currQuad); //--  
            (yyval.forval)=tmp;
        }
#line 3255 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1425 "parser.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].statement)=tmp_stmt;
            printf("stmt : %d\n",(yyvsp[-1].statement)->contlist->quadadd);
            loop--;
            patchlabel((yyvsp[-6].forval)->enter,(yyvsp[-2].intval)+2);
            patchlabel((yyvsp[-5].intval),nextquadlabel()+1);
            patchlabel((yyvsp[-2].intval),((yyvsp[-6].forval)->test)+1);
            patchlabel((yyvsp[0].intval),(yyvsp[-5].intval)+2);

             if(tmp_stmt!=NULL && fbreak==1){    
                    patchlabel((yyvsp[-1].statement)->breaklist->quadadd,nextquadlabel()+1);
                    tmp_stmt=NULL;
                    fbreak=0;
                }
                else if(tmp_stmt!=NULL && fcontinue==1){  
                    patchlabel((yyvsp[-1].statement)->contlist->quadadd,(yyvsp[-5].intval)+2);
                    tmp_stmt=NULL;
                    fcontinue=0;
                }

          
           
}
#line 3283 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1451 "parser.y" /* yacc.c:1646  */
    { 
                if(inFunc==1){
                    //emit(assign,$2,NULL,NULL,-1,currQuad);
                    emit(ret, (yyvsp[-1].expression), NULL, (yyvsp[-1].expression), -1, currQuad);
                    emit(jump,NULL,NULL,NULL,-1,currQuad);
                }
                else{
                        printf(" "RED" ERROR "RESET" Return outside of function\n");
                }
            }
#line 3298 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1461 "parser.y" /* yacc.c:1646  */
    {
                if(inFunc==1){
                    emit(ret, NULL, NULL, NULL, -1, currQuad);
                }
                else{
                        printf(" "RED" ERROR "RESET" Return outside of function\n");
                }
            }
#line 3311 "parser.c" /* yacc.c:1646  */
    break;


#line 3315 "parser.c" /* yacc.c:1646  */
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
#line 1473 "parser.y" /* yacc.c:1906  */


int yyerror(const char* yaccProvidedMessage)
{
    fprintf(stderr,"%s: at line %d, before token: %s\n",yaccProvidedMessage,yylineno,yytext);
}


int main(int argc, char **argv)
{
    CreateSymTable();
    initialize_Arrays();

    FILE *fp;
    if(argc > 1) {
        if(!(yyin = fopen(argv[1],"r"))) {
            fprintf(stderr,"cannot read file : %s \n",argv[1]);
            return 1;
        }
    }
    else { 
        yyin=stdin; 
    }

    yyparse();
    PrintSym();
    printf("---------------------------------------------------------------------------\n");
    printf("--------------------------------- QUADS -----------------------------------\n");
    printquads();
    //=======FOR LIBRARY FUNCTIONS ( INSERT IN LIBFUNC TABLE)======================
    SymbolTableEntry* temp;
    for(i=0; i<SIZE; i++){
        temp = mySymTable->buckets[i];
        if(temp!=NULL){
            while(temp != NULL){
                if(temp->line == 0 && temp->type==4) {
                    namedLibFuncs[totalNamedLibFuncs]=strdup(temp->name);
                    totalNamedLibFuncs++;
                }
                if(temp->scope == 0) globals++; // count global vars for phase5  // programVarOffset mhpws ??
                temp = temp->next;
            }
        }
    }

    namedLibFuncs[0]="print";
	namedLibFuncs[1]="input";
	namedLibFuncs[2]="objectmemberkeys";
	namedLibFuncs[3]="objecttotalmembers";
	namedLibFuncs[4]="objectcopy";
	namedLibFuncs[5]="totalarguments";
	namedLibFuncs[6]="argument";
	namedLibFuncs[7]="typeof";
	namedLibFuncs[8]="strtonum";
	namedLibFuncs[9]="sqrt";
	namedLibFuncs[10]="cos";
	namedLibFuncs[11]="sin";
    //==================================================================================   
    generate2();
    printf("------------------------------ INSTRUCTIONS -----------------------------\n");
    printInst();
    printf("-------------------------------------------------------------------------\n");
    printf("--------------------------------- TABLES --------------------------------\n");
    print_tables();
  

    FILE *fp2;
    fp2=fopen("binary.bin","w");
    if(fp2==NULL){
        printf("Den uparxei to arxeio magka\n");
    }
    else{
        ArraysToFile(fp2);
        InstructionsToFile(fp2);
        
    }

    fclose(fp2);
    
    
    return 0;
}
