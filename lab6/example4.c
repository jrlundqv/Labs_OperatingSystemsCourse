#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *Increase(void *a_void_ptr)
{
	int *a_ptr = (int *) a_void_ptr;

	for (int i = 0; i < 100; i++)
	{
		*a_ptr += 1;
	}
	printf("Increasing a finished thanks to the second thread\n");
}

int main()
{
	int a = 0;

	printf("Initial values: a = %d\n", a);

	pthread_t increaseThread;

	int ret;
	ret = pthread_create(&increaseThread, NULL, (void*)Increase, &a);
	if (ret)
	{
		printf("ERROR in creating thread. ERROR code %d\n", ret);
		exit(-1);
	}
	pthread_join(increaseThread, NULL);
	printf("Final values: a = %d\n", a);
	return 0;
}
