#include <stdio.h>
#include <math.h>

float Func (float x){
	return 1 - cos(x);
}

float dFunc (float x, float (*F)(float )){
	float h=0.000001;
	return (F(x + h) - F(x - h)) / (2 * h);
}

float solving_the_equation (float x, int accuracy, float (*Fu)(float )) {
	float accuracy_limit = 10, S1, S2;
	do {
		S1 = x - (Fu(x) / dFunc(x, Func));
		S2 = S1 - (Fu(S1) / dFunc(S1, Func));
		x = S2;
	}
	while ((Fu(S1) / dFunc(S1, Func)) > pow(accuracy_limit, -accuracy));
	return S1 + S2;
}

int main()
{
	printf ("This program solves an equation of the form F(x) = 0 by\
 Newton's method\nEnter the initial approximation and the required\
 accuracy of the calculation\n");
	
	int accuracy=0;
	float accuracy_limit = 10, x;
	
	scanf ("%f %d", &x, &accuracy);
	
	printf ("%f\n", round(solving_the_equation(x, accuracy, Func) / 2 /\
 pow(accuracy_limit, -accuracy)) * pow(accuracy_limit, -accuracy));
	
	return 0;
}
