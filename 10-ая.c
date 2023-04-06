#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
	int N;
	int M;
	float *Mas1;
	float *Mas2;
	float *Mas3;
} Matrix;

Matrix mat;

void summ (float Mas3[], float Mas1[], float Mas2[]) {//функция по сложению
	for (int i = 0; i < mat.N; i++) {
		for (int j = 0; j < mat.M; j++) {
			Mas3[i * mat.N + j] = Mas1[i * mat.N + j] + Mas2[i * mat.N + j];
		}
	}
}

void product (float Mas3[], float Mas1[], float Mas2[]) {//функция по умножению
	for (int i = 0; i < mat.N; i++) {
		for (int j = 0; j < mat.M; j++) {
			Mas3[i * mat.N + j] = 0;
			for (int k = 0; k < mat.M; k++) {
				Mas3[i * mat.N + j] = Mas1[i * mat.N + k] * Mas2[k * mat.M + j] + Mas3[i * mat.N + j];	 
			}
		}
	}
}
        
 float Det (float Mas[], int number) { //функция по поиску определителя матрицы
	if (number == 1)
		return Mas[0];
	else if (number == 2)
		return (Mas[0] * Mas[3] - Mas[1] * Mas[2]);
    else {
		float d = 0;
		int m;
		float *D_Mas = (float*) malloc((number - 1) * (number - 1) * sizeof(float));
        for (int i = 0; i < number; i++) {
            for (int j = 1; j < number; j++) {
                m = 0;
                for (int k = 0; k < number; k++) {
					if (k == i){
						continue;
					}
					D_Mas[(j-1) * (number - 1) + m] = Mas[j * number + k];
                    m++;
                }
            }
            d += pow(-1, (i + 2)) * Mas[0 * number + i] * Det(D_Mas, number - 1);
        }
        free(D_Mas);
        return d;
	}
}

void reverse (float* Mas1, float* Mas2, int number) {//функция по поиску обратной матрицы
	int n, m;
	if (number == 1) {
		Mas2[0] = 1 / Det(Mas1, number);
	}
	else {
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				float *D_Mas = (float*) malloc((number - 1) * (number - 1) * sizeof(float));
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
						D_Mas[n * (number - 1) + m] = Mas1[k * number + f];
						m++;
					}
					n++;
				}
				Mas2[j * number + i] = (Det(D_Mas, number - 1) * pow(-1, (i + j + 2))) / Det(Mas1, number);
				free(D_Mas);
			}
		}
	}
}

float enter_matrix_by_file (FILE *array_input, float Mas[]) {
	for (int i = 0; i < mat.N; i++) {
		for (int j = 0; j < mat.M; j++) {
			printf ("\nВводится %d %d элемент первой матрицы\n", i, j);
			fscanf (array_input,"%f", &Mas[i * mat.N + j]); 
			printf ("%f", Mas[i * mat.N + j]);
		}
	}
	return *Mas;
}

void output_matrix (float Mas[]) {
	for (int i = 0; i < mat.N; i++) {
		printf ("\n");
		for (int j = 0; j < mat.M; j++) {
			printf ("%f ", Mas[i * mat.N + j]);
		}
	}
}

float enter_matrix_by_random (float Mas[]) {
	for (int i = 0; i < mat.N; i++) {
		for (int j = 0; j < mat.M; j++) {
			printf ("\nВведите %d %d элемент первой матрицы\n", i, j);
			Mas[i * mat.N + j] = rand() % 10;
			printf ("%f", Mas[i * mat.N + j]);
		}
	}
	return *Mas;
}

void output_matrix_in_file (FILE *array_output, float Mas[]) {
	for (int i = 0; i < mat.N; i++) {
		fprintf (array_output,"\n");
		for (int j = 0; j < mat.M; j++) {
			fprintf (array_output, "%f ", Mas[i * mat.N + j]);
		}
	}
}

