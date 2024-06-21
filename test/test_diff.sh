#! /bin/bash

#chmod +x test_diff.sh

program=main
csv_sample=users_regular_valid.csv
csv_test=my.csv


# exec
./$program > $csv_test

# compare
if cmp -s "$csv_sample" "$csv_test"; then
    result="Passed."
else
    result="Failed!"
fi
echo "[1] Read, Store and Write: $result"
echo ""

# diff
if [ $result=="Failed!" ]; then
	
	echo -n "Run diff? [y/N] "
	read -s -n 1 y
	echo ""

	if [ $y == "y" ]; then
		#echo ""
		diff "$csv_sample" "$csv_test"
	fi

fi
