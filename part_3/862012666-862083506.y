%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <map>
	void yyerror(const char *msg);
	extern int currLine;
	extern int currPos;
	FILE * yyin;
	
	map<string, pair<string, unsigned>> symbols;
	
	struct Statement {
		std::string IR;
	}
	struct Expression {
		std::string IR;
		std::string ret_name;
	}
	
	struct Var {
		std::string identifier;
		unsigned index;
	}
	struct VarBlock {
		std::vector<std::pair<std::string, unsigned>> variables;
	}
	
	struct Identifier {
		std::string identifier;
	}
	struct IdentifierBlock {
		vector<std::string> identifiers;
	}
	struct DeclarationBlock {
		std::string IR;
		std::vector<std::tuple<std::string, std::string, unsigned>> variables;
	}
	struct Declaration {
		std::string IR;
		std::vector<std::string> identifiers;
		std::string type;
		unsigned size;
	}
	struct DeclarationType {
		std::string type;
		unsigned size;
	}
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

%type<Statement> statement-block-optional
%type<Statement> statement-block
%type<Statement> statement
%type<Expression> bool-expr
%type<Expression> multiplicative-expr
%type<Expression> term

%type<Declaration> declaration
%type<DeclarationType> declaration-type
%type<IdentifierBlock> identifier-block
%type<Identifier> identifier

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
		END_BODY {
		
			stringstream s;
			s << $1 << std::endl;
			
			
			
			//Free the symbols and temps
			
			s << "endfunc" << std::endl;
		}
		;
declaration-block-optional:
						{}
	  | declaration-block {
			$$.IR = $0.IR;
			$$.variables = $0.IR;
		}
		;
declaration-block:
	    declaration SEMICOLON {
			$$.IR = $0.IR;
			for(unsigned i = 0; i < $0.identifiers.size(); i++) {
				$$.variables.push_back(make_tuple($0.identifiers[i], $0.type, $0.size));
			}
		}
	  | declaration SEMICOLON declaration-block {
			stringstream s;
			s << $0.IR;
			s << $1.IR;
			$$.IR = s.str();
			
			$$.variables = $1.variables;
			
			for(unsigned i = 0; i < $0.identifiers.size(); i++) {
				$$.variables.push_back(make_tuple($0.identifiers[i], $0.type, $0.size));
			}
		}
		;
statement-block-optional: {}
	  | statement-block {
			$$.IR = $0.IR;
		}
		;
statement-block:
	    statement SEMICOLON {
			$$.IR = $0.IR;
		}
	  | statement SEMICOLON statement-block {
			stringstream s;
			s << $0.IR;
			s << $2.IR;
			$$.IR = s.str();
		}
		;
declaration:
		identifier-block COLON declaration-type {
		
				$$.identifiers = $0.identifiers;
				$$.type = $2.type;
				$$.size = $2.size;
				
				stringstream s;
				if($$.size > 0) {
					for(unsigned i = 0; i < $$.identifiers.size(); i++) {
						string identifier = $$.identifiers[i];
						
						//Check if already in symbol table
						
						//Make a temp
						string temp = make_temp();
						s << ". " << temp << std::endl;
						
						//Add to symbol table
						
						//Make sure to free the symbol table entry and temp
					}
				} else {
					for(unsigned i = 0; i < $$.identifiers.size(); i++) {
						string identifier = $$.identifiers[i];
						
						//Check if already in symbol table
						
						//Make a temp
						string temp = make_temp();
						s << ".[] " << temp << ", " << $2.size << std::endl;
						
						//Add to symbol table
						
						//Make sure to free the symbol table entry and temp
					}
				}
				$$.IR = s.str();
		}
		;
declaration-type:
		INTEGER	{
				$$.type = $0;
				$$.size = 0;
		}
	  | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
				$$.type = "integer";
				$$.size = atoi($2);
		}
		;
