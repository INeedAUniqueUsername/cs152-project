make

cat primes.min | ./lexer > primes.out
diff primes.txt primes.out

cat fibonacci.min | ./lexer > fibonacci.out
diff fibonacci.txt fibonacci.out

cat mytest.min | ./lexer > mytest.out
diff mytest.txt mytest.out