make
cat fibonacci.min | ./lexer > fibonacci.out
diff fibonacci.txt fibonacci.out
#cat fibonacci.sh | sh