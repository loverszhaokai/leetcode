#!/bin/bash

if [ $# == 0 ]
then
	echo "usage: ./run.sh /path/to/src [-g]"
	exit 1
fi

if [ $# == 1 ]
then
	g++ $1 --std=c++11 -I ../ -L ../ -lutils && ./a.out
	exit 1
fi

if [ $# == 2 ]
then
	g++ $1 -g --std=c++11 -I ../ -L ../ -lutils && ./a.out
	exit 1
fi
