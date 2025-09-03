#include <iostream>
using namespace std;
int Fact(int);
int main() {
    cout << Fact(4);
    return 0;
}
int Fact(int n) {
    if (n == 1)
        return 1;
    else if(n == 0)
        return 1;
    else
        return n * Fact(n - 1);
}