#include <stdio.h>
#include <string.h>

void buildLPS(char pattern[], int lps[]) {
    int m = strlen(pattern);
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
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

int KMP(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[m];
    buildLPS(pattern, lps);
    int i = 0, j = 0, count = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } if (j == m) {
            count++;
            j = lps[j - 1];
        } if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    char text[100], pattern[20];
    fgets(text, 100, stdin);
    fgets(pattern, 20, stdin);

    text[strlen(text) - 1] = '\0';
    pattern[strlen(pattern) - 1] = '\0';

    int count = KMP(text, pattern);
    printf("%d\n", count);
    return 0;
}