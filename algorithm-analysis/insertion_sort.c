#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        int key = arr[i];
        for (j = i - 1; j >= 0 && key < arr[j]; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void bubblesort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int pos = i, min = arr[pos];
        for (int j = i; j < n; j++) {
            if (min > arr[j]) {
                min = arr[j];
                pos = j;
            }
        }
        arr[pos] = arr[i];
        arr[i] = min;
    }
}

void quicksort(int arr[], int start, int end) {
    if (start >= end) return;

    int pivot = arr[end];
    int pIndex = start;

    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = arr[end];
    arr[end] = arr[pIndex];
    arr[pIndex] = temp;

    quicksort(arr, start, pIndex - 1);
    quicksort(arr, pIndex + 1, end);
}

void merge(int arr[], int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;

    merge(arr, start, mid);
    merge(arr, mid + 1, end);

    int i = start, j = mid + 1, k = 0;
    int temp[end - start + 1];
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else if (arr[j] < arr[i])
            temp[k++] = arr[j++];
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (int i = 0, j = start; i < end - start + 1; i++, j++) {
        arr[j] = temp[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    printArray(arr, n);

    return 0;
}