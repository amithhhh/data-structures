#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define SIZE 1000
#define PATTERN "^[a-zA-Z_][a-zA-Z0-9_*\t ]+[ \t]+[a-zA-Z_][a-zA-Z0-9_]*[ \t]*\\([^)]*\\)[ \t]*\\{"
#define PATTERN2 "^[a-zA-Z_][a-zA-Z0-9_*\\s]*\\s+[a-zA-Z_][a-zA-Z0-9_]*\\s*\\([^)]*\\)"

int TOP = -1;

char *STACK[SIZE];

void push(char*);
void pop();

int main(int argc, char **argv) 
{
	
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
		regex_t regex, regex2;
		char *curr = NULL;
		char *prev = NULL;
		int count = 0;

		regcomp(&regex, PATTERN, REG_EXTENDED);
		regcomp(&regex2, PATTERN2, REG_EXTENDED);

		while ((read = getline(&curr, &len, file)) != -1) {
			if ((regexec(&regex, curr, 0, NULL, 0) == 0)) {
				STACK[++TOP] = "{";
			} else if ((prev != NULL) && (regexec(&regex2, prev, 0, NULL, 0) == 0) && (strcmp(curr, "{\n") == 0)) {
				STACK[++TOP] = "{";
			}
			if (strcmp(curr, "}\n") == 0) {
				TOP--;
				if (TOP == -1)
					count++;
			}
			if (prev)
				free(prev);
			prev = strdup(curr);
			free(curr);
		}
		printf("The total userdefined function used here: %d\n", count - 1);
		regfree(&regex);
		regfree(&regex2);
		fclose(file);
	}
	return 0;
}

