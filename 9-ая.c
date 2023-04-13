#include <stdio.h>
#include <math.h>

typedef struct {
	float Mas[9];
} Matrix;

Matrix summ (float *Mas1, float *Mas2) {//функция по сложению
	Matrix m3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m3.Mas[i * 3 + j] = Mas1[i * 3 + j] + Mas2[i * 3 + j];
		}
	}
	return m3;
}

Matrix multiply (float *Mas1, float *Mas2) {//функция по умножению
	Matrix m3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m3.Mas[i * 3 + j] = 0;
			for (int k = 0; k < 3; k++) {
				m3.Mas[i * 3 + j] = Mas1[i * 3 + k] * Mas2[k * 3 + j] + m3.Mas[i * 3 + j];	 
			}
		}
	}
	return m3;
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

Matrix reverse (float *Mas1) {//функция по поиску обратной матрицы
	Matrix m3;
	m3.Mas[0] = (Mas1[1 * 3 + 1] * Mas1[2 * 3 + 2] - Mas1[2 * 3 + 1] * Mas1[1 * 3 + 2]) / det(Mas1);
	m3.Mas[1] = (Mas1[0 * 3 + 1] * Mas1[2 * 3 + 2] - Mas1[2 * 3 + 1] * Mas1[0 * 3 + 2]) / det(Mas1);
	m3.Mas[2] = (Mas1[0 * 3 + 1] * Mas1[1 * 3 + 2] - Mas1[1 * 3 + 1] * Mas1[0 * 3 + 2]) / det(Mas1);
	m3.Mas[3] = (Mas1[1 * 3 + 0] * Mas1[2 * 3 + 2] - Mas1[2 * 3 + 0] * Mas1[1 * 3 + 2]) / det(Mas1);
	m3.Mas[4] = (Mas1[0 * 3 + 0] * Mas1[2 * 3 + 2] - Mas1[2 * 3 + 0] * Mas1[0 * 3 + 2]) / det(Mas1);
	m3.Mas[5] = (Mas1[0 * 3 + 0] * Mas1[1 * 3 + 2] - Mas1[1 * 3 + 0] * Mas1[0 * 3 + 2]) / det(Mas1);
	m3.Mas[6] = (Mas1[1 * 3 + 0] * Mas1[2 * 3 + 1] - Mas1[2 * 3 + 0] * Mas1[1 * 3 + 1]) / det(Mas1);
	m3.Mas[7] = (Mas1[0 * 3 + 0] * Mas1[2 * 3 + 1] - Mas1[2 * 3 + 0] * Mas1[0 * 3 + 1]) / det(Mas1);
	m3.Mas[8] = (Mas1[0 * 3 + 0] * Mas1[1 * 3 + 1] - Mas1[1 * 3 + 0] * Mas1[0 * 3 + 1]) / det(Mas1);
	return m3;
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
	Matrix m1;
	Matrix m2;
	Matrix mat;
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
	//summ(*Mas3, m1.Mas, m2.Mas);//вызываем функцию суммирования
	mat = summ(m1.Mas, m2.Mas);
	output_matrix(mat.Mas);
	
	printf("\n\n");
	mat = multiply(m1.Mas, m2.Mas);//вызываем функцию умножения
	output_matrix(mat.Mas);
		
	printf("\n\ndet1 = %f\n\ndet2 = %f\n\n", det(m1.Mas), det(m2.Mas));
	/*вызываем функцию по обнаружению определителя и сразу 
	  же выводим его значение*/
	
	mat = reverse(m1.Mas);/*вызываем функцию по обнаружению обратной
							 матрицы к первой матрице*/
	output_matrix(mat.Mas);
	printf("\n\n");
		
	mat = reverse(m2.Mas);/*вызываем функцию по обнаружению обратной
							матрицы ко второй матрице*/
	output_matrix(mat.Mas);
	
	
	FILE *array_output = fopen("/home/hello/Рабочий стол/Основы\
								программирования/array_output.txt", "w");
	mat = summ(m1.Mas, m2.Mas);//вызываем функцию суммирования
	output_matrix_in_file(array_output, mat.Mas);
	fprintf (array_output, "\n\n");
		
	mat = multiply(m1.Mas, m2.Mas);//вызываем функцию умножения
	output_matrix_in_file(array_output, mat.Mas);
	fprintf (array_output, "\n\n");
		
	fprintf (array_output,"\n\ndet1 = %f\n\ndet2 = %f\n\n",\
			 det(m1.Mas), det(m2.Mas));
	/*вызываем функцию по обнаружению определителя и сразу же
	  записываем его значение в файл*/
	fprintf (array_output, "\n\n");
		
	mat = reverse(m1.Mas);/*вызываем функцию по обнаружению обратной
							 матрицы к первой матрице*/
	output_matrix_in_file(array_output, mat.Mas);
	fprintf (array_output, "\n\n");
		
	mat = reverse(m2.Mas);/*вызываем функцию по обнаружению обратной
							 матрицы ко второй матрице*/
	output_matrix_in_file(array_output, mat.Mas);
	fprintf (array_output, "\n\n");
	fclose(array_output);
	return 0;
}
