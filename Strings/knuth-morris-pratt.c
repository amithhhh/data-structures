#include <stdio.>
#include <string.h>

void computeLPSArray(char*, int, int*);
void KMPSearch(char*, char*);

int main() {
	return 0;
}

void computeLPSArray(char *p, int m, int *lps) {
	int len = 0;
	lps[0] = 0
	int i = 1;

	while (i < m) {
		if (p[i] == p[len]) {
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

void KMPSearch(char *P,char *T) {
	int m = strlen(P);
	int n = strlen(T);

	int lps[m];

	computeLPSArray(P, m, lps);
}
