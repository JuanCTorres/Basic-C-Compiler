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
#line 1 "tree.y"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "ast.h"

#define YYSTYPE ast_node
#define YYDEBUG 1
#define DEBUG

extern int yylex();
int yyerror(char *s);
extern char *yytext;

extern int num_lines;
extern ast_node root;
extern int parseError;

extern char savedIdText[];
extern char savedLiteralText[];



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
#line 184 "tree.tab.c"

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  160

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
      41,    42,    33,    31,    38,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      29,    28,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
       0,     0,     3,     5,     8,    10,    12,    14,    18,    22,
      24,    26,    30,    35,    42,    49,    51,    53,    54,    58,
      60,    63,    68,    73,    76,    77,    80,    81,    83,    85,
      87,    89,    91,    93,    95,    97,    99,   102,   104,   110,
     118,   124,   132,   138,   146,   156,   158,   159,   162,   166,
     170,   174,   178,   182,   184,   186,   191,   195,   199,   203,
     207,   211,   215,   219,   223,   227,   231,   235,   239,   243,
     246,   249,   251,   254,   257,   261,   263,   265,   270,   272,
     273,   277
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    47,    48,    -1,    48,    -1,
      49,    -1,    52,    -1,    11,    50,    37,    -1,    50,    38,
      51,    -1,    51,    -1,    20,    -1,    20,    28,    69,    -1,
      20,    39,    24,    40,    -1,    11,    20,    41,    53,    42,
      56,    -1,    17,    20,    41,    53,    42,    56,    -1,    54,
      -1,    17,    -1,    -1,    54,    38,    55,    -1,    55,    -1,
      11,    20,    -1,    11,    20,    39,    40,    -1,    43,    57,
      58,    44,    -1,    57,    49,    -1,    -1,    58,    59,    -1,
      -1,    60,    -1,    56,    -1,    61,    -1,    62,    -1,    63,
      -1,    64,    -1,    66,    -1,    67,    -1,    68,    -1,    69,
      37,    -1,    37,    -1,    14,    41,    69,    42,    59,    -1,
      14,    41,    69,    42,    59,    15,    59,    -1,    14,    41,
       1,    42,    59,    -1,    14,    41,     1,    42,    59,    15,
      59,    -1,    12,    41,    69,    42,    59,    -1,    22,    59,
      12,    41,    69,    42,    37,    -1,    13,    41,    65,    37,
      65,    37,    65,    42,    59,    -1,    69,    -1,    -1,    16,
      37,    -1,    16,    69,    37,    -1,    18,    70,    37,    -1,
      19,    69,    37,    -1,    19,    23,    37,    -1,    70,    28,
      69,    -1,    71,    -1,    20,    -1,    20,    39,    69,    40,
      -1,    69,    31,    69,    -1,    69,    32,    69,    -1,    69,
      33,    69,    -1,    69,    34,    69,    -1,    69,    35,    69,
      -1,    69,    29,    69,    -1,    69,     5,    69,    -1,    69,
      30,    69,    -1,    69,     6,    69,    -1,    69,     3,    69,
      -1,    69,     4,    69,    -1,    69,     9,    69,    -1,    69,
      10,    69,    -1,    36,    69,    -1,    32,    69,    -1,    70,
      -1,     7,    70,    -1,     8,    70,    -1,    41,    69,    42,
      -1,    72,    -1,    24,    -1,    20,    41,    73,    42,    -1,
      74,    -1,    -1,    74,    38,    69,    -1,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    61,    70,    75,    78,    83,    96,   105,
     108,   113,   121,   132,   144,   159,   164,   168,   174,   182,
     185,   192,   200,   211,   222,   225,   236,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   250,   251,   258,   263,
     269,   271,   275,   282,   290,   302,   303,   308,   312,   319,
     326,   331,   340,   346,   349,   354,   363,   369,   374,   379,
     384,   389,   394,   399,   404,   409,   414,   419,   424,   429,
     433,   437,   438,   442,   446,   447,   448,   460,   468,   469,
     472,   481
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
  "','", "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept", "program",
  "declarationList", "declaration", "varDeclaration", "varDeclList",
  "varDecl", "funcDeclaration", "formalParams", "formalList",
  "formalParam", "compoundStatement", "localDeclarations", "statementList",
  "statement", "expressionStatement", "ifStatement", "whileStatement",
  "doWhileStatement", "forStatement", "forHeaderExpression",
  "returnStatement", "readStatement", "printStatement", "expression",
  "var", "rValue", "call", "args", "argList", 0
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
      62,    43,    45,    42,    47,    37,    33,    59,    44,    91,
      93,    40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    50,    50,
      51,    51,    51,    52,    52,    53,    53,    53,    54,    54,
      55,    55,    56,    57,    57,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      61,    61,    62,    63,    64,    65,    65,    66,    66,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    73,    73,
      74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     3,     4,     6,     6,     1,     1,     0,     3,     1,
       2,     4,     4,     2,     0,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     5,     7,
       5,     7,     5,     7,     9,     1,     0,     2,     3,     3,
       3,     3,     3,     1,     1,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     2,     2,     3,     1,     1,     4,     1,     0,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     5,     6,    10,     0,
       9,     0,     1,     3,     0,     0,    17,     7,     0,    17,
       0,     0,    54,    76,     0,     0,     0,    11,    71,    53,
      75,     0,     0,    16,     0,    15,    19,    10,     8,     0,
      54,    72,    73,     0,    79,    70,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    20,     0,     0,     0,     0,    81,     0,
      78,    74,    65,    66,    62,    64,    67,    68,    61,    63,
      56,    57,    58,    59,    60,    52,     0,    24,    13,    18,
      14,    55,    77,     0,    21,    26,    80,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,    37,    22,    28,
      25,    27,    29,    30,    31,    32,    33,    34,    35,     0,
       0,    46,     0,    47,     0,     0,     0,     0,     0,    36,
       0,     0,    45,     0,     0,    48,    49,    51,    50,     0,
       0,    46,     0,     0,     0,    42,     0,    40,    38,     0,
      46,     0,     0,     0,     0,    41,    39,    43,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     9,    10,     7,    34,    35,
      36,   109,    95,    99,   110,   111,   112,   113,   114,   115,
     131,   116,   117,   118,   119,    28,    29,    30,    69,    70
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -133
static const yytype_int16 yypact[] =
{
      -4,   -17,    13,    49,    -4,  -133,  -133,  -133,   -24,    -6,
    -133,    12,  -133,  -133,   172,    32,     8,  -133,    37,     8,
      38,    38,   -33,  -133,   172,   172,   172,   356,    35,  -133,
    -133,    24,    45,  -133,    25,    30,  -133,   -23,  -133,    27,
      36,  -133,  -133,   172,   172,  -133,  -133,    67,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,  -133,    41,    39,    70,    39,   211,   356,    42,
      50,  -133,   387,   387,   -11,   -11,   372,   339,   -11,   -11,
      -7,    -7,  -133,  -133,  -133,   356,    43,  -133,  -133,  -133,
    -133,  -133,  -133,   172,  -133,    76,   356,    37,  -133,   187,
      51,    52,    53,   315,    38,   317,   240,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   264,
     172,   172,    54,  -133,   281,    66,    68,   299,    92,  -133,
     108,    73,   356,    74,   142,  -133,  -133,  -133,  -133,    78,
     240,   172,   240,   240,   172,  -133,    83,   100,   106,   156,
     172,   240,   240,    85,    81,  -133,  -133,  -133,   240,  -133
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,   120,    31,  -133,   107,  -133,   109,  -133,
      64,   -12,  -133,  -133,   -92,  -133,  -133,  -133,  -133,  -133,
    -132,  -133,  -133,  -133,   -14,   -19,  -133,  -133,  -133,  -133
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      27,    41,    42,     8,    14,    14,    43,     1,    44,   146,
      45,    46,    47,     2,   128,    15,    15,    16,   154,    32,
      56,    57,    58,    59,    60,    33,    58,    59,    60,    67,
      68,    17,    18,    11,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,   145,    12,
     147,   148,    88,    19,    90,   133,    31,    37,    40,   155,
     156,    20,    21,    61,    62,    63,   159,    64,    65,    66,
      48,    49,    50,    51,    22,    43,    52,    53,    23,    96,
      86,    32,    87,    94,    92,   125,    24,    97,    93,   124,
      25,   127,   120,   121,   122,    26,    54,    55,    56,    57,
      58,    59,    60,   136,   139,   137,   130,   132,   134,    71,
     141,    48,    49,    50,    51,   151,   142,    52,    53,   144,
     150,   152,   157,   158,    13,    38,    98,   132,    39,    89,
     149,     0,     0,     0,     0,     0,   132,    54,    55,    56,
      57,    58,    59,    60,     0,    48,    49,    50,    51,     0,
     140,    52,    53,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,     0,     0,    52,    53,     0,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    60,     0,    20,
      21,     0,     0,     0,   143,    54,    55,    56,    57,    58,
      59,    60,    22,     0,    20,    21,    23,     0,   153,   100,
     101,   102,     0,   103,    24,   104,   105,    22,    25,   106,
       0,    23,     0,    26,    48,    49,    50,    51,     0,    24,
      52,    53,     0,    25,   107,     0,     0,     0,    26,     0,
      87,   108,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    20,    21,     0,
       0,    91,   100,   101,   102,     0,   103,     0,   104,   105,
      22,     0,   106,     0,    23,     0,     0,    48,    49,    50,
      51,     0,    24,    52,    53,     0,    25,   107,     0,     0,
       0,    26,     0,    87,    48,    49,    50,    51,     0,     0,
      52,    53,     0,    54,    55,    56,    57,    58,    59,    60,
       0,   129,    48,    49,    50,    51,     0,     0,    52,    53,
      54,    55,    56,    57,    58,    59,    60,     0,   135,     0,
       0,     0,    20,    21,    20,    21,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    22,   138,    22,     0,    23,
     126,    23,    48,    49,    50,    51,     0,    24,    52,    24,
       0,    25,   123,    25,     0,     0,    26,     0,    26,    48,
      49,    50,    51,     0,     0,    52,    53,     0,    54,    55,
      56,    57,    58,    59,    60,    48,    49,    50,    51,     0,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,    50,    51,     0,     0,     0,     0,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    60
};

