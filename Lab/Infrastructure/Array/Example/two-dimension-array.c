#include <stdio.h>

// Initialize two 2D arrays with predefined values
int arr1[2][5] = {
    {1, 2, 3, 4, 5}, 
    {6, 7, 8, 9, 10}
};
int arr2[2][5] = {
    {11, 12, 13, 14, 15}, 
    {16, 17, 18, 19, 20}
};
int sum[2][5];  // Array to store the sum of arr1 and arr2
int diff[2][5];  // Array to store the difference of arr1 and arr2

// Function declarations
void sumTwoArrays();
void print2DArray(int arr[][5]);
void diffTwoArrays();

void main()
{
    sumTwoArrays();  // Call function to calculate the sum of arr1 and arr2
    printf("\n::Result of sum array::\n");
    print2DArray(sum);  // Print the resulting sum array

    diffTwoArrays();  // Call function to calculate the difference of arr1 and arr2
    printf("\n::Result of diff array::\n");
    print2DArray(diff);  // Print the resulting difference array
}

// Function to print a 2D array
void print2DArray(int arr[][5])
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the sum of two 2D arrays and store the result in sum array
void sumTwoArrays()
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
        {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

// Function to calculate the difference of two 2D arrays and store the result in diff array
void diffTwoArrays()
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
        {
            diff[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}

//! ::Result of diff array::
// -10 -10 -10 -10 -10 
// -10 -10 -10 -10 -10 

//? เมื่อคำนวณความแตกต่าง:
// arr1[0][0] - arr2[0][0] = 1 - 11 = -10
// arr1[0][1] - arr2[0][1] = 2 - 12 = -10
// arr1[0][2] - arr2[0][2] = 3 - 13 = -10
// arr1[0][3] - arr2[0][3] = 4 - 14 = -10
// arr1[0][4] - arr2[0][4] = 5 - 15 = -10
// arr1[1][0] - arr2[1][0] = 6 - 16 = -10
// arr1[1][1] - arr2[1][1] = 7 - 17 = -10
// arr1[1][2] - arr2[1][2] = 8 - 18 = -10
// arr1[1][3] - arr2[1][3] = 9 - 19 = -10
// arr1[1][4] - arr2[1][4] = 10 - 20 = -10

//* ดังนั้นทุกตำแหน่งในอาร์เรย์ diff จะมีค่าของ -10