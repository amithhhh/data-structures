#include <stdio.h>
#include <limits.h>

#define VERTICES 6

int distance[VERTICES];
int visited[VERTICES] = {0};

void initialize() {
    for (int i = 0; i < VERTICES; i++) {
        distance[i] = INT_MAX;
    } 
    distance[0] = 0;
}


void dijikstra(int adj[VERTICES][VERTICES], int v) {
    visited[v] = 1;
    for (int i = 0; i < VERTICES; i++) {
        if (distance[v] != INT_MAX &&
    adj[v][i] != 0 && distance[v] + adj[v][i] < distance[i]) {
            distance[i] = distance[v] + adj[v][i];
        }
    }
    int min = INT_MAX, pos = -1;
    for (int i = 0; i < VERTICES; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            pos = i;
        }
    }
    if (min == INT_MAX || pos == -1)
        return;
    dijikstra(adj, pos);
    
}

int main() {
	//int adj[4][4] = {{0, 10, 11, 15}, {10, 0, 2, 2}, {15, 2, 0, 5}, {15, 2, 5, 0}};
    
    int adj[6][6] = {
    { 0, 4, 0, 0,10, 0}, 
    { 4, 0, 7, 2, 5, 0}, 
    { 0, 7, 0, 1, 0, 3}, 
    { 0, 2, 1, 0, 0, 6}, 
    {10, 5, 0, 0, 0, 2}, 
    { 0, 0, 3, 6, 2, 0}  
};
    
    initialize();
    dijikstra(adj, 0);

    printf("distance: %d\n", distance[VERTICES - 1]);
	return 0;
}