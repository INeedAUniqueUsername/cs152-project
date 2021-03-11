make parser;
cat fibonacci.min | ./parser > fibonacci.mil
./mil_run fibonacci.mil