#!/bin/bash

make -C ..

source diff_script_function.sh

files_dir=files
tmp_file=dev_random_1000_chars

cat /dev/random | head -n 1000 > ${files_dir}/${tmp_file}

nb_tests=0
nb_passed=0

function testString()
{
	diff_script $1 -s ${2}
	if [ $? == 0 ]
	then
		nb_passed=$((nb_passed + 1))
	fi
}

strings=(\
 "hello_world" \
 "123456789" \
 "abcdefghijklmnopqrstuvwxyz" \
 "🐙🐙" \
 "💯" \
 "🦀🦀🦀" \
 "⛄️" \
 "☀️ ☀️ " \
 "🥨🧀" \
 "¨˙∑ˆ¨ƒ˙ˆ¨´∑˜ƒ´ƒ" \
 "πøπøπøπ∑´ƒπø´∑ƒµµ" \
 "åœ®´∑\©ƒççç√∂®©®´©®´ø∑ƒ∆´ˆ" \
 "¨˙ˆ∑œ∂˜∑…ˆø∆∂ø∑´ˆª•ª¶ª•º™ª∞•º£ª•ª•§ºª£¢•§º" \
 "øƒƒøç˚ç˚ç∑˜√´∆∑ƒ´¨•¨´•∑¨´•ª∞∞∞∞∞∞∞" \
 "ª∑\•£˙®ƒ˜∆ˆ˜√∆˜ˆø∆†ºª\ºº–ˆ£¢∆©∆®©˜∆ ∆®˜øˆ∆π∆∑π∆π∆´ºª¨º∆©ˆ®ø˜©" \
 "¨˙∑ˆ¨ƒ˙ˆ¨´∑˜ƒ´ƒ" \
 "∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂∂øøøøøøøøøøøƒƒƒƒƒ˚˚˚˚˚˚˚˚√√√√√√√" \
)

function testFile()
{
	diff_script $1 $2
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
	for string in "${strings[@]}"
	do
		testString $hash $string
		nb_tests=$((nb_tests + 1))
	done
done

echo

green="\033[32m"
red="\033[91m"
eoc="\033[39m"

if [ $nb_passed -eq $nb_tests ]
then
	echo -e "${green}All ${nb_tests} tests passed !${eoc}"
	exit 0;
else
	echo -e "${red}only ${nb_passed} / ${nb_tests} passed tests !${eoc}"
	exit 1;
fi
