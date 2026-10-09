# Semaine 04/16

## Au programme

- [x] Conventions de nommage et identifiants
- [x] Types et constantes littérales
- [x] `printf`: affichage formaté ([printf.c](printf.c))
- [x] `scanf`: lecture formatée ([scanf.c](scanf.c), [scanf2.c](scanf2.c))
- [x] Arguments de la ligne de commande ([arguments.c](arguments.c), [parameters.c](parameters.c))
- [x] Conversion chaîne → entier à la main ([atoi.c](atoi.c))

---

## 1. Nommage et identifiants

### Styles de nommage

| Style       | Exemples                                          | Usage typique                 |
| ----------- | ------------------------------------------------- | ----------------------------- |
| Pascal Case | `ComputeSum`, `NumberOfApplesInTheBin`            | types, classes (autres langages) |
| Camel Case  | `computeSum`, `numberOfAppleInTheBin`             | variables/fonctions (Java, JS) |
| Snake Case  | `compute_sum`, `number_of_apples_in_the_bin`      | **convention usuelle en C**   |
| Kebab Case  | `compute-sum`, `a-b-c-d`                          | **interdit en C** (`-` est l'opérateur de soustraction) |

En C on utilise le *snake case*. Un identifiant commençant par `_` est légal
(`_toto`) mais réservé en pratique à la bibliothèque standard et au compilateur:
à éviter dans notre code.

### Règle de formation d'un identifiant

Un identifiant (nom de variable, de fonction, de type…) respecte l'expression
régulière:

```text
[a-zA-Z_][0-9a-zA-Z_]*
```

Il commence par une lettre ou `_`, suivi de lettres, chiffres ou `_`.
Valides: `points`, `a`, `b`, `compute_sum`, `main`. Invalides: `2fast`,
`compute-sum`, `a b`.

Le langage est **sensible à la casse**: `points` et `Points` sont deux
identifiants différents. Les mots-clés (`int`, `return`, `if`…) ne peuvent pas
servir d'identifiants.

### Et l'Unicode ?

Le standard ne garantit que l'ASCII, mais GCC accepte des caractères UTF-8
dans les identifiants. C'est amusant, **mais à ne pas faire** (portabilité,
lisibilité, outils): [test-identifier.c](test-identifier.c)

```c
#include <stdio.h>

int ညအော = 42;
int 💩 = 23;
int _toto_aime_les_biscuits = 8;

int main() {
    printf("%d\n", ညအော);
    printf("%d\n", 💩);
}
```

### Déclaration vs définition

```c
int compute_sum(int a, int b);   // prototype (déclaration): nom, paramètres, retour

int main() {
    int points = 0;              // variable entière initialisée
    double area = 0.;            // réel double précision
}
```

Toujours **initialiser** les variables: une variable locale non initialisée
contient une valeur indéterminée.

---

## 2. Types et constantes littérales

Types de base vus jusqu'ici: `char`, `short`, `int`, `long`, `long long`,
`float`, `double` (et leurs variantes `unsigned`).

Une constante littérale a elle-même un type, déterminé par son écriture:

| Littéral          | Type                          |
| ----------------- | ----------------------------- |
| `123`             | `int`                         |
| `123u`            | `unsigned int`                |
| `123l`            | `long int`                    |
| `123ll`           | `long long int`               |
| `123ull`          | `unsigned long long int`      |
| `3.14`            | `double` (64 bits)            |
| `3.14f`           | `float` (32 bits)             |
| `'c'`             | `char` (8 bits); `'abc'` est interdit |
| `"toto"`          | chaîne: `char*`, adresse d'un tableau de caractères terminé par `\0` |

### Bases numériques

| Notation     | Base        | Exemple                |
| ------------ | ----------- | ---------------------- |
| `123`        | décimal     | `123`                  |
| `0x12`       | hexadécimal | `0x12` (= 18), `0x12ull` |
| `0b1001001110010` | binaire (C23 / extension GCC) | `0b101` (= 5) |
| `0344`       | octal (préfixe `0` !) | `0344` (= 228)   |

Piège: `012` n'est **pas** 12 mais 10 (octal).

