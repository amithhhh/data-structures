#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generate(int**, int);
int binary_search(int*, int, int, int*);

int main() {
    srand(time(NULL));
    int size = 10000;
    while (size <= 100000) {
        int *ptr;
        int no_of_div = 0;
        generate(&ptr, size);
        clock_t start = clock();
        int pos = binary_search(ptr, size, /*element to be found = */ ptr[size - 1], &no_of_div);
        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("SIZE: %d || time: %f || no_of_div: %d\n", size, time_taken, no_of_div);
        free(ptr);
        size += 10000;
    }
    return 0;
}

void generate(int** ptr, int size) {
    *ptr = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        (*ptr)[i] = i;
    }
}

int binary_search(int *ptr, int size, int num, int* no_of_div) {
    int low = 0, high = size - 1, mid = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        (*no_of_div)++;
        if (ptr[mid] == num)
            return mid;
        else if (ptr[mid] < num) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

