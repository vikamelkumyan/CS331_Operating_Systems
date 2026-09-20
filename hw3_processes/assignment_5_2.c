#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int res = fork();

    if (res == 0)
    {
        printf("Child PID: %d\n", getpid());
        exit(0);
    }
    else
    {
        printf("Parent PID: %d\n", getpid());
        wait(NULL);
        sleep(60);
    }

    return 0;
}

