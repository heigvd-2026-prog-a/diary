# Semaine 03/16

## Qu'est-ce qu'un programme

Comme expliqué dans le [cours](https://heig-tin-info.github.io/handbook/), un programme est un ensemble d’instructions qui sont exécutées par un ordinateur. Ces instructions sont écrites dans un langage de programmation, comme le langage C que nous utilisons dans ce cours.

Un programme exécuté (processus) se compose d'entrées sorties comme montré [ici](https://heig-tin-info.github.io/handbook/course-c/25-architecture-and-systems/programs-and-processes/?h=programm#entrees-sorties)

- Une entrée standard (STDIN) qui est généralement le clavier
- Une sortie standard (STDOUT) qui est généralement l’écran
- Une sortie d’erreur standard (STDERR) qui est également généralement l’écran
- Un status de sortie (EXIT STATUS) qui est un code numérique retourné par le programme à la fin de son exécution. Un code de sortie de 0 indique que le programme s’est terminé avec succès, tandis qu’un code différent de 0 indique qu’une erreur s’est produite.
- Des arguments de ligne de commande (COMMAND LINE ARGUMENTS) qui sont des paramètres passés au programme lors de son exécution. Ces arguments sont accessibles dans le programme via les variables `argc` et `argv`.
- Des variables d'environnement (ENVIRONMENT VARIABLES) qui sont des paires clé-valeur accessibles par le programme. Ces variables sont définies par le système d’exploitation et peuvent être utilisées pour configurer le comportement du programme.

## Numération

Le chapitre sur la [numération](https://heig-tin-info.github.io/handbook/course-c/10-numeration/) explique les différents systèmes de numération et comment ils sont utilisés en informatique. Dans ce cours on utilisera principalement:

- Le système décimal (base 10)
- Le système binaire (base 2)
- Le système hexadécimal (base 16)
- Le système octal (base 8)

On se rappelle que la conversion de binaire vers hexadécimal ou octal est facile, car 2^4 = 16 et 2^3 = 8. Il est donc possible de regrouper les bits par 4 pour convertir en hexadécimal et par 3 pour convertir en octal.

## Complément à 1

Le complément à 1 est une méthode de représentation des nombres négatifs en binaire. Pour obtenir le complément à 1 d’un nombre binaire, il suffit d’inverser tous les bits du nombre. Par exemple, le complément à 1 de `1010` est `0101`.

Il est l'équivalent en base 10 du complément à 9. Pour obtenir le complément à 9 d’un nombre décimal, il suffit de soustraire chaque chiffre du nombre de 9. Par exemple, le complément à 9 de `1234` est `8765`.

## Complément à 2

Le [complément à 2](https://heig-tin-info.github.io/handbook/course-c/10-numeration/) est une méthode pour représenter les nombres négatifs en binaire. Il est obtenu en prenant le complément à 1 d’un nombre binaire et en ajoutant 1 au résultat. Par exemple, pour obtenir le complément à 2 de `1010`, on prend d’abord le complément à 1 qui est `0101`, puis on ajoute 1 pour obtenir `0110`.

## IEEE 754

Il s'agit d'une norme pour la représentation des [nombres à virgule flottante](https://heig-tin-info.github.io/handbook/course-c/10-numeration/) en binaire. Elle définit comment les nombres réels sont représentés en mémoire, ainsi que les opérations arithmétiques qui peuvent être effectuées sur ces nombres. La norme IEEE 754 est largement utilisée dans les ordinateurs et les langages de programmation pour garantir la précision et la cohérence des calculs en virgule flottante.
