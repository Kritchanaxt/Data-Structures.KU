
//? O(log n) - Logarithmic Time:

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // O(log n)
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}



//* O(log n) - Logarithmic Time Complexity Example: Binary Search

#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1; // Initialize the left and right pointers

    // Loop until the search space is exhausted
    while (left <= right) {
        // Calculate the middle index to divide the search space
        int mid = left + (right - left) / 2;

        // Check if the middle element is the target
        if (arr[mid] == target) {
            return mid; // Target found, return its index
        }
        // If the target is greater than the middle element, ignore the left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If the target is smaller than the middle element, ignore the right half
        else {
            right = mid - 1;
        }
    }
    // If the target is not found in the array, return -1
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40}; // Example sorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int target = 10; // Element to search for

    // Perform binary search and print the result
    int result = binarySearch(arr, n, target);
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
