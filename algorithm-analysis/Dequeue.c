#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;

#define SIZE 5
int queue[SIZE];
int size = 0;

void insert(int val) {
	int choice;
	printf("Enter the choice (1-rear, 0-front): ");
	scanf("%d", &choice);
	if (front == -1 && rear == -1) {
		front = rear = 0;
		queue[rear] = val;
	} else if ((rear + 1) % SIZE == front) {
		printf("Queue Overflow.\n");
		return;
	} else {
		if (choice) {
			rear = (rear + 1) % SIZE;
			queue[rear] = val;
		} else {
			front = (front - 1 + SIZE) % SIZE;
			Queue[front] = val;
		}
	}
}

int delete() {
	int choice;
	int val;
        printf("Enter the choice (1-rear, 0-front): ");
        scanf("%d", &choice);
	if (front == -1) {
		printf("Queue Overflow.\n");
                return -1;
	} else if (front == rear) {
		val = queue[front];
		front = rear = -1;
	} else {
		if (choice) {
			val = queue[rear];
			rear = (rear - 1 + SIZE) % SIZE;
		} else {
			val = queue[front];
			front = (front + 1) % SIZE;
		}
	}
	return val;
}


void enqueue(int size, int val) {
	int i = size;
	queue[size] = val;
	size++;
	while (i > 0) {
		int parent = (i - 1) / 2;
		if (a[i] > a[parent]) {
			swap(a[i], a[parent]);
			i = parent;
		} else {
			break;
		}
	}
	
}

int dequeue(int size) {
	int val = a[0];
	size--;
	a[0] = a[size];
	int i = 0;
	
	while (1) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < size && a[largest] < a[left]) {
			largest = left;
		}
		if (right < size && a[largest] < a[right]) {
			largest = right;
		}
		if (largest == i) break;
		swap(a[largest], a[i]);
		i = largest;
	}
}
