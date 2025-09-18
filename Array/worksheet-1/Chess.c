#include <stdio.h>

int main() {
    // 8x8 chessboard, each string up to 2 characters (e.g., "Rk", "Kn")
    char a[8][8][3] = {
        {"Rk", "Kn", "Bi", "Qu", "K",  "Bi", "Kn", "Rk"},
        {" p",  " p",  " p",  " p",  " p",  " p",  " p",  " p"},
        {"",   "",   "",   "",   "",   "",   "",   ""},
        {"",   "",   "",   "",   "",   "",   "",   ""},
        {"",   "",   "",   "",   "",   "",   "",   ""},
        {"",   "",   "",   "",   "",   "",   "",   ""},
        {" p",  " p",  " p",  " p",  " p",  " p",  " p",  " p"},
        {"Rk", "Kn", "Bi", "K",  "Qu", "Bi", "Kn", "Rk"}
    };

    // Print board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%2s\t", a[i][j][0] ? a[i][j] : "--");  // print "--" for empty squares
        }
        printf("\n");
    }

    return 0;
}
