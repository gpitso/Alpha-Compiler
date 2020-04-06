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
    unsigned int tmpquad=0;
  
    
    #include "Quads.h"
    statement* tmp_stmt=NULL;


#line 102 "parser.c" /* yacc.c:339  */

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

union YYSTYPE
{
#line 41 "parser.y" /* yacc.c:355  */

	int intval;
	float flval;
    char* strval;
    struct expression* expression;
    struct SymbolTableEntry* sym;
    struct statement* statement;
    struct for_struct* forval;

#line 250 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 267 "parser.c" /* yacc.c:358  */

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
#define YYLAST   575

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

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
       0,   109,   109,   110,   114,   117,   121,   124,   127,   130,
     144,   155,   159,   160,   166,   174,   184,   185,   194,   206,
     218,   230,   242,   242,   260,   260,   275,   275,   291,   291,
     307,   307,   322,   322,   337,   351,   367,   370,   371,   379,
     399,   475,   548,   616,   688,   691,   691,   781,   839,   840,
     841,   846,   849,   857,   865,   873,   876,   951,  1036,  1042,
    1045,  1060,  1100,  1118,  1119,  1122,  1132,  1142,  1155,  1171,
    1174,  1189,  1205,  1206,  1215,  1222,  1224,  1227,  1227,  1237,
    1266,  1277,  1284,  1291,  1302,  1302,  1313,  1331,  1337,  1347,
    1356,  1362,  1369,  1376,  1387,  1404,  1422,  1426,  1433,  1437,
    1440,  1451,  1454,  1457,  1464,  1473,  1481,  1499,  1505,  1510,
    1520,  1547,  1555
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
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "term", "assignexpr", "$@7",
  "primary", "lvalue", "member", "call", "callsuffix", "methodcall",
  "normcall", "elist", "tabledef", "indexed", "indexedelem", "block_stmt",
  "block", "$@8", "idname", "fblock_s", "fblock_e", "fprefix", "fargs",
  "$@9", "fbody", "funcdef", "const", "idlist", "ifprefix", "elseprefix",
  "ifstmt", "loopstart", "loopend", "loopstmt", "whilecond", "whilestart",
  "whilestmt", "N", "M", "forprefix", "for", "returnstmt", YY_NULLPTR
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

#define YYPACT_NINF -169

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-169)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-46)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     157,  -169,  -169,  -169,  -169,  -169,   -12,     7,    54,   186,
    -169,  -169,   282,    78,  -169,  -169,  -169,   282,    -3,    -3,
     215,  -169,   253,  -169,    80,    31,   157,    14,    18,   326,
    -169,  -169,  -169,    56,  -169,    38,  -169,  -169,    48,  -169,
    -169,   157,  -169,    51,  -169,  -169,  -169,  -169,   282,   282,
    -169,  -169,  -169,   349,    67,  -169,    67,   112,    26,    38,
      26,   282,   512,   -30,   -28,  -169,  -169,   395,    83,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,   282,   282,   282,   282,
     282,  -169,  -169,  -169,  -169,  -169,  -169,    74,  -169,  -169,
     282,   282,   121,   125,   113,  -169,  -169,  -169,   282,   282,
     131,  -169,  -169,   132,   282,  -169,   282,   -26,   416,  -169,
     103,   303,  -169,   282,  -169,   107,    15,  -169,   109,   282,
     282,    73,    73,  -169,  -169,  -169,   282,   282,   282,   282,
     282,   282,   476,     2,  -169,   111,   282,   494,     8,  -169,
     141,   114,  -169,  -169,   157,   437,   157,  -169,    23,  -169,
    -169,   109,   282,   512,  -169,  -169,  -169,   282,   106,   106,
     526,   526,   540,   540,   540,   540,  -169,  -169,   282,   512,
    -169,  -169,  -169,    35,  -169,  -169,  -169,  -169,  -169,   282,
     458,    52,    64,  -169,   142,  -169,  -169,   157,   372,  -169,
    -169,  -169,  -169,  -169,  -169,  -169
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    88,    90,    52,    89,   105,     0,     0,    80,     0,
      14,    15,     0,     0,    92,    93,    91,     0,     0,     0,
      69,    77,     0,    13,     0,     0,     3,     0,     0,    22,
      36,    16,    44,    47,    55,    48,    49,    11,     0,    12,
      51,     0,     5,     0,     6,   107,     7,     8,    69,     0,
      79,    83,   112,    22,    39,    53,    38,     0,    40,     0,
      42,     0,    67,     0,     0,    72,    76,    22,     0,    54,
       1,     2,     9,    10,   108,   108,     0,     0,     0,     0,
       0,    30,    32,    24,    28,    26,     4,     0,    41,    43,
       0,    69,     0,     0,     0,    61,    64,    63,     0,    69,
       0,    84,    81,    99,     0,   101,    69,     0,    22,   111,
       0,    22,    70,     0,    71,     0,     0,    37,    50,     0,
       0,    17,    18,    19,    21,    20,     0,     0,     0,     0,
       0,     0,    22,     0,    56,     0,     0,    22,     0,    58,
      96,     0,    87,    98,     0,    22,     0,   106,     0,   108,
      97,     0,     0,    68,    73,    78,    75,    69,    34,    35,
      31,    33,    25,    29,    27,    23,    57,    66,    69,    46,
      59,    60,    94,     0,    82,   100,   104,   102,   107,     0,
      22,     0,     0,    85,     0,    86,   103,     0,    22,    74,
      62,    65,    95,   107,   109,   110
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,   127,   -37,  -169,  -169,    -9,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,    94,  -169,    97,  -169,
    -169,  -169,   -43,  -169,  -169,    39,  -169,    16,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,   -16,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -168,   -74,
    -169,  -169,  -169
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    87,   128,   130,   129,
     126,   127,    30,    31,    94,    32,    33,    34,    35,    95,
      96,    97,    63,    36,    64,    65,   116,    37,    66,    51,
     141,   185,    38,   102,   140,   142,    39,    40,   173,    41,
     144,    42,   146,   186,   147,   105,    43,    44,   106,   119,
      45,    46,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,   120,     3,    54,   103,   107,    68,   112,    56,   114,
     187,    62,   113,    67,   115,    13,   113,   149,     1,     2,
       3,     4,     5,     6,     7,   195,     8,     9,    48,    10,
      11,    70,    12,    13,    14,    15,    16,    57,    17,    62,
     108,   110,    24,   167,   113,    18,    19,    49,   133,   171,
     113,    20,   111,    21,   155,    22,   138,    72,    23,    50,
      24,    73,    90,   148,   178,   113,    91,   121,   122,   123,
     124,   125,    92,    93,    98,   179,   183,   184,    99,   156,
     -45,   132,    62,    55,   100,    69,    88,    89,   101,   137,
      62,   104,    90,   190,   113,   145,    91,    62,    78,    79,
      80,   -22,    92,    93,   153,   191,   113,   175,   131,   177,
     158,   159,    58,    60,   181,    59,    59,   160,   161,   162,
     163,   164,   165,     8,   118,   182,   134,   169,    76,    77,
     135,    78,    79,    80,    81,    82,   139,   136,    83,    84,
     -22,    85,   143,   180,   151,    61,   172,   192,    62,   157,
     193,   168,    21,    71,   154,     0,     0,   174,     0,    62,
       1,     2,     3,     4,     5,     6,     7,     0,     8,     9,
     188,    10,    11,     0,    12,    13,    14,    15,    16,     0,
      17,     0,     0,     0,     0,     0,     0,    18,    19,     1,
       2,     3,     4,    20,     0,    21,     0,    22,     0,     0,
      23,     0,    24,    12,    13,    14,    15,    16,     0,    17,
       0,     0,     0,     0,     0,     0,    18,    19,     1,     2,
       3,     4,    20,     0,     0,     0,    22,     0,     0,    52,
       0,    24,    12,    13,    14,    15,    16,     0,    17,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,    20,     0,    61,     0,    22,     1,     2,     3,     4,
      24,     0,     0,     0,     8,     0,     0,     0,     0,     0,
      12,    13,    14,    15,    16,     0,    17,     0,     0,     0,
       0,     0,     0,    18,    19,     1,     2,     3,     4,    20,
       0,     0,     0,    22,     0,     0,     0,     0,    24,    12,
      13,    14,    15,    16,     0,    17,     0,     0,     0,     0,
       0,     0,    18,    19,     0,     0,    74,     0,    20,    75,
       0,     0,    22,     0,     0,    76,    77,    24,    78,    79,
      80,    81,    82,     0,     0,    83,    84,     0,    85,    74,
       0,     0,    75,     0,     0,     0,     0,   152,    76,    77,
       0,    78,    79,    80,    81,    82,     0,     0,    83,    84,
       0,    85,    74,     0,     0,    75,     0,     0,     0,    86,
       0,    76,    77,     0,    78,    79,    80,    81,    82,     0,
       0,    83,    84,     0,    85,    74,     0,     0,    75,     0,
       0,     0,   109,     0,    76,    77,     0,    78,    79,    80,
      81,    82,     0,     0,    83,    84,     0,    85,    74,     0,
       0,    75,     0,     0,     0,   194,     0,    76,    77,     0,
      78,    79,    80,    81,    82,     0,     0,    83,    84,    74,
      85,     0,    75,     0,     0,     0,   117,     0,    76,    77,
       0,    78,    79,    80,    81,    82,     0,     0,    83,    84,
      74,    85,     0,    75,     0,     0,     0,   150,     0,    76,
      77,     0,    78,    79,    80,    81,    82,     0,     0,    83,
      84,    74,    85,     0,    75,     0,     0,     0,   176,     0,
      76,    77,     0,    78,    79,    80,    81,    82,     0,    74,
      83,    84,    75,    85,     0,     0,     0,   189,    76,    77,
       0,    78,    79,    80,    81,    82,     0,    74,    83,    84,
      75,    85,     0,   166,     0,     0,    76,    77,     0,    78,
      79,    80,    81,    82,     0,    74,    83,    84,    75,    85,
       0,   170,     0,     0,    76,    77,     0,    78,    79,    80,
      81,    82,     0,     0,    83,    84,   -22,    85,    76,    77,
       0,    78,    79,    80,   -46,   -46,     0,     0,    83,    84,
     -22,    85,    76,    77,     0,    78,    79,    80,     0,     0,
       0,     0,   -46,   -46,   -22,   -46
};

