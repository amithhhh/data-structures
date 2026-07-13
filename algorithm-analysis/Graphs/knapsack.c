#include <stdio.h>

int main() {
    int coins[] = {4, 3, 1};
    int price = 6;
    int count = 0, i = 0;
    int dp[price + 1];
    dp[0] = 0;
    while (price > 0) {
        if (price - coins[i] >= 0) {
            price -= coins[i];
            count++;
        } else {
            i++;
        }
    }
    printf("%d\n", count);

    for (int i = 1; i <= price; i++) {
        dp[i] = 1e9;
        for (int j = 0; j < 3; j++) {
            if (coins[j] <= i) {
                int sub = dp[i - coins[j]];
                if (sub != 1e9 && sub + 1 < dp[i]) {
                    dp[i] = sub + 1;
                }
            }
        }
    }
    return 0;
}