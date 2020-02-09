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

#ifndef YY_YY_EZCOMPILER_H_INCLUDED
# define YY_YY_EZCOMPILER_H_INCLUDED
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
    S_LBRACE = 258,
    S_RBRACE = 259,
    S_LPAREN = 260,
    S_RPAREN = 261,
    S_SEM = 262,
    S_POINT = 263,
    S_DCOLON = 264,
    S_COM = 265,
    S_ADD = 266,
    S_SUB = 267,
    S_MUL = 268,
    S_DIV = 269,
    S_AND = 270,
    S_OR = 271,
    S_XOR = 272,
    S_NOT = 273,
    S_ASSIGN = 274,
    S_MOD = 275,
    S_LEQ = 276,
    S_LLT = 277,
    S_LGT = 278,
    S_LNE = 279,
    S_LLE = 280,
    S_LGE = 281,
    S_LNOT = 282,
    S_LAND = 283,
    S_LOR = 284,
    V_INT = 285,
    V_DOUBLE = 286,
    V_CHAR = 287,
    K_TRUE = 288,
    K_FALSE = 289,
    V_STRING = 290,
    V_ID = 291,
    K_CLASS = 292,
    K_DEF = 293,
    K_CONTINUE = 294,
    K_BREAK = 295,
    K_RETURN = 296,
    K_IF = 297,
    K_WHILE = 298,
    K_ELSE = 299,
    K_INT = 300,
    K_DOUBLE = 301,
    K_BOOL = 302,
    K_CHAR = 303,
    K_STRING = 304,
    K_NEW = 305,
    NEGATIVE = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{

  /* exp  */
  ExpInfo exp;
  /* formal_args  */
  ExpInfoArray formal_args;
  /* exps  */
  ExpInfoArray exps;
  /* V_STRING  */
  String V_STRING;
  /* V_ID  */
  String V_ID;
  /* val_type  */
  String val_type;
  /* id_list  */
  StringArray id_list;
  /* informal_args  */
  StringArray informal_args;
  /* val_types  */
  StringArray val_types;
  /* K_TRUE  */
  bool K_TRUE;
  /* K_FALSE  */
  bool K_FALSE;
  /* V_CHAR  */
  char V_CHAR;
  /* V_DOUBLE  */
  double V_DOUBLE;
  /* V_INT  */
  int V_INT;
#line 135 "EzCompiler.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EZCOMPILER_H_INCLUDED  */
