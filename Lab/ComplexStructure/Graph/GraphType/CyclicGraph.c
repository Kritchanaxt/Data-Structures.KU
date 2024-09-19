
//? Example Code for Unweighted Graph (Using Adjacency Matrix)

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a graph
struct Graph {
    int V;  // Number of vertices
    int** adjMatrix;
    int* visited;  // Array to track visited vertices
};

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    graph->visited = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = 0;
        }
        graph->visited[i] = 0;
    }
    return graph;
}

// Insert edge in an undirected graph
void insertEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Detect cycle in an undirected graph using DFS
int detectCycle(struct Graph* graph, int v, int parent) {
    graph->visited[v] = 1;
    for (int u = 0; u < graph->V; u++) {
        if (graph->adjMatrix[v][u]) {
            if (!graph->visited[u]) {
                if (detectCycle(graph, u, v)) {
                    return 1;
                }
            } else if (u != parent) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if the graph contains a cycle
int isCyclic(struct Graph* graph) {
    for (int v = 0; v < graph->V; v++) {
        if (!graph->visited[v]) {
            if (detectCycle(graph, v, -1)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int V = 4;
    struct Graph* graph = createGraph(V);

    // Insert edges
    insertEdge(graph, 0, 1);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 0);
    insertEdge(graph, 2, 3);

    // Detect cycle
    if (isCyclic(graph)) {
        printf("Graph contains a cycle\n");
    } else {
        printf("Graph does not contain a cycle\n");
    }

    return 0;
}
