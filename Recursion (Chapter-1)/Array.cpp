#include <iostream>
using namespace std;
int isArraySorted(int A[], int);
int main() {
    int a[] = {1, 2, 5, 4};
    cout << isArraySorted(a, 4);
    return 0;
}
int isArraySorted(int A[], int n) {
    if ( n == 1)
        return 1;
    return (A[n-1] < A[n-2]) ? 0 : isArraySorted(A, n-1);
}