#include <stdio.h>
#include <string.h>
#include <pthread.h>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

struct range {
        int start;
        int end;
};

void *thread_function(void *arg){
        struct range *r = arg;
        int sum = 0;
        int i;

        for (i = r->start; i < r->end; i++){
                sum += arr[i];
        }
        printf("Thread %lu: sum of indices %d to %d is %d\n",
               pthread_self(), r->start, r->end - 1, sum);
        return NULL;
}

int main(void){
        pthread_t thread_1, thread_2;
        int n = sizeof(arr) / sizeof(arr[0]);
        struct range r1 = {0, n / 2};
        struct range r2 = {n / 2, n};
        int err;

        err = pthread_create(&thread_1, NULL, thread_function, &r1);
        if (err != 0){
                fprintf(stderr, "pthread_create: %s\n", strerror(err));
                return 1;
        }
        err = pthread_create(&thread_2, NULL, thread_function, &r2);
        if (err != 0){
                fprintf(stderr, "pthread_create: %s\n", strerror(err));
                return 1;
        }

        err = pthread_join(thread_1, NULL);
        if (err != 0){
                fprintf(stderr, "pthread_join: %s\n", strerror(err));
                return 1;
        }
        err = pthread_join(thread_2, NULL);
        if (err != 0){
                fprintf(stderr, "pthread_join: %s\n", strerror(err));
                return 1;
        }
        return 0;
}
