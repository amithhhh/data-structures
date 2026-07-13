/*Implement stack using single linked list.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *head = NULL;

void push(int);
int pop();
int peek();
void display();

int main() {

	int choice, val;

	do {
		printf("\n--- STACK OPERATIONS ---\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Exit\n");

		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {

			case 1:
				printf("Enter value to push: ");
				scanf("%d", &val);
				push(val);
				break;

			case 2:
				val = pop();

				if (val == -1)
					printf("Stack Underflow\n");
				else
					printf("Popped element: %d\n", val);

				break;

			case 3:
				val = peek();

				if (val == -1)
					printf("Stack is Empty\n");
				else
					printf("Top element: %d\n", val);

				break;

			case 4:
				printf("Stack elements:\n");
				display();
				break;

			case 5:
				printf("Exiting...\n");
				break;

			default:
				printf("Invalid Choice\n");
		}

	} while (choice != 5);

	return 0;
}

void push(int val) {
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = val;
	node->next = head;
	head = node;
}

int pop() {
	if (head == NULL)
		return -1;
	struct Node *node = head;
	head = head->next;
	int val = node->data;
	free(node);
	return val;
}

int peek() {
	if (head != NULL)
		return head->data;
	return -1;
}
void display() {
	struct Node *temp = head;
	while (temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
