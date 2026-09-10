#include <stdio.h>

int main(void) {
    char str[] = "Hello";
    char *p = str;
    int count = 0;

    printf("The string is: ");
    while (*p != '\0') {
        putchar(*p);
        p++;
    }
    printf("\n");

    p = str;
    while (*p != '\0') {
        count++;
        p++;
    }
    printf("Length (by counting): %d\n", count);

    p = str;
    while (*p) p++;
    printf("Length (by pointer subtraction): %ld\n", (long)(p - str));

    printf("Bytes the array occupies: %ld\n", (long)sizeof(str));

    return 0;
}
