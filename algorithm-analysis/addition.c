#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int coeff;
	int exp;
	struct Node *next;
} Node;

Node *create_node(int coeff, int exp) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->coeff = coeff;
	node->exp = exp;
	node->next = NULL;
	return node;
}

void position(Node **head, Node *node) {
	if (*head == NULL) {
		*head = node;
	} else {
		struct Node *temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = node;
	}
}

void initialize(Node **head) {
	int coeff, exp, choice;
	do {
		printf("Enter the coefficient: ");
		scanf("%d", &coeff);
		printf("Enter the exponent: ");
		scanf("%d", &exp);
		Node *node = create_node(coeff, exp);
		position(head, node);
		printf("Do you have more(1/0): ");
		scanf("%d", &choice);
	} while (choice == 1);
}

void print(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		if (temp->next == NULL)
			printf("%dx^%d\n", temp->coeff, temp->exp);
		else 
			printf("%dx^%d + ", temp->coeff, temp->exp);
		temp = temp->next;
	}
}

void addition(Node *first, Node *second, Node **result) {
	Node *temp1 = first;
	Node *temp2 = second;
	
	while (temp1 != NULL || temp2 != NULL) {
		if (temp1->exp == temp2->exp) {
			Node *node = create_node(temp1->coeff + temp2->coeff, temp1->exp);
			position(result, node);
			temp1 = temp1->next;
			temp2 = temp2->next;
		} else if (temp1->exp > temp2->exp) {
			Node *node = create_node(temp1->coeff, temp1->exp);
			position(result, node);
			temp1 = temp1->next;
		} else {
			Node *node = create_node(temp2->coeff, temp2->exp);
			position(result, node);
                        temp2 = temp2->next;

		}
	}
	while (temp1 != NULL) {
		Node *node = create_node(temp1->coeff, temp1->exp);
                position(result, node);
                temp1 = temp1->next;
	}
	while (temp2 != NULL) {
		Node *node = create_node(temp2->coeff, temp2->exp);
                position(result, node);
                temp2 = temp2->next;
	}
}

int main() {
	Node *first = NULL, *second = NULL, *result = NULL;
	initialize(&first);
	initialize(&second);
	print(first);
	print(second);
	addition(first, second, &result);
	print(result);
	return 0;
}
