#include <stdio.h>

// Function declarations
void printAllData();
void addData(int, int);
void deleteData(int);

// Initialize array and size
int marks[10] = {49, 51, 23, 77, 12, 29};
int n = 6;

void main()
{
    // Print array before adding a new value
    printf("\n-- Array \"before add 79\" at index number 3 --\n");
    printAllData();
    printf("\n");

    // Add 79 at index 3 and print the array
    addData(3, 79);
    printf("\n-- Array \"after add 79\" at index number 3 --\n");
    printAllData();
    printf("\n");

    // Delete the value 23 from the array and print the array
    deleteData(23);
    printf("\n-- Array \"after delete 23\" --\n");
    printAllData();
    printf("\n");
}

// Function to print all data in the array
void printAllData()
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", marks[i]);
    }
}

// Function to add new data into the array by position and its value
void addData(int pos, int val)
{
    // Check if position is valid and array is not full
    if (n >= 10 || pos < 0 || pos > n)
    {
        printf("Invalid position or array is full\n");
        return;
    }

    // Shift elements to the right to make space for the new value
    for (int i = n; i > pos; i--)
    {
        marks[i] = marks[i - 1];
    }

    // Insert the new value at the specified position
    marks[pos] = val;
    n++;
}

// Function to delete data by its value
void deleteData(int val)
{
    int pos = -1;

    // Find the position of the value to be deleted
    for (int i = 0; i < n; i++)
    {
        if (marks[i] == val)
        {
            pos = i;
            break;
        }
    }

    // If value is not found, print a message and return
    if (pos == -1)
    {
        printf("Value not found in the array\n");
        return;
    }

    // Shift elements to the left to fill the gap left by the deleted value
    for (int i = pos; i < n - 1; i++)
    {
        marks[i] = marks[i + 1];
    }

    // Optional: Clear the last element
    marks[n - 1] = 0; 

    // Decrease the size of the array
    n--;
}
