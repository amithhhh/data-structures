#include <stdio.h>

int main() {
	char processes[] = {'a', 'b', 'c'};
	for (int i = 0; i < 3; i++) {
		printf("Processed %c in the position %d\n", processes[i], i);
	}
	return 0;
}
