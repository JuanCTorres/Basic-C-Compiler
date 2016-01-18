#!/bin/bash
# Script name: testscript.sh
# Made by SeokJun Bing, Charles Li, Juan Torres  on 01/13/16
#
#
# Input: none
# Output: a logfiled named "testoutput.`date +"%a_%b_%d_%T_%Y"`"

rm -rf test.output.*
make clean
make

file="test.output.`date +"%a_%b_%d_%T_%Y"`"
printf "This log will record various tests done to lexer.\n\n" >> "${file}"

printf "test_1.input BEGIN:\n" >> "${file}"
printf "===========================================================\n\n" >> "${file}"

cat ./test_1.input | ./cscan >> "${file}"

printf "\n\n===========================================================\n" >> "${file}"

printf "test_c.input BEGIN:\n" >> "${file}"
printf "===========================================================\n" >> "${file}"

cat ./test_c.input | ./cscan >> "${file}"

printf "\n\n===========================================================\n" >> "${file}"
printf "TEST FINISHED\n\n\n" >> "${file}"

