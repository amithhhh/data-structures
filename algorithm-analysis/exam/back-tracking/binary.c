#include <stdio.h>

void generate(char *arr, int n, int pos) {
    if (pos == n) {
        arr[pos] = '\0';
        printf("%s\n", arr);
        return;
    }
    arr[pos] = '0';
    generate(arr, n, pos + 1);

    arr[pos] = '1';
    generate(arr, n, pos + 1);
}

int main() {
    int n = 3;
    char arr[4];

    generate(arr, n, 0);

    return 0;
}