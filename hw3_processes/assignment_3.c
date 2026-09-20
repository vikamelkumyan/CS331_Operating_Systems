#include <stdio.h>
#include <stdlib.h>

void first()
{
    printf("First cleanup function\n");
}

void second()
{
    printf("Second cleanup function\n");
}

int main()
{
    atexit(first);
    atexit(second);
    printf("Main function\n");
    exit(0);
}
