#define data 100//максимальный размер массива
#include <stdio.h>
#include <math.h>
int Mas[data];//массив в виде глобальной переменной

int Max (int numb) {//функция по нахождению максимума массива через оператор (*)
	int i, max=0;
	int* pMas;//указатель
	for (i=1, pMas=Mas;i<=numb;i++) {//указатель "указывает" на массив
		if (*(pMas+i)>max) {
			max=*(pMas+i);
		}
	}
	return (max);
}

int Min (int numb) {//функция по нахождению минимума массива через оператор (*)
	int* pMas;//ссылка
	int i=1, min=Max(numb);
	for (i=1, pMas=Mas;i<=numb;i++) {//ссылка принимает значение массива
		if (*(pMas+i)<min) {
			min=*(pMas+i);
		}
	}
	return (min);
}

float Mean (int numb) {//функция по нахождению среднеарифметического значения массива
	int i;
	float count=0;
	for(i=1;i<=numb;i++) {
		count+=Mas[i];
	}
	count/=numb;
	return (count);
}

float RMS (int numb) {//функция по нахождению среднеквадратичного отклонения в массиве
	int i;
	float S=0;
	for (i=1;i<=numb;i++) {
		S+=pow(Mas[i]-Mean(numb),2);
	}
	S/=numb-1;
	return(sqrt(S));
}

int main()
{
	printf ("This program calculates the maximum, minimum, mean, square deviation in the entered static array\nEnter the array size\n");//приветствие
	int array_size, i;
	int s = scanf ("%d", &array_size);//проверка на правильность ввода переменной
	if (s<1) {
		printf("You entered the wrong variable type");
		return (90);//если код ошибки 90, значит введён неправильный тип переменной
	}
	for(i=1;i<=array_size;i++) {
		printf ("Enter the %d item\n", i);
		scanf ("%d", &Mas[i]);//вводим значение для каждого элемента массива
	}
	printf ("\n\nMax = %d\nMin = %d\nMean = %f\nRMS = %f\n", Max(array_size), Min(array_size), Mean(array_size), RMS(array_size));
	return 0;
}
