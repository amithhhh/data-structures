//Selection Sort Implementations.

/*import header files.*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/*Function declaration.*/
void bubble(int*, int);
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
	    bubble(arr, size);
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

void bubble(int *ptr, int SIZE) {
    long int swap = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - i - 1; j++) {
			if (ptr[j] > ptr[j + 1]) {
				int temp = ptr[j + 1];
                ptr[j + 1] = ptr[j];
                ptr[j] = temp;
                swap++;
			}
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


