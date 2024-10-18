
#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("example.txt", "w"); // Open file for writing.
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    fprintf(file, "Hello, World!\n"); // Write data to file
    fclose(file); // Close the file.
    
    printf("File has been written successfully.\n");
    return 0;
}
