#include <stdio.h>

int largest(int*, int, int);

int main() {
    int a[] = {7, 2, 9, 4, 1, 1000};
    int num = largest(a, 0, 5);
    printf("%d\n", num);
    return 0;
}

int largest(int *a, int start, int end) {
    if (start == end)
        return a[start];

    int mid = (start + end) / 2;

    int num1 = largest(a, start, mid);
    int num2 = largest(a, mid + 1, end);

    int max = (num1 > num2) ? num1 : num2;

    return max;

}