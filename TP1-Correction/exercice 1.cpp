#include <stdio.h>

int main() {
    int n, i;
    long long factoriel = 1;

    printf("Entrez un entier positif : ");
    scanf("%d", &n);

    // Gestion des cas spéciaux pour 0 et les nombres négatifs
    if (n < 0) {
        printf("Erreur ! Le factoriel d'un nombre négatif n'est pas défini.");
    } else {
        for (i = 1; i <= n; ++i) {
            factoriel *= i; // Calcul du factoriel en multipliant de 1 à n
        }
        printf("Le factoriel de %d est : %lld", n, factoriel);
    }
    return 0;
}
