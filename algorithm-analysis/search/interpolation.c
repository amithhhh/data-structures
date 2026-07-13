#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generate(int**, int);
int interpolation_search(int*, int, int);

int main() {
    srand(time(NULL));
    int *ptr;
    generate(&ptr, 100);
    int pos = interpolation_search(ptr, 100, /*element to be found = */ 99);
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

int interpolation_search(int *ptr, int size, int num) {
    int low = 0, high = size - 1, mid = 0;

    while (low <= high && ptr[low] <= num && ptr[high] >= num) {

        if (ptr[low] == ptr[high]) {
            if (ptr[low] == num)
                return low;
            else
                return -1;
        }

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

