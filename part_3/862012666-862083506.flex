%{   
	#include "y.tab.h"	
	#include <string.h>
	#include <assert.h>
	#include <stdlib.h>
	 
	int currLine = 1, currPos = 1;
%}

DIGIT   	[0-9]
LETTER		[a-zA-Z]
ALPHA		[0-9a-zA-Z]
SPACE		[ \t]
LINE        ({SPACE}*.*)*
IDENT		{LETTER}{ALPHA}*(_*{ALPHA}+)*
   
%%

function	{currPos += yyleng;	return FUNCTION;}
if			{currPos += yyleng;	return IF;}
else		{currPos += yyleng; return ELSE;}
then		{currPos += yyleng;	return THEN;}
return		{currPos += yyleng;	return RETURN;}
endif		{currPos += yyleng;	return ENDIF;}
while		{currPos += yyleng;	return WHILE;}
do			{currPos += yyleng;	return DO;}
beginloop	{currPos += yyleng;	return BEGINLOOP;}
endloop		{currPos += yyleng;	return ENDLOOP;}
break		{currPos += yyleng;	return BREAK;}

array		{currPos += yyleng;	return ARRAY;}
of			{currPos += yyleng;	return OF;}

beginparams	{currPos += yyleng;	return BEGIN_PARAMS;}
endparams	{currPos += yyleng;	return END_PARAMS; }

beginlocals	{currPos += yyleng;	return BEGIN_LOCALS; }
endlocals	{currPos += yyleng;	return END_LOCALS; }

beginbody	{currPos += yyleng;	return BEGIN_BODY; }
endbody		{currPos += yyleng;	return END_BODY; }

integer		{currPos += yyleng;	return INTEGER;}

read		{currPos += yyleng; return READ; }
write		{currPos += yyleng;	return WRITE; }

":="		{currPos += yyleng;	return ASSIGN; }

","			{currPos += yyleng;	return COMMA;}

";"			{currPos += yyleng;	return SEMICOLON;}
":"			{currPos += yyleng; return COLON; }

"<="		{currPos += yyleng; return LTE;	}
">="		{currPos += yyleng; return GTE;	}
"<"			{currPos += yyleng; return LT;	}
">"			{currPos += yyleng; return GT;	}

"-"			{currPos += yyleng; return SUB;}
"+"			{currPos += yyleng; return ADD; }
"*"			{currPos += yyleng; return MULT;}
"/"			{currPos += yyleng; return DIV;}
"%"			{currPos += yyleng; return MOD;}
"=="		{currPos += yyleng; return EQ;}
"<>"		{currPos += yyleng; return NEQ;}
"("			{currPos += yyleng; return L_PAREN;}
")"			{currPos += yyleng; return R_PAREN;}

"["			{currPos += yyleng; return L_SQUARE_BRACKET;}
"]"			{currPos += yyleng; return R_SQUARE_BRACKET;}

true		{printf("\n");		currPos += yyleng; return TRUE; }
false		{printf("\n");		currPos += yyleng; return FALSE; }
and			{printf("\n");		currPos += yyleng; return AND; }
or			{printf("\n");		currPos += yyleng; return OR; }
not			{printf("\n");		currPos += yyleng; return NOT;}

##{LINE}	{/* printf("COMMENT(%s)\n", yytext); */ currLine++; currPos += yyleng;}

{DIGIT}+{IDENT}			{printf("Error at line %d, column %d: invalid identifier \"%s\" must begin with a letter\n", currLine, currPos, yytext); currPos += yyleng;}

{LETTER}({ALPHA}*_+)+	{printf("Error at line %d, column %d: invalid identifier \"%s\" cannot end with an underscore\n", currLine, currPos, yytext); currPos += yyleng;}

{DIGIT}*	{ /* printf("NUMBER %s\n", yytext); */ currPos += yyleng; yylval.ival = atoi(yytext); return NUMBER;}

{IDENT}		{ /* printf("IDENT(%s)\n", yytext); */ currPos += yyleng; yylval.ident = strdup(yytext); return IDENT;}

{SPACE}+	{/* ignore spaces */ currPos += yyleng;}

"\n"		{currLine++; currPos = 1;}
"\r"		{ /* stupid char */ }

.			{printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos, yytext); exit(0);}

%%
/*
int main(int argc, char ** argv)
{
   if(argc >= 2)
   {
      yyin = fopen(argv[1], "r");
      if(yyin == NULL)
      {
         yyin = stdin;
      }
   }
   else
   {
      yyin = stdin;
   }
   
   yylex();
 
}
*/