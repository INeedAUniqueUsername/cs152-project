%{
 #include <stdio.h>
 #include <stdlib.h>
 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;
 FILE * yyin;
%}

%union{
  double dval;
  int ival;
  char* ident;
}

%error-verbose
%start program
%token FUNCTION IF ELSE THEN RETURN ENDIF WHILE DO BEGINLOOP ENDLOOP BREAK ARRAY OF
%token BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token INTEGER READ WRITE ASSIGN COMMA SEMICOLON COLON
%token LTE GTE LT GT
%token SUB ADD MULT DIV MOD EQ NEQ 
%token L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET
%token TRUE FALSE AND OR NOT
%token <ident> IDENT
%token <dval> NUMBER
%left PLUS MINUS
%left MULT DIV
%nonassoc UMINUS

%% 
program:
		function-block				{ printf("program -> function-block\n"); }
		;
function-block:
			| function function-block { printf("function-block -> function function-block\n"); }
			;
function:
		FUNCTION identifier SEMICOLON
		BEGIN_PARAMS
		declaration-block-optional
		END_PARAMS
		BEGIN_LOCALS
		declaration-block-optional
		END_LOCALS
		BEGIN_BODY
		statement-block-optional
		END_BODY
						{ printf("function -> FUNCTION identifier SEMICOLON BEGIN_PARAMS declaration-block-optional END_PARAMS BEGIN_LOCALS declaration-block-optional END_LOCALS BEGIN_BODY statement-block-optional END_BODY\n"); }
		;
declaration-block-optional:
						{ printf("declaration-block-optional -> epsilon\n"); }
	  | declaration-block
						{ printf("declaration-block-optional -> declaration-block\n"); }
		;
declaration-block:
	    declaration SEMICOLON
			{ printf("declaration-block -> declaration SEMICOLON\n"); }
	  | declaration SEMICOLON declaration-block
			{ printf("declaration-block -> declaration SEMICOLON declaration-block\n"); }
		;
statement-block-optional:
					{ printf("statement-block-optional -> epsilon\n"); }
	  | statement-block
					{ printf("statement-block-optional -> statement-block\n"); }
		;
statement-block:
	    statement SEMICOLON
					{ printf("statement-block -> statement SEMICOLON\n"); }
	  | statement SEMICOLON statement-block
					{ printf("statement-block -> statement SEMICOLON statement-block\n"); }
		;
declaration:
		identifier-block COLON declaration-type
					{ printf("declaration -> identifier-block COLON declaration-type\n"); }
		;
declaration-type:
		INTEGER		{ printf("declaration-type -> INTEGER\n"); }
	  | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
					{ printf("declaration-type -> ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n"); }
		;
identifier-block:
		identifier		{ printf("identifier-block -> identifier\n"); }
      | identifier COMMA identifier-block
					{ printf("identifier-block -> identifier COMMA identifier-block\n"); }
		;
identifier:
		IDENT		{ printf("identifier -> IDENT(%s)\n", $1); }
		;
statement:
		var ASSIGN expression
			{ printf("statement -> var ASSIGN expression\n"); }
	  | IF bool-expr THEN statement-block ENDIF
			{ printf("statement -> IF bool-expr THEN statement-then ENDIF\n"); }
	  | IF bool-expr THEN statement-block ELSE statement-block ENDIF
			{ printf("statement -> IF bool-expr THEN statement-block ELSE statement-block ENDIF\n"); }
	  | WHILE bool-expr BEGINLOOP statement-block ENDLOOP
			{ printf("statement -> WHILE bool-expr BEGINLOOP statement-block ENDLOOP\n"); }
	  | DO BEGINLOOP statement-block ENDLOOP WHILE bool-expr
			{ printf("statement -> DO BEGINLOOP statement-block ENDLOOP WHILE bool-expr\n"); }
	  | READ var-block		{ printf("statement -> READ var-block\n"); }
	  | WRITE var-block		{ printf("statement -> WRITE var-block\n"); }
	  | BREAK				{ printf("statement -> BREAK\n"); }
	  | RETURN expression	{ printf("statement -> RETURN expression\n"); }
		;
bool-expr:
		relation-and-expr
					{ printf("bool-expr -> relation-and-expr\n"); }
	  | relation-and-expr OR bool-expr
					{ printf("bool-expr -> relation-and-expr OR bool-expr\n"); }
		;
relation-and-expr:
		relation-expr
				{ printf("relation-and-expr -> relation-expr\n"); }
	  | relation-expr AND relation-and-expr
				{ printf("relation-and-expr -> relation-expr AND relation-and-expr\n"); }
		;
relation-expr:
		relation-expr-body
				{ printf("relation-expr -> relation-expr-body\n"); }
	  | NOT relation-expr-body
				{ printf("relation-expr -> NOT relation-expr-body\n"); }
		;
relation-expr-body:
		expression comp expression
				{ printf("relation-expr-body -> expression comp expression\n"); }
	  | TRUE						{ printf("relation-expr-body -> TRUE\n"); }
	  | FALSE						{ printf("relation-expr-body -> FALSE\n"); }
	  | L_PAREN bool-expr R_PAREN	{ printf("relation-expr-body -> L_PAREN bool-expr R_PAREN\n"); }
		;
comp:
		EQ			{ printf("comp -> EQ\n"); }
	  | NEQ			{ printf("comp -> NEQ\n"); }
	  | LT			{ printf("comp -> LT\n"); }
	  | GT			{ printf("comp -> GT\n"); }
	  | LTE			{ printf("comp -> LTE\n"); }
	  | GTE			{ printf("comp -> GTE\n"); }
		;
expression:
		multiplicative-expr
					{ printf("expression -> multiplicative-expr\n"); }
	  | multiplicative-expr ADD expression 
					{ printf("expression -> multiplicative-expr ADD expression\n"); }
	  | multiplicative-expr SUB expression
					{ printf("expression -> multiplicative-expr SUB expression\n"); }
		;
multiplicative-expr:
		term		{ printf("multiplicative-expr -> term\n"); }
	  | term MULT multiplicative-expr
					{ printf("multiplicative-expr -> term MULT multiplicative-expr\n"); }
	  | term DIV multiplicative-expr
					{ printf("multiplicative-expr -> term DIV multiplicative-expr\n"); }
	  | term MOD multiplicative-expr
					{ printf("multiplicative-expr -> term MOD multiplicative-expr\n"); }
		;
term:
		term-body			{ printf("term -> term-body\n"); }
	  | MINUS term-body		{ printf("term -> MINUS term-body\n"); }
	  | IDENT L_PAREN expression-block R_PAREN
							{ printf("term -> IDENT L_PAREN expression-block R_PAREN\n"); }
		;
term-body:
		NUMBER		{ printf("term-body -> NUMBER\n"); }
	  | var			{ printf("term-body -> var\n"); }
	  | L_PAREN expression R_PAREN
					{ printf("term-body -> L_PAREN expression R_PAREN\n"); }
		;
expression-block:
		expression	{ printf("expression-block -> expression\n"); }
	  | expression COMMA expression-block
					{ printf("expression-block -> expression COMMA expression-block\n"); }
		;
var-block:
		var			{ printf("var-block -> var\n"); }
	  | var COMMA var-block
					{ printf("var-block -> var COMMA var-block\n"); }
		;
var:
		identifier		{ printf("var -> identifier\n"); }
	  | identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET
					{ printf("var -> identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n"); }
		;
%%

int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
      }//end if
   }//end if
   yyparse(); // Calls yylex() for tokens.
   return 0;
}

void yyerror(const char *msg) {
   printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}
