diff --git a/part_3/862012666-862083506.y b/part_3/862012666-862083506.y
index da52abf..6d4540c 100644
--- a/part_3/862012666-862083506.y
+++ b/part_3/862012666-862083506.y
@@ -1,7 +1,8 @@
 %{
-	#include <stdio.h>
-	#include <stdlib.h>
-	#include <map>
+#include<stdio.h>
+#include<stdlib.h>
+using namespace std;
+	
 	void yyerror(const char *msg);
 	extern int currLine;
 	extern int currPos;
@@ -9,42 +10,66 @@
 	
 	map<string, pair<string, unsigned>> symbols;
 	
+	string make_label() {
+		static unsigned count;
+		ostringstream s;
+		s << "l" << count << endl;
+		count++;
+		return s.str();
+	}
+	string make_temp() {
+		static unsigned count;
+		ostringstream s;
+		s << "t" << count << endl;
+		count++;
+		return s.str();
+	}
+	
 	struct Statement {
 		std::string IR;
-	}
+	};
 	struct Expression {
 		std::string IR;
 		std::string ret_name;
-	}
+	};
+	struct ExpressionBlock {
+		vector<Expression> expressions;
+	};
 	
 	struct Var {
 		std::string identifier;
-		unsigned index;
-	}
+		std::string index;
+	};
 	struct VarBlock {
-		std::vector<std::pair<std::string, unsigned>> variables;
-	}
+		std::vector<std::pair<std::string, std::string>> variables;
+	};
 	
 	struct Identifier {
 		std::string identifier;
-	}
+	};
 	struct IdentifierBlock {
 		vector<std::string> identifiers;
-	}
+	};
 	struct DeclarationBlock {
 		std::string IR;
 		std::vector<std::tuple<std::string, std::string, unsigned>> variables;
-	}
+	};
 	struct Declaration {
 		std::string IR;
 		std::vector<std::string> identifiers;
 		std::string type;
 		unsigned size;
-	}
+	};
 	struct DeclarationType {
 		std::string type;
 		unsigned size;
-	}
+	};
+	struct Operator {
+		string op;
+	};
+	struct Program {
+		string IR;
+	};
 %}
 
 %union{
@@ -68,24 +93,51 @@
 %left MULT DIV
 %nonassoc UMINUS
 
+%type<Statement> program
+%type<Statement> function-block;
+%type<Statement> function;
+
 %type<Statement> statement-block-optional
 %type<Statement> statement-block
 %type<Statement> statement
-%type<Expression> bool-expr
+%type<ExpressionBlock> expression-block
+%type<Expression> expression
 %type<Expression> multiplicative-expr
 %type<Expression> term
+%type<Expression> term-body
+
+%type<Expression> bool-expr
+%type<Expression> relation-and-expr
+%type<Expression> relation-expr
+%type<Expression> relation-expr-body
 
 %type<Declaration> declaration
 %type<DeclarationType> declaration-type
+%type<DeclarationBlock> declaration-block
+%type<DeclarationBlock> declaration-block-optional
 %type<IdentifierBlock> identifier-block
 %type<Identifier> identifier
 
+%type<Var> var
+%type<VarBlock> var-block
+
+%type<Operator> comp;
+
 %% 
 program:
-		function-block				{ printf("program -> function-block\n"); }
+		function-block				{
+			$$.IR = $1.IR;
+		}
 		;
-function-block:
-			| function function-block { printf("function-block -> function function-block\n"); }
+function-block: {
+
+			  }
+			| function function-block {
+				ostringstream s;
+				s << $1.IR << endl;
+				s << $2.IR << endl;
+				$$.IR = s.str();
+			}
 			;
 function:
 		FUNCTION identifier SEMICOLON
@@ -100,64 +152,73 @@ function:
 		END_BODY {
 		
 			stringstream s;
-			s << $1 << std::endl;
+			s << $2.identifier << std::endl;
+			
+			s << $5.IR << std::endl;
+			
+			s << $8.IR << std::endl;
+			
+			s << $11.IR<< std::endl;
 			
 			
 			
 			//Free the symbols and temps
 			
 			s << "endfunc" << std::endl;
+			
+			$$.IR = s.str();
 		}
 		;
 declaration-block-optional:
-						{}
+		{}
 	  | declaration-block {
-			$$.IR = $0.IR;
-			$$.variables = $0.IR;
+			$$.IR = $1.IR;
+			$$.variables = $1.IR;
 		}
 		;
 declaration-block:
 	    declaration SEMICOLON {
-			$$.IR = $0.IR;
-			for(unsigned i = 0; i < $0.identifiers.size(); i++) {
-				$$.variables.push_back(make_tuple($0.identifiers[i], $0.type, $0.size));
+			$$.IR = $1.IR;
+			for(unsigned i = 0; i < $1.identifiers.size(); i++) {
+				$$.variables.push_back(make_tuple($1.identifiers[i], $1.type, $1.size));
 			}
 		}
 	  | declaration SEMICOLON declaration-block {
 			stringstream s;
-			s << $0.IR;
 			s << $1.IR;
+			s << $3.IR;
 			$$.IR = s.str();
 			
 			$$.variables = $1.variables;
 			
-			for(unsigned i = 0; i < $0.identifiers.size(); i++) {
-				$$.variables.push_back(make_tuple($0.identifiers[i], $0.type, $0.size));
+			for(unsigned i = 0; i < $1.identifiers.size(); i++) {
+				$$.variables.push_back(make_tuple($1.identifiers[i], $1.type, $1.size));
 			}
 		}
 		;
-statement-block-optional: {}
+statement-block-optional: 
+		{}
 	  | statement-block {
-			$$.IR = $0.IR;
+			$$.IR = $1.IR;
 		}
 		;
 statement-block:
 	    statement SEMICOLON {
-			$$.IR = $0.IR;
+			$$.IR = $1.IR;
 		}
 	  | statement SEMICOLON statement-block {
 			stringstream s;
-			s << $0.IR;
-			s << $2.IR;
+			s << $1.IR;
+			s << $3.IR;
 			$$.IR = s.str();
 		}
 		;
 declaration:
 		identifier-block COLON declaration-type {
 		
-				$$.identifiers = $0.identifiers;
-				$$.type = $2.type;
-				$$.size = $2.size;
+				$$.identifiers = $1.identifiers;
+				$$.type = $3.type;
+				$$.size = $3.size;
 				
 				stringstream s;
 				if($$.size > 0) {
@@ -182,7 +243,7 @@ declaration:
 						
 						//Make a temp
 						string temp = make_temp();
-						s << ".[] " << temp << ", " << $2.size << std::endl;
+						s << ".[] " << temp << ", " << $3.size << std::endl;
 						
 						//Add to symbol table
 						
@@ -194,26 +255,26 @@ declaration:
 		;
 declaration-type:
 		INTEGER	{
-				$$.type = $0;
+				$$.type = "integer";
 				$$.size = 0;
 		}
 	  | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
 				$$.type = "integer";
-				$$.size = atoi($2);
+				$$.size = atoi($3);
 		}
 		;
 identifier-block:
 		identifier		{
-			$$.identifiers.push_back($0);
+			$$.identifiers.push_back($1);
 		}
       | identifier COMMA identifier-block {
-			$$.identifiers = $1.identifiers;
-			$$.identifiers.push_back($0);
+			$$.identifiers = $3.identifiers;
+			$$.identifiers.push_back($1);
 		}
 		;
 identifier:
 		IDENT		{
-			$$.identifier = $0;
+			$$.identifier = $1;
 		}
 		;
 statement:
@@ -221,24 +282,22 @@ statement:
 			stringstream s;
 			
 			//Lookup from symbol table
-			string temp = lookup($0.identifier);
+			string temp = lookup($1.identifier);
 			
-			unsigned index = $0.index;
+			unsigned index = $1.index;
 			if(index != -1) {
-				s << "=[] " << temp << ", " << $2.ret_name << ", " << index << std::endl;
+				s << "=[] " << temp << ", " << $3.ret_name << ", " << index << std::endl;
 			} else {
-				s << "= " << temp << ", " << $2.ret_name << std::endl;
+				s << "= " << temp << ", " << $3.ret_name << std::endl;
 			}
 			$$.IR = s.str();
 		}
 	  | IF bool-expr THEN statement-block ENDIF {
-	  
 			//TO DO: Make sure $ entries are properly indexed
 			//Remove $0
-	  
+			
 			string label0 = make_label();
 			string label1 = make_label();
-			string label2 = make_label();
 			stringstream s;
 			
 			//Condition
@@ -246,27 +305,22 @@ statement:
 			//Jump into branch
 			s << "?:=" << label0 << ", " << $2.ret_name << std::endl;
 			
-			//Jump into else
+			//Skip branch
 			s << ":= " << label1 << std::endl;
 			
 			//Branch
 			s << ":" << label0 << std::endl;
 			s << $4.IR;
-			//Jump to finally
-			s << ":= " << label2 << std::endl;
-			
-			//Else
-			s << ": " << label1 << std::endl;
 			
 			//Finally
-			s << ": " << label2 << std::endl;
-			s << $6.IR;
+			s << ": " << label1 << std::endl;
 			
 			$$.IR = s.str();
 		}
 	  | IF bool-expr THEN statement-block ELSE statement-block ENDIF {
 			string label0 = make_label();
 			string label1 = make_label();
+			string label2 = make_label();
 			stringstream s;
 			
 			//Condition
@@ -274,27 +328,57 @@ statement:
 			//Jump into branch
 			s << "?:=" << label0 << ", " << $2.ret_name << std::endl;
 			
-			//Skip branch
+			//Jump into else
 			s << ":= " << label1 << std::endl;
 			
 			//Branch
 			s << ":" << label0 << std::endl;
 			s << $4.IR;
 			
-			//Finally
+			//Jump to finally
+			s << ":= " << label2 << std::endl;
+			
+			//Else
 			s << ": " << label1 << std::endl;
+			
+			//Finally
+			s << ": " << label2 << std::endl;
+			s << $6.IR;
 			$$.IR = s.str();
 			
 		}
-	  | WHILE bool-expr BEGINLOOP statement-block ENDLOOP
-			{ printf("statement -> WHILE bool-expr BEGINLOOP statement-block ENDLOOP\n"); }
-	  | DO BEGINLOOP statement-block ENDLOOP WHILE bool-expr
-			{ printf("statement -> DO BEGINLOOP statement-block ENDLOOP WHILE bool-expr\n"); }
+	  | WHILE bool-expr BEGINLOOP statement-block ENDLOOP {
+			string label_body = make_label();
+			string label_condition = make_label();
+			
+			ostringstream s;
+			s << ":= " << label_condition << endl;
+			s << ": " << label_body << endl; 
+			s << $4.IR << endl;
+			s << ": " << label_condition << endl;
+			s << $2.IR << endl;
+			s << "?:= " << label_body << $2.ret_name << endl;
+			
+			$$.IR = s.str();
+		}
+	  | DO BEGINLOOP statement-block ENDLOOP WHILE bool-expr {
+			string label_body = make_label();
+			string label_condition = make_label();
+			
+			ostringstream s;
+			s << ": " << label_body << endl; 
+			s << $3.IR << endl;
+			s << ": " << label_condition << endl;
+			s << $6.IR << endl;
+			s << "?:= " << label_body << $6.ret_name << endl;
+			
+			$$.IR = s.str();
+		}
 	  | READ var-block	{
 			stringstream s;
-			for(unsigned i = 0; i < $1.variables.size(); i++) {
-				auto var = $1.variables[i];
-				if(var.second == (unsigned)-1) {
+			for(unsigned i = 0; i < $2.variables.size(); i++) {
+				auto var = $2.variables[i];
+				if(var.second == "") {
 					s << ".< " << var.first << endl;
 				} else {
 					s << ".[]< " << var.first << ", " << var.second << std::endl;
@@ -304,10 +388,10 @@ statement:
 		}
 	  | WRITE var-block		{
 			stringstream s;
-			for(unsigned i = 0; i < $1.variables.size(); i++) {
-				auto var = $1.variables[i];
-				if(var.second == (unsigned)-1) {
-					s << ".> " << var.first << endl;
+			for(unsigned i = 0; i < $2.variables.size(); i++) {
+				auto var = $2.variables[i];
+				if(var.second == "") {
+					s << ".> " << var.first << std::endl;
 				} else {
 					s << ".[]> " << var.first << ", " << var.second << std::endl;
 				}
@@ -319,99 +403,240 @@ statement:
 		}
 	  | RETURN expression	{
 			stringstream s;
-			s << "ret " << $1.ret_name << endl;
+			s << "ret " << $2.ret_name << endl;
 			$$.IR = s.str();
 		}
 		;
 bool-expr:
-		relation-and-expr
-					{ printf("bool-expr -> relation-and-expr\n"); }
-	  | relation-and-expr OR bool-expr
-					{ printf("bool-expr -> relation-and-expr OR bool-expr\n"); }
+		relation-and-expr {
+			$$.IR = $1.IR;
+			$$.ret_name = $1.ret_name;
+		}
+	  | relation-and-expr OR bool-expr {
+			string temp = make_temp();
+	  
+			ostringstream s;
+			s << $1.IR << std::endl;
+			s << $3.IR << std::endl;
+			s << "|| " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
+			$$.IR = s.str();
+			$$.ret_name = temp;
+		}
 		;
 relation-and-expr:
-		relation-expr
-				{ printf("relation-and-expr -> relation-expr\n"); }
-	  | relation-expr AND relation-and-expr
-				{ printf("relation-and-expr -> relation-expr AND relation-and-expr\n"); }
+		relation-expr {
+			$$.IR = $1.IR;
+			$$.ret_name = $1.ret_name;
+		}
+	  | relation-expr AND relation-and-expr {
+			string temp = make_temp();
+	  
+			ostringstream s;
+			s << $1.IR << std::endl;
+			s << $3.IR << std::endl;
+			s << "&& " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
+			$$.IR = s.str();
+			$$.ret_name = temp;
+		}
 		;
 relation-expr:
-		relation-expr-body
-				{ printf("relation-expr -> relation-expr-body\n"); }
-	  | NOT relation-expr-body
-				{ printf("relation-expr -> NOT relation-expr-body\n"); }
+		relation-expr-body {
+			$$.IR = $1.IR;
+			$$.ret_name = $1.ret_name;
+		}
+	  | NOT relation-expr-body {
+			string temp = make_temp();
+	  
+			ostringstream s;
+			s << $2.IR << std::endl;
+			s << "! " << temp << ", " << $2.ret_name << endl;
+			$$.IR = s.str();
+			$$.ret_name = temp;
+	  }
 		;
 relation-expr-body:
-		expression comp expression
-				{ printf("relation-expr-body -> expression comp expression\n"); }
-	  | TRUE						{ printf("relation-expr-body -> TRUE\n"); }
-	  | FALSE						{ printf("relation-expr-body -> FALSE\n"); }
-	  | L_PAREN bool-expr R_PAREN	{ printf("relation-expr-body -> L_PAREN bool-expr R_PAREN\n"); }
+		expression comp expression {
+			string temp = make_temp();
+	  
+			ostringstream s;
+			s << $1.IR << std::endl;
+			s << $3.IR << std::endl;
+			s << $2.op << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
+			$$.IR = s.str();
+			$$.ret_name = temp;
+		}
+	  | TRUE						{
+			$$.ret_name = "true";
+		}
+	  | FALSE						{
+			$$.ret_name = "false";
+		}
+	  | L_PAREN bool-expr R_PAREN	{
+			$$.IR = $2.IR;
+			$$.ret_name = $2.ret_name;
+		}
 		;
 comp:
-		EQ			{ printf("comp -> EQ\n"); }
-	  | NEQ			{ printf("comp -> NEQ\n"); }
-	  | LT			{ printf("comp -> LT\n"); }
-	  | GT			{ printf("comp -> GT\n"); }
-	  | LTE			{ printf("comp -> LTE\n"); }
-	  | GTE			{ printf("comp -> GTE\n"); }
+		EQ			{ $$.op = "=="; }
+	  | NEQ			{ $$.op = "!="; }
+	  | LT			{ $$.op = "<"; }
+	  | GT			{ $$.op = ">"; }
+	  | LTE			{ $$.op = "<="; }
+	  | GTE			{ $$.op = ">="; }
 		;
 expression:
-		multiplicative-expr
-					{ printf("expression -> multiplicative-expr\n"); }
-	  | multiplicative-expr ADD expression 
-					{ printf("expression -> multiplicative-expr ADD expression\n"); }
-	  | multiplicative-expr SUB expression
-					{ printf("expression -> multiplicative-expr SUB expression\n"); }
+		multiplicative-expr {
+			$$.IR = $1.IR;
+			$$.ret_name = $1.ret_name;
+		}
+	  | multiplicative-expr ADD expression { 
+			ostringstream s;
+			s << $1.IR << endl;
+			s << $3.IR << endl;
+			
+			string temp = make_temp();
+			s << "+ " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
+			
+			$$.IR = s.str();
+			$$.ret_name = temp;
+		}
+	  | multiplicative-expr SUB expression {
+			ostringstream s;
+			s << $1.IR << endl;
+			s << $3.IR << endl;
+			
+			string temp = make_temp();
+			s << "- " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
+			
+			$$.IR = s.str();
+			$$.ret_name = temp;
+		}
 		;
 multiplicative-expr:
-		term		{ printf("multiplicative-expr -> term\n"); }
-	  | term MULT multiplicative-expr
-					{ printf("multiplicative-expr -> term MULT multiplicative-expr\n"); }
-	  | term DIV multiplicative-expr
-					{ printf("multiplicative-expr -> term DIV multiplicative-expr\n"); }
-	  | term MOD multiplicative-expr
-					{ printf("multiplicative-expr -> term MOD multiplicative-expr\n"); }
+		term {
+			$$.IR = $1.IR;
+			$$.ret_name = $1.ret_name;
+		}
+	  | term MULT multiplicative-expr {
+			ostringstream s;
+			s << $1.IR << endl;
+			s << $3.IR << endl;
+			
+			string temp = make_temp();
+			s << "* " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
+			
+			$$.IR = s.str();
+			$$.ret_name = temp;
+		}
+	  | term DIV multiplicative-expr {
+			ostringstream s;
+			s << $1.IR << endl;
+			s << $3.IR << endl;
+			
+			string temp = make_temp();
+			s << "/ " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
+			
+			$$.IR = s.str();
+			$$.ret_name = temp;
+		}
+	  | term MOD multiplicative-expr {
+			ostringstream s;
+			s << $1.IR << endl;
+			s << $3.IR << endl;
+			
+			string temp = make_temp();
+			s << "% " << temp << ", " << $1.ret_name << ", " << $3.ret_name << endl;
+			
+			$$.IR = s.str();
+			$$.ret_name = temp;
+		}
 		;
 term:
-		term-body			{ printf("term -> term-body\n"); }
-	  | MINUS term-body		{ printf("term -> MINUS term-body\n"); }
-	  | IDENT L_PAREN expression-block R_PAREN
-							{ printf("term -> IDENT L_PAREN expression-block R_PAREN\n"); }
+		term-body			{
+			$$.IR = $1.IR;
+			$$.ret_name = $1.ret_name;
+		}
+	  | MINUS term-body		{
+			string temp = make_temp();
+			
+			ostringstream s;
+			s << $2.IR << endl;
+			s << "- " << temp << ", 0, " << $2.ret_name;
+			
+			$$.IR = s.str();
+			$$.ret_name = temp;
+		}
+	  | IDENT L_PAREN expression-block R_PAREN {
+			ostringstream s;
+			for(const auto& e : $3.expressions) {
+				s << e.IR << endl;
+			}
+			for(const auto& e : $3.expressions) {
+				s << "param " << e.ret_name << endl;
+			}
+			string temp = make_temp();
+			s << "call " << $1 << ", " << temp << endl;
+			
+			$$.IR = s.str();
+			$$.ret_name = temp;
+		}
 		;
 term-body:
-		NUMBER		{ printf("term-body -> NUMBER\n"); }
-	  | var			{ printf("term-body -> var\n"); }
-	  | L_PAREN expression R_PAREN
-					{ printf("term-body -> L_PAREN expression R_PAREN\n"); }
+		NUMBER		{
+			$$.ret_name = $1;
+		}
+	  | var			{
+			if($1.index != (unsigned)-1) {
+				string temp = make_temp();
+				ostringstream s;
+				s << "=[] " << temp << ", " << $1.identifier << ", " << $1.index;
+				$$.IR = s.str();
+				$$.ret_name = temp;
+			} else {
+				$$.ret_name = $1.ret_name;
+			}
+		}
+	  | L_PAREN expression R_PAREN {
+			$$.IR = $2.IR;
+			$$.ret_name = $2.ret_name;
+		}
 		;
 expression-block:
-		expression	{ printf("expression-block -> expression\n"); }
-	  | expression COMMA expression-block
-					{ printf("expression-block -> expression COMMA expression-block\n"); }
+		expression	{
+			$$.expressions.push_back($1);
+		}
+	  | expression COMMA expression-block {
+			$$.expressions = $3.expressions;
+			$$.expressions.push_back($1);
+		}
 		;
 var-block:
 		var			{
-			$$.variables.push_back(make_pair($0.identifier, $0.index));
+			$$.variables.push_back(make_pair($1.identifier, $1.index));
 		}
 	  | var COMMA var-block {
-			$$.variables = $2.variables;
-			$$.variables.push_back(make_pair($0.identifier, $0.index));
+			$$.variables = $3.variables;
+			$$.variables.push_back(make_pair($1.identifier, $1.index));
 		}
 		;
 var:
 		identifier		{
-			$$.identifier = $0;
-			$$.index = -1;
+			auto pair = symbols.find($1);
+			if(pair != symbols.end()) {
+				$$.identifier = pair.second;
+			} else {
+				throw exception("invalid symbol");
+			}
 		}
 	  | identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
-			$$.identifier = $0;
-			int index = atoi($2);
-			if(index > -1) {
-				$$.index = (unsigned)index;
+			auto pair = symbols.find($1);
+			if(pair != symbols.end()) {
+				$$.identifier = pair.second;
 			} else {
-				//Error
+				throw exception("invalid symbol");
 			}
+			
+			$$.index = $3.ret_name;
 		}
 		;
 %%
diff --git a/part_3/y.tab.c b/part_3/y.tab.c
index faf178c..db55d69 100644
--- a/part_3/y.tab.c
+++ b/part_3/y.tab.c
@@ -64,14 +64,80 @@
 /* Copy the first part of user declarations.  */
 #line 1 "862012666-862083506.y" /* yacc.c:339  */
 
- #include <stdio.h>
- #include <stdlib.h>
- void yyerror(const char *msg);
- extern int currLine;
- extern int currPos;
- FILE * yyin;
-
-#line 75 "y.tab.c" /* yacc.c:339  */
+#include<stdio.h>
+#include<stdlib.h>
+#include<map.h>
+using namespace std;
+	
+	void yyerror(const char *msg);
+	extern int currLine;
+	extern int currPos;
+	FILE * yyin;
+	
+	map<string, pair<string, unsigned>> symbols;
+	
+	string make_label() {
+		static unsigned count;
+		ostringstream s;
+		s << "l" << count << endl;
+		count++;
+		return s.str();
+	}
+	string make_temp() {
+		static unsigned count;
+		ostringstream s;
+		s << "t" << count << endl;
+		count++;
+		return s.str();
+	}
+	
+	struct Statement {
+		std::string IR;
+	};
+	struct Expression {
+		std::string IR;
+		std::string ret_name;
+	};
+	struct ExpressionBlock {
+		vector<Expression> expressions;
+	};
+	
+	struct Var {
+		std::string identifier;
+		std::string index;
+	};
+	struct VarBlock {
+		std::vector<std::pair<std::string, std::string>> variables;
+	};
+	
+	struct Identifier {
+		std::string identifier;
+	};
+	struct IdentifierBlock {
+		vector<std::string> identifiers;
+	};
+	struct DeclarationBlock {
+		std::string IR;
+		std::vector<std::tuple<std::string, std::string, unsigned>> variables;
+	};
+	struct Declaration {
+		std::string IR;
+		std::vector<std::string> identifiers;
+		std::string type;
+		unsigned size;
+	};
+	struct DeclarationType {
+		std::string type;
+		unsigned size;
+	};
+	struct Operator {
+		string op;
+	};
+	struct Program {
+		string IR;
+	};
+
+#line 141 "y.tab.c" /* yacc.c:339  */
 
 # ifndef YY_NULLPTR
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -165,13 +231,13 @@ extern int yydebug;
 
 union YYSTYPE
 {
-#line 10 "862012666-862083506.y" /* yacc.c:355  */
+#line 76 "862012666-862083506.y" /* yacc.c:355  */
 
   double dval;
   int ival;
   char* ident;
 
-#line 175 "y.tab.c" /* yacc.c:355  */
+#line 241 "y.tab.c" /* yacc.c:355  */
 };
 
 typedef union YYSTYPE YYSTYPE;
@@ -188,7 +254,7 @@ int yyparse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 192 "y.tab.c" /* yacc.c:358  */
+#line 258 "y.tab.c" /* yacc.c:358  */
 
 #ifdef short
 # undef short
@@ -488,15 +554,15 @@ static const yytype_uint8 yytranslate[] =
 
 #if YYDEBUG
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
-static const yytype_uint8 yyrline[] =
+static const yytype_uint16 yyrline[] =
 {
-       0,    33,    33,    35,    36,    39,    52,    53,    57,    59,
-      63,    64,    68,    70,    74,    78,    79,    83,    84,    88,
-      91,    93,    95,    97,    99,   101,   102,   103,   104,   107,
-     109,   113,   115,   119,   121,   125,   127,   128,   129,   132,
-     133,   134,   135,   136,   137,   140,   142,   144,   148,   149,
-     151,   153,   157,   158,   159,   163,   164,   165,   169,   170,
-     174,   175,   179,   180
+       0,   129,   129,   133,   136,   144,   174,   175,   181,   187,
+     201,   202,   207,   210,   218,   258,   262,   268,   271,   277,
+     282,   296,   321,   351,   365,   378,   390,   402,   405,   412,
+     416,   428,   432,   444,   448,   459,   469,   472,   475,   481,
+     482,   483,   484,   485,   486,   489,   493,   504,   517,   521,
+     532,   543,   556,   560,   570,   586,   589,   600,   606,   609,
+     615,   618,   624,   632
 };
 #endif
 
@@ -1357,373 +1423,776 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 33 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("program -> function-block\n"); }
-#line 1363 "y.tab.c" /* yacc.c:1646  */
+#line 129 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Statement).IR = (yyvsp[0].Statement).IR;
+		}
+#line 1431 "y.tab.c" /* yacc.c:1646  */
+    break;
+
+  case 3:
+#line 133 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+
+			  }
+#line 1439 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 4:
-#line 36 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("function-block -> function function-block\n"); }
-#line 1369 "y.tab.c" /* yacc.c:1646  */
+#line 136 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+				ostringstream s;
+				s << (yyvsp[-1].Statement).IR << endl;
+				s << (yyvsp[0].Statement).IR << endl;
+				(yyval.Statement).IR = s.str();
+			}
+#line 1450 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 5:
-#line 49 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("function -> FUNCTION identifier SEMICOLON BEGIN_PARAMS declaration-block-optional END_PARAMS BEGIN_LOCALS declaration-block-optional END_LOCALS BEGIN_BODY statement-block-optional END_BODY\n"); }
-#line 1375 "y.tab.c" /* yacc.c:1646  */
+#line 153 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+		
+			stringstream s;
+			s << (yyvsp[-10].Identifier).identifier << std::endl;
+			
+			s << (yyvsp[-7].DeclarationBlock).IR << std::endl;
+			
+			s << (yyvsp[-4].DeclarationBlock).IR << std::endl;
+			
+			s << (yyvsp[-1].Statement).IR<< std::endl;
+			
+			
+			
+			//Free the symbols and temps
+			
+			s << "endfunc" << std::endl;
+			
+			(yyval.Statement).IR = s.str();
+		}
+#line 1474 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 6:
-#line 52 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("declaration-block-optional -> epsilon\n"); }
-#line 1381 "y.tab.c" /* yacc.c:1646  */
+#line 174 "862012666-862083506.y" /* yacc.c:1646  */
+    {}
+#line 1480 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 7:
-#line 54 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("declaration-block-optional -> declaration-block\n"); }
-#line 1387 "y.tab.c" /* yacc.c:1646  */
+#line 175 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.DeclarationBlock).IR = (yyvsp[0].DeclarationBlock).IR;
+			(yyval.DeclarationBlock).variables = (yyvsp[0].DeclarationBlock).IR;
+		}
+#line 1489 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 8:
-#line 58 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("declaration-block -> declaration SEMICOLON\n"); }
-#line 1393 "y.tab.c" /* yacc.c:1646  */
+#line 181 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.DeclarationBlock).IR = (yyvsp[-1].Declaration).IR;
+			for(unsigned i = 0; i < (yyvsp[-1].Declaration).identifiers.size(); i++) {
+				(yyval.DeclarationBlock).variables.push_back(make_tuple((yyvsp[-1].Declaration).identifiers[i], (yyvsp[-1].Declaration).type, (yyvsp[-1].Declaration).size));
+			}
+		}
+#line 1500 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 9:
-#line 60 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("declaration-block -> declaration SEMICOLON declaration-block\n"); }
-#line 1399 "y.tab.c" /* yacc.c:1646  */
+#line 187 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			stringstream s;
+			s << (yyvsp[-2].Declaration).IR;
+			s << (yyvsp[0].DeclarationBlock).IR;
+			(yyval.DeclarationBlock).IR = s.str();
+			
+			(yyval.DeclarationBlock).variables = (yyvsp[-2].Declaration).variables;
+			
+			for(unsigned i = 0; i < (yyvsp[-2].Declaration).identifiers.size(); i++) {
+				(yyval.DeclarationBlock).variables.push_back(make_tuple((yyvsp[-2].Declaration).identifiers[i], (yyvsp[-2].Declaration).type, (yyvsp[-2].Declaration).size));
+			}
+		}
+#line 1517 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 10:
-#line 63 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement-block-optional -> epsilon\n"); }
-#line 1405 "y.tab.c" /* yacc.c:1646  */
+#line 201 "862012666-862083506.y" /* yacc.c:1646  */
+    {}
+#line 1523 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 11:
-#line 65 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement-block-optional -> statement-block\n"); }
-#line 1411 "y.tab.c" /* yacc.c:1646  */
+#line 202 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Statement).IR = (yyvsp[0].Statement).IR;
+		}
+#line 1531 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 12:
-#line 69 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement-block -> statement SEMICOLON\n"); }
-#line 1417 "y.tab.c" /* yacc.c:1646  */
+#line 207 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Statement).IR = (yyvsp[-1].Statement).IR;
+		}
+#line 1539 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 13:
-#line 71 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement-block -> statement SEMICOLON statement-block\n"); }
-#line 1423 "y.tab.c" /* yacc.c:1646  */
+#line 210 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			stringstream s;
+			s << (yyvsp[-2].Statement).IR;
+			s << (yyvsp[0].Statement).IR;
+			(yyval.Statement).IR = s.str();
+		}
+#line 1550 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 14:
-#line 75 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("declaration -> identifier-block COLON declaration-type\n"); }
-#line 1429 "y.tab.c" /* yacc.c:1646  */
+#line 218 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+		
+				(yyval.Declaration).identifiers = (yyvsp[-2].IdentifierBlock).identifiers;
+				(yyval.Declaration).type = (yyvsp[0].DeclarationType).type;
+				(yyval.Declaration).size = (yyvsp[0].DeclarationType).size;
+				
+				stringstream s;
+				if((yyval.Declaration).size > 0) {
+					for(unsigned i = 0; i < (yyval.Declaration).identifiers.size(); i++) {
+						string identifier = (yyval.Declaration).identifiers[i];
+						
+						//Check if already in symbol table
+						
+						//Make a temp
+						string temp = make_temp();
+						s << ". " << temp << std::endl;
+						
+						//Add to symbol table
+						
+						//Make sure to free the symbol table entry and temp
+					}
+				} else {
+					for(unsigned i = 0; i < (yyval.Declaration).identifiers.size(); i++) {
+						string identifier = (yyval.Declaration).identifiers[i];
+						
+						//Check if already in symbol table
+						
+						//Make a temp
+						string temp = make_temp();
+						s << ".[] " << temp << ", " << (yyvsp[0].DeclarationType).size << std::endl;
+						
+						//Add to symbol table
+						
+						//Make sure to free the symbol table entry and temp
+					}
+				}
+				(yyval.Declaration).IR = s.str();
+		}
+#line 1593 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 15:
-#line 78 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("declaration-type -> INTEGER\n"); }
-#line 1435 "y.tab.c" /* yacc.c:1646  */
+#line 258 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+				(yyval.DeclarationType).type = "integer";
+				(yyval.DeclarationType).size = 0;
+		}
+#line 1602 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 16:
-#line 80 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("declaration-type -> ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n"); }
-#line 1441 "y.tab.c" /* yacc.c:1646  */
+#line 262 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+				(yyval.DeclarationType).type = "integer";
+				(yyval.DeclarationType).size = atoi((yyvsp[-3].dval));
+		}
+#line 1611 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 17:
-#line 83 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("identifier-block -> identifier\n"); }
-#line 1447 "y.tab.c" /* yacc.c:1646  */
+#line 268 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.IdentifierBlock).identifiers.push_back((yyvsp[0].Identifier));
+		}
+#line 1619 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 18:
-#line 85 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("identifier-block -> identifier COMMA identifier-block\n"); }
-#line 1453 "y.tab.c" /* yacc.c:1646  */
+#line 271 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.IdentifierBlock).identifiers = (yyvsp[0].IdentifierBlock).identifiers;
+			(yyval.IdentifierBlock).identifiers.push_back((yyvsp[-2].Identifier));
+		}
+#line 1628 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 19:
-#line 88 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("identifier -> IDENT(%s)\n", (yyvsp[0].ident)); }
-#line 1459 "y.tab.c" /* yacc.c:1646  */
+#line 277 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Identifier).identifier = (yyvsp[0].ident);
+		}
+#line 1636 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 20:
-#line 92 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement -> var ASSIGN expression\n"); }
-#line 1465 "y.tab.c" /* yacc.c:1646  */
+#line 282 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			stringstream s;
+			
+			//Lookup from symbol table
+			string temp = lookup((yyvsp[-2].Var).identifier);
+			
+			unsigned index = (yyvsp[-2].Var).index;
+			if(index != -1) {
+				s << "=[] " << temp << ", " << (yyvsp[0].Expression).ret_name << ", " << index << std::endl;
+			} else {
+				s << "= " << temp << ", " << (yyvsp[0].Expression).ret_name << std::endl;
+			}
+			(yyval.Statement).IR = s.str();
+		}
+#line 1655 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 21:
-#line 94 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement -> IF bool-expr THEN statement-then ENDIF\n"); }
-#line 1471 "y.tab.c" /* yacc.c:1646  */
+#line 296 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			//TO DO: Make sure $ entries are properly indexed
+			//Remove $0
+			
+			string label0 = make_label();
+			string label1 = make_label();
+			stringstream s;
+			
+			//Condition
+			s << (yyvsp[-3].Expression).IR;
+			//Jump into branch
+			s << "?:=" << label0 << ", " << (yyvsp[-3].Expression).ret_name << std::endl;
+			
+			//Skip branch
+			s << ":= " << label1 << std::endl;
+			
+			//Branch
+			s << ":" << label0 << std::endl;
+			s << (yyvsp[-1].Statement).IR;
+			
+			//Finally
+			s << ": " << label1 << std::endl;
+			
+			(yyval.Statement).IR = s.str();
+		}
+#line 1685 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 22:
-#line 96 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement -> IF bool-expr THEN statement-block ELSE statement-block ENDIF\n"); }
-#line 1477 "y.tab.c" /* yacc.c:1646  */
+#line 321 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			string label0 = make_label();
+			string label1 = make_label();
+			string label2 = make_label();
+			stringstream s;
+			
+			//Condition
+			s << (yyvsp[-5].Expression).IR;
+			//Jump into branch
+			s << "?:=" << label0 << ", " << (yyvsp[-5].Expression).ret_name << std::endl;
+			
+			//Jump into else
+			s << ":= " << label1 << std::endl;
+			
+			//Branch
+			s << ":" << label0 << std::endl;
+			s << (yyvsp[-3].Statement).IR;
+			
+			//Jump to finally
+			s << ":= " << label2 << std::endl;
+			
+			//Else
+			s << ": " << label1 << std::endl;
+			
+			//Finally
+			s << ": " << label2 << std::endl;
+			s << (yyvsp[-1].Statement).IR;
+			(yyval.Statement).IR = s.str();
+			
+		}
+#line 1720 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 23:
-#line 98 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement -> WHILE bool-expr BEGINLOOP statement-block ENDLOOP\n"); }
-#line 1483 "y.tab.c" /* yacc.c:1646  */
+#line 351 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			string label_body = make_label();
+			string label_condition = make_label();
+			
+			ostringstream s;
+			s << ":= " << label_condition << endl;
+			s << ": " << label_body << endl; 
+			s << (yyvsp[-1].Statement).IR << endl;
+			s << ": " << label_condition << endl;
+			s << (yyvsp[-3].Expression).IR << endl;
+			s << "?:= " << label_body << (yyvsp[-3].Expression).ret_name << endl;
+			
+			(yyval.Statement).IR = s.str();
+		}
+#line 1739 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 24:
-#line 100 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement -> DO BEGINLOOP statement-block ENDLOOP WHILE bool-expr\n"); }
-#line 1489 "y.tab.c" /* yacc.c:1646  */
+#line 365 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			string label_body = make_label();
+			string label_condition = make_label();
+			
+			ostringstream s;
+			s << ": " << label_body << endl; 
+			s << (yyvsp[-3].Statement).IR << endl;
+			s << ": " << label_condition << endl;
+			s << (yyvsp[0].Expression).IR << endl;
+			s << "?:= " << label_body << (yyvsp[0].Expression).ret_name << endl;
+			
+			(yyval.Statement).IR = s.str();
+		}
+#line 1757 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 25:
-#line 101 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement -> READ var-block\n"); }
-#line 1495 "y.tab.c" /* yacc.c:1646  */
+#line 378 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			stringstream s;
+			for(unsigned i = 0; i < (yyvsp[0].VarBlock).variables.size(); i++) {
+				auto var = (yyvsp[0].VarBlock).variables[i];
+				if(var.second == "") {
+					s << ".< " << var.first << endl;
+				} else {
+					s << ".[]< " << var.first << ", " << var.second << std::endl;
+				}
+			}
+			(yyval.Statement).IR = s.str();
+		}
+#line 1774 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 26:
-#line 102 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement -> WRITE var-block\n"); }
-#line 1501 "y.tab.c" /* yacc.c:1646  */
+#line 390 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			stringstream s;
+			for(unsigned i = 0; i < (yyvsp[0].VarBlock).variables.size(); i++) {
+				auto var = (yyvsp[0].VarBlock).variables[i];
+				if(var.second == "") {
+					s << ".> " << var.first << std::endl;
+				} else {
+					s << ".[]> " << var.first << ", " << var.second << std::endl;
+				}
+			}
+			(yyval.Statement).IR = s.str();
+		}
+#line 1791 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 27:
-#line 103 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement -> BREAK\n"); }
-#line 1507 "y.tab.c" /* yacc.c:1646  */
+#line 402 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+	  
+		}
+#line 1799 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 28:
-#line 104 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("statement -> RETURN expression\n"); }
-#line 1513 "y.tab.c" /* yacc.c:1646  */
+#line 405 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			stringstream s;
+			s << "ret " << (yyvsp[0].Expression).ret_name << endl;
+			(yyval.Statement).IR = s.str();
+		}
+#line 1809 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 29:
-#line 108 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("bool-expr -> relation-and-expr\n"); }
-#line 1519 "y.tab.c" /* yacc.c:1646  */
+#line 412 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
+			(yyval.Expression).ret_name = (yyvsp[0].Expression).ret_name;
+		}
+#line 1818 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 30:
-#line 110 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("bool-expr -> relation-and-expr OR bool-expr\n"); }
-#line 1525 "y.tab.c" /* yacc.c:1646  */
+#line 416 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			string temp = make_temp();
+	  
+			ostringstream s;
+			s << (yyvsp[-2].Expression).IR << std::endl;
+			s << (yyvsp[0].Expression).IR << std::endl;
+			s << "|| " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
+			(yyval.Expression).IR = s.str();
+			(yyval.Expression).ret_name = temp;
+		}
+#line 1833 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 31:
-#line 114 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("relation-and-expr -> relation-expr\n"); }
-#line 1531 "y.tab.c" /* yacc.c:1646  */
+#line 428 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
+			(yyval.Expression).ret_name = (yyvsp[0].Expression).ret_name;
+		}
+#line 1842 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 32:
-#line 116 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("relation-and-expr -> relation-expr AND relation-and-expr\n"); }
-#line 1537 "y.tab.c" /* yacc.c:1646  */
+#line 432 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			string temp = make_temp();
+	  
+			ostringstream s;
+			s << (yyvsp[-2].Expression).IR << std::endl;
+			s << (yyvsp[0].Expression).IR << std::endl;
+			s << "&& " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
+			(yyval.Expression).IR = s.str();
+			(yyval.Expression).ret_name = temp;
+		}
+#line 1857 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 33:
-#line 120 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("relation-expr -> relation-expr-body\n"); }
-#line 1543 "y.tab.c" /* yacc.c:1646  */
+#line 444 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
+			(yyval.Expression).ret_name = (yyvsp[0].Expression).ret_name;
+		}
+#line 1866 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 34:
-#line 122 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("relation-expr -> NOT relation-expr-body\n"); }
-#line 1549 "y.tab.c" /* yacc.c:1646  */
+#line 448 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			string temp = make_temp();
+	  
+			ostringstream s;
+			s << (yyvsp[0].Expression).IR << std::endl;
+			s << "! " << temp << ", " << (yyvsp[0].Expression).ret_name << endl;
+			(yyval.Expression).IR = s.str();
+			(yyval.Expression).ret_name = temp;
+	  }
+#line 1880 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 35:
-#line 126 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("relation-expr-body -> expression comp expression\n"); }
-#line 1555 "y.tab.c" /* yacc.c:1646  */
+#line 459 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			string temp = make_temp();
+	  
+			ostringstream s;
+			s << (yyvsp[-2].Expression).IR << std::endl;
+			s << (yyvsp[0].Expression).IR << std::endl;
+			s << (yyvsp[-1].Operator).op << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
+			(yyval.Expression).IR = s.str();
+			(yyval.Expression).ret_name = temp;
+		}
+#line 1895 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 36:
-#line 127 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("relation-expr-body -> TRUE\n"); }
-#line 1561 "y.tab.c" /* yacc.c:1646  */
+#line 469 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Expression).ret_name = "true";
+		}
+#line 1903 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 37:
-#line 128 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("relation-expr-body -> FALSE\n"); }
-#line 1567 "y.tab.c" /* yacc.c:1646  */
+#line 472 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Expression).ret_name = "false";
+		}
+#line 1911 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 38:
-#line 129 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("relation-expr-body -> L_PAREN bool-expr R_PAREN\n"); }
-#line 1573 "y.tab.c" /* yacc.c:1646  */
+#line 475 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Expression).IR = (yyvsp[-1].Expression).IR;
+			(yyval.Expression).ret_name = (yyvsp[-1].Expression).ret_name;
+		}
+#line 1920 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 39:
-#line 132 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("comp -> EQ\n"); }
-#line 1579 "y.tab.c" /* yacc.c:1646  */
+#line 481 "862012666-862083506.y" /* yacc.c:1646  */
+    { (yyval.Operator).op = "=="; }
+#line 1926 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 40:
-#line 133 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("comp -> NEQ\n"); }
-#line 1585 "y.tab.c" /* yacc.c:1646  */
+#line 482 "862012666-862083506.y" /* yacc.c:1646  */
+    { (yyval.Operator).op = "!="; }
+#line 1932 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 41:
-#line 134 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("comp -> LT\n"); }
-#line 1591 "y.tab.c" /* yacc.c:1646  */
+#line 483 "862012666-862083506.y" /* yacc.c:1646  */
+    { (yyval.Operator).op = "<"; }
+#line 1938 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 42:
-#line 135 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("comp -> GT\n"); }
-#line 1597 "y.tab.c" /* yacc.c:1646  */
+#line 484 "862012666-862083506.y" /* yacc.c:1646  */
+    { (yyval.Operator).op = ">"; }
+#line 1944 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 43:
-#line 136 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("comp -> LTE\n"); }
-#line 1603 "y.tab.c" /* yacc.c:1646  */
+#line 485 "862012666-862083506.y" /* yacc.c:1646  */
+    { (yyval.Operator).op = "<="; }
+#line 1950 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 44:
-#line 137 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("comp -> GTE\n"); }
-#line 1609 "y.tab.c" /* yacc.c:1646  */
+#line 486 "862012666-862083506.y" /* yacc.c:1646  */
+    { (yyval.Operator).op = ">="; }
+#line 1956 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 45:
-#line 141 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("expression -> multiplicative-expr\n"); }
-#line 1615 "y.tab.c" /* yacc.c:1646  */
+#line 489 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
+			(yyval.Expression).ret_name = (yyvsp[0].Expression).ret_name;
+		}
+#line 1965 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 46:
-#line 143 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("expression -> multiplicative-expr ADD expression\n"); }
-#line 1621 "y.tab.c" /* yacc.c:1646  */
+#line 493 "862012666-862083506.y" /* yacc.c:1646  */
+    { 
+			ostringstream s;
+			s << (yyvsp[-2].Expression).IR << endl;
+			s << (yyvsp[0].Expression).IR << endl;
+			
+			string temp = make_temp();
+			s << "+ " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
+			
+			(yyval.Expression).IR = s.str();
+			(yyval.Expression).ret_name = temp;
+		}
+#line 1981 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 47:
-#line 145 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("expression -> multiplicative-expr SUB expression\n"); }
-#line 1627 "y.tab.c" /* yacc.c:1646  */
+#line 504 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			ostringstream s;
+			s << (yyvsp[-2].Expression).IR << endl;
+			s << (yyvsp[0].Expression).IR << endl;
+			
+			string temp = make_temp();
+			s << "- " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
+			
+			(yyval.Expression).IR = s.str();
+			(yyval.Expression).ret_name = temp;
+		}
+#line 1997 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 48:
-#line 148 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("multiplicative-expr -> term\n"); }
-#line 1633 "y.tab.c" /* yacc.c:1646  */
+#line 517 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
+			(yyval.Expression).ret_name = (yyvsp[0].Expression).ret_name;
+		}
+#line 2006 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 49:
-#line 150 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("multiplicative-expr -> term MULT multiplicative-expr\n"); }
-#line 1639 "y.tab.c" /* yacc.c:1646  */
+#line 521 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			ostringstream s;
+			s << (yyvsp[-2].Expression).IR << endl;
+			s << (yyvsp[0].Expression).IR << endl;
+			
+			string temp = make_temp();
+			s << "* " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
+			
+			(yyval.Expression).IR = s.str();
+			(yyval.Expression).ret_name = temp;
+		}
+#line 2022 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 50:
-#line 152 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("multiplicative-expr -> term DIV multiplicative-expr\n"); }
-#line 1645 "y.tab.c" /* yacc.c:1646  */
+#line 532 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			ostringstream s;
+			s << (yyvsp[-2].Expression).IR << endl;
+			s << (yyvsp[0].Expression).IR << endl;
+			
+			string temp = make_temp();
+			s << "/ " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
+			
+			(yyval.Expression).IR = s.str();
+			(yyval.Expression).ret_name = temp;
+		}
+#line 2038 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 51:
-#line 154 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("multiplicative-expr -> term MOD multiplicative-expr\n"); }
-#line 1651 "y.tab.c" /* yacc.c:1646  */
+#line 543 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			ostringstream s;
+			s << (yyvsp[-2].Expression).IR << endl;
+			s << (yyvsp[0].Expression).IR << endl;
+			
+			string temp = make_temp();
+			s << "% " << temp << ", " << (yyvsp[-2].Expression).ret_name << ", " << (yyvsp[0].Expression).ret_name << endl;
+			
+			(yyval.Expression).IR = s.str();
+			(yyval.Expression).ret_name = temp;
+		}
+#line 2054 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 52:
-#line 157 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("term -> term-body\n"); }
-#line 1657 "y.tab.c" /* yacc.c:1646  */
+#line 556 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Expression).IR = (yyvsp[0].Expression).IR;
+			(yyval.Expression).ret_name = (yyvsp[0].Expression).ret_name;
+		}
+#line 2063 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 53:
-#line 158 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("term -> MINUS term-body\n"); }
-#line 1663 "y.tab.c" /* yacc.c:1646  */
+#line 560 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			string temp = make_temp();
+			
+			ostringstream s;
+			s << (yyvsp[0].Expression).IR << endl;
+			s << "- " << temp << ", 0, " << (yyvsp[0].Expression).ret_name;
+			
+			(yyval.Expression).IR = s.str();
+			(yyval.Expression).ret_name = temp;
+		}
+#line 2078 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 54:
-#line 160 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("term -> IDENT L_PAREN expression-block R_PAREN\n"); }
-#line 1669 "y.tab.c" /* yacc.c:1646  */
+#line 570 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			ostringstream s;
+			for(const auto& e : (yyvsp[-1].ExpressionBlock).expressions) {
+				s << e.IR << endl;
+			}
+			for(const auto& e : (yyvsp[-1].ExpressionBlock).expressions) {
+				s << "param " << e.ret_name << endl;
+			}
+			string temp = make_temp();
+			s << "call " << (yyvsp[-3].ident) << ", " << temp << endl;
+			
+			(yyval.Expression).IR = s.str();
+			(yyval.Expression).ret_name = temp;
+		}
+#line 2097 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 55:
-#line 163 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("term-body -> NUMBER\n"); }
-#line 1675 "y.tab.c" /* yacc.c:1646  */
+#line 586 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Expression).ret_name = (yyvsp[0].dval);
+		}
+#line 2105 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 56:
-#line 164 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("term-body -> var\n"); }
-#line 1681 "y.tab.c" /* yacc.c:1646  */
+#line 589 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			if((yyvsp[0].Var).index != (unsigned)-1) {
+				string temp = make_temp();
+				ostringstream s;
+				s << "=[] " << temp << ", " << (yyvsp[0].Var).identifier << ", " << (yyvsp[0].Var).index;
+				(yyval.Expression).IR = s.str();
+				(yyval.Expression).ret_name = temp;
+			} else {
+				(yyval.Expression).ret_name = (yyvsp[0].Var).ret_name;
+			}
+		}
+#line 2121 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 57:
-#line 166 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("term-body -> L_PAREN expression R_PAREN\n"); }
-#line 1687 "y.tab.c" /* yacc.c:1646  */
+#line 600 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.Expression).IR = (yyvsp[-1].Expression).IR;
+			(yyval.Expression).ret_name = (yyvsp[-1].Expression).ret_name;
+		}
+#line 2130 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 58:
-#line 169 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("expression-block -> expression\n"); }
-#line 1693 "y.tab.c" /* yacc.c:1646  */
+#line 606 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.ExpressionBlock).expressions.push_back((yyvsp[0].Expression));
+		}
+#line 2138 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 59:
-#line 171 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("expression-block -> expression COMMA expression-block\n"); }
-#line 1699 "y.tab.c" /* yacc.c:1646  */
+#line 609 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.ExpressionBlock).expressions = (yyvsp[0].ExpressionBlock).expressions;
+			(yyval.ExpressionBlock).expressions.push_back((yyvsp[-2].Expression));
+		}
+#line 2147 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 60:
-#line 174 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("var-block -> var\n"); }
-#line 1705 "y.tab.c" /* yacc.c:1646  */
+#line 615 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.VarBlock).variables.push_back(make_pair((yyvsp[0].Var).identifier, (yyvsp[0].Var).index));
+		}
+#line 2155 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 61:
-#line 176 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("var-block -> var COMMA var-block\n"); }
-#line 1711 "y.tab.c" /* yacc.c:1646  */
+#line 618 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			(yyval.VarBlock).variables = (yyvsp[0].VarBlock).variables;
+			(yyval.VarBlock).variables.push_back(make_pair((yyvsp[-2].Var).identifier, (yyvsp[-2].Var).index));
+		}
+#line 2164 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 62:
-#line 179 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("var -> identifier\n"); }
-#line 1717 "y.tab.c" /* yacc.c:1646  */
+#line 624 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			auto pair = symbols.find((yyvsp[0].Identifier));
+			if(pair != symbols.end()) {
+				(yyval.Var).identifier = pair.second;
+			} else {
+				throw exception("invalid symbol");
+			}
+		}
+#line 2177 "y.tab.c" /* yacc.c:1646  */
     break;
 
   case 63:
