#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
	srand(time(NULL));
	int *a = (int *)malloc(sizeof(int) * SIZE);
	for (int i = 0; i < SIZE; i++) {
		a[i] = rand() % 1000;
	}
	for (int i = 1; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < SIZE; i++) {
                printf("%d\t", a[i]);
        }
	return 0;
}