static const yytype_int16 yycheck[] =
{
       9,    75,     5,    12,    41,    48,    22,    37,    17,    37,
     178,    20,    42,    22,    42,    18,    42,    43,     3,     4,
       5,     6,     7,     8,     9,   193,    11,    12,    40,    14,
      15,     0,    17,    18,    19,    20,    21,    40,    23,    48,
      49,    57,    45,    41,    42,    30,    31,    40,    91,    41,
      42,    36,    61,    38,    39,    40,    99,    43,    43,     5,
      45,    43,    36,   106,    41,    42,    40,    76,    77,    78,
      79,    80,    46,    47,    36,   149,    41,    42,    40,   116,
      24,    90,    91,     5,    46,     5,    30,    31,    40,    98,
      99,    40,    36,    41,    42,   104,    40,   106,    25,    26,
      27,    34,    46,    47,   113,    41,    42,   144,    34,   146,
     119,   120,    18,    19,   157,    18,    19,   126,   127,   128,
     129,   130,   131,    11,    41,   168,     5,   136,    22,    23,
       5,    25,    26,    27,    28,    29,     5,    24,    32,    33,
      34,    35,    10,   152,    41,    38,     5,     5,   157,    40,
     187,    40,    38,    26,   115,    -1,    -1,   141,    -1,   168,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
     179,    14,    15,    -1,    17,    18,    19,    20,    21,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,     3,
       4,     5,     6,    36,    -1,    38,    -1,    40,    -1,    -1,
      43,    -1,    45,    17,    18,    19,    20,    21,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,     3,     4,
       5,     6,    36,    -1,    -1,    -1,    40,    -1,    -1,    43,
      -1,    45,    17,    18,    19,    20,    21,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    36,    -1,    38,    -1,    40,     3,     4,     5,     6,
      45,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,     3,     4,     5,     6,    36,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    45,    17,
      18,    19,    20,    21,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    13,    -1,    36,    16,
      -1,    -1,    40,    -1,    -1,    22,    23,    45,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    -1,    35,    13,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    44,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      -1,    35,    13,    -1,    -1,    16,    -1,    -1,    -1,    43,
      -1,    22,    23,    -1,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    -1,    35,    13,    -1,    -1,    16,    -1,
      -1,    -1,    43,    -1,    22,    23,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    -1,    35,    13,    -1,
      -1,    16,    -1,    -1,    -1,    43,    -1,    22,    23,    -1,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    13,
      35,    -1,    16,    -1,    -1,    -1,    41,    -1,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      13,    35,    -1,    16,    -1,    -1,    -1,    41,    -1,    22,
      23,    -1,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    13,    35,    -1,    16,    -1,    -1,    -1,    41,    -1,
      22,    23,    -1,    25,    26,    27,    28,    29,    -1,    13,
      32,    33,    16,    35,    -1,    -1,    -1,    39,    22,    23,
      -1,    25,    26,    27,    28,    29,    -1,    13,    32,    33,
      16,    35,    -1,    37,    -1,    -1,    22,    23,    -1,    25,
      26,    27,    28,    29,    -1,    13,    32,    33,    16,    35,
      -1,    37,    -1,    -1,    22,    23,    -1,    25,    26,    27,
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
      62,    63,    65,    66,    67,    68,    73,    77,    82,    86,
      87,    89,    91,    96,    97,   100,   101,   102,    40,    40,
       5,    79,    43,    55,    55,     5,    55,    40,    66,    68,
      66,    38,    55,    72,    74,    75,    78,    55,    86,     5,
       0,    51,    43,    43,    13,    16,    22,    23,    25,    26,
      27,    28,    29,    32,    33,    35,    43,    56,    30,    31,
      36,    40,    46,    47,    64,    69,    70,    71,    36,    40,
      46,    40,    83,    52,    40,    95,    98,    72,    55,    43,
      86,    55,    37,    42,    37,    42,    76,    41,    41,    99,
      99,    55,    55,    55,    55,    55,    60,    61,    57,    59,
      58,    34,    55,    72,     5,     5,    24,    55,    72,     5,
      84,    80,    85,    10,    90,    55,    92,    94,    72,    43,
      41,    41,    44,    55,    75,    39,    52,    40,    55,    55,
      55,    55,    55,    55,    55,    55,    37,    41,    40,    55,
      37,    41,     5,    88,    77,    52,    41,    52,    41,    99,
      55,    72,    72,    41,    42,    81,    93,    98,    55,    39,
      41,    41,     5,    52,    43,    98
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    54,    55,    55,    55,    55,
      55,    55,    56,    55,    57,    55,    58,    55,    59,    55,
      60,    55,    61,    55,    55,    55,    55,    62,    62,    62,
      62,    62,    62,    62,    62,    64,    63,    65,    65,    65,
      65,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      68,    68,    68,    69,    69,    70,    71,    72,    72,    72,
      73,    73,    74,    74,    75,    76,    76,    78,    77,    79,
      79,    80,    81,    82,    84,    83,    85,    86,    87,    87,
      87,    87,    87,    87,    88,    88,    88,    89,    90,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     4,     4,     1,     3,     2,     2,
       2,     2,     2,     2,     1,     0,     4,     1,     1,     1,
       3,     1,     1,     2,     2,     1,     3,     4,     3,     4,
       4,     2,     6,     1,     1,     5,     3,     1,     3,     0,
       3,     3,     1,     3,     5,     2,     0,     0,     4,     1,
       0,     0,     0,     2,     0,     4,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     4,     1,     0,
       4,     0,     0,     3,     3,     1,     3,     0,     0,     7,
       7,     3,     2
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
#line 114 "parser.y" /* yacc.c:1646  */
    {
 
            }
#line 1571 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 117 "parser.y" /* yacc.c:1646  */
    {


            }
#line 1580 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 121 "parser.y" /* yacc.c:1646  */
    {

            }
#line 1588 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 124 "parser.y" /* yacc.c:1646  */
    {

            }
#line 1596 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 127 "parser.y" /* yacc.c:1646  */
    {

            }
#line 1604 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 130 "parser.y" /* yacc.c:1646  */
    {
                    fbreak=1;
                    if(loop==0) {
                        printf(RED"ERROR"RESET" in line %d, break is defined outside of loop\n",yylineno);
                    }
                    (yyval.statement)=(yyvsp[-1].statement);
                    tmp_stmt=(yyvsp[-1].statement);


                    //blist->breaklist = insert_list(blist->breaklist,nextquadlabel());
                    //emit(jump,NULL,NULL,NULL,-1,currQuad);
                    //$1->breaklist = insert_list(blist->breaklist,nextquadlabel());  

            }
#line 1623 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "parser.y" /* yacc.c:1646  */
    {
               
                    fcontinue=1;
                    if(loop==0){
                        printf(RED"ERROR"RESET" in line %d, continue is defined outside of loop\n",yylineno);
                    }
                     (yyval.statement)=(yyvsp[-1].statement);
                     
                     tmp_stmt=(yyvsp[-1].statement);

            }
#line 1639 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 155 "parser.y" /* yacc.c:1646  */
    {
                    // $$ = (statement*)malloc(sizeof(statement));
                    // $$ = $1;
            }
#line 1648 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 159 "parser.y" /* yacc.c:1646  */
    {}
#line 1654 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 160 "parser.y" /* yacc.c:1646  */
    {
                    // $$ = (statement*)malloc(sizeof(statement));
                    // resettemp();
            }
#line 1663 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 167 "parser.y" /* yacc.c:1646  */
    {   
        (yyval.statement)=(statement*)malloc(sizeof(statement));
        (yyval.statement)->breaklist = insertb_list(nextquadlabel()); emit(jump,NULL,NULL,NULL,-1,currQuad);
        printf("break_add : %d\n",(yyval.statement)->breaklist->quadadd);
    }
#line 1673 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 175 "parser.y" /* yacc.c:1646  */
    {  
    (yyval.statement)=(statement*)malloc(sizeof(statement));
    (yyval.statement)->contlist = insertc_list(nextquadlabel()); emit(jump,NULL,NULL,NULL,-1,currQuad);
    printf("cont_add : %d\n",(yyval.statement)->contlist->quadadd);
}
#line 1683 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.expression) = (yyvsp[0].expression);}
#line 1689 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 185 "parser.y" /* yacc.c:1646  */
    {
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(add , (yyvsp[-2].expression) , (yyvsp[0].expression) , tmpexpr , -1 , currQuad);
                                (yyval.expression) = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset); //to au3anw gia to temp.
                                (yyval.expression)->sym->offset=currscopeoffset();

            }
