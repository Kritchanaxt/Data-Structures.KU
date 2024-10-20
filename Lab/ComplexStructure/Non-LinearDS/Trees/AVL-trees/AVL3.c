
#include <stdio.h>
#include <stdlib.h>

// โครงสร้างของโหนดใน AVL Tree
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// ฟังก์ชันเพื่อหาความสูงของโหนด
int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// ฟังก์ชันเพื่อหาค่าสูงสุดระหว่างสองค่า
int max(int a, int b) {
    return (a > b) ? a : b;
}

// ฟังก์ชันสร้างโหนดใหม่
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // ความสูงของโหนดใหม่คือ 1
    return node;
}

// ฟังก์ชันหมุนขวา (Right Rotate)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // ทำการหมุน
    x->right = y;
    y->left = T2;

    // อัพเดทความสูง
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // คืนค่าโหนดใหม่ที่เป็นราก
    return x;
}

// ฟังก์ชันหมุนซ้าย (Left Rotate)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // ทำการหมุน
    y->left = x;
    x->right = T2;

    // อัพเดทความสูง
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // คืนค่าโหนดใหม่ที่เป็นราก
    return y;
}

// ฟังก์ชันเพื่อหาค่าความสมดุลของโหนด
int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// ฟังก์ชันแทรกโหนดใหม่ใน AVL Tree
Node* insert(Node* node, int key) {
    // ขั้นตอนมาตรฐานของการแทรกใน BST
    if (node == NULL) {
        return newNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node; // ไม่อนุญาตให้มีคีย์ซ้ำ
    }

    // อัพเดทความสูงของโหนดนี้
    node->height = 1 + max(height(node->left), height(node->right));

    // หาค่าความสมดุลของโหนดนี้เพื่อดูว่าไม่สมดุลหรือไม่
    int balance = getBalance(node);

    // กรณี Left-Left (LL)
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // กรณี Right-Right (RR)
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // กรณี Left-Right (LR)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // กรณี Right-Left (RL)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // คืนค่าโหนด (ไม่มีการหมุน)
    return node;
}

// ฟังก์ชันเพื่อแสดงผล AVL Tree ในรูปแบบ In-Order Traversal
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main() {
    Node* root = NULL;

    // แทรกข้อมูลใน AVL Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // แสดงผล AVL Tree
    printf("In-Order Traversal of the constructed AVL Tree is:\n");
    inOrder(root);

    return 0;
}
