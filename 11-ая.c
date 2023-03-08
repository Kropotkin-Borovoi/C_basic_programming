#include <stdio.h>
char text [100];//задаём текст как массив из 100 символов в виде глобальной переменной

int delete_symb (int number) {//функция по удалению лишних символов, суть в том, что след. символ становится на место текущего и так все последующие, тем самым весь текст сместился на один символ
	for (int i=number;i<100;i++) {
		text[i]=text[i+1];
	}
	return (number-1);
}

void replace_symb (int number) {//в системе ascii от маленьких переходит большим буквам
	text[number]=(int)text[number]-32;
}

void insert_symb (int number) {//функция по вставке пробелов, суть в том, что текущий символ становится на место след. и так все последующие, тем самым весь текст сместился на один символ
	int k, l;
	k=text[number];
	text[number]=' ';
	for (int i=number+1;i<100-2;i+=2) {
		l=text[i];
		text[i]=k;
		k=text[i+1];
		text[i+1]=l;
	}
}

void correct_string () {//вся функция по корректировке текста
	int i=0;
	while (text[i]==' ') {//цикл по удалению лишних пробелов перед началом текста
		delete_symb(i);
	}
	if ((int)text[0]>90) {//проверка, чтоб первый символ был с заглавной буквы
		replace_symb
		(0);
	}
	for (i=1;i<100-2;i++) {//корректировка всего текста
		if ((text[i]=='.')||(text[i]==',')||(text[i]=='!')||(text[i]=='?')) {//чтоб после знаков препинания были пробелы
			if (text[i+1]!=' ') {
				insert_symb(i+1);
			}
		}
		if ((text[i]=='.')||(text[i]=='!')||(text[i]=='?')) {
			if (text[i+1]==' ') {//чтоб после точки, вопросительного и воклицательного знака шли заглавные буквы
				if ((int)text[i+2]>90) {
					replace_symb(i+2);
				}
			}
		}
		if ((text[i-1]=='.')||(text[i-1]=='!')||(text[i-1]=='?')) {
			if (text[i]==' ') {//чтоб после точки, вопросительного и воклицательного знака шли заглавные буквы
				if ((int)text[i+1]>90) {
					replace_symb(i+1);
				}
			}
		}
		if (text[i]==' ') {//удаление лишних пробелов
			if (text[i+1]==' ') {
				i=delete_symb(i+1)-1;
			}
		}
		if (text[i]==' ') {//удаление пробелов перед знаками препинания
			if ((text[i+1]=='.')||(text[i+1]==',')||(text[i+1]=='!')||(text[i+1]=='?')) {
				i=delete_symb(i);
			}
		}
	}	
}

int main() {
	printf("Enter the text you want to correct:\n");
	fgets(text, 100, stdin);
	correct_string();
	printf("%s", text);
	return 0;
}

