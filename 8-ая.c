#include <stdio.h>
#include <math.h>
int auxiliary_element;//создаём его как глобальную переменную, чтоб в каждой функции не создавать его заново
void Compare_to_Big (int *numb1, int *numb2) {//сравнение по возрастанию
	if (*numb1>*numb2) {
		auxiliary_element=*numb1;
		*numb1=*numb2;
		*numb2=auxiliary_element;
	}
}

void Compare_to_Small (int *numb1, int *numb2) {//сравнение по убыванию
	if (*numb1<*numb2) {
		auxiliary_element=*numb1;
		*numb1=*numb2;
		*numb2=auxiliary_element;
	}
}

void Compare_Absolutely (int *numb1, int *numb2) {//сравнение по абсолютному значению
	if (fabs(*numb1)>fabs(*numb2)) {//сравниваем по модулю
		auxiliary_element=*numb1;
		*numb1=*numb2;
		*numb2=auxiliary_element;
	} 
}

int Replace (int* DMas, int array_size, char direct) {//сортировка
	int i, j;
		if (direct=='>') {
			for (i=1;i<=array_size-1;i++) {
				for (j=i;j<=array_size;j++) {
					Compare_to_Big (&DMas[i], &DMas[j]);
				}
			}
		}
		else if (direct=='<') {
			for (i=1;i<=array_size-1;i++) {
				for (j=i;j<=array_size;j++) {
					Compare_to_Small (&DMas[i], &DMas[j]);
				}
			}
		}
		else {
			for (i=1;i<=array_size-1;i++) {
				for (j=i;j<=array_size;j++) {
					Compare_Absolutely (&DMas[i], &DMas[j]);
				}
			}	
		}
	return (*DMas);
}

int main()
{
	printf ("This program sorts the entered dynamic array\nEnter the array size:\n");//приветствие
	int array_size, i;
	int s = scanf ("%d", &array_size);
	if (s<1) {//проверка на правильность ввода переменной
		printf("You entered the wrong variable type");
		return (90);//если код ошибки 90, значит введён неправильный тип переменной
	}
	int* DMas = (int*) malloc(array_size*sizeof(int*));//создаём динамический массив
	for(i=1;i<=array_size;i++) {
		printf ("Enter the %d item:\n", i);
		scanf ("%d", &DMas[i]);//вводим значение для каждого элемента массива
	}
	char direct;
	printf ("In what direction should I sort? Descending (<), or ascending (>), or absolutely (!)?\n");//выбор направления по сортировке
	scanf (" %c", &direct);
	Replace (DMas, array_size, direct);//сортируем
	for(i=1;i<=array_size;i++) {
		printf ("DMas [%d] = %d\n", i ,DMas[i]);//выводим отсортированный массив
	}
	free(DMas);
	return 0;
}

