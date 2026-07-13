#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

/* -------------------- CREATE NODE -------------------- */
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void insert(int value, int pos) {
    struct Node *newNode = createNode(value);
    if (pos == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    } else {
        struct Node *temp = head;
        int i = 1;
        while (i < pos) {
            temp = temp->next;
            i++;

        }
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;

    }
}

struct Node *delete(int pos) {
    struct Node *val;
    if (pos == 1) {
        val = head;
        head = head->next;
        head->prev = NULL;
        return val;
    } else {
        struct Node *temp = head;
        int i = 1;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        val = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    return val;
}

/* -------------------- DISPLAY LIST -------------------- */
void display() {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* -------------------- MAIN -------------------- */
int main() {
    insertAtBeginning(10);
    insertAtBeginning(5);
    insertAtEnd(20);
    insertAtEnd(30);

    display();

    deleteFromBeginning();
    display();

    deleteFromEnd();
    display();

    return 0;
}