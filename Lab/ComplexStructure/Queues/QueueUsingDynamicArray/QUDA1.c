#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* items;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// Initialize the queue
void initQueue(Queue* queue, int initialCapacity) {
    queue->capacity = initialCapacity;
    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;
    queue->items = (int*)malloc(queue->capacity * sizeof(int));
}

// Resize the queue
void resize(Queue* queue, int newCapacity) {
    queue->items = (int*)realloc(queue->items, newCapacity * sizeof(int));
    queue->capacity = newCapacity;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return queue->size == queue->capacity;
}

// Enqueue an item into the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        resize(queue, queue->capacity * 2); // Double the size if full
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
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
    queue->front = (queue->front + 1) % queue->capacity;
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
        printf("%d ", queue->items[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initQueue(&queue, 2); // Start with an initial capacity of 2

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30); // This will trigger a resize

    display(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Front item: %d\n", peek(&queue));

    display(&queue);

    free(queue.items); // Free the allocated memory

    return 0;
}
