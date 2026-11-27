/**
 * Compute collatz sequence with multiple inputs:
 * 
 * Example:
 * 
 * $ ./collatz 12
 * 12 -> 6 -> 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1 (9 steps)\n
 */
#include <stdio.h>

int next_term(int term) {
    return term % 2 == 0 ? term / 2 : term * 3 + 1;
}

void print_sequence(int number) {
    int steps = 0;
    while(number > 1) {
        printf("%d -> ", number);
        number = next_term(number);
        steps++;
    }
    printf("1 (%d step%s)\n", steps, steps > 1 ? "s" : "");
}

void print_usage_and_exit(void) {
    fprintf(stderr, "usage: ./collatz NUMBER ...\n");
    exit(2);
}

int main(int argc, char*argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        int number;
        if (sscanf(argv[arg], "%d", &number) != 1) print_usage_and_exit();
        if (number < 1 || number > 1000) print_usage_and_exit();
        print_sequence(number);
    }
}