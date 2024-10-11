
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
        // Initialize all values to 0 (no edges)
        for (int j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Insert an edge into an undirected graph
void insertEdge(struct Graph* graph, int src, int dest) {
    // Set both [src][dest] and [dest][src] to 1
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Delete an edge from an undirected graph
void deleteEdge(struct Graph* graph, int src, int dest) {
    // Set both [src][dest] and [dest][src] to 0
    graph->adjMatrix[src][dest] = 0;
    graph->adjMatrix[dest][src] = 0;
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

// Free memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    int V = 5;  // Number of vertices
    struct Graph* graph = createGraph(V);

    // Insert edges
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 4);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 1, 3);
    insertEdge(graph, 1, 4);
    insertEdge(graph, 2, 3);
    insertEdge(graph, 3, 4);

    // Print the adjacency matrix
    printGraph(graph);

    // Delete an edge and print the matrix again
    deleteEdge(graph, 1, 4);
    printf("\nGraph after deleting edge 1-4:\n");
    printGraph(graph);

    // Free the memory
    freeGraph(graph);

    return 0;
}
