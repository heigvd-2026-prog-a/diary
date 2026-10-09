# Semaine 04/16

- [ ] printf ([printf.c](printf.c))
- [ ] scanf ([scanf.c](scanf.c))

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


### Structure d'un format

```text
%[drapeaux][largeur][.précision][longueur]conversion
```

| Élément     | Exemples        | Rôle                                                     |
| ----------- | --------------- | -------------------------------------------------------- |
| drapeaux    | `0`, `-`, `+`   | remplir de zéros, aligner à gauche, toujours le signe    |
| largeur     | `8`             | nombre minimum de positions                              |
| précision   | `.2`, `.10`     | nombre de décimales pour un réel                         |
| longueur    | `h`, `hh`, `l`, `ll` | taille de l'entier (`short`, `char`, `long`, `long long`) |
| conversion  | `d`, `f`, `x`…  | type d'affichage                                         |

### Conversions courantes

- `%c` afficher un caractère
- `%s` afficher une chaîne de caractères
- `%u` afficher un entier non signé (`unsigned int`)
- `%x` / `%X` afficher en hexadécimal (minuscules / majuscules)
- `%o` afficher en octal
- `%b` afficher en binaire (C23, `%032b` pour 32 bits)
- `%e` notation scientifique
- `%p` afficher une adresse (pointeur)
- `%%` afficher le caractère `%`

### Exemples

```c
printf("%8d|\n", 1200);      //     1200|
printf("%-8d|\n", 1200);     // 1200    |
printf("%08d|\n", 102);      // 00000102|
printf("%+d\n", 42);         // +42
printf("%8.2f|\n", 3.14159); //     3.14|
printf("%08x\n", 12345);     // 00003039
printf("%c %s\n", 'A', "C"); // A C
printf("100%%\n");           // 100%
```

Exemple complet: [printf.c](printf.c)

### Pièges

- Le format doit correspondre au type de l'argument, sinon le comportement
  est indéfini (`printf("%d", 3.14)` est une erreur).
- Un `float` est promu en `double` lors de l'appel, donc `%f` convient aux deux.
- Les `float` ont environ 7 chiffres significatifs: au-delà, les décimales
  affichées sont du bruit (voir `printf.c`).
- `printf` n'ajoute pas de retour à la ligne: penser à `\n`.

### Pour aller plus loin

- [Entrées/sorties console (`stdio`)](https://heig-tin-info.github.io/handbook/course-c/15-fundations/stdio/)
- [Types de données](https://heig-tin-info.github.io/handbook/course-c/15-fundations/datatype/)
- [Opérateurs](https://heig-tin-info.github.io/handbook/course-c/15-fundations/operators/)
- [Syntaxe du langage C](https://heig-tin-info.github.io/handbook/course-c/15-fundations/syntax/)
- [Bibliothèque standard](https://heig-tin-info.github.io/handbook/course-c/35-libraries/standard-library/)
