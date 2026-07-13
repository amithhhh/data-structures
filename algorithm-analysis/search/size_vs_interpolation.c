#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generate(int**, int);
int interpolation_search(int*, int, int, int*);

int main() {
    srand(time(NULL));
    int size = 10000;
    while (size <= 100000) {
        int *ptr;
        int no_of_div = 0;
        generate(&ptr, size);
        clock_t start = clock();
        int pos = interpolation_search(ptr, size, /*element to be found = */ rand() % size, &no_of_div);
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

int interpolation_search(int *ptr, int size, int num, int *no_of_div) {
    int low = 0, high = size - 1, mid = 0;

    while (low <= high && ptr[low] <= num && ptr[high] >= num) {

        if (ptr[low] == ptr[high]) {
            if (ptr[low] == num)
                return low;
            else
                return -1;
        }

        (*no_of_div)++;
        int pos = low + (num - ptr[low]) * (high - low) / (ptr[high] - ptr[low]);
        
        if (ptr[pos] == num)
            return pos;
        else if (ptr[pos] < num)
            low = pos + 1;
        else  
            high = pos - 1;
    }
    return -1;
}
