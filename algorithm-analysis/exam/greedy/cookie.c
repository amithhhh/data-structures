#include <stdio.h>

int main() {
    int children[] = {1, 2, 3};
    int cookies[] = {1, 1, 3};
    int i = 0, j = 0, count = 0;

    while (i < 3 || j < 3) {
        if (cookies[j] >= children[i]) {
            count++;
        } else {
            j++;
        }
        i++; j++;
    }
    printf("%d\n", count);
}