#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
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

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Pointing to itself to make it circular
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head; // Make the new node point to head
}

// Function to insert a node at a specific position in the circular linked list
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    
    // If inserting at the beginning
    if (position == 1) {
        if (*head == NULL) { // Empty list, so set newNode as head
            *head = newNode;
            newNode->next = *head; // Circular link
        } else { 
            // Find the last node to update its next to point to new head
            while (temp->next != *head) {
                temp = temp->next;
            }
            newNode->next = *head;
            temp->next = newNode;
            *head = newNode;
        }
        return;
    }
    
    // For other positions, traverse to the correct position
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    // Insert the node in the specified position
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node at a specific position in the circular linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;

    // If deleting the first node
    if (position == 1) {
        // Find the last node
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        // If there's only one node in the list
        if (temp->next == *head) {
            *head = NULL;
            free(temp);
        } else {
            last->next = temp->next;
            *head = temp->next;
            free(temp);
        }
        return;
    }

    // For other positions, traverse to the correct node
    struct Node* prev = NULL;
    for (int i = 1; i < position && temp->next != *head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
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
    insertAtPosition(&head, 15, 3); // Insert at position 3
    insertAtPosition(&head, 35, 6); // Insert at position 6 (end)

    printf("\nAfter List: ");
    printList(head);

    // Delete nodes at specific positions
    deleteAtPosition(&head, 1); // Delete at position 1
    deleteAtPosition(&head, 3); // Delete at position 3
    printf("\nDelete List: ");
    printList(head);

    return 0;
}
