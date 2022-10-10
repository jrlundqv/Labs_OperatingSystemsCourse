#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

pthread_mutex_t mutex;

int count;

void* Increase(void* arg)
{
	int i;
	int temp;
	for (i = 0; i < 100; i++)
	{
		pthread_mutex_lock(&mutex);
		temp = count + 10;
		usleep(1);
		count = temp;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

void* Decrease(void* arg)
{
	int i;
	int temp;
	for (i = 0; i < 100; i++)
	{
		pthread_mutex_lock(&mutex);
		temp = count - 10;
		usleep(2);
		count = temp;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t t1;
	pthread_t t2;

	count = 0;

	pthread_mutex_init(&mutex, NULL);

	pthread_create(&t1, NULL, Increase, NULL);
	pthread_create(&t2, NULL, Decrease, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("global variable count is: %d\n", count);
	pthread_mutex_destroy(&mutex);
	return 0;
}
