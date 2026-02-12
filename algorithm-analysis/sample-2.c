#include <stdio.h>
#include <regex.h>
#include <string.h>

int main() {
	char input[] = "int a, b = 10, c = 20, d, double=30.0, float=30.0";
	regex_t regex;
	regmatch_t match;
	size_t size = 0;
	regcomp(&regex, "[a-zA-Z_][a-zA-Z0-9_]*", REG_EXTENDED);

	char *ptr = input;
	
	while (regexec(&regex, ptr, 1, &match, 0) == 0) {
		int start = match.rm_so;
		int end = match.rm_eo;

		char var[20];
		strncpy(var, ptr + start, end - start);
		var[end - start] = '\0';

		if (strcmp(var, "int") != 0) {
			size += sizeof(int);
		} 
		ptr += end;
	}
	printf("Total Integer size: %d", size);
	return 0;
}
