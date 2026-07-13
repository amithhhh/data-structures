#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define VERTICES 4

typedef struct Node {
	int vertex;
	int weight;
	struct Node *next;
} Node;

typedef struct Graph {
	int vertices;
	struct Node **adjLists;
} Graph;

typedef struct Element {
	int vertex;
	int distance;
} Element;

Element Queue[100];
int size = 0;

int visited[VERTICES] = {0};
int distance[VERTICES];


void add_element(int vertex, int distance) {
	Queue[size].vertex = vertex;
	Queue[size].distance = distance;
	int i = size;
	size++;

	while (i > 0) {
		int parent = (i - 1) / 2;

		if (Queue[i].distance < Queue[parent].distance) {
			Element temp;
			temp = Queue[i];
			Queue[i] = Queue[parent];
			Queue[parent] = temp;

			i = parent;
		} else break;
	}
}

Element extract_min() {
	Element e = Queue[0];
	Queue[0] = Queue[size - 1];
	size--;
	int current = 0;
	while (1) {
		int left = 2*current + 1;
		int right = 2*current + 2;

		int smallest = current;

		if (left < size && Queue[left].distance < Queue[smallest].distance) {
			smallest = left;
		}
		if (right < size && Queue[right].distance < Queue[smallest].distance) { 
                        smallest = right;
                }
		if (smallest == current) break;

		Element temp = Queue[smallest];
		Queue[smallest] = Queue[current];
		Queue[current] = temp;

		current = smallest;
	}
	return e;
}

void init_distance() {
	for (int i = 0; i < VERTICES; i++)
		distance[i] = INT_MAX;
	distance[0] = 0;
}

Node *create_node(int v, int w) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->weight = w;
	node->vertex = v;
	node->next = NULL;
	return node;
}

Graph *init_graph(int vertices) {
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->vertices = vertices;
	graph->adjLists = (Node **)malloc(sizeof(Node*) * vertices);

	for (int i = 0; i < vertices; i++) {
		graph->adjLists[i] = NULL;
	}
	return graph;
}

void add_graph(Graph *graph, int src, int dest, int weight) {
	Node *newNode = create_node(dest, weight);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;

	newNode = create_node(src, weight);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;

	
}

void dijikstra(Graph *graph, int v) {
	visited[v] = 1;
	Node *temp = graph->adjLists[v];

	while (temp != NULL) {
		int neighbour = temp->vertex;
		if (!visited[neighbour] && distance[v] + temp->weight < distance[neighbour]) {
			distance[neighbour] = distance[v] + temp->weight;
			add_element(neighbour, distance[neighbour]);
		}
		temp = temp->next;
	}
	Element e;
	do {
		if (size == 0) return;
		e = extract_min();
	} while (visited[e.vertex]);

	if (visited[e.vertex]) {
    		dijikstra(graph, e.vertex);
	}
}

int main() {
	init_distance();
	Graph *graph = init_graph(VERTICES);
	int d = 0;
	add_graph(graph, 0, 1, 10);
	add_graph(graph, 0, 2, 5);
	add_graph(graph, 0, 3, 8);
	add_graph(graph, 1, 2, 12);
	add_graph(graph, 1, 3, 2);
	add_graph(graph, 2, 3, 12);
	
	dijikstra(graph, 0);
	for (int i = 0; i < VERTICES; i++) {
    		printf("Distance from 0 to %d = %d\n", i, distance[i]);
	}
	return 0;
}
