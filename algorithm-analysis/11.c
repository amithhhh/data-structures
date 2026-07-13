/* Write a circular queue implement simple linked list and perform creation, 
insertion and deletion operation. */
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insert_node(int);
void delete_node();
void display();

int main() {
	int choice, value;
	while(1) {
		printf("Enter your choice(1-insert, 2-delete, 3-exit): ");
		scanf("%d", &choice);
		if (choice == 1) {
			printf("Enter the value: ");
			scanf("%d", &value);
			insert_node(value);
			display();
		} else if (choice == 2) {
			delete_node();
			display();
		} else {
			free(front);
			free(rear);
			return 0;
		}
	}
	return 0;
}

void insert_node(int val) {
	int i = 0;
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	node->data = val;

	if (front == NULL) {
		front = rear = node;
		node->next = front;
	} else {
		node->next = front;
		rear->next = node;
		rear = rear->next;
	}
}

void display() {
	struct Node *temp = front;
	if (front == NULL)
		return;
	do {
		printf("%d\t", temp->data);
		temp = temp->next;
	} while(temp != front);
	printf("\n");
}

void delete_node() {
	if (front == NULL) {
		printf("[-]Linked list empty.\n");
		return;
	}
	if (front == rear) {
		free(front);
		front = rear = NULL;
		return;
	}
	front = front->next;
	free(rear->next);
	rear->next = front;
}
