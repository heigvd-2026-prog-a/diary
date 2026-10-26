/*
Exercice : deviner un nombre
Réaliser un programme qui se comporte comme suit:

$ ./guess 100
J'ai choisi un nombre entre 1 et 100 quel est-il ?
> 50
C'est plus grand !
> 75
C'est plus petit !
> 63
C'est plus grand !
> 69
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int max = atoi(argv[1]);
    int value = (rand() % max) + 1;
    printf("J'ai choisi un nombre entre 1 et %d quel est-il ?\n", max);
    int guess;
    do {
        printf("> ");
        if (scanf("%d", &guess) != 1) return -2;

        if (value > guess) {
            printf("C'est plus petit !\n");
        } else if (value < guess) {
            printf("C'est plus grand !\n");
        }
    } while (guess != value);

    printf("Bravo\n");    
}