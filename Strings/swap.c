#include <stdio.h>
#include <string.h>

#define MAX 6

char *names[MAX];
int count;

int add(char *);
void swap(int, int);
void show();

int main() {
	int flag;
	
	flag = add("akshay");
	flag = add("parag");
	flag = add("raman");
	flag = add("srinivas");
	flag = add("gopal");
	flag = add("rajesh");
	
	printf("\nNames before swapping:\n");
	show();

	swap(2, 3);
	
	printf("\nNames after swapping:\n");
	show();
	
	return 0;	
}

int add(char *s) {
	if (count < MAX) {
		names[count] = s;
		count++;
		return 1;
	}
	return 0;
}

void swap(int i, int j) {
	char *temp;

	temp = names[i];
	names[i] = names[j];
	names[j] = temp;
}

void show() {
	int i;
	for (i = 0; i < MAX; i++) {
		printf("%s\n", names[i]);
	}
}
