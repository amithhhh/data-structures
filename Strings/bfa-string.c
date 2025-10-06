#include <stdio.h>
#include <string.h>

int xstrsearch(char *, char *);
void show();

int main() {
	char s1[] = "NagpurKicit";
	char s2[] = "Kicit";
	int pos;
	pos = xstrsearch(s1, s2);
	printf("\n Pattern string found at the position: %d\n", pos);
	return 0;
}

int xstrsearch(char *s1, char *s2) {
	int i, j, k;
	int l1 = strlen(s1);
	int l2 = strlen(s2);

	for (i = 0; i <= l1-l2; i++) {
		j = 0;
		k = i;

		while ((s1[k] == s2[j]) && (j < l2)) {
			k++;
			j++;
		}
		if (j == l2)
			return i;
	}
	return -1;
}
