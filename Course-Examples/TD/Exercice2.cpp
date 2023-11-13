#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

struct Data {
    char nom[50];
    char article[50];
    int nombre;
    float prix;
};

int main() {
    FILE *file;
    struct Data data[MAX_LINES];
    int i = 0;

    file = fopen("data.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fscanf(file, "%s %s %d %f", data[i].nom, data[i].article, &data[i].nombre, &data[i].prix) != EOF) {
        i++;
    }

    fclose(file);

    // Parcourir le tableau de structures et afficher son contenu
    for (int j = 0; j < i; j++) {
        printf("Nom: %s, Article: %s, Nombre: %d, Prix: %.2f\n", data[j].nom, data[j].article, data[j].nombre, data[j].prix);
    }

    return 0;
}
