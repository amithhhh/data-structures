#include <stdio.h>
#define MAX 20

void createArray(int*);
void display(int*);
void deleteDuplicates(int*);
void changePos(int*);

int main() {
	int a[MAX];
	createArray(a);
	display(a);
	deleteDuplicates(a);
	display(a);
	changePos(a);
	display(a);
	return 0;
}

void createArray(int *a) {
	for (int i = 0; i < MAX; i++) {
		printf("\nEnter the element in position %d: \n", i+1);
		scanf("%d", a + i);
	}
}

void display(int *a) {
	for (int i = 0; i < MAX; i++)
		printf("%d\t", *(a + i));
	printf("\n");
}

void deleteDuplicates(int *a) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (i != j) {
				if (*(a + i) == *(a + j)) {
					*(a + i) = -1;
				}
			} else {
				continue;
			}
		}
	}
}

void changePos(int *a) {
	int i = 0, size = MAX;

	while (i < size) {
		if (a[i] == -1) {
			for (int j = i; j < size - 1; j++) {
				a[j] = a[j + 1];
			}
		size--;
		} else {
			i++;
		}
	}
}
