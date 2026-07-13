#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate(int**, int);
int linear_search(int*, int, int, int*);

int main() {

    srand(time(NULL));

    int size = 10000;

    while (size <= 100000) {

        int *ptr;
        int no_of_div = 0;

        generate(&ptr, size);

        clock_t start = clock();

        int pos = linear_search(
            ptr,
            size,
            ptr[size - 1],   // searching last element
            &no_of_div
        );

        clock_t end = clock();

        double time_taken =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf(
            "SIZE: %d || time: %f || no_of_comp: %d || pos: %d\n",
            size,
            time_taken,
            no_of_div,
            pos
        );

        free(ptr);

        size += 10000;
    }

    return 0;
}

void generate(int **ptr, int size) {

    *ptr = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        (*ptr)[i] = i;
    }
}

int linear_search(int *ptr, int size, int num, int *no_of_div) {

    for (int i = 0; i < size; i++) {

        (*no_of_div)++;

        if (ptr[i] == num)
            return i;
    }

    return -1;
}