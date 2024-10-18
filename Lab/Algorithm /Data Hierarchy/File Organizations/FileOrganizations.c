
#include <stdio.h>

typedef struct {
    int id;
    char name[50];
} Student;

int main() {
    FILE *file;
    Student s;

    // Open file for writing
    file = fopen("students.dat", "w");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

   // Write data to file
    s.id = 1;
    snprintf(s.name, 50, "John Doe");
    fwrite(&s, sizeof(Student), 1, file);

    s.id = 2;
    snprintf(s.name, 50, "Jane Smith");
    fwrite(&s, sizeof(Student), 1, file);

    fclose(file); // Close the file.

    // Open file for reading
    file = fopen("students.dat", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Read data from file
    while (fread(&s, sizeof(Student), 1, file)) {
        printf("ID: %d, Name: %s\n", s.id, s.name);
    }

    fclose(file); // Close the file.
    return 0;
}
