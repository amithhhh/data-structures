#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define SIZE 1000
#define PATTERN "^[a-zA-Z_][a-zA-Z0-9_*\t ]+[ \t]+[a-zA-Z_][a-zA-Z0-9_]*[ \t]*\\([^)]*\\)[ \t]*\\{"

int top = -1;

char* STACK[SIZE];

int main(int argc, char **argv) {
	
	if (argc < 2) {
		perror("[-]Please specify the path.\n");
		return -1;
	}

	FILE *file;

	if ((file = fopen(argv[1], "r")) == NULL) {
		perror("[-] Read error.\n");
		return -1;
	} else {
		ssize_t read;
		size_t len;
		regex_t regex;
		char *prev = NULL;
		char *curr = NULL;
		int count = 0;

		regcomp(&regex, PATTERN, REG_EXTENDED);

		while ((read = getline(&curr, &len, file)) != -1) {
			if (regexec(&regex, curr, 0, NULL, 0) == 0) {
				count++;
			}
		}
		printf("The total userdefined function used here: %d\n", count - 1);
		regfree(&regex);
	}
	return 0;
}
