#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* PrintMessage1(void* arg)
{
	printf("Hello from Thread1\n");
	return 0;
}

void* PrintMessage2(void* arg)
{
	printf("Hello from Thread2\n");
	return 0;
}

int main()
{
	pthread_t Thread1, Thread2;
	int ret;

	ret = pthread_create(&Thread1, NULL, PrintMessage1, NULL);
	if (ret) {printf("Thread1 creation error\n"); exit(1);}

	ret = pthread_create(&Thread2, NULL, PrintMessage2, NULL);
	if (ret) {printf("Thread2 creation error\n"); exit(2);}

	printf("Hello from main\n");

	return 0;
}