### Chaînes de caractères

```c
#include <stdio.h>

int main() {
   char* text = "salut ça va ?";
   printf("%s\n", text);
}
```

Une chaîne est un tableau de `char` terminé par le caractère nul `'\0'`.

---

## 3. `printf`

La sortie standard `stdout` est le flux de sortie par défaut avec `printf`.

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

### Exemple complet: [printf.c](printf.c)

```c
#include <stdio.h>

int main() {
    int i = 42;
    long j = 1234567;
    float f = 3.14159;

    printf("i: %7d, j: %ld, f: %f\n", i, j, f);

    printf("i: %7d, ", i);
    printf("j: %ld, ", j);
    printf("f: %f\n", f);

    printf("%8d\n", 12);
    printf("%08d\n", 102);
    printf("%8d\n", 1200);
    printf("%8d\n", 9876004);
    printf("-----\n");

    printf("%8f\n", 3.1415926535);
    printf("%8.2f\n", 30.1415926535);

    printf("%.10f\n", 0.123456789f);
    printf("%.10f\n", 1.123456789f);
    printf("%.10f\n", 12.123456789f);
    printf("%.10f\n", 123.123456789f);
    printf("%.10f\n", 1234.123456789f);
    printf("%.10f\n", 1234567890.123456789f);

    printf("%08.3f\n", 12.123456789f);

    int foo = 12345;
    printf("%d\n", foo);
    printf("%032b\n", foo);
    printf("%08x\n", foo);
}
```

À retenir de cet exemple:

- Un seul `printf` avec plusieurs `%` est équivalent à plusieurs `printf`
  successifs (lignes 1 et 2 du programme).
- `%8f` ne limite pas les décimales: `%f` en affiche toujours 6 par défaut. Pour
  les contrôler, il faut la précision: `%8.2f`.
- Les `%.10f` successifs montrent qu'un `float` n'a que ~7 chiffres
  significatifs: plus le nombre est grand, moins il reste de décimales
  exactes, le reste est du bruit.
- Un même entier (`12345`) s'affiche en décimal, binaire (`%032b`) ou
  hexadécimal (`%08x`): c'est la même valeur, seule la représentation change.

### Pièges

- Le format doit correspondre au type de l'argument, sinon le comportement
  est indéfini (`printf("%d", 3.14)` est une erreur).
- Un `float` est promu en `double` lors de l'appel, donc `%f` convient aux deux.
- Les `float` ont environ 7 chiffres significatifs: au-delà, les décimales
  affichées sont du bruit (voir `printf.c`).
- `printf` n'ajoute pas de retour à la ligne: penser à `\n`.

---

## 4. `scanf`

`scanf` est le pendant de `printf` pour **lire** sur l'entrée standard
`stdin` (le clavier par défaut). Les conversions sont similaires (`%d`, `%f`,
`%c`, `%s`…), mais il faut passer l'**adresse** de la variable à remplir, avec
l'opérateur `&`:

```c
int value;
scanf("%d", &value);   // &value: l'adresse de value
```

Sans `&`, `scanf` écrirait à une adresse invalide (comportement indéfini).

### Exemple: convertisseur décimal → hexadécimal / binaire ([scanf.c](scanf.c))

```c
/** 
 * Convert number into hex or binary
 */
#include <stdio.h>

int main() {
    printf("Bienvenue dans le convertisseur\n");
    printf("-------------------------------\n\n");
    printf("Voulez-vous convertir de dec->hex (h) ou de dec->bin (b) ?\n");
    
    char c; 
    scanf("%c", &c);

    if ((c != 'b') && (c != 'h')) { // !(c == 'b' && c == 'h')
        printf("Erreur!\n");
        return 1;
    }

    printf("Entrez une valeur décimale: ");
    int value;
    scanf("%d", &value);

    if (c == 'b') {
        printf("Bin value %032b\n", value);
    }
    if (c == 'h') {
        printf("Hex value 0x%08x\n", value);
    }
}
```

Points d'attention:

