#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]){
	char *buffer; // pointer to the buffer

	buffer = malloc(1<<31); // allocate a new buffer
	printf("Please enter your name:\n");
	fgets(buffer, 1024, stdin); // get upto 1024 characters from STDIN
	printf("You fixed the bug! Congratulations %s\n", buffer); // print the buffer to STDOUT

	return 0;
}