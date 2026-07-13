#include <stdio.h>
#include <limits.h>

void dijikstra(int adj[4][4], int *distance, int v, int target) {
	int min = INT_MAX, pos = -1;
	for (int i = 0; i < 4; i++) {
		if (i == v || adj[v][i] == 0) continue;
		if (adj[v][i] < min) {
			min = adj[v][i];
			pos = i;
		}
	}
	*distance += min;
	if (pos != target) {
		dijikstra(adj, distance, pos, target);
	}
}

int main() {
	int adj[4][4] = {{0, 10, 11, 15}, {10, 0, 2, 2}, {15, 2, 0, 5}, {15, 2, 5, 0}};
	int distance = 0;

	dijikstra(adj, &distance, 0, 2);

	printf("distance: %d\n", distance);
	return 0;
}
