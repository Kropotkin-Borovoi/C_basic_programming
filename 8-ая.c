#include <stdio.h>
#include <math.h>

void swap (int *numb1, int *numb2) {
	int auxiliary_element;
	auxiliary_element =* numb1;
	*numb1 = *numb2;
	*numb2 = auxiliary_element;
}

void Compare_n_Swap_to_Big (int *numb1, int *numb2) {//сравнение по возрастанию
	if (*numb1 > *numb2) {
		swap(numb1, numb2);
	}
}

void Compare_n_Swap_to_Small (int *numb1, int *numb2) {//сравнение по убыванию
	if (*numb1 < *numb2) {
		swap(numb1, numb2);
	}
}

void Compare_n_Swap_Absolutely (int *numb1, int *numb2) {//сравнение по 
// абсолютному значению
	if (fabs(*numb1) > fabs(*numb2)) {//сравниваем по модулю
		swap(numb1, numb2);
	} 
}

int Sort (int* DMas, int array_size, void (*Compare) (int *, int *)) {//сортировка
	int i, j;
		for (i = 1; i <= array_size - 1; i++) {
			for (j = i; j <= array_size; j++) {
				Compare (&DMas[i], &DMas[j]);
			}
		}
	return *DMas;
}

int main()
{
	printf ("This program sorts the entered dynamic array\nEnter \
 the array size:\n");//приветствие
	int array_size, i;
	scanf ("%d", &array_size);
	int* DMas = (int*) malloc(array_size * sizeof(int*));//создаём динамический массив
	
	for (i = 1; i <= array_size; i++) {
		printf ("Enter the %d item:\n", i);
		scanf ("%d", &DMas[i]);//вводим значение для каждого элемента массива
	}
	
	char direct;
	printf ("In what direction should I sort? Descending (<), \
 or ascending (>), or absolutely (!)?\n");//выбор направления по сортировке
	scanf (" %c", &direct);
	
	
	if (direct == '!')	
		Sort (DMas, array_size, Compare_n_Swap_Absolutely);
	else if (direct == '<')	
		Sort (DMas, array_size, Compare_n_Swap_to_Small);
	else if (direct == '>')	
		Sort (DMas, array_size, Compare_n_Swap_to_Big);
	else
		printf ("What do you wnat?");
	
	
	for (i = 1; i <= array_size; i++) {
		printf ("DMas [%d] = %d\n", i ,DMas[i]);//выводим отсортированный массив
	}
	free(DMas);
	return 0;
}

