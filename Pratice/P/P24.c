
//? Stack with Circular Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* top;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;

    if (isEmpty(stack)) {
        newNode->next = newNode;
        newNode->prev = newNode;
        stack->top = newNode;
    } else {
        Node* tail = stack->top->prev;
        newNode->next = stack->top;
        newNode->prev = tail;
        tail->next = newNode;
        stack->top->prev = newNode;
        stack->top = newNode;
    }
    printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to pop.\n");
        return -1;
    }
    Node* temp = stack->top;
    int item = temp->data;

    if (temp->next == temp) {
        stack->top = NULL;
    } else {
        Node* tail = temp->prev;
        stack->top = temp->next;
        tail->next = stack->top;
        stack->top->prev = tail;
    }
    free(temp);
    return item;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    Node* current = stack->top;
    printf("Stack contents: ");
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != stack->top);
    printf("(head)\n");
}

int main() {
    Stack stack;

    printf("\n");
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Popped: %d\n", pop(&stack));
    printf("Top item: %d\n", peek(&stack));

    display(&stack);
    printf("\n");


    return 0;
}