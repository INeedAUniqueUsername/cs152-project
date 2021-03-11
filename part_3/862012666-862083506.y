%{

//TO DO: FIX TEMP DECLARATIONS
//to do: check var type matches (single vs array)
//to do: check var exists in symbol table
//to do: check array indexing
//to do: check advanced programs
//to do: syntax errors
//to do: re-entrant error

#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<string>
#include<string.h>
#include<sstream>
#include<utility>
#include<string>
#include<iostream>
using namespace std;
	
	int yylex();
	void yyerror(const char *msg);
	extern int currLine;
	extern int currPos;
	
	map<string, string> symbols;
	
	string make_label() {
		static unsigned count;
		ostringstream s;
		s << "__label__" << count;
		count++;
		return s.str();
	}
	string make_temp() {
		static unsigned count;
		ostringstream s;
		s << "__temp__" << count;
		count++;
		return s.str();
	}
%}

%union{
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
}
%error-verbose
%start program
%token FUNCTION IF ELSE THEN RETURN ENDIF WHILE DO BEGINLOOP ENDLOOP BREAK ARRAY OF BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER READ WRITE ASSIGN COMMA SEMICOLON COLON LTE GTE LT GT SUB ADD MULT DIV MOD EQ NEQ L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET TRUE FALSE AND OR NOT
%token <ident> IDENT
%token <ival> NUMBER
%left PLUS MINUS MULT DIV
%nonassoc UMINUS

%type<Statement> program function-block function statement-block-optional loop-statement-block statement-block statement
%type<FunctionArgs> function-args
%type<Expression> expression multiplicative-expr term term-body bool-expr relation-and-expr relation-expr relation-expr-body
%type<Declaration> declaration
%type<DeclarationBlock> declaration-block declaration-block-optional
%type<IdentifierBlock> identifier-block
%type<Identifier> identifier
%type<Statement> read-block write-block
%type<Operator> comp;

%%
program:
		function-block				{
			cout << $1.IR;
		}
		;
function-block: {

			  }
			| function function-block {
				std::ostringstream s;
				s << $1.IR;
				s << $2.IR;
				$$.IR = strdup(s.str().c_str());
			}
			;
function:
		FUNCTION IDENT SEMICOLON
		BEGIN_PARAMS
		declaration-block-optional
		END_PARAMS
		BEGIN_LOCALS
		declaration-block-optional
		END_LOCALS
		BEGIN_BODY
		statement-block-optional
		END_BODY {
		
			ostringstream s;

			s << "func " << $2 << std::endl;
			s << $5.IR;

			istringstream i($5.identifiers);
			string identifier;
			int count = 0;
			while(i >> identifier) {
				s << "= " << identifier << " $" << count << endl;
				count++;
			}

			s << $8.IR;
			s << $11.IR;
			
			//Free the symbols and temps
			
			s << "endfunc" << std::endl;
			
			$$.IR = strdup(s.str().c_str());
		}
		;
declaration-block-optional:
		{	$$.IR = strdup("");
			$$.identifiers = strdup("");
		}
	  | declaration-block {
			$$.IR = strdup($1.IR);
			$$.identifiers = strdup($1.identifiers);
		}
		;
declaration-block:
	    declaration SEMICOLON {
			$$.IR = strdup($1.IR);
			$$.identifiers = strdup($1.identifiers);
		}
	  | declaration SEMICOLON declaration-block {
			ostringstream s;
			s << $1.IR;
			s << $3.IR;
			$$.IR = strdup(s.str().c_str());

			ostringstream s2;
			s2 << $1.identifiers << " " << $3.identifiers;
			$$.identifiers = strdup(s2.str().c_str());
		}
		;
statement-block-optional: 
		{	$$.IR = strdup(""); }
	  | statement-block {
			$$.IR = strdup($1.IR);
		}
		;
statement-block:
	    statement SEMICOLON {
			$$.IR = strdup($1.IR);
		}
	  | statement SEMICOLON statement-block {
			ostringstream s;
			s << $1.IR;
			s << $3.IR;

			$$.IR = strdup(s.str().c_str());
		}
		;
loop-statement-block:
	    statement SEMICOLON {
			$$.IR = strdup($1.IR);
		}
	  | statement SEMICOLON statement-block {
			ostringstream s;
			s << $1.IR;
			s << $3.IR;

			$$.IR = strdup(s.str().c_str());
		}

	  | BREAK SEMICOLON {
			ostringstream s;
			s << "__BREAK__" << endl;
			$$.IR = strdup(s.str().c_str());
		}
	  | BREAK SEMICOLON statement-block {
			ostringstream s;
			s << "__BREAK__" << endl;
			s << $3.IR;

			$$.IR = strdup(s.str().c_str());
		}

		;


