y.tab.c: 862012666-862083506.y
	bison -v -d --file-prefix=y 862012666-862083506.y

lex.yy.c: 862012666-862083506.flex
	flex 862012666-862083506.flex;
	g++ -o lexer lex.yy.c -lfl;
	
parser: 862012666-862083506.y
	bison -v -d --file-prefix=y 862012666-862083506.y
	flex 862012666-862083506.flex;
	g++ -o parser y.tab.cc lex.yy.c -lfl