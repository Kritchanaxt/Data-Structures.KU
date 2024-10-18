
//? O(n) - Linear Time:

void printAllElements(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // O(n)
    }
}



//* O(n) - Linear Time Complexity Example: Print All Elements

#include <stdio.h>

// Function to print all elements in the array
void printAllElements(int arr[], int n) {
    // Loop through each element in the array
    for (int i = 0; i < n; i++) {
        // Print the current element
        printf("%d ", arr[i]); // O(n) because it runs n times
    }
    printf("\n"); // New line for better readability after printing all elements
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    // Print all elements in the array
    printf("All elements in the array:\n");
    printAllElements(arr, arrSize);

    return 0;
}
