#include <stdio.h>

int main() {
    char s[] = "1234";

    int i = 0;
    i = i + (s[0] - 0x30) * 1000;
    i = i + (s[1] - 0x30) * 100;
    i = i + (s[2] - 0x30) * 10;
    i = i + (s[3] - 0x30) * 1;

    printf("%d\n", i);
    printf("%s\n", s);
}