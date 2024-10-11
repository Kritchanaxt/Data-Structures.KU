
//? Circular Doubly

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* tail = (*head)->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        if (*head == NULL) {
            *head = newNode;
        } else {
            struct Node* tail = (*head)->prev;
            newNode->next = *head;
            newNode->prev = tail;
            (*head)->prev = newNode;
            tail->next = newNode;
            *head = newNode;
        }
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    if (temp->next == *head && position != 1) {
        insertAtEnd(head, data);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 1) {
        if ((*head)->next == *head) {
            free(*head);
            *head = NULL;
            return;
        }
        struct Node* tail = (*head)->prev;
        tail->next = (*head)->next;
        (*head)->next->prev = tail;
        *head = (*head)->next;
        free(temp);
        return;
    }

    for (int i = 1; i < position && temp->next != *head; i++) {
        temp = temp->next;
    }

    if (temp->next == *head && temp == *head) {
        printf("Position out of bounds.\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printf("\nOriginal List: ");
    printList(head);

    insertAtPosition(&head, 5, 1);  
    insertAtPosition(&head, 25, 3); 
    printf("\nAfter List: ");
    printList(head);

    deleteAtPosition(&head, 2);
    deleteAtPosition(&head, 4); 
    printf("\nDelete List: ");
    printList(head);
    printf("\n");

    return 0;
}
