#!/bin/bash
# Script name: testscript.sh
# Made by SeokJun Bing, Juan Torres  on 01/21/16
#
#
# Input: none
# Output:

# Clean output and previously compiled files
rm -rf ./testoutputs/*
rm -rf ys/*
make clean
make


fileArray=($(ls ./testinputs/ | xargs -n 1 basename))
tLen=${#fileArray[@]}
compiler="bcc"

for (( i=0; i<${tLen}; i++ ));
do

	file="./testoutputs/${fileArray[$i]}.output.`date +"%a_%b_%d_%T_%Y"`"
	printf "Result of test done to parser.\n\n" >> "${file}"

	printf "${fileArray[$i]} BEGIN.\n" >> "${file}"
	printf "===========================================================\n\n" >> "${file}"

	echo ${fileArray[$i]}
	./$compiler ${fileArray[$i]} < ./testinputs/${fileArray[$i]} >> "${file}" 2>&1

	if [ $? -eq 0 ];
	then
	  yas ./ys/${fileArray[$i]}.ys
	 else
	 	printf "\t${fileArray[$i]} generated an error\n"
	fi

	printf "\n\n===========================================================\n" >> "${file}"
	printf "${fileArray[$i]} finished.\n" >> "${file}"



done


make clean
