
//? O(n!) - Factorial Time: 

void permute(char* str, int left, int right) {
    if (left == right) {
        printf("%s\n", str); // O(n!)
    } else {
        for (int i = left; i <= right; i++) {
            swap((str + left), (str + i));
            permute(str, left + 1, right);
            swap((str + left), (str + i)); // backtrack
        }
    }
}
  


//* O(n!) - Factorial Time Complexity Example: Permutations of a String

#include <stdio.h>
#include <string.h>

// Function to swap two characters
void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate permutations of a string
void permute(char* str, int left, int right) {
    if (left == right) {
        printf("%s\n", str); // Print the permutation
    } else {
        for (int i = left; i <= right; i++) {
            swap((str + left), (str + i));  // Swap current character with the character at index 'i'
            permute(str, left + 1, right);  // Recursively call permute for the next position
            swap((str + left), (str + i));  // Backtrack to restore the original string
        }
    }
}

int main() {
    char str[] = "ABC"; // Example string
    int n = strlen(str);
    printf("Permutations of the string \"%s\":\n", str);
    permute(str, 0, n - 1);
    return 0;
}
