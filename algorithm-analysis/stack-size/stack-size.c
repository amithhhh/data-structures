#include <stdio.h>

void calculate_size(char*);

int main() {
	char start;
	calculate_size(&start);
	return 0;
}

void calculate_size(char *start) {
	char c;
	printf("%ld\n", start - &c);
	calculate_size(start);
}
