#include <stdio.h>
#include <math.h>

typedef struct {
	float Mas[9];
	int N;
} Matrix;

void initMatrix (Matrix *Mas1) {
	Mas1->N = 3;
}

Matrix summ (Matrix Mas1, Matrix Mas2) {//функция по сложению
	Matrix result;
	initMatrix (&result);
	
	for (int i = 0; i < result.N; i++) {
		for (int j = 0; j < result.N; j++) {
			result.Mas[i * result.N + j] = Mas1.Mas[i * Mas1.N + j]\
			+ Mas2.Mas[i * Mas2.N + j];
		}
	}
	return result;
}

Matrix multiply (Matrix Mas1, Matrix Mas2) {//функция по умножению
	Matrix result;
	initMatrix (&result);
	
	for (int i = 0; i < result.N; i++) {
		for (int j = 0; j < result.N; j++) {
			result.Mas[i * result.N + j] = 0;
			for (int k = 0; k < result.N; k++) {
				result.Mas[i * result.N + j] += \
				Mas1.Mas[i * Mas1.N + k] * \
				Mas2.Mas[k * Mas2.N + j];	 
			}
		}
	}
	return result;
}

float det (Matrix Mas1) {//функция по поиску определителя матрицы
	float det;
	det = Mas1.Mas[0 * Mas1.N + 0] * Mas1.Mas[1 * Mas1.N + 1] * Mas1.Mas[2 * Mas1.N + 2] + \
	Mas1.Mas[0 * Mas1.N + 1] * Mas1.Mas[1 * Mas1.N + 2] * Mas1.Mas[2 * Mas1.N + 0] + \
	Mas1.Mas[0 * Mas1.N + 2] * Mas1.Mas[1 * Mas1.N + 0] * Mas1.Mas[2 * Mas1.N + 1]- \
	Mas1.Mas[0 * Mas1.N + 2] * Mas1.Mas[1 * Mas1.N + 1] * Mas1.Mas[2 * Mas1.N + 0]- \
	Mas1.Mas[0 * Mas1.N + 0] * Mas1.Mas[1 * Mas1.N + 2] * Mas1.Mas[2 * Mas1.N + 1]- \
	Mas1.Mas[0 * Mas1.N + 1] * Mas1.Mas[1 * Mas1.N + 0] * Mas1.Mas[2 * Mas1.N + 2];
	return det;
}

Matrix reverse (Matrix Mas1) {//функция по поиску обратной матрицы
	Matrix result;
	initMatrix(&result);
	
	result.Mas[0] = (Mas1.Mas[1 * Mas1.N + 1] * Mas1.Mas[2 * Mas1.N + 2] - Mas1.Mas[2 * Mas1.N + 1] * Mas1.Mas[1 * Mas1.N + 2]) / det(Mas1);
	result.Mas[1] = (Mas1.Mas[0 * Mas1.N + 1] * Mas1.Mas[2 * Mas1.N + 2] - Mas1.Mas[2 * Mas1.N + 1] * Mas1.Mas[0 * Mas1.N + 2]) / det(Mas1);
	result.Mas[2] = (Mas1.Mas[0 * Mas1.N + 1] * Mas1.Mas[1 * Mas1.N + 2] - Mas1.Mas[1 * Mas1.N + 1] * Mas1.Mas[0 * Mas1.N + 2]) / det(Mas1);
	result.Mas[3] = (Mas1.Mas[1 * Mas1.N + 0] * Mas1.Mas[2 * Mas1.N + 2] - Mas1.Mas[2 * Mas1.N + 0] * Mas1.Mas[1 * Mas1.N + 2]) / det(Mas1);
	result.Mas[4] = (Mas1.Mas[0 * Mas1.N + 0] * Mas1.Mas[2 * Mas1.N + 2] - Mas1.Mas[2 * Mas1.N + 0] * Mas1.Mas[0 * Mas1.N + 2]) / det(Mas1);
	result.Mas[5] = (Mas1.Mas[0 * Mas1.N + 0] * Mas1.Mas[1 * Mas1.N + 2] - Mas1.Mas[1 * Mas1.N + 0] * Mas1.Mas[0 * Mas1.N + 2]) / det(Mas1);
	result.Mas[6] = (Mas1.Mas[1 * Mas1.N + 0] * Mas1.Mas[2 * Mas1.N + 1] - Mas1.Mas[2 * Mas1.N + 0] * Mas1.Mas[1 * Mas1.N + 1]) / det(Mas1);
	result.Mas[7] = (Mas1.Mas[0 * Mas1.N + 0] * Mas1.Mas[2 * Mas1.N + 1] - Mas1.Mas[2 * Mas1.N + 0] * Mas1.Mas[0 * Mas1.N + 1]) / det(Mas1);
	result.Mas[8] = (Mas1.Mas[0 * Mas1.N + 0] * Mas1.Mas[1 * Mas1.N + 1] - Mas1.Mas[1 * Mas1.N + 0] * Mas1.Mas[0 * Mas1.N + 1]) / det(Mas1);
	return result;
}

