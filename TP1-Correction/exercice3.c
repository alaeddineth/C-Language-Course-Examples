#include <stdio.h>

// Fonction récursive pour calculer le factoriel
long long factorielRecursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorielRecursive(n - 1);
    }
}

int main() {
    int nombre;
    printf("Entrez un entier positif : ");
    scanf("%d", &nombre);

    // Gestion des cas spéciaux pour 0 et les nombres négatifs
    if (nombre < 0) {
        printf("Erreur ! Le factoriel d'un nombre négatif n'est pas défini.");
    } else {
        long long resultat = factorielRecursive(nombre);
        printf("Le factoriel de %d est : %lld", nombre, resultat);
    }

    return 0;
}
