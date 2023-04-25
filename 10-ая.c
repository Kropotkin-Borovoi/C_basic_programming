#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
	float *Mas;
	int length;
	int width;
} Matrix;

void initMatrix (Matrix *Mas1, int length, int width) {
	Mas1->length = length;
	Mas1->width = width;
}

Matrix summ (Matrix Mas1, Matrix Mas2) {//функция по сложению
	Matrix result;
	initMatrix (&result, Mas1.length, Mas1.width);
	result.Mas = (float*) malloc(result.length * result.width * sizeof(float));

	for (int i = 0; i < result.length; i++) {
		for (int j = 0; j < result.width; j++) {
			result.Mas[i * result.length + j] = Mas1.Mas[i * Mas1.length + j] + Mas2.Mas[i * Mas2.length + j];
		}
	}
	return result;
}

Matrix multiply (Matrix Mas1, Matrix Mas2) {//функция по умножению
	Matrix result;
	initMatrix (&result, Mas1.length, Mas1.width);
	result.Mas = (float*) malloc(result.length * result.width * sizeof(float));
	
	for (int i = 0; i < result.length; i++) {
		for (int j = 0; j < result.width; j++) {
			result.Mas[i * result.length + j] = 0;
			for (int k = 0; k < result.width; k++) {
				result.Mas[i * result.length + j] += Mas1.Mas[i * Mas1.length + k] * Mas2.Mas[k * Mas2.width + j];	 
			}
		}
	}
	return result;
}
        
 float Det (Matrix Mas1) { //функция по поиску определителя матрицы
	if (Mas1.length == 1)
		return Mas1.Mas[0];
	else if (Mas1.length == 2)
		return (Mas1.Mas[0] * Mas1.Mas[3] - Mas1.Mas[1] * Mas1.Mas[2]);
    else {
		float det = 0;
		int strikethrough_column;
		Matrix D_Mas;
		initMatrix (&D_Mas, (Mas1.length - 1), (Mas1.width - 1));
		D_Mas.Mas = (float*) malloc(D_Mas.length * D_Mas.length * sizeof(float));
        for (int i = 0; i < Mas1.length; i++) {
            for (int j = 1; j < Mas1.length; j++) {
                strikethrough_column = 0;
                for (int k = 0; k < Mas1.length; k++) {
					if (k == i){
						continue;
					}
					D_Mas.Mas[(j-1) * D_Mas.length + strikethrough_column] = Mas1.Mas[j * Mas1.length + k];
                    strikethrough_column++;
                }
            }
            det += pow(-1, (i + 2)) * Mas1.Mas[i] * Det(D_Mas);
        }
        free(D_Mas.Mas);
        return det;
	}
}

Matrix reverse (Matrix Mas1) {//функция по поиску обратной матрицы
	Matrix result;
	initMatrix (&result, Mas1.length, Mas1.width);
	result.Mas = (float*) malloc(result.length * result.width * sizeof(float));
	
	int n, m;
	if (Mas1.length == 1) {
		result.Mas[0] = 1 / Det(Mas1);
	}
	else {
		for (int i = 0; i < Mas1.length; i++) {
			for (int j = 0; j < Mas1.length; j++) {
				Matrix D_Mas;
				initMatrix (&D_Mas, (Mas1.length - 1), (Mas1.width - 1));
				D_Mas.Mas = (float*) malloc(D_Mas.length * D_Mas.length * sizeof(float));
				n = 0;
				for (int k = 0; k < Mas1.length; k++) {
					m = 0;
					if (k == i) {
						continue;
					}
					for (int f = 0; f < Mas1.length; f++) {
						if (f == j) {
							continue;
						}
						D_Mas.Mas[n * D_Mas.length + m] = Mas1.Mas[k * Mas1.length + f];
						m++;
					}
					n++;
				}
				result.Mas[j * Mas1.length + i] = (Det(D_Mas) * pow(-1, (i + j + 2))) / Det(Mas1);
				free(D_Mas.Mas);
			}
		}
	}
	return result;
}

Matrix ReadMatrixFromFile (FILE *array_input, Matrix Mas1) {
	for (int i = 0; i < Mas1.length; i++) {
		for (int j = 0; j < Mas1.width; j++) {
			printf ("\nВводится %d %d элемент первой матрицы\n", i, j);
			fscanf (array_input,"%f", &Mas1.Mas[i * Mas1.length + j]); 
			printf ("%f", Mas1.Mas[i * Mas1.length + j]);
		}
	}
	return Mas1;
}

void PrintMatrix (Matrix Mas1) {
	for (int i = 0; i < Mas1.length; i++) {
		printf ("\n");
		for (int j = 0; j < Mas1.width; j++) {
			printf ("%f ", Mas1.Mas[i * Mas1.length + j]);
		}
	}
}

