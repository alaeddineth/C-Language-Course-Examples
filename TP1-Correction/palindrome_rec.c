#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Fonction itérative pour vérifier si un mot est un palindrome
bool estPalindromeIteratif(char mot[], int taille) {
    int debut = 0;
    int fin = taille - 1;
    while (fin > debut) {
        if (mot[debut++] != mot[fin--]) {
            return false;
        }
    }
    return true;
}

int main() {
    char mot[] = "RADAR";

    if (estPalindromeIteratif(mot, strlen(mot))) {
        printf("%s est un palindrome.\n", mot);
    } else {
        printf("%s n'est pas un palindrome.\n", mot);
    }

    return 0;
}
