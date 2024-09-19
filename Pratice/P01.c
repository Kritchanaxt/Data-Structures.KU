
//* Array declaration and initialization

#include <stdio.h>

int main() {
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;

    for (i = 0; i < 10; i++) {
        printf("%d", numbers[i]);
    }

    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%d", numbers[i] + 1);
    }

    printf("\n");

    return 0;
}