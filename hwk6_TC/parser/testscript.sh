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

./parser test1.c < ./testinputs/test1.c >> "${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/test1.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "test1.c finished.\n" >> "${file}"


file="./testoutputs/test2.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test2.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser test2.c < ./testinputs/test2.c >> "${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/test2.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "test2.c finished.\n" >> "${file}"


file="./testoutputs/test3.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test3.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser test3.c < ./testinputs/test3.c >> "${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/test3.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "test3.c finished.\n" >> "${file}"



file="./testoutputs/test4.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test4.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser test4.c < ./testinputs/test4.c >> "${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/test4.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "test4.c finished.\n" >> "${file}"





file="./testoutputs/test5.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test5.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser test5.c < ./testinputs/test5.c >> "${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/test5.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "test5.c finished.\n" >> "${file}"




file="./testoutputs/test6.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test6.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser test6.c < ./testinputs/test6.c >> "${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/test6.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "test6.c finished.\n" >> "${file}"




file="./testoutputs/test7.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test7.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser test7.c < ./testinputs/test7.c >> "${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/test7.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "test7.c finished.\n" >> "${file}"






file="./testoutputs/test8.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >> "${file}"

printf "test8.c BEGIN.\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

./parser test8.c < ./testinputs/test8.c >> "${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/test8.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "test8.c finished.\n" >> "${file}"



file="./testoutputs/test9.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >>"${file}"

printf "test9.c BEGIN.\n" >>"${file}"
printf "===========================================================\n\n" >> "${file}"

./parser test9.c < ./testinputs/test9.c >>"${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/test9.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "test9.c finished.\n" >>"${file}"




file="./testoutputs/test10.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >>"${file}"

printf "test10.c BEGIN.\n" >>"${file}"
printf "===========================================================\n\n" >> "${file}"

./parser test10.c < ./testinputs/test10.c >>"${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/test10.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "test10.c finished.\n" >>"${file}"



file="./testoutputs/recursive_factorial.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >>"${file}"

printf "recursive_factorial.c BEGIN.\n" >>"${file}"
printf "===========================================================\n\n" >> "${file}"

./parser recursive_factorial.c < ./testinputs/recursive_factorial.c >>"${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/recursive_factorial.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "recursive_factorial.c finished.\n" >>"${file}"


file="./testoutputs/fibb.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >>"${file}"

printf "fibb.c BEGIN.\n" >>"${file}"
printf "===========================================================\n\n" >> "${file}"

./parser fibb.c < ./testinputs/fibb.c >>"${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/fibb.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "fibb.c finished.\n" >>"${file}"




file="./testoutputs/helloworld.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >>"${file}"

printf "helloworld.c BEGIN.\n" >>"${file}"
printf "===========================================================\n\n" >> "${file}"

./parser helloworld.c < ./testinputs/helloworld.c >>"${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/helloworld.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "helloworld.c finished.\n" >>"${file}"


file="./testoutputs/scoping.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >>"${file}"

printf "scoping.c BEGIN.\n" >>"${file}"
printf "===========================================================\n\n" >> "${file}"

./parser scoping.c < ./testinputs/scoping.c >>"${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/scoping.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "scoping.c finished.\n" >>"${file}"




file="./testoutputs/test.error.c.output.`date +"%a_%b_%d_%T_%Y"`"
printf "Result of test done to parser.\n\n" >>"${file}"

printf "test.error.c BEGIN.\n" >>"${file}"
printf "===========================================================\n\n" >> "${file}"

./parser test.error.c < ./testinputs/test.error.c >>"${file}" 2>&1

if [ $? -eq 0 ] 
then
  yas ./ys/test.error.c.ys
fi

printf "\n\n===========================================================\n" >> "${file}"
printf "test.error.c finished.\n" >>"${file}"






make clean