int main()
{
	int path;//"path" - переменная по выбору способа считывания и записи элементов матрицы
	printf ("Enter the dimensions of the matrix, first the number of\
 rows (N) and then the number of columns (M)\n");
	scanf ("%d %d", &mat.N, &mat.M);
	mat.Mas1 = (float*) malloc(mat.N * mat.M * sizeof(float));
	mat.Mas2 = (float*) malloc(mat.N * mat.M * sizeof(float));
	mat.Mas3 = (float*) malloc(mat.N * mat.M * sizeof(float));
	printf ("Enter '0'(self) if you want to enter values from the\
 terminal or enter '1'(file) if you want to read from a file\n");
	scanf ("%d", &path);
	
	if (path==1) {
		FILE *array_input1 = fopen("/home/hello/Рабочий стол/Основы\
 программирования/array_input1.txt", "r");
		FILE *array_input2 = fopen("/home/hello/Рабочий стол/Основы\
 программирования/array_input2.txt", "r");
		enter_matrix_by_file(array_input1, mat.Mas1);
		printf ("\n\n");
		enter_matrix_by_file(array_input2, mat.Mas2);
		fclose(array_input1);
		fclose(array_input2);
	} else if (path==0){
		enter_matrix_by_random(mat.Mas1);
		printf ("\n\n\n");
		enter_matrix_by_random(mat.Mas2);
	}else {
		printf ("What do you want?");
		return (69);
	}
	
	printf ("\n\n");
	printf ("This is the first matrix");
	output_matrix(mat.Mas1);
	
	printf ("\n\n\n");
	printf ("This is the second matrix");
	output_matrix(mat.Mas2);
	
	
	printf("\n\n");
	summ(mat.Mas3, mat.Mas1, mat.Mas2);//вызываем функцию суммирования
	printf ("This is the sum matrix");
	output_matrix(mat.Mas3);
	
	printf("\n\n");
	product(mat.Mas3, mat.Mas1, mat.Mas2);//вызываем функцию умножения
	printf ("This is the product matrix");
	output_matrix(mat.Mas3);
		
	if (mat.N == mat.M) {
		printf ("\n\ndet1 = %f\n\ndet2 = %f\n\n", Det(mat.Mas1, mat.N), Det(mat.Mas2, mat.N)), //Det(mat.Mas2, mat.N));
		//вызываем функцию по обнаружению определителя и сразу же выводим его значение
		
		reverse(mat.Mas1, mat.Mas3, mat.N);//вызываем функцию по обнаружению обратной матрицы к первой матрице
		printf ("This is the first reverse matrix");
		output_matrix(mat.Mas3);
		printf("\n\n");
			
		reverse(mat.Mas2, mat.Mas3, mat.N);//вызываем функцию по обнаружению обратной матрицы ко второй матрице
		printf ("This is the second reverse matrix");
		output_matrix(mat.Mas3);
	}else
		printf ("\n\nSince the matrix is not square, it will not be \
 possible to calculate its determinant and therefore the inverse matrix\
 does not exist");
	
	
	FILE *array_output = fopen("/home/hello/Рабочий стол/Основы\
 программирования/array_output.txt", "w");
	summ(mat.Mas3, mat.Mas1, mat.Mas2);//вызываем функцию суммирования
	output_matrix_in_file(array_output, mat.Mas3);
	fprintf (array_output, "\n\n");
		
	product(mat.Mas3, mat.Mas1, mat.Mas2);//вызываем функцию умножения
	output_matrix_in_file(array_output, mat.Mas3);
	fprintf (array_output, "\n\n");
		
	if (mat.N == mat.M) {
		fprintf (array_output,"\n\ndet1 = %f\n\ndet2 = %f\n\n", Det(mat.Mas1, mat.N), Det(mat.Mas2, mat.N));
		//вызываем функцию по обнаружению определителя и сразу же записываем его значение в файл
		fprintf (array_output, "\n\n");
			
		reverse(mat.Mas3, mat.Mas1, mat.N);//вызываем функцию по обнаружению обратной матрицы к первой матрице
		output_matrix_in_file(array_output, mat.Mas3);
		fprintf (array_output, "\n\n");
			
		reverse(mat.Mas3, mat.Mas2, mat.N);//вызываем функцию по обнаружению обратной матрицы ко второй матрице
		output_matrix_in_file(array_output, mat.Mas3);
		fprintf (array_output, "\n\n");
		fclose(array_output);
	}else
		printf ("\n\nSince the matrix is not square, it will not be \
 possible to calculate its determinant and therefore the inverse matrix\
 does not exist");
	free(mat.Mas3);
	free(mat.Mas1);
	free(mat.Mas2);
	return 0;
}


