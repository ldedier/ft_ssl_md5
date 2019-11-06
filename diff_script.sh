#!/bin/bash

if [ -z $1 ] || [ -z $2 ];
then
	echo "usage: $0 hash {-s string, filename }"
	exit 1
fi

ft_ssl="ft_ssl"
openssl="openssl"
green="\033[32m"
red="\033[91m"
eoc="\033[39m"

if [ "${2}" = "-s" ];
then
	if [ -z $3 ];
	then
		echo "usage: $0 hash {-s string, filename }"
		exit 1
	fi
	diff <(./${ft_ssl} $1 -q -s $3 2>/dev/null) <(echo -n "$3" | ${openssl} $1 2>/dev/null)

	if [ $? -ne 0 ];
	then
		echo -e "${red}diff for string ${3} (hash $1)${eoc}"
	else
		echo -e "${green}no diff for string ${3} (hash $1)${eoc}"
	fi
	exit 0;
fi

diff <(./${ft_ssl} $1 $2 2>/dev/null) <(${openssl} $1 $2 2>/dev/null)

if [ $? -ne 0 ];
then
	echo -e "${red}diff for file ${2} (hash $1)${eoc}"
else
	echo -e "${green}no diff for file ${2} (hash $1)${eoc}"
fi
