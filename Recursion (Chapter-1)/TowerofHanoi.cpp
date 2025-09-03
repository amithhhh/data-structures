#include <iostream>
using namespace std;
void towerOfHanoi(int, char, char, char);

int main() {
    towerOfHanoi(3, 'S', 'E', 'A');
    return 0;
}

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n > 0) {
        towerOfHanoi(n-1, from, aux, to);
        cout << "Move a Disc from " << from << " to " << to << "\n";
        towerOfHanoi(n-1, aux, to, from);
    }
}