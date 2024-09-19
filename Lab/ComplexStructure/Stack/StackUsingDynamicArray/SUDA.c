#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* items;
    int top;
    int capacity;
} Stack;

// Initialize the stack
void initStack(Stack* stack, int initialCapacity) {
    stack->capacity = initialCapacity;
    stack->top = -1;
    stack->items = (int*)malloc(stack->capacity * sizeof(int));
}

// Resize the stack
void resize(Stack* stack, int newCapacity) {
    stack->items = (int*)realloc(stack->items, newCapacity * sizeof(int));
    stack->capacity = newCapacity;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an item onto the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        resize(stack, stack->capacity * 2); // Double the stack size if full
    }
    stack->items[++(stack->top)] = item;
    printf("%d pushed to stack\n", item);
}

// Pop an item from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to pop.\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}

// Peek at the top item of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->items[stack->top];
}

// Display the stack contents
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack, 2); // Start with an initial capacity of 2

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30); // This will trigger a resize

    display(&stack);

    printf("Popped: %d\n", pop(&stack));
    printf("Top item: %d\n", peek(&stack));

    display(&stack);

    free(stack.items); // Free the allocated memory

    return 0;
}