declaration:
		identifier-block COLON INTEGER {
			ostringstream o;
			ostringstream o2;
			istringstream i($1.identifiers);
			string identifier;
			while(i >> identifier) {
				string temp = make_temp();
				symbols[identifier] = temp;
				o << ". " << temp << endl;
				o2 << " " << temp;
			}

			$$.size = 0;
			$$.IR = strdup(o.str().c_str());
			$$.identifiers = strdup(o2.str().c_str());
		}
	  | identifier-block COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
			ostringstream o;
			ostringstream o2;
			istringstream i($1.identifiers);

			string identifier;
			int size = $5;
			while(i >> identifier) {
				string temp = make_temp();
				symbols[identifier] = temp;

				o << ".[] " << temp << ", " << size << endl;
				o2 << " " << temp;
			}

			$$.size = (unsigned)size;
			$$.IR = strdup(o.str().c_str());
			$$.identifiers = strdup(o2.str().c_str());
		}

		;
identifier-block:
		identifier		{
			$$.identifiers = strdup($1.identifier);
		}
      | identifier COMMA identifier-block {
			ostringstream s;
			s << $1.identifier << " " << $3.identifiers;
			$$.identifiers = strdup(s.str().c_str());
		}
		;
identifier:
		IDENT		{
			$$.identifier = $1;
		}
		;
statement:
		IDENT ASSIGN expression {
			//std::string temp = lookup($1.identifier);
			string temp = symbols[$1];

			ostringstream s;
			s << $3.IR;
			s << "= " << temp << ", " << $3.ret_name << std::endl;

			$$.IR = strdup(s.str().c_str());
		}
	  | identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET ASSIGN expression {
			//Lookup from symbol table
			//std::string temp = lookup($1.identifier);
			string temp($1.identifier);

			ostringstream s;
			s << "[]= " << temp << ", " << $3.ret_name << ", " << $6.ret_name << std::endl;

			$$.IR = strdup(s.str().c_str());
		}
	  | IF bool-expr THEN statement-block ENDIF {
			//TO DO: Make sure $ entries are properly indexed
			//Remove $0
			
			std::string label0 = make_label();
			std::string label1 = make_label();
			ostringstream s;
			
			//Condition
			s << $2.IR;
			//Jump into branch
			s << "?:= " << label0 << ", " << $2.ret_name << std::endl;
			
			//Skip branch
			s << ":= " << label1 << std::endl;

			//Branch
			s << ": " << label0 << std::endl;
			s << $4.IR;
			
			//Finally
			s << ": " << label1 << std::endl;
			
			$$.IR = strdup(s.str().c_str());
		}
	  | IF bool-expr THEN statement-block ELSE statement-block ENDIF {
			std::string label0 = make_label();
			std::string label1 = make_label();
			std::string label2 = make_label();
			ostringstream s;
			
			//Condition
			s << $2.IR;
			//Jump into branch
			s << "?:=" << label0 << ", " << $2.ret_name << std::endl;
			
			//Jump into else
			s << ":= " << label1 << std::endl;
			
			//Branch
			s << ": " << label0 << std::endl;
			s << $4.IR;
			
			//Jump to finally
			s << ":= " << label2 << std::endl;
			
			//Else
			s << ": " << label1 << std::endl;
			
			//Finally
			s << ": " << label2 << std::endl;
			s << $6.IR;
			$$.IR = strdup(s.str().c_str());
			
		}
	  | WHILE bool-expr BEGINLOOP loop-statement-block ENDLOOP {
			string label_body = make_label();
			string label_condition = make_label();
			string label_end = make_label();

			std::ostringstream s;
			//Jump to condition
			s << ":= " << label_condition << endl;
			
			//Body
			s << ": " << label_body << endl; 

			//Body replace Breaks
			string line;
			istringstream body($4.IR);
			while(getline(body, line)) {
				if(line == "__BREAK__") {
					s << ":= " << label_end << endl;
				} else {
					s << line << endl;
				}
			}

			//Check condition
			s << ": " << label_condition << endl;
			s << $2.IR << endl;

			//Jump to body
			s << "?:= " << label_body << $2.ret_name << endl;

			//End
			s << ": " << label_end << endl;

			$$.IR = strdup(s.str().c_str());
		}
	  | DO BEGINLOOP loop-statement-block ENDLOOP WHILE bool-expr {
			std::string label_body = make_label();
			std::string label_condition = make_label();
			string label_end = make_label();
			
			std::ostringstream s;

			//Body
			s << ": " << label_body << std::endl; 
			
			//Body replace Breaks
			string line;
			istringstream body($3.IR);
			while(getline(body, line)) {
				if(line == "__BREAK__") {
					s << ":= " << label_end << endl;
				} else {
					s << line << endl;
				}
			}
			
			//Condition
			s << ": " << label_condition << std::endl;
			s << $6.IR << std::endl;

			//Jump to body
			s << "?:= " << label_body << $6.ret_name << std::endl;

			//End
			s << ": " << label_end << endl;

			
			$$.IR = strdup(s.str().c_str());
		}
	  | read-block	{
			$$.IR = strdup($1.IR);
		}
	  | write-block	{
			$$.IR = strdup($1.IR);
		}
	  | RETURN expression	{
			ostringstream s;
			s << $2.IR;
			s << "ret " << $2.ret_name << endl;
			$$.IR = strdup(s.str().c_str());
		}
		;
