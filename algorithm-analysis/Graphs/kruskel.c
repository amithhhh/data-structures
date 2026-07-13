#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

Edge edges[MAX_EDGES];

int parent[MAX_VERTICES];
int rank[MAX_VERTICES];   // Optional if you use union by rank

int V, E;

// You implement these
int find(int vertex) {
    while (vertex != parent[vertex])
        vertex = parent[vertex];
    return vertex;
}
void unionSets(int u, int v) {
    int rootA = find(u);
    int rootB = find(v);

    parent[rootA] = rootB;
}

// Comparator for qsort
int compare(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;

    return e1->weight - e2->weight;
}

void kruskal() {

    // Step 1: Initialize parent[] and rank[]

    // Step 2: Sort all edges by weight
    qsort(edges, E, sizeof(Edge), compare);

    int edgeCount = 0;
    int totalWeight = 0;

    for (int i = 0; i < E; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int w = edges[i].weight;

        if (find(src) != find(dest)) {
            printf("%d->%d->%d\n", src, dest, w);
            unionSets(src, dest);
            edgeCount++;
            totalWeight += w;
        }
        if (edgeCount == V - 1) break;
    }

    printf("Total Weight = %d\n", totalWeight);
}

int main() {

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter source destination weight:\n");

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    kruskal();

    return 0;
}