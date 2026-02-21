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
	int window_sum = a[0] + a[1] + a[2];
	int  max_sum = window_sum;
	//sliding-window-problem
	
	for (int i = k; i < n; i++) {
		window_sum = window_sum - a[i - k] + a[i];
		if (window_sum > max_sum) {
			max_sum = window_sum;
		} 
	}
	
	clock_t start = clock();
	
	clock_t end = clock();
	clock_t time = end - start;
	printf("%d\n", max_sum);
	printf("Time Taken: %f", (double)time / CLOCKS_PER_SEC);
	return 0;
}
