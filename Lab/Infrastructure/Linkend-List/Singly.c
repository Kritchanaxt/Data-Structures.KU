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

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;

    // If the node to be deleted is the head node
    if (position == 1) {
        *head = temp->next;  // Move the head to the next node
        free(temp);          // Free the memory of the old head
        return;
    }

    // Traverse to the node before the one to be deleted
    struct Node* prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);  // Free the memory of the node to be deleted
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Create a list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("\nOriginal Linked List: ");
    printList(head);

    // Insert data at positions 2 and 3
    insertAtPosition(&head, 9, 2);  // Insert 9 at position 2
    insertAtPosition(&head, 8, 3);  // Insert 8 at position 3

    printf("\nAfter Linked List: ");
    printList(head);

    // Delete nodes at positions 2 and 3
    deleteAtPosition(&head, 2);  // Delete node at position 2
    deleteAtPosition(&head, 3);  // Delete node at position 3

    printf("\nDeleting Linked List: ");
    printList(head);

    return 0;
}
