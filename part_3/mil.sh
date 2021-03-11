file=$1
make clean;
make parser;
rm $file".mil";

cat $file".min";

cat $file".min" | ./parser > $file".mil";

cat $file".mil";

./mil_run $file".mil";