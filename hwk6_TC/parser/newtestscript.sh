#!/bin/bash
# Script name: testscript.sh
# Made by SeokJun Bing, Juan Torres  on 01/21/16
#
#
# Input: none
# Output: 

rm -f ./testoutputs/*
make clean
make

fileArray=($(ls ./testinputs/ | xargs -n 1 basename))
tLen=${#fileArray[@]}


for (( i=0; i<${tLen}; i++ ));
do
  	echo "${fileArray[$i]}"

	file="./testoutputs/${fileArray[$i]}.output.`date +"%a_%b_%d_%T_%Y"`"
	printf "Result of test done to parser.\n\n" >> "${file}"

	printf "${fileArray[$i]}.c BEGIN.\n" >> "${file}"
	printf "===========================================================\n\n" >> "${file}"

	./parser ${fileArray[$i]} < ./testinputs/${fileArray[$i]} >> "${file}" 2>&1

	if [ $? -eq 0 ] 
	then
	  yas ./ys/${fileArray[$i]}.ys
	fi

	printf "\n\n===========================================================\n" >> "${file}"
	printf "${fileArray[$i]} finished.\n" >> "${file}"



done