#include <stdio.h>
#include <math.h>

float Func (float x){
	return 1 / logl(x);
}

float solving_the_equation (float a, float b, int step, float (*F)(float )) { 
	float dx, integral, result;
	dx = (b - a) / step; //вычисляем длину каждого шага
	integral = (F(a) + F(b)) / 2; /*это первый член суммы по методу 
	трапеции */
	for(int i = 1; i < step; i++) {//прибавляем каждый последующий шаг
		a += dx;
		integral += F(a);
	}
	result = dx * integral;
	if (b < a) {
		result *= (-1);
	}
	return result;
}

int main()
{
	printf ("This program calculates the integral of the function F(x)\
 by trapezoidal method\nEnter the lower integration limit, the\
 upper integration limit, the number of partitions\n");
	int step;
	float a, b;
	
	scanf ("%f %f %d", &a, &b, &step);
	
	printf ("%f\n", solving_the_equation(a, b, step, Func));
	
	return 0;
}
