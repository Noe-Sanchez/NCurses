echo Making target...
cmake ./
echo Building target...
old=$(date +%s)
cmake --build ./
now=$(date +%s)
ttime=$((now-old))
echo Building took $ttime seconds.
old=$(date +%s)
echo Runnning target...
./HelloCurses
now=$(date +%s)
ttime=$((now-old))
echo Succesfully executed target after $ttime seconds.
