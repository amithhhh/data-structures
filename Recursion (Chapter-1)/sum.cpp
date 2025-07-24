#include <iostream>
using namespace std;
int sum(int);
int main() {
    cout << sum(10);
    return 0;
}

int sum(int n) {
    if (n == 1 | n == 0)
        return n;
    else
        return n + sum(n-1);
}