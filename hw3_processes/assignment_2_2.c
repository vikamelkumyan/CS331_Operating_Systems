#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int res1 = fork();

    if (res1 == 0)
    {
        printf("First child PID: %d\n", getpid());
        return 0;
    }

    int res2 = fork();

    if (res2 == 0)
    {
        printf("Second child PID: %d\n", getpid());
        return 0;
    }

    int status1, status2;

    waitpid(res2, &status2, 0);
    wait(&status1);

    printf("First child exit status: %d\n", WEXITSTATUS(status1));
    printf("Second child exit status: %d\n", WEXITSTATUS(status2));

    printf("Parent PID: %d\n", getpid());

    return 0;
}
