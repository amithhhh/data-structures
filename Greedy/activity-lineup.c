#include <stdio.h>

void sort(int*, int*, int);

int main() {
	int start_arr[] = {1, 2, 3, 0, 5, 8};
	int finish_arr[] = {3, 4, 5, 6, 7, 9};
	int count = 0;
	int last_finish = 0;
	int size = sizeof(start_arr) / sizeof(start_arr[0]);

	sort(start_arr, finish_arr, size);

	for (int i = 0; i < size; i++) {
		int start_time = start_arr[i];
		int finish_time = finish_arr[i];
		
		if (start_time >= last_finish) {
			count++;
			last_finish = finish_time;
		}
	}
	printf("%d\n", count);
	return 0;
}

void sort(int* start, int* end, int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (end[j] > end[j + 1]) {
				temp = end[j];
				end[j] = end[j + 1];
				end[j + 1] = temp;

				temp = start[j];
				start[j] = start[j + 1];
				start[j + 1] = temp;
			}
		}
	}
}
