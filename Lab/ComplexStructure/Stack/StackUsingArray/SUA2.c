
//* Stack using Array 2

#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the stack

// Structure representing a stack
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1; // Stack is empty initially
}

// Check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full! Cannot push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot pop\n");
        return -1;
    } else {
        int value = stack->arr[stack->top--];
        printf("Popped %d from the stack\n", value);
        return value;
    }
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

// Main function
int main() {
    struct Stack stack;
    
    printf("\n");
    initialize(&stack);

    // Perform operations
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printf("\nTop element is %d\n", peek(&stack));
    printf("\n");
    pop(&stack);
    pop(&stack);
    
    printf("\nTop element is %d\n", peek(&stack));
    printf("\n");
    
    return 0;
}
