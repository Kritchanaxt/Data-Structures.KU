
//* Using access to members of an array

#include <stdio.h>

int main() {
    int i;
    int numbers[6] = {10, 20, 30, 40, 50, 60};

    printf("Original Array: ");
    for (i = 0; i < 6; i++) {
        printf("%d,", numbers[i]);
    }

    printf("\n");
    printf("Change index 2: %d\n", numbers[2]);

    numbers[2] = 200;

    printf("New Array: ");
    for (i = 0; i < 6; i++) {
        printf("%d,", numbers[i]);
    }
    printf("\n");

    return 0;
}