#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
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

// Function to insert a node at the end
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

// Function to insert a node at a specific position
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

// Function to delete a node at a specific position
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

// Function to print the circular doubly linked list
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

    // Insert elements at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printf("Original List: ");
    printList(head);

    // Insert elements at specific positions
    insertAtPosition(&head, 5, 1);  // Insert at position 1
    insertAtPosition(&head, 25, 3); // Insert at position 3
    printf("List after inserting at positions: ");
    printList(head);

    // Delete nodes at specific positions
    deleteAtPosition(&head, 1); // Delete at position 1
    deleteAtPosition(&head, 3); // Delete at position 3
    printf("List after deleting positions: ");
    printList(head);

    return 0;
}
