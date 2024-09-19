#include <stdio.h>
#include <stdlib.h>

// Structure of a Node in Binary Tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new Node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(struct Node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Function to insert a node at a specific position
struct Node* insertAtPosition(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    // Use a queue to perform level order traversal
    struct Node** queue = (struct Node**)malloc(100 * sizeof(struct Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];

        // Check if the left child is empty
        if (current->left == NULL) {
            current->left = newNode(data);
            free(queue);
            return root;
        } else {
            queue[rear++] = current->left;
        }

        // Check if the right child is empty
        if (current->right == NULL) {
            current->right = newNode(data);
            free(queue);
            return root;
        } else {
            queue[rear++] = current->right;
        }
    }

    free(queue);
    return root;
}

// Function to delete a node from the Binary Tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return NULL; // Tree is empty
    }

    // If the node to be deleted is found
    if (root->data == key) {
        // If the node is a leaf
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // If the node has one child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children, find the inorder successor
        struct Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        // Replace the node's data with the inorder successor's data
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
        return root;
    }

    // Recursively delete in the left or right subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else {
        root->right = deleteNode(root->right, key);
    }

    return root;
}

// Main function
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Preorder traversal of Binary Tree is: \n");
    preorderTraversal(root);
    printf("\n");

    // Insert a new node
    root = insertAtPosition(root, 6);
    printf("Preorder traversal after inserting 6:\n");
    preorderTraversal(root);
    printf("\n");

    // Delete a node
    root = deleteNode(root, 3);
    printf("Preorder traversal after deleting 3:\n");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
