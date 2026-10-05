#include <stdio.h>
#include <stdlib.h>

void freeAll(char **strings, int count) {
    for (int i = 0; i < count; i++)
        free(strings[i]);
    free(strings);
}

int main(void) {
    char **strings = malloc(3 * sizeof(char *));
    if (strings == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter 3 strings: ");
    for (int i = 0; i < 3; i++) {
        strings[i] = malloc(51); 
        if (strings[i] == NULL) {
            printf("Memory allocation failed.\n");
            freeAll(strings, i);
            return 1;
        }
        if (scanf("%50s", strings[i]) != 1) {
            printf("Invalid input.\n");
            freeAll(strings, i + 1);
            return 1;
        }
    }

    printf("Strings: ");
    for (int i = 0; i < 3; i++)
        printf("%s ", strings[i]);
    printf("\n");

    char **tmp = realloc(strings, 5 * sizeof(char *));
    if (tmp == NULL) {
        printf("Memory reallocation failed.\n");
        freeAll(strings, 3);
        return 1;
    }
    strings = tmp;

    printf("Enter 2 more strings: ");
    for (int i = 3; i < 5; i++) {
        strings[i] = malloc(51);
        if (strings[i] == NULL) {
            printf("Memory allocation failed.\n");
            freeAll(strings, i);
            return 1;
        }
        if (scanf("%50s", strings[i]) != 1) {
            printf("Invalid input.\n");
            freeAll(strings, i + 1);
            return 1;
        }
    }

    printf("All strings: ");
    for (int i = 0; i < 5; i++)
        printf("%s ", strings[i]);
    printf("\n");

    freeAll(strings, 5);
    return 0;
}

