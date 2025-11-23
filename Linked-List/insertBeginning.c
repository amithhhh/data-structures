#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node* insertBeg(struct Node*);

int main() {
	int limit, i;
	printf("Enter the limit: ");
	scanf("%d", &limit);

	struct Node *head;
	struct Node *temp;

	for (i = 0; i < limit; i++) {
		struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
		printf("Enter the number at [%d]: ", i + 1);
		scanf("%d", &newNode->data);
		newNode->next = NULL;
		if (i == 0) {
			head = newNode;
			temp = head;
		} else {
			temp->next = newNode;
			temp = temp->next;
		}

	}
	head = insertBeg(head);

	while(head != NULL) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
	return 0;
}

struct Node* insertBeg(struct Node* head) {
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	printf("Enter the number: ");
	scanf("%d", &newNode->data);
	newNode->next = head;
	return newNode;
}
