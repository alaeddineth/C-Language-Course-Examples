#include <stdio.h>

// Fonction pour remplir les éléments du tableau
void remplirTableau(int tableau[], int taille) {
    printf("Entrez les éléments du tableau :\n");
    for (int i = 0; i < taille; i++) {
        printf("Élément %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }
}

// Fonction pour déterminer le nombre d'occurrences et l'indice de la première apparition
void occurrencesElement(int tableau[], int taille, int element) {
    int occurrences = 0;
    int firstIndex = -1;

    for (int i = 0; i < taille; i++) {
        if (tableau[i] == element) {
            occurrences++;
            if (firstIndex == -1) {
                firstIndex = i;
            }
        }
    }

    if (occurrences == 0) {
        printf("L'élément %d n'existe pas dans le tableau.\n", element);
    } else {
        printf("Le nombre d'occurrences de %d dans le tableau est : %d\n", element, occurrences);
        printf("L'indice de sa première apparition est : %d\n", firstIndex);
    }
}

int main() {
    int taille;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &taille);

    int tableau[taille];
    remplirTableau(tableau, taille);

    int element;
    printf("Entrez l'entier dont vous voulez trouver les occurrences : ");
    scanf("%d", &element);

    occurrencesElement(tableau, taille, element);

    return 0;
}