Matrix enter_matrix_by_file (FILE *array_input, Matrix Mas1) {
	for (int i = 0; i < Mas1.N; i++) {
		for (int j = 0; j < Mas1.N; j++) {
			printf ("\nВводится %d %d элемент первой матрицы\n", i, j);
			fscanf (array_input,"%f", &Mas1.Mas[i * Mas1.N + j]); 
			printf ("%f", Mas1.Mas[i * Mas1.N + j]);
		}
	}
	return Mas1;
}

Matrix enter_matrix_by_yourself (Matrix Mas1) {
	for (int i = 0; i < Mas1.N; i++) {
			for (int j = 0; j < Mas1.N; j++) {
				printf ("Введите %d %d элемент первой матрицы\n", i, j);
				scanf ("%f", &Mas1.Mas[i * Mas1.N + j]);
			}
		}
	return Mas1;
}

void output_matrix (Matrix Mas1) {
	for (int i = 0; i < Mas1.N; i++) {
		printf ("\n");
		for (int j = 0; j < Mas1.N; j++) {
			printf ("%f ", Mas1.Mas[i * Mas1.N + j]);
		}
	}
}

void output_matrix_in_file (FILE *array_output, Matrix Mas1) {
	for (int i = 0; i < Mas1.N; i++) {
		fprintf (array_output,"\n");
		for (int j = 0; j < Mas1.N; j++) {
			fprintf (array_output, "%f ", Mas1.Mas[i * Mas1.N + j]);
		}
	}
}

void test_Mas_summ () {
	Matrix Mas1;
	Matrix Mas2;
	Matrix Mas_summ;
	
	float mat1[9] = {1, 2, 3, 7, 5, 6, 7, 8, 9};  
	for (int i = 0; i < 9; i++) {
		Mas1.Mas[i] = mat1[i]; 
	}
	
	float mat2[9] = {3, 4, 7, 2, 8, 9, 0, 4, 1};  
	for (int i = 0; i < 9; i++) {
		Mas2.Mas[i] = mat2[i]; 
	}
	 
	float mat_summ[9] = {4, 6, 10, 9, 13, 15, 7, 12, 10};  
	for (int i = 0; i < 9; i++) {
		Mas_summ.Mas[i] = mat_summ[i]; 
	}
	
	initMatrix(&Mas1);
	initMatrix(&Mas2);
	
	Matrix Mas_summ_;
	Mas_summ_ = summ(Mas1, Mas2);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(fabs(Mas_summ.Mas[i * Mas1.N + j] - Mas_summ_.Mas[i * Mas1.N + j]) > pow(10, -4)) {
				printf ("\nMas_summ.Mas[%d] == %f\nMas_summ_.Mas[%d] == %f", i * Mas1.N + j, Mas_summ.Mas[i * Mas1.N + j], i * Mas1.N + j, Mas_summ_.Mas[i * Mas1.N + j]);
				printf("error");
				exit(1);
			}
		}
	}
}

