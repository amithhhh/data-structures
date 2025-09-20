#include <stdio.h>

void createArray(int*, int);
void displayArray(int*, int);
//int* findCommon(int*, int*);

int main() {
	int *a, *b, *c;

	createArray(a, 5);
	displayArray(a, 5);

	createArray(b, 6);
	displayArray(b, 6);

	//c = findCommon(a, b)
	//displayArray(c);

	return 0;
}

void createArray(int *a, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("\n Enter the number: \n");
			scanf("%d", a + size * j + i);
		}
	}
}

void displayArray(int *a, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d\t", *(a + (size * j) + i));
		}
		printf("\n");
	}
}

int* findCommon(int *a, int *b) {
	int *c, k = 0, *temp;
	temp = c;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (*(a + 5 * j + i) == *(b + 6 * j + i)) {
				*(c + k) = *(a + 5 * j + i);
				k++;
			}
		}
	}
	return temp;
}
