#include <stdio.h>

int main() {
    FILE *file;
    char c;

    file = fopen("example.txt", "r");

    if (file) {
        while ((c = fgetc(file)) != EOF) {
            printf("%c", c); // Printing each character read from the file
        }
        fclose(file);
    } else {
        perror("Error opening file");
    }

    return 0;
}
