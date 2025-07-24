#include <iostream>
using namespace std;
void printNum(int);
int main() {
    printNum(1024);
    return 0;
}
void printNum(int n) {
    if ( n == 0 )
        cout << "";
    else {
        printNum(n/10);
        cout << n % 10;
    }
        
}