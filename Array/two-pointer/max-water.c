#include <stdio.h>
#include <stdlib.h>

int max_capacity(int*, int);
int min(int, int);

int main() {
	int a[] = {1, 10, 2, 11, 9, 5, 6};
	int size = sizeof(a) / sizeof(a[0]);
	printf("The Maximum water capacity: %d", max_capacity(a, size));
	return 0;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

int max_capacity(int *a, int size) {
	int left = 0;
	int right = size - 1;
	int area = 0, max_area = 0;

	while (left < right) {
		area = min(a[left], a[right]) * (right - left);
		if (area >  max_area)
			max_area = area;
		if (a[left] < a[right])
			left++;
		else
			right--;
	}
	return max_area;
}
