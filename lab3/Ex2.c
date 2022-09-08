#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M, **A, i, max_value = 0;
	FILE *data = fopen("Input.dat", "r");

	fscanf(data, "%d%d", &N, &M);

	A = malloc(N * sizeof(long));

	for (i = 0; i < N; i++)
	{
		A[i] = malloc(M * sizeof(int));
	}

	for (i = 0; i < N; i++)
	{
		printf("\n\n");

		for (int j = 0; j < M; j++)
		{
			fscanf(data, "%d", &A[i][j]);
			printf("[%d]", A[i][j]);
			if (A[i][j] > max_value) max_value = A[i][j];
		}
	}

	printf("\n\nThe maximum value of the array is %d\n", max_value);

	free(A);
	return 0;
}
