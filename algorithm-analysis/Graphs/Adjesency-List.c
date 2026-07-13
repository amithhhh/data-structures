#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int Queue[SIZE];

int front = -1, rear = -1;

void enqueue(int v) {
	if (front == -1 || rear == -1) {
		front = rear = 0;
		Queue[rear] = v;
	} else {
		rear = rear + 1;
		Queue[rear] = v;
	}
}

int dequeue() {
	int v;
	if (front == rear) {
		v = Queue[front];
		front = rear = -1;
		return v;
	} else if (front == -1) {
		return -1;
	} else {
		v = Queue[front];
		front--;
		return v;
	}
}

typedef struct Node {
	int vertex;
	struct Node *next;
} Node;

typedef struct Graph {
	int vertices;
	Node **adjlists;
} Graph;

int visited[4] = {0};

Node *create_node(int vertex) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->vertex = vertex;
	node->next = NULL;
	return node;
}

Graph *create_graph(int vertices) {
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->vertices = vertices;
	graph->adjlists = (Node **)malloc(sizeof(Node*) * vertices);

	for (int i = 0; i < vertices; i++) {
		graph->adjlists[i] = NULL;
	}
	return graph;
}

void addEdge(Graph *graph, int src, int dest) {
	Node *newNode = create_node(dest);
	newNode->next = graph->adjlists[src];
	graph->adjlists[src] = newNode;

	newNode = create_node(src);
	newNode->next = graph->adjlists[dest];
        graph->adjlists[dest] = newNode;

}

void printGraphs(Graph *graph) {
	for (int i = 0; i < graph->vertices; i++) {
		char c = 'A' + i;
		printf("%c: ", c);

		Node *temp = graph->adjlists[i];
		while (temp != NULL) {
			c = 'A' + temp->vertex;
			printf("%c->", c);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

void freeGraph(Graph *graph) {

    for (int i = 0; i < graph->vertices; i++) {

        Node *temp = graph->adjlists[i];

        while (temp != NULL) {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(graph->adjlists);
    free(graph);
}

void dfs(int adj[4][4], int v) {
	visited[v] = 1;

	printf("%d", v);

	for (int i = 0; i < 4; i++) {
		if (!visited[i] && adj[v][i] == 1) {
			dfs(adj, i);
		}
	}
}
int graph_visit[4] = {0};
void dfs_graph(Graph *graph, int v) {
	graph_visit[v] = 1;
	printf("%d", v);
	Node *adjlist = graph->adjlists[v];

	while (adjlist != NULL) {
		int neighbour = adjlist->vertex;
		if (!graph_visit[neighbour])
			dfs_graph(graph, neighbour);
		adjlist = adjlist->next;
	}
}

int isEmpty() {
    return front > rear;
}

int bfs_visited[4] = {0};
void bfs(int adj[4][4], int v) {
	bfs_visited[v] = 1;

	enqueue(v);

	while (!isEmpty()) {
		int curr = dequeue();
		for (int i = 0; i < 4; i++) {
			if (!bfs_visited[i] && adj[curr][i] == 1) {
				bfs_visited[i] = 1;
				enqueue(i);
			}
		}
	}
}

int main() {
	Graph *graph = create_graph(4);
	int adj[4][4] = {0};
	addEdge(graph, 0, 1);
    	addEdge(graph, 0, 2);
    	addEdge(graph, 1, 3);
    	addEdge(graph, 2, 3);
	printGraphs(graph);

	for (int i = 0; i < 4; i++) {
		Node *temp = graph->adjlists[i];
		while (temp != NULL) {
			adj[i][temp->vertex] = 1;
			temp = temp->next;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d\t", adj[i][j]);
		}
		printf("\n");
	}
	dfs(adj, 0);
	dfs_graph(graph, 0);
	bfs(adj, 0);
	free(graph);
	return 0;
}

