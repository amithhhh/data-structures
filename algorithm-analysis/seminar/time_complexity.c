//Selection Sort Implementations.

/*import header files.*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/*Function declaration.*/
void selection_sort(int*, int);
void display(int*, int);
int *generate(int);

/*main function*/
int main() {
	srand(time(NULL));
    int size = 10000;
    clock_t start, end;
    while (size <= 100000) {
	    int *arr = generate(size);
        start = clock();
	    selection_sort(arr, size);
        end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("SIZE: %d || time taken: %fsec\n", size, time_taken);
        size += 10000;
    }
	return 0;
}

/*Function Definitions.*/
int* generate(int SIZE) {
	int *ptr = (int*) malloc(sizeof(int) * SIZE);
	for (int i = 0; i < SIZE; i++) {
		*(ptr + i) = rand();
	}
	return ptr;
}

void selection_sort(int *ptr, int SIZE) {
	int swap = 0;
	for (int i = 0; i < SIZE; i++) {
		int min = ptr[i];
		int pos = i;
		for (int j = i; j < SIZE; j++) {
			if (ptr[j] < min) {
				min = ptr[j];
				pos = j;
			}
		}
		if (pos != i) {
			ptr[pos] = ptr[i];
			ptr[i] = min;
			swap++;
		}
	}
	printf("SIZE: %d || swaps: %d\n", SIZE, swap);
}

void display(int *ptr, int SIZE) {
	int i = 0;
	while (i < SIZE) {
		printf("%d\t", ptr[i]);
		i++;
	}
	printf("\n");
}