Matrix enter_matrix_by_random (Matrix Mas1) {
	for (int i = 0; i < Mas1.length; i++) {
		for (int j = 0; j < Mas1.width; j++) {
			printf ("\nВведите %d %d элемент первой матрицы\n", i, j);
			Mas1.Mas[i * Mas1.length + j] = rand() % 10;
			printf ("%f", Mas1.Mas[i * Mas1.length + j]);
		}
	}
	return Mas1;
}

void WriteMatrix (FILE *array_output, Matrix Mas1) {
	for (int i = 0; i < Mas1.length; i++) {
		fprintf (array_output,"\n");
		for (int j = 0; j < Mas1.width; j++) {
			fprintf (array_output, "%f ", Mas1.Mas[i * Mas1.length + j]);
		}
	}
}

void test_Mas_summ () {
	Matrix Mas1;
	Matrix Mas2;
	Matrix Mas_summ_expected;
	
	Mas1.Mas = (float*) malloc(3 * 3 * sizeof(float));
	Mas2.Mas = (float*) malloc(3 * 3 * sizeof(float));
	Mas_summ_expected.Mas = (float*) malloc(3 * 3 * sizeof(float));
	
	float Mas1_data[9] = {1, 2, 3, 7, 5, 6, 7, 8, 9};  
	for (int i = 0; i < 9; i++) {
		Mas1.Mas[i] = Mas1_data[i]; 
	}
	
	float Mas2_data[9] = {3, 4, 7, 2, 8, 9, 0, 4, 1};  
	for (int i = 0; i < 9; i++) {
		Mas2.Mas[i] = Mas2_data[i]; 
	}
	 
	float Mas_summ_data[9] = {4, 6, 10, 9, 13, 15, 7, 12, 10};  
	for (int i = 0; i < 9; i++) {
		Mas_summ_expected.Mas[i] = Mas_summ_data[i]; 
	}
	
	initMatrix(&Mas1, 3, 3);
	initMatrix(&Mas2, 3, 3);
	
	Matrix Mas_summ_gotten;
	Mas_summ_gotten.Mas = (float*) malloc(3 * 3 * sizeof(float));
	Mas_summ_gotten = summ(Mas1, Mas2);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(fabs(Mas_summ_expected.Mas[i * Mas1.length + j] - Mas_summ_gotten.Mas[i * Mas1.length + j]) > pow(10, -4)) {
				printf ("\nMas_summ_expected.Mas[%d] == %f\nMas_summ_gotten.Mas[%d] == %f", i * Mas1.length + j, Mas_summ_expected.Mas[i * Mas1.length + j], i * Mas1.length + j, Mas_summ_gotten.Mas[i * Mas1.length + j]);
				printf("error");
				exit(1);
			}
		}
	}
}

void test_Mas_multiply (){
	Matrix Mas1;
	Matrix Mas2;
	Matrix Mas_multiply_expected;
	
	Mas1.Mas = (float*) malloc(3 * 3 * sizeof(float));
	Mas2.Mas = (float*) malloc(3 * 3 * sizeof(float));
	Mas_multiply_expected.Mas = (float*) malloc(3 * 3 * sizeof(float));
	
	float Mas1_data[9] = {1, 2, 3, 7, 5, 6, 7, 8, 9};  
	for (int i = 0; i < 9; i++) {
		Mas1.Mas[i] = Mas1_data[i]; 
	}
	
	float Mas2_data[9] = {3, 4, 7, 2, 8, 9, 0, 4, 1};  
	for (int i = 0; i < 9; i++) {
		Mas2.Mas[i] = Mas2_data[i]; 
	}
	
	float Mas_multiply_data[9] = {7, 32, 28, 31, 92, 100, 37, 128, 130};  
	for (int i = 0; i < 9; i++) {
		Mas_multiply_expected.Mas[i] = Mas_multiply_data[i]; 
	}

	initMatrix(&Mas1, 3, 3);
	initMatrix(&Mas2, 3, 3);
	
	Matrix Mas_multiply_gotten;
	Mas_multiply_gotten.Mas = (float*) malloc(3 * 3 * sizeof(float));
	Mas_multiply_gotten = multiply(Mas1, Mas2);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(fabs(Mas_multiply_expected.Mas[i * Mas1.length + j] - Mas_multiply_gotten.Mas[i * Mas1.length + j]) > pow(10, -4)) {
				printf ("\nMas_multiply_expected.Mas[%d] == %f\nMas_multiply_gotten.Mas[%d] == %f", i * Mas1.length + j, Mas_multiply_expected.Mas[i * Mas1.length + j], i * Mas1.length + j, Mas_multiply_gotten.Mas[i * Mas1.length + j]);
				printf("error");
				exit(1);
			}
		}
	}
}

