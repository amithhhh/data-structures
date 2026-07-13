#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph {
    int vertices;
    Node **adjLists;
} Graph;

// -------------------- Helper Functions --------------------

Node *createNode(int vertex) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));

    graph->vertices = vertices;
    graph->adjLists = (Node **)malloc(vertices * sizeof(Node *));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(Graph *graph) {
    printf("\nAdjacency List:\n");

    for (int i = 0; i < graph->vertices; i++) {
        printf("%d : ", i);

        Node *temp = graph->adjLists[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }

        printf("\n");
    }
}

// -------------------- Implement These --------------------

int dfs(Graph *graph, int vertex, int visited[], int parent) {
	Node *temp = graph->adjLists[vertex];
	visited[vertex] = 1;
	while (temp != NULL) {
		int neighbour = temp->vertex;
		if (!visited[neighbour]) {
			if (dfs(graph, neighbour, visited, vertex)) {
				return 1;	
			}
		} else if (neighbour != parent) {
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

int hasCycle(Graph *graph, int visited[graph->vertices]) {
    	for (int i = 0; i < graph->vertices; i++) {
		if (!visited[i]) {
			if (dfs(graph, i, visited, -1)) return 1;
		}
	}
	return 0;
}

// -------------------- Driver --------------------

int main() {

    Graph *graph = createGraph(6);
    int visited[100] = {0};
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);
    addEdge(graph, 4, 5);

    printGraph(graph);

    if (hasCycle(graph, visited))
        printf("\nCycle Found\n");
    else
        printf("\nNo Cycle\n");

    return 0;
}
