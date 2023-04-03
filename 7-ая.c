#include <stdio.h>
#include <math.h>

int Max (int *DMas, int numb) {//функция по нахождению максимума массива
	int i, max = 0;
	for (i = 1; i <= numb; i++) {
		if (DMas[i] > max) {
			max = DMas[i];
		}
	}
	return max;
}

int Min (int *DMas, int numb) {//функция по нахождению минимума массива
	int i = 1, min = Max(DMas, numb);
	for (i = 1; i <= numb; i++) {
		if (DMas[i] < min) {
			min = DMas[i];
		}
	}
	return min;
}

float Mean (int *DMas, int numb) {//функция по нахождению 
// среднеарифметического значения массива через оператор (*)
	int i;
	float count = 0;
	for(i = 1; i <= numb; i++) {
		count += DMas[i];
	}
	count /= numb;
	return count;
}

float RMS (int *DMas, int numb) {//функция по нахождению 
// среднеквадратичного отклонения в массиве через оператор (*)
	int i;
	float S = 0;
	for (i = 1; i <= numb; i++) {
		S += pow(DMas[i] - Mean(DMas, numb), 2);
	}
	S /= numb - 1;
	return sqrt(S);
}

int main()
{
	printf ("This program calculates the maximum, minimum, mean,\
 square deviation in the entered dynamic array\nEnter the array size\n");
	int array_size, i;
	scanf ("%d", &array_size);
	int* DMas = (int*) malloc(array_size * sizeof(int));
	for (i = 1; i <= array_size; i++) {
		printf ("Enter the %d item\n", i);
		scanf ("%d", &DMas[i]);
	}
	printf ("\n\nMax = %d\nMin = %d\nMean = %f\nRMS = %f\n", \
	Max(DMas, array_size), Min(DMas, array_size), Mean(DMas, \
 array_size), RMS(DMas, array_size));
	free(DMas);
	return 0;
}

