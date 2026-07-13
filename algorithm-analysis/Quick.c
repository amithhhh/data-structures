#include <stdio.h>
#include <stdlib.h>

void quick_sort(int*, int, int);
void swap(int*, int*);
void merge(int*, int, int);

int main() {
	int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	merge(a, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d\t", a[i]);
	}
	return 0;
}

void quick_sort(int *a, int low, int high) {
	if (low >= high) return;
	int pIndex = low;
	int pivot = high;
	for (int i = low; i < high; i++) {
		if (a[i] < a[pivot]) {
			swap(&a[i], &a[pIndex]);
			pIndex++;
		}
	}
	swap(&a[pivot], &a[pIndex]);
	quick_sort(a, low, pIndex - 1);
	quick_sort(a, pIndex + 1, high);
}

void swap(int *a, int *b)  {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void merge(int *a, int low, int high) {
	if (low >= high) return;
	int mid = (low + high) / 2;

	merge(a, low, mid);
	merge(a, mid + 1, high);

	int *temp = (int *)malloc(sizeof(int) * (high - low + 1));
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high) {
		if (a[i] < a[j]) {
			temp[k++] = a[i];
			i++;
		} else if (a[j] < a[i]) {
			temp[k++] = a[j];
			j++;
		}
	}
	while (i <= mid) {
		temp[k++] = a[i];
                i++;
	}
	while(j <= high) {
		temp[k++] = a[j];
                j++;
	}
	for (int i = 0, j = low; i < (high - low + 1); i++, j++) {
		a[j] = temp[i];
	}
}


















