#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *create_node(int val) {
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void inorder(struct Node *root) {
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d\n", root->data);
	inorder(root->right);
}

struct Node *insert(struct Node *root, int val) {
	if (root == NULL) return create_node(val);
	else {
		if (val < root->data) {
			root->left = insert(root->left, val);
		} else if (val > root->data) {
			root->right = insert(root->right, val);
		}
	}
	return root;
}

int main() {
	struct Node *root = NULL;
	root = insert(root, 30);
	root = insert(root, 45);
	root = insert(root, 15);
	root = insert(root, 100);
	root = insert(root, 10);
	root = insert(root, 25);
	root = insert(root, 89);

	inorder(root);
	return 0;
}