void test_Mas_multiply (){
	Matrix Mas1;
	Matrix Mas2;
	Matrix Mas_multiply;
	
	float mat1[9] = {1, 2, 3, 7, 5, 6, 7, 8, 9};  
	for (int i = 0; i < 9; i++) {
		Mas1.Mas[i] = mat1[i]; 
	}
	
	float mat2[9] = {3, 4, 7, 2, 8, 9, 0, 4, 1};  
	for (int i = 0; i < 9; i++) {
		Mas2.Mas[i] = mat2[i]; 
	}
	
	float mat_multiply[9] = {7, 32, 28, 31, 92, 100, 37, 128, 130};  
	for (int i = 0; i < 9; i++) {
		Mas_multiply.Mas[i] = mat_multiply[i]; 
	}

	initMatrix(&Mas1);
	initMatrix(&Mas2);
	
	Matrix Mas_multiply_;
	Mas_multiply_ = multiply(Mas1, Mas2);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(fabs(Mas_multiply.Mas[i * Mas1.N + j] - Mas_multiply_.Mas[i * Mas1.N + j]) > pow(10, -4)) {
				printf ("\nMas_multiply.Mas[%d] == %f\nMas_multiply_.Mas[%d] == %f", i * Mas1.N + j, Mas_multiply.Mas[i * Mas1.N + j], i * Mas1.N + j, Mas_multiply_.Mas[i * Mas1.N + j]);
				printf("error");
				exit(1);
			}
		}
	}
}

void test_Mas1_reverse (){
	Matrix Mas1;
	Matrix Mas1_reverse;
	
	float mat1[9] = {1, 2, 3, 7, 5, 6, 7, 8, 9};  
	for (int i = 0; i < 9; i++) {
		Mas1.Mas[i] = mat1[i]; 
	}
	
	float mat1_reverse[9] = {-0.1666, -0.3333, -0.1666, 1.1666, -0.6666, -0.8333, 1.1666, -0.3333, -0.5};  
	for (int i = 0; i < 9; i++) {
		Mas1_reverse.Mas[i] = mat1_reverse[i]; 
	}

	initMatrix(&Mas1);
	
	Matrix Mas1_reverse_;
	Mas1_reverse_ = reverse(Mas1);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(fabs(Mas1_reverse.Mas[i * Mas1.N + j] - Mas1_reverse_.Mas[i * Mas1.N + j]) > pow(10, -4)) {
				printf ("\nMas1_reverse.Mas[%d] == %f\nMas1_reverse_.Mas[%d] == %f", i * Mas1.N + j, Mas1_reverse.Mas[i * Mas1.N + j], i * Mas1.N + j, Mas1_reverse_.Mas[i * Mas1.N + j]);
				printf("error");
				exit(1);
			}
		}
	}
}

void test_Mas2_reverse (){
	Matrix Mas2;
	Matrix Mas2_reverse;
	
	float mat2[9] = {3, 4, 7, 2, 8, 9, 0, 4, 1};  
	for (int i = 0; i < 9; i++) {
		Mas2.Mas[i] = mat2[i]; 
	}
	
	float mat2_reverse[9] = {0.7777, 0.6666, 0.5555, -0.0555, -0.0833, -0.3611, -0.2222, -0.3333, -0.4444};  
	for (int i = 0; i < 9; i++) {
		Mas2_reverse.Mas[i] = mat2_reverse[i]; 
	}

	initMatrix(&Mas2);
	
	Matrix Mas2_reverse_;
	Mas2_reverse_ = reverse(Mas2);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(fabs(Mas2_reverse.Mas[i * Mas2.N + j] - Mas2_reverse_.Mas[i * Mas2.N + j]) > pow(10, -4)) {
				printf ("\nMas2_reverse.Mas[%d] == %f\nMas2_reverse_.Mas[%d] == %f", i * Mas2.N + j, Mas2_reverse.Mas[i * Mas2.N + j], i * Mas2.N + j, Mas2_reverse_.Mas[i * Mas2.N + j]);
				printf("error");
				exit(1);
			}
		}
	}
}

void test_Mas1_det(){
	Matrix Mas1;
	
	float mat1[9] = {1, 2, 3, 7, 5, 6, 7, 8, 9};  
	for (int i = 0; i < 9; i++) {
		Mas1.Mas[i] = mat1[i]; 
	}
	
	float det1 = 18;
	
	initMatrix(&Mas1);
	
	float det1_1 = det(Mas1);
	
	if (fabs(det1 - det1_1) > pow(10, -4)) { 
		printf ("\ndet1 == %f\ndet1_1 == %f", det1, det1_1);
		printf("error");
		exit(1);
	}
}

