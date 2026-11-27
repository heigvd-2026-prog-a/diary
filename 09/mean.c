#include <stdio.h>

double mean(int *values, int size) {
   double sum = 0;
    for (int i = 0; i < size; i++) 
        sum += values[i];
    return sum / size;
}

int main() {
    // Capturer les valeurs
    double n[512];
    int k = 0;
    while(scanf("%lf", &n[k++]) == 1);
    
    printf("Moyenne: %lf\n", mean(n, k));
}

