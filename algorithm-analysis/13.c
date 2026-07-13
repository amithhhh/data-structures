#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

char stack[SIZE];
int TOP = -1;

void push(char);
char pop();
int presedence(char);
int is_left_associative(char);

int main() {
	char *expr = (char*) malloc(sizeof(char) * SIZE);
	char *out = (char*)malloc(sizeof(char) * SIZE);
	char ch;
	int i, j;
	printf("Enter the equation: ");
	fgets(expr, SIZE, stdin);
	expr[strlen(expr) - 1] = '\0';

	//algorithm implementation

	for (i = 0, j = 0; expr[i] != '\0'; i++) {
		ch = expr[i];
		if (ch == ' ')
			continue;
		if (presedence(ch) == -1 && ch != '(' && ch != ')') {
			out[j++] = ch;
			continue;
		}
		if (ch == '(') {
			push(ch);
			continue;
		}
		if (ch == ')') {
			while (stack[TOP] != '(') {
				out[j++] = pop();
			}
			pop();
			continue;
		}
		if (presedence(ch) != -1 && TOP == -1) {
			push(ch);
			continue;
		} else if (presedence(ch) != -1 && TOP != -1) {
			if (presedence(ch) > presedence(stack[TOP])) {
				push(ch);
			} else {
				while (TOP != -1 && (
					presedence(ch) <= presedence(stack[TOP])
				) && is_left_associative(ch)) {
					out[j++] = pop();
				}
				push(ch);
			}
			continue;
		}
	}
	while (TOP != -1) {
		out[j++] = pop();
	}
	printf("Equation in postfix form: %s\n", out);
	return 0;
}


int presedence(char c) {
	if (c == '^')
		return 4;
	else if (c == '*' || c == '/')
		return 3;
	else if (c == '+' || c == '-')
		return 2;
	else
		return -1;
}

void push(char ch) {
	if (TOP == SIZE - 1)
		return;
	stack[++TOP] = ch;
}

char pop() {
	if (TOP == -1)
		return '\0';
	return stack[TOP--];
}

int is_left_associative(char ch) {
	if (ch == '^')
		return -1;
	return 1;
}