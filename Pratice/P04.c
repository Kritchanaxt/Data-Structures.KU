
#include <stdio.h>

void printAllData();
void addData(int, int);
void deleteData(int);

int marks[10] = {50, 55, 25, 75, 15, 30};
int n = 6;

void main() {
    printf("\n-- Array \"Original\" --\n");
    printAllData();
    printf("\n");

    addData(5, 80);
    printf("\n-- Array \"before add 80\"at index number 5 --\n");
    printAllData();
    printf("\n");

    deleteData(15);
    printf("\n-- Array \"after deleting 15\" --\n");
    printAllData();
    printf("\n");
}

void printAllData() {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\t", marks[i]);
    }
}

void addData(int pos, int val) {
    if (n >= 10 || pos < 0 || pos > n) {
        printf("Invalid position or array is full\n");
        return;
    }

    for (int i = n; i > pos; i--) {
        marks[i] = marks[i - 1];
    }

    marks[pos] = val;
    n++;
}

void deleteData(int val) {
    int i, pos = -1;

    for (i = 0; i < n; i++) {
        if (marks[i] == val) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Value not found in the array\n");
        return;
    }

    for (i = pos; i < n - 1; i++) {
        marks[i] = marks[i + 1];
    }

    marks[n - 1] = 0;

    n--;
}