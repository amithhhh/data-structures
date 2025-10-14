#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXLINE 4096

int main() {
	char *str = (char *) malloc(sizeof(char) * MAXLINE);
	char *substr = (char *) malloc(sizeof(char) * MAXLINE);
	int i;
	printf("\nEnter the string: ");
	fgets(str, MAXLINE, stdin);
	str[strcspn(str, "\n")] = '\0';
	printf("\nEnter the substring: ");
	fgets(substr, MAXLINE, stdin);
	substr[strcspn(substr, "\n")] = '\0';
	printf("%s\n", str);
	printf("%s\n", substr);

	for (i = 0; i <= (strlen(str) - strlen(substr)); i++) {
		bool flag = true;
		for (int j = 0; j < strlen(substr); j++) {
			if (str[i + j] != substr[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("\nindex of substr found at location: %d\n", i);
			break;
		}
	}
	printf("\n%d\n", i);

	for (int j = (i + strlen(substr)); j > i; j--) {
		str[j-1] = str[j];
	}
	
	for (int k = 0; k < strlen(str) - strlen(substr); k++)
		printf("%c", str[k]);

	return 0;
}
