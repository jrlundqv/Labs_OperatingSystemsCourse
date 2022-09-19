#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static const char* message[] =
{
	"Hello mate!",
	"Goodbye friend :)",
	"See you later!",
	"This is a string of text",
	"This is a modification.",
	"The content has been changed."
};

void print_message()
{
	int index;
	srand(time(NULL));
	index = rand()%6;
	printf("Linking multiple c files...\n");
	printf("%s\n", message[index]);
}
