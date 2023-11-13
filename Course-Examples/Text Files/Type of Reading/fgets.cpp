#include <stdio.h>

int main() {
    FILE *file;
    char buffer[255];

    file = fopen("example.txt", "r");

    if (file) {
        while (fgets(buffer, 255, file) != NULL) {
            printf("%s", buffer); // Printing each line read from the file
        }
        fclose(file);
    } else {
        perror("Error opening file");
    }

    return 0;
}
