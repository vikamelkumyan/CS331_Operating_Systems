#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, sum = 0;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
        sum += arr[i];
    }

    printf("Sum of the array: %d\n", sum);

    free(arr);
    return 0;
}
