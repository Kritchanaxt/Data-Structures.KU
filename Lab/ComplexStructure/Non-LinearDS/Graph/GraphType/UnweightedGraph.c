
//? Example Code for Unweighted Graph (Using Adjacency Matrix)

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a graph
struct Graph {
    int V;  // Number of vertices
    int** adjMatrix;  // Adjacency matrix
};

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = 0;  // Initialize all edges to 0
        }
    }
    return graph;
}

// Insert an edge into an unweighted graph (no weights, simply connection)
void insertEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;  // Undirected graph
}

// Print the adjacency matrix
void printGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V = 4;  // Number of vertices
    struct Graph* graph = createGraph(V);

    // Insert edges
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 3);

    // Print the adjacency matrix
    printGraph(graph);

    return 0;
}
