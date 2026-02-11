
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

//^\s*(static\s+)?(int|float|double|char|long|short)\s+([^;()]+);


int main(int argc, char **argv) {
	if (argc < 2) {
		perror("[-]Usage: ./static-read <path of the c file>.");
		exit(-1);
	}
	FILE *file = fopen(argv[1], "r");
	if (!file) {
		printf("[-]Error, Sorry, Please verify the path.\n");
	} else {
		char *line = NULL;
		size_t len = 0, type_size = 0, total_size = 0;
		ssize_t read;
		regex_t regex;
		regmatch_t match[4];
		char *ptr;

		regcomp(&regex,
    "^\\s*(static\\s+)?(int|float|double|char|long|short)\\s+([^;()]+);",
    REG_EXTENDED);


		while ((read = getline(&line, &len, file)) != -1) {
			ptr = line;
			if (regexec(&regex, line, 4, match, 0) == 0) {
				int start = match[2].rm_so;
				int end = match[2].rm_eo;
				
				char var[end - start + 1];
				strncpy(var, ptr + start, end - start);
				var[end - start] = '\0';
	
				if (strcmp(var, "int") == 0) {
					type_size = sizeof(int);
				} else if (strcmp(var, "float") == 0) {
					type_size = sizeof(float);
				} else if (strcmp(var, "char") == 0) {
					type_size = sizeof(char);
				} else if (strcmp(var, "double") == 0) {
					type_size = sizeof(double);
				}

				int v_start = match[3].rm_so;
				int v_end = match[3].rm_eo;

				char vars[v_end - v_start + 1];

        			strncpy(vars, line + v_start, v_end - v_start);
        			vars[v_end - v_start] = '\0';

				char *token = strtok(vars, ",");

				while (token != NULL) {
					while (*token == ' ')
						token++;
					char *equal = strchr(token, '=');
					if (equal)
						*equal = '\0';


					char *bracket = strchr(token, '[');
					if (bracket) {
						int arr_size;
						sscanf(bracket, "[%d]", &arr_size);
						total_size += type_size * arr_size;
					} else {
						total_size += type_size;
					}
					token = strtok(NULL, ",");
				}
			}
		}
		printf("Total static memory need for %s is: %d\n", argv[1], total_size);
		return 0;
	}
}
