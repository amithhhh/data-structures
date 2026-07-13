#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *getMiddle(Node *head) {
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *sortMerge(Node *left, Node *right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Node *result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = sortMerge(left->next, right);
    } else {
        result = right;
        result->next = sortMerge(left, right->next);
    }
    return result;
}

Node *merge_sort(Node *head) {
    if (head == NULL || head->next == NULL) return head;
    Node *middle = getMiddle(head);
    Node *nextMiddle = middle->next;
    middle->next = NULL;

    Node *left = merge_sort(head);
    Node *right = merge_sort(nextMiddle);

    return sortMerge(left, right);

}

int main() {
    Node *head = malloc(sizeof(Node));
    Node *n2 = malloc(sizeof(Node));
    Node *n3 = malloc(sizeof(Node));
    Node *n4 = malloc(sizeof(Node));

    head->data = 40;
head->next = n2;

n2->data = 30;
n2->next = n3;

n3->data = 20;
n3->next = n4;

n4->data = 10;
n4->next = NULL;

    Node *result = merge_sort(head);


    while (result != NULL) {
        printf("%d\t", result->data);
        result = result->next;
    }
    return 0;
}