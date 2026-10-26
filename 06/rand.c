#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N = 42;
    printf("%ld\n", time(NULL));
    srand(1793019029);
    //srand(time(NULL));
    int random_number = rand() % N + 1;
    printf("%d\n", random_number);
}