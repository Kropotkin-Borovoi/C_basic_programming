#include <stdio.h>
#include <math.h>

float Func (float x){
	return 1 / logl(x);
}

float count_dx (int a, int b, int step) {
	return (b - a) / step;	
}

float first_integral (int a, int b) {
	return (Func(a) + Func(b)) / 2;
}

float full_integral (int step, int a, int b) {
	float integral = first_integral(a, b);
	for (int i = 1; i < step; i++) {
		a += count_dx(a, b, step);
		integral += Func(a);
	}
	return integral;
}

float character_definition (int a, int b, float result) {
	if (b < a) {
		result *= (-1);
	}
}

int main()
{
	printf ("This program calculates the integral of the function F(x)\
 by trapezoidal method\nEnter the lower integration limit, the\
 upper integration limit, the number of partitions\n");
	int step;
	float a, b, result;
	
	scanf ("%f %f %d", &a, &b, &step);
	
	result = count_dx(a, b, step) * full_integral(step, a, b);
	
	printf ("%f\n", character_definition(a, b, result));
	
	return 0;
}
