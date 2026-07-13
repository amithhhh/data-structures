#include <stdio.h>
#include <stdlib.h>

struct Node {
	int coeff;
	int exp;
	struct Node *next;
};

void polynomial_create(struct Node**);
struct Node *polynomial_addition(struct Node*, struct Node*);
void display(struct Node*);
void position(struct Node**, struct Node*);
struct Node* term_initialize(int, int);

int main() {
	struct Node *first = NULL;
	struct Node *second = NULL;
	struct Node *result = NULL;
	polynomial_create(&first);
	polynomial_create(&second);
	result = polynomial_addition(first, second);
	display(result);
	return 0;
}

void polynomial_create(struct Node **p) {
	int coeff, exp, choice;
	printf("Enter the polynomial: \n");
	do {
		printf("Enter the coefficient: ");
		scanf("%d", &coeff);
		printf("Enter the exponent: ");
		scanf("%d", &exp);
		struct Node *term = term_initialize(coeff, exp);

		if (*p == NULL) {
			*p = term;
		} else {
			struct Node *temp = *p;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = term;

		}
		printf("Do you have anymore...?(1-yes, 0-no)\n");
		scanf("%d", &choice);
	} while (choice == 1);
	return;
}

void display(struct Node *poly) {
	struct Node *temp = poly;
	while (temp != NULL) {
		if (temp->next != NULL) {
			printf("%dx^%d + ", temp->coeff, temp->exp);
		} else {
			printf("%dx^%d\n", temp->coeff, temp->exp);
		}
		temp = temp->next;
	}
}

struct Node *polynomial_addition(struct Node *first, struct Node *second) {
	struct Node *result = NULL;
	struct Node *temp = NULL;
	while (first != NULL && second != NULL) {
		if (first->exp == second->exp) {
			struct Node *term = term_initialize(first->coeff + second->coeff, first->exp);
			position(&result, term);
			first = first->next;
			second = second->next;
		} else if (first->exp > second->exp) {
			struct Node *term = term_initialize(first->coeff, first->exp);
			position(&result, term);
			first = first->next;

		} else {
			struct Node *term = term_initialize(second->coeff, second->exp);
                        position(&result, term);
                        second = second->next;

		}
	}
	while (second != NULL) {
		struct Node *term = term_initialize(second->coeff, second->exp);
                position(&result, term);
                second = second->next;

	}
	while (first != NULL) {
		struct Node *term = term_initialize(first->coeff, first->exp);
                position(&result, term);
                first = first->next;

	}
	return result;
}

void position(struct Node **result, struct Node *term) {
	struct Node *temp = *result;
	if (temp == NULL)
		*result = temp = term;
	else {
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = term;
	}
}

struct Node* term_initialize(int coeff, int exp) {
	struct Node *term = (struct Node*)malloc(sizeof(struct Node));
        term->exp = exp;
        term->coeff = coeff;
        term->next = NULL;
	return term;
}
