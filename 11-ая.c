#include <stdio.h>

#define data 100

char text [data];

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

void remove_spaces_before_text (int number) {
	while (text[number] == ' ') {
		delete_symb(number);
	}
}

void first_capital_symbol (int number) {
	if ((int)text[number] > 90) {
		replace_symb(number);
	}
}

void space_after_character (int number) {
	if ((text[number] == '.') || (text[number] == ',') || \
 (text[number] == '!') || (text[number] == '?')) {
		if (text[number + 1] != ' ') {
			insert_symb(number + 1);
		}
	}
}

void capital_letter_after_space (int number) {
	if ((text[number] == '.') || (text[number] == '!') ||\
 (text[number] == '?')) {
		if (text[number + 1] == ' ') {
			if ((int)text[number + 2] > 90) {
				replace_symb(number + 2);
			}
		}
	}
}

void capital_letter_after_space_2 (int number) {
	if ((text[number - 1] == '.') || (text[number - 1] == '!') || \
 (text[number - 1] == '?')) {
		if (text[number] == ' ') {
			if ((int)text[number + 1] > 90) {
				replace_symb(number + 1);
			}
		}
	}
}

void removal_of_extra_spaces (int number) {
	if (text[number] == ' ') {
		if (text[number + 1] == ' ') {
			number = delete_symb(number + 1) - 1;
		}
	}
}

void remove_a_space_before_a_character (int number) {
	if (text[number] == ' ') {
		if ((text[number + 1] == '.') || (text[number + 1] == ',') ||\
 (text[number + 1] == '!') || (text[number + 1] == '?')) {
			number = delete_symb(number);
		}
	}
}

void correct_string (char *text, int size) {
	
	int i=0;
	
	remove_spaces_before_text(i);
		
	first_capital_symbol(i);
	
	for (i = 1; i < size - 2; i++) {
		
		space_after_character(i);
		
		capital_letter_after_space(i);
		
		capital_letter_after_space_2(i);
		
		removal_of_extra_spaces(i);
				
		remove_a_space_before_a_character(i);
	}	
}

int main() {
	printf ("This program edits the text you enter\n\
 Enter the text you want to correct:\n");
	fgets (text, data, stdin);
	correct_string(text, data);
	printf("%s", text);
	return 0;
}
