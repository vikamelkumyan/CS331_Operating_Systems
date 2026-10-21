#include <stdio.h>

struct Normal {
    char a;
    int b;
    double c;
};

#pragma pack(push, 1)
struct Packed1 {
    char a;
    int b;
    double c;
};
#pragma pack(pop)

#pragma pack(push, 2)
struct Packed2 {
    char a;
    int b;
    double c;
};
#pragma pack(pop)

#pragma pack(push, 4)
struct Packed4 {
    char a;
    int b;
    double c;
};
#pragma pack(pop)

int main()
{
    struct Normal n;
    struct Packed1 p1;
    struct Packed2 p2;
    struct Packed4 p4;

    printf("size of struct Normal: %zu bytes\n", sizeof(n));
    printf("address of struct: %p\n", (void*)&n);
    printf("address of a: %p\n", (void*)&n.a);
    printf("address of b: %p\n", (void*)&n.b);
    printf("address of c: %p\n", (void*)&n.c);

    printf("\n");

    printf("size of struct Packed1: %zu bytes\n", sizeof(p1));
    printf("address of struct: %p\n", (void*)&p1);
    printf("address of a: %p\n", (void*)&p1.a);
    printf("address of b: %p\n", (void*)&p1.b);
    printf("address of c: %p\n", (void*)&p1.c);

    printf("\n");

    printf("size of struct Packed2: %zu bytes\n", sizeof(p2));
    printf("address of struct: %p\n", (void*)&p2);
    printf("address of a: %p\n", (void*)&p2.a);
    printf("address of b: %p\n", (void*)&p2.b);
    printf("address of c: %p\n", (void*)&p2.c);

    printf("\n");

    printf("size of struct Packed4: %zu bytes\n", sizeof(p4));
    printf("address of struct: %p\n", (void*)&p4);
    printf("address of a: %p\n", (void*)&p4.a);
    printf("address of b: %p\n", (void*)&p4.b);
    printf("address of c: %p\n", (void*)&p4.c);

    return 0;
}
