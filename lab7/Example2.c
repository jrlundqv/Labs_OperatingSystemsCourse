#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int signal = 0;
pthread_cond_t generic_condition;
pthread_mutex_t lock;

void* Thread1PrintMessage(void* arg)
{
	pthread_mutex_lock(&lock);

	printf("Welcome to ");

	pthread_cond_signal(&generic_condition);
	signal = 1;
	pthread_mutex_unlock(&lock);
	return NULL;
}


void* Thread2PrintMessage(void* arg)
{
	pthread_mutex_lock(&lock);
	while (signal == 0)
	{
		pthread_cond_wait(&generic_condition, &lock);
	}
	printf("Østfold University College\n");
	pthread_mutex_unlock(&lock);
	return NULL;
}


int main(int argc, char** argv)
{
	int err = 0;
	pthread_t t1;
	pthread_t t2;

	err = pthread_mutex_init(&lock, NULL);
	if (err) perror("pthread_mutex_init encountered an error");

	err = pthread_cond_init(&generic_condition, NULL);
	if (err) perror("pthread_cond_init encountered an error");

	err = pthread_create(&t1, NULL, Thread1PrintMessage, NULL);
	if (err)
	{
		perror("pthread_create encountered an error");
		exit(-1);
	}
	err = pthread_create(&t2, NULL, Thread2PrintMessage, NULL);
	if (err)
	{
		perror("pthread_create encountered an error");
		exit(-1);
	}

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	err = pthread_mutex_destroy(&lock);
	if (err) perror("pthread_mutex_destroy encountered an error");

	err = pthread_cond_destroy(&generic_condition);
	if (err) perror("pthread_cond_destroy encountered an error");

	return 0;
}
