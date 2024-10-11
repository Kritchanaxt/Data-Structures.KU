
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in adjacency list
struct AdjListNode {
    int dest;
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
struct AdjListNode* createNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
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

// Insert an edge into a directed graph
void insertEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Delete an edge from a directed graph
void deleteEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* temp = graph->array[src].head;
    struct AdjListNode* prev = NULL;

    // Find and remove the destination from src adjacency list
    while (temp != NULL && temp->dest != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev != NULL) {
            prev->next = temp->next;
        } else {
            graph->array[src].head = temp->next;
        }
        free(temp);
    }
}

// Print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* temp = graph->array[v].head;
        printf("\nAdjacency list of vertex %d\n head", v);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // Create a graph with 5 vertices
    int V = 5;
    struct Graph* graph = createGraph(V);

    // Insert edges into the directed graph
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 4);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 1, 3);
    insertEdge(graph, 1, 4);
    insertEdge(graph, 2, 3);
    insertEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Delete an edge and print the graph again
    deleteEdge(graph, 1, 4);
    printf("\nGraph after deleting edge 1-4:\n");
    printGraph(graph);

    return 0;
}
