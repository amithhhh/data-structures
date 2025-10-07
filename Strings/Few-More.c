#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int search(char*, char);
int isEquals(char*, char*);
int isSmaller(char*, char*);
int isGreater(char*, char*);
char* getSub(char*, int, int);

int main() {
	char s1[] = "Hello";
	char s2[] = "Hello World";
	char s3[] = "Four hundred thirty two";
	char ch, *s;
	int i;

	printf("\nString1 s1: %s", s1);

	printf("\nEnter the character to search: ");
	scanf("%c", &ch);

	i = search(s1, ch);

	if (i != -1)
		printf("\nThe first occurance of character %c is found at index no %d\n", ch, i);
	else
		printf("\n 404 Error Not found");

	i = isEquals(s1, s2);

	if (i == 1)
		printf("\n They are identical");
	else
		printf("\n 404 Error not match");

	return 0;
}

int search(char* s1, char ch) {
	int i = 0;
	while (*s1) {
		if (*s1 == ch)
			return i + 1;
		s1++;
		i++;
	}
	return -1;
}

int isEquals(char *s, char *t) {
	while (*s || *t) {
		if (*s != *t)
			return 0;
		s++;
		t++;
	}
	return 1;
}
