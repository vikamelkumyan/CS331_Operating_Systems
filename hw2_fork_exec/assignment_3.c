#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int res = fork();
	if (res == 0)
	{
		execl("/bin/echo", "echo", "Hello from the child process", NULL);
	}

	wait(NULL);
	printf("Parent process done\n");
	return 0;
}
