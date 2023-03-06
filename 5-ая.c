#include <stdio.h>
#include <math.h>

float Func (float x){ //интереумая функция
	float value; //значение функции
	value = 1/logl(x); //самостоятельно вводим интересуемую нами функцию
	return (value);//возвращение значения функции
}

int main()
{
	printf ("This program calculates the integral of the function F(x) by trapezoidal method\nEnter the lower integration limit (a), the upper integration limit, the number of partitions\n");//приветствие
	int step, i;
	float a, b, h, integral, result;
	scanf ("%f %f %d", &a, &b, &step);
	h=(b-a)/step; //вычисляем длину каждого шага
	integral=(Func(a)+Func(b))/2; /*это первый член суммы по методу 
	трапеции */
	for(i=1;i<step;i++) {//прибавляем каждый последующий шаг
		a+=h;
		integral+=Func(a);
	}
	result = h*integral;
	if (b<a) {
		result*=(-1);
	}
	printf ("%f\n", result);
	return 0;
}