-#line 181 "862012666-862083506.y" /* yacc.c:1646  */
-    { printf("var -> identifier L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n"); }
-#line 1723 "y.tab.c" /* yacc.c:1646  */
+#line 632 "862012666-862083506.y" /* yacc.c:1646  */
+    {
+			auto pair = symbols.find((yyvsp[-3].Identifier));
+			if(pair != symbols.end()) {
+				(yyval.Var).identifier = pair.second;
+			} else {
+				throw exception("invalid symbol");
+			}
+			
+			(yyval.Var).index = (yyvsp[-1].Expression).ret_name;
+		}
+#line 2192 "y.tab.c" /* yacc.c:1646  */
     break;
 
 
-#line 1727 "y.tab.c" /* yacc.c:1646  */
+#line 2196 "y.tab.c" /* yacc.c:1646  */
       default: break;
     }
   /* User semantic actions sometimes alter yychar, and that requires
@@ -1951,7 +2420,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 183 "862012666-862083506.y" /* yacc.c:1906  */
+#line 643 "862012666-862083506.y" /* yacc.c:1906  */
 
 
 int main(int argc, char **argv) {
diff --git a/part_3/y.tab.h b/part_3/y.tab.h
index 02d23a9..eb7ebd9 100644
--- a/part_3/y.tab.h
+++ b/part_3/y.tab.h
@@ -104,7 +104,7 @@ extern int yydebug;
 
 union YYSTYPE
 {
-#line 10 "862012666-862083506.y" /* yacc.c:1909  */
+#line 76 "862012666-862083506.y" /* yacc.c:1909  */
 
   double dval;
   int ival;
