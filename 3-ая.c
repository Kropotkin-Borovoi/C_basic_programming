#include <stdio.h>
#include <math.h>

int main() 
{
	printf ("This program prints the number Pi up to the sign requested by the user\nEnter the number up to which you want to calculate the number Pi\n"); //приветствие
	int accuracy=0, n=0;
	double accuracy_limit=10, S1=0, S2=0;
	scanf ("%d", &accuracy);
	do {
		n++;//для нечётных
		S1=S2+(4.0/(2*n-1));//высчитывается верхняя сумма
		n++;//для чётных
		S2=S1-(4.0/(2*n-1));//высчитывается нижняя сумма
	}
	while ((S1-S2)>pow(accuracy_limit, -accuracy));//проверка точности
	printf("%f\n", round((S1+S2)/2/pow(accuracy_limit, -accuracy))*pow(accuracy_limit, -accuracy));//вывод числа Пи с той точностью, которой мы указали
	printf("%d", n);//вывод количества слагаемых
	return 0;
}


