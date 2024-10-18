
//? O(1) - Constant Time:

int getFirstElement(int arr[]) {
    return arr[0]; // O(1)
}



//* O(1) - Constant Time Complexity Example: Get First Element

#include <stdio.h>

// Function to get the first element of the array
int getFirstElement(int arr[]) {
    return arr[0]; // O(1) because it always accesses the first element directly
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};

    // Get the first element of the array
    int firstElement = getFirstElement(arr);
    
    // Print the first element
    printf("The first element in the array is: %d\n", firstElement);

    return 0;
}
