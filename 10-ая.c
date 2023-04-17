#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
	float *Mas;
} Matrix;

Matrix summ (Matrix Mas1, Matrix Mas2, Matrix result, int N, int M) {//функция по сложению
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result.Mas[i * N + j] = Mas1.Mas[i * N + j] + Mas2.Mas[i * N + j];
		}
	}
	return result;
}

Matrix multiply (Matrix Mas1, Matrix Mas2, Matrix result, int N, int M) {//функция по умножению
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result.Mas[i * N + j] = 0;
			for (int k = 0; k < M; k++) {
				result.Mas[i * N + j] += Mas1.Mas[i * N + k] * Mas2.Mas[k * M + j];	 
			}
		}
	}
	return result;
}
        
 float Det (Matrix Mas1, int number) { //функция по поиску определителя матрицы
	if (number == 1)
		return Mas1.Mas[0];
	else if (number == 2)
		return (Mas1.Mas[0] * Mas1.Mas[3] - Mas1.Mas[1] * Mas1.Mas[2]);
    else {
		float det = 0;
		int strikethrough_column;
		Matrix D_Mas;
		D_Mas.Mas = (float*) malloc((number - 1) * (number - 1) * sizeof(float));
        for (int i = 0; i < number; i++) {
            for (int j = 1; j < number; j++) {
                strikethrough_column = 0;
                for (int k = 0; k < number; k++) {
					if (k == i){
						continue;
					}
					D_Mas.Mas[(j-1) * (number - 1) + strikethrough_column] = Mas1.Mas[j * number + k];
                    strikethrough_column++;
                }
            }
            det += pow(-1, (i + 2)) * Mas1.Mas[0 * number + i] * Det(D_Mas, number - 1);
        }
        free(D_Mas.Mas);
        return det;
	}
}

Matrix reverse (Matrix Mas1, Matrix result, int number) {//функция по поиску обратной матрицы
	int n, m;
	if (number == 1) {
		result.Mas[0] = 1 / Det(Mas1, number);
	}
	else {
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				Matrix D_Mas;
				D_Mas.Mas = (float*) malloc((number - 1) * (number - 1) * sizeof(float));
				n = 0;
				for (int k = 0; k < number; k++) {
					m = 0;
					if (k == i) {
						continue;
					}
					for (int f = 0; f < number; f++) {
						if (f == j) {
							continue;
						}
						D_Mas.Mas[n * (number - 1) + m] = Mas1.Mas[k * number + f];
						m++;
					}
					n++;
				}
				result.Mas[j * number + i] = (Det(D_Mas, number - 1) * pow(-1, (i + j + 2))) / Det(Mas1, number);
				free(D_Mas.Mas);
			}
		}
	}
	return result;
}

Matrix enter_matrix_by_file (FILE *array_input, Matrix Mas1, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf ("\nВводится %d %d элемент первой матрицы\n", i, j);
			fscanf (array_input,"%f", &Mas1.Mas[i * N + j]); 
			printf ("%f", Mas1.Mas[i * N + j]);
		}
	}
	return Mas1;
}

void output_matrix (Matrix Mas1, int N, int M) {
	for (int i = 0; i < N; i++) {
		printf ("\n");
		for (int j = 0; j < M; j++) {
			printf ("%f ", Mas1.Mas[i * N + j]);
		}
	}
}

Matrix enter_matrix_by_random (Matrix Mas1, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf ("\nВведите %d %d элемент первой матрицы\n", i, j);
			Mas1.Mas[i * N + j] = rand() % 10;
			printf ("%f", Mas1.Mas[i * N + j]);
		}
	}
	return Mas1;
}

void output_matrix_in_file (FILE *array_output, Matrix Mas1, int N, int M) {
	for (int i = 0; i < N; i++) {
		fprintf (array_output,"\n");
		for (int j = 0; j < M; j++) {
			fprintf (array_output, "%f ", Mas1.Mas[i * N + j]);
		}
	}
}

