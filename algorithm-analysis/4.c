#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
int TOP = -1;

int *STACK;

void init();
void stack_free();
void operation();
bool push(int);
bool pop(int*);
void display();
bool peek(int*);

int main() {
	init();
	operation();
	return 0;
}

void init() {
	STACK = (int *)malloc(SIZE * sizeof(int));
	printf("[+]Successfully initialized stack\n");
}

void stack_free() {
	free(STACK);
	printf("[+]Successfully destroyed Stack.\n");
}

void operation() {
	int choice;
	int val;
	while (1) {
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("Please choose from the following menu(push is the default): \n");
		printf("[1]: push\n");
		printf("[2]: pop\n");
		printf("[3]: peek\n");
        	printf("[4]: display\n");
		printf("[5]: exit\n");
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		scanf("%d", &choice);

		switch (choice) {
			case 1:		printf("Enter the value for pushing: ");
					scanf("%d", &val);
					if (push(val))
						printf("[+]%d pushed successfully.\n",val);
					else
						printf("[-]Stack is full.\n");
					break;

			case 2:		if (pop(&val))
						printf("[+]Popped value: %d\n", val);
					else
						printf("[-]Stack is empty.\n");
					break;

			case 3:		if (peek(&val))
						printf("[+]Top most element: %d\n", val);
					else
						printf("[-]Stack is empty\n");
					break;
			
			case 4:		display();
					break;
		
			case 5:		stack_free();
					break;
		}
	}
}	

bool push(int val) {
	if (TOP == SIZE -1) {
		return false;
	} else {
		STACK[++TOP] = val;
		return true;
	}
}

bool pop(int *val) {
	if (TOP == -1) {
		return false;
	} else {
		*val = STACK[TOP--];
		return true;
	}
}

void display() {
	if (TOP == -1) {
		printf("[-]Stack is empty.\n");
		return;
	} else {
		for (int i = 0; i <= TOP; i++) {
			printf("%d\t", STACK[i]);
		}
	}
}

bool peek(int *val) {
	if (TOP == -1) return false;
	else {
		*val = STACK[TOP];
		return true;
	}
}
