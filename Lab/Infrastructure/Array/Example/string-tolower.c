#include <stdio.h>

int main()
{
    char str[100], lower_str[100];  // Declare arrays for the input string and the lowercase string
    int i = 0;  // Initialize index variable

    printf("\n Enter the string : ");
    gets(str);  // Get the input string from the user 

    // Convert each character to lowercase if it's an uppercase letter
    while (str[i] != '\0') // character null is \0
    {
        if (str[i] >= 'A' && str[i] <= 'Z')  // Check if the character is an uppercase letter
        {
            lower_str[i] = str[i] + ('a' - 'A'); // Find the difference between ASCII codes 'a' and 'A'.
        }
        else
        {
            lower_str[i] = str[i];  // Keep the character as is if it's not an uppercase letter
        }
        i++;
    }

    lower_str[i] = '\0';  // Null-terminate the lowercase string
    printf("\n The string converted into lower case is : ");
    puts(lower_str);  // Print the lowercase string
    return 0;  // End of the program
}
