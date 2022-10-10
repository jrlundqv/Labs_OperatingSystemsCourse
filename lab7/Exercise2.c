#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int signal;
pthread_cond_t cond;
pthread_mutex_t lock;


void* print_Halden(void* arg)
{
	for (int i = 0; i < 5; i++)
	{
		pthread_mutex_lock(&lock);
		while (signal == 0) pthread_cond_wait(&cond, &lock);
		printf("Halden\n");
		pthread_cond_signal(&cond);
		signal = 0;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}


void* print_Fredrikstad(void* arg)
{
	for (int i = 0; i < 5; i++)
	{
		pthread_mutex_lock(&lock);
		while (signal == 1) pthread_cond_wait(&cond, &lock);
		printf("Fredrikstad\n");
		pthread_cond_signal(&cond);
		signal = 1;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}


int main(int argc, char** argv)
{
	signal = 0;

	pthread_t t1, t2;

	pthread_mutex_init(&lock, NULL);

	pthread_cond_init(&cond, NULL);

	pthread_create(&t1, NULL, print_Halden, NULL);
	pthread_create(&t2, NULL, print_Fredrikstad, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("Østfold University College!\n");

	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&cond);

	return 0;
}
