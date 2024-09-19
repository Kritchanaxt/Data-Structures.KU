#include <stdio.h>

// Function to heapify a subtree rooted with node i
void maxHeapify(int arr[], int n, int i) {
    int largest = i;  // Assume the current node is the largest
    int left = 2 * i + 1;  // Left child node
    int right = 2 * i + 2; // Right child node

    // If the left child is greater than the current node
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is greater than the current node
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest node is not the current node, swap and heapify
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Heapify the affected subtree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a Max-Heap
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// Function to print the values in the Max-Heap
void printHeap(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 15, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMaxHeap(arr, n);

    printf("Max-Heap array: \n");
    printHeap(arr, n);

    return 0;
}
