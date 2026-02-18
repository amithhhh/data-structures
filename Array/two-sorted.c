#include <stdio.h>
#include <stdlib.h>

int merge_array(int*, int*, int, int*, int);
void print(int*, int);

int main() {
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {6, 7, 8, 9, 10};
	int *c = (int*) malloc(sizeof(int) *(sizeof(a) / sizeof(a[0]) + sizeof(b) / sizeof(b[0])));
	int len = merge_array(c, a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0]));
	print(c, len);
	return 0;
}

int merge_array(int *c, int *a, int len_a, int *b, int len_b) {
	int i, j , k;
	i = j = k = 0;

	while (i < len_a && j < len_b) {
		if (a[i] < b[j]) {
			c[k++] = a[i++];
		} else if (b[j] < a[i]) {
			c[k++] = b[j++];
		} else {
			c[k++] = a[i++];
			c[k++] = b[j++];
		}
	}
	while (i < len_a) {
		c[k++] = a[i++];
	}

	while (j < len_b) {
		c[k++] = b[j++];
	}
	return k;
}


void print(int *a, int len) {
	int i = 0;
	while (i < len) {
		printf("%d\t", a[i]);
		i += 1;
	}
	printf("\n");
}

