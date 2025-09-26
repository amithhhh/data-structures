#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *name[6];
	char str[20];
	int i;

	for (i = 0; i < 6; i++) {
		printf("\nEnter the string: ");
		fgets(str, 20, stdin);
		name[i] = (char *) malloc(strlen(str) + 1);
		strcpy(name[i], str);
	}

	printf("\n The strings are: \n");

	for (i = 0; i < 6; i++)  {
		printf("\n%s", name[i]);
		free(name[i]);
	}
	return 0;
}

