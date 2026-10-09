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