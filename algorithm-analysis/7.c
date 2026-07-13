#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
int FRONT = -1;
int REAR = -1;

int *QUEUE;

void init();
void queue_free();
void operation();
bool EnQueue(int);
bool DeQueue(int*);
void display();

int main() {
	init();
	operation();
	return 0;
}

void init() {
	QUEUE = (int *)malloc(SIZE * sizeof(int));
	printf("[+]Successfully initialized Queue\n");
}

void queue_free() {
	free(QUEUE);
	printf("[+]Successfully destroyed Queue.\n");
}

void operation() {
	int choice;
	int val;
	while (1) {
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("Please choose from the following menu(push is the default): \n");
		printf("[1]: Enqueue\n");
		printf("[2]: Dequeue\n");
        	printf("[3]: display\n");
		printf("[4]: exit\n");
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		scanf("%d", &choice);

		switch (choice) {
			case 1:		printf("Enter the value for enqueuing: ");
					scanf("%d", &val);
					if (EnQueue(val))
						printf("[+]%d operation successful.\n",val);
					else
						printf("[-]Queue is full.\n");
					break;

			case 2:		if (DeQueue(&val))
						printf("[+]Dequeued value: %d\n", val);
					else
						printf("[-]Queue is empty.\n");
					break;
			
			case 3:		display();
					break;
		
			case 4:		queue_free();
					break;
		}
	}
}	

bool EnQueue(int val) {
	int choice;
	printf("Enter the side to which the value to be inserted(1-rear, 0-front): ");
	scanf("%d", &choice);
	if ((REAR + 1) % SIZE == FRONT) return false;
	if (REAR == -1 && FRONT == -1) { 
                 	FRONT = REAR = 0;
			QUEUE[REAR] = val;
			return true;
        }
	if (choice) {
		REAR = (REAR + 1) % SIZE;
		QUEUE[REAR] = val;
	} else {
		FRONT = (FRONT - 1 + SIZE) % SIZE;
		QUEUE[FRONT] = val;
	}
	return true;

}

bool DeQueue(int *val) {
	int choice;
        printf("Enter the side to which the value to be inserted(1-rear, 0-front): ");
        scanf("%d", &choice);

	if (FRONT == -1 || REAR == -1) return false;	
	else if (FRONT == REAR) {
		*val = QUEUE[FRONT];
		FRONT = REAR = -1;
		return true;
	}
	if (choice) {
		*val = QUEUE[REAR];
		REAR = (REAR - 1 + SIZE) % SIZE;
	} else {
		*val = QUEUE[FRONT];
		FRONT = (FRONT + 1) % SIZE;
	}
	return true;
}

void display() {
	if (REAR == -1 || FRONT == -1) {
		printf("[-]Queue is empty.\n");
		return;
	} else {
		for (int i = FRONT; i <= REAR; i++) {
			printf("%d\t", QUEUE[i]);
		}
	}
	printf("\n");
}
