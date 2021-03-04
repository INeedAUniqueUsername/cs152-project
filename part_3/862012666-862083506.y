%{
#include<stdio.h>
#include<stdlib.h>
using namespace std;
	
	void yyerror(const char *msg);
	extern int currLine;
	extern int currPos;
	FILE * yyin;
	
	map<string, pair<string, unsigned>> symbols;
	
	string make_label() {
		static unsigned count;
		ostringstream s;
		s << "l" << count << endl;
		count++;
		return s.str();
	}
	string make_temp() {
		static unsigned count;
		ostringstream s;
		s << "t" << count << endl;
		count++;
		return s.str();
	}
	
	struct Statement {
		std::string IR;
	};
	struct Expression {
		std::string IR;
		std::string ret_name;
	};
	struct ExpressionBlock {
		vector<Expression> expressions;
	};
	
	struct Var {
		std::string identifier;
		std::string index;
	};
	struct VarBlock {
		std::vector<std::pair<std::string, std::string>> variables;
	};
	
	struct Identifier {
		std::string identifier;
	};
	struct IdentifierBlock {
		vector<std::string> identifiers;
	};
	struct DeclarationBlock {
		std::string IR;
		std::vector<std::tuple<std::string, std::string, unsigned>> variables;
	};
	struct Declaration {
		std::string IR;
		std::vector<std::string> identifiers;
		std::string type;
		unsigned size;
	};
	struct DeclarationType {
		std::string type;
		unsigned size;
	};
	struct Operator {
		string op;
	};
	struct Program {
		string IR;
	};
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

%type<Statement> program
%type<Statement> function-block;
%type<Statement> function;

%type<Statement> statement-block-optional
%type<Statement> statement-block
%type<Statement> statement
%type<ExpressionBlock> expression-block
%type<Expression> expression
%type<Expression> multiplicative-expr
%type<Expression> term
%type<Expression> term-body

%type<Expression> bool-expr
%type<Expression> relation-and-expr
%type<Expression> relation-expr
%type<Expression> relation-expr-body

%type<Declaration> declaration
%type<DeclarationType> declaration-type
%type<DeclarationBlock> declaration-block
%type<DeclarationBlock> declaration-block-optional
%type<IdentifierBlock> identifier-block
%type<Identifier> identifier

%type<Var> var
%type<VarBlock> var-block

%type<Operator> comp;

%% 
program:
		function-block				{
			$$.IR = $1.IR;
		}
		;
function-block: {

			  }
			| function function-block {
				ostringstream s;
				s << $1.IR << endl;
				s << $2.IR << endl;
				$$.IR = s.str();
			}
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
			s << $2.identifier << std::endl;
			
			s << $5.IR << std::endl;
			
			s << $8.IR << std::endl;
			
			s << $11.IR<< std::endl;
			
			
			
			//Free the symbols and temps
			
			s << "endfunc" << std::endl;
			
			$$.IR = s.str();
		}
		;
declaration-block-optional:
		{}
	  | declaration-block {
			$$.IR = $1.IR;
			$$.variables = $1.IR;
		}
		;
declaration-block:
	    declaration SEMICOLON {
			$$.IR = $1.IR;
			for(unsigned i = 0; i < $1.identifiers.size(); i++) {
				$$.variables.push_back(make_tuple($1.identifiers[i], $1.type, $1.size));
			}
		}
	  | declaration SEMICOLON declaration-block {
			stringstream s;
			s << $1.IR;
			s << $3.IR;
			$$.IR = s.str();
			
			$$.variables = $1.variables;
			
			for(unsigned i = 0; i < $1.identifiers.size(); i++) {
				$$.variables.push_back(make_tuple($1.identifiers[i], $1.type, $1.size));
			}
		}
		;
statement-block-optional: 
		{}
	  | statement-block {
			$$.IR = $1.IR;
		}
		;
statement-block:
	    statement SEMICOLON {
			$$.IR = $1.IR;
		}
	  | statement SEMICOLON statement-block {
			stringstream s;
			s << $1.IR;
			s << $3.IR;
			$$.IR = s.str();
		}
		;
declaration:
		identifier-block COLON declaration-type {
		
				$$.identifiers = $1.identifiers;
				$$.type = $3.type;
				$$.size = $3.size;
				
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
						s << ".[] " << temp << ", " << $3.size << std::endl;
						
						//Add to symbol table
						
						//Make sure to free the symbol table entry and temp
					}
				}
				$$.IR = s.str();
		}
		;
