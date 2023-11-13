#include <stdio.h>
#include <stdlib.h>

struct Data {
    int id;
    float value;
};

int main() {
    FILE *file;
    struct Data data_write = { 1, 3.14 };
    struct Data data_read;

    // Écriture de données binaires dans un fichier
    file = fopen("databinary.bin", "wb");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    if (fwrite(&data_write, sizeof(struct Data), 1, file) != 1) {
        perror("Error writing to file");
        return -1;
    }

    fclose(file);

    // Lecture de données binaires à partir du fichier
    file = fopen("databinary.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    if (fread(&data_read, sizeof(struct Data), 1, file) != 1) {
        perror("Error reading from file");
        return -1;
    }

    printf("Data read: id = %d, value = %f\n", data_read.id, data_read.value);

    fclose(file);

    return 0;
}
