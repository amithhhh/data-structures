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
	for (int i = 0; i < SIZE - 1; i++) {
		int min = a[i];
		int pos = i;
		for (int j = i; j < SIZE; j++) {
			if (a[j] < min) {
				min = a[j];
				pos = j;
			}
		}
		a[pos] = a[i];
		a[i] = min;
	}
	for (int i = 0; i < SIZE; i++) {
                printf("%d\t", a[i]);
        }
	return 0;
}
