
#include <stdio.h>
#include <stdlib.h>

// Structure for an Edge (connection between two vertices)
struct EdgeNode {
    int src;   // Source vertex
    int dest;  // Destination vertex
    struct EdgeNode* srcNext;  // Next edge from the source vertex
    struct EdgeNode* destNext; // Next edge to the destination vertex
};

// Structure for the Graph
struct Graph {
    int V;  // Number of vertices
    struct EdgeNode** adjList; // Array of edge nodes (adjacency multi-list)
};

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct EdgeNode**)malloc(V * sizeof(struct EdgeNode*));

    // Initialize adjacency list for each vertex
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to create a new edge node
struct EdgeNode* createEdgeNode(int src, int dest) {
    struct EdgeNode* newEdge = (struct EdgeNode*)malloc(sizeof(struct EdgeNode));
    if (newEdge == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newEdge->src = src;
    newEdge->dest = dest;
    newEdge->srcNext = NULL;
    newEdge->destNext = NULL;
    return newEdge;
}

// Function to insert an edge into the graph
void insertEdge(struct Graph* graph, int src, int dest) {
    // Create a new edge node
    struct EdgeNode* newEdge = createEdgeNode(src, dest);

    // Insert edge into the source vertex's adjacency list
    newEdge->srcNext = graph->adjList[src];
    graph->adjList[src] = newEdge;

    // Insert edge into the destination vertex's adjacency list (for undirected graph)
    newEdge->destNext = graph->adjList[dest];
    graph->adjList[dest] = newEdge;
}

// Function to print the graph as an adjacency multi-list
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; v++) {
        struct EdgeNode* temp = graph->adjList[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("(%d -> %d) ", temp->src, temp->dest);
            temp = temp->srcNext;
        }
        printf("\n");
    }
}

int main() {
    int V = 4;  // Number of vertices
    struct Graph* graph = createGraph(V);

    // Add edges to the graph
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 3);

    // Print the graph
    printGraph(graph);

    return 0;
}
