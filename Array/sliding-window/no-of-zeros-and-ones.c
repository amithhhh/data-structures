#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000

struct Node{
	int key;
	int value;
	struct Node *next;
};

struct Node *HashMap[SIZE];

int hash(int);
void put(int);
int get(int);
int count_sub_array(int*, int);
int* get_prefix_array(int*, int);

int main() {
	int a[] = {1, 1, 0, 0, 1, 1, 0, 1, 0};
	int size = sizeof(a) / sizeof(a[0]);
	printf("The total number: %d", count_sub_array(a, size));
	return 0;
}

int hash(int key) {
	return abs(key) % SIZE;
}

int get(int key) {
	int idx = hash(key);
	struct Node *node = HashMap[idx];

	while (node != NULL) {
		if (node->key == key)
			return node->value;
		node = node->next;
	}
	return 0;
}

void put(int key) {
	int idx = hash(key);
	struct Node *node = HashMap[idx];

	while (node != NULL) {
		if (node->key == key) {
			node->value++;
			return;
		}
		node = node->next;

	}
	struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->value = 1;
        newNode->next = HashMap[idx];
        HashMap[idx] = newNode;
	return;

}

int count_sub_array(int *a, int size) {
	int count = 0;
	int sum = 0;
	int *prefix = get_prefix_array(a, size);
	put(0);
	for (int i = 0; i < size; i++) {
		count += get(prefix[i]);
		put(prefix[i]);
	}
	return count;
}

int* get_prefix_array(int *a, int size) {
	int *prefix = (int *) malloc(sizeof(int) * size);
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] == 0) {
			sum +=  -1;
		} else {
			sum += a[i];
		}
		prefix[i] = sum;
	}
	return prefix;
}