#line 1703 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 194 "parser.y" /* yacc.c:1646  */
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
#line 1720 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 206 "parser.y" /* yacc.c:1646  */
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
#line 1737 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 218 "parser.y" /* yacc.c:1646  */
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
#line 1754 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 230 "parser.y" /* yacc.c:1646  */
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
#line 1771 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 242 "parser.y" /* yacc.c:1646  */
    {tmpquad=currQuad;}
#line 1777 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 242 "parser.y" /* yacc.c:1646  */
    {
                                   
                                    
                                    SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
							        tmpexpr->truelist=(backpatch*)make_tlist(nextquadlabel()+2);
                                    tmpexpr->falselist=(backpatch*)make_flist(nextquadlabel() + 1);
							        emit(if_greater, (yyvsp[-3].expression), (yyvsp[0].expression), NULL, currQuad + 3, currQuad);
							        emit(jump, NULL, NULL, NULL,currQuad + 4, currQuad);
                                    emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                    
                                    emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); 
                                    (yyval.expression) = tmpexpr;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();

            }
#line 1800 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 260 "parser.y" /* yacc.c:1646  */
    {tmpquad=currQuad;}
#line 1806 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 260 "parser.y" /* yacc.c:1646  */
    {
                                 SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
							        tmpexpr->truelist=(backpatch*)make_tlist(nextquadlabel()+2);
                                    tmpexpr->falselist=(backpatch*)make_flist(nextquadlabel() + 1);
							        emit(if_greater, (yyvsp[-3].expression), (yyvsp[0].expression), NULL, currQuad + 3, currQuad);
							        emit(jump, NULL, NULL, NULL,currQuad + 4, currQuad);
                                    emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                    
                                    emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); 
                                    (yyval.expression) = tmpexpr;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();           
            }
