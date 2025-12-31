#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int*);
int find2sum(int*, int);
int **find3sum(int*, int, int*);
void swap(int*, int*);

int main(int argc, char **argv) {
	int a[] = {10, 20, 9, 1, 23, 17, 11, 10, 0, 7};
	int count;
	bubbleSort(a);
	/*for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}*/
	if (find2sum(a, atoi(argv[1])))
		printf("There are elements with sum %d.\n", atoi(argv[1]));
	else
		printf("No element present.\n");
	int **ptr = find3sum(a, atoi(argv[1]), &count);
	for (int i = 0; i < count; i++) {
        	printf("%d %d %d\n", ptr[i][0], ptr[i][1], ptr[i][2]);
        	free(ptr[i]); // free each triplet
    	}
    	free(ptr);
	return 0;
}

int find2sum(int *a, int target) {
	int left = 0;
	int right = 9;
	int flag = 0;
	int sum = 0;
	while (left < right) {
		sum = a[left] + a[right];
		if (sum == target) {
			flag = 1;
			break;
		}
		if (sum < target)
			left++;
		else
			right--;
	}
	return flag;
}

void bubbleSort(int *a) {
	for (int i = 0; i < 10 - 1; i++) {
		for (int j = 0; j < 10 - i - 1; j++) {
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
	}
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int **find3sum(int *a, int target, int *count) {
	int **ptr = malloc(sizeof(int*) * 100);
	int k = 0;
	for (int i = 0; i < 8; i++) {
		int *array = (int *) malloc(sizeof(int) * 3);
		int left = i + 1;
        	int right = 9;
        	int sum = 0;
		while (left < right) {
			sum = a[i] + a[left] +a[right];

			if (sum == target) {
				array[0] = a[left];
				array[1] =  a[right];
				array[2] =  a[i];
				ptr[k++] = array;
				left++; right--;
			}
			if (sum < target)
				left++;
			else
				right--;
		}
	}
	*count = k;
	return ptr;
}
