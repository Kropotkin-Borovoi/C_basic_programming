#include <stdio.h>
#include <math.h>
float Mas3 [3][3];//создаём третий массив, который будет результатом наших операций, в виде глобальной переменоой

void summ (float Mas1[3][3], float Mas2[3][3]) {//функция по сложению
	int i, j;
	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			Mas3[i][j]=Mas1[i][j]+Mas2[i][j];//берём элемент первого массива, берём элемент того же номера, но уже из второго массива, складываем и записываем в третий массив 
		}
	}
}

void product (float Mas1[3][3], float Mas2[3][3]) {//функция по умножению
	int i, j;
	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			Mas3[i][j]=Mas1[i][j]*Mas2[i][j];//берём элемент первого массива, берём элемент того же номера, но уже из второго массива, перемножаем и записываем в третий массив 
		}
	}	
}

float det (float Mas3[3][3]) {//функция по поиску определителя матрицы
	float det;
	det=Mas3[0][0]*Mas3[1][1]*Mas3[2][2]+\
	Mas3[0][1]*Mas3[1][2]*Mas3[2][0]+\
	Mas3[0][2]*Mas3[1][0]*Mas3[2][1]-\
	Mas3[0][2]*Mas3[1][1]*Mas3[2][0]-\
	Mas3[0][0]*Mas3[1][2]*Mas3[2][1]-\
	Mas3[0][1]*Mas3[1][0]*Mas3[2][2];
	return (det);
}

void reverse (float Mas1[3][3]) {//функция по поиску обратной матрицы
			Mas3[0][0] = (Mas1[1][1]*Mas1[2][2]-Mas1[2][1]*Mas1[1][2])/det(Mas1);
			Mas3[0][1] = (Mas1[0][1]*Mas1[2][2]-Mas1[2][1]*Mas1[0][2])/det(Mas1);
			Mas3[0][2] = (Mas1[0][1]*Mas1[1][2]-Mas1[1][1]*Mas1[0][2])/det(Mas1);
			Mas3[1][0] = (Mas1[1][0]*Mas1[2][2]-Mas1[2][0]*Mas1[1][2])/det(Mas1);
			Mas3[1][1] = (Mas1[0][0]*Mas1[2][2]-Mas1[2][0]*Mas1[0][2])/det(Mas1);
			Mas3[1][2] = (Mas1[0][0]*Mas1[1][2]-Mas1[1][0]*Mas1[0][2])/det(Mas1);
			Mas3[2][0] = (Mas1[1][0]*Mas1[2][1]-Mas1[2][0]*Mas1[1][1])/det(Mas1);
			Mas3[2][1] = (Mas1[0][0]*Mas1[2][1]-Mas1[2][0]*Mas1[0][1])/det(Mas1);
			Mas3[2][2] = (Mas1[0][0]*Mas1[1][1]-Mas1[1][0]*Mas1[0][1])/det(Mas1);
}

