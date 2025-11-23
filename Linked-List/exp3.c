#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node *next;
};

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

	while(head != NULL) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
	return 0;
}
