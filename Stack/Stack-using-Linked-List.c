#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

// Function to peek at the top element of the stack
int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return top->data;
}

// Function to print the stack
void printStack(struct Node* top) {
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack elements: ");
    printStack(stack); // Output: 30 20 10 

    printf("Top element: %d\n", peek(stack)); // Output: 30

    printf("Popped element: %d\n", pop(&stack)); // Output: 30

    printf("Stack elements after pop: ");
    printStack(stack); // Output: 20 10 

    return 0;
}
