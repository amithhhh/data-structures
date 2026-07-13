#include <stdio.h>
#include <limits.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}

int max_crossing_sum(int* a, int start, int end, int mid) {
    int sum = 0;
    int left_sum = INT_MIN;

    for (int i = mid; i >= start; i--) {
        sum += a[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;

    for (int i = mid + 1; i <= end; i++) {
        sum += a[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return left_sum + right_sum;
}

int merge(int *a, int start, int end) {
    if (start == end)
        return a[start];

    int mid = (start + end) / 2;
    int left = merge(a, start, mid);
    int right = merge(a, mid + 1, end);
    int cross = max_crossing_sum(a, start, end, mid);

    return max(max(left, right), cross);
}

int main() {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d\n", merge(a, 0, 8));
    return 0;
}
