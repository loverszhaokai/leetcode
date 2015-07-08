#!/bin/bash

if [ $# != 1 ]
then
	echo "usage: ./run.sh /path/to/src"
	exit 1
fi

g++ $1 --std=c++11 && ./a.out 
