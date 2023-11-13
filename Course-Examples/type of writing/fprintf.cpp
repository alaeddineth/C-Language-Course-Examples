#include <stdio.h>

int main() {
    FILE *fichier;
    int age = 40;
    float taille = 1.90;

    fichier = fopen("exemple.txt", "w"); // Ouverture du fichier en mode écriture

    if (fichier != NULL) {
        fprintf(fichier, "J'ai %d ans et je mesure %.2f mètres de haut.", age, taille); // Écriture formatée dans le fichier
    }

    fclose(fichier); // Fermeture du fichier
    return 0;
}
