#include <iostream>
using namespace std;
int countWays(int n);

int main() {
    cout << countWays(5);
    return 0;
}

int countWays(int n) {
    if ( n == 0)
        return 1;
    else if ( n < 0 )
        return 0;
    else
        return countWays(n-1) + countWays(n-2);
}