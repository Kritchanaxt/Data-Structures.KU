
//* Stack with Circular Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
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

void push(Stack* stack,int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;

    if (isEmpty(stack)) {
        newNode->next = newNode;
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

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to pop.\n");
        return -1;
    } 
    Node* temp = stack->top;
    int item = temp->data;

    if (temp->next == stack->top) {
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
        printf("%d -> ", current->data);
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