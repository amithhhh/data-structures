#include <stdio.h>

int main() {
    int start[] = {1, 2, 7, 10};
    int end[] = {6, 8, 12, 16};

    int count = 1, last = end[0];
    for (int i = 1; i < 4; i++) {
        if (start[i] >= last) {
            count++;
            last = end[i];
        }
    }
    printf("%d\n", count);
    return 0;
}