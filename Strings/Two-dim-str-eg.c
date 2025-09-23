#include <stdio.h>
#include <string.h>

#define MAX1 6
#define MAX2 10

char masterlist[MAX1][MAX2];
int count;

int add(char *);
int find(char *);

void main() {
	char amith[MAX2];
	int flag;

	flag = add("akshay");

	if (flag == 0)
		printf("\n Unable to add string");

	printf("\n Enter your name: ");
	fgets(amith, sizeof(amith), stdin);

	amith[strcspn(amith, "\n")] = '\0';

	flag = find(amith);

	if (flag)
		printf("\nAllowed");
	else
		printf("\n sorry");
}

int add(char *s) {
	if (count < MAX1) {
		if (strlen(s) < MAX2) {
			strcpy(&masterlist[count][0], s);
			count++;
			return 1;
		}
	}
	return 0;
}

int find(char *s) {
	int flag = 0, i;

	for (i = 0; i < count; i++) {
		if (strcmp(&masterlist[i][0], s) == 0) {
			flag = 1;
			break;
		}
	}
	return flag;
}
