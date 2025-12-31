#include <stdio.h>

void reverse(int*);
void print(int*);
void swap(int*, int*);

int main() {
	int a[] = {1, 2, 3, 4, 5, 6, 8, 9, 10};
	print(a);
	reverse(a);
	print(a);
	return 0;
}
void print(int *a) {
	for (int i = 0; i < 9; i++)
		printf("%d\t", a[i]);
	printf("\n");
}

void reverse(int *a) {
	int left = 0;
	int right = 8;
	while (left < right) {
		swap(&a[left], &a[right]);
		left++;
		right--;
	}
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
}
