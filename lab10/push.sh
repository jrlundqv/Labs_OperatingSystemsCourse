#!/bin/bash

echo "This script will add, commit and push a file to github"
echo "You can choose an already existing file, or you can create a new one"
echo

function push
{
	git add $file
	git commit -m "Exercise 1"
	git push
}

#while !file_chosen || !file_created
	echo "Enter filename to push"

	read file

	if [ ! $file = $(ls | grep -x $file) ]; then
		echo "You are creating a new file called $file"
		echo "continue? [y/n]"
		read input
#		while input != y || n
			if [ $input = "y" ]; then
				touch $file
				echo "PUSH"
			elif [ $input = "n" ]; then
				echo "Cancelling operation..."
#				break
			fi
	fi

#	elif file exists; then
#		echo "You have chosen *$file*"
#		echo "confirm selection? [y/n]"
#		read input
#		while input != y || n
#			if input == "y"; then
#				echo "PUSH"
#			elif input == "n"; then
#				echo "Cancelling operation..."
