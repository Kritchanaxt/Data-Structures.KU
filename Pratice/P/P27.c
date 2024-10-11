
#include <stdio.h>
#include <stdlib.h> 

typedef struct {
    int* items;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

void initQueue(Queue* queue)