
//* Stack with Circular Linked List

#include <stdio.h>
#include <stdlib.h>

// Node structure for Circular Linked List
typedef struct Node {
    int data;
    struct Node* next;
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

// Push an item onto the stack (with circular linked list)
void push(Stack* stack, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;

    if (isEmpty(stack)) {
        newNode->next = newNode; // Point to itself
    } else {
        Node* temp = stack->top;
        while (temp->next != stack->top) {
            temp = temp->next;
        }
        newNode->next = stack->top;
        temp->next = newNode;
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

    if (temp->next == stack->top) {
        // Only one node in the circular list
        stack->top = NULL;
    } else {
        Node* last = stack->top;
        while (last->next != stack->top) {
            last = last->next;
        }
        stack->top = stack->top->next;
        last->next = stack->top;
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
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != stack->top);
    printf("(back to top)\n");

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
