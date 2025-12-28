#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Element {
	int key;
	int value;
	struct Element *next;
};

struct Element *insert(struct Element*, int key, int value);
struct Element *create(struct Element*, int key);

int main() {
	struct Element *head = NULL;
	char *str = (char *) malloc(sizeof(char) * MAX_SIZE);
	printf("Enter the string: ");
	fgets(str, MAX_SIZE, stdin);
	str[strlen(str) - 1] = '\0';

	for (int i = 0; str[i] != '\0'; i++) {
		head = create(head, (int)str[i]);
	}
	while(head) {
		printf("%c->%d\n", (char)head->key, head->value);
		head = head->next;
	}
	return 0;
}

struct Element *insert(struct Element *temp, int key, int value) {
	struct Element *newNode = malloc(sizeof(struct Element));
	struct Element *head = NULL;
	newNode->key = key;
        newNode->value = value;
	newNode->next = NULL;
	if (temp == NULL) {
		temp = newNode;
		head = temp;
	} else {
		head = temp;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		temp = head;
	}
	return head;
}

struct Element *create(struct Element *temp, int key) {
	struct Element *newNode = (struct Element*) malloc(sizeof(struct Element));
        newNode->key = key; 
        newNode->value = 1; 
        newNode->next = NULL;
	struct Element *head = NULL;
	if (temp == NULL) {
		temp = newNode;
		return temp;
	} else {
		head = temp;
		while(temp != NULL) {
			if (temp->key == key) {
				temp->value += 1;
				return head;
			}
			if (temp->next == NULL) {
				break;
			}
			temp = temp->next;
		}
		temp->next = newNode;
		return head;
	}
}
 
