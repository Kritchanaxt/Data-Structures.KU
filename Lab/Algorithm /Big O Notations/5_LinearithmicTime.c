
//? O(n log n) - Linearithmic Time:

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid); // O(n log n)
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}



//* O(n log n) - Linearithmic Time Complexity Example: Merge Sort

#include <stdio.h>

// Function to merge two sorted halves of the array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    // Create temporary arrays to hold the sorted subarrays
    int L[n1], R[n2];

    // Copy data to the temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on the array
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Calculate the middle index
        int mid = left + (right - left) / 2;

        // Recursively sort the first half and the second half
        mergeSort(arr, left, mid);    // Sort the left half
        mergeSort(arr, mid + 1, right); // Sort the right half

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform merge sort
    mergeSort(arr, 0, arrSize - 1);

    printf("Sorted array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
