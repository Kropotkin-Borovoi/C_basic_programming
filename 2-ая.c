#include <stdio.h>
#include <math.h>

float check_prime_number (int j) {
	int i, in_int, counter = 0;
	float in_float;
	for (i = 2; i < j; i++) {
		in_float = (float)j / i;
		in_int = j / i;
		if (in_int == in_float) {
			counter++;
		}
	}
	return counter;
}

int main() {
	int Number, j;
	printf ("This program displays all the prime numbers up to the one\
 specified by the user \nPut a number:\n");
	scanf ("%d", &Number);
	printf ("\n");
	for (j = 2; j <= Number; j++) {
		if (chech_prime_number(j) == 0) {
			printf ("%d\n", j);
		}
	}
	return 0;
}

