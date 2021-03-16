y.tab.c: 862012666-862083506.y
	bison -v -d --file-prefix=y 862012666-862083506.y

lex.yy.c: 862012666-862083506.flex
	flex 862012666-862083506.flex;
	g++ -o lexer lex.yy.c -lfl;
	
my_compiler: 862012666-862083506.y
	bison -v -d --file-prefix=y 862012666-862083506.y
	flex 862012666-862083506.flex;
	g++ -o my_compiler y.tab.c lex.yy.c -lfl
	
clean:
	rm my_compiler;
	rm y.tab.c;
	rm y.tab.h;
	rm lex.yy.c;