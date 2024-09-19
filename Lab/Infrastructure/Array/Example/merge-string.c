#include <stdio.h>

int main()
{
    char firstName[100], lastName[50];  // Declare variables for storing first name and last name
    int i = 0, j = 0;  // Declare index variables

    printf("\n Enter the first name : ");
    gets(firstName);  // e from the user Get the first name
    
    printf("\n Enter the last name string : ");
    gets(lastName);  // Get the last name from the user 

    // Find the position of the '\0' in lastName
    while (lastName[i] != '\0')
    {
        i++;  // Increment i until the null terminator is found
    }

    lastName[i] = ' ';  // Add a space after the last name
    i++;  // Move i to the next position

    // Copy the first name to the last name after the space
    while (firstName[j] != '\0')
    {
        lastName[i] = firstName[j];  // Copy characters from first name to last name
        i++;  // Move i to the next position in last name
        j++;  // Move j to the next position in first name
    }

    lastName[i] = '\0';  // Add null terminator at the end of the combined string
    printf("\n After appending, full name is : ");
    puts(lastName);  // Print the last name after appending the first name
    return 0;  // End of the program
}
