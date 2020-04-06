/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 41 "parser.y" /* yacc.c:1909  */

	int intval;
	float flval;
    char* strval;
    struct expression* expression;
    struct SymbolTableEntry* sym;
    struct statement* statement;
    struct for_struct* forval;

#line 162 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
