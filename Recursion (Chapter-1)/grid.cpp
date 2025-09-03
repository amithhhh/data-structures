#include <iostream>
using namespace std;
int gridPath(int, int);
int main() {
    cout << gridPath(3, 4);
    return 0;
}

int gridPath(int n, int m) {
    if ((n == 1) || (m == 1))
        return 1;
    else
        return gridPath(n-1, m) + gridPath(n, m-1);
}