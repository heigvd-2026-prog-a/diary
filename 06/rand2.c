#include <stdio.h>
#include <stdlib.h>

int seed = 0;

void srand(int x) { seed = x; }

int rand() { 
    seed = (seed * 1103515245 + 12345) % 0xffffffff;
    return seed;
}

int main() {
    srand(123);

    for (int i = 0; i < 10; i++) {
        printf("%d ", rand() % 100);
    }
    printf("\n");
}