#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int value;
    int priority;
} Node;

typedef struct {
    Node arr[MAX];
    int size;
} PriorityQueue;

// Initialize
void initQueue(PriorityQueue *pq) {
    pq->size = 0;
}

// Check if empty
int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// Check if full
int isFull(PriorityQueue *pq) {
    return pq->size == MAX;
}

// Insert element
void enqueue(PriorityQueue *pq, int value, int priority) {
    if (isFull(pq)) {
        return;
    }
    Node node;
    node.value = value;
    node.priority = priority;

    pq->arr[pq->size] = node;
    int i = pq->size;
    pq->size++;

    

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (pq->arr[parent].priority > pq->arr[i].priority) {
            Node temp;
            temp = pq->arr[parent];
            pq->arr[parent] = pq->arr[i];
            pq->arr[i] = temp;
        } else {
            break;
        }
        i = parent;
    }

}

// Remove highest-priority element
Node dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        Node temp = {-1, -1};
        return temp;
    }
    Node node = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1]; 
    pq->size--;

    int parent = 0, smallest = 0;
    while (1) {
        smallest = parent;
        int left = (parent * 2) + 1;
        int right = (parent * 2) + 2;

        if (left < pq->size && pq->arr[smallest].priority > pq->arr[left].priority) {
            smallest = left;
        }

        if (right < pq->size && pq->arr[smallest].priority > pq->arr[right].priority) {
            smallest = right;
        }
        if (smallest == parent) break;

        Node temp;
        temp = pq->arr[parent];
        pq->arr[parent] = pq->arr[smallest];
        pq->arr[smallest] = temp;

        parent = smallest;
    }
    return node;
}

// Peek
Node peek(PriorityQueue *pq) {
    Node temp = {-1, -1};

    if (isEmpty(pq))
        return temp;

    return pq->arr[0];
}

// Display
void display(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Value\tPriority\n");

    for (int i = 0; i < pq->size; i++) {
        printf("%d\t%d\n",
               pq->arr[i].value,
               pq->arr[i].priority);
    }
}

int main() {

    PriorityQueue pq;

    initQueue(&pq);

    // Test here

    return 0;
}