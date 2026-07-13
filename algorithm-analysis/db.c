#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

Node *create_node(int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void insert(Node **head, int data, int pos) {
	Node *node = create_node(data);
	if (pos == 1) {
		node->next = *head;
		if (*head != NULL) {
			(*head)->prev = node;
		}
		*head = node;
		return;
	} else {
		int i = 1;
		Node *temp = *head;
		while (i < pos - 1 && temp != NULL) {
			i++;
			temp = temp->next;
		}
		node->prev = temp;
		node->next = temp->next;
		temp->next = node;
		if (node->next != NULL) {
			node->next->prev = node;
		}
		
	}
}

Node* delete(Node **head, int val) {
	Node *temp = *head;
	while (temp != NULL) {
		if (temp->data == val) {
			if (temp->prev != NULL)
                		temp->prev->next = temp->next;
            		else
                		*head = temp->next;
			if (temp->next != NULL) {
				temp->next->prev = temp->prev;
			}
			break;
		}
		temp = temp->next;
	}
	return temp;
}


void print(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main() {
	Node *head = NULL;
	insert(&head, 10, 1);
	insert(&head, 20, 2);
	insert(&head, 30, 1);
	print(head);
	delete(&head, 20);
	print(head);
	return 0;
}
