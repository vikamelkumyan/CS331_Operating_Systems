#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
        int res;
        res = fork();

        if (res == 0)
                execl("/bin/ls", "ls", NULL);

        wait(NULL);
        printf("Parent process done\n");
        return 0;
}
