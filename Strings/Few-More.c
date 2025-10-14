#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int search(char*, char);
int isEquals(char*, char*);
int isSmaller(char*, char*);
int isGreater(char*, char*);
char* getSub(char*, int, int);
char* leftSub(char*, int);
char* rightSub(char*, int);
void lower(char*);
void upper(char*);
void reverse(char*);
int replace(char*, char, char);

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
	
	i = isSmaller(s1, s2);

	if (i == 1)
		printf("\n String s1 is smaller than string s2");
	else
		printf("\n String s1 is not smaller than string s2");

	i = isGreater(s1, s2);

        if (i == 1)
                printf("\n String s1 is greater than string s2");
        else
                printf("\n String s1 is not greater than string s2");

	printf("\nString 3: %s", s3);

	s = getSub(s3, 5, 7);

	printf("\nSub string: %s\n", s);
	//free(s);
	
	s = leftSub(s3, 10);
	printf("\nLeft Most String: %s\n", s);

	s = rightSub(s3, 10);
        printf("\nRight Most String: %s\n", s);

	upper(s3);
	printf("\nString in upper case: %s", s3);

	lower(s3);
	printf("\nString in lower case: %s", s3);

	reverse(s3);
	printf("\nString in reversed form: %s\n", s3);

	if (replace(s3, 'f', 'z'))
		printf("\n%s", s3);
	else
		printf("\nNot possible");

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

int  isSmaller(char *s, char *t) {
	while (*t) {
		if (*s != *t) {
			if (*s < *t)
				return 1;
			else
				return 0;
		}
		t++;
		s++;
	}
	return 0;
}

int isGreater(char *s, char *t) {
	while (*t) {
		if (*s != *t) {
			if (*s > *t) 
				return 1;
			else
				return 0;
		}
		s++;
		t++;
	}
	return 0;
}


char* getSub(char *s, int spos, int n) {
	int i = 0;
	char *str = s + spos;
	char *t = (char *) malloc(n + 1);

	while (i < n) {
		t[i] = *str;
		str++;
		i++;
	} 
	t[i] = '\0';
	return t;
}

char* leftSub(char *s, int n) {
	char *t = (char *) malloc(n + 1);
	int i = 0;
	char *a;
	a = t;

	while (i < n) {
		*t = *s;
		t++;
		s++;
		i++;
	}
	*t = '\0';
	t = a;
	return t;
}

char* rightSub(char *str, int n) {
	char *t = (char *) malloc(n + 1);
	int l = strlen(str);
	char *a;
	char *s = str + (l - n);
	a = t;
	int i = 0;
	while (i < n) {
		*t = *s;
		s++;
		t++;
		i++;
	}
	*t = '\0';
	t = a;
	return t;
}

void upper(char *s) {
	while (*s) {
		if (*s >= 97 && *s <= 123)
			*s -= 32;
		s++;
	}
}

void lower(char *s) {
	while (*s) {
		if (*s >= 65 && *s <= 91)
			*s += 32;
		s++;
	}
}

void reverse(char *str) {
	int l = strlen(str);
	char ch;
	char *t = str + l - 1;
	int i = 0;

	while (i < l/2) {
		ch = *str;
		*str = *t;
		*t = ch;

		str++;
		t--;
		i++;
	}
}

int replace(char *str, char oldch, char newch) {
	while (*str) {
		if (*str == oldch) {
			*str = newch;
			return 1;
		}
		str++;
	}
	return 0;
}

int setat(char *str, char ch, int i) {
	if (i < 0 || strlen(str) < i) {
		return 0;
	}
	*(str + i) = ch;
	return 1;
}
