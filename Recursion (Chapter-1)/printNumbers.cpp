#include <iostream>
using namespace std;
void printNum(int);
int main() {
    printNum(10);
    return 0;
}

void printNum(int n) {
    if (n == 1) {
        cout << n << endl;
    } else {
        cout << n << endl;
        printNum(n - 1);
    }
       
}