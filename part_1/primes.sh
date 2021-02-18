make
cat primes.min | ./lexer > primes.out
diff primes.txt primes.out
#cat primes.sh | sh