#line 1826 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 275 "parser.y" /* yacc.c:1646  */
    {tmpquad=currQuad;}
#line 1832 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 275 "parser.y" /* yacc.c:1646  */
    {

                                SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
							        tmpexpr->truelist=(backpatch*)make_tlist(nextquadlabel()+2);
                                    tmpexpr->falselist=(backpatch*)make_flist(nextquadlabel() + 1);
							        emit(if_greater, (yyvsp[-3].expression), (yyvsp[0].expression), NULL, currQuad + 3, currQuad);
							        emit(jump, NULL, NULL, NULL,currQuad + 4, currQuad);
                                    emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                    
                                    emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); 
                                    (yyval.expression) = tmpexpr;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1853 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 291 "parser.y" /* yacc.c:1646  */
    {tmpquad=currQuad;}
#line 1859 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 291 "parser.y" /* yacc.c:1646  */
    {

                                        SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
							        tmpexpr->truelist=(backpatch*)make_tlist(nextquadlabel()+2);
                                    tmpexpr->falselist=(backpatch*)make_flist(nextquadlabel() + 1);
							        emit(if_greater, (yyvsp[-3].expression), (yyvsp[0].expression), NULL, currQuad + 3, currQuad);
							        emit(jump, NULL, NULL, NULL,currQuad + 4, currQuad);
                                    emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                    
                                    emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); 
                                    (yyval.expression) = tmpexpr;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1880 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 307 "parser.y" /* yacc.c:1646  */
    {tmpquad=currQuad;}
#line 1886 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 307 "parser.y" /* yacc.c:1646  */
    {
                                    SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
							        tmpexpr->truelist=(backpatch*)make_tlist(nextquadlabel()+2);
                                    tmpexpr->falselist=(backpatch*)make_flist(nextquadlabel() + 1);
							        emit(if_greater, (yyvsp[-3].expression), (yyvsp[0].expression), NULL, currQuad + 3, currQuad);
							        emit(jump, NULL, NULL, NULL,currQuad + 4, currQuad);
                                    emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                    
                                    emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); 
                                    (yyval.expression) = tmpexpr;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1906 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 322 "parser.y" /* yacc.c:1646  */
    {tmpquad=currQuad;}
#line 1912 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 322 "parser.y" /* yacc.c:1646  */
    {
                                    SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
							        tmpexpr->truelist=(backpatch*)make_tlist(nextquadlabel()+2);
                                    tmpexpr->falselist=(backpatch*)make_flist(nextquadlabel() + 1);
							        emit(if_greater, (yyvsp[-3].expression), (yyvsp[0].expression), NULL, currQuad + 3, currQuad);
							        emit(jump, NULL, NULL, NULL,currQuad + 4, currQuad);
                                    emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                    
                                    emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); 
                                    (yyval.expression) = tmpexpr;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1932 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 337 "parser.y" /* yacc.c:1646  */
    {
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp);
                                
                                backpatchh((yyvsp[-3].expression)->falselist, tmpquad);
                                (yyvsp[-3].expression)->truelist = (yyvsp[0].expression)->truelist;
                                (yyvsp[-3].expression)->falselist = mergeList((yyvsp[-3].expression)->falselist, (yyvsp[0].expression)->falselist);

                                (yyval.expression) = (yyvsp[-3].expression);

                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                (yyval.expression)->sym->offset=currscopeoffset();
                                tmpquad=0;
            }
