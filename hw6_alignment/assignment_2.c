#include <stdio.h>

struct Original {
    char a;
    int b;
    double c;
};

struct Reordered {
    double c;
    int b;
    char a;
};

struct BadOrder {
    char a;
    double c;
    int b;
};

int main()
{
    struct Original o;
    struct Reordered r;
    struct BadOrder x;

    printf("size of struct Original: %zu bytes\n", sizeof(o));
    printf("address of struct: %p\n", (void*)&o);
    printf("address of a: %p\n", (void*)&o.a);
    printf("address of b: %p\n", (void*)&o.b);
    printf("address of c: %p\n", (void*)&o.c);

    printf("\n");

    printf("size of struct Reordered: %zu bytes\n", sizeof(r));
    printf("address of struct: %p\n", (void*)&r);
    printf("address of c: %p\n", (void*)&r.c);
    printf("address of b: %p\n", (void*)&r.b);
    printf("address of a: %p\n", (void*)&r.a);

    printf("\n");

    printf("size of struct BadOrder: %zu bytes\n", sizeof(x));
    printf("address of struct: %p\n", (void*)&x);
    printf("address of a: %p\n", (void*)&x.a);
    printf("address of c: %p\n", (void*)&x.c);
    printf("address of b: %p\n", (void*)&x.b);

    return 0;
}
