# Semaine 04/16

- [ ] printf
- [ ] scanf

## printf

La sortie standard `stdout` est le flux de sortie par défaut avec 
`printf`

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

```c
int main() {
    int i = 42;
    long j = 1234567;
    float f = 3.14159;

    printf("i: %d, j: %ld, f: %f\n", i, j, f);
}
```

- `%d` afficher un `int`
- `%ld` afficher un `long int`
- `%5d` pour utiliser au minimum 5 positions pour afficher le nombre
- `%05d` pour remplir avec des zéros au lieu des espaces
- `%f` affiche `float`
- `%g` affiche `float` en supprimant les décimales inutiles
- `%5.2f` afficher un `float` avec 2 décimales le tout sur 5 positions
- `%hd` pour un `short`
- `%hhd` pour un `char`
- `%lld` pour un `long long int`
