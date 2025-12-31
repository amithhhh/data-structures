#include <stdio.h>
#include <string.h>

int mystrlen(char*);
int palindrome(char*);

int main(int argc, char **argv){
	char *s = argv[1];
	if (palindrome(s))
		printf("[+]It is a palindrome.\n");
	else
		printf("[-]It is not a palindrome.\n");
	return 0;
}

int mystrlen(char *s) {
	int len = 0;
	while (*s != '\0') {
		len++;
		s++;
	}
	return len;
}

int palindrome(char *s) {
	int left = 0;
	int right = mystrlen(s) - 1;
	int flag = 1;
	while (left < right) {
		if (s[left] != s[right]){
			flag = 0;
			break;
		}
		left++; right--;
	}
	return flag;
}
