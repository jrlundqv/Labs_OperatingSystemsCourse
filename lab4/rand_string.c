/**
 * This file contains a broken program to be debugged with GDB.
 * This program reads a line from stdin, generates random numbers
 *			  that is then used to pull characters from random
 *			  parts of the read string
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "message.h"
#include <time.h>

int main(int arg, char** argv)
{
	char* string = NULL;
	int i, n;
	int length = 10;
	size_t j = 0;

        srand(time(NULL));

	printf("Enter a line: ");
	n = getline(&string, &j, stdin);
	printf("You entered the %d character line: %s", n-1, string);

	int rand_array[n];

	for(i = 0; i < n; i++)
	{
		rand_array[i] = rand() % (n-1);
	}

	printf("The randomized string is \n");

	for(i = 0; i < n-1; i++)
	{
		putchar(string[rand_array[i]]);
	}

	printf("\n");

	return 0;
}
