#include <stdio.h>

int main() {
    FILE *fichier;
    fichier = fopen("exemple.txt", "w"); // Ouverture du fichier en mode écriture

    if (fichier != NULL) {
        fputc('H', fichier); // Écriture du caractère 'H' dans le fichier
        fputc('e', fichier); // Écriture du caractère 'e' dans le fichier
        fputc('l', fichier); // Écriture du caractère 'l' dans le fichier
        fputc('l', fichier); // Écriture du caractère 'l' dans le fichier
        fputc('o', fichier); // Écriture du caractère 'o' dans le fichier
    }

    fclose(fichier); // Fermeture du fichier
    return 0;
}
