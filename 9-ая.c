#include <stdio.h>
#include <math.h>

typedef struct {
	float Mas[9];
} Matrix;

void summ (float *Mas3, float *Mas1, float *Mas2) {//функция по сложению
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Mas3[i * 3 + j] = Mas1[i * 3 + j] + Mas2[i * 3 + j];
		}
	}
}

void product (float *Mas3, float *Mas1, float *Mas2) {//функция по умножению
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Mas3[i * 3 + j] = 0;
			for (int k = 0; k < 3; k++) {
				Mas3[i * 3 + j] = Mas1[i * 3 + k] * Mas2[k * 3 + j] + Mas3[i * 3 + j];	 
			}
		}
	}
}

float det (float *Mas) {//функция по поиску определителя матрицы
	float det;
	det = Mas[0 * 3 + 0] * Mas[1 * 3 + 1] * Mas[2 * 3 + 2] + \
	Mas[0 * 3 + 1] * Mas[1 * 3 + 2] * Mas[2 * 3 + 0] + \
	Mas[0 * 3 + 2] * Mas[1 * 3 + 0] * Mas[2 * 3 + 1]-\
	Mas[0 * 3 + 2] * Mas[1 * 3 + 1] * Mas[2 * 3 + 0]-\
	Mas[0 * 3 + 0] * Mas[1 * 3 + 2] * Mas[2 * 3 + 1]-\
	Mas[0 * 3 + 1] * Mas[1 * 3 + 0] * Mas[2 * 3 + 2];
	return (det);
}

void reverse (float *Mas3, float *Mas1) {//функция по поиску обратной матрицы
	Mas3[0] = (Mas1[1 * 3 + 1] * Mas1[2 * 3 + 2] - Mas1[2 * 3 + 1] * Mas1[1 * 3 + 2]) / det(Mas1);
	Mas3[1] = (Mas1[0 * 3 + 1] * Mas1[2 * 3 + 2] - Mas1[2 * 3 + 1] * Mas1[0 * 3 + 2]) / det(Mas1);
	Mas3[2] = (Mas1[0 * 3 + 1] * Mas1[1 * 3 + 2] - Mas1[1 * 3 + 1] * Mas1[0 * 3 + 2]) / det(Mas1);
	Mas3[3] = (Mas1[1 * 3 + 0] * Mas1[2 * 3 + 2] - Mas1[2 * 3 + 0] * Mas1[1 * 3 + 2]) / det(Mas1);
	Mas3[4] = (Mas1[0 * 3 + 0] * Mas1[2 * 3 + 2] - Mas1[2 * 3 + 0] * Mas1[0 * 3 + 2]) / det(Mas1);
	Mas3[5] = (Mas1[0 * 3 + 0] * Mas1[1 * 3 + 2] - Mas1[1 * 3 + 0] * Mas1[0 * 3 + 2]) / det(Mas1);
	Mas3[6] = (Mas1[1 * 3 + 0] * Mas1[2 * 3 + 1] - Mas1[2 * 3 + 0] * Mas1[1 * 3 + 1]) / det(Mas1);
	Mas3[7] = (Mas1[0 * 3 + 0] * Mas1[2 * 3 + 1] - Mas1[2 * 3 + 0] * Mas1[0 * 3 + 1]) / det(Mas1);
	Mas3[8] = (Mas1[0 * 3 + 0] * Mas1[1 * 3 + 1] - Mas1[1 * 3 + 0] * Mas1[0 * 3 + 1]) / det(Mas1);
}

float enter_matrix_by_file (FILE *array_input, float *Mas) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf ("\nВводится %d %d элемент первой матрицы\n", i, j);
			fscanf (array_input,"%f", &Mas[i * 3 + j]); 
			printf ("%f", Mas[i * 3 + j]);
		}
	}
	return *Mas;
}

float enter_matrix_by_yourself (float *Mas) {
	for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf ("Введите %d %d элемент первой матрицы\n", i, j);
				scanf ("%f", &Mas[i * 3 + j]);
			}
		}
	return *Mas;
}

