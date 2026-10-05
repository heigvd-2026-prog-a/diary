#include <stdio.h>

int main() {
    int i = 42;
    long j = 1234567;
    float f = 3.14159;

    printf("i: %7d, j: %ld, f: %f\n", i, j, f);

    printf("i: %7d, ", i);
    printf("j: %ld, ", j);
    printf("f: %f\n", f);

    printf("%8d\n", 12);
    printf("%08d\n", 102);
    printf("%8d\n", 1200);
    printf("%8d\n", 9876004);
    printf("-----\n");

    printf("%8f\n", 3.1415926535);
    printf("%8.2f\n", 30.1415926535);

    printf("%.10f\n", 0.123456789f);
    printf("%.10f\n", 1.123456789f);
    printf("%.10f\n", 12.123456789f);
    printf("%.10f\n", 123.123456789f);
    printf("%.10f\n", 1234.123456789f);
    printf("%.10f\n", 1234567890.123456789f);

    printf("%08.3f\n", 12.123456789f);


    int foo = 12345;
    printf("%d\n", foo);
    printf("%032b\n", foo);
    printf("%08x\n", foo);


}
