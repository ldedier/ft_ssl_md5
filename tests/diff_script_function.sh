#!/bin/sh

source algorithms.sh

function trim_output()
{
	return "$1 2>/dev/null | sed s/\ //g";
}

function compare_output_string()
{
	if [ -z $3 ];
	then
		diff <($1 2>/dev/null | sed s/\ //g) <($2 2>/dev/null | sed s/\ //g) >/dev/null
		ret=$?
	else
		diff <(echo -n $3 | $1 2>/dev/null | sed s/\ //g) <(echo -n $3 | $2 2>/dev/null | sed s/\ //g) >/dev/null
		ret=$?
	fi
	return $ret;
}

function diff_script()
{
	#echo $1 $2 $3

	if [ -z $1 ] || [ -z $2 ];
	then
		echo "usage: $0 hash {-s string, filename }"
		return 1
	fi

	if [[ ! " ${algorithms[@]} " =~ " $1 " ]]; then
		echo "$1: not a valid hash algorithm name"
			return 1;
	fi

	ft_ssl="../ft_ssl"
	openssl="openssl"

	green="\033[32m"
	red="\033[91m"
	eoc="\033[39m"


	##	diff <(./${ft_ssl} $1 -q -s $3 2>/dev/null) <(echo -n "$3" | ${openssl} $1 2>/dev/null)

	if [ $2 = "-s" ];
	then
		if [ -z "$3" ];
		then
			3=""
			echo "usage: $0 hash {-s string, filename }"
			return 2;
		fi
		compare_output_string "./${ft_ssl} $1 -q -s $3" "${openssl} $1" $3
		if [ $? -ne 0 ];
		then
			echo -e "${red}diff for string ${3} (hash $1)${eoc}"
			return 1;
		else
			echo -e "${green}no diff for string ${3} (hash $1)${eoc}"
				return 0;
		fi
	fi
	compare_output_string "./${ft_ssl} $1 $2" "${openssl} $1 $2"
	if [ $? -ne 0 ];
	then
		echo -e "${red}diff for file ${2} (hash $1)${eoc}"
		return 1;
	else
		echo -e "${green}no diff for file ${2} (hash $1)${eoc}"
		return 0;
	fi
}
