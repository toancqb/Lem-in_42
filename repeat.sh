#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo "Number of repeat"
read n
for i in $(seq 1 $n)
do
	./../generator --big-superposition > tmp.map
	exp="$(tail -n 1 tmp.map | rev | cut -d' ' -f1 | rev)"
	tt=$((time ./lem-in < tmp.map) 2>&1 | tail -n 3 | grep real | rev | cut -f1 | rev)
	obs=$(./lem-in -i < tmp.map | grep 'number of steps' | rev | cut -d' ' -f1 | rev)
	diff=$(echo "$obs - $exp" | bc)
	echo "----------------------"
	echo "Expected: $exp steps."
	echo -n "Observed: $obs steps."
	if [[ $diff -gt 0 ]]
	then
		echo -e "(${RED}+${diff}${NC})"
	elif [[ $diff -eq 0 ]]
	then
		echo "(+0)"
	else
		echo -e "(${GREEN}${diff}${NC})"
	fi
	echo "Time: ${tt}."	
	sleep 1
done
