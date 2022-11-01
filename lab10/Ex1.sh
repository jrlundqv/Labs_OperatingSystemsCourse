#!/bin/bash

echo "Enter name of file to push"

read file

touch $file

git add $file
git commit -m "Exercise 1"
git push


