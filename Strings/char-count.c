#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 4096

int main() {
	int c;
	char *sentence = (char *) malloc(sizeof(char) * MAXLINE);
	printf("pointer initialized at %p\n", sentence);
	printf("Enter the string: ");
	char *copy = sentence;
	int frequency[26] = {0};
	//scanf("%s", sentence);
	
	while ((c = getc(stdin)) != EOF) {
		*copy = c;
		copy++;
	}
	*copy = '\0';
	printf("\n Specified String: %s", sentence);

	//actual logic
	for (int i = 0; sentence[i] != '\0'; i++) {
		char ch = tolower(sentence[i]);
		if (ch >= 'a' && ch <= 'z')
			frequency[ch - 'a']++;
	}

	for (int j = 0; j < 26; j++) {
		printf("%c: %d\n", 'a' + j, frequency[j]);
	}

	return 0;
}
