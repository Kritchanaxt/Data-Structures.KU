#include <stdio.h>
#include <stdlib.h>

// Queue Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Queue Structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Declaring a Queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue Function
void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue Function
int dequeue(struct Queue* q) {
    if (q->front == NULL)
        return -1;
    
    struct Node* temp = q->front;
    int value = temp->data;
    
    q->front = q->front->next;
    
    if (q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    
    return value;
}

// Display Function
void displayQueue(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main Function to Test the Queue
int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("Queue: ");
    displayQueue(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Queue after dequeue: ");
    displayQueue(q);

    return 0;
}

// Using the Queue
// Enqueue (Add an element): Add a new element to the end of the queue.
// Dequeue (Remove an element): Remove the element from the front of the queue.
// Display: Show all elements in the queue.