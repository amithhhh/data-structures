#include <stdio.h>
#include <stdbool.h>
#define MAX 5

void createArray(int a[MAX][MAX]);
void display(int a[MAX][MAX]);
bool isSingular(int a[MAX][MAX]);

int main() {
	int a[MAX][MAX];
	createArray(a);
	display(a);
	if (isSingular(a))
		printf("\nMatrix is singular\n");
	else
		printf("\nMatrix is not singular");
}

void createArray(int a[MAX][MAX]) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			printf("\nEnter the number: \n");
			scanf("%d", &a[i][j]);
		}
	}
}

void display(int a[MAX][MAX]) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

bool isSingular(int a[MAX][MAX]) {
	bool flag = true;

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (a[i][j] != a[j][i]) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}
