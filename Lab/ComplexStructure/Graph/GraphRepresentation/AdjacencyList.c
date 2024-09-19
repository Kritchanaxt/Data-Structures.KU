#include <stdio.h>
#include <stdlib.h>

// Structure to represent an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure to represent a graph
struct Graph {
    int V; // Number of vertices
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* createNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by setting head to NULL
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to insert an edge into an undirected graph
void insertEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to delete an edge from the graph
void deleteEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* temp = graph->array[src].head;
    struct AdjListNode* prev = NULL;

    // Traverse the adjacency list of the source vertex
    while (temp != NULL && temp->dest != dest) {
        prev = temp;
        temp = temp->next;
    }

    // If the destination node is found, remove it from the list
    if (temp != NULL) {
        if (prev != NULL) {
            prev->next = temp->next;
        } else {
            graph->array[src].head = temp->next;
        }
        free(temp);
    }

    // Repeat for undirected edge (dest -> src)
    temp = graph->array[dest].head;
    prev = NULL;
    while (temp != NULL && temp->dest != src) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev != NULL) {
            prev->next = temp->next;
        } else {
            graph->array[dest].head = temp->next;
        }
        free(temp);
    }
}

// Function to print the adjacency list representation of a graph
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

    // Add edges to the graph
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
