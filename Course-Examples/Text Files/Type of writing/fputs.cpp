#include <stdio.h>

int main() {
    FILE *fichier;
    fichier = fopen("exemple.txt", "w"); // Ouverture du fichier en mode écriture

    if (fichier != NULL) {
        fputs("Hello, world!", fichier); // Écriture de la chaîne de caractères dans le fichier
    }

    fclose(fichier); // Fermeture du fichier
    return 0;
}
