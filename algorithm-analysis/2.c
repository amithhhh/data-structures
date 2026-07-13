#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define N (SIZE * SIZE)
#define M (SIZE * SIZE * SIZE)

int a[SIZE][SIZE], b[SIZE][SIZE],e[SIZE][SIZE] ,x[SIZE][SIZE][SIZE], y[SIZE][SIZE][SIZE], f[SIZE][SIZE][SIZE];
int *c, *d, *p, *q, *threeD_result, *result;

void init();
void index_sum();
void pointer_sum();
void threeD_index_sum();
void threeD_pointer_sum();

int main() {
	init();
	clock_t start_time = clock();
	index_sum();
	clock_t end_time = clock();
	double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;
	printf("Time Taken for 2d (Indexing): %f\n", time_taken);
	start_time = clock();
        pointer_sum();
        end_time = clock();
        time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;
        printf("Time Taken for 2d (Pointer): %f\n", time_taken);
	start_time = clock();
        threeD_index_sum();
        end_time = clock();
        time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;
        printf("Time Taken for 3d (Index): %f\n", time_taken);
	start_time = clock();
        threeD_pointer_sum();
        end_time = clock();
        time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;
        printf("Time Taken for 3d (Pointer): %f\n", time_taken);
	free(c); free(d); free(p); free(q); free(result); free(threeD_result);
	return 0;
}

void init() {
	int k = 0;
	c = malloc(sizeof(int) * N);
	d = malloc(sizeof(int) * N);
	result = malloc(sizeof(int) * N);
	p = malloc(sizeof(int) * M);
        q = malloc(sizeof(int) * M);
	threeD_result = malloc(sizeof(int) * M);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			int num = rand();
			a[i][j] = num;
			*(c + k) = num;
			k++;
		}
	}
	k = 0;
	for (int i = 0; i < SIZE; i++) { 
                for (int j = 0; j < SIZE; j++) { 
                        int num = rand();
                        b[i][j] = num;
                        *(d + k) = num;
			k++;
                }
        }
	int n = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				int num = rand();
				x[i][j][k] = num;
				*(p + n) = num;
				n++;
			}
		}
	}
	n = 0;
        for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < SIZE; k++) {
                                int num = rand();
                                y[i][j][k] = num;
                                *(q + n) = num;
				n++;
                        }
                }
        }

}

void index_sum() {
	for (int i = 0; i < SIZE; i++) { 
                for (int j = 0; j < SIZE; j++) {
			e[i][j] = a[i][j] + b[i][j];
                }
        }
}

void pointer_sum() {
	for (int i = 0; i < N; i++) {
		*(result + i) = *(c + i) + *(d + i);
	}
}

void threeD_index_sum() {
	for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                        for (int k = 0; k < SIZE; k++) {
                                f[i][j][k] = x[i][j][k] + y[i][j][k];
                        }
                }
        }

}

void threeD_pointer_sum() {
        for (int i = 0; i < M; i++) {
                *(threeD_result + i) = *(p + i) + *(q + i);
        }
}
