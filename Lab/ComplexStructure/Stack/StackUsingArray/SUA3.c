#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum size of the stack

// Structure to represent a stack
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an item onto the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d\n", item);
        return;
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
    initStack(&stack);

    printf("\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("\n");
    display(&stack);

    printf("\nPopped: %d\n", pop(&stack));
    printf("\nTop item: %d\n", peek(&stack));

    printf("\n");
    display(&stack);
    printf("\n");

    return 0;
}
