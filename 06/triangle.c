#include <stdio.h>

int main(int argc, char*argv[]) {
    if (argc < 2) {
        printf("Usage: ./triangle {width}\n");
        return 1;
    }

    int rows = 0;
    if (sscanf(argv[1], "%d", &rows) != 1) {
        printf("Error: invalid number\n");
        return 2;
    }

    if (rows > 0) {
        for (int i = 1; i <= rows; i++) {
            for (int j = 0; j < i; j++)
                printf("*");
            printf("\n");
        }
    } else {
        rows = -rows;
        for (int row = 1; row <= rows; row++) {
            for (int k = 0; k < rows - row; k++) printf(" "); 
            for (int k = 0; k < row; k++) printf("*"); 
            puts("");
        }        
    }
}