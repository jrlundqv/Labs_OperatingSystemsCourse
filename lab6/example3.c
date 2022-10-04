#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *PrintMessage(void)
{
	printf("Message from Thread1 \n");
}

int main(int argc, char *argv[])
{
	pthread_t Thread1;
	int ret;

	ret = pthread_create(&Thread1, NULL, (void*)PrintMessage, NULL);
	if (ret != 0)
	{
		printf("Thread1 creation encountered an error\n");
		exit(1);
	}
	pthread_join(Thread1, NULL);

	printf("I am the main Thread\n");

	return 0;
}
