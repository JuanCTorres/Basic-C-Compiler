/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

