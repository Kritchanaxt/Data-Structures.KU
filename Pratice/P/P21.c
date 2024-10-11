
//? Stack with Single Linked Link

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    } 
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

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

int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return top->data;
}

void printStack(struct Node* top) {
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> "); 
        }
        temp = temp->next;
    }
    printf(" -> NULL\n"); 
}


int main() {
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("\nStack element: ");
    printStack(stack);

    printf("\nTop element: %d\n", peek(stack));
    printf("\nPopped element: %d\n", pop(&stack));
    printf("\nStack elements after pop: ");
    printStack(stack);

    printf("\n");

    return 0;
}