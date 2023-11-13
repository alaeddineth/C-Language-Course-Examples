#include <stdio.h>

int main() {
    FILE *file;
    char name[50];
    int age;

    file = fopen("data.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (!feof(file)) {
        if (fscanf(file, "%s %d", name, &age) == 2) {
            printf("Name: %s, Age: %d\n", name, age);
        }
    }

    fclose(file);
    return 0;
}
