#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateArray(int row, int col, int val);
int* generateArrayForMatrix(int*, int, int, int);
void add_by_indexing(int*, int*, int, int, int);
void add_by_pointers(int*, int*, int);

int main() {

	int row = 10, col = 10000, val = 10000;

    	clock_t index_start, index_end, pointers_start, pointers_end;
    	double index_time, pointers_time;

    	int *a = generateArray(row, col, val);
    	int *b = generateArray(row, col, val);

    	index_start = clock();
    	add_by_indexing(a, b, row, col, val);
    	index_end = clock();

    	pointers_start = clock();
    	add_by_pointers(a, b, row * col * val);
    	pointers_end = clock();

    	index_time = (double)(index_end - index_start) / CLOCKS_PER_SEC;
    	pointers_time = (double)(pointers_end - pointers_start) / CLOCKS_PER_SEC;

    	printf("Indexing: %f\n", index_time);
    	printf("Pointers: %f\n", pointers_time);

    	free(a);
    	free(b);

    	return 0;
}

int* generateArray(int row, int col, int val) {

	int size = row * col * val;
    	int *array = malloc(sizeof(int) * size);

    	for (int i = 0; i < size; i++)
        	array[i] = rand();

    	return array;
}

void add_by_indexing(int *a, int *b, int row, int col, int val) {

    int size = row * col * val;
    int *c = malloc(sizeof(int) * size);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            for (int k = 0; k < val; k++) {

                int index = i * col * val + j * val + k;
                c[index] = a[index] + b[index];
        }

    	free(c);
}

void add_by_pointers(int *a, int *b, int size) {

    	int *c = malloc(sizeof(int) * size);
	int i = 0;
	while (i < size) {
		*c = *a + *b;
		c++; i++; a++; b++;
	}

    	free(c);
}

int* generateArrayForMatrix(int *a, int row, int col, int val) {
	int l = 0;
	for (int i = 0; i < row; i++) {
		int *b = (int**) malloc(sizeof(int**) * row);
		for (int j = 0; j < col; j++){
			int *b[i] = (int*)malloc(sizeof(int*) * col);
			for (int k = 0; k < val; k++) {
				b[i][j][k] = a[l];
				l++;
			}
		}
	}
}
