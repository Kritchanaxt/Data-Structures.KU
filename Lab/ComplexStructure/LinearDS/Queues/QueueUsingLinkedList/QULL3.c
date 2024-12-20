
//? Queue Using Circular Linked List

#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
typedef struct Node {
    int data;
    struct Node* next;
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
    newNode->next = queue->front;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
        newNode->next = queue->front;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
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
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
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

// Display the queue contents
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* current = queue->front;
    printf("Queue contents: ");
    do {
        printf("%d", current->data);
        current = current->next;
        if (current != queue->front) {
            printf(" -> ");  // Add arrow to show linkage
        }
    } while (current != queue->front);
    printf(" -> (back to front)\n");  // Indicate circular connection
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

