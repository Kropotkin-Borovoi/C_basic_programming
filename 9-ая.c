#include <stdio.h>
#include <math.h>

typedef struct {
	float Mas[9];
} Matrix;

Matrix summ (Matrix Mas1, Matrix Mas2, Matrix result, int array_size) {//функция по сложению
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size; j++) {
			result.Mas[i * array_size + j] = Mas1.Mas[i * array_size + j]\
			+ Mas2.Mas[i * array_size + j];
		}
	}
	return result;
}

Matrix multiply (Matrix Mas1, Matrix Mas2, Matrix result, int array_size) {//функция по умножению
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size; j++) {
			result.Mas[i * array_size + j] = 0;
			for (int k = 0; k < array_size; k++) {
				result.Mas[i * array_size + j] = \
				Mas1.Mas[i * array_size + k] * \
				Mas2.Mas[k * array_size + j] + \
				result.Mas[i * array_size + j];	 
			}
		}
	}
	return result;
}

float det (Matrix Mas1, int array_size) {//функция по поиску определителя матрицы
	float det;
	det = Mas1.Mas[0 * array_size + 0] * Mas1.Mas[1 * array_size + 1] * Mas1.Mas[2 * array_size + 2] + \
	Mas1.Mas[0 * array_size + 1] * Mas1.Mas[1 * array_size + 2] * Mas1.Mas[2 * array_size + 0] + \
	Mas1.Mas[0 * array_size + 2] * Mas1.Mas[1 * array_size + 0] * Mas1.Mas[2 * array_size + 1]- \
	Mas1.Mas[0 * array_size + 2] * Mas1.Mas[1 * array_size + 1] * Mas1.Mas[2 * array_size + 0]- \
	Mas1.Mas[0 * array_size + 0] * Mas1.Mas[1 * array_size + 2] * Mas1.Mas[2 * array_size + 1]- \
	Mas1.Mas[0 * array_size + 1] * Mas1.Mas[1 * array_size + 0] * Mas1.Mas[2 * array_size + 2];
	return det;
}

Matrix reverse (Matrix Mas1, Matrix result, int array_size) {//функция по поиску обратной матрицы
	result.Mas[0] = (Mas1.Mas[1 * array_size + 1] * Mas1.Mas[2 * array_size + 2] - Mas1.Mas[2 * array_size + 1] * Mas1.Mas[1 * array_size + 2]) / det(Mas1, array_size);
	result.Mas[1] = (Mas1.Mas[0 * array_size + 1] * Mas1.Mas[2 * array_size + 2] - Mas1.Mas[2 * array_size + 1] * Mas1.Mas[0 * array_size + 2]) / det(Mas1, array_size);
	result.Mas[2] = (Mas1.Mas[0 * array_size + 1] * Mas1.Mas[1 * array_size + 2] - Mas1.Mas[1 * array_size + 1] * Mas1.Mas[0 * array_size + 2]) / det(Mas1, array_size);
	result.Mas[3] = (Mas1.Mas[1 * array_size + 0] * Mas1.Mas[2 * array_size + 2] - Mas1.Mas[2 * array_size + 0] * Mas1.Mas[1 * array_size + 2]) / det(Mas1, array_size);
	result.Mas[4] = (Mas1.Mas[0 * array_size + 0] * Mas1.Mas[2 * array_size + 2] - Mas1.Mas[2 * array_size + 0] * Mas1.Mas[0 * array_size + 2]) / det(Mas1, array_size);
	result.Mas[5] = (Mas1.Mas[0 * array_size + 0] * Mas1.Mas[1 * array_size + 2] - Mas1.Mas[1 * array_size + 0] * Mas1.Mas[0 * array_size + 2]) / det(Mas1, array_size);
	result.Mas[6] = (Mas1.Mas[1 * array_size + 0] * Mas1.Mas[2 * array_size + 1] - Mas1.Mas[2 * array_size + 0] * Mas1.Mas[1 * array_size + 1]) / det(Mas1, array_size);
	result.Mas[7] = (Mas1.Mas[0 * array_size + 0] * Mas1.Mas[2 * array_size + 1] - Mas1.Mas[2 * array_size + 0] * Mas1.Mas[0 * array_size + 1]) / det(Mas1, array_size);
	result.Mas[8] = (Mas1.Mas[0 * array_size + 0] * Mas1.Mas[1 * array_size + 1] - Mas1.Mas[1 * array_size + 0] * Mas1.Mas[0 * array_size + 1]) / det(Mas1, array_size);
	return result;
}