#line 1951 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 351 "parser.y" /* yacc.c:1646  */
    {
                         
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                
                                
                                backpatchh((yyvsp[-3].expression)->truelist, (yyvsp[0].expression)->truelist->quadadd);
                                (yyvsp[-3].expression)->truelist = mergeList((yyvsp[-3].expression)->truelist, (yyvsp[0].expression)->truelist);
                                

                                (yyvsp[-3].expression)->falselist = (yyvsp[-3].expression)->falselist;
                                
                                (yyval.expression) = (yyvsp[-3].expression);
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                (yyval.expression)->sym->offset=currscopeoffset();
            }
#line 1972 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 367 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);}
#line 1978 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 370 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[-1].expression);}
#line 1984 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 371 "parser.y" /* yacc.c:1646  */
    {
                                        checkuminusexpr((yyvsp[0].expression));
                                        (yyval.expression) = newexpr(arithexpr_e);
                                        (yyval.expression)->sym = newtemp(LOKAL);
                                        (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                        emit(uminus,NULL,(yyvsp[0].expression),(yyval.expression),-1,currQuad);
                                        
            }
#line 1997 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 379 "parser.y" /* yacc.c:1646  */
    {
                                // SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                // expr* tmpexpr = lvalue_expr(tmp); 
							    // if($2->type!=boolexpr_e) {
                                //     $2->truelist=(backpatch*)createlist(currQuad);
                                //     $2->falselist=(backpatch*)createlist(currQuad + 1);
                                //     emit(if_eq, $2, newexpr_constbool('1'), NULL, currQuad + 2, currQuad);
                                //     emit(jump, NULL, NULL, NULL, currQuad + 1, currQuad);
                                // }
                                // $$->truelist = $2->falselist;
							    // $$->falselist = $2->truelist;
                                // if(checkboolean($2,$2)==0){
                                //     printf(RED"ERROR"RESET" in line %d,try to do boolean operation on smth diff than number \n",yylineno);
                                //     yyerror("boolean operation problem");
                                // }
                                (yyval.expression) = newexpr(arithexpr_e);
                                (yyval.expression)->sym = newtemp(LOKAL);
                                (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                emit(not,NULL,(yyvsp[0].expression),(yyval.expression),-1,currQuad);
            }
#line 2022 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 399 "parser.y" /* yacc.c:1646  */
    {
                                
                                if(checknumerical((yyvsp[0].expression),(yyvsp[0].expression))==0){
                                    printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                    yyerror("numerical operation problem");  
                                }

                                if(local == 1){
                                    local = 0;
                                    if( LookupForLval((yyvsp[0].expression)->strConst,scope)==0 ){ 
                                    
                                    }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==1){
                                        // if( haveAccess(findEntry($1)) == 0){
                                        //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                        // }
                                    }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==2){ //userfunc
                                        // if(haveAccess(findEntry($1)) == 0){
                                        //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);}
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
                                            // if(inFunc==0) programVarOffset++;//offset
                                            // else functionLocalOffset++;
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
                                        // if(haveAccess(findEntry($1)) == 0){
                                        printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    
                                    }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==3){
                                        // if(haveAccess(findEntry($1)) == 0){
                                        printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                }
                              
            }
#line 2103 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 475 "parser.y" /* yacc.c:1646  */
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
                                    // if( haveAccess(findEntry($1)) == 0){
                                    //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    // }
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==2){ //userfunc
                                    // if(haveAccess(findEntry($1)) == 0){
                                    //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);}
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
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==3){
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }
                            }
      
            }
#line 2181 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 548 "parser.y" /* yacc.c:1646  */
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
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==3){
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                            }
            }
#line 2254 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 616 "parser.y" /* yacc.c:1646  */
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
                                    // if( haveAccess(findEntry($1)) == 0){
                                    //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    // }
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==2){ //userfunc
                                    // if(haveAccess(findEntry($1)) == 0){
                                    //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);}
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
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[-1].expression)->strConst, scope)==3){
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-1].expression)->strConst);
                                }
                            }
            }
#line 2331 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 688 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);}
#line 2337 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 691 "parser.y" /* yacc.c:1646  */
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
                                    // if( haveAccess(findEntry($1)) == 0){
                                    //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    // }
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==2){ //userfunc
                                    // if(haveAccess(findEntry($1)) == 0){
                                    //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);}
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
                                    else if(LookupForLval((yyvsp[0].expression)->strConst,0)==2){
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                    else if(LookupForLval((yyvsp[0].expression)->strConst,0)==3){
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                    }
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==1){
                                    
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==2){
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==3){
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                            }
            }
#line 2405 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 753 "parser.y" /* yacc.c:1646  */
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
                                    //$$->sym = findEntry2($1,scope);
                                    (yyval.expression)->type = (yyvsp[0].expression)->type;
                                    (yyval.expression)->strConst = (yyval.expression)->sym->name;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    (yyval.expression)->sym->offset=currscopeoffset();
                                    emit(assign,(yyvsp[-3].expression),NULL,(yyval.expression),-1,currQuad);
                                }
            }
#line 2436 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 781 "parser.y" /* yacc.c:1646  */
    {
                            if(local == 1){
                                local = 0;
                                if( LookupForLval((yyvsp[0].expression)->strConst,scope)==0 ){ 
                                    Insert((yyvsp[0].expression)->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    (yyvsp[0].expression)->sym = findEntry2((yyvsp[0].expression)->strConst,scope);
                                    (yyvsp[0].expression)->type = var_e;
                                    (yyval.expression)=(yyvsp[0].expression);
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==1){
                                    // if( haveAccess(findEntry($1)) == 0){
                                    //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    // }
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==2){ //userfunc
                                    // if(haveAccess(findEntry($1)) == 0){
                                    //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);}
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
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[0].expression)->strConst, scope)==3){
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[0].expression)->strConst);
                                }
                            }     
            }
