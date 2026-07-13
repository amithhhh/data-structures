#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generate(int**, int);
int binary_search(int*, int, int);

int main() {
    srand(time(NULL));
    int *ptr;
    generate(&ptr, 100);
    int pos = binary_search(ptr, 100, /*element to be found = */ 99);
    if (pos)
        printf("element found at %d\n", pos);
    return 0;
}

void generate(int** ptr, int size) {
    *ptr = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        (*ptr)[i] = i;
    }
}

int binary_search(int *ptr, int size, int num) {
    int low = 0, high = size - 1, mid = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (ptr[mid] == num)
            return mid;
        else if (ptr[mid] < num)
            low = mid + 1;
        else  
            high = mid - 1;
    }
    return -1;
}

