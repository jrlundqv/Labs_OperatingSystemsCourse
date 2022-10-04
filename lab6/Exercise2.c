#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int balance = 1000;

void* Deposit(int arg)
{
	balance = balance + arg;
}

void* Withdraw(int arg)
{
	balance = balance - arg;
}

int main()
{
	printf("Your balance is: %d\n", balance);

	int deposit;
	printf("Enter deposit amount: ");
	scanf("%d", &deposit);

	pthread_t depositThread;
	int ret;

	ret = pthread_create(&depositThread, NULL, Deposit(deposit), NULL);
	if (ret)
	{
		printf("Error creating thread. Error code: %d", ret);
		exit(-1);
	}

	printf("Your balance is now: %d\n", balance);
}