void output_matrix (float *Mas) {
	for (int i = 0; i < 3; i++) {
		printf ("\n");
		for (int j = 0; j < 3; j++) {
			printf ("%f ", Mas[i * 3 + j]);
		}
	}
}

void output_matrix_in_file (FILE *array_output, float *Mas) {
	for (int i = 0; i < 3; i++) {
		fprintf (array_output,"\n");
		for (int j = 0; j < 3; j++) {
			fprintf (array_output, "%f ", Mas[i * 3 + j]);
		}
	}
}

int main()
{
	int path;/*"path" - переменная по выбору способа считывания 
			   и записи элементов матрицы*/
	float Mas3 [3][3];
	Matrix m1;
	Matrix m2;
	printf ("Enter '0'(self) if you want to enter values from the\
			 terminal or enter '1'(file) if you want to read from\
			 a file\n");
	scanf ("%d", &path);
	
	if (path==1) {
		FILE *array_input1 = fopen("/home/hello/Рабочий стол/Основы\
									программирования/array_input1.txt\
									", "r");
		FILE *array_input2 = fopen("/home/hello/Рабочий стол/Основы\
									программирования/array_input2.txt\
									", "r");
		enter_matrix_by_file(array_input1, m1.Mas);
		printf ("\n\n");
		enter_matrix_by_file(array_input2, m2.Mas);
		fclose(array_input1);
		fclose(array_input2);
	}
	else if (path==0){
		enter_matrix_by_yourself(m1.Mas);
		printf ("\n\n\n");
		enter_matrix_by_yourself(m2.Mas);
	}
	else {
		printf ("What do you want?");
	}
	printf ("\n\n");
	output_matrix(m1.Mas);
	printf ("\n\n\n");
	output_matrix(m2.Mas);
	
	printf("\n\n");
	summ(*Mas3, m1.Mas, m2.Mas);//вызываем функцию суммирования
	output_matrix(*Mas3);
	
	printf("\n\n");
	product(*Mas3, m1.Mas, m2.Mas);//вызываем функцию умножения
	output_matrix(*Mas3);
		
	printf("\n\ndet1 = %f\n\ndet2 = %f\n\n", det(m1.Mas), det(m2.Mas));
	/*вызываем функцию по обнаружению определителя и сразу 
	  же выводим его значение*/
	
	reverse(*Mas3, m1.Mas);/*вызываем функцию по обнаружению обратной
							 матрицы к первой матрице*/
	output_matrix(*Mas3);
	printf("\n\n");
		
	reverse(*Mas3, m2.Mas);/*вызываем функцию по обнаружению обратной
							 матрицы ко второй матрице*/
	output_matrix(*Mas3);
	
	
	FILE *array_output = fopen("/home/hello/Рабочий стол/Основы\
								программирования/array_output.txt", "w");
	summ(*Mas3, m1.Mas, m2.Mas);//вызываем функцию суммирования
	output_matrix_in_file(array_output, *Mas3);
	fprintf (array_output, "\n\n");
		
	product(*Mas3, m1.Mas, m2.Mas);//вызываем функцию умножения
	output_matrix_in_file(array_output, *Mas3);
	fprintf (array_output, "\n\n");
		
	fprintf (array_output,"\n\ndet1 = %f\n\ndet2 = %f\n\n",\
			 det(m1.Mas), det(m2.Mas));
	/*вызываем функцию по обнаружению определителя и сразу же
	  записываем его значение в файл*/
	fprintf (array_output, "\n\n");
		
	reverse(*Mas3, m1.Mas);/*вызываем функцию по обнаружению обратной
							 матрицы к первой матрице*/
	output_matrix_in_file(array_output, *Mas3);
	fprintf (array_output, "\n\n");
		
	reverse(*Mas3, m2.Mas);/*вызываем функцию по обнаружению обратной
							 матрицы ко второй матрице*/
	output_matrix_in_file(array_output, *Mas3);
	fprintf (array_output, "\n\n");
	fclose(array_output);
	return 0;
}
