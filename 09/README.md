# Semaine 09/16

- [x] Chaînes de caractères
- [x] Vendredi Labo Test (de rattrappage)

## Chaînes de caractères

Une chaîne de caractère c'est une succession de caractères en mémoire. Chaque caractère
prend 8 bit et est encodé (généralement) avec la table ASCII.

Une chaîne de caractère s'adresse par son premier caractère avec un pointeur vers un 
caractère:

```c
char *s = "toto";
```

### Notation tableau

```c
a[b]    *(a + b)
```

```c
int main() {
    char *s = "salut";
    putchar(s[3]);    //  3[s]
}
```

```c
char s[] = "salut" // (a) La chaîne est modificable
char *s  = "salut" // (b) La chaîne n'est pas modifiable
```

### <string.h>

```c
long int strlen(const char *s) {
    long int count = 0;
    while(*s != '\0') { count++; s++; }
    return count;
}

long int strlen(const char *s); 
```

```c
bool isalpha(char u); // A-Z a-z
bool isdigit(char u); // 0-9 
bool ispunct(char u); // .,;.!?
bool isspace(char u); // ' \n\t\v\f'
```

### Pointer sur à partir de trois avec un *s

```c
char s[] = "abcdefghijklmnopqrstuvwxyz";
char *q = s[3];
puts(q); // defghi...
puts(&s[3]); // defghijk...
```


## Tableaux

On l'a compris une succesion de valeurs en mémoire peut être lue séquentiellement et indexées par une position dans la mémoire par rapport à l'adresse de base

```c
char s[] = "abcdef";
assert(s[2] == 'c');
```

Ici `s` c'est en réalité un tableau de 7 caractères (si on compte la sentielle de fin). On peut faire pareil avec des nombres:

```c
char s[] = {'s', 'a', 'l', 'u', 't', '\0'}; // "salut"
int k[] = {1, 2, 3, 4};
```

Cette notation avec des accolades s'appelle "liste d'initialisation"

En C il y a un opérateur qu'on appelle `sizeof` il retourne la taille connue en bytes par le compilateur au moment de la compilation.

```c
int u;
assert(sizeof(u) == 4) 
```

Si on donne pas la taille d'un tableau parce que on ne l'initialise pas, quelle est sa taille ? 

```c
int u[]; // Erreur ! 
int u[42]; // Taille de 42 entiers == 42 * 4 bytes
```

Toutes les valeurs pas initialisées sont initialisées à 0

```c
int u[10] = {1,2,3,4}; 
int u[10] = {0}; // Initialise la première valeur à 0 et les autres à 0
```

### Itérer sur un tableau 

```c
#define N 10

int u[N] = {1,2,3,4};

for (int i = 0; i < N; i++) {
    printf("%d ", u[i]);
}
```


```c
int u[10] = {1,2,3,4};

for (int i = 0; i < sizeof(u) / sizeof(u[0]); i++) {
    printf("%d ", u[i]);
}
```

### Exercice

On crée un programme qui demande à l'utilisateur des nombres réels (stocké sous forme d'un double)
La saisie se fait nombre après nombre, dès qu'une valeur invalide est entrée la saisie s'arrête.

Le programme affiche la moyenne de ce nombre. 