#line 2499 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 839 "parser.y" /* yacc.c:1646  */
    {}
#line 2505 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 840 "parser.y" /* yacc.c:1646  */
    {(yyval.expression) = (yyvsp[0].expression);}
#line 2511 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 841 "parser.y" /* yacc.c:1646  */
    {
                                                    (yyval.expression) = newexpr(programfunc_e);
                                                    (yyval.expression)->sym = (yyvsp[-1].sym);
                                                    (yyval.expression)->strConst = (yyval.expression)->sym->name;
            }
#line 2521 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 846 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);}
#line 2527 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 849 "parser.y" /* yacc.c:1646  */
    {
                            expr* tmp = (expr*)malloc(sizeof(expr));
                            tmp->strConst = strdup((yyvsp[0].strval));
                            tmp->sym = findEntry2((yyvsp[0].strval),scope); //???
                            tmp->type=var_e; //??
                            (yyval.expression) = tmp;
                           
            }
#line 2540 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 857 "parser.y" /* yacc.c:1646  */
    {
                                    local = 1;
                                    expr* tmp = (expr*)malloc(sizeof(expr));
                                    tmp->strConst = strdup((yyvsp[0].strval));
                                    tmp->type=var_e; //??
                                    (yyval.expression) = tmp;
                              
            }
#line 2553 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 865 "parser.y" /* yacc.c:1646  */
    {
                                    global = 1;
                                    //$$ = $2;
                                    expr* tmp = (expr*)malloc(sizeof(expr));
                                    tmp->strConst = strdup((yyvsp[0].strval));
                                    tmp->type=var_e; //??
                                    (yyval.expression) = tmp;
            }
#line 2566 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 873 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);}
#line 2572 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 876 "parser.y" /* yacc.c:1646  */
    {
                            if(local == 1){
                                local = 0;
                                if( LookupForLval((yyvsp[-2].expression)->strConst,scope)==0 ){ 
                                    // printf(RED"ERROR"RESET" in line %d, %s is not declared\n",yylineno,$1->strConst);
                                    Insert((yyvsp[-2].expression)->strConst ,scope,yylineno,0,LOKAL);
                                    (yyvsp[-2].expression)->sym = findEntry2((yyvsp[-2].expression)->strConst,scope);
                                    (yyvsp[-2].expression)->type = var_e;
                                    (yyvsp[-2].expression)->member =1;
                                }else if(LookupForLval((yyvsp[-2].expression)->strConst, scope)==1){
                                    // if( haveAccess(findEntry($1)) == 0){
                                    //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    // }
                                   
                                }else if(LookupForLval((yyvsp[-2].expression)->strConst, scope)==2){ //userfunc
                                    // if(haveAccess(findEntry($1)) == 0){
                                    //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);}
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
                                        // printf(RED"ERROR"RESET" in line %d, %s is not declared\n",yylineno,$1->strConst);
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
                                    // if(haveAccess(findEntry($1)) == 0){
                                    //     //Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                   
                                }else if(LookupForLval((yyvsp[-2].expression)->strConst, scope)==2){
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-2].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[-2].expression)->strConst, scope)==3){
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-2].expression)->strConst);
                                }
                            }
                            if(LookupForLval((yyvsp[-2].expression)->strConst,scope)==1){

                                if((yyvsp[-2].expression)->type == var_e){
                                    (yyvsp[-2].expression)->type = tableitem_e;
                                    (yyvsp[-2].expression)->strConst = (yyvsp[-2].expression)->sym->name;
                                    (yyvsp[-2].expression)->member =1;
                                    //emit(tablecreate,$1,NULL,NULL,-1,currQuad);
                                    }
                                    (yyval.expression) = member_item((yyvsp[-2].expression),(yyvsp[0].strval));
                            }
                            else printf(" "RED" ERROR "RESET" Table %s doesnt exist in line %d \n",(yyvsp[-2].expression)->strConst,yylineno); 
            }
