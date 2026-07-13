#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define SIZE 2000
#define PATTERN "^\\s*[a-zA-Z_][a-zA-Z0-9_\\*\\s]*\\s+[a-zA-Z_][a-zA-Z0-9_]*\\s*\\([^)]*\\)\\s*"

int top = -1;

void push(char*);
void pop();
void display();

char *STACK[SIZE];

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("[-]Usage: ./project <file_name.c>\n");
		return -1;
	} else {
		size_t len = 0;
		int can_push = 0;
		ssize_t read;
		regex_t regex;
		int count = 0;
		char *curr = NULL;
		int multi_comment = 0;

		FILE *file = fopen(argv[1], "r");

		if (file == NULL) {
			printf("[-]Open Error.\n");
			return -1;
		}
		regcomp(&regex, PATTERN, REG_EXTENDED);

		while ((read = getline(&curr, &len, file)) != -1) {
			if (regexec(&regex, curr, 0, NULL, 0) == 0) {
				can_push = 1;
			}

			if (strstr(curr, "/*") != NULL) {
				multi_comment = 1;
			}

			if (strstr(curr, "*/") != NULL) {
				multi_comment = 0;
			}

			if (multi_comment == 1) {
				continue;
			}

			if (strchr(curr, '{') != NULL && can_push == 1) {
				push("{");
			}

			if (strchr(curr, '}') != NULL) {
				if (top != -1) {
					pop();
				}
				if (top == -1 && can_push == 1) {
					count++;
					can_push = 0;
				}
			}
		}
		fclose(file);
		free(curr);
		printf("The total number of userdefined functions: %d\n", count);
	}
	return 0;
}


void push(char *s) {
	if (top >= SIZE - 1) {
		printf("[-]Sorry Stack is full. Can't load anymore.\n");
	} else {
		top += 1;
		STACK[top] = strdup(s);
	}
}


void pop() {
	if (top == -1) {
		printf("[-]Sorry, Stack is empty, can't unload anymore.\n");
	} else {
		top--;
	}
}


void display() {
	for (int i = 0; i <= top; i++) {
		printf("%s\n", STACK[i]);
	}
}
