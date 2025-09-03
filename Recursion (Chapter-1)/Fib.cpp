#include <iostream>
using namespace std;
int fib(int);
void fibList(int);
int main() {
    cout << fib(3);
    return 0;
}

int fib(int n) {
    if ( (n == 0) || (n ==  1) )
        return n;
    else
        return  fib(n-1) + fib(n-2);
}