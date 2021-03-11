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
#line 47 "862012666-862083506.y" /* yacc.c:1909  */

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

#line 163 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
