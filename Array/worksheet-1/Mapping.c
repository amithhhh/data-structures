#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mapping {
	char *word;
	int value;
};

struct mapping numbers[] = {
	{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6},
	{"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10}, {"eleven", 11}, {"twelve", 12}, 
	{"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
	{"eighteen", 18}, {"ninteen", 19}, {"twenty", 2}, {"thirty", 3}, {"forty", 4},
	{"fifty", 5}, {"sixty", 6}, {"seventy", 7}, {"eighty", 8}, {"ninty", 9}, {"hundred", 100}, {"thousand", 1000}
};

int getVal(char *token);

int main() {
	char input[200];
	printf("Enter numbers in words: ");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = 0;

	char *token = strtok(input, " ");
	int val;
	while (token != NULL) {
		val = getVal(token);
		printf("%d", val);
		token = strtok(NULL, " ");
	}
	return 0;
}

int getVal(char *token) {
	for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
		if (strcmp(token, numbers[i].word) == 0) {
			return numbers[i].value;
		}
	}
	return -1;
}
