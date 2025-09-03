#include <iostream>
using namespace std;
int countZeros(int);
int main() {
    cout << countZeros(1000000111);
    return 0;
}
int countZeros(int n) {
    if ( n == 0 )
        return 0;
    int lastDigit = n % 10;
    if (lastDigit == 0) {
        return 1 + countZeros(n/10);
    } else {
        return countZeros(n/10);
    }

}