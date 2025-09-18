#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

void initArray(int *ptr);
int findMaximum(int *ptr);
void findTwoLargest(int *ptr);

int main() {
	int *arr, num;
	arr = (int *) malloc(sizeof(int) * (MAX));
	initArray(arr);
	num = findMaximum(arr);
	printf("%d is the maximum\n", num);
	findTwoLargest(arr);
	return 0;
}

void initArray(int *ptr) {
	int i;

	for (i = 0; i < MAX; i++) {
		printf("\nEnter the number %d\n", i + 1);
		scanf("%d", (ptr + i));
	}
}

int findMaximum(int *ptr) {
	int i, max;
	max = *ptr;
	for (i = 0; i < MAX; i++) {
		if (*(ptr + i) > max)
			max = *(ptr + i);
	}
	return max;
}

void findTwoLargest(int *ptr) {
	int first = INT_MIN;
	int second = INT_MIN;

	for(int i = 0; i < MAX; i++) {
		if (*(ptr + i) > first) {
			second = first;
			first = *(ptr + i);
		} else if (*(ptr + i) > second && *(ptr + i) != first) {
			second = *(ptr + i);
		}
	}
	if (second == INT_MIN)
		printf("\n ALl Elements are equal\n");
	else
		printf("\n%d and %d are the largest and second largest element in the present array\n", first, second);
}
