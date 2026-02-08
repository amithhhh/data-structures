#include <stdio.h>
#include <stdlib.h>

struct Tree {
	int data;
	struct Tree *left;
	struct Tree *right;
};

void createNode(struct Tree**, int*);
void inorder(struct Tree*);
void preorder(struct Tree*);
void postorder(struct Tree*);

int main() {
	struct Tree *tree = NULL;
	int a[] = {65, 3, 4, 56, 2, 19, 90, 12, 199, 200};
	createNode(&tree, a);
	printf("[+]Inorder Traversal\n");
	inorder(tree);
	printf("[+]Preorder traversal\n");
	preorder(tree);
	printf("[+]Postorder traversal\n");
        postorder(tree);
	return 0;
}

void inorder(struct Tree *temp) {
	if  (temp == NULL)
		return;

	inorder(temp->left);
	printf("%d\n", temp->data);
	inorder(temp->right);
}

void preorder(struct Tree *temp) {
	if (temp == NULL)
		return;
	printf("%d\n", temp->data);
	preorder(temp->left);
	preorder(temp->right);
}

void postorder(struct Tree *temp) {
	if (temp == NULL)
		return;
	postorder(temp->left);
	postorder(temp->right);
	printf("%d\n", temp->data);
}

void createNode(struct Tree **tree, int* values) {
	struct Tree *temp = NULL;
	for (int i = 0; i < 10; i++) {
		struct Tree *newNode = (struct Tree*) malloc(sizeof(struct Tree));
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->data = values[i];

		if (*tree == NULL) {
			*tree = newNode;
			temp = *tree;
		} else {
			if (newNode->data < temp->data) {
				temp->left = newNode;
				temp = temp->left;
			} else {
				temp->right = newNode;
				temp = temp->right;
			}
		}
	}
}