Matrix enter_matrix_by_file (FILE *array_input, Matrix Mas1, int array_size) {
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size; j++) {
			printf ("\nВводится %d %d элемент первой матрицы\n", i, j);
			fscanf (array_input,"%f", &Mas1.Mas[i * array_size + j]); 
			printf ("%f", Mas1.Mas[i * array_size + j]);
		}
	}
	return Mas1;
}

Matrix enter_matrix_by_yourself (Matrix Mas1, int array_size) {
	for (int i = 0; i < array_size; i++) {
			for (int j = 0; j < array_size; j++) {
				printf ("Введите %d %d элемент первой матрицы\n", i, j);
				scanf ("%f", &Mas1.Mas[i * array_size + j]);
			}
		}
	return Mas1;
}

void output_matrix (Matrix Mas1, int array_size) {
	for (int i = 0; i < array_size; i++) {
		printf ("\n");
		for (int j = 0; j < array_size; j++) {
			printf ("%f ", Mas1.Mas[i * array_size + j]);
		}
	}
}

void output_matrix_in_file (FILE *array_output, Matrix Mas1, int array_size) {
	for (int i = 0; i < array_size; i++) {
		fprintf (array_output,"\n");
		for (int j = 0; j < array_size; j++) {
			fprintf (array_output, "%f ", Mas1.Mas[i * array_size + j]);
		}
	}
}

int main()
{
	int path,/*"path" - переменная по выбору способа считывания 
			   и записи элементов матрицы*/
		array_size = 3;
	Matrix m1;
	Matrix m2;
	Matrix m3;
	printf ("Enter '0'(self) if you want to enter values from the\
			 terminal or enter '1'(file) if you want to read from\
			 a file\n");
	scanf ("%d", &path);
	
	if (path==1) {
		FILE *array_input1 = fopen("array_input1.txt", "r");
		FILE *array_input2 = fopen("array_input2.txt", "r");
		enter_matrix_by_file(array_input1, m1, array_size);
		printf ("\n\n");
		enter_matrix_by_file(array_input2, m2, array_size);
		fclose(array_input1);
		fclose(array_input2);
	}
	else if (path==0){
		m1 = enter_matrix_by_yourself(m1, array_size);
		printf ("\n\n");
		m2 = enter_matrix_by_yourself(m2, array_size);
	}
	
	else {
		printf ("What do you want?");
		return 0;
	}
	
	printf ("\n\n");
	output_matrix(m1, array_size);
	printf ("\n\n\n");
	output_matrix(m2, array_size);
	
	printf("\n\n");
	m3 = summ(m1, m2, m3, array_size);//вызываем функцию суммирования
	output_matrix(m3, array_size);
	
	printf("\n\n");
	m3 = multiply(m1, m2, m3, array_size);//вызываем функцию умножения
	output_matrix(m3, array_size);
		
	printf("\n\ndet1 = %f\n\ndet2 = %f\n\n", det(m1, array_size), det(m2, array_size));
	/*вызываем функцию по обнаружению определителя и сразу 
	  же выводим его значение*/
	
	m3 = reverse(m1, m3, array_size);/*вызываем функцию по обнаружению обратной
							 матрицы к первой матрице*/
	output_matrix(m3, array_size);
	printf("\n\n");
		
	m3 = reverse(m2, m3, array_size);/*вызываем функцию по обнаружению обратной
							матрицы ко второй матрице*/
	output_matrix(m3, array_size);
	
	
	FILE *array_output = fopen("array_output.txt", "w");
	m3 = summ(m1, m2, m3, array_size);//вызываем функцию суммирования
	output_matrix_in_file(array_output, m3, array_size);
	fprintf (array_output, "\n\n");
		
	m3 = multiply(m1, m2, m3, array_size);//вызываем функцию умножения
	output_matrix_in_file(array_output, m3, array_size);
	fprintf (array_output, "\n\n");
		
	fprintf (array_output,"\n\ndet1 = %f\n\ndet2 = %f\n\n",\
			 det(m1, array_size), det(m2, array_size));
	/*вызываем функцию по обнаружению определителя и сразу же
	  записываем его значение в файл*/
	fprintf (array_output, "\n\n");
		
	m3 = reverse(m1, m3, array_size);/*вызываем функцию по обнаружению обратной
							 матрицы к первой матрице*/
	output_matrix_in_file(array_output, m3, array_size);
	fprintf (array_output, "\n\n");
		
	m3 = reverse(m2, m3, array_size);/*вызываем функцию по обнаружению обратной
							 матрицы ко второй матрице*/
	output_matrix_in_file(array_output, m3, array_size);
	fprintf (array_output, "\n\n");
	fclose(array_output);
	return 0;
}
