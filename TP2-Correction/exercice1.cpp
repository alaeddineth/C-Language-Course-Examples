#include <stdio.h>

int main() {
    FILE *f1, *f2, *fusion;
    char c1, c2;

    f1 = fopen("f1.dat", "r");
    f2 = fopen("f2.dat", "r");
    fusion = fopen("fusion.dat", "w");

    // Check if files are opened successfully
    if (f1 == NULL || f2 == NULL || fusion == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    // Merge the sorted files
    while ((fscanf(f1, "%c", &c1) != EOF) && (fscanf(f2, "%c", &c2) != EOF)) {
        if (c1 <= c2) {
            fprintf(fusion, "%c", c1);
            fseek(f2, -1, SEEK_CUR); // Move the cursor back by 1 position in f2
        } else {
            fprintf(fusion, "%c", c2);
            fseek(f1, -1, SEEK_CUR); // Move the cursor back by 1 position in f1
        }
    }

    // Copy the remaining elements of f1, if any
    while (fscanf(f1, "%c", &c1) != EOF) {
        fprintf(fusion, "%c", c1);
    }

    // Copy the remaining elements of f2, if any
    while (fscanf(f2, "%c", &c2) != EOF) {
        fprintf(fusion, "%c", c2);
    }

    // Close all files
    fclose(f1);
    fclose(f2);
    fclose(fusion);

    return 0;
}
