#include <stdio.h>
#include <math.h>

float Func (float x){
	return x;
}

float dFunc (float x){
	float h=0.000001;
	return (Func(x + h) - Func(x - h)) / (2 * h);
}

float count_sum (float x) {
	return x - (Func(x) / dFunc(x));
}

float solving_the_equation (float x, int accuracy) {
	float accuracy_limit = 10, S1, S2;
	do {
		S1 = count_sum(x);
		S2 = count_sum(S1);
		x = S2;
	}
	while ((Func(S1) / dFunc(S1)) > pow(accuracy_limit, -accuracy));
	return S1 + S2;
}

int main()
{
	printf ("This program solves an equation of the form F(x) = 0 by\
 Newton's method\nEnter the initial approximation and the required\
 accuracy of the calculation\n");
	
	int accuracy=0;
	float accuracy_limit = 10, x;
	
	// scanf ("%f %d", &x, &accuracy);
	{
		x = 0.5;
		accuracy = 10;
		printf ("%f\n", round(solving_the_equation(x, accuracy) / 2 /\
				pow(accuracy_limit, -accuracy)) * pow(accuracy_limit, -accuracy));
	}
	{
		x = 1.5;
		accuracy = 10;
		printf ("%f\n", round(solving_the_equation(x, accuracy) / 2 /\
				pow(accuracy_limit, -accuracy)) * pow(accuracy_limit, -accuracy));
	}
	{
		x = 3.5;
		accuracy = 10;
		printf ("%f\n", round(solving_the_equation(x, accuracy) / 2 /\
				pow(accuracy_limit, -accuracy)) * pow(accuracy_limit, -accuracy));
	}
	{
		x = 5.5;
		accuracy = 10;
		printf ("%f\n", round(solving_the_equation(x, accuracy) / 2 /\
				pow(accuracy_limit, -accuracy)) * pow(accuracy_limit, -accuracy));
	}
	{
		x = 100.5;
		accuracy = 10;
		printf ("%f\n", round(solving_the_equation(x, accuracy) / 2 /\
				pow(accuracy_limit, -accuracy)) * pow(accuracy_limit, -accuracy));
	}
	return 0;
}