identifier-block:
		identifier		{
			$$.identifiers.push_back($0);
		}
      | identifier COMMA identifier-block {
			$$.identifiers = $1.identifiers;
			$$.identifiers.push_back($0);
		}
		;
identifier:
		IDENT		{
			$$.identifier = $0;
		}
		;
statement:
		var ASSIGN expression {
			stringstream s;
			
			//Lookup from symbol table
			string temp = lookup($0.identifier);
			
			unsigned index = $0.index;
			if(index != -1) {
				s << "=[] " << temp << ", " << $2.ret_name << ", " << index << std::endl;
			} else {
				s << "= " << temp << ", " << $2.ret_name << std::endl;
			}
			$$.IR = s.str();
		}
	  | IF bool-expr THEN statement-block ENDIF {
	  
			//TO DO: Make sure $ entries are properly indexed
			//Remove $0
	  
			string label0 = make_label();
			string label1 = make_label();
			string label2 = make_label();
			stringstream s;
			
			//Condition
			s << $2.IR;
			//Jump into branch
			s << "?:=" << label0 << ", " << $2.ret_name << std::endl;
			
			//Jump into else
			s << ":= " << label1 << std::endl;
			
			//Branch
			s << ":" << label0 << std::endl;
			s << $4.IR;
			//Jump to finally
			s << ":= " << label2 << std::endl;
			
			//Else
			s << ": " << label1 << std::endl;
			
			//Finally
			s << ": " << label2 << std::endl;
			s << $6.IR;
			
			$$.IR = s.str();
		}
	  | IF bool-expr THEN statement-block ELSE statement-block ENDIF {
			string label0 = make_label();
			string label1 = make_label();
			stringstream s;
			
			//Condition
			s << $2.IR;
			//Jump into branch
			s << "?:=" << label0 << ", " << $2.ret_name << std::endl;
			
			//Skip branch
			s << ":= " << label1 << std::endl;
			
			//Branch
			s << ":" << label0 << std::endl;
			s << $4.IR;
			
			//Finally
			s << ": " << label1 << std::endl;
			$$.IR = s.str();
			
		}
	  | WHILE bool-expr BEGINLOOP statement-block ENDLOOP
			{ printf("statement -> WHILE bool-expr BEGINLOOP statement-block ENDLOOP\n"); }
	  | DO BEGINLOOP statement-block ENDLOOP WHILE bool-expr
			{ printf("statement -> DO BEGINLOOP statement-block ENDLOOP WHILE bool-expr\n"); }
	  | READ var-block	{
			stringstream s;
			for(unsigned i = 0; i < $1.variables.size(); i++) {
				auto var = $1.variables[i];
				if(var.second == (unsigned)-1) {
					s << ".< " << var.first << endl;
				} else {
					s << ".[]< " << var.first << ", " << var.second << std::endl;
				}
			}
			$$.IR = s.str();
		}
	  | WRITE var-block		{
			stringstream s;
			for(unsigned i = 0; i < $1.variables.size(); i++) {
				auto var = $1.variables[i];
				if(var.second == (unsigned)-1) {
					s << ".> " << var.first << endl;
				} else {
					s << ".[]> " << var.first << ", " << var.second << std::endl;
				}
			}
			$$.IR = s.str();
		}
	  | BREAK				{
	  
		}
	  | RETURN expression	{
			stringstream s;
			s << "ret " << $1.ret_name << endl;
			$$.IR = s.str();
		}
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
		var			{
			$$.variables.push_back(make_pair($0.identifier, $0.index));
		}
	  | var COMMA var-block {
			$$.variables = $2.variables;
			$$.variables.push_back(make_pair($0.identifier, $0.index));
		}
		;
var:
		identifier		{
			$$.identifier = $0;
			$$.index = -1;
		}
	  | identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
			$$.identifier = $0;
			int index = atoi($2);
			if(index > -1) {
				$$.index = (unsigned)index;
			} else {
				//Error
			}
		}
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
