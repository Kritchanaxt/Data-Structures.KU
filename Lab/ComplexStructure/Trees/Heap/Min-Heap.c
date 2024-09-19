#include <stdio.h>

// Function to heapify a subtree rooted with node i
void minHeapify(int arr[], int n, int i) {
    int smallest = i;  // Assume the current node is the smallest
    int left = 2 * i + 1;  // Left child node
    int right = 2 * i + 2; // Right child node

    // If the left child is less than the current node
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If the right child is less than the current node
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If the smallest node is not the current node, swap and heapify
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        // Heapify the affected subtree
        minHeapify(arr, n, smallest);
    }
}

// Function to build a Min-Heap
void buildMinHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

// Function to print the values in the Min-Heap
void printHeap(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {40, 30, 15, 10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMinHeap(arr, n);

    printf("Min-Heap array: \n");
    printHeap(arr, n);

    return 0;
}
