#include <stdio.h>
#include <string.h>

int longestUniqueSubstring(char*);

int main() {
	char str[] = "abcabcbb";
    	printf("Longest unique substring: %d\n", longestUniqueSubstring(str));
	return 0;
}

int longestUniqueSubstring(char *s) {
	int start = 0, end = 0;
	int freq[256] = {0};
	int maxLen = 0;

	for (end = 0; s[end] != '\0'; end++) {
		freq[s[end]] += 1;

		while (freq[s[end]] > 1) {
			freq[s[start]]--;
			start++;
		}
		int currlen = end - start + 1;

		if (maxLen < currlen)
			maxLen = currlen;
	}
	return maxLen;
}
