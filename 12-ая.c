#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int delete_symb (int number, char *text) {
	for (int i = number; i < 100; i++) {
		text[i] = text[i + 1];
	}
	return number - 1;
}

void make_capital (int number, char *text) {
	text[number] = toupper(text[number]);
}

void insert_space (int number, char *text) {
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
	delete_symb(number, text);
}

void first_capital_symbol (int number, char *text) {
	make_capital(number, text);
}

void insert_space_after_character (int number, char *text) {
	insert_space(number, text);
}

void capital_letter_after_space (int number, char *text) {
	make_capital(number, text);
}

int removal_of_extra_space (int number, char *text) {
	number = delete_symb(number, text) - 1;
	
	return number;
}

int remove_a_space_before_a_character (int number, char *text) {
	number = delete_symb(number, text);
	
	return number;
}

void correct_string (char *text, int SIZE) {
	
	int i=0;
	
	while (text[i] == ' ') {
		remove_spaces_before_text(i, text);
	}
		
	if (text[i] > 'a') {
		first_capital_symbol(i, text);
	}
	
	for (i = 1; i < SIZE - 2; i++) {
		
		if ((text[i] == '.') || (text[i] == ',') || \
			(text[i] == '!') || (text[i] == '?')) {
			if (text[i + 1] != ' ') {
				insert_space_after_character(i + 1, text);
			}
		}
		
		if ((text[i - 1] == '.') || (text[i - 1] == '!') || \
			(text[i - 1] == '?')) {
			if (text[i] == ' ') {
				if (text[i + 1] > 'a') {
					capital_letter_after_space(i + 1, text);
				}
			}
		}
		
		if (text[i] == ' ') {
			if (text[i + 1] == ' ') {
				i = removal_of_extra_space(i + 1, text);
			}
		}
		
		if (text[i] == ' ') {
			if ((text[i + 1] == '.') || (text[i + 1] == ',') ||\
				(text[i + 1] == '!') || (text[i + 1] == '?')) {
				i = remove_a_space_before_a_character(i, text);
			}
		}
		
		if (text[i-1] >= 'a') {
			if (text[i] < 'Z') {
				text[i] = tolower(text[i]);
			} 
		}
		
	}	
}

void copy_text (char* text1, char* text2) {
	strcpy(text1, text2);
}

int main() {
	printf ("This program edits the text you enter\n\
			 \rEnter the text you want to correct:\n");
	
	int i = 0, text_size = 10;
	char* text = (char*) malloc(text_size * sizeof(char));
	
	do {
		text[i] = getchar();
		if (text[i] == '#') {
			text[i]='\0';
			break;
		}

		if (i == text_size - 1) {
			text_size *= 2;
			char* auxiliary_text = (char*) malloc(text_size * sizeof(char));
	
			copy_text(auxiliary_text, text);
	
			free(text);
	
			text = auxiliary_text;
		}
		i++;
		
	} while (1);
		
	char* full_text = (char*) malloc((i-1) * sizeof(char));
	copy_text(full_text, text);	
	
	free(text);
	
	correct_string(full_text, i);
	
	i = 0;
	
	while (full_text[i] != '\0') {
		printf ("%c", full_text[i]);
		i++;
	}
	
	free(full_text);
	return 0;
}
