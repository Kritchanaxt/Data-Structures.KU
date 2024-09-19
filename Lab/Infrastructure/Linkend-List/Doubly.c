#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    // Initialize the new node's data and pointers
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // Link the new node with the current head
    newNode->next = *head;
    
    // If the list is not empty, set the previous pointer of the old head
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
    // Update the head to the new node
    *head = newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    int i;
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    // If inserting at the first position, call the insertAtBeginning function
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    // Traverse the list to find the node just before the insertion point
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If the position is beyond the end of the list, exit the function
    if (temp == NULL || temp->next == NULL) {
        return;
    }

    // Insert the new node at the desired position
    newNode->next = temp->next;
    newNode->prev = temp;

    // Update the next node's previous pointer, if it exists
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    // Link the new node to the list
    temp->next = newNode;
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node** head, int position) {
    int i;

    // If the list is empty, exit the function
    if (*head == NULL) {
        return;
    }

    struct Node* temp = *head;

    // If deleting the first node, update the head
    if (position == 1) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;  // Set the new head's previous pointer to NULL
        }
        free(temp);  // Free the memory of the deleted node
        return;
    }

    // Traverse the list to find the node to delete
    for (i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    // If the position is beyond the end of the list, exit the function
    if (temp == NULL) {
        return;
    }

    // Update the next node's previous pointer, if it exists
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Update the previous node's next pointer
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Free the memory of the deleted node
    free(temp);
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;

    // Traverse and print the list from head to end
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");  // Indicate the end of the list
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning of the list
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    printf("\nOriginal Linked List: ");
    printList(head);

    // Insert nodes at specific positions
    insertAtPosition(&head, 40, 1);  // Insert 40 at position 1
    insertAtPosition(&head, 50, 4);  // Insert 50 at position 4

    printf("\nAfter Linked List: ");
    printList(head);

    // Delete nodes at specific positions
    deleteAtPosition(&head, 2);  // Delete node at position 2
    deleteAtPosition(&head, 1);  // Delete node at position 1

    printf("\nDeleting Linked List: ");
    printList(head);

    return 0;
}
