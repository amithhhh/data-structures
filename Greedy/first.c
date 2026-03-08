#include <stdio.h>

int main() {
	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
	int size = sizeof(coins) / sizeof(coins[0]);

	int i = size - 1;
	int n = 299;

	while (n > 0) {
		if (coins[i] > n) {
			i--;
		} else {
			printf("%d\n", coins[i]);
			n -= coins[i];
		}
	}
}
