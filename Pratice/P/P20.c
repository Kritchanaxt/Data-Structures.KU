
//? Stack Using Dynamic Array

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* items;
    int top;
    int capacity;
} Stack;

void initStack(Stack* stack, int initialCapacity) {
    stack->capacity = initialCapacity;
    stack->top = -1;
    stack->items = (int*)malloc(stack->capacity * sizeof(int));
}

void resize(Stack* stack, int newCapacity) {
    stack->items = (int*)realloc(stack->items, newCapacity * sizeof(int));
    stack->capacity = newCapacity;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        resize(stack, stack->capacity * 2);
    }
    stack->items[++(stack->top)] = item;
    printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to pop.\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->items[stack->top];
}

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
    printf("\n");

    // Initializes the stack with a capacity of 2.
    initStack(&stack, 2);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Popped: %d\n", pop(&stack));
    printf("Top item: %d\n", peek(&stack));

    display(&stack);

    free(stack.items);
    printf("\n");

    return 0;
}