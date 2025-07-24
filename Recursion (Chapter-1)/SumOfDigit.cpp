#include <iostream>
using namespace std;
int sumOfDigit(int n);

int main() {
    cout << sumOfDigit(1234);
    return 0;
}

int sumOfDigit(int n) {
    if (n == 0)
        return n;
    else
        return n % 10 + sumOfDigit(n / 10);
}