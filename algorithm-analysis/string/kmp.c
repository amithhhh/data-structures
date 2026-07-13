#include <stdio.h>

void computLPS(char pattern[], int lps[]) {
	lps[0] = 0;
	int i = 1, len = 0;

	while (i < strlen(pattern)) {
		if (pattern[i] == pattern[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
}
