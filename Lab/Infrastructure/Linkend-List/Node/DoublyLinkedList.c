#include <stdio.h>
#include <stdlib.h>

// Structure of a node in a doubly linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next; // Pointer to the next node
    struct Node* prev; // Pointer to the previous node
};

