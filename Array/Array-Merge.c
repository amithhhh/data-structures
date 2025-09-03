#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define MAX1 5
#define MAX2 7


int* create(int);
void sort(int*, int);
void display(int*, int);
int* merge(int*, int*);

int main() {
	int *a, *b, *c;
	a = create(MAX1);
	sort(a, MAX1);
	display(a, MAX1);
	printf("\n");

	b = create(MAX2);
	sort(b, MAX2);
	display(b, MAX2);
	printf("\n");

	c = merge(a, b);
	display(c, MAX1 + MAX2);	

	return 0;
}

int* create(int size) {
	int i, *arr;
	arr = (int *) malloc(sizeof(int) * size);
	for(i = 0; i < size; i++) {
		printf("\nEnter the element no. %d >", i + 1);
		scanf("%d", arr + i);
	}
	printf("\n Succesfully updated values.\n");
	return arr;
}

void display(int *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d\t", *(arr + i));
	}
}

void sort(int *arr, int size) {
	int i, j, temp;
	
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (*(arr + i) > *(arr + j)) {
				temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}

int* merge(int *a, int *b) {
	int *arr;
	int i, k, j;
	int size = MAX1 + MAX2;
	arr = (int *) malloc(sizeof(int) * size);
	
	for (k = 0, j = 0, i = 0; i <= size; i++) {
		if (*(a + k) < *(b + j)) {
			*(arr + i) = *(a + k);
			k++;

			if (k >= MAX1) {
				for (i++; j < MAX2; i++, j++) {
					*(arr + i) = *(b + j);
				}
			}
		} else {
			*(arr + i) = *(b + j);
			j++;

			if (j >= MAX2) {
				for (k++; k < MAX1; k++, i++) {
					*(arr + i) = *(a + k);
				}
			}
		}
	}
	return arr;
}
