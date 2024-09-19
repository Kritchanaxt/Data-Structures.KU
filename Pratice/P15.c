
//? Circular Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failure\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if (position == 1) {
        if (*head == NULL) {
            *head = newNode;
            newNode->next = *head;
        } else {
            while (temp->next != *head) {
                temp = temp->next;
            }
            newNode->next = *head;
            temp->next = newNode;
            *head = newNode;
        } 
        return;
    }

    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp =  *head;

    if (position == 1) {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        if (temp->next == *head) {
            *head = NULL;
        } else {
            last->next = temp->next;
            *head = temp->next;
            free(temp);
        }
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; i < position && temp->next != *head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head) {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp!= head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printf("\nOriginal Linked List: ");
    printList(head);

    insertAtPosition(&head, 5, 1);
    insertAtPosition(&head, 15, 3);
    insertAtPosition(&head, 35, 6);
    printf("\nAfter Linked List: ");
    printList(head);

    deleteAtPosition(&head, 2);
    deleteAtPosition(&head, 3);
    printf("\nDeleting Linked List: ");
    printList(head);
    printf("\n");

    return 0;
}