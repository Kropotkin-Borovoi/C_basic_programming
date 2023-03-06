#include <stdio.h>
#include <math.h>

int Max (int* DMas, int numb) {//функция по нахождению максимума массива
	int i, max=0;
	for (i=1;i<=numb;i++) {
		if (DMas[i]>max) {
			max=DMas[i];
		}
	}
	return (max);
}

int Min (int *DMas, int numb) {//функция по нахождению минимума массива
	int i=1, min=Max(DMas, numb);
	for (i=1;i<=numb;i++) {
		if (DMas[i]<min) {
			min=DMas[i];
		}
	}
	return (min);
}

float Mean (int *DMas, int numb) {//функция по нахождению среднеарифметического значения массива через оператор (*)
	int i;
	int* pMas;//ссылка
	float count=0;
	for(i=1, pMas=DMas;i<=numb;i++) {//ссылка принимает значение массива
		count+=*(pMas+i);
	}
	count/=numb;
	return (count);
}

float RMS (int *DMas, int numb) {//функция по нахождению среднеквадратичного отклонения в массиве через оператор (*)
	int i;
	int* pMas;//ссылка
	float S=0;
	for (i=1, pMas=DMas;i<=numb;i++) {//ссылка принимает значение массива
	S+=pow(*(pMas+i)-Mean(DMas, numb),2);
	}
	S/=numb;
	return(sqrt(S));
}

int main()
{
	printf ("This program calculates the maximum, minimum, mean, square deviation in the entered dynamic array\nEnter the array size\n");//приветствие
	int array_size, i;
	int s = scanf ("%d", &array_size);
	if (s<1) {//проверка на правильность ввода переменной
		printf("You entered the wrong variable type");
		return (90);//если код ошибки 90, значит введён неправильный тип переменной
	}
	int* DMas = (int*) malloc(array_size*sizeof(int*));//создаём динамический массив
	for(i=1;i<=array_size;i++) {
		printf ("Enter the %d item\n", i);
		scanf ("%d", &DMas[i]);//вводим значение для каждого элемента массива
	}
	printf ("\n\nMax = %d\nMin = %d\nMean = %f\nRMS = %f\n", \
	Max(DMas, array_size), Min(DMas, array_size), Mean(DMas, array_size), RMS(DMas, array_size));
	free(DMas);
	return 0;
}

