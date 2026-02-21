//Count number of subarrays with sum = K

#include <stdio.h>
#include <stdlib.h>

int count_sub_array(int*, int, int);


int main() {
	int arr[] = {2,3,1,2,4,3};
    	int target = 7;
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("The number of substring with sum = %d is %d", target, count_sub_array(arr, n, target));
}

int count_sub_array(int *arr, int size, int target) {
	int current_sum = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		current_sum += arr[i];
		if (current_sum == target)
			count++;
		else if ((current_sum - target) == target)
			count++;
	}
	return count;
} 
