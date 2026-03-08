#include <stdio.h>
#include <stdlib.h>

int *generateRatio(int*, int*, int);

int main() {
	int weight[] = {10, 20, 30};
	int value[] = {60, 100, 120};
	int target = 50;
	int size = sizeof(value) / sizeof(value[0]);

	int *ratio = generateRatio(weight, value, size);

	for (int i = 0; i < size; i++) {
		int item_to_be_added = ratio[i];
		
		if (weight[i] < target) {
			target -= weight[i];
			printf("Adding %d of items from %c\n", weight[i], 'A' + i);
		} else {
			float partial = (float) target / weight[i];
			target -= partial;
			printf("Adding %f of items from %c\n", partial, 'A' + i);
		}
			
	}
}

int *generateRatio(int *weight, int *value, int size) {
	int *ratio = (int *) malloc(sizeof(int) * size);
	int i = 0;

	while (i < size) {
		ratio[i] = value[i] / weight[i];
		i++;
	}
	return ratio;
}
