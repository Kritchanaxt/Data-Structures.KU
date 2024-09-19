
//? Example Code for Unweighted Graph (Using Adjacency Matrix)

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a graph
struct Graph {
    int V;
    int** adjMatrix;
    int* visited;
    int* recursionStack;
};

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    graph->visited = (int*)malloc(V * sizeof(int));
    graph->recursionStack = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = 0;
        }
        graph->visited[i] = 0;
        graph->recursionStack[i] = 0;
    }
    return graph;
}

// Insert edge in a directed graph
void insertEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
}

// Helper function for cycle detection using DFS in a directed graph
int detectCycleUtil(struct Graph* graph, int v) {
    if (!graph->visited[v]) {
        graph->visited[v] = 1;
        graph->recursionStack[v] = 1;

        for (int u = 0; u < graph->V; u++) {
            if (graph->adjMatrix[v][u]) {
                if (!graph->visited[u] && detectCycleUtil(graph, u)) {
                    return 1;
                } else if (graph->recursionStack[u]) {
                    return 1;
                }
            }
        }
    }
    graph->recursionStack[v] = 0;
    return 0;
}

// Check if the directed graph contains a cycle
int isCyclic(struct Graph* graph) {
    for (int v = 0; v < graph->V; v++) {
        if (detectCycleUtil(graph, v)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int V = 4;
    struct Graph* graph = createGraph(V);

    // Insert edges (acyclic)
    insertEdge(graph, 0, 1);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 3);

    // Check if the graph contains a cycle
    if (isCyclic(graph)) {
        printf("Graph contains a cycle\n");
    } else {
        printf("Graph does not contain a cycle\n");
    }

    return 0;
}
