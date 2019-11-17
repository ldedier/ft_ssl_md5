#!/bin/sh

source algorithms.sh

files_dir=files
tmp_file=dev_random_1000_chars

cat /dev/random | head -n 1000 > ${files_dir}/${tmp_file}

nb_tests=0
nb_passed=0

function testString()
{
	./diff_script.sh $1 -s $2
	if [ $? == 0 ]
	then
		nb_passed=$((nb_passed + 1))
	fi
}

function testFile()
{
	./diff_script.sh $1 $2
	if [ $? == 0 ]
	then
		nb_passed=$((nb_passed + 1))
	fi
}

for hash in "${algorithms[@]}"
do
	for file in ${files_dir}/*
	do
		testFile $hash $file
		nb_tests=$((nb_tests + 1))
	done
done

echo

green="\033[32m"
red="\033[91m"
eoc="\033[39m"

if [ $nb_passed -eq $nb_tests ]
then
	echo "${green}All ${nb_tests} tests passed !${eoc}"
	exit 0;
else
	echo "${red}only ${nb_passed} / ${nb_tests} passed tests !${ec}"
	exit 1;
fi
