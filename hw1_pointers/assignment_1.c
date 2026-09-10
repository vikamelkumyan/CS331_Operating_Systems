#include <stdio.h>

int main(void) {
    int num = 42;     
    int *ptr = &num;   

    printf("Value of num:              %d\n", num);
    printf("Address of num (&num):     %p\n", (void *)&num);
    printf("Address stored in ptr:     %p\n", (void *)ptr);
    printf("Value through the pointer: %d\n", *ptr);

    *ptr = 100;   

    printf("After *ptr = 100, num is:  %d\n", num);
    return 0;
}