int main()
{
	int i, j, path;//"path" - переменная по выбору способа считывания и записи элементов матрицы
	float Mas1 [3][3], Mas2 [3][3];//создаём два массива
	printf ("Enter '0'(self) if you want to enter values from the terminal or enter '1'(file) if you want to read from a file\n");//"приветствие"
	scanf ("%d", &path);
	if (path==1) {
		FILE *array_input1 = fopen("/home/hello/Рабочий стол/Основы программирования/array_input1.txt", "r");
		FILE *array_input2 = fopen("/home/hello/Рабочий стол/Основы программирования/array_input2.txt", "r");
		for (i=0;i<3;i++) {//считывает с первого файла
			for (j=0;j<3;j++) {
				printf ("\nВводится %d %d элемент первой матрицы\n", i, j);
				fscanf(array_input1,"%f", &Mas1[i][j]); 
				printf("%f", Mas1[i][j]);
			}
		}
		printf ("\n\n");
		for (i=0;i<3;i++) {//считывает со второго файла
			for (j=0;j<3;j++) {
				printf ("\nВводится %d %d элемент второй матрицы\n", i, j);
				fscanf(array_input2,"%f", &Mas2[i][j]);
				printf("%f", Mas2[i][j]); 
			}
		}
		fclose(array_input1);
		fclose(array_input2);
	}
	else if (path==0){
		for (i=0;i<3;i++) {//вводим самостоятельно элементы первой матрицы
			for (j=0;j<3;j++) {
				printf ("Введите %d %d элемент первой матрицы\n", i, j);
				scanf ("%f", &Mas1[i][j]);
			}
		}
		printf ("\n\n\n");
		for (i=0;i<3;i++) {//вводим самостоятельно элементы второй матрицы
			for (j=0;j<3;j++) {
				printf ("Введите %d %d элемент второй матрицы\n", i, j);
				scanf ("%f", &Mas2[i][j]);
			}
		}
	}
	else {
		printf ("You wrong");
	}
	printf ("\n\n");
	for (i=0;i<3;i++) {//вывод первой матрицы
		printf("\n");
		for (j=0;j<3;j++) {
			printf ("%f ", Mas1[i][j]);
		}
	}
	printf ("\n\n\n");
	for (i=0;i<3;i++) {//вывод второй матрицы
		printf("\n");
		for (j=0;j<3;j++) {
			printf ("%f ", Mas2[i][j]);
		}
	}
	printf ("\n\n\nType '0'(self) if you want to output values in terminal or '1'(file) if you want to write values to a file\n");
	scanf ("%d", &path);
//	printf ("What???");
	if (path==0) {
		printf("\n\n");
		summ(Mas1, Mas2);//вызываем функцию суммирования
		for (i=0;i<3;i++) {//вывод результат функции в виде третьей матрицы
			printf("\n");
			for (j=0;j<3;j++) {
				printf ("%f ", Mas3[i][j]);
			}
		}
		printf("\n\n");
		product(Mas1, Mas2);//вызываем функцию умножения
		for (i=0;i<3;i++) {//вывод результат функции в виде третьей матрицы
			printf("\n");
			for (j=0;j<3;j++) {
				printf ("%f ", Mas3[i][j]);
			}
		}
		printf("\n\ndet1 = %f\n\ndet2 = %f\n\n", det(Mas1), det(Mas2));//вызываем функцию по обнаружению определителя и сразу же выводим его значение
		reverse(Mas1);//вызываем функцию по обнаружению обратной матрицы к первой матрице
		for (i=0;i<3;i++) {//вывод результат функции в виде третьей матрицы
			printf("\n");
			for (j=0;j<3;j++) {
				printf ("%f ", Mas3[i][j]);
			}
		}
		printf("\n\n");
		reverse(Mas2);//вызываем функцию по обнаружению обратной матрицы ко второй матрице
		for (i=0;i<3;i++) {//вывод результат функции в виде третьей матрицы
			printf("\n");
			for (j=0;j<3;j++) {
				printf ("%f ", Mas3[i][j]);
			}
		}
	}
	else if (path==1){
		FILE *array_output = fopen("/home/hello/Рабочий стол/Основы программирования/array_output.txt", "w");
		summ(Mas1, Mas2);//вызываем функцию суммирования
		for (i=0;i<3;i++) {//записываем результат функции в виде третьей матрицы в файл
			fprintf(array_output,"\n");
			for (j=0;j<3;j++) {
				fprintf (array_output, "%f ", Mas3[i][j]);
			}
		}
		fprintf (array_output, "\n\n");
		
		product(Mas1, Mas2);//вызываем функцию умножения
		for (i=0;i<3;i++) {//записываем результат функции в виде третьей матрицы в файл
			fprintf(array_output,"\n");
			for (j=0;j<3;j++) {
				fprintf (array_output, "%f ", Mas3[i][j]);
			}
		}
		fprintf (array_output, "\n\n");
		
		fprintf (array_output,"\n\ndet1 = %f\n\ndet2 = %f\n\n", det(Mas1), det(Mas2));//вызываем функцию по обнаружению определителя и сразу же записываем его значение в файл
		fprintf (array_output, "\n\n");
		
		reverse(Mas1);//вызываем функцию по обнаружению обратной матрицы к первой матрице
		for (i=0;i<3;i++) {//записываем результат функции в виде третьей матрицы в файл
			fprintf(array_output,"\n");
			for (j=0;j<3;j++) {
				fprintf (array_output, "%f ", Mas3[i][j]);
			}
		}
		fprintf (array_output, "\n\n");
		
		reverse(Mas2);//вызываем функцию по обнаружению обратной матрицы ко второй матрице
		for (i=0;i<3;i++) {//записываем результат функции в виде третьей матрицы в файл
			fprintf(array_output,"\n");
			for (j=0;j<3;j++) {
				fprintf (array_output, "%f ", Mas3[i][j]);
			}
		}
		fprintf (array_output, "\n\n");
		fclose(array_output);
	}
	else {
		printf ("You wrong");
	}
	return 0;
}
