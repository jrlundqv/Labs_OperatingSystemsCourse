#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int status = 0;
	pid_t pid;
	pid = fork();

	if (pid == 0)
	{
		sleep(2);
		printf("\n\nChild: Hey! I'm ready to do stuff");
		fflush(stdout);
		sleep(2);
		printf("\n\nChild: Doing stuff");
		for (int i = 0; i < 8; i++)
		{
			printf(".");
			fflush(stdout);
			sleep(1);
		}
		printf(" FINISHED");
		fflush(stdout);
		sleep(2);
		printf("\n\n");
		return 2147483690;
	}
	else if (pid > 0)
	{
		printf("Parent: Waiting for child to finish doing stuff...");
		fflush(stdout);
		wait(&status);
		printf("Parent: The child is done, status is: %d", WEXITSTATUS(status));
		fflush(stdout);
		sleep(2);
		printf("\n");
		return 0;
	}
	else
	{
		perror("fork");
		exit(-1);
	}

	sleep(2);
	return 0;
}