void test_Mas2_det(){
	Matrix Mas2;
	
	float mat2[9] = {3, 4, 7, 2, 8, 9, 0, 4, 1};  
	for (int i = 0; i < 9; i++) {
		Mas2.Mas[i] = mat2[i]; 
	}
	
	float det2 = -36;
	
	initMatrix(&Mas2);
	
	float det2_2 = det(Mas2);
	
	if (fabs(det2 - det2_2) > pow(10, -4)) { 
		printf ("\ndet2 == %f\ndet2_2 == %f", det2, det2_2);
		printf("error");
		exit(1);
	}
}

int main()
{
	int path;/*"path" - переменная по выбору способа считывания 
			   и записи элементов матрицы*/
	Matrix m1;
	Matrix m2;
	Matrix m3;
	
	initMatrix (&m1);
	initMatrix (&m2);
	initMatrix (&m3);
	
	test_Mas_summ();
	test_Mas_multiply();
	test_Mas1_reverse();
	test_Mas2_reverse();
	test_Mas1_det();
	test_Mas2_det();
	
	printf ("Enter '0'(self) if you want to enter values from the\
			 terminal or enter '1'(file) if you want to read from\
			 a file\n");
	scanf ("%d", &path);
	
	if (path==1) {
		FILE *array_input1 = fopen("array_input1.txt", "r");
		FILE *array_input2 = fopen("array_input2.txt", "r");
		enter_matrix_by_file(array_input1, m1);
		printf ("\n\n");
		enter_matrix_by_file(array_input2, m2);
		fclose(array_input1);
		fclose(array_input2);
	}
	else if (path==0){
		m1 = enter_matrix_by_yourself(m1);
		printf ("\n\n");
		m2 = enter_matrix_by_yourself(m2);
	}
	
	else {
		printf ("What do you want?");
		return 0;
	}
	
	printf ("\n\n");
	output_matrix(m1);
	printf ("\n\n\n");
	output_matrix(m2);
	
	printf("\n\n");
	m3 = summ(m1, m2);//вызываем функцию суммирования
	output_matrix(m3);
	
	printf("\n\n");
	m3 = multiply(m1, m2);//вызываем функцию умножения
	output_matrix(m3);
		
	printf("\n\ndet1 = %f\n\ndet2 = %f\n\n", det(m1), det(m2));
	/*вызываем функцию по обнаружению определителя и сразу 
	  же выводим его значение*/
	
	m3 = reverse(m1);/*вызываем функцию по обнаружению обратной
							 матрицы к первой матрице*/
	output_matrix(m3);
	printf("\n\n");
		
	m3 = reverse(m2);/*вызываем функцию по обнаружению обратной
							матрицы ко второй матрице*/
	output_matrix(m3);
	
	
	FILE *array_output = fopen("array_output.txt", "w");
	m3 = summ(m1, m2);//вызываем функцию суммирования
	output_matrix_in_file(array_output, m3);
	fprintf (array_output, "\n\n");
		
	m3 = multiply(m1, m2);//вызываем функцию умножения
	output_matrix_in_file(array_output, m3);
	fprintf (array_output, "\n\n");
		
	fprintf (array_output,"\n\ndet1 = %f\n\ndet2 = %f\n\n",\
			 det(m1), det(m2));
	/*вызываем функцию по обнаружению определителя и сразу же
	  записываем его значение в файл*/
	fprintf (array_output, "\n\n");
		
	m3 = reverse(m1);/*вызываем функцию по обнаружению обратной
							 матрицы к первой матрице*/
	output_matrix_in_file(array_output, m3);
	fprintf (array_output, "\n\n");
		
	m3 = reverse(m2);/*вызываем функцию по обнаружению обратной
							 матрицы ко второй матрице*/
	output_matrix_in_file(array_output, m3);
	fprintf (array_output, "\n\n");
	fclose(array_output);
	return 0;
}
