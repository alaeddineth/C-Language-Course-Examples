#include <stdio.h>

int main() {
    FILE *file;
    char nom[50];
    char article[50];
    int nombre;
    float prix;

    file = fopen("data.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fscanf(file, "%s %s %d %f", nom, article, &nombre, &prix) != EOF) {
        printf("Nom: %s, Article: %s, Nombre: %d, Prix: %.2f\n", nom, article, nombre, prix);
    }

    fclose(file);
    return 0;
}
