#include <stdio.h>

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;
    int i;

    printf("Original array: ");
    for (i = 0; i < 5; i++)
        printf("%d ", *(p + i));
    printf("\n");

    for (i = 0; i < 5; i++)
        *(p + i) = *(p + i) * 2;

    printf("Via pointer:    ");
    for (i = 0; i < 5; i++)
        printf("%d ", *(p + i));
    printf("\n");

    printf("Via array name: ");
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
