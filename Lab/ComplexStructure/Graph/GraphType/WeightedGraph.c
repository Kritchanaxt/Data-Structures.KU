
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in adjacency list
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

// Define the structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Define the structure for a graph
struct Graph {
    int V;
    struct AdjList* array;
};

// Create a new adjacency list node
struct AdjListNode* createNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    
    // Initialize each adjacency list as empty
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Insert an edge into a weighted graph
void insertEdge(struct Graph* graph, int src, int dest, int weight) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = createNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src
    newNode = createNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* temp = graph->array[v].head;
        printf("\nAdjacency list of vertex %d\n head", v);
        while (temp) {
            printf(" -> %d(weight=%d)", temp->dest, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // Create a weighted graph with 5 vertices
    int V = 5;
    struct Graph* graph = createGraph(V);

    // Insert edges into the graph
    insertEdge(graph, 0, 1, 10);
    insertEdge(graph, 0, 4, 20);
    insertEdge(graph, 1, 2, 30);
    insertEdge(graph, 1, 3, 40);
    insertEdge(graph, 1, 4, 50);
    insertEdge(graph, 2, 3, 60);
    insertEdge(graph, 3, 4, 70);

    // Print the graph
    printGraph(graph);

    return 0;
}
