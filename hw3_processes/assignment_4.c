#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int res1 = fork();

    if (res1 == 0)
    {
        printf("First child PID: %d\n", getpid());
        exit(1);
    }

    int res2 = fork();

    if (res2 == 0)
    {
        printf("Second child PID: %d\n", getpid());
        exit(2);
    }

    int status1, status2;

    waitpid(res1, &status1, 0);
    waitpid(res2, &status2, 0);

    if (WIFEXITED(status1))
        printf("First child exited normally with status: %d\n", WEXITSTATUS(status1));
    else
        printf("First child exited with an error\n");

    if (WIFEXITED(status2))
        printf("Second child exited normally with status: %d\n", WEXITSTATUS(status2));
    else
        printf("Second child exited with an error\n");

    return 0;
}
