
//? O(n^2) - Quadratic Time:

void printAllPairs(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d, %d) ", arr[i], arr[j]); // O(n^2)
        }
    }
}



//* O(n^2) - Quadratic Time Complexity Example: Print All Pairs

#include <stdio.h>

// Function to print all possible pairs in the array
void printAllPairs(int arr[], int n) {
    // Outer loop runs n times
    for (int i = 0; i < n; i++) {
        // Inner loop also runs n times for each iteration of the outer loop
        for (int j = 0; j < n; j++) {
            // Print the current pair (arr[i], arr[j])
            printf("(%d, %d) ", arr[i], arr[j]); // O(n^2) as it prints n*n pairs
        }
        printf("\n"); // New line for better readability
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    // Print all pairs in the array
    printf("All pairs in the array:\n");
    printAllPairs(arr, arrSize);

    return 0;
}
