#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void removeDup(int*, int*);
void init(int*,  int);
void print(int*, int);
void bubbleSort(int*, int);

int main() {
	int *a = (int*) malloc(MAX * sizeof(int));
	int limit;
	printf("Enter the limit: ");
	scanf("%d", &limit);
	init(a, limit);
	print(a, limit);
	bubbleSort(a, limit);
	removeDup(a, &limit);
	print(a, limit);
	return 0;
}

void removeDup(int *a, int *limit) {
	int slow = 0;
	int fast = 1;
	int temp = *limit;
	for (fast = 1; fast < temp; fast++) {
		if (a[fast] !=a[slow]) {
			slow++;
			a[slow] = a[fast];
		}
	}
	*limit = slow + 1;
}

void init(int *a, int limit) {
	for (int i = 0; i < limit; i++) {
		printf("Enter the element at loc %d: ", i + 1);
		scanf("%d", a + i);
	}
}

void print(int *a, int limit) {
	for (int i = 0; i < limit; i++)
		printf("%d\t", *(a + i));
	printf("\n");
}

void bubbleSort(int *a, int limit) {
	int temp;
	for (int i = 0; i < limit - 1; i++) {
		for (int j = 0; j < limit - i - 1; j++) {
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
