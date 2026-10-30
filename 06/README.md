# Semaine 06/16

- [ ] Structures de contrôle
  - [.] if / else
  - [.] if / else if / else
  - [.] switch / case
  - [.] while
  - [.] for
  - [.] do / while
  - [.] break 
  - [.] goto

## Choix 

```c
if ( /* condition */ ) { /* code si vrai */ }
if ( /* condition */ ) { /* code si vrai */ } else { /* code si faux */ }

bool a = true; 
bool b = false;

if ( a ) 
{ 
    if ( b ) 
    { 
        printf("true");
    } 
}

if ( a && b ) 
{ 
  printf("true");
}


if ( /* condition */ ) { 
    /* code si vrai */ 
} 
else if ( /* condition */ ) { 
    /* code si vrai */ 
} 
else { 
    /* code si faux */ 
}



```

## Boucles

```c
// GOTO a éviter
int i = 0;
loop: 
/*code*/;
i++;
if (i < 10) goto loop;

// Boucle for
// On l'utilise si on connaît a priori le nombre d'exécution
for (int i = 0; i < 10; i++) { /*code*/ }

// Boucle while
int i = 0;
while (i < 10) { /*code*/; i++; }

// Boucle Do While
int i = 0;
do { /*code*/; i++; } while ( i < 10 )

```

## Exercice : deviner un nombre

Réaliser un programme qui se comporte comme suit:

```bash
$ ./guess 100
J'ai choisi un nombre entre 1 et 100 quel est-il ?
> 50
C'est plus grand !
> 75
C'est plus petit !
> 63
C'est plus grand !
> 69
Bravo ! Vous avez trouvé le nombre 69 en 4 essais.
```

> Pour générer une valeur aléatoire entre 1 et N utilisez la fonction `rand()` de la bibliothèque standard C. N'oubliez pas d'initialiser le générateur de nombres aléatoires avec `srand(time(NULL))` pour obtenir des résultats différents à chaque exécution.
>
> ```c
> #include <stdlib.h>
> #include <time.h>
>
> int main() {
>     srand(time(NULL));
>     int random_number = rand() % N + 1;
>     ...
> }
> ```

## Exercice : Triangle 

### Première partie : triangle simple

Écrire un programme qui dessine un triangle rectangle de hauteur et de largeur N où N est donné en argument. 

```bash
./triangle 5
*
**
***
****
*****
```

### Deuxième partie : mirroir horizontal

Si la valeur transmise est négative, on aligne le triangle à droite:

```bash
./triangle -5
    *
   **
  ***
 ****
*****
```
