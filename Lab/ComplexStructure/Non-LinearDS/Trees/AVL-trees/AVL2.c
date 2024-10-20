#include <stdio.h>
#include <stdlib.h>

// โครงสร้างของโหนดใน AVL Tree
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// ฟังก์ชันหาค่าความสูงของโหนด
int height(Node* N) {
    if (N == NULL) {
        return 0;
    }
    return N->height;
}

// ฟังก์ชันหาค่ามากที่สุดระหว่างสองค่า
int max(int a, int b) {
    return (a > b) ? a : b;
}

// สร้างโหนดใหม่
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // ใบไม้มีความสูงเป็น 1
    return node;
}

// หมุนขวา (Right Rotate)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // หมุนขวา
    x->right = y;
    y->left = T2;

    // อัพเดทความสูง
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // คืนค่าโหนดใหม่ที่เป็นราก
    return x;
}

// หมุนซ้าย (Left Rotate)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // หมุนซ้าย
    y->left = x;
    x->right = T2;

    // อัพเดทความสูง
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // คืนค่าโหนดใหม่ที่เป็นราก
    return y;
}

// หา Balance Factor ของโหนด
int getBalance(Node* N) {
    if (N == NULL) {
        return 0;
    }
    return height(N->left) - height(N->right);
}

// แทรกโหนดใหม่ใน AVL Tree และคืนค่า root ใหม่
Node* insert(Node* node, int key) {
    // 1. แทรกในแบบของ Binary Search Tree ปกติ
    if (node == NULL) {
        return newNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        // กรณี key ซ้ำ ไม่อนุญาตให้แทรก
        return node;
    }

    // 2. อัพเดทความสูงของโหนดปัจจุบัน
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. หา Balance Factor เพื่อตรวจสอบว่าต้นไม้ไม่สมดุลหรือไม่
    int balance = getBalance(node);

    // ถ้าต้นไม้ไม่สมดุล ให้แก้ไขตาม 4 กรณี
    // กรณี LL (Left Left)
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // กรณี RR (Right Right)
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // กรณี LR (Left Right)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // กรณี RL (Right Left)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // คืนค่าโหนดปัจจุบัน
    return node;
}

// ฟังก์ชันแสดงข้อมูลของ AVL Tree แบบ In-order
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = NULL;

    // แทรกข้อมูลลงใน AVL Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // แสดงผล AVL Tree
    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);

    return 0;
}