declaration-type:
		INTEGER	{
				$$.type = "integer";
				$$.size = 0;
		}
	  | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
				$$.type = "integer";
				$$.size = atoi($3);
		}
		;
identifier-block:
		identifier		{
			$$.identifiers.push_back($1);
		}
      | identifier COMMA identifier-block {
			$$.identifiers = $3.identifiers;
			$$.identifiers.push_back($1);
		}
		;
identifier:
		IDENT		{
			$$.identifier = $1;
		}
		;
statement:
		var ASSIGN expression {
			stringstream s;
			
			//Lookup from symbol table
			string temp = lookup($1.identifier);
			
			unsigned index = $1.index;
			if(index != -1) {
				s << "=[] " << temp << ", " << $3.ret_name << ", " << index << std::endl;
			} else {
				s << "= " << temp << ", " << $3.ret_name << std::endl;
			}
			$$.IR = s.str();
		}
	  | IF bool-expr THEN statement-block ENDIF {
			//TO DO: Make sure $ entries are properly indexed
			//Remove $0
			
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
	  | IF bool-expr THEN statement-block ELSE statement-block ENDIF {
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
	  | WHILE bool-expr BEGINLOOP statement-block ENDLOOP {
			string label_body = make_label();
			string label_condition = make_label();
			
			ostringstream s;
			s << ":= " << label_condition << endl;
			s << ": " << label_body << endl; 
			s << $4.IR << endl;
			s << ": " << label_condition << endl;
			s << $2.IR << endl;
			s << "?:= " << label_body << $2.ret_name << endl;
			
			$$.IR = s.str();
		}
	  | DO BEGINLOOP statement-block ENDLOOP WHILE bool-expr {
			string label_body = make_label();
			string label_condition = make_label();
			
			ostringstream s;
			s << ": " << label_body << endl; 
			s << $3.IR << endl;
			s << ": " << label_condition << endl;
			s << $6.IR << endl;
			s << "?:= " << label_body << $6.ret_name << endl;
			
			$$.IR = s.str();
		}
	  | READ var-block	{
			stringstream s;
			for(unsigned i = 0; i < $2.variables.size(); i++) {
				auto var = $2.variables[i];
				if(var.second == "") {
					s << ".< " << var.first << endl;
				} else {
					s << ".[]< " << var.first << ", " << var.second << std::endl;
				}
			}
			$$.IR = s.str();
		}
	  | WRITE var-block		{
			stringstream s;
			for(unsigned i = 0; i < $2.variables.size(); i++) {
				auto var = $2.variables[i];
				if(var.second == "") {
					s << ".> " << var.first << std::endl;
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
			s << "ret " << $2.ret_name << endl;
			$$.IR = s.str();
		}
		;
bool-expr:
		relation-and-expr {
			$$.IR = $1.IR;
			$$.ret_name = $1.ret_name;
		}
	  | relation-and-expr OR bool-expr {
			string temp = make_temp();
	  
			ostringstream s;
			s << $1.IR << std::endl;
			s << $3.IR << std::endl;
			s << "|| " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
			$$.IR = s.str();
			$$.ret_name = temp;
		}
		;
relation-and-expr:
		relation-expr {
			$$.IR = $1.IR;
			$$.ret_name = $1.ret_name;
		}
	  | relation-expr AND relation-and-expr {
			string temp = make_temp();
	  
			ostringstream s;
			s << $1.IR << std::endl;
			s << $3.IR << std::endl;
			s << "&& " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
			$$.IR = s.str();
			$$.ret_name = temp;
		}
		;
relation-expr:
		relation-expr-body {
			$$.IR = $1.IR;
			$$.ret_name = $1.ret_name;
		}
	  | NOT relation-expr-body {
			string temp = make_temp();
	  
			ostringstream s;
			s << $2.IR << std::endl;
			s << "! " << temp << ", " << $2.ret_name << endl;
			$$.IR = s.str();
			$$.ret_name = temp;
	  }
		;
relation-expr-body:
		expression comp expression {
			string temp = make_temp();
	  
			ostringstream s;
			s << $1.IR << std::endl;
			s << $3.IR << std::endl;
			s << $2.op << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
			$$.IR = s.str();
			$$.ret_name = temp;
		}
	  | TRUE						{
			$$.ret_name = "true";
		}
	  | FALSE						{
			$$.ret_name = "false";
		}
	  | L_PAREN bool-expr R_PAREN	{
			$$.IR = $2.IR;
			$$.ret_name = $2.ret_name;
		}
		;
comp:
		EQ			{ $$.op = "=="; }
	  | NEQ			{ $$.op = "!="; }
	  | LT			{ $$.op = "<"; }
	  | GT			{ $$.op = ">"; }
	  | LTE			{ $$.op = "<="; }
	  | GTE			{ $$.op = ">="; }
		;
expression:
		multiplicative-expr {
			$$.IR = $1.IR;
			$$.ret_name = $1.ret_name;
		}
	  | multiplicative-expr ADD expression { 
			ostringstream s;
			s << $1.IR << endl;
			s << $3.IR << endl;
			
			string temp = make_temp();
			s << "+ " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
			
			$$.IR = s.str();
			$$.ret_name = temp;
		}
	  | multiplicative-expr SUB expression {
			ostringstream s;
			s << $1.IR << endl;
			s << $3.IR << endl;
			
			string temp = make_temp();
			s << "- " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
			
			$$.IR = s.str();
			$$.ret_name = temp;
		}
		;
multiplicative-expr:
		term {
			$$.IR = $1.IR;
			$$.ret_name = $1.ret_name;
		}
	  | term MULT multiplicative-expr {
			ostringstream s;
			s << $1.IR << endl;
			s << $3.IR << endl;
			
			string temp = make_temp();
			s << "* " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
			
			$$.IR = s.str();
			$$.ret_name = temp;
		}
	  | term DIV multiplicative-expr {
			ostringstream s;
			s << $1.IR << endl;
			s << $3.IR << endl;
			
			string temp = make_temp();
			s << "/ " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
			
			$$.IR = s.str();
			$$.ret_name = temp;
		}
	  | term MOD multiplicative-expr {
			ostringstream s;
			s << $1.IR << endl;
			s << $3.IR << endl;
			
			string temp = make_temp();
			s << "% " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
			
			$$.IR = s.str();
			$$.ret_name = temp;
		}
		;
term:
		term-body			{
			$$.IR = $1.IR;
			$$.ret_name = $1.ret_name;
		}
	  | MINUS term-body		{
			string temp = make_temp();
			
			ostringstream s;
			s << $2.IR << endl;
			s << "- " << temp << ", 0, " << $2.ret_name;
			
			$$.IR = s.str();
			$$.ret_name = temp;
		}
	  | IDENT L_PAREN expression-block R_PAREN {
			ostringstream s;
			for(const auto& e : $3.expressions) {
				s << e.IR << endl;
			}
			for(const auto& e : $3.expressions) {
				s << "param " << e.ret_name << endl;
			}
			string temp = make_temp();
			s << "call " << $1 << ", " << temp << endl;
			
			$$.IR = s.str();
			$$.ret_name = temp;
		}
		;
term-body:
		NUMBER		{
			$$.ret_name = $1;
		}
	  | var			{
			if($1.index != (unsigned)-1) {
				string temp = make_temp();
				ostringstream s;
				s << "=[] " << temp << ", " << $1.identifier << ", " << $1.index;
				$$.IR = s.str();
				$$.ret_name = temp;
			} else {
				$$.ret_name = $1.ret_name;
			}
		}
	  | L_PAREN expression R_PAREN {
			$$.IR = $2.IR;
			$$.ret_name = $2.ret_name;
		}
		;
expression-block:
		expression	{
			$$.expressions.push_back($1);
		}
	  | expression COMMA expression-block {
			$$.expressions = $3.expressions;
			$$.expressions.push_back($1);
		}
		;
var-block:
		var			{
			$$.variables.push_back(make_pair($1.identifier, $1.index));
		}
	  | var COMMA var-block {
			$$.variables = $3.variables;
			$$.variables.push_back(make_pair($1.identifier, $1.index));
		}
		;
var:
		identifier		{
			auto pair = symbols.find($1);
			if(pair != symbols.end()) {
				$$.identifier = pair.second;
			} else {
				throw exception("invalid symbol");
			}
		}
	  | identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
			auto pair = symbols.find($1);
			if(pair != symbols.end()) {
				$$.identifier = pair.second;
			} else {
				throw exception("invalid symbol");
			}
			
			$$.index = $3.ret_name;
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
