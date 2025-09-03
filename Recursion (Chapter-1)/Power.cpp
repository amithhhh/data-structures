#include <iostream>
using namespace std;
int power(int, int);
int main() {
    cout << power(2, 5);
    return 0;
}

int power(int n, int m) {
    if (n == 0)
        return 0;
    else if (m == 0)
        return 1;
    else
        return n * power(n, m-1);
}