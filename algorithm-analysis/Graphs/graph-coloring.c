#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,1,1},
    {0,1,1,0,1},
    {0,0,1,1,0}
};

int color[V];

void initialize() {
    for (int i = 0; i < V; i++) {
        color[i] = -1;      // No color assigned
    }
}

void greedyColoring() {

    // Assign first color to first vertex
    color[0] = 0;

    // Color remaining vertices
    for (int u = 1; u < V; u++) {
        int available[V];      

        for (int i = 0; i < V; i++)
            available[i] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] == 1 && color[v] != -1)
                available[v] = 0; 
        }

        int c;
        for (c = 0; c < V; c++) {
            if (available[c]) {
                break;
            }
        }
        color[u] = c;

    }
}

void printColors() {
    printf("\nVertex\tColor\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
}

int main() {

    initialize();

    greedyColoring();

    printColors();

    return 0;
}