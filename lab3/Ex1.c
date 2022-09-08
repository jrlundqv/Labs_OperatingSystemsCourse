#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;
	int *A;

	printf("Enter size of array: ");
	scanf("%d", &n);

	A = malloc(n*sizeof(int));

	printf("You have created an array of size %d\n", n);
	printf("\nAssign values to your array\n");

	for (i = 0; i < n; i++)
	{
		printf("A[%d] = ", i);
		scanf("%d", &A[i]);
	}

	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("A[%d] value is %d. Memory address is %p\n", i, *(A+i), &A[i]);
	}

	printf("\nAn integer is stored in %ld bytes.\n", sizeof(int));
	printf("We can confirm this by looking at the memory addresses, and seeing they are separated by 4 bytes.\n");

	int min_value = *A;
	for (i = 1; i < n; i++)
	{
		if (*(A+i) < min_value) min_value = *(A+i);
	}

	printf("\nThe minimum value in the array is %d\n", min_value);

	free(A);
	return 0;
}
