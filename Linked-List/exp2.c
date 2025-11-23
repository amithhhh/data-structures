#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

int main() {
	struct Node *first = (struct Node*) malloc(sizeof(struct Node));
	struct Node *second = (struct Node*) malloc(sizeof(struct Node));

	first->data = 10;
	first->next = second;

	second->data = 20;
	second->next = NULL;

	struct Node *temp = first;

	while(temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return 0;
}
