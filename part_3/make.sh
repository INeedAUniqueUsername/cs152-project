flex 862012666-862083506.flex;
bison -v -d --file-prefix=y 862012666-862083506.y
gcc -o parser y.tab.c lex.yy.c -lfl