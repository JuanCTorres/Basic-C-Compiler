/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ISEQUAL_T = 258,
     NOTEQUAL_T = 259,
     LESS_EQUAL_T = 260,
     GREATER_EQUAL_T = 261,
     INCREMENT_T = 262,
     DECREMENT_T = 263,
     AND_T = 264,
     OR_T = 265,
     INT_T = 266,
     WHILE_T = 267,
     FOR_T = 268,
     IF_T = 269,
     ELSE_T = 270,
     RETURN_T = 271,
     VOID_T = 272,
     READ_T = 273,
     PRINT_T = 274,
     ID_T = 275,
     UMINUS_T = 276,
     DO_T = 277,
     STRINGCONST_T = 278,
     INTCONST_T = 279,
     EOF_T = 280,
     OTHER_T = 281,
     LOWER_THAN_ELSE = 282
   };
#endif
/* Tokens.  */
#define ISEQUAL_T 258
#define NOTEQUAL_T 259
#define LESS_EQUAL_T 260
#define GREATER_EQUAL_T 261
#define INCREMENT_T 262
#define DECREMENT_T 263
#define AND_T 264
#define OR_T 265
#define INT_T 266
#define WHILE_T 267
#define FOR_T 268
#define IF_T 269
#define ELSE_T 270
#define RETURN_T 271
#define VOID_T 272
#define READ_T 273
#define PRINT_T 274
#define ID_T 275
#define UMINUS_T 276
#define DO_T 277
#define STRINGCONST_T 278
#define INTCONST_T 279
#define EOF_T 280
#define OTHER_T 281
#define LOWER_THAN_ELSE 282




/* Copy the first part of user declarations.  */
#line 18 "parser.y"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "ast.h"

#define YYSTYPE ast_node
#define YYDEBUG 1
//#define DEBUG //uncomment to see additional debugging printf

extern int yylex();
int yyerror(char *s);
extern char *yytext;
extern int YYRECOVERING();

extern int num_lines;
extern ast_node root;
extern int parseError;

extern char savedIdText[];
extern char savedLiteralText[];

