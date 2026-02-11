#include <stdio.h>

double mysqrt(double);

int main() {
	int num;
	printf("Enter the number: ");
	scanf("%d", &num);
	
	double sqrt = mysqrt(num);
	printf("The square root of a %d is %f\n", num, sqrt);
	return 0;

}

double mysqrt(double x) {
	double guess = x;
	double eps = 1e-9;

	while ((guess * guess - x) > eps) {
		guess = (guess + x / guess) / 2;
	}
	return guess;
}
