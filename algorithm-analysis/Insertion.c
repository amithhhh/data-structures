#include <stdio.h>

void insertion_sort(int arr[], int size) {
    int i, j;
    for (i = 1; i < size; i++) {
        int key = arr[i];
        for (j = i - 1; j >= 0 && key < arr[j]; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int min = arr[i], pos = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < min) {
                min = arr[j];
                pos = j;
            }
        }
        arr[pos] = arr[i];
        arr[i] = min;
    }
}

int main() {
    int a[] = {40, 30, 20, 10};
    selection_sort(a, 4);

    for (int i = 0; i < 4; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}