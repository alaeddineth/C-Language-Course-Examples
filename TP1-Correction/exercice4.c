#include <stdio.h>

// Fonction récursive pour trouver le nombre d'occurrences et l'indice de la première apparition
void occurrencesElementRecursive(int tableau[], int taille, int element, int index, int *occurrences, int *firstIndex) {
    if (index == taille) {
        return;
    }
    if (tableau[index] == element) {
        (*occurrences)++;
        if (*firstIndex == -1) {
            *firstIndex = index;
        }
    }
    occurrencesElementRecursive(tableau, taille, element, index + 1, occurrences, firstIndex);
}

int main() {
    int tableau[] = {1, 2, 3, 4, 2, 5, 2, 6, 7, 2};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    int element = 2;
    int occurrences = 0;
    int firstIndex = -1;

    occurrencesElementRecursive(tableau, taille, element, 0, &occurrences, &firstIndex);

    if (occurrences == 0) {
        printf("L'élément %d n'existe pas dans le tableau.\n", element);
    } else {
        printf("Le nombre d'occurrences de %d dans le tableau est : %d\n", element, occurrences);
        printf("L'indice de sa première apparition est : %d\n", firstIndex);
    }

    return 0;
}
