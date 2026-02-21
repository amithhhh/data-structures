#include <limits.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000000

int main() {
	srand(time(0));
	int a[SIZE];
	for (int i = 0; i < SIZE; i++) {
		a[i] = rand() % 10000;
	}
	int n = sizeof(a) / sizeof(a[0]);
	int target = 100;
	int start = 0, end = 0, sum = 0;
	clock_t start_time = clock();
	int currLen = 0, minLen = INT_MAX;

	for (int i = 0; i < n; i++) {
		sum += a[i];
		while (sum >= target) {
			currLen = i - start + 1;
			if (currLen < minLen) {
				minLen = currLen;
			}
			sum -= a[start];
			start++;
		}
	}
	clock_t end_time = clock();
	clock_t time = end_time - start_time;
	printf("%d\n", minLen);
	printf("Time Taken: %f", (double)time / CLOCKS_PER_SEC);
	return 0;
}
