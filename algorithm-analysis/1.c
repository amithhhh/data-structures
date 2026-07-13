#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int*, int);
void swap(int*, int*);

int main() {
	for (int i = 10000; i <= 100000; i+=10000) {
		int *arr = (int *) malloc(sizeof(int) * i);
		for (int j = 0; j < i; j++) {
			arr[j] = rand();
		}
		clock_t start_time = clock();
		bubbleSort(arr, i);
		clock_t end_time = clock();
		double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		printf("size: %d, time taken: %f\n", i, time_taken);
		free(arr);
	}
	return 0;
}

void bubbleSort(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
