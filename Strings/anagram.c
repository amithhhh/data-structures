#include <stdio.h>
#include <string.h>

int main() {
	char *str1, *str2;

	printf("Enter the string1: ");
	scanf("%s", str1);
	printf("Enter the string2: ");
	fgets(stdin, str1, 100);
	return 0;
}
