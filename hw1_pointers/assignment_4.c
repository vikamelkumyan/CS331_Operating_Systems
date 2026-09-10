#include <stdio.h>

int main(void) {
    int num = 7;
    int *ptr = &num;
    int **pptr = &ptr;

    printf("Direct:            num   = %d\n", num);
    printf("One dereference:   *ptr  = %d\n", *ptr);
    printf("Two dereferences: **pptr = %d\n", **pptr);

    printf("\nAddress of num:  %p\n", (void *)&num);
    printf("ptr holds:       %p\n", (void *)ptr);
    printf("*pptr holds:     %p\n", (void *)*pptr);
    printf("Address of ptr:  %p\n", (void *)&ptr);
    printf("pptr holds:      %p\n", (void *)pptr);

    return 0;
}
