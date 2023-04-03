#include <stdio.h>
#include <math.h>

#define data 100

int Mas[data];

int Max (int *Mas, int numb) {//функция по нахождению максимума массива через
//оператор (*)
	int max = Mas[0];
	for (int i = 0; i < numb; i++) {
		if (*(Mas + i + 1) > max) {
			max =* (Mas + i + 1);
		}
	}
	return max;
}

int Min (int *Mas, int numb) {//функция по нахождению минимума массива через
// оператор (*)
	int min = Max(Mas, numb);
	for (int i = 0; i < numb; i++) {
		if (*(Mas + i + 1) < min) {
			min =* (Mas + i + 1);
		}
	}
	return min;
}

float Mean (int *Mas, int numb) {//функция по нахождению среднеарифметического
// значения массива
	float count=0;
	for (int i = 0; i < numb; i++) {
		count += Mas[i];
	}
	count /= numb;
	return count;
}

float RMS (int *Mas, int numb) {//функция по нахождению среднеквадратичного 
// отклонения в массиве
	float S = 0;
	for (int i = 0; i < numb; i++) {
		S += pow(Mas[i] - Mean(Mas, numb), 2);
	}
	S /= numb - 1;
	return sqrt(S);
}

int main()
{
	printf ("This program calculates the maximum, minimum, mean,\
 square deviation in the entered static array\nEnter the array size\n");
	int array_size, i;
	
	scanf ("%d", &array_size);
	
	for (i = 1; i <= array_size; i++) {
		printf ("Enter the %d item\n", i);
		scanf ("%d", &Mas[i]);
	}
	
	printf ("\n\nMax = %d\nMin = %d\nMean = %f\nRMS = %f\n",\
 Max(Mas, array_size), Min(Mas, array_size), Mean(Mas, array_size), \
 RMS(Mas, array_size));
	return 0;
}