#line 2652 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 951 "parser.y" /* yacc.c:1646  */
    {
                    if(local == 1){
                                local = 0;
                                if( LookupForLval((yyvsp[-3].expression)->strConst,scope)==0 ){ 
                                    // printf(RED"ERROR"RESET" in line %d, %s is not declared\n",yylineno,$1->strConst);
                                    Insert((yyvsp[-3].expression)->strConst ,scope,yylineno,0,LOKAL);
                                    (yyvsp[-3].expression)->sym = findEntry2((yyvsp[-3].expression)->strConst,scope);
                                    (yyvsp[-3].expression)->type = var_e;
                                    (yyvsp[-3].expression)->member =1;
                                }else if(LookupForLval((yyvsp[-3].expression)->strConst, scope)==1){
                                    // if( haveAccess(findEntry($1)) == 0){
                                    //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    // }
                                   
                                }else if(LookupForLval((yyvsp[-3].expression)->strConst, scope)==2){ //userfunc
                                    // if(haveAccess(findEntry($1)) == 0){
                                    //     Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);}
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
                                        // printf(RED"ERROR"RESET" in line %d, %s is not declared\n",yylineno,$1->strConst);
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
                                    // if(haveAccess(findEntry($1)) == 0){
                                    //     //Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                   
                                }else if(LookupForLval((yyvsp[-3].expression)->strConst, scope)==2){
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,(yyvsp[-3].expression)->strConst);
                                
                                }else if(LookupForLval((yyvsp[-3].expression)->strConst, scope)==3){
                                    // if(haveAccess(findEntry($1)) == 0){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,(yyvsp[-3].expression)->strConst);
                                }
                            }
                            if(LookupForLval((yyvsp[-3].expression)->strConst,scope) == 1){
                                printf("name: %s\n",(yyvsp[-3].expression)->strConst);
                                if((yyvsp[-3].expression)->type == var_e){
                                    (yyvsp[-3].expression)->type = tableitem_e;
                                    (yyvsp[-3].expression)->strConst = (yyvsp[-3].expression)->sym->name;
                                    (yyvsp[-3].expression)->member =1;
                                    //emit(tablecreate,$1,NULL,NULL,-1,currQuad);
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
#line 2742 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1036 "parser.y" /* yacc.c:1646  */
    {
                    expr* tmp = (expr*)malloc(sizeof(expr));
                    tmp->strConst = strdup((yyvsp[0].strval));
                    tmp->sym = findEntry2((yyvsp[0].strval),scope);
                    (yyval.expression) = tmp;
            }
#line 2753 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1042 "parser.y" /* yacc.c:1646  */
    {}
#line 2759 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1045 "parser.y" /* yacc.c:1646  */
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
#line 2779 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1060 "parser.y" /* yacc.c:1646  */
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
                        // if($2->boolConst){
                        //     expr* many;
                        //     $1->type = tableitem_e;
                        //     many = $1;
                        //     $1 = member_item(self,$2->strConst);
                        //     self->next = $2->next;
                        //     $2->next = self;        
                        // }

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
#line 2824 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1100 "parser.y" /* yacc.c:1646  */
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
#line 2845 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1118 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);(yyval.expression)->boolConst = 1;}
#line 2851 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1119 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);(yyval.expression)->boolConst = 0;}
#line 2857 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1123 "parser.y" /* yacc.c:1646  */
    {
                                                    expr* tmp = (expr*)malloc(sizeof(expr));
                                                    tmp->strConst = (yyvsp[-3].strval);
                                                    tmp->next = (yyvsp[-1].expression);
                                                    (yyval.expression)=tmp;       
                }
#line 2868 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1132 "parser.y" /* yacc.c:1646  */
    {
                                                    expr* tmp = (expr*)malloc(sizeof(expr));
                                                    tmp->strConst = NULL;
                                                    tmp->next = (yyvsp[-1].expression);
                                                    (yyval.expression)=tmp;
            }
#line 2879 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1142 "parser.y" /* yacc.c:1646  */
    {
                        if((yyvsp[0].expression)->type==boolexpr_e){
							SymbolTableEntry *tmp = newtemp(LOKAL);
                            expr* tmpexpr = lvalue_expr(tmp);
                            patchlabelList((yyvsp[0].expression)->falselist,currQuad);
                            emit(assign, newexpr_constbool('0'), NULL, tmpexpr, -1, currQuad);
                            emit(jump, NULL, NULL, NULL, currQuad + 2, yylineno);
                            patchlabelList((yyvsp[0].expression)->truelist,currQuad + 1);
                            emit(assign, newexpr_constbool('1'), NULL, tmpexpr, -1, currQuad);
						}
                        (yyval.expression)=(yyvsp[0].expression);
                        (yyval.expression)->next=NULL;
            }
#line 2897 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1155 "parser.y" /* yacc.c:1646  */
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
#line 2918 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1171 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=NULL;}
#line 2924 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1174 "parser.y" /* yacc.c:1646  */
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
#line 2944 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1189 "parser.y" /* yacc.c:1646  */
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
#line 2963 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1205 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=(yyvsp[0].expression);}
#line 2969 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1206 "parser.y" /* yacc.c:1646  */
    {
                                            expr* tmp=(yyvsp[-2].expression);
                                            while(tmp->next!=NULL)  tmp=tmp->next;
                                            tmp=tmp->next=(yyvsp[0].expression);
                                            (yyval.expression)=(yyvsp[-2].expression);
            }
#line 2980 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1215 "parser.y" /* yacc.c:1646  */
    {
                    (yyvsp[-1].expression)->index = (yyvsp[-3].expression);
                    (yyvsp[-1].expression)->next = NULL;
                    (yyval.expression) = (yyvsp[-1].expression);
            }
#line 2990 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1222 "parser.y" /* yacc.c:1646  */
    {}
#line 2996 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1227 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 3002 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1229 "parser.y" /* yacc.c:1646  */
    {
        // $$ = (statement*)malloc(sizeof(statement));
        // $$ = $3;
        Hide(scope--);
        }
#line 3012 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1237 "parser.y" /* yacc.c:1646  */
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
#line 3046 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1266 "parser.y" /* yacc.c:1646  */
    {
                // char* uname = "$_%d",uf;
                // Insert(uname,scope,yylineno,1,USERFUNC); // einai i periptwsi pou to function den exei onoma p.x function(){}, 8a prepei na tou baloume ena tmp onoma, $0, $1, $2
                // $$ = uname;
                char uname[256];
                sprintf(uname, "$%d", uf++);
                Insert(uname,scope,yylineno,1,USERFUNC);
                (yyval.strval) = uname;
            }
#line 3060 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1277 "parser.y" /* yacc.c:1646  */
    { 
                enterscopespace();
                inFunc=1;
                pushLoop(loop);
                loop=0;
            }
#line 3071 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1284 "parser.y" /* yacc.c:1646  */
    {
            exitscopespace();
            exitscopespace();
            inFunc=0;
            loop=popLoop()->loopcounter;
}
#line 3082 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1291 "parser.y" /* yacc.c:1646  */
    {
                                resetfunctionlocaloffset();
                                (yyval.sym)=findEntryFunc((yyvsp[0].strval),scope);
                                if((yyval.sym)==NULL ||funcNameError==1) {}//printf("cant emit func(same name with prev func)\n");
                                else
                                {
                                    (yyval.sym)->address= nextquadlabel();
                                    emit(funcstart , NULL , NULL ,  lvalue_expr((yyval.sym)) , -1 , currQuad);
                                }                             
}
#line 3097 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1302 "parser.y" /* yacc.c:1646  */
    {
                            scope++;
                            enterscopespace();
            }
#line 3106 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1307 "parser.y" /* yacc.c:1646  */
    {
                scope--;
                resetformalargoffset();
            }
#line 3115 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1313 "parser.y" /* yacc.c:1646  */
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
#line 3136 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1337 "parser.y" /* yacc.c:1646  */
    {
                            char res[50]; 
                            expr *tmp;
                            tmp=newexpr(constnum_e);
                            tmp->numConst=(yyvsp[0].intval);
                            sprintf(res, "%d", (yyvsp[0].intval));
                            tmp->strConst=strdup(res);
                            (yyval.expression)=tmp;
                             
            }
#line 3151 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1347 "parser.y" /* yacc.c:1646  */
    {
                            char res[50]; 
                            expr *tmp;
                            tmp=newexpr(constnum_e);
                            tmp->numConst=(yyvsp[0].flval);
                            sprintf(res, "%f", (yyvsp[0].flval));
                            tmp->strConst=strdup(res);
                            (yyval.expression)=tmp;
            }
#line 3165 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1356 "parser.y" /* yacc.c:1646  */
    {
                            expr *tmp;
                            tmp=newexpr(conststring_e);
                            tmp->strConst=strdup((yyvsp[0].strval));
                            (yyval.expression)=tmp;
            }
#line 3176 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1362 "parser.y" /* yacc.c:1646  */
    {
                            expr *tmp;
                            tmp=newexpr(nil_e);
                            tmp->strConst="null";
                            tmp->boolConst=(unsigned char)0;
                            (yyval.expression)=tmp;
            }
#line 3188 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1369 "parser.y" /* yacc.c:1646  */
    {
                            expr *tmp;
                            tmp=newexpr(constbool_e);
                            tmp->strConst="true";
                            tmp->boolConst=(unsigned char)1;
                            (yyval.expression)=tmp;
            }
#line 3200 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1376 "parser.y" /* yacc.c:1646  */
    {
                            expr *tmp;
                            tmp=newexpr(constbool_e);
                            tmp->strConst="false";
                            tmp->boolConst=(unsigned char)0;
                            (yyval.expression)=tmp;
            }
#line 3212 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1387 "parser.y" /* yacc.c:1646  */
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
#line 3234 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1404 "parser.y" /* yacc.c:1646  */
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
#line 3257 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1422 "parser.y" /* yacc.c:1646  */
    {}
#line 3263 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1426 "parser.y" /* yacc.c:1646  */
    {														
								emit(if_eq, (yyvsp[-1].expression), newexpr_constbool('1'), NULL, nextquadlabel() + 3, currQuad);
				    			(yyval.intval) = nextquadlabel();
                                emit(jump, NULL, NULL, NULL, -1, currQuad);
								}
#line 3273 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1433 "parser.y" /* yacc.c:1646  */
    {
    (yyval.intval)=nextquadlabel();
    emit(jump , NULL , NULL , NULL , 0 , currQuad);
}
#line 3282 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1437 "parser.y" /* yacc.c:1646  */
    {(yyval.intval)=0;}
#line 3288 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1440 "parser.y" /* yacc.c:1646  */
    {
                           if((yyvsp[-1].intval)==0){
                                patchlabel((yyvsp[-3].intval),nextquadlabel()+1);
                           }
                           else{
                                patchlabel((yyvsp[-3].intval),(yyvsp[-1].intval)+2);
                                patchlabel((yyvsp[-1].intval),nextquadlabel()+1);
                           }
		}
#line 3302 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1451 "parser.y" /* yacc.c:1646  */
    {++loop;}
#line 3308 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1454 "parser.y" /* yacc.c:1646  */
    {--loop;}
#line 3314 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1457 "parser.y" /* yacc.c:1646  */
    {
    (yyval.statement)=tmp_stmt;
}
#line 3322 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1464 "parser.y" /* yacc.c:1646  */
    {
            emit(if_eq, (yyvsp[-1].expression), newexpr_constbool('1'), NULL, nextquadlabel() + 3, currQuad);
            (yyval.intval)=nextquadlabel();
            emit(jump, NULL, NULL, NULL, -1, currQuad);
            // pushWhile(currQuad);

}
#line 3334 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1473 "parser.y" /* yacc.c:1646  */
    {//inWhile++;                    
                        (yyval.intval)=nextquadlabel()+1;
                        
}
#line 3343 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1481 "parser.y" /* yacc.c:1646  */
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
#line 3364 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1499 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.intval) = nextquadlabel(); 
        emit(jump, NULL, NULL, NULL, -1, currQuad); 
    }
#line 3373 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1505 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.intval) = nextquadlabel(); 
    }
