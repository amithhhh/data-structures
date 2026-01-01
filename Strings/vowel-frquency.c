#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXSIZE 100

struct Element {
	int key;
	int count;
	struct Element *next;
};

void createElement(struct Element**, int);
void print(struct Element*);
void initialize(char*);

int main() {
	char *str = (char *) malloc(sizeof(char) * MAXSIZE);
	int fd[2];
	pid_t pid;
	if (pipe(fd) < 0) {
		perror("Pipe Error.");
		return -1;
	}
	if ((pid =fork()) < 0) {
		perror("Fork Error.");
		return -1;
	} else if (pid > 0) {
		close(fd[0]);
		initialize(str);
		write(fd[1], str, MAXSIZE);
		close(fd[1]);
		wait(NULL);
	} else {
		close(fd[1]);
		char *buffer = (char *) malloc(sizeof(char) * MAXSIZE);
		read(fd[0], buffer, MAXSIZE);
		struct Element *head = NULL;
		while (*buffer != '\0') {
			if ((*buffer =='A')|| (*buffer == 'a')||(*buffer =='E')|| (*buffer == 'e')||(*buffer =='I')||(*buffer == 'i')|| (*buffer =='O')|| (*buffer == 'o')||(*buffer =='U')||(*buffer == 'u')) {
				createElement(&head, (int) *buffer);
			}
			buffer++;
		}
		print(head);
		close(fd[0]);
	}
	return 0;
}

void createElement(struct Element **head, int key) {
	struct Element *temp = *head;
	struct Element *newNode = (struct Element*) malloc(sizeof(struct Element));
	newNode->key = key;
	newNode->count = 1;
	newNode->next = NULL;
	if (*head == NULL) {
		*head = newNode;
	} else { 
			while (temp != NULL) {
				if (temp->key == key) {
					temp->count += 1;
					break;
				}
				if (temp->next == NULL){
					temp->next = newNode;
					break;
				}
				temp = temp->next;
			}
	}
}
void print(struct Element *head) {
	while (head != NULL) {
		printf("%c -> %d\n", (char)head->key, head->count);
		head = head->next;
	}
}
void initialize(char *str) {
	printf("Enter the string: ");
        fgets(str, MAXSIZE, stdin);
        str[strlen(str) - 1] = '\0';
}