int main()
{
	int path,//"path" - переменная по выбору способа считывания и записи элементов матрицы
	N, M;
	printf ("Enter the dimensions of the matrix, first the number of\
 rows (N) and then the number of columns (M)\n");
	scanf ("%d %d", &N, &M);
	Matrix Mas1;
	Matrix Mas2;
	Matrix Mas3;
	
	Mas1.Mas = (float*) malloc(N * M * sizeof(float));
	Mas2.Mas = (float*) malloc(N * M * sizeof(float));
	Mas3.Mas = (float*) malloc(N * M * sizeof(float));
	printf ("Enter '0'(random) if you want to enter values by the\
 random or enter '1'(file) if you want to read from a file\n");
	scanf ("%d", &path);
	
	if (path==1) {
		FILE *array_input1 = fopen("array_input1.txt", "r");
		FILE *array_input2 = fopen("array_input2.txt", "r");
		enter_matrix_by_file(array_input1, Mas1, N, M);
		printf ("\n\n");
		enter_matrix_by_file(array_input2, Mas2, N, M);
		fclose(array_input1);
		fclose(array_input2);
	} else if (path==0){
		Mas1 = enter_matrix_by_random(Mas1, N, M);
		printf ("\n\n\n");
		Mas2 = enter_matrix_by_random(Mas2, N, M);
	}else {
		printf ("What do you want?");
		return 0;
	}
	
	printf ("\n\n");
	printf ("This is the first matrix");
	output_matrix(Mas1, N, M);
	
	printf ("\n\n");
	printf ("This is the second matrix");
	output_matrix(Mas2, N, M);
	
	
	printf("\n\n");
	Mas3 = summ(Mas1, Mas2, Mas3, N, M);//вызываем функцию суммирования
	printf ("This is the sum matrix");
	output_matrix(Mas3, N, M);
	
	printf("\n\n");
	Mas3 = multiply(Mas1, Mas2, Mas3, N, M);//вызываем функцию умножения
	printf ("This is the multiply matrix");
	output_matrix(Mas3, N, M);
		
	if (N == M) {
		printf ("\n\ndet1 = %f\n\ndet2 = %f\n\n", Det(Mas1, N), Det(Mas2, N));
		//вызываем функцию по обнаружению определителя и сразу же выводим его значение
		
		Mas3 = reverse(Mas1, Mas3, N);//вызываем функцию по обнаружению обратной матрицы к первой матрице
		printf ("This is the first reverse matrix");
		output_matrix(Mas3, N, M);
		printf("\n\n");
			
		Mas3 = reverse(Mas2, Mas3, N);//вызываем функцию по обнаружению обратной матрицы ко второй матрице
		printf ("This is the second reverse matrix");
		output_matrix(Mas3, N, M);
	}else
		printf ("\n\nSince the matrix is not square, it will not be \
 possible to calculate its determinant and therefore the inverse matrix\
 does not exist");
	
	
	FILE *array_output = fopen("array_output.txt", "w");
	summ(Mas1, Mas2, Mas3, N, M);//вызываем функцию суммирования
	output_matrix_in_file(array_output, Mas3, N, M);
	fprintf (array_output, "\n\n");
		
	multiply(Mas1, Mas2, Mas3, N, M);//вызываем функцию умножения
	output_matrix_in_file(array_output, Mas3, N, M);
	fprintf (array_output, "\n\n");
		
	if (N == M) {
		fprintf (array_output,"\n\ndet1 = %f\n\ndet2 = %f\n\n", Det(Mas1, N), Det(Mas2, N));
		//вызываем функцию по обнаружению определителя и сразу же записываем его значение в файл
		fprintf (array_output, "\n\n");
			
		reverse(Mas1, Mas3, N);//вызываем функцию по обнаружению обратной матрицы к первой матрице
		output_matrix_in_file(array_output, Mas3, N, M);
		fprintf (array_output, "\n\n");
			
		reverse(Mas2, Mas3, N);//вызываем функцию по обнаружению обратной матрицы ко второй матрице
		output_matrix_in_file(array_output, Mas3, N, M);
		fprintf (array_output, "\n\n");
		fclose(array_output);
	}else
		printf ("\n\nSince the matrix is not square, it will not be \
 possible to calculate its determinant and therefore the inverse matrix\
 does not exist");
	free(Mas1.Mas);
	free(Mas2.Mas);
	free(Mas3.Mas);
	return 0;
}
