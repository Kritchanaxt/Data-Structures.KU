
#include <stdio.h>

int arr1[2][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10}
};

int arr2[2][5] = {
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20}
};

int sum[2][5];

int diff[2][5];

void sumTwoArrays();
void print2DArray(int arr[][5]);
void diffTwoArrays();

void main() {
    sumTwoArrays();
    printf("Sum of the two arrays:\n");
    print2DArray(sum);

    diffTwoArrays();
    printf("\nDifference of the two arrays:\n");
    print2DArray(diff);
}

// Prints the two arrays (sum and diff)
void print2DArray(int arr[][5]) {
    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

// Calculate values sum two arrays
void sumTwoArrays() {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 5; j++) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

// Calculate values difference between two arrays
void diffTwoArrays() {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 5; j++) {
            diff[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}