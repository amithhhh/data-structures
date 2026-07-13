#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *left;
	struct Node *right;
	int height;
} Node;

Node *create_node(int val) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

Node *insert_node(Node *root, int val) {
	if (root == NULL)
		return create_node(val);

	if (val < root->val) {
		root->left = insert_node(root->left, val);	
	} else if (val > root->val) {
		root->right = insert_node(root->right, val);
	} else {
		return root;
	}

	root->height = 1 + max(height(root->left), height(root->right));
	int balance = get_balance_factor(root);

	if (balance > 1 && val < root->left->val) {
		return right_rotation(root);
	}
	if (balance > -1 && val > root->right->val) {
		return left_rotation(root);
	}
	if (balance > 1 && val > root->left->val) {
		root->left = left_rotation(root->left);
		return right_rotation(root);
	}

	if (balance > -1 && val < root->right->val) {
		root->right = right_rotation(root->right);
		return left_rotation(root);
	}
	return root;
}

int height(Node *root) {
	if (root == NULL)
		return 0;
	return root->height;
}

int get_balance_factor(Node *root) {
	if (root == NULL) return 0;
	return height(root->left) - height(root->right);
}

int max(int a, int b) {
	return (a > b) ? a : b;
}


Node *right_rotation(Node *y) {
	Node *x = y->left;
	Node *t2 = x->right;
	
	x->right = y;
	y->left = t2;

	x->height = 1 + max(height(x->left), height(x->right));
	y->height = 1 + max(height(y->left), height(y->right));

	return x;
}

Node *left_rotation(Node *x) {
	Node *y = x->right;
	Node *t2 = y->left;

	y->left = x;
	x->right = t2;

	x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

	return y;
}







