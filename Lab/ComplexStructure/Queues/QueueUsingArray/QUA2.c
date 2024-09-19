#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

// Queue structure using an array
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    if ((q->rear + 1) % MAX == q->front) {
        return 1;
    }
    return 0;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Enqueue an element into the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // Set front to 0 if it's the first element
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("%d enqueued to queue\n", value);
}

// Dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        // Queue has only one element
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return item;
}

// Peek at the front element of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->items[q->front];
}

// Display the queue contents
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->items[q->rear]);
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Front item: %d\n", peek(&q));

    display(&q);

    enqueue(&q, 60); // Try to enqueue when queue is full

    return 0;
}
