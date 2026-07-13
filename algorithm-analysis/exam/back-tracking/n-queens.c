#include <stdio.h>

#define N 5

int isSafe(int board[N][N],int row, int col) {
    int flag = 1;
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            flag = 0;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            flag = 0;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            flag = 0;
        }
    }

    return flag;
}

void solveNQueens(int board[N][N], int row) {
    if (row == N) {
        printf("Solution: \n");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d\t", board[i][j]);
            }
            printf("\n");
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            board[row][i] = 1;
            solveNQueens(board, row + 1);
            board[row][i] = 0;
        }

    }
}

int main()
{
    int board[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    solveNQueens(board, 0);

    return 0;
}