- Le test `c != 'b' && c != 'h'` signifie «ni `b` ni `h`». Le commentaire
  `!(c == 'b' && c == 'h')` dans le code est **faux** (c ne peut pas valoir les
  deux): la bonne négation (De Morgan) est `!(c == 'b' || c == 'h')`.
- `return 1;` depuis `main` signale une erreur au système (0 = succès).
- Ce programme ne vérifie pas la valeur de retour de `scanf`: voir ci-dessous.

### Toujours tester la valeur de retour de `scanf`

`scanf` retourne le **nombre de conversions réussies** (ou `EOF` si l'entrée
est terminée). Pour une seule conversion `%d`, on attend donc `1`.
**On teste toujours cette valeur** ([scanf2.c](scanf2.c)):

```c
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
```

Si l'utilisateur tape `abc`, `scanf` retourne `0` et `value` garde sa valeur
initiale (`666`). Sans test, on utiliserait une valeur erronée sans le savoir.
Idéalement, après l'erreur, on quitte avec `return 1;` plutôt que de continuer.

### Pièges

- `scanf("%c", &c)` lit **n'importe quel caractère**, y compris l'espace ou le
  retour à la ligne laissé par une saisie précédente. Pour ignorer les blancs
  avant, on écrit `scanf(" %c", &c)` (l'espace dans le format saute tous les
  blancs).
- `%d` saute automatiquement les blancs avant le nombre, mais laisse le `\n`
  final dans le tampon d'entrée.
- En cas d'erreur de conversion, les caractères fautifs restent dans le tampon.

---

## 5. Arguments de la ligne de commande

Une autre manière de recevoir des données est de les passer au lancement du
programme: `./programme arg1 arg2`. Pour cela, `main` prend deux paramètres:

```c
int main(int argc, char* argv[])
```

- `argc` (*argument count*): nombre d'arguments, **nom du programme compris**
  (donc toujours ≥ 1).
- `argv` (*argument vector*): tableau de chaînes de caractères. `argv[0]` est le
  nom du programme, `argv[1]` le premier argument, etc.

### Afficher les arguments ([arguments.c](arguments.c))

```c
#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("Nombre d'arguments: %d\n", argc);

    for (int i = 0; i < argc; i++) {  // i++ === i = i + 1
        printf("%d: %s\n", i, argv[i]);
    }
}
```

```console
$ ./arguments salut "le monde" 42
Nombre d'arguments: 4
0: ./arguments
1: salut
2: le monde
3: 42
```

Les guillemets du shell regroupent «le monde» en un seul argument.

**Tous les arguments sont des chaînes**, même `42`: c'est un `char*` contenant
`'4'` et `'2'`, pas l'entier 42. Il faut donc les convertir.

---

## 6. Convertir une chaîne en entier

### À la main ([atoi.c](atoi.c))

```c
#include <stdio.h>

int main() {
    char s[] = "1234";

    int i = 0;
    i = i + (s[0] - 0x30) * 1000;
    i = i + (s[1] - 0x30) * 100;
    i = i + (s[2] - 0x30) * 10;
    i = i + (s[3] - 0x30) * 1;

    printf("%d\n", i);
    printf("%s\n", s);
}
```

Principe: en ASCII, le caractère `'0'` vaut `0x30` (48), `'1'` vaut `0x31`,
etc. Donc `s[k] - 0x30` (ou mieux `s[k] - '0'`) donne le **chiffre** que
représente le caractère. On multiplie ensuite par la puissance de 10
correspondant à sa position.

Ce code est volontairement figé sur 4 chiffres; on verra comment le généraliser
avec une boucle (méthode de Horner: `i = i * 10 + (s[k] - '0')`).

### Avec la bibliothèque: `atoi`

`atoi` (*ASCII to integer*, dans `<stdlib.h>`) fait ce travail pour une chaîne
de longueur quelconque:

```c
int n = atoi("1234");   // 1234
```

Limite: `atoi` ne permet pas de détecter une erreur (`atoi("abc")` retourne `0`,
comme `atoi("0")`). On lui préférera plus tard `strtol`, qui signale les
erreurs.

### Avec gestion d'erreur: `sscanf`

