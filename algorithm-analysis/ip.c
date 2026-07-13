#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int top = -1;
char stack[SIZE];

void push(char c) {
	if (top == SIZE - 1) return;
	stack[++top] = c;
}

char pop() {
	if (top == -1) return (char)-1;
	char val = stack[top];
	top--;
	return val;
}
int isEmpty() {
	if (top == -1) return -1;
	return 1;
}
int precedence(char ch) {
	if (ch == '^') return 4;
	else if (ch == '*' || ch == '/') return 3;
	else if (ch == '+' || ch == '-') return 2;
	else return -1;
}

int is_left_associative(char ch) {
	if (ch == '^') return 0;
	return 1;
}

char *infix_to_postfix(char *infix) {
	char ch;
	int k = 0;
	char *postfix = (char*)malloc(sizeof(char) * SIZE);
	for (int i = 0; infix[i] != '\0'; i++) {
		ch = infix[i];
		if (ch == ' ') continue;
		if (precedence(ch) == -1 && ch != '(' && ch != ')' && ch != ' ') {
			postfix[k++] = ch;
			continue;
		}
		if (ch == '(') {
			push('(');
			continue;
		}
		if (ch == ')') {
			while (stack[top] != '(') {
				postfix[k++] = pop();
			}
			pop();
			continue;
		}
		if (top == -1 && precedence(ch) != -1) {
			push(ch);
			continue;
		} else if (top != -1 && precedence(ch) != -1) {
			while (top != -1 && ch != '(' && ((precedence(stack[top]) > precedence(ch)) || ((precedence(stack[top]) == precedence(ch)) && is_left_associative(ch)))) {
				postfix[k++] = pop();
			}
			push(ch);
			continue;
		}
	}
	while (top != -1) {
		postfix[k++] = pop();
	}
	postfix[k] = '\0';
	return postfix;
}

void reverse(char *str) {
	char temp;
	int i = 0, j = strlen(str) - 1;
	while (i < j) {
		temp = str[i];
        	str[i] = str[j];
        	str[j] = temp;

        	i++;
        	j--;
	}
}

void replace(char *infix) {
	for (int i = 0; infix[i] != '\0'; i++) {
		if (infix[i] == '(')  infix[i] = ')';
		else if (infix[i] == ')') infix[i] = '(';
	}
}

int main() {
	char  ch;
	char *infix = (char*)malloc(sizeof(char) * SIZE);
	char *postfix;

	printf("Enter the expression: ");
	fgets(infix, SIZE, stdin);
	infix[strlen(infix) - 1] = '\0';
	postfix = infix_to_postfix(infix);
	printf("%s\n", postfix);
	reverse(infix);
	replace(infix);
	char *prefix = infix_to_postfix(infix);
	reverse(prefix);
	printf("%s\n", prefix);
	return 0;
}













