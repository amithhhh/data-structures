/*Implement stack using single linked list.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int);
int dequeue();
void display();

int main() {

	int choice, val;

	do {
		printf("\n--- QUEUE OPERATIONS ---\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");

		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {

			case 1:
				printf("Enter value to enqueue: ");
				scanf("%d", &val);
				enqueue(val);
				break;

			case 2:
				val = dequeue();

				if (val == -1)
					printf("Queue empty\n");
				else
					printf("Dequeued element: %d\n", val);

				break;

			case 3:
				printf("Queue elements:\n");
				display();
				break;

			case 4:
				printf("Exiting...\n");
				break;

			default:
				printf("Invalid Choice\n");
		}

	} while (choice != 5);

	return 0;
}

void enqueue(int val) {
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = val;
	node->next = NULL;
	if (front == NULL && rear == NULL) {
		front = rear = node;
	} else {
		rear->next = node;
		rear = rear->next;
	}
}

int dequeue() {
	int val;
	if (front == NULL)
		return -1;
	else if (front == rear) {
		struct Node *node = front;
		val = front->data;
		front = rear = NULL;
		free(node);
	} else {
		struct Node *node = front;
		front = front->next;
		val = node->data;
		free(node);
	}
	return val;
}
void display() {
	struct Node *temp = front;
	while (temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
