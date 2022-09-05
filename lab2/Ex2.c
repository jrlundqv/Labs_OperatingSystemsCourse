#include <stdio.h>

int fib_func(int x, int y) {
	return x + y;
}

int main() {
	int a = 0; // a = F(n-2)
	int b = 1; // b = F(n-1)
	int c, i; // c = F(n) = F(n-1) + F(n-2)
	int fib_sum = 0;

	int fib_array[20];

	fib_array[0] = a;
	fib_array[1] = b;

	for (i = 2; i < 20; i++) {
		c = fib_func(a,b);
		fib_array[i] = c;
		a = b;
		b = c;
	}

	for (i = 0; i < 20; i++) fib_sum += fib_array[i];

	printf("Summen av de 20 første tallene i Fibonacci sekvensen er: %d\n", fib_sum);

	return 0;
}
