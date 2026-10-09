#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("Nombre d'arguments: %d\n", argc);

    for (int i = 0; i < argc; i++) {  // i++ === i = i + 1
        printf("%d: %s\n", i, argv[i]);
    }
}