read-block:
		READ IDENT		{
			ostringstream s;
			s << ".< " << symbols[$2] << endl;
			$$.IR = strdup(s.str().c_str());
		}
	  | READ IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
			ostringstream s;
			s << ".< " << symbols[$2] << ", " << $4.ret_name << endl;
			$$.IR = strdup(s.str().c_str());
		}
	  | read-block IDENT	{
			ostringstream s;
			s << $1.IR;
			s << ".< " << symbols[$2] << endl;
			$$.IR = strdup(s.str().c_str());
		}
	  | read-block IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
			ostringstream s;
			s << $1.IR;
			s << ".< " << symbols[$2] << ", " << $4.ret_name << endl;
			$$.IR = strdup(s.str().c_str());
		}
		;
write-block:
		WRITE IDENT		{
			ostringstream s;
			s << ".> " << symbols[$2] << endl;
			$$.IR = strdup(s.str().c_str());
		}
	  | WRITE IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
			ostringstream s;
			s << ".> " << symbols[$2] << ", " << $4.ret_name << endl;
			$$.IR = strdup(s.str().c_str());
		}
	  | write-block IDENT	{
			ostringstream s;
			s << $1.IR;
			s << ".> " << symbols[$2] << endl;
			$$.IR = strdup(s.str().c_str());
		}
	  | write-block IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
			ostringstream s;
			s << $1.IR;
			s << ".> " << symbols[$2] << ", " << $4.ret_name << endl;
			$$.IR = strdup(s.str().c_str());
		}
		;
bool-expr:
		relation-and-expr {
			$$.IR = $1.IR;
			$$.ret_name = strdup($1.ret_name);
		}
	  | relation-and-expr OR bool-expr {
			ostringstream s;
			s << $1.IR;
			s << $3.IR;

			string temp = make_temp();
			s << ". " << temp << endl;
			s << "|| " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
			$$.IR = strdup(s.str().c_str());
			$$.ret_name = strdup(temp.c_str());
		}
		;
relation-and-expr:
		relation-expr {
			$$.IR = $1.IR;
			$$.ret_name = strdup($1.ret_name);
		}
	  | relation-expr AND relation-and-expr {
			std::ostringstream s;
			s << $1.IR;
			s << $3.IR;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "&& " << temp << ", " << $1.ret_name << ", " << $3.ret_name << std::endl;
			$$.IR = strdup(s.str().c_str());
			$$.ret_name = strdup(temp.c_str());
		}
		;
relation-expr:
		relation-expr-body {
			$$.IR = $1.IR;
			$$.ret_name = strdup($1.ret_name);
		}
	  | NOT relation-expr-body {
			std::ostringstream s;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;

			s << $2.IR;
			s << "! " << temp << ", " << $2.ret_name << std::endl;
			$$.IR = strdup(s.str().c_str());
			$$.ret_name = strdup(temp.c_str());
	  }
		;
relation-expr-body:
		expression comp expression {
		
			std::ostringstream s;
			s << $1.IR;
			s << $3.IR;
			string temp = make_temp();
			s << ". " << temp << endl;
			s << $2.op << " " << temp << ", " << $1.ret_name << ", " << $3.ret_name << std::endl;
			$$.IR = strdup(s.str().c_str());
			$$.ret_name = strdup(temp.c_str());
		}
	  | TRUE						{
			$$.ret_name = strdup("true");
		}
	  | FALSE						{
			$$.ret_name = strdup("false");
		}
	  | L_PAREN bool-expr R_PAREN	{
			$$.IR = strdup($2.IR);
			$$.ret_name = strdup($2.ret_name);
		}
		;

