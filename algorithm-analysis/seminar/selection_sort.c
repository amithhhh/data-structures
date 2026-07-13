//Selection Sort Implementations.

/*import header files.*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*Global variables.*/
#define SIZE 10

/*Function declaration.*/
void selection_sort(int*);
void display(int*);
int *generate();

/*main function*/
int main() {
	srand(time(NULL));
	int *arr = generate();
	display(arr);
	selection_sort(arr);
	display(arr);
	return 0;
}

/*Function Definitions.*/
int* generate() {
	int *ptr = (int*) malloc(sizeof(int) * SIZE);
	for (int i = 0; i < SIZE; i++) {
		*(ptr + i) = rand() % 10000;
	}
	return ptr;
}

void selection_sort(int *a) {
	for (int i = 0; i < SIZE; i++) {
		int min = a[i];
		int pos = i;
		for (int j = i; j < SIZE; j++) {
			if (a[j] < min) {
				min = a[j];
				pos = j;
			}
		}
		if (pos != i) {
			a[pos] = a[i];
			a[i] = min;
		}
	}
}

void display(int *ptr) {
	int i = 0;
	while (i < SIZE) {
		printf("%d\t", ptr[i]);
		i++;
	}
	printf("\n");
}


