#include <stdio.h>
#include <math.h>

#define MAX 3

void matrix(int [3][3]);
void create(int [3][3]);
void display(int [3][3]);
void matadd(int [3][3], int [3][3], int [3][3]);
void matmul(int [3][3], int [3][3], int [3][3]);
void transpose(int [3][3], int [3][3]);
int determinant(int [3][3]);
int isortho(int [3][3]);

int main() {
	int mat1[3][3], mat2[3][3], mat3[3][3], mat4[3][3], mat5[3][3], det;
	printf("\033[H\033[J");

	printf("\nEnter elements for first array: \n\n");
	create(mat1);

	printf("\nEnter elements for second array: \n\n");
	create(mat2);

	printf("\n First Array: \n");
	display(mat1);

	printf("\n second Array: \n");
	display(mat2);

	matadd(mat1, mat2, mat3);
	printf("\n After Addition: \n");
	display(mat3);

	matmul(mat1, mat2, mat4);
	printf("\n After Multiplication: \n");
	display(mat4);

	transpose(mat1, mat5);
	printf("\n After Transposing: \n");
	display(mat5);

	det = determinant(mat4);
	printf("\n Determinant of Matrix 4 is: %d \n", det);

	if (det == 0)
		printf("\n Matrix is singular.\n");
	else
		printf("\n Matrix is not singular. \n");

	if (isortho(mat1))
		printf("\n Matrix is orthogonal. \n");
	else
		printf("\n Matrix is not orthogonal. \n");

	return 0;
}

void create(int mat[3][3]) {
	int i, j;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			printf("Enter the element\n: ");
			scanf("%d", &mat[i][j]);
		}
	}
}

void display(int mat[3][3]) {
	int i, j;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}

void matadd(int mat1[3][3], int mat2[3][3], int mat3[3][3]) {
	int i, j;

	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
			mat3[i][j] = mat1[i][j] + mat2[i][j];
}

void matmul(int mat1[3][3], int mat2[3][3], int mat3[3][3]) {
	int i, j, k;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			mat3[i][j] = 0;
			for (k = 0; k < MAX; k++) {
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}

void transpose(int mat1[3][3], int mat5[3][3]) {
	int i, j;
	
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			mat5[i][j] = mat1[j][i];
		}
	}
}



int determinant(int mat[3][3]) {
	int sum, i, j , k, p;
	sum = 0; j = 1; k = MAX - 1;

	for (i = 0; i < MAX; i++) {
		p = pow(-1, i);
		
		if (i == MAX - 1)
			k = 1;

		sum = sum + (mat[0][i] * (mat[1][j] * mat[2][k] - mat[2][j] * mat[1][k])) * p;
		j = 0;

	}
	return sum;
}

int isortho(int mat[3][3]) {
	int m1[3][3], m2[3][3], i;

	transpose(mat, m1);

	matmul(mat, m1, m2);

	for (i = 0; i < MAX; i++) {
		if (m2[i][i] == 1)
			continue;
		else
			break;
	}
	if (i == MAX)
		return 1;
	else
		return 0;
}