`sscanf` (*string scanf*) fonctionne comme `scanf`, mais au lieu de lire le
clavier, elle **lit dans une chaîne** déjà en mémoire (ici `argv[1]`). Elle
utilise les mêmes formats (`%d`, `%c`, ...) et, comme `scanf`, retourne le
**nombre de conversions réussies**. C'est ce qui permet de détecter une erreur.

```c
#include <stdio.h>
#include <stdlib.h>

// ./a.out prout
int main(int argc, char* argv[]) {
    if (argc < 2) return 1;

    int x;

    // Bien, mais aucune gestion des erreurs:
    // atoi("prout") retourne 0, indistinguable de atoi("0")
    x = atoi(argv[1]);

    // Très bien: on teste la valeur de retour
    // 1 conversion attendue (%d); si != 1, la chaîne n'est pas un entier
    if (sscanf(argv[1], "%d", &x) != 1) {
        return 1;   // erreur: "prout" n'est pas un nombre
    }

    printf("x = %d\n", x);
}
```

| Appel | `atoi` | `sscanf(..., "%d", &x)` |
|-------|--------|-------------------------|
| `"42"` | `42` | retourne `1`, `x = 42` |
| `"0"` | `0` | retourne `1`, `x = 0` |
| `"prout"` | `0` (erreur invisible) | retourne `0`, `x` inchangé |

Comme pour `scanf`, le `&` est obligatoire: `sscanf` doit pouvoir **écrire**
dans `x`.

---

## 7. Mise en pratique: arguments + conversion ([parameters.c](parameters.c))

Ce programme lit des coordonnées `x y` obligatoires, puis jusqu'à trois valeurs
optionnelles (points par zone) qui ont une **valeur par défaut**:

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int zone_a = 100;
    int zone_b = 50; 
    int zone_c = 10;

    int x, y; 

    if (argc < 3) { printf("Erreur\n"); return 1; }
    x = atoi(argv[1]);
    y = atoi(argv[2]);

    if (argc > 3) { zone_a = atoi(argv[3]); }
    if (argc > 4) { zone_b = atoi(argv[4]); }
    if (argc > 5) { zone_c = atoi(argv[5]); }

    printf("Coordonnées (x,y): (%d, %d)\n", x, y);
    printf("Points par zone A=%d B=%d C=%d\n", zone_a, zone_b, zone_c);
}
```

```console
$ ./parameters 3 4
Coordonnées (x,y): (3, 4)
Points par zone A=100 B=50 C=10
$ ./parameters 3 4 200
Coordonnées (x,y): (3, 4)
Points par zone A=200 B=50 C=10
$ ./parameters 3
Erreur
```

Idées à retenir:

- **Valider `argc`** avant d'accéder à `argv[i]`: lire `argv[2]` quand
  `argc == 2` est un accès hors tableau.
- **Valeurs par défaut**: on initialise avec la valeur par défaut, et on ne
  l'écrase que si l'argument est présent.
- Dans la même veine que le test de `scanf`: on vérifie toujours que l'entrée
  est exploitable avant de s'en servir. Un message d'erreur pourrait aussi
  aller sur `stderr` (`fprintf(stderr, …)`).

---

## Compiler et exécuter

```console
$ gcc -Wall -Wextra -std=c23 printf.c -o printf
$ ./printf
```

`-Wall -Wextra` activent les avertissements (très utiles pour détecter un
format `printf` qui ne correspond pas au type). `-std=c23` est nécessaire pour
`%b` et `0b…` avec les versions récentes de GCC.

## Pour aller plus loin

- [Entrées/sorties console (`stdio`)](https://heig-tin-info.github.io/handbook/course-c/15-fundations/stdio/)
- [Types de données](https://heig-tin-info.github.io/handbook/course-c/15-fundations/datatype/)
- [Opérateurs](https://heig-tin-info.github.io/handbook/course-c/15-fundations/operators/)
- [Syntaxe du langage C](https://heig-tin-info.github.io/handbook/course-c/15-fundations/syntax/)
- [Bibliothèque standard](https://heig-tin-info.github.io/handbook/course-c/35-libraries/standard-library/)
