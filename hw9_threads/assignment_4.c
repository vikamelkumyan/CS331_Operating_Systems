#include <stdio.h>
#include <string.h>
#include <pthread.h>

int arr[] = {1, 2, 3, 4, 5};

void *thread_function(void *arg){
        int num = *(int *)arg;
        int square = num * num;
        printf("Square of %d is %d\n", num, square);
        return NULL;
}

int main(void){
        int n = sizeof(arr) / sizeof(arr[0]);
        pthread_t threads[5];
        int i;
        int err;

        for (i = 0; i < n; i++){
                err = pthread_create(&threads[i], NULL, thread_function, &arr[i]);
                if (err != 0){
                        fprintf(stderr, "pthread_create: %s\n", strerror(err));
                        return 1;
                }
        }

        for (i = 0; i < n; i++){
                err = pthread_join(threads[i], NULL);
                if (err != 0){
                        fprintf(stderr, "pthread_join: %s\n", strerror(err));
                        return 1;
                }
        }
        return 0;
}
