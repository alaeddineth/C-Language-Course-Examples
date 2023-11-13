#include <stdio.h>

int main() {
    char operation;
    float num1, num2;
    char end = 'f';

    while (1) {
        printf("Entrez un premier réel, l'opération (+, -, *, /) et un deuxième réel ou 'f' pour quitter : ");
        scanf("%f %c %f", &num1, &operation, &num2);

        if (operation == end) {
            printf("Fin du programme.\n");
            break;
        }

        switch (operation) {
            case '+':
                printf("Le résultat de l'addition est : %.2f\n", num1 + num2);
                break;
            case '-':
                printf("Le résultat de la soustraction est : %.2f\n", num1 - num2);
                break;
            case '*':
                printf("Le résultat de la multiplication est : %.2f\n", num1 * num2);
                break;
            case '/':
                if (num2 != 0) {
                    printf("Le résultat de la division est : %.2f\n", num1 / num2);
                } else {
                    printf("Erreur ! Division par zéro.\n");
                }
                break;
            default:
                printf("Opération non valide.\n");
        }
    }

    return 0;
}
