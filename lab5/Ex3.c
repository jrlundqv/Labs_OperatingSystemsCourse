#include <stdio.h>
#include <unistd.h>

int main()
{
	execl("/bin/ps", "ps", "-U", "root", "-u", "root", "u", NULL);
//	execl("/bin/ls", "ls", NULL);
//	execl("/bin/pwd", "pwd", NULL);
//	execl("/bin/cat", "cat", NULL);
//	execl("/bin/ps", "ps", NULL);
//	execl("/bin/ps", "ps", "-l", NULL);
	printf("This will only be printed if the execl call fails");
}

