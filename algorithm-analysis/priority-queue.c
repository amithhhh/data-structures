#include <stdio.h>

void insert(int *a, int* size, int val) {
	int i = *size;
	a[i] = val;
	(*size)++;
	while (i > 0) {
		int parent = (i - 1) / 2;
		if (a[i] > a[parent]) {
			int temp = a[i];
			a[i] = a[parent];
			a[parent] = temp;
			i = parent;
		} else {
			break;
		}
	}
}

int delete(int *a, int* size) {
	int val = a[0];
	(*size)--;
    	a[0] = a[*size];   // last element to root

    	int i = 0;


	while (1) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < *size && a[largest] < a[left]) {
			largest = left;
		} if (right <*size && a[largest] < a[right]){
                        largest = right;
		}
		if (largest == i)
			break;

		int temp = a[largest];
                a[largest] = a[i];
                a[i] = temp;
		i = largest;
	}
	return val;	
}

int main() {
	int a[] = {100, 50, 20, 10, 5, 0, 0, 0};
	int size = 5;
	insert(a, &size, 200);
	printf("%d\n", delete(a, &size));
	printf("%d\n", delete(a, &size));	

/*	for (int i = 0; i < size; i++) {
		printf("%d\n", a[i]);
	}*/
	return 0;
}
