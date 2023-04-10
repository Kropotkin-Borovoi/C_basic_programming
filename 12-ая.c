#include <stdio.h>
#include <stdlib.h>

int delete_symb (int number, char *text) {
	for (int i = number; i < 100; i++) {
		text[i] = text[i + 1];
	}
	return number - 1;
}

void replace_symb (int number, char *text) {
	text[number] = (int)text[number] - 32;
}

void insert_symb (int number, char *text) {
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

void remove_spaces_before_text (int number, char *text) {
	while (text[number] == ' ') {
		delete_symb(number, text);
	}
}

void first_capital_symbol (int number, char *text) {
	if ((int)text[number] > 90) {
		replace_symb(number, text);
	}
}

void insert_space_after_character (int number, char *text) {
	if ((text[number] == '.') || (text[number] == ',') || \
 (text[number] == '!') || (text[number] == '?')) {
		if (text[number + 1] != ' ') {
			insert_symb(number + 1, text);
		}
	}
}

void capital_letter_after_space (int number, char *text) {
	if ((text[number - 1] == '.') || (text[number - 1] == '!') || \
 (text[number - 1] == '?')) {
		if (text[number] == ' ') {
			if ((int)text[number + 1] > 90) {
				replace_symb(number + 1, text);
			}
		}
	}
}

int removal_of_extra_spaces (int number, char *text) {
	if (text[number] == ' ') {
		if (text[number + 1] == ' ') {
			number = delete_symb(number + 1, text) - 1;
		}
	}
	return number;
}

int remove_a_space_before_a_character (int number, char *text) {
	if (text[number] == ' ') {
		if ((text[number + 1] == '.') || (text[number + 1] == ',') ||\
 (text[number + 1] == '!') || (text[number + 1] == '?')) {
			number = delete_symb(number, text);
		}
	}
	return number;
}

void correct_string (char *text, int SIZE) {
	
	int i=0;
	
	remove_spaces_before_text(i, text);
		
	first_capital_symbol(i, text);
	
	for (i = 1; i < SIZE - 2; i++) {
		
		insert_space_after_character(i, text);
		
		capital_letter_after_space(i, text);
		
		i = removal_of_extra_spaces(i, text);
				
		i = remove_a_space_before_a_character(i, text);
	}	
}

void copy_text (char text1[], char text2[], int number) {
	for (int i = 0; i < number; i++) {
		text1[i] = text2[i];
	}
}

int main() {
	printf ("This program edits the text you enter\n\
 Enter the text you want to correct:\n");
	
	int i = 0, text_size = 10;
	char* text = (char*) malloc(text_size * sizeof(char));
	while (text[i] != '#') {
		scanf ("%c\n", &text[i]);
		i++;
		if (i >= text_size) {
			text_size *= 2;
			
			char* auxiliary_text = (char*) malloc(text_size * sizeof(char));
			copy_text(auxiliary_text, text, i);
			free(text);
			
			text = auxiliary_text;
		}
	}
	
	char* full_text = (char*) malloc((i-1) * sizeof(char));
	copy_text(full_text, text, i);
	free(text);
	
	fgets (full_text, i, stdin);
	correct_string(full_text, i);
	printf("%s", full_text);
	free(full_text);
	return 0;
}