#line 3381 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1510 "parser.y" /* yacc.c:1646  */
    {
            for_struct* tmp=(for_struct*)malloc(sizeof(for_struct));
            loop++;
            tmp->test=(yyvsp[-2].intval);
            tmp->enter=nextquadlabel();
            emit(if_eq,(yyvsp[-1].expression), newexpr_constbool('1'), NULL, -1, currQuad); //--  
            (yyval.forval)=tmp;
        }
#line 3394 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1520 "parser.y" /* yacc.c:1646  */
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

            //patchlabel($6.breaklist,nextquadlabel());
            //patchlabel($6.contlist,$2+1);
           
}
#line 3423 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1547 "parser.y" /* yacc.c:1646  */
    { 
                if(inFunc==1){
                    emit(ret, NULL, NULL, (yyvsp[-1].expression), -1, currQuad);
                }
                else{
                        printf(" "RED" ERROR "RESET" Return outside of function\n");
                }
            }
#line 3436 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1555 "parser.y" /* yacc.c:1646  */
    {
                if(inFunc==1){
                    emit(ret, NULL, NULL, NULL, -1, currQuad);
                }
                else{
                        printf(" "RED" ERROR "RESET" Return outside of function\n");
                }
            }
#line 3449 "parser.c" /* yacc.c:1646  */
    break;


#line 3453 "parser.c" /* yacc.c:1646  */
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
#line 1567 "parser.y" /* yacc.c:1906  */


int yyerror(const char* yaccProvidedMessage)
{
    fprintf(stderr,"%s: at line %d, before token: %s\n",yaccProvidedMessage,yylineno,yytext);
}


int main(int argc, char **argv)
{
      CreateSymTable();

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
  
    printquads();
    
    return 0;
}
