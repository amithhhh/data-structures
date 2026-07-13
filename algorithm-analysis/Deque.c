#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Deque;

// Initialize deque
void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if deque is empty
int isEmpty(Deque *dq) {
    return (dq->front == -1);
}

// Check if deque is full
int isFull(Deque *dq) {
    return ((dq->front == 0 && dq->rear == MAX - 1) ||
            (dq->front == dq->rear + 1));
}

// Insert at front
void enqueueFront(Deque *dq, int value) {
    if (isFull(dq)) {
        return;
    } if (dq->front == -1 && dq->rear == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = value;
}

// Insert at rear
void enqueueRear(Deque *dq, int value) {
    if (isFull(dq)) {
        return;
    } if (dq->front == -1 && dq->rear == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = value;
}

// Delete from front
int dequeueFront(Deque *dq) {
    int val = -1;
    if (isEmpty(dq)) {
        return val;
    } if (dq->front == dq->rear) {
        val = dq->arr[dq->front];
        dq->front = dq->rear = -1;
    } else {
        val = dq->arr[dq->front];
        dq->front = (dq->front + 1) % MAX;
    }
    return val;
}

// Delete from rear
int dequeueRear(Deque *dq) {
    int val = -1;
    if (isEmpty(dq)) {
        return val;
    } if (dq->rear == dq->front) {
        val = dq->arr[dq->rear];
        dq->front = dq->rear = -1;
    } else {
        val = dq->arr[dq->rear];
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
    return val;
}

// Get front element
int getFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->front];
}

// Get rear element
int getRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

// Display deque
void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    int i = dq->front;

    printf("Deque: ");

    while (1) {
        printf("%d ", dq->arr[i]);

        if (i == dq->rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    // Test your implementation here

    return 0;
}