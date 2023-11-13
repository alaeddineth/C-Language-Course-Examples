#include <stdio.h>

int main() {
    FILE *file;
    char name[20];
    int age;

    file = fopen("data.txt", "r");

    if (file) {
        while (fscanf(file, "%s %d", name, &age) != EOF) {
            printf("Name: %s, Age: %d\n", name, age); // Printing formatted data read from the file
        }
        fclose(file);
    } else {
        perror("Error opening file");
    }

    return 0;
}
