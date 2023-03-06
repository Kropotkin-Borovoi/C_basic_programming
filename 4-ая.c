#include <stdio.h>
#include <math.h>

float Func (float x){ //интересующая функция
	float value; //значение функции
	value = 1-cosl(x); //самостоятельно вводим интересующую нами функцию
	return (value);//возвращение значения функции
}

float dFunc (float x){ //производная к интересующей нами функции
	float d_value, h=0.000001;// значение производной функции и "бесконечно малой" величины
	d_value = (Func(x+h)-Func(x-h))/(2*h); /*автоматически считает приблизительную производную к инетересующей нами функции
	функции */
	return (d_value);//возвращение значения производной функции
}

int main()
{
	printf ("This program solves an equation of the form F(x) = 0 by Newton's method\nEnter the initial approximation and the required accuracy of the calculation\n");//приветствие
	int accuracy=0;
	float accuracy_limit=10, x, S1, S2;
	scanf ("%f %d", &x, &accuracy);
	do {
		S1=x-(Func(x)/dFunc(x));//вверхняя сумма
		S2=S1-(Func(S1)/dFunc(S1));//нижняя сумма
		x=S2;
	}
	while ((Func(S1)/dFunc(S1))>pow(accuracy_limit, -accuracy));
	printf("%f\n", round((S1+S2)/2/pow(accuracy_limit, -accuracy))*pow(accuracy_limit, -accuracy));
	return 0;
}
