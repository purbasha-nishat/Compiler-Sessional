/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 125 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
