#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int **C;

void* MatrixProduct(int **M1, int **M2, int M1_rows, int M1_cols, int M2_rows, int M2_cols)
{
	if (M1_cols != M2_rows)
	{
		printf("Multiplication of matrices with dimensions %dx%d and %dx%d is not possible, exiting...\n", M1_rows, M1_cols, M2_rows, M2_cols);
		exit(-1);
	}
	else
	{
		for (int i = 0; i < M1_rows; i++)
		{
			for (int j = 0; j < M2_cols; j++)
			{
			int cell_sum = 0;
				for (int k = 0; k < M1_cols; k++)
				{
					int product = M1[i][k] * M2[k][j];
					cell_sum = cell_sum + product;
				}
			C[i][j] = cell_sum;
			}
		}
	}
}


int main()
{
	FILE* matrix_A = fopen("A.txt", "r");
	FILE* matrix_B = fopen("B.txt", "r");
	int n_A, n_B, **A, **B, i, ret;
	fscanf(matrix_A, "%d", &n_A);
	fscanf(matrix_B, "%d", &n_B);

	A = malloc(n_A * sizeof(int *));

	for (i = 0; i < n_A; i++)
	{
		A[i] = malloc(n_A * sizeof(int));
	}

	for (i = 0; i < n_A; i++)
	{
		for (int j = 0; j < n_A; j++)
		{
			fscanf(matrix_A, "%d", &A[i][j]);
		}
	}

	B = malloc(n_B * sizeof(int *));

	for (i = 0; i < n_B; i++)
	{
		B[i] = malloc(n_B * sizeof(int));
	}

	for (i = 0; i < n_B; i++)
	{
		for (int j = 0; j < n_B; j++)
		{
			fscanf(matrix_B, "%d", &B[i][j]);
		}
	}

	C = malloc(n_A * sizeof(int *));

	for (i = 0; i < n_A; i++)
	{
		C[i] = malloc(n_B * sizeof(int));
	}

/*	pthread_t Thread1, Thread2, Thread3, Thread4;

	ret = pthread_create(&Thread1, NULL, MatrixProduct(A, B, n_A, n_A, n_B, n_B), NULL);
	if (ret)
	{
		printf("Error creating thread. Error code: %d\n", ret);
		exit(-1);
	}

	pthread_join(Thread1, NULL);
*/
	MatrixProduct(A, B, n_A, n_A, n_B, n_B);

	FILE *fp;

	fp = fopen("D.txt", "w");

	for (i = 0; i < n_A; i++)
	{
		for (int j = 0; j < n_A; j++)
		{
			fprintf(fp, "%d ", C[i][j]);
		}
		fprintf(fp, "\n");
	}

	free(A);
	free(B);
	return 0;
}
