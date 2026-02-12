#include <regex.h>
#include <stdio.h>

int main() {
	regex_t regex;
	int result;

	regcomp(&regex, "^[0-9]+$", REG_EXTENDED);
	result = regexec(&regex, "12345", 0, NULL, 0);

	if (result == 0) {
		printf("Success\n");
	} else {
		printf("Error\n");
	}
	return 0;
}
