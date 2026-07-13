#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

char *stack[SIZE];
int top = -1;

void push(char *ch) {
    if (top == SIZE - 1)
        return;
    stack[++top] = ch;
    return;
}

char* pop() {
    if (top == -1) return NULL;
    return stack[top--];
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}


int main() {
    char *expr = (char *) malloc(sizeof(char) * SIZE);
    char ch;
    int j = 0;

    printf("Enter the postfix expression: ");
    fgets(expr, SIZE, stdin);
    expr[strlen(expr) - 1] = '\0';

    for (int i = 0; expr[i] != '\0'; i++) {
        ch = expr[i];

        if (ch == '(' || ch == ')' || ch == ' ')
            continue;

        if (!isOperator(ch)) {
            char *temp = (char *) malloc(sizeof(char) * 2);
            temp[0] = ch;
            temp[1] = '\0';
            push(temp);
        } else {
            char *temp = (char *) malloc(sizeof(char) * SIZE);
            char *op1 = pop();
            char *op2 = pop();
            sprintf(temp, "(%s%c%s)", op2, ch, op1);
            push(temp);
        }
    }
    printf("infix format: %s\n", pop());
    return 0;
}
