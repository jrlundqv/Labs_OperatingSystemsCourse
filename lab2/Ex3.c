#include <stdio.h>

int main() {
	int n, i, j;

	printf("Please enter n: ");
	scanf("%d", &n);
	printf("n = %d\n", n);

	int A[n], B[n];

	for (i = 1; i <= n; i++) { // Løkke som styrer antall linjer/arrays
		printf("\n");

		for (j = 0; j < i; j++) { // Løkke som styrer antall elementer i hver array

			if (j == 0) A[j] = 1; // Sørger for at første indeks alltid er 1
			else {

				if (j == i-1) A[j] = 1; // Sørger for at siste indeks alltid er 1
				else A[j] = B[j-1] + B[j]; // Hovedlogikken bak tallrekken
			}
		}

		for (j = 0; j < i; j++) B[j] = A[j]; /* Løkke som kopierer nåværende array slik at den
												kan brukes til å kalkulere og skrive neste array */

		for (j = 0; j < i; j++) printf("%5d", A[j]); // Printer hvert array på en linje 
	}

	printf("\n");
	return 0;
}
