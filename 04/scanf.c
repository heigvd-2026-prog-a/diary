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