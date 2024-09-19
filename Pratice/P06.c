
#include <stdio.h>

int main() {
    char str[100], lower_str[100];
    int i = 0;

    printf("\n Enter the string: ");
    gets(str);

    while (str[i] != '\0') { 
        if (str[i] >= 'A' && str[i] <= 'Z') {
            lower_str[i] = str[i] + ('a' - 'A');
        } else {
            lower_str[i] = str[i];
        }
        i++;
    }

    lower_str[i] = '\0';
    printf("\n The string converted into lower case is: ");
    puts(lower_str);
    return 0;
}