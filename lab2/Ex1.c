#include <stdio.h>

int main() {

	int n, n_power_of_two, sum = 0;

	for (n = 0; n <= 100; n++) {
		n_power_of_two = 0;
		n_power_of_two = n * n;
		sum += n_power_of_two;
	}

	printf("Summen av n² ved n = 0 til 100 er %d\n", sum);

	return 0;
}
