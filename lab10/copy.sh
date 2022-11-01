#!/bin/bash

source_file=$1
dest_file=$2

if [ $# = 2 ]; then
	if [ -e $source_file ]; then
		cp $source_file $dest_file
		wc -l $source_file | awk '{ print $1 }'
	else
		echo "Source file does not exist"
	fi
else
	echo "Please provide the two input parameters source_file and dest_file"
fi
