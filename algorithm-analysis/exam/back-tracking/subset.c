#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generate(int *a, int size, int pos) {
    if (pos == size) {
        for (int i = 0; i < size; i++) {
            printf("%d\t", a[i]);
        }
        printf("\n");
        return;
    }
    
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    generate(a, 5, 0);
    return 0;
}