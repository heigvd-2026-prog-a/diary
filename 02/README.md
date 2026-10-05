# Semaine 02/16

## Compilateur

`gcc` est un compilateur pour le langage C. Il transforme un code source écrit en C en un fichier exécutable. L'exemple hello world est le plus simple pour illustrer le fonctionnement d’un compilateur:

```c
$ cat hello.c
#include <stdio.h>

int main() {
    printf("Hello World!\n");
    return 0;
}
```

Puis on peut compiler le code source avec la commande suivante:

```bash
$ gcc hello.c -o hello
$ ./hello
Hello World!
```

N'oubliez pas le `./` devant le nom du fichier exécutable pour l'exécuter dans le terminal.

## Résumé du labo-01

- Utilisation de `gcc` pour compiler un programme en C
- Utilisation de `make` pour automatiser la compilation
- Utilisation de `gdb` pour déboguer un programme en C
