#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000000

int main() {
	srand(time(0));
	int a[SIZE];
	for (int i = 0; i < SIZE; i++) {
		a[i] = rand();
	}
	int k = 3;
	int n = sizeof(a) / sizeof(a[0]);
	int window_sum = 0, max_sum = 0;
	//Brute-Force Approach
	clock_t start = clock();
	for (int i = 0; i < n - k; i++) {
		for (int j = i; j <= i + k - 1; j++) {
			window_sum += a[j];
		}
		if (window_sum > max_sum) {
                        max_sum = window_sum;
                }
		window_sum = 0;

	}
	clock_t end = clock();
	clock_t time = end - start;
	printf("%d\n", max_sum);
	printf("Time Taken: %f", (double)time / CLOCKS_PER_SEC);
	return 0;
}