//int yyerrstatus;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 187 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   531

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,     2,     2,    35,     2,     2,
      42,    43,    33,    31,    38,    32,    39,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      29,    28,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    16,    18,    20,
      24,    28,    30,    34,    38,    40,    41,    46,    51,    52,
      60,    61,    69,    71,    73,    74,    78,    80,    84,    87,
      92,    95,   100,   103,   104,   107,   108,   110,   112,   114,
     116,   118,   120,   122,   124,   126,   129,   131,   137,   145,
     151,   159,   165,   171,   179,   187,   197,   207,   213,   215,
     216,   219,   223,   227,   231,   235,   239,   243,   247,   251,
     253,   257,   259,   260,   266,   270,   274,   278,   282,   286,
     290,   294,   298,   302,   306,   310,   314,   318,   321,   324,
     326,   329,   332,   336,   338,   340,   341,   347,   349,   350,
     354,   356
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    48,    49,    -1,    49,    -1,
      48,     1,    -1,     1,    49,    -1,    50,    -1,    54,    -1,
      11,    51,    37,    -1,    51,    38,    52,    -1,    52,    -1,
      51,    38,     1,    -1,     1,    39,    52,    -1,    20,    -1,
      -1,    20,    53,    28,    73,    -1,    20,    40,    24,    41,
      -1,    -1,    11,    20,    55,    42,    57,    43,    60,    -1,
      -1,    17,    20,    56,    42,    57,    43,    60,    -1,    58,
      -1,    17,    -1,    -1,    58,    38,    59,    -1,    59,    -1,
      58,    38,     1,    -1,    11,    20,    -1,    11,    20,    40,
      41,    -1,    11,     1,    -1,    44,    61,    62,    45,    -1,
      61,    50,    -1,    -1,    62,    63,    -1,    -1,    64,    -1,
      60,    -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,
      70,    -1,    71,    -1,    72,    -1,    73,    37,    -1,    37,
      -1,    14,    42,    73,    43,    63,    -1,    14,    42,    73,
      43,    63,    15,    63,    -1,    14,    42,     1,    43,    63,
      -1,    14,    42,     1,    43,    63,    15,    63,    -1,    12,
      42,    73,    43,    63,    -1,    12,    42,     1,    43,     1,
      -1,    22,    63,    12,    42,    73,    43,    37,    -1,    22,
       1,    12,    42,     1,    43,    37,    -1,    13,    42,    69,
      37,    69,    37,    69,    43,    63,    -1,    13,    42,     1,
      37,     1,    37,     1,    43,     1,    -1,    13,    42,     1,
      43,     1,    -1,    73,    -1,    -1,    16,    37,    -1,    16,
      73,    37,    -1,    16,     1,    37,    -1,    18,    74,    37,
      -1,    18,     1,    37,    -1,    19,    73,    37,    -1,    19,
      23,    37,    -1,    19,     1,    37,    -1,    74,    28,    73,
      -1,    76,    -1,    74,    28,     1,    -1,    20,    -1,    -1,
      20,    75,    40,    73,    41,    -1,    73,    31,    73,    -1,
      73,    32,    73,    -1,    73,    33,    73,    -1,    73,    34,
      73,    -1,    73,    35,    73,    -1,    73,    29,    73,    -1,
      73,     5,    73,    -1,    73,    30,    73,    -1,    73,     6,
      73,    -1,    73,     3,    73,    -1,    73,     4,    73,    -1,
      73,     9,    73,    -1,    73,    10,    73,    -1,    36,    73,
      -1,    32,    73,    -1,    74,    -1,     7,    74,    -1,     8,
      74,    -1,    42,    73,    43,    -1,    77,    -1,    24,    -1,
      -1,    20,    78,    42,    79,    43,    -1,    80,    -1,    -1,
      80,    38,    73,    -1,    73,    -1,     1,    38,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    82,    91,    94,    95,    98,   101,   106,
     121,   130,   131,   132,   135,   140,   140,   150,   161,   161,
     173,   173,   189,   194,   198,   204,   212,   213,   216,   223,
     230,   233,   246,   262,   268,   284,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   304,   305,   314,   319,   325,
     327,   331,   336,   339,   345,   348,   357,   358,   361,   362,
     367,   371,   376,   379,   384,   387,   392,   399,   402,   410,
     411,   414,   419,   419,   433,   439,   444,   449,   454,   459,
     464,   469,   474,   479,   484,   489,   494,   499,   503,   507,
     508,   512,   516,   517,   518,   531,   531,   544,   545,   548,
     557,   558
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ISEQUAL_T", "NOTEQUAL_T",
  "LESS_EQUAL_T", "GREATER_EQUAL_T", "INCREMENT_T", "DECREMENT_T", "AND_T",
  "OR_T", "INT_T", "WHILE_T", "FOR_T", "IF_T", "ELSE_T", "RETURN_T",
  "VOID_T", "READ_T", "PRINT_T", "ID_T", "UMINUS_T", "DO_T",
  "STRINGCONST_T", "INTCONST_T", "EOF_T", "OTHER_T", "LOWER_THAN_ELSE",
  "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "';'",
  "','", "'.'", "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept",
  "program", "declarationList", "declaration", "varDeclaration",
  "varDeclList", "varDecl", "@1", "funcDeclaration", "@2", "@3",
  "formalParams", "formalList", "formalParam", "compoundStatement",
  "localDeclarations", "statementList", "statement", "expressionStatement",
  "ifStatement", "whileStatement", "doWhileStatement", "forStatement",
  "forHeaderExpression", "returnStatement", "readStatement",
  "printStatement", "expression", "var", "@4", "rValue", "call", "@5",
  "args", "argList", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    61,    60,
      62,    43,    45,    42,    47,    37,    33,    59,    44,    46,
      91,    93,    40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    48,    49,    49,    50,
      51,    51,    51,    51,    52,    53,    52,    52,    55,    54,
      56,    54,    57,    57,    57,    58,    58,    58,    59,    59,
      59,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65,    65,
      65,    66,    66,    67,    67,    68,    68,    68,    69,    69,
      70,    70,    70,    71,    71,    72,    72,    72,    73,    73,
      73,    74,    75,    74,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    78,    77,    79,    79,    80,
      80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     1,     3,
       3,     1,     3,     3,     1,     0,     4,     4,     0,     7,
       0,     7,     1,     1,     0,     3,     1,     3,     2,     4,
       2,     4,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     5,     7,     5,
       7,     5,     5,     7,     7,     9,     9,     5,     1,     0,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     0,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       2,     2,     3,     1,     1,     0,     5,     1,     0,     3,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     4,     7,     8,     6,
       0,    14,     0,    11,    20,     1,     5,     3,     0,     0,
       0,     0,     9,     0,     0,    14,    13,     0,     0,    24,
      12,    10,    24,    17,     0,     0,    71,    94,     0,     0,
       0,    16,    89,    69,    93,     0,    23,     0,    22,    26,
       0,    71,    90,    91,     0,     0,    88,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    28,     0,     0,     0,     0,     0,
      92,    83,    84,    80,    82,    85,    86,    79,    81,    74,
      75,    76,    77,    78,    70,    68,     0,    33,    19,    27,
      25,    21,     0,     0,   100,     0,    97,    29,    35,    73,
       0,    96,     0,     0,    32,     0,   101,    99,     0,     0,
       0,     0,     0,     0,     0,    46,    31,    37,    34,    36,
      38,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,     0,    58,     0,     0,    62,
      61,    64,    63,    67,    66,    65,     0,     0,     0,     0,
       0,     0,    59,     0,     0,     0,     0,    52,    51,     0,
      57,     0,    49,    47,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,    50,    48,    54,    53,     0,     0,
      56,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    12,    13,    20,     8,    21,
      24,    47,    48,    49,   127,   108,   115,   128,   129,   130,
     131,   132,   133,   155,   134,   135,   136,   137,    42,    54,
      43,    44,    55,   105,   106
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -160
static const yytype_int16 yypact[] =
{
      46,    49,     3,    -5,    30,    54,  -160,  -160,  -160,  -160,
      10,    33,    77,  -160,  -160,  -160,  -160,  -160,    36,    35,
      41,    22,  -160,     4,    37,   -19,  -160,    31,    38,    65,
    -160,  -160,    65,  -160,    63,    63,   -24,  -160,    38,    38,
      38,   465,    62,  -160,  -160,     5,  -160,    51,    67,  -160,
      64,    69,  -160,  -160,    73,    75,  -160,  -160,   236,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,   179,  -160,    78,    80,    18,    80,    38,   122,
    -160,   496,   496,   102,   102,   482,   269,   102,   102,    53,
      53,  -160,  -160,  -160,  -160,   465,    81,  -160,  -160,  -160,
    -160,  -160,   358,    87,   465,    88,    89,  -160,   108,  -160,
     139,  -160,    38,     6,  -160,   334,  -160,   465,    99,   103,
     105,   131,     7,   168,    84,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,   412,   182,   142,
     212,   115,  -160,   430,   116,   119,   120,   123,   447,   149,
     158,  -160,   128,   252,   -23,   135,   465,   134,   287,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,   140,   143,   180,   388,
     192,   193,    38,   388,   388,   194,    38,  -160,  -160,   159,
    -160,   160,   183,   186,   162,   302,   206,    38,   388,   388,
     171,   172,   169,   173,  -160,  -160,  -160,  -160,   216,   388,
    -160,  -160
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,  -160,    76,   114,  -160,    -1,  -160,  -160,  -160,
    -160,   191,  -160,   150,    24,  -160,  -160,  -121,  -160,  -160,
    -160,  -160,  -160,  -159,  -160,  -160,  -160,   -28,   -33,  -160,
    -160,  -160,  -160,  -160,  -160
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -99
static const yytype_int16 yytable[] =
{
      41,    52,    53,   150,    10,    30,    73,    10,   144,   -15,
      56,    57,    58,   181,   170,    14,   -72,    26,   -95,    99,
     171,    19,    31,    11,    25,    74,    25,    51,   193,    45,
      15,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    95,    34,    35,     1,   178,    18,
     102,   104,   182,   183,    -2,    16,    25,     2,    36,    27,
       2,   -15,    37,     3,    29,     2,     3,   194,   195,    28,
      38,     3,    33,    19,    39,   -18,    45,     9,   201,    32,
      40,    17,    46,    51,   117,   149,    69,    70,    71,   145,
      72,    34,    35,   143,    75,   148,   118,   119,   120,    98,
     121,   101,   122,   123,    36,    76,   124,    77,    37,   -72,
     153,   156,   158,    78,    22,    23,    38,    79,    96,   113,
      39,   125,   107,   103,    97,   110,    40,   112,    97,    34,
      35,   111,   141,    67,    68,    69,    70,    71,    34,    35,
     116,   138,    36,   154,   156,   139,    37,   140,   185,    34,
      35,    36,   159,   161,    38,    37,   162,   163,    39,   156,
     164,   166,    36,    38,    40,   -98,    37,    39,   142,   146,
     167,   168,   172,    40,    38,    34,    35,   173,    39,   -59,
      94,   177,   175,   152,    40,   176,    34,    35,    36,    34,
      35,   147,    37,   179,   180,   184,   186,   187,   188,    36,
      38,   189,    36,    37,    39,   190,    37,   192,   196,   197,
      40,    38,   198,   157,    38,    39,   199,   200,    39,    34,
      35,    40,   114,    50,    40,     0,   100,     0,     0,     0,
       0,     0,    36,     0,     0,     0,    37,     0,     0,    59,
      60,    61,    62,     0,    38,    63,    64,     0,    39,     0,
       0,     0,     0,     0,    40,    59,    60,    61,    62,     0,
       0,    63,    64,     0,     0,    65,    66,    67,    68,    69,
      70,    71,    59,    60,    61,    62,     0,     0,    63,    80,
       0,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      59,    60,    61,    62,     0,   169,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    59,    60,    61,    62,     0,
       0,    63,    64,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,     0,     0,     0,     0,     0,     0,     0,
     174,    65,    66,    67,    68,    69,    70,    71,     0,     0,
       0,    34,    35,     0,     0,   191,   118,   119,   120,     0,
     121,     0,   122,   123,    36,     0,   124,     0,    37,     0,
       0,    59,    60,    61,    62,     0,    38,    63,    64,     0,
      39,   125,     0,     0,     0,     0,    40,     0,    97,   126,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,    70,    71,     0,    34,    35,     0,     0,   109,
     118,   119,   120,     0,   121,     0,   122,   123,    36,     0,
     124,     0,    37,     0,     0,    59,    60,    61,    62,     0,
      38,    63,    64,     0,    39,   125,     0,     0,     0,     0,
      40,     0,    97,    59,    60,    61,    62,     0,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,   151,
      59,    60,    61,    62,     0,     0,    63,    64,     0,    65,
      66,    67,    68,    69,    70,    71,     0,   160,    59,    60,
      61,    62,     0,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,   165,    59,    60,    61,    62,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    71,     0,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,    69,
      70,    71
};

static const yytype_int16 yycheck[] =
{
      28,    34,    35,   124,     1,     1,     1,     1,     1,    28,
      38,    39,    40,   172,    37,    20,    40,    18,    42,     1,
      43,    40,    23,    20,    20,    20,    20,    20,   187,    11,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     7,     8,     1,   169,    39,
      78,    79,   173,   174,     0,     1,    20,    11,    20,    24,
      11,    28,    24,    17,    42,    11,    17,   188,   189,    28,
      32,    17,    41,    40,    36,    42,    11,     1,   199,    42,
      42,     5,    17,    20,   112,     1,    33,    34,    35,   122,
      28,     7,     8,   121,    43,   123,    12,    13,    14,    75,
      16,    77,    18,    19,    20,    38,    22,    43,    24,    40,
     138,   139,   140,    40,    37,    38,    32,    42,    40,    11,
      36,    37,    41,     1,    44,    38,    42,    38,    44,     7,
       8,    43,     1,    31,    32,    33,    34,    35,     7,     8,
       1,    42,    20,     1,   172,    42,    24,    42,   176,     7,
       8,    20,    37,    37,    32,    24,    37,    37,    36,   187,
      37,    12,    20,    32,    42,    43,    24,    36,    37,     1,
      12,    43,    37,    42,    32,     7,     8,    43,    36,    37,
       1,     1,    42,     1,    42,    42,     7,     8,    20,     7,
       8,    23,    24,     1,     1,     1,    37,    37,    15,    20,
      32,    15,    20,    24,    36,    43,    24,     1,    37,    37,
      42,    32,    43,     1,    32,    36,    43,     1,    36,     7,
       8,    42,   108,    32,    42,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    24,    -1,    -1,     3,
       4,     5,     6,    -1,    32,     9,    10,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    42,     3,     4,     5,     6,    -1,
      -1,     9,    10,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,     3,     4,     5,     6,    -1,    -1,     9,    43,
      -1,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
       3,     4,     5,     6,    -1,    43,     9,    10,    29,    30,
      31,    32,    33,    34,    35,     3,     4,     5,     6,    -1,
      -1,     9,    10,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,     7,     8,    -1,    -1,    43,    12,    13,    14,    -1,
      16,    -1,    18,    19,    20,    -1,    22,    -1,    24,    -1,
      -1,     3,     4,     5,     6,    -1,    32,     9,    10,    -1,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    -1,     7,     8,    -1,    -1,    41,
      12,    13,    14,    -1,    16,    -1,    18,    19,    20,    -1,
      22,    -1,    24,    -1,    -1,     3,     4,     5,     6,    -1,
      32,     9,    10,    -1,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    44,     3,     4,     5,     6,    -1,    -1,     9,
      10,    29,    30,    31,    32,    33,    34,    35,    -1,    37,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    29,
      30,    31,    32,    33,    34,    35,    -1,    37,     3,     4,
       5,     6,    -1,    -1,     9,    10,    29,    30,    31,    32,
      33,    34,    35,    -1,    37,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    11,    17,    47,    48,    49,    50,    54,    49,
       1,    20,    51,    52,    20,     0,     1,    49,    39,    40,
      53,    55,    37,    38,    56,    20,    52,    24,    28,    42,
       1,    52,    42,    41,     7,     8,    20,    24,    32,    36,
      42,    73,    74,    76,    77,    11,    17,    57,    58,    59,
      57,    20,    74,    74,    75,    78,    73,    73,    73,     3,
       4,     5,     6,     9,    10,    29,    30,    31,    32,    33,
      34,    35,    28,     1,    20,    43,    38,    43,    40,    42,
      43,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,     1,    73,    40,    44,    60,     1,
      59,    60,    73,     1,    73,    79,    80,    41,    61,    41,
      38,    43,    38,    11,    50,    62,     1,    73,    12,    13,
      14,    16,    18,    19,    22,    37,    45,    60,    63,    64,
      65,    66,    67,    68,    70,    71,    72,    73,    42,    42,
      42,     1,    37,    73,     1,    74,     1,    23,    73,     1,
      63,    37,     1,    73,     1,    69,    73,     1,    73,    37,
      37,    37,    37,    37,    37,    37,    12,    12,    43,    43,
      37,    43,    37,    43,    43,    42,    42,     1,    63,     1,
       1,    69,    63,    63,     1,    73,    37,    37,    15,    15,
      43,    43,     1,    69,    63,    63,    37,    37,    43,    43,
       1,    63
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 75 "parser.y"
    {
  ast_node t = create_ast_node(ROOT_N);
  t->left_child = (yyvsp[(1) - (1)]);
  root = (yyval) = t; 
;}
    break;

  case 3:
#line 82 "parser.y"
    {
  ast_node t = (yyvsp[(1) - (2)]);
  assert(t != NULL);
    while (t->right_sibling != NULL) { 
      t = t->right_sibling; 
    }
    t->right_sibling = (yyvsp[(2) - (2)]);
    (yyval) = (yyvsp[(1) - (2)]);
 ;}
    break;

  case 4:
#line 91 "parser.y"
    { 
   (yyval) = (yyvsp[(1) - (1)]);
 ;}
    break;

  case 5:
#line 94 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 6:
#line 95 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 7:
#line 98 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 8:
#line 101 "parser.y"
    {
  (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 9:
#line 106 "parser.y"
    {
  /* replaced varTypeSpecifier to INT_T*/
  (yyvsp[(2) - (3)])->return_type = INT_TYPE_N;
  ast_node temp_t = (yyvsp[(2) - (3)]);
  assert((yyvsp[(2) - (3)]) != NULL);
  while((yyvsp[(2) - (3)])->right_sibling != NULL) {
      (yyvsp[(2) - (3)])->return_type = INT_TYPE_N;
      (yyvsp[(2) - (3)]) = (yyvsp[(2) - (3)])->right_sibling;
    }
  (yyvsp[(2) - (3)])->return_type = INT_TYPE_N;
  (yyval) = temp_t;
;}
    break;

  case 10:
#line 121 "parser.y"
    {
  ast_node t = (yyvsp[(1) - (3)]);
  assert(t != NULL);
    while (t->right_sibling != NULL) { 
      t = t->right_sibling; 
    }
    t->right_sibling = (yyvsp[(3) - (3)]);
    (yyval) = (yyvsp[(1) - (3)]);
 ;}
    break;

  case 11:
#line 130 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 12:
#line 131 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 13:
#line 132 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 14:
#line 135 "parser.y"
    {
    ast_node t = create_ast_node(ID_N);
    t->value_string = strdup(savedIdText);
    (yyval) = t;
  ;}
    break;

  case 15:
#line 140 "parser.y"
    { /* embedded action needed to prevent savedidtext from being overwritten */
    ast_node t = create_ast_node(ID_N);
    t->value_string = strdup(savedIdText);
    (yyvsp[(1) - (1)]) = t;
  ;}
    break;

  case 16:
#line 144 "parser.y"
    {
    ast_node t2 = create_ast_node(OP_ASSIGN_N);
    t2->left_child = (yyvsp[(1) - (4)]);
    (yyvsp[(1) - (4)])->right_sibling = (yyvsp[(4) - (4)]);
    (yyval) = t2;
  ;}
    break;

  case 17:
#line 150 "parser.y"
    { /* array[number] */
    ast_node t1 = create_ast_node(ARRAY_TYPE_N);
    ast_node  t2 = create_ast_node(INT_LITERAL_N);
    t1->value_string = strdup(savedIdText);
    t1->left_child = t2;
    t2->value_int = atoi(savedLiteralText);

    (yyval) = t1; /* <later> catch negative array length here? */
  ;}
    break;

  case 18:
#line 161 "parser.y"
    { /* embedded action required to prevent savedIDtext from being overwritten */
  ast_node t1 = create_ast_node(FUNC_DECLARATION_N);
  t1->value_string = strdup(savedIdText);
  t1->return_type = INT_TYPE_N;
  (yyvsp[(2) - (2)]) = t1; 
  ;}
    break;

  case 19:
#line 166 "parser.y"
    {
/* removed functypespecifier, replaced with INT_T */
  ast_node t = (yyvsp[(2) - (7)]);
  t->left_child = (yyvsp[(5) - (7)]);
  t->left_child->right_sibling = (yyvsp[(7) - (7)]);
  (yyval) = t;
;}
    break;

  case 20:
#line 173 "parser.y"
    { /* embedded action required to prevent savedIDtext from being overwritten */
  ast_node t1 = create_ast_node(FUNC_DECLARATION_N);
  t1->value_string = strdup(savedIdText);
  t1->return_type = VOID_TYPE_N;
  (yyvsp[(2) - (2)]) = t1; 
  ;}
    break;

  case 21:
#line 178 "parser.y"
    {
/* removed functypespecifier, replaced with void_t */
  ast_node t = (yyvsp[(2) - (7)]);
  t->left_child = (yyvsp[(5) - (7)]);
  t->left_child->right_sibling = (yyvsp[(7) - (7)]);
  (yyval) = t;
;}
    break;

  case 22:
#line 189 "parser.y"
    {
    ast_node t = create_ast_node(FORMAL_PARAMS_N);
    t->left_child = (yyvsp[(1) - (1)]);
    (yyval) = t;
  ;}
    break;

  case 23:
#line 194 "parser.y"
    {
  ast_node t = create_ast_node(FORMAL_PARAMS_N);
  (yyval) = t; /* <later> */
;}
    break;

  case 24:
#line 198 "parser.y"
    {
  ast_node t = create_ast_node(FORMAL_PARAMS_N);
  (yyval) = t;
;}
    break;

  case 25:
#line 204 "parser.y"
    {
    ast_node t = (yyvsp[(1) - (3)]);
    while(t->right_sibling != NULL){
      t = t->right_sibling;
    }
    t->right_sibling = (yyvsp[(3) - (3)]);
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 26:
#line 212 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 27:
#line 213 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 28:
#line 216 "parser.y"
    { /* replaced varTypeSpecifier to INT_T*/
     /* error handling <later>? */
    ast_node t = create_ast_node(ID_N);
    t->value_string = strdup(savedIdText);
    t->return_type = INT_TYPE_N;
    (yyval) = t;
  ;}
    break;

  case 29:
#line 223 "parser.y"
    { /* replaced varTypeSpecifier to INT_T*/
    /*<later*/
    ast_node t = create_ast_node(ARRAY_TYPE_N);
    t->return_type = INT_TYPE_N;
    t->value_string = strdup(savedIdText);
    (yyval) = t;
  ;}
    break;

  case 30:
#line 230 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 31:
#line 233 "parser.y"
    {
  ast_node t = create_ast_node(SEQ_N);
  ast_node temp = t;
  t->left_child = (yyvsp[(2) - (4)]);
  t = t->left_child;
  while(t->right_sibling != NULL){
    t = t->right_sibling;
  }
  t->right_sibling = (yyvsp[(3) - (4)]); /* local declarations before code */
  (yyval) = temp;
;}
    break;

  case 32:
#line 246 "parser.y"
    {
  ast_node t = (yyvsp[(1) - (2)]);

  if(t->left_child == NULL) {
    t->left_child = (yyvsp[(2) - (2)]);
  }
  else {
    t = t->left_child;
    while(t->right_sibling != NULL) {
      t = t->right_sibling;
    }
    t->right_sibling = (yyvsp[(2) - (2)]);
  }

  (yyval) = (yyvsp[(1) - (2)]);
 ;}
    break;

  case 33:
#line 262 "parser.y"
    {
  ast_node t = create_ast_node(LOCAL_DECLARATIONS_N);
  (yyval) = t;
;}
    break;

  case 34:
#line 268 "parser.y"
    {
  ast_node t = (yyvsp[(1) - (2)]);

  if(t->left_child == NULL) {
    t->left_child = (yyvsp[(2) - (2)]);
  }
  else {
    t = t->left_child;
    while(t->right_sibling != NULL) {
      t = t->right_sibling;
    }
    t->right_sibling = (yyvsp[(2) - (2)]);
  }

  (yyval) = (yyvsp[(1) - (2)]);
 ;}
    break;

  case 35:
#line 284 "parser.y"
    {
  ast_node t = create_ast_node(STATEMENT_LIST_N);
  (yyval) = t;

  ;}
    break;

  case 36:
#line 293 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 37:
#line 294 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 38:
#line 295 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 39:
#line 296 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 40:
#line 297 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 41:
#line 298 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 42:
#line 299 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 43:
#line 300 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 44:
#line 301 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 45:
#line 304 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 46:
#line 305 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 47:
#line 314 "parser.y"
    {
  ast_node t = create_ast_node(IF_STMT_N);
  t->left_child = (yyvsp[(3) - (5)]);
  t->left_child->right_sibling = (yyvsp[(5) - (5)]);
  (yyval) = t; ;}
    break;

  case 48:
#line 319 "parser.y"
    {
  ast_node t = create_ast_node(IF_ELSE_STMT_N);
  t->left_child = (yyvsp[(3) - (7)]);
  t->left_child->right_sibling = (yyvsp[(5) - (7)]);
  t->left_child->right_sibling->right_sibling = (yyvsp[(7) - (7)]);
  (yyval) = t; ;}
    break;

  case 49:
#line 326 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 50:
#line 327 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 51:
#line 331 "parser.y"
    {
  ast_node t = create_ast_node(WHILE_N);
  t->left_child = (yyvsp[(3) - (5)]);
  t->left_child->right_sibling = (yyvsp[(5) - (5)]);
  (yyval) = t; ;}
    break;

  case 52:
#line 336 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 53:
#line 339 "parser.y"
    {
    ast_node t = create_ast_node(DO_WHILE_N);
    t->left_child = (yyvsp[(5) - (7)]);
    t->left_child->right_sibling = (yyvsp[(2) - (7)]);
    (yyval) = t;
  ;}
    break;

  case 54:
#line 345 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 55:
#line 348 "parser.y"
    {
    ast_node t = create_ast_node(FOR_N);
    t->left_child = (yyvsp[(3) - (9)]);
    t->left_child->right_sibling = (yyvsp[(5) - (9)]);
    t->left_child->right_sibling->right_sibling = (yyvsp[(7) - (9)]);
    t->left_child->right_sibling->right_sibling->right_sibling = (yyvsp[(9) - (9)]);

    (yyval) = t;
  ;}
    break;

  case 56:
#line 357 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 57:
#line 358 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 58:
#line 361 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 59:
#line 362 "parser.y"
    { 
    ast_node t = create_ast_node(FOR_HEADER_EMPTY_N);
  ;}
    break;

  case 60:
#line 367 "parser.y"
    {
   ast_node t = create_ast_node(RETURN_N);
   (yyval) = t;
  ;}
    break;

  case 61:
#line 371 "parser.y"
    {
    ast_node t = create_ast_node(RETURN_N);
    t->left_child = (yyvsp[(2) - (3)]);
    (yyval) = t;
  ;}
    break;

  case 62:
#line 376 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 63:
#line 379 "parser.y"
    {
    ast_node t = create_ast_node(READ_N);
    t->left_child = (yyvsp[(2) - (3)]);
    (yyval) = t;
  ;}
    break;

  case 64:
#line 384 "parser.y"
    {(yyval)=NULL;;}
    break;

  case 65:
#line 387 "parser.y"
    {
  ast_node t = create_ast_node(PRINT_N);
  t->left_child = (yyvsp[(2) - (3)]);
  (yyval) = t;
;}
    break;

  case 66:
#line 392 "parser.y"
    {
  ast_node t1 = create_ast_node(PRINT_N);
  ast_node t2 = create_ast_node(STRING_LITERAL_N);
  t2->value_string = strdup(savedLiteralText);
  t1->left_child = t2;
  (yyval) = t1;
;}
    break;

  case 67:
#line 399 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 68:
#line 402 "parser.y"
    {
    assert((yyvsp[(1) - (3)]) != NULL);
    assert((yyvsp[(3) - (3)]) != NULL);
    ast_node t = create_ast_node(OP_ASSIGN_N);
    t->left_child = (yyvsp[(1) - (3)]);
    t->left_child->right_sibling = (yyvsp[(3) - (3)]);
    (yyval) = t; 
  ;}
    break;

  case 69:
#line 410 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 70:
#line 411 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 71:
#line 414 "parser.y"
    {
   ast_node t = create_ast_node(ID_N);
   t->value_string = strdup(savedIdText);
   (yyval) = t;
 ;}
    break;

  case 72:
#line 419 "parser.y"
    {
     ast_node t1 = create_ast_node(ARRAY_TYPE_N);
     t1->value_string = strdup(savedIdText);
     (yyvsp[(1) - (1)]) = t1; 
  ;}
    break;

  case 73:
#line 423 "parser.y"
    {
     /*<later*/
   ast_node t2 = (yyvsp[(1) - (5)]);
    t2->left_child = (yyvsp[(4) - (5)]);
    (yyval) = t2;
 ;}
    break;

  case 74:
#line 433 "parser.y"
    {
ast_node t = create_ast_node(OP_PLUS_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t;
  ;}
    break;

  case 75:
#line 439 "parser.y"
    {
  ast_node t = create_ast_node(OP_MINUS_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 76:
#line 444 "parser.y"
    {
  ast_node t = create_ast_node(OP_TIMES_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 77:
#line 449 "parser.y"
    {
  ast_node t = create_ast_node(OP_DIVIDE_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 78:
#line 454 "parser.y"
    {
  ast_node t = create_ast_node(OP_MODULUS_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 79:
#line 459 "parser.y"
    {
  ast_node t = create_ast_node(OP_LESS_THAN_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 80:
#line 464 "parser.y"
    {
  ast_node t = create_ast_node(OP_LESS_EQUAL_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 81:
#line 469 "parser.y"
    {
  ast_node t = create_ast_node(OP_GREATER_THAN_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 82:
#line 474 "parser.y"
    {
  ast_node t = create_ast_node(OP_GREATER_EQUAL_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 83:
#line 479 "parser.y"
    {
  ast_node t = create_ast_node(OP_EQUALS_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 84:
#line 484 "parser.y"
    {
  ast_node t = create_ast_node(OP_NOT_EQUAL_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 85:
#line 489 "parser.y"
    {
  ast_node t = create_ast_node(OP_AND_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 86:
#line 494 "parser.y"
    {
  ast_node t = create_ast_node(OP_OR_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 87:
#line 499 "parser.y"
    {
  ast_node t = create_ast_node(OP_NOT_N);
  t->left_child = (yyvsp[(2) - (2)]);
  (yyval) = t; ;}
    break;

  case 88:
#line 503 "parser.y"
    {
  ast_node t = create_ast_node(OP_NEG_N);
  t->left_child = (yyvsp[(2) - (2)]);
  (yyval) = t; ;}
    break;

  case 89:
#line 507 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 90:
#line 508 "parser.y"
    {
  ast_node t = create_ast_node(OP_INCREMENT_N);
  t->left_child = (yyvsp[(2) - (2)]);
  (yyval) = t; ;}
    break;

  case 91:
#line 512 "parser.y"
    {
  ast_node t = create_ast_node(OP_DECREMENT_N);
  t->left_child = (yyvsp[(2) - (2)]);
  (yyval) = t; ;}
    break;

  case 92:
#line 516 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 93:
#line 517 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 94:
#line 518 "parser.y"
    {
  ast_node t = create_ast_node(INT_LITERAL_N);
  t->value_int = atoi(savedLiteralText);
  (yyval) = t;

  #ifdef DEBUG
  printf("value_int = %d\n", t->value_int);
  #endif

   ;}
    break;

  case 95:
#line 531 "parser.y"
    {
    ast_node t1 = create_ast_node(FUNCTION_N);
    t1->value_string = strdup(savedIdText);
    (yyvsp[(1) - (1)]) = t1;
  ;}
    break;

  case 96:
#line 535 "parser.y"
    {
   ast_node t2 = create_ast_node(CALL_N);
   (yyvsp[(1) - (5)])->left_child = (yyvsp[(4) - (5)]);
   
   t2->left_child = (yyvsp[(1) - (5)]);
   (yyval) = t2;
 ;}
    break;

  case 97:
#line 544 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 98:
#line 545 "parser.y"
    {(yyval) = NULL; ;}
    break;

  case 99:
#line 548 "parser.y"
    {
  ast_node t = (yyvsp[(1) - (3)]);
  assert(t != NULL);
    while (t->right_sibling != NULL) { 
      t = t->right_sibling; 
    }
    t->right_sibling = (yyvsp[(3) - (3)]);
    (yyval) = (yyvsp[(1) - (3)]);
 ;}
    break;

  case 100:
#line 557 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 101:
#line 558 "parser.y"
    {(yyval) = NULL;;}
    break;


/* Line 1267 of yacc.c.  */
#line 2450 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 567 "parser.y"

 /* this function redefinition prints out line number as well */

int yyerror(char *s) {
  parseError = 1;
  
  //if( YYRECOVERING() )
    fprintf(stderr, "%s at line %d\t yytext = '%s'\n", s, num_lines, yytext);
  return 0;
}

