#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char c;
	int count;
	struct Node *left;
	struct Node *right;
} Node;

Node *createNode(char c, int val) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->c = c;
	node->count = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void printCodes(Node *root, char codes[], int top) {
	if (root == NULL)
		return;
	if (root->left == NULL || root->right == NULL) {
		for (int i = 0; i < top; i++) {
			printf("%c", codes[i]);
		}
		printf("\n");
	}
	codes[top] = '0';
	printCodes(root->left, codes, top + 1);
	codes[top] = '1';
        printCodes(root->right, codes, top + 1);

}

void selection_sort(Node **nodes, int size) {
	for (int i = 0; i < size - 1; i++) {
		int pos = i; Node *min = nodes[i];
		for (int j = i; j < size; j++) {
			if (nodes[j]->count < min->count) {
				pos = j;
				min = nodes[j];
			}
		}
		Node *temp = nodes[i];
		nodes[i] = nodes[pos];
		nodes[pos] = temp;
	}
}

int main() {
	Node *nodes[100];
	char codes[100];
	int size = 4, top = 0;
	nodes[0] = createNode('A', 6);
	nodes[1] = createNode('B', 3);
	nodes[2] = createNode('C', 2);	
	nodes[3] = createNode('D', 1);

	while (size > 1) {
		selection_sort(nodes, size);
		Node *left = nodes[0];
		Node *right = nodes[1];

		Node *parent = createNode('$', left->count + right->count);
		parent->left = left;
		parent->right = right;

		for (int i = 2; i < size; i++) {
			nodes[i - 2] = nodes[i];
		}
		nodes[size - 2] = parent;
		size--;
	}
	printCodes(nodes[0], codes, top);
	return 0;
}	