void test_Mas1_reverse (){
	Matrix Mas1;
	Matrix Mas1_reverse_expected;
	
	Mas1.Mas = (float*) malloc(3 * 3 * sizeof(float));
	Mas1_reverse_expected.Mas = (float*) malloc(3 * 3 * sizeof(float));
	
	float Mas1_data[9] = {1, 2, 3, 7, 5, 6, 7, 8, 9};  
	for (int i = 0; i < 9; i++) {
		Mas1.Mas[i] = Mas1_data[i]; 
	}
	
	float Mas1_reverse_data[9] = {-0.1666, 0.3333, -0.1666, -1.1666, -0.6666, 0.8333, 1.1666, 0.3333, -0.5};  
	for (int i = 0; i < 9; i++) {
		Mas1_reverse_expected.Mas[i] = Mas1_reverse_data[i]; 
	}

	initMatrix(&Mas1, 3, 3);
	
	Matrix Mas1_reverse_gotten;
	Mas1_reverse_gotten.Mas = (float*) malloc(3 * 3 * sizeof(float));
	Mas1_reverse_gotten = reverse(Mas1);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(fabs(Mas1_reverse_expected.Mas[i * Mas1.length + j] - Mas1_reverse_gotten.Mas[i * Mas1.length + j]) > pow(10, -4)) {
				printf ("\nMas1_reverse_expected.Mas[%d] == %f\nMas1_reverse_gotten.Mas[%d] == %f", i * Mas1.length + j, Mas1_reverse_expected.Mas[i * Mas1.length + j], i * Mas1.length + j, Mas1_reverse_gotten.Mas[i * Mas1.length + j]);
				printf("error");
				exit(1);
			}
		}
	}
}

void test_Mas2_reverse (){
	Matrix Mas2;
	Matrix Mas2_reverse_expected;
	
	Mas2.Mas = (float*) malloc(3 * 3 * sizeof(float));
	Mas2_reverse_expected.Mas = (float*) malloc(3 * 3 * sizeof(float));
	
	float Mas2_data[9] = {3, 4, 7, 2, 8, 9, 0, 4, 1};  
	for (int i = 0; i < 9; i++) {
		Mas2.Mas[i] = Mas2_data[i]; 
	}
	
	float Mas2_reverse_data[9] = {0.7777, -0.6666, 0.5555, 0.0555, -0.0833, 0.3611, -0.2222, 0.3333, -0.4444};  
	for (int i = 0; i < 9; i++) {
		Mas2_reverse_expected.Mas[i] = Mas2_reverse_data[i]; 
	}

	initMatrix(&Mas2, 3, 3);
	
	Matrix Mas2_reverse_gotten;
	Mas2_reverse_gotten.Mas = (float*) malloc(3 * 3 * sizeof(float));
	Mas2_reverse_gotten = reverse(Mas2);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(fabs(Mas2_reverse_expected.Mas[i * Mas2.length + j] - Mas2_reverse_gotten.Mas[i * Mas2.length + j]) > pow(10, -4)) {
				printf ("\nMas2_reverse_expected.Mas[%d] == %f\nMas2_reverse_gotten.Mas[%d] == %f", i * Mas2.length + j, Mas2_reverse_expected.Mas[i * Mas2.length + j], i * Mas2.length + j, Mas2_reverse_gotten.Mas[i * Mas2.length + j]);
				printf("error");
				exit(1);
			}
		}
	}
}

void test_Mas1_det(){
	Matrix Mas1;
	
	Mas1.Mas = (float*) malloc(3 * 3 * sizeof(float));
	
	float Mas1_data[9] = {1, 2, 3, 7, 5, 6, 7, 8, 9};  
	for (int i = 0; i < 9; i++) {
		Mas1.Mas[i] = Mas1_data[i]; 
	}
	
	float det1_expected = 18;
	
	initMatrix(&Mas1, 3, 3);
	
	float det1_gotten = Det(Mas1);
	
	if (fabs(det1_expected - det1_gotten) > pow(10, -4)) { 
		printf ("\ndet1_expected == %f\ndet1_gotten == %f", det1_expected, det1_gotten);
		printf("error");
		exit(1);
	}
}

void test_Mas2_det(){
	Matrix Mas2;
	
	Mas2.Mas = (float*) malloc(3 * 3 * sizeof(float));
	
	float Mas2_data[9] = {3, 4, 7, 2, 8, 9, 0, 4, 1};  
	for (int i = 0; i < 9; i++) {
		Mas2.Mas[i] = Mas2_data[i]; 
	}
	
	float det2_expected = -36;
	
	initMatrix(&Mas2, 3, 3);
	
	float det2_gotten = Det(Mas2);
	
	if (fabs(det2_expected - det2_gotten) > pow(10, -4)) { 
		printf ("\ndet2_expected == %f\ndet2_gotten == %f", det2_expected, det2_gotten);
		printf("error");
		exit(1);
	}
}


