#include <stdio.h>
#define MAX 10

void findMode(int *a);

int main() {
	int a[MAX], i;
	for (i = 0; i < MAX; i++) {
		printf("\nEnter the number in position %d\n",i + 1);
		scanf("%d", &a[i]);
	}
	findMode(a);
	return 0;
}

void findMode(int *a) {
	int maxFreq, currentFreq, i, j, mode, isUnique;
	mode = a[0];
	isUnique = 1;
	i = j = currentFreq = maxFreq = 0;

	for (i = 0; i < MAX; i++) {
		currentFreq = 0;
		for (j = 0; j < MAX; j++) {
			if (a[i] == a[j])
				currentFreq++;
		}
		if (currentFreq > maxFreq) {
			maxFreq = currentFreq;
			mode = a[i];
			isUnique = 1;
		} else if (currentFreq == maxFreq && a[i] != mode) {
			isUnique = 0;
		}
	}
	if (isUnique)
		printf("\n%d is the mode of this array\n", mode);
	else
		printf("\nMode does'nt exist\n");
}
