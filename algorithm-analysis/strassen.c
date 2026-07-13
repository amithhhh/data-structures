#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 128

void add(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void printMatrix(int A[MAX][MAX], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%4d ", A[i][j]);
        printf("\n");
    }
}

void fillRandom(int A[MAX][MAX], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            A[i][j] = rand() % 10;
}

/* STRASSEN */
void strassen(int A[MAX][MAX],
              int B[MAX][MAX],
              int C[MAX][MAX],
              int n)
{
    if(n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    /* IMPORTANT: static avoids stack overflow */
    static int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    static int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];

    static int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX];
    static int M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];

    static int T1[MAX][MAX], T2[MAX][MAX];

    static int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];

    /* Split */
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    /* M1 */
    add(A11, A22, T1, k);
    add(B11, B22, T2, k);
    strassen(T1, T2, M1, k);

    /* M2 */
    add(A21, A22, T1, k);
    strassen(T1, B11, M2, k);

    /* M3 */
    subtract(B12, B22, T1, k);
    strassen(A11, T1, M3, k);

    /* M4 */
    subtract(B21, B11, T1, k);
    strassen(A22, T1, M4, k);

    /* M5 */
    add(A11, A12, T1, k);
    strassen(T1, B22, M5, k);

    /* M6 */
    subtract(A21, A11, T1, k);
    add(B11, B12, T2, k);
    strassen(T1, T2, M6, k);

    /* M7 */
    subtract(A12, A22, T1, k);
    add(B21, B22, T2, k);
    strassen(T1, T2, M7, k);

    /* C11 */
    add(M1, M4, T1, k);
    subtract(T1, M5, T2, k);
    add(T2, M7, C11, k);

    /* C12 */
    add(M3, M5, C12, k);

    /* C21 */
    add(M2, M4, C21, k);

    /* C22 */
    subtract(M1, M2, T1, k);
    add(T1, M3, T2, k);
    add(T2, M6, C22, k);

    /* Combine */
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

int main()
{
    srand(time(NULL));

    int n = 4; // must be power of 2

    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX] = {0};

    fillRandom(A, n);
    fillRandom(B, n);

    printf("Matrix A:\n");
    printMatrix(A, n);

    printf("\nMatrix B:\n");
    printMatrix(B, n);

    strassen(A, B, C, n);

    printf("\nResult Matrix:\n");
    printMatrix(C, n);

    return 0;
}