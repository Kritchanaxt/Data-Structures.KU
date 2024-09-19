
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the graph
struct Graph {
    int V;          // Number of vertices
    struct Node** adjList; // Array of adjacency lists
};

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    // Initialize each adjacency list to NULL
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to create a new adjacency list node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // For undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function for BFS traversal
void BFS(struct Graph* graph, int start) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    // Create a queue for BFS
    int* queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

    // Mark the starting node as visited and enqueue it
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        // Traverse the adjacency list of the current node
        struct Node* temp = graph->adjList[currentNode];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(queue);
}

// Function for DFS traversal
void DFSUtil(struct Graph* graph, int node, int* visited) {
    visited[node] = 1; // Mark the node as visited
    printf("%d ", node);

    // Recur for all the vertices adjacent to this vertex
    struct Node* temp = graph->adjList[node];
    while (temp) {
        if (!visited[temp->data]) {
            DFSUtil(graph, temp->data, visited);
        }
        temp = temp->next;
    }
}

// Function to initiate DFS traversal
void DFS(struct Graph* graph, int start) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }
    DFSUtil(graph, start, visited);
    free(visited);
}

int main() {
    struct Graph* graph = createGraph(5);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("BFS starting from vertex 0: ");
    BFS(graph, 0);
    printf("\n");

    printf("DFS starting from vertex 0: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}
