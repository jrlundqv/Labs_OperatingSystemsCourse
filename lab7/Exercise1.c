#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;
pthread_mutex_t lock;

void* Increase(void* arg)
{
	int i;
	pthread_mutex_lock(&lock);
	for(i = 0; i < 1e8; ++i)
	{
		count++;
	}
	pthread_mutex_unlock(&lock);
	return NULL;
}


void* Decrease(void* arg)
{
	int i;
	pthread_mutex_lock(&lock);
	for(i = 0; i < 1e8; ++i)
	{
		count--;
	}
	pthread_mutex_unlock(&lock);
	return NULL;
}


int main()
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, (void*)Increase, NULL);
	pthread_create(&thread2, NULL, (void*)Decrease, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Count is %d\n", count);

	return 0;
}