comp:
		EQ			{ $$.op = strdup("=="); }
	  | NEQ			{ $$.op = strdup("!="); }
	  | LT			{ $$.op = strdup("<"); }
	  | GT			{ $$.op = strdup(">"); }
	  | LTE			{ $$.op = strdup("<="); }
	  | GTE			{ $$.op = strdup(">="); }
		;
expression:
		multiplicative-expr {
			$$.IR = strdup($1.IR);
			$$.ret_name = strdup($1.ret_name);
		}
	  | multiplicative-expr ADD expression { 
			std::ostringstream s;
			s << $1.IR;
			s << $3.IR;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "+ " << temp << ", " << $1.ret_name << ", " << $3.ret_name << std::endl;
			
			$$.IR = strdup(s.str().c_str());
			$$.ret_name = strdup(temp.c_str());
		}
	  | multiplicative-expr SUB expression {
			std::ostringstream s;
			s << $1.IR;
			s << $3.IR;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "- " << temp << ", " << $1.ret_name << ", " << $3.ret_name << std::endl;
			
			$$.IR = strdup(s.str().c_str());
			$$.ret_name = strdup(temp.c_str());
		}
		;
multiplicative-expr:
		term {
			$$.IR = strdup($1.IR);
			$$.ret_name = strdup($1.ret_name);
		}
	  | term MULT multiplicative-expr {
			std::ostringstream s;
			s << $1.IR;
			s << $3.IR;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "* " << temp << ", " << $1.ret_name << ", " << $3.ret_name << std::endl;
			
			$$.IR = strdup(s.str().c_str());
			$$.ret_name = strdup(temp.c_str());
		}
	  | term DIV multiplicative-expr {
			std::ostringstream s;
			s << $1.IR;
			s << $3.IR;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "/ " << temp << ", " << $1.ret_name << ", " << $3.ret_name << std::endl;
			
			$$.IR = strdup(s.str().c_str());
			$$.ret_name = strdup(temp.c_str());
		}
	  | term MOD multiplicative-expr {
			std::ostringstream s;
			s << $1.IR;
			s << $3.IR;
			
			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "% " << temp << ", " << $1.ret_name << ", " << $3.ret_name << std::endl;
			
			$$.IR = strdup(s.str().c_str());
			$$.ret_name = strdup(temp.c_str());
		}
		;
term:
		term-body			{
			$$.IR = strdup($1.IR);
			$$.ret_name = strdup($1.ret_name);
		}
	  | MINUS term-body		{
			std::string temp = make_temp();
			
			std::ostringstream s;
			s << $2.IR;
			s << ". " << temp << endl;
			s << "- " << temp << ", 0, " << $2.ret_name << endl;
			
			$$.IR = strdup(s.str().c_str());
			$$.ret_name = strdup(temp.c_str());
		}
	  | IDENT L_PAREN function-args R_PAREN {
			std::ostringstream s;
			s << $3.IR;

			istringstream i($3.ret_names);
			string ret_name;
			while(i >> ret_name) {
				s << "param " << ret_name << endl;
			}

			std::string temp = make_temp();
			s << ". " << temp << endl;
			s << "call " << $1 << ", " << temp << endl;
			
			$$.IR = strdup(s.str().c_str());
			$$.ret_name = strdup(temp.c_str());
		}
		;
term-body:
		NUMBER		{
			$$.IR = strdup("");
			char str[12];
			sprintf(str, "%d", $1);
			$$.ret_name = strdup(str);
		}
	  | IDENT	{
			$$.IR = strdup("");

			string temp = symbols[$1];
			$$.ret_name = strdup(temp.c_str());
		}
	  | IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
			string temp = make_temp();

			string func = symbols[$1];

			ostringstream s;
			s << "=[] " << temp << ", " << func << ", " << $3.ret_name << endl;

			$$.IR = strdup(s.str().c_str());
			$$.ret_name = strdup(temp.c_str());
		}
	  | L_PAREN expression R_PAREN {
			$$.IR = strdup($2.IR);
			$$.ret_name = strdup($2.ret_name);
		}
		;
function-args:
		expression	{
			$$.IR = strdup($1.IR);
			$$.ret_names = strdup($1.ret_name);
		}
	  | expression COMMA function-args {
			ostringstream s;
			s << $1.IR;
			s << $3.IR;
			$$.IR = strdup(s.str().c_str());

			ostringstream s2;
			s2 << $1.ret_name << " " << $3.ret_names;
			$$.ret_names = strdup(s2.str().c_str());
		}
		;
%%

int main(int argc, char **argv) {
   if (argc > 1) {
      FILE * yyin = fopen(argv[1], "r");
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