static const yytype_int16 yycheck[] =
{
      14,    20,    21,    20,    28,    28,    39,    11,    41,   141,
      24,    25,    26,    17,   106,    39,    39,    41,   150,    11,
      31,    32,    33,    34,    35,    17,    33,    34,    35,    43,
      44,    37,    38,    20,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   140,     0,
     142,   143,    64,    41,    66,     1,    24,    20,    20,   151,
     152,     7,     8,    28,    40,    20,   158,    42,    38,    42,
       3,     4,     5,     6,    20,    39,     9,    10,    24,    93,
      39,    11,    43,    40,    42,   104,    32,    11,    38,   103,
      36,   105,    41,    41,    41,    41,    29,    30,    31,    32,
      33,    34,    35,    37,    12,    37,   120,   121,   122,    42,
      37,     3,     4,     5,     6,    15,    42,     9,    10,    41,
      37,    15,    37,    42,     4,    18,    95,   141,    19,    65,
     144,    -1,    -1,    -1,    -1,    -1,   150,    29,    30,    31,
      32,    33,    34,    35,    -1,     3,     4,     5,     6,    -1,
      42,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    -1,     7,
       8,    -1,    -1,    -1,    42,    29,    30,    31,    32,    33,
      34,    35,    20,    -1,     7,     8,    24,    -1,    42,    12,
      13,    14,    -1,    16,    32,    18,    19,    20,    36,    22,
      -1,    24,    -1,    41,     3,     4,     5,     6,    -1,    32,
       9,    10,    -1,    36,    37,    -1,    -1,    -1,    41,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,     7,     8,    -1,
      -1,    40,    12,    13,    14,    -1,    16,    -1,    18,    19,
      20,    -1,    22,    -1,    24,    -1,    -1,     3,     4,     5,
       6,    -1,    32,     9,    10,    -1,    36,    37,    -1,    -1,
      -1,    41,    -1,    43,     3,     4,     5,     6,    -1,    -1,
       9,    10,    -1,    29,    30,    31,    32,    33,    34,    35,
      -1,    37,     3,     4,     5,     6,    -1,    -1,     9,    10,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    -1,
      -1,    -1,     7,     8,     7,     8,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    20,    37,    20,    -1,    24,
      23,    24,     3,     4,     5,     6,    -1,    32,     9,    32,
      -1,    36,    37,    36,    -1,    -1,    41,    -1,    41,     3,
       4,     5,     6,    -1,    -1,     9,    10,    -1,    29,    30,
      31,    32,    33,    34,    35,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    17,    46,    47,    48,    49,    52,    20,    50,
      51,    20,     0,    48,    28,    39,    41,    37,    38,    41,
       7,     8,    20,    24,    32,    36,    41,    69,    70,    71,
      72,    24,    11,    17,    53,    54,    55,    20,    51,    53,
      20,    70,    70,    39,    41,    69,    69,    69,     3,     4,
       5,     6,     9,    10,    29,    30,    31,    32,    33,    34,
      35,    28,    40,    20,    42,    38,    42,    69,    69,    73,
      74,    42,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    39,    43,    56,    55,
      56,    40,    42,    38,    40,    57,    69,    11,    49,    58,
      12,    13,    14,    16,    18,    19,    22,    37,    44,    56,
      59,    60,    61,    62,    63,    64,    66,    67,    68,    69,
      41,    41,    41,    37,    69,    70,    23,    69,    59,    37,
      69,    65,    69,     1,    69,    37,    37,    37,    37,    12,
      42,    37,    42,    42,    41,    59,    65,    59,    59,    69,
      37,    15,    15,    42,    65,    59,    59,    37,    42,    59
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
#line 54 "tree.y"
    {
  ast_node t = create_ast_node(ROOT_N);
  t->left_child = (yyvsp[(1) - (1)]);
  root = (yyval) = t; 
;}
    break;

  case 3:
#line 61 "tree.y"
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
#line 70 "tree.y"
    { 
   (yyval) = (yyvsp[(1) - (1)]);
 ;}
    break;

  case 5:
#line 75 "tree.y"
    {
  (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 6:
#line 78 "tree.y"
    {
  (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 7:
#line 83 "tree.y"
    {
  /* replaced varTypeSpecifier to INT_T*/
  (yyvsp[(2) - (3)])->return_type = INT_TYPE_N;
  ast_node temp_t = (yyvsp[(2) - (3)]);
  while((yyvsp[(2) - (3)])->right_sibling != NULL) {
      (yyvsp[(2) - (3)])->return_type = INT_TYPE_N;
      (yyvsp[(2) - (3)]) = (yyvsp[(2) - (3)])->right_sibling;
    }
  (yyval) = temp_t;
;}
    break;

  case 8:
#line 96 "tree.y"
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

  case 9:
#line 105 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 10:
#line 108 "tree.y"
    {
    ast_node t = create_ast_node(ID_N);
    t->value_string = strdup(savedIdText);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 11:
#line 113 "tree.y"
    {
    ast_node t1 = create_ast_node(ID_N);
    t1->value_string = strdup(savedIdText);
    ast_node t2 = create_ast_node(OP_ASSIGN_N);
    t2->left_child = t1;
    t2->left_child->right_sibling = (yyvsp[(2) - (3)]);
    (yyval) = t2;
  ;}
    break;

  case 12:
#line 121 "tree.y"
    {
    ast_node t1 = create_ast_node(ARRAY_TYPE_N);
    ast_node  t2 = create_ast_node(INT_LITERAL_N);
    t1->value_string = strdup(savedIdText);
    t1->left_child = t2;
    t2->value_int = atoi(savedLiteralText);

    (yyval) = t1; /* <later> catch negative array length here? */
  ;}
    break;

  case 13:
#line 132 "tree.y"
    {
/* removed functypespecifier, replaced with INT_T */
  ast_node t2 = create_ast_node(FUNCTION_N);
  t2->value_string = strdup(savedIdText);
  t2->left_child = (yyvsp[(4) - (6)]);
  t2->left_child->right_sibling = (yyvsp[(6) - (6)]);

  t2->return_type = INT_TYPE_N;
  (yyval) = t2;


;}
    break;

  case 14:
#line 144 "tree.y"
    {
/* removed functypespecifier, replaced with VOID_T */
  ast_node t2 = create_ast_node(FUNCTION_N);
  t2->value_string = strdup(savedIdText);
  t2->left_child = (yyvsp[(4) - (6)]);
  t2->left_child->right_sibling = (yyvsp[(6) - (6)]);

  t2->return_type = VOID_TYPE_N;
  (yyval) = t2;

;}
    break;

  case 15:
#line 159 "tree.y"
    {
    ast_node t = create_ast_node(FORMAL_PARAMS_N);
    t->left_child = (yyvsp[(1) - (1)]);
    (yyval) = t;
  ;}
    break;

  case 16:
#line 164 "tree.y"
    {
  ast_node t = create_ast_node(FORMAL_PARAMS_N);
  (yyval) = t;
;}
    break;

  case 17:
#line 168 "tree.y"
    {
  ast_node t = create_ast_node(FORMAL_PARAMS_N);
  (yyval) = t;
;}
    break;

  case 18:
#line 174 "tree.y"
    {
    ast_node t = (yyvsp[(1) - (3)]);
    while(t->right_sibling != NULL){
      t = t->right_sibling;
    }
    t->right_sibling = (yyvsp[(3) - (3)]);
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 19:
#line 182 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 20:
#line 185 "tree.y"
    { /* replaced varTypeSpecifier to INT_T*/
     /* error handling <later>? */
    ast_node t = create_ast_node(ID_N);
    t->value_string = strdup(savedIdText);
    t->return_type = INT_TYPE_N;
    (yyval) = t;
  ;}
    break;

  case 21:
#line 192 "tree.y"
    { /* replaced varTypeSpecifier to INT_T*/
    /*<later*/
    ast_node t = create_ast_node(ARRAY_TYPE_N);
    t->value_string = strdup(savedIdText);
    (yyval) = t;
  ;}
    break;

  case 22:
#line 200 "tree.y"
    {
  ast_node t = create_ast_node(SEQ_N);
  t->left_child = (yyvsp[(2) - (4)]);
  while(t->right_sibling != NULL){
    t = t->right_sibling;
  }
  t->right_sibling = (yyvsp[(3) - (4)]); /* local declarations before code */
  (yyval) = (yyvsp[(2) - (4)]);
;}
    break;

  case 23:
#line 211 "tree.y"
    {
  ast_node t = (yyvsp[(1) - (2)]);
  if (t != NULL) {
    while (t->right_sibling != NULL)
      t = t->right_sibling;
    t->right_sibling = (yyvsp[(2) - (2)]);
    (yyval) = (yyvsp[(1) - (2)]);
  }
  else
    (yyval) = (yyvsp[(2) - (2)]);
 ;}
    break;

  case 24:
#line 222 "tree.y"
    {(yyval) = NULL;;}
    break;

  case 25:
#line 225 "tree.y"
    {
  ast_node t = (yyvsp[(1) - (2)]);
  if (t != NULL) {
    while (t->right_sibling != NULL)
      t = t->right_sibling;
    t->right_sibling = (yyvsp[(2) - (2)]);
    (yyval) = (yyvsp[(1) - (2)]);
  }
  else
    (yyval) = (yyvsp[(2) - (2)]);
 ;}
    break;

  case 26:
#line 236 "tree.y"
    {(yyval) = NULL;;}
    break;

  case 27:
#line 239 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 28:
#line 240 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 29:
#line 241 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 30:
#line 242 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 31:
#line 243 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 32:
#line 244 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 33:
#line 245 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 34:
#line 246 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 35:
#line 247 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 36:
#line 250 "tree.y"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 37:
#line 251 "tree.y"
    { (yyval) = NULL; ;}
    break;

  case 38:
#line 258 "tree.y"
    {
  ast_node t = create_ast_node(IF_STMT_N);
  t->left_child = (yyvsp[(3) - (5)]);
  t->left_child->right_sibling = (yyvsp[(5) - (5)]);
  (yyval) = t; ;}
    break;

  case 39:
#line 263 "tree.y"
    {
  ast_node t = create_ast_node(IF_ELSE_STMT_N);
  t->left_child = (yyvsp[(3) - (7)]);
  t->left_child->right_sibling = (yyvsp[(5) - (7)]);
  t->left_child->right_sibling->right_sibling = (yyvsp[(7) - (7)]);
  (yyval) = t; ;}
    break;

  case 40:
#line 270 "tree.y"
    { (yyval) = NULL; ;}
    break;

  case 41:
#line 271 "tree.y"
    { (yyval) = NULL; ;}
    break;

  case 42:
#line 275 "tree.y"
    {
  ast_node t = create_ast_node(WHILE_N);
  t->left_child = (yyvsp[(3) - (5)]);
  t->left_child->right_sibling = (yyvsp[(5) - (5)]);
  (yyval) = t; ;}
    break;

  case 43:
#line 282 "tree.y"
    {
    ast_node t = create_ast_node(DO_WHILE_N);
    t->left_child = (yyvsp[(5) - (7)]);
    t->left_child->right_sibling = (yyvsp[(2) - (7)]);
    (yyval) = t;
  ;}
    break;

  case 44:
#line 290 "tree.y"
    {
    ast_node t = create_ast_node(FOR_N);
    t->left_child = (yyvsp[(3) - (9)]);
    t->left_child->right_sibling = (yyvsp[(5) - (9)]);
    t->left_child->right_sibling->right_sibling = (yyvsp[(7) - (9)]);
    t->left_child->right_sibling->right_sibling->right_sibling = (yyvsp[(9) - (9)]);

    (yyval) = t;

  ;}
    break;

  case 45:
#line 302 "tree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 46:
#line 303 "tree.y"
    { 
    ast_node t = create_ast_node(FOR_HEADER_EMPTY_N);
  ;}
    break;

  case 47:
#line 308 "tree.y"
    {
   ast_node t = create_ast_node(RETURN_N);
   (yyval) = t;
  ;}
    break;

  case 48:
#line 312 "tree.y"
    {
    ast_node t = create_ast_node(RETURN_N);
    t->left_child = (yyvsp[(2) - (3)]);
    (yyval) = t;
  ;}
    break;

  case 49:
#line 319 "tree.y"
    {
    ast_node t = create_ast_node(READ_N);
    t->left_child = (yyvsp[(2) - (3)]);
    (yyval) = t;
  ;}
    break;

  case 50:
#line 326 "tree.y"
    {
  ast_node t = create_ast_node(PRINT_N);
  t->left_child = (yyvsp[(2) - (3)]);
  (yyval) = t;
;}
    break;

  case 51:
#line 331 "tree.y"
    {
  ast_node t1 = create_ast_node(PRINT_N);
  ast_node t2 = create_ast_node(STRING_LITERAL_N);
  t2->value_string = strdup(savedLiteralText);
  t1->left_child = t2;
  (yyval) = t1;
;}
    break;

  case 52:
#line 340 "tree.y"
    {
  assert((yyvsp[(1) - (3)]) != NULL);
  ast_node t2 = create_ast_node(OP_ASSIGN_N);
  t2->left_child = (yyvsp[(1) - (3)]);
  t2->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t2; ;}
    break;

  case 53:
#line 346 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 54:
#line 349 "tree.y"
    {
   ast_node t = create_ast_node(ID_N);
   t->value_string = strdup(savedIdText);
   (yyval) = t;
 ;}
    break;

  case 55:
#line 354 "tree.y"
    {
     /*<later*/
    ast_node t = create_ast_node(ARRAY_TYPE_N);
    t->value_string = strdup(savedIdText);
    t->left_child = (yyvsp[(3) - (4)]);
    (yyval) = t;
 ;}
    break;

  case 56:
#line 363 "tree.y"
    {
ast_node t = create_ast_node(OP_PLUS_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t;
  ;}
    break;

  case 57:
#line 369 "tree.y"
    {
  ast_node t = create_ast_node(OP_MINUS_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 58:
#line 374 "tree.y"
    {
  ast_node t = create_ast_node(OP_TIMES_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 59:
#line 379 "tree.y"
    {
  ast_node t = create_ast_node(OP_DIVIDE_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 60:
#line 384 "tree.y"
    {
  ast_node t = create_ast_node(OP_MODULUS_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 61:
#line 389 "tree.y"
    {
  ast_node t = create_ast_node(OP_LESS_THAN_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 62:
#line 394 "tree.y"
    {
  ast_node t = create_ast_node(OP_LESS_EQUAL_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 63:
#line 399 "tree.y"
    {
  ast_node t = create_ast_node(OP_GREATER_THAN_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 64:
#line 404 "tree.y"
    {
  ast_node t = create_ast_node(OP_GREATER_EQUAL_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 65:
#line 409 "tree.y"
    {
  ast_node t = create_ast_node(OP_EQUALS_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 66:
#line 414 "tree.y"
    {
  ast_node t = create_ast_node(OP_NOT_EQUAL_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 67:
#line 419 "tree.y"
    {
  ast_node t = create_ast_node(OP_AND_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 68:
#line 424 "tree.y"
    {
  ast_node t = create_ast_node(OP_OR_N);
  t->left_child = (yyvsp[(1) - (3)]);
  t->left_child->right_sibling = (yyvsp[(3) - (3)]);
  (yyval) = t; ;}
    break;

  case 69:
#line 429 "tree.y"
    {
  ast_node t = create_ast_node(OP_NOT_N);
  t->left_child = (yyvsp[(2) - (2)]);
  (yyval) = t; ;}
    break;

  case 70:
#line 433 "tree.y"
    {
  ast_node t = create_ast_node(OP_NEG_N);
  t->left_child = (yyvsp[(2) - (2)]);
  (yyval) = t; ;}
    break;

  case 71:
#line 437 "tree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 72:
#line 438 "tree.y"
    {
  ast_node t = create_ast_node(OP_INCREMENT_N);
  t->left_child = (yyvsp[(2) - (2)]);
  (yyval) = t; ;}
    break;

  case 73:
#line 442 "tree.y"
    {
  ast_node t = create_ast_node(OP_DECREMENT_N);
  t->left_child = (yyvsp[(2) - (2)]);
  (yyval) = t; ;}
    break;

  case 74:
#line 446 "tree.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 75:
#line 447 "tree.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 76:
#line 448 "tree.y"
    {
  ast_node t = create_ast_node(INT_LITERAL_N);
  t->value_int = atoi(savedLiteralText);
  (yyval) = t;

  #ifdef DEBUG
  printf(" value_int = %d\n", t->value_int);
  #endif

   ;}
    break;

  case 77:
#line 460 "tree.y"
    {
   ast_node t = create_ast_node(ID_N);
   t->value_string = strdup(savedIdText);
   t->left_child = (yyvsp[(3) - (4)]);
   (yyval) = t;
 ;}
    break;

  case 78:
#line 468 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 79:
#line 469 "tree.y"
    {(yyval) = NULL; ;}
    break;

  case 80:
#line 472 "tree.y"
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

  case 81:
#line 481 "tree.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2257 "tree.tab.c"
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


#line 495 "tree.y"


int yyerror(char *s) {
  parseError = 1;
  fprintf(stderr, "%s at line %d\n yytext = '%s', savedIdText = '%s', savedLiteralText = '%s' \n", s, num_lines, yytext, savedIdText, savedLiteralText);
  return 0;
}

