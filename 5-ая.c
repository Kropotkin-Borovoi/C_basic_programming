#include <stdio.h>
#include <math.h>

double Func (float x){ //интереумая функция
	double value; //значение функции
	value = 1/logl(x); //самостоятельно вводим интересуемую нами функцию
	return (value);//возвращение значения функции
}

int main()
{
	printf ("This program calculates the integral of the function F(x) by trapezoidal method\nEnter the lower integration limit (a), the upper integration limit, the number of partitions\n");//приветствие
	int step, i;
	double a, b, h, integral, result;
	int s = scanf ("%lf %lf %d", &a, &b, &step);//проверка на правильность ввода переменных
	if (s<3) {
		printf("You entered the wrong variable type");
		return (90);//если код ошибки 90, значит введён неправильный тип переменной
	}
	h=(b-a)/step; //вычисляем длину каждого шага
	integral=(Func(a)+Func(b))/2; /*это первый член суммы по методу 
	трапеции */
	for(i=1;i<step;i++) {//прибавляем каждый последующий шаг
		a+=h;
		integral+=Func(a);
	}
	result = h*integral;
	printf ("%lf\n", result);
	return 0;
}
