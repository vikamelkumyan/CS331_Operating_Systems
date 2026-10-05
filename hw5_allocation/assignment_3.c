#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr = malloc(10 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter 10 integers: ");
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    int *tmp = realloc(arr, 5 * sizeof(int));
    if (tmp == NULL) {
        printf("Memory reallocation failed.\n");
        free(arr);
        return 1;
    }
    arr = tmp;

    printf("Array after resizing: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}