int main()
{
	test_Mas_summ();
	test_Mas_multiply();
	test_Mas1_reverse();
	test_Mas2_reverse();
	test_Mas1_det();
	test_Mas2_det();
	
	int path,//"path" - переменная по выбору способа считывания и записи элементов матрицы
	length, width;
	printf("Enter the dimensions of the matrix, first the number of\
			 rows (length) and then the number of columns (width)\n");
	scanf("%d %d", &length, &width);
	Matrix Mas1;
	Matrix Mas2;
	Matrix Mas3;
	
	Mas1.Mas = (float*) malloc(length * width * sizeof(float));
	Mas2.Mas = (float*) malloc(length * width * sizeof(float));
	Mas3.Mas = (float*) malloc(length * width * sizeof(float));
	
	initMatrix (&Mas1, length, width);
	initMatrix (&Mas2, length, width);
	initMatrix (&Mas3, length, width);
	
	printf("Enter '0'(random) if you want to enter values by the\
			 random or enter '1'(file) if you want to read from a \
			 file\n");
	scanf("%d", &path);
	
	if (path==1) {
		FILE *array_input1 = fopen("array_input1.txt", "r");
		FILE *array_input2 = fopen("array_input2.txt", "r");
		ReadMatrixFromFile(array_input1, Mas1);
		printf ("\n\n");
		ReadMatrixFromFile(array_input2, Mas2);
		fclose(array_input1);
		fclose(array_input2);
	} else if (path==0){
		Mas1 = enter_matrix_by_random(Mas1);
		printf ("\n\n\n");
		Mas2 = enter_matrix_by_random(Mas2);
	}else {
		printf("What do you want?");
		return 0;
	}
	
	printf("\n\n");
	printf("This is the first matrix");
	PrintMatrix(Mas1);
	
	printf("\n\n");
	printf("This is the second matrix");
	PrintMatrix(Mas2);
	
	
	printf("\n\n");
	Mas3 = summ(Mas1, Mas2);//вызываем функцию суммирования
	printf("This is the summ matrix");
	PrintMatrix(Mas3);
	
	printf("\n\n");
	Mas3 = multiply(Mas1, Mas2);//вызываем функцию умножения
	printf("This is the multiply matrix");
	PrintMatrix(Mas3);
		
	if (length == width) {		
		printf("\n\ndet1 = %f\n\ndet2 = %f\n\n", Det(Mas1), Det(Mas2));
		//вызываем функцию по обнаружению определителя и сразу же выводим его значение
		
		if (Det(Mas1) != 0) {
			Mas3 = reverse(Mas1);//вызываем функцию по обнаружению обратной матрицы к 					   первой матрице
			printf("This is the first reverse matrix");
			PrintMatrix(Mas3);
			printf("\n\n");
		}
		
		if (Det(Mas2) != 0) {
			Mas3 = reverse(Mas2);//вызываем функцию по обнаружению обратной матрицы ко второй матрице
			printf("This is the second reverse matrix");
			PrintMatrix(Mas3);
		}
			
		
	}else
		printf("\n\nSince the matrix is not square, it will not be \
				 possible to calculate its determinant and therefore\
				 the inverse matrix does not exist");
	
	
	FILE *array_output = fopen("array_output.txt", "w");
	summ(Mas1, Mas2);//вызываем функцию суммирования
	WriteMatrix(array_output, Mas3);
	fprintf(array_output, "\n\n");
		
	multiply(Mas1, Mas2);//вызываем функцию умножения
	WriteMatrix(array_output, Mas3);
	fprintf(array_output, "\n\n");
		
	if (length == width) {
		fprintf(array_output,"\n\ndet1 = %f\n\ndet2 = %f\n\n", Det(Mas1), Det(Mas2));
		//вызываем функцию по обнаружению определителя и сразу же записываем его значение в файл
		fprintf(array_output, "\n\n");
		
		if (Det(Mas1) != 0) {
			reverse(Mas1);//вызываем функцию по обнаружению обратной матрицы к первой матрице
			WriteMatrix(array_output, Mas3);
			fprintf(array_output, "\n\n");
		}
		
		if (Det(Mas2) != 0) {
			reverse(Mas2);//вызываем функцию по обнаружению обратной матрицы ко второй матрице
			WriteMatrix(array_output, Mas3);
			fprintf(array_output, "\n\n");
			fclose(array_output);
		}
		
	} else
		printf("\n\nSince the matrix is not square, it will not be \
				 possible to calculate its determinant and therefore \
				 the inverse matrix does not exist");
	free(Mas1.Mas);
	free(Mas2.Mas);
	free(Mas3.Mas);
	return 0;
}
