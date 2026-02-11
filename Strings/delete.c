#include <stdio.h>

int min(int, int);

int main() {
	char s[] = "aabaaaabbbbab";
	int b_count = 0, deletions = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == 'b')
			b_count++;
		else
			deletions = min(deletions + 1, b_count);
	}
	printf("Number of deletions: %d\n", deletions);
	return 0;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}
