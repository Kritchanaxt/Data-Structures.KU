
//* Queue use array 1

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum size of the queue

// Structure to represent a queue
typedef struct {
    int items[MAX];
    int front;
    int rear;
    int size;
} Queue;

// Initialize the queue
void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return queue->size == MAX;
}

// Enqueue an item into the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->items[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue\n", item);
}

// Dequeue an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->size--;
    return item;
}

// Peek at the front item of the queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->items[queue->front];
}

// Display the queue contents
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->items[(queue->front + i) % MAX]);
    }
    printf("\n");
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
