
//? O(2^n) - Exponential Time: 

int fibonacci(int n) {
    if (n <= 1) {
        return n; // O(2^n)
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}



//*  O(2^n) - Exponential Time Complexity Example: Fibonacci Sequence

#include <stdio.h>

// Function to calculate Fibonacci sequence using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base cases: return n if n is 0 or 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive calls
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Fibonacci of %d is %d\n", n, fibonacci(n));

    return 0;
}
