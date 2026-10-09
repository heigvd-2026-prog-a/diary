#include <stdio.h>

int main() {
    int value = 666;

    printf("Entrez un nombre: ");

    // En C on test toujours la valeur de retour de scanf
    if (scanf("%d", &value) != 1) {
        printf("Erreur: ce n'est pas un nombre valide!\n");
    }
    printf("Tu as entré: %d\n", value);
}