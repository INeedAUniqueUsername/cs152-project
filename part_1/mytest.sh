make
cat mytest.min | ./lexer > mytest.out
diff mytest.txt mytest.out
#cat mytest.sh | sh