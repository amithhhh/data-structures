/* Write a program to implement simple linked list and perform creation, 
insertion and deletion operation. */
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *head = NULL;

void insert_node(int, int);
void delete_node(int);
void display();

int main() {
	int choice, value, pos;
	while(1) {
		printf("Enter your choice(1-insert, 2-delete, 3-exit): ");
		scanf("%d", &choice);
		if (choice == 1) {
			printf("Enter the value, position (format val pos): ");
			scanf("%d %d", &value, &pos);
			insert_node(value, pos);
			display();
		} else if (choice == 2) {
			printf("Enter the value you want to delete: ");
			scanf("%d", &value);
			delete_node(value);
			display();
		} else {
			free(head);
			return 0;
		}
	}
	return 0;
}

void insert_node(int val, int pos) {
	int i = 0;
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	node->data = val;
	node->next = NULL;

	if (pos == 0) {
		node->next = head;
		head = node;
	} else {
		struct Node *temp = head;
		while (temp != NULL && i < pos - 1) {
			temp = temp->next;
			i++;
		}
		node->next = temp->next;
		temp->next = node;
		return;
	}
}

void display() {
	struct Node *temp = head;
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void delete_node(int val) {
	if (head == NULL) {
		printf("[-]Linked list empty.\n");
		return;
	}
	struct Node *prev = NULL, *curr = head;
	if (head != NULL && head->data == val) {
		curr = head;
		head = head->next;
		free(curr);
	} else {
		curr = head;
		while (curr != NULL) {
			if (curr->data == val) {
				prev->next = curr->next;
				struct Node *del = curr;
				free(del);
				return;
			}
			prev = curr;
			curr = curr->next;
		}
 	}
}
