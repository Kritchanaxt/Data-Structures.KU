
//? Stack with Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev; // Add previous pointer
} Node;

// Stack structure
typedef struct {
    Node* top;
} Stack;

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Push an item onto the stack (with doubly linked list)
void push(Stack* stack, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = stack->top;
    newNode->prev = NULL; // No previous node initially
    
    if (stack->top != NULL) {
        stack->top->prev = newNode; // Update previous of the current top
    }
    
    stack->top = newNode;
    printf("%d pushed to stack\n", item);
}

// Pop an item from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to pop.\n");
        return -1;
    }
    Node* temp = stack->top;
    int item = temp->data;
    stack->top = stack->top->next;
    
    if (stack->top != NULL) {
        stack->top->prev = NULL; // Remove previous reference
    }
    
    free(temp);
    return item;
}

// Peek at the top item of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

// Display the stack contents
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    Node* current = stack->top;
    printf("Stack contents: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Popped: %d\n", pop(&stack));
    printf("Top item: %d\n", peek(&stack));

    display(&stack);

    return 0;
}
