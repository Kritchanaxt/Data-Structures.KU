
#include <stdio.h>

int main() {
    FILE *file;
    char buffer[100];

    file = fopen("example.txt", "r"); // Open file for reading
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    while (fgets(buffer, 100, file) != NULL) { // Read data from file
        printf("%s", buffer);
    }

    fclose(file); // Close the file.
    return 0;
}
