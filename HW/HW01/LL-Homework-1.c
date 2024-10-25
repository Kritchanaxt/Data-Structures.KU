#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Global pointer to the start of the linked list
struct node *start = NULL;

// Function prototypes
struct node *create_ll();                     
void display();                       
struct node *insert_beg();       
struct node *insert_end();       
struct node *delete_beg();      
struct node *delete_end();      
void find_data();                

int main() {
    int option;  
    do {
        printf("\n\n * ****MAIN MENU * ****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Find data");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 10: Exit");
        printf("\nSelect your choice: ");
        scanf("%d", &option); 

        switch (option) {
            case 1: 
                start = create_ll(); 
                printf("\n LINKED LIST CREATED"); 
                break;
            case 2: 
                display(); 
                break;
            case 3: 
                start = insert_beg(); 
                break;
            case 4: 
                start = insert_end(); 
                break;
            case 7:  
                start = delete_beg(); 
                break;
            case 8: 
                start = delete_end(); 
                break;
            case 5:  
                find_data(); 
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (option != 10);  
    
    return 0;
}

// Function to create the linked list with initial nodes
struct node *create_ll() {
    struct node *new_node, *ptr;  
    int num[] = {20, 30, 50, 60, 90}, i;  

    // Create the list with predefined numbers
    for (i = 0; i < 5; i++) {  
        new_node = (struct node *)malloc(sizeof(struct node)); 
        new_node->data = num[i];  
        new_node->next = NULL;  

        if (start == NULL) {  
            start = new_node;       
        } else {  
            ptr = start;  
            while (ptr->next != NULL)  
                ptr = ptr->next;
            ptr->next = new_node;  
        }
    }
    return start;  
}

// Function to display the linked list
void display() {
    struct node *ptr;  
    ptr = start;  
    while (ptr != NULL) {  
        printf("%d -> ", ptr->data);  
        ptr = ptr->next;  
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
struct node *insert_beg() {
    struct node *new_node;  
    int num;  
    printf("\n Enter the data: ");
    scanf("%d", &num);  
    new_node = (struct node *)malloc(sizeof(struct node));  
    new_node->data = num;  
    new_node->next = start;  
    start = new_node;  
    return start;  
}

// Function to insert a node at the end
struct node *insert_end() {
    struct node *ptr, *new_node;  
    int num;  
    printf("\n Enter the data: ");
    scanf("%d", &num);  
    new_node = (struct node *)malloc(sizeof(struct node));  
    new_node->data = num;  
    new_node->next = NULL;  
    if (start == NULL) {
        start = new_node;
    } else {
        ptr = start;  
        while (ptr->next != NULL)  
            ptr = ptr->next;
        ptr->next = new_node;  
    }
    return start;  
}

// Function to delete a node from the beginning
struct node *delete_beg() {
    struct node *ptr;  
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    ptr = start;  
    start = start->next;  
    free(ptr);  
    return start;  
}

// Function to delete a node from the end
struct node *delete_end() {
    struct node *ptr, *preptr;  
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    ptr = start;  
    if (ptr->next == NULL) {  // Only one node in the list
        free(ptr);
        start = NULL;
        return start;
    }
    while (ptr->next != NULL) {  
        preptr = ptr;  
        ptr = ptr->next;  
    }
    preptr->next = NULL;  
    free(ptr);  
    return start;  
}

// Function to find and display a specific data in the list
void find_data() {
    struct node *ptr = start;
    int search;
    printf("Find data: ");
    scanf("%d", &search);
    while (ptr != NULL && ptr->data != search) {
        ptr = ptr->next;
    }
    if (ptr != NULL && ptr->data == search) {
        printf("Data %d found.\n", ptr->data);
    } else {
        printf("Data not found.\n");
    }
}
