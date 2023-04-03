#include <stdio.h>

char text [100];

int delete_symb (int number) {
	for (int i = number; i < 100; i++) {
		text[i] = text[i + 1];
	}
	return number - 1;
}

void replace_symb (int number) {
	text[number] = (int)text[number] - 32;
}

void insert_symb (int number) {
	int k, l;
	k = text[number];
	text[number] = ' ';
	for (int i = number + 1; i < 100 - 2; i += 2) {
		l = text[i];
		text[i] = k;
		k = text[i + 1];
		text[i + 1] = l;
	}
}

void correct_string () {
	int i=0;
	while (text[i] == ' ') {
		delete_symb(i);
	}
	if ((int)text[0] > 90) {
		replace_symb
		(0);
	}
	for (i = 1; i < 100 - 2; i++) {
		if ((text[i] == '.') || (text[i] == ',') || (text[i] == '!') \
 || (text[i] == '?')) {
			if (text[i + 1] != ' ') {
				insert_symb(i + 1);
			}
		}
		if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?')) {
			if (text[i + 1] == ' ') {
				if ((int)text[i + 2] > 90) {
					replace_symb(i + 2);
				}
			}
		}
		if ((text[i - 1] == '.') || (text[i - 1] == '!') || \
 (text[i - 1] == '?')) {
			if (text[i] == ' ') {
				if ((int)text[i + 1] > 90) {
					replace_symb(i + 1);
				}
			}
		}
		if (text[i] == ' ') {
			if (text[i + 1] == ' ') {
				i = delete_symb(i + 1) - 1;
			}
		}
		if (text[i] == ' ') {
			if ((text[i + 1] == '.') || (text[i + 1] == ',') ||\
 (text[i + 1] == '!') || (text[i + 1] == '?')) {
				i = delete_symb(i);
			}
		}
	}	
}

int main() {
	printf ("This program edits the text you enter\n\
 Enter the text you want to correct:\n");
	fgets (text, 100, stdin);
	correct_string();
	printf("%s", text);
	return 0;
}

