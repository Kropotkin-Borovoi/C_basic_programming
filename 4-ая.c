#include <stdio.h>
#include <math.h>

double Func (float x){ //интересующая функция
	double value; //значение функции
	value = 1-cosl(x); //самостоятельно вводим интересующую нами функцию
	return (value);//возвращение значения функции
}

double dFunc (float x){ //производная к интересуемой нами функции
	double d_value;// значение производной функции
	d_value = sinl(x); /*самостоятельно вводим интересуемую нами производную
	функции */
	return (d_value);//возвращение значения производной функции
}

int main()
{
	printf ("This program solves an equation of the form F(x) = 0 by Newton's method\nEnter the initial approximation and the required accuracy of the calculation\n");//приветствие
	int accuracy=0;
	double accuracy_limit=10, x, S1, S2;
	int s = scanf ("%lf %d", &x, &accuracy); 
	if (s<2) {//проверка на правильность ввода переменной типа integer
		printf("You entered the wrong variable type");
		return (90);//если код ошибки 90, значит введён неправильный тип переменной
	}
	do {
		S1=x-(Func(x)/dFunc(x));//вверхняя сумма
		S2=S1-(Func(S1)/dFunc(S1));//нижняя сумма
		x=S2;
	}
	while ((Func(S1)/dFunc(S1))>pow(accuracy_limit, -accuracy));
	printf("%f\n", round((S1+S2)/2/pow(accuracy_limit, -accuracy))*pow(accuracy_limit, -accuracy));
	return 0;
}
