#include <stdio.h>
#include <limits.h>

#define SIZE 4

int size = 0;
int distance[SIZE];

typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

void add_edge(Edge graph[], int src, int dest, int weight) {
    graph[size].src = src;
    graph[size].dest = dest;
    graph[size].weight = weight;
    size++;
}

void init_distance() {
    for (int i = 0; i < SIZE; i++)
        distance[i] = INT_MAX;
    distance[0] = 0;
}

void dynamic_shortest(Edge graph[]) {
    for (int j = 0; j < SIZE - 1; j++) {
        for (int i = 0; i < size; i++) {
            if (distance[graph[i].src] != INT_MAX && distance[graph[i].src] + graph[i].weight < distance[graph[i].dest]) {
                distance[graph[i].dest] = distance[graph[i].src] + graph[i].weight;
            }
        }
    }
    for (int i = 0; i < size; i++) {

        if (distance[graph[i].src] != INT_MAX &&
            distance[graph[i].src] + graph[i].weight < distance[graph[i].dest]) {

            printf("Negative weight cycle detected!\n");
            return;
        }
    }
}

int main() {
    Edge graph[100];
    init_distance();

    add_edge(graph, 0, 1, 11);
    add_edge(graph, 1, 3, 8);
    add_edge(graph, 3, 2, 5);
    add_edge(graph, 2, 0, -2);
    add_edge(graph, 0, 3, -3);
    add_edge(graph, 0, 2, -3);

    dynamic_shortest(graph);

    for (int i = 0; i < SIZE; i++) {
        printf("NODE: %d || DISTANCE: %d\n", i, distance[i]);
    }
    return 0;

}