
#include <stdio.h>

int main() {
    char firstName[100], lastName[50];
    int i = 0, j = 0;

    printf("\n Enter the first name: ");
    gets(firstName);

    printf("\n Enter the last name: ");
    gets(lastName);

    while (lastName[i] != '\0') {
        i++;
    }

    lastName[i] = ' ';
    i++;
    
    while (firstName[j] != '\0') { 
        lastName[i] = firstName[j];
        i++;
        j++;
    }

    lastName[i] = '\0';
    printf("\n After the appending, full name is: ");
    puts(lastName);
    return 0;
}

// None = \0