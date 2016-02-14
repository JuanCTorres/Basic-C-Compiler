#!/bin/bash
# Script name: testscript.sh
# Made by SeokJun Bing, Juan Torres  on 01/21/16
#
#
# Input: none
# Output: 3 log files named by {filename}.output.`date +"%a_%b_%d_%T_%Y"`

rm -f ./testoutputs/*
make clean
make

file="./testoutputs/test1.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test1.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser < ./testinputs/test1.c >> "${file}" 2>&1

printf "\n\n===========================================================\n" >> "${file}"
printf "test1.c finished.\n" >> "${file}"


file="./testoutputs/test2.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test2.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser < ./testinputs/test2.c >> "${file}" 2>&1

printf "\n\n===========================================================\n" >> "${file}"
printf "test2.c finished.\n" >> "${file}"


file="./testoutputs/test3.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test3.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser < ./testinputs/test3.c >> "${file}" 2>&1

printf "\n\n===========================================================\n" >> "${file}"
printf "test3.c finished.\n" >> "${file}"



file="./testoutputs/test4.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test4.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser < ./testinputs/test4.c >> "${file}" 2>&1

printf "\n\n===========================================================\n" >> "${file}"
printf "test4.c finished.\n" >> "${file}"





file="./testoutputs/test5.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test5.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser < ./testinputs/test5.c >> "${file}" 2>&1

printf "\n\n===========================================================\n" >> "${file}"
printf "test5.c finished.\n" >> "${file}"




file="./testoutputs/test6.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test6.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser < ./testinputs/test6.c >> "${file}" 2>&1

printf "\n\n===========================================================\n" >> "${file}"
printf "test6.c finished.\n" >> "${file}"




file="./testoutputs/test7.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test7.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser < ./testinputs/test7.c >> "${file}" 2>&1

printf "\n\n===========================================================\n" >> "${file}"
printf "test7.c finished.\n" >> "${file}"






file="./testoutputs/test8.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test8.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser < ./testinputs/test8.c >> "${file}" 2>&1

printf "\n\n===========================================================\n" >> "${file}"
printf "test8.c finished.\n" >> "${file}"





file="./testoutputs/test.error.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >>"${file}"

printf "test.error.c BEGIN.\n" >>"${file}"
printf "===========================================================\n\n" >> "${file}"

./parser < ./testinputs/test.error.c >>"${file}" 2>&1

printf "\n\n===========================================================\n" >> "${file}"
printf "test.error.c finished.\n" >>"${file}"






make clean
