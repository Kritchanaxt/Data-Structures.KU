
//* Declaring a multidimensional array

#include <stdio.h>

int main() {
    int i, j;
    int matrix[6][6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };

    for(i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;

}