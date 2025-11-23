#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

int main() {
	struct Node *first = (struct Node*) malloc (sizeof(struct Node));
	first->data = 10;
	first->next = NULL;

	printf("Data: %d\n", first->data);
	printf("Next: %p\n", first->next);
	
	return 0;
}

