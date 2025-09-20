#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int xstrlen(char *);
void xstrcpy(char *, char *);
void xstrcat(char *, char *);
bool xstrcmp(char *, char *);
void show(char *);

int main() {
	char s1[] = "Amith";
	char s2[] = "Fyodor";
	char s3[20];
	int len;

	printf("\n String s1: %s", s1);
	len = xstrlen(s1);
	printf("\n Length of s1: %d", len);

	printf("\n String s2: %s", s2);

	xstrcpy(s3, s1);
	printf("\n Contents in string 3 after copying: %s", s3);

	xstrcat(s3, s2);
	printf("\n Contents in string 3 after concat: %s", s3);
	
	if (xstrcmp(s1, s2))
		printf("\n strings are similar");
	else
		printf("\n strings are not similar");

	return 0;
}

int xstrlen(char *ptr) {
	int i = 0;
	while (*ptr) {
		i++;
		ptr++;
	}
	return i;
}

void xstrcpy(char *to, char *from) {
	while (*from) {
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

void xstrcat(char *s1, char *s2) {
	while (*s1) {
		//printf("\n%c\n", *s1);
		s1++;
	}
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
}

bool xstrcmp(char *s1, char *s2) {
	bool flag = true;
	while (*s1 != *s2) {
		flag = false;
		break;
	}
	return flag;
}
