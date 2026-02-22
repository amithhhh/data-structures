//Count number of subarrays with sum = K

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
	int key;
	int val;
	struct Node *next;
};

#define SIZE 1000

struct Node *HashTable[SIZE] = {NULL};

int hash(int);
void put(int);
int get(int);
int count_sub_array(int*, int, int);
int* get_prefix_array(int*, int);

int main() {
	int arr[] = {1, 2, 3};
	int k = 3;
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("The total amount of sub array = %d", count_sub_array(arr, n, k));
	return 0;
}

int* get_prefix_array(int *a, int size) {
	int *prefix = (int*) malloc(sizeof(int) * size);
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
		prefix[i] = sum;
	}
	return prefix;
}

int hash(int key) {
	return abs(key) % SIZE;
}

void put(int key) {
	int index = hash(key);
	struct Node *temp = HashTable[index];

	while (temp != NULL) {
		if (temp->key == key) {
			temp->val++;
			return;
		}
		temp = temp->next;
	}
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->val = 1;
	newNode->next = HashTable[index];
	HashTable[index] = newNode;

}

int get(int key) {
	int index = hash(key);
	struct Node *temp = HashTable[index];

	while (temp != NULL) {
		if (temp->key == key) return temp->val;
		temp = temp->next;
	}
	return 0;
}


int count_sub_array(int *a, int n, int k) {
	int *prefix = get_prefix_array(a, n);
	int count = 0;
	put(0);
	for (int i = 0; i < n; i++) {
		count += get(prefix[i] - k);
		put(prefix[i]);
	}
	return count;
}
