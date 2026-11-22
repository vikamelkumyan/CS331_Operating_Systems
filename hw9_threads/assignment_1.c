#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg){
        printf("Thread %lu is running\n", pthread_self());
        return NULL;
}

int main(){
        pthread_t thread_1;
        pthread_t thread_2;
        pthread_t thread_3;
        int err;

        err = pthread_create(&thread_1, NULL, thread_function, NULL);
        if (err != 0){
                fprintf(stderr, "pthread_create: %s\n", strerror(err));
                return 1;
        }
        err = pthread_create(&thread_2, NULL, thread_function, NULL);
        if (err != 0){
                fprintf(stderr, "pthread_create: %s\n", strerror(err));
                return 1;
        }
        err = pthread_create(&thread_3, NULL, thread_function, NULL);
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
        err = pthread_join(thread_3, NULL);
        if (err != 0){
                fprintf(stderr, "pthread_join: %s\n", strerror(err));
                return 1;
        }
        return 0;
}
