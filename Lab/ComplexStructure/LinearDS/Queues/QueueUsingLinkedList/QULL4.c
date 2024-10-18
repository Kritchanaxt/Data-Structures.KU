
//? Queue Using Circular Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

// Node structure for circular doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Initialize the queue
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Enqueue an item into the queue
void enqueue(Queue* queue, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
        newNode->next = newNode; // Pointing to itself
        newNode->prev = newNode; // Pointing to itself
    } else {
        newNode->next = queue->front; // New node points to front
        newNode->prev = queue->rear;  // New node points to rear
        queue->rear->next = newNode;   // Current rear points to new node
        queue->front->prev = newNode;  // Front points back to new node
        queue->rear = newNode;          // Update rear to new node
    }
    printf("%d enqueued to queue\n", item);
}

// Dequeue an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return -1;
    }
    Node* temp = queue->front;
    int item = temp->data;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next; // Move front to next node
        queue->rear->next = queue->front;   // Update rear's next to new front
        queue->front->prev = queue->rear;   // New front's prev points to rear
    }
    free(temp);
    return item;
}

// Peek at the front item of the queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* current = queue->front;
    printf("Queue contents: ");
    do {
        printf("%d", current->data);
        if (current->next != queue->front) {
            printf(" <-> "); // Show arrows to indicate both directions
        }
        current = current->next;
    } while (current != queue->front);
    printf(" <-> (back to front)\n");
}


int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Front item: %d\n", peek(&queue));

    display(&queue);

    return 0;
}
