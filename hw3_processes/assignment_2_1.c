#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int res = fork();
	if (res ==-1)
	{
	        perror("fork");
	        return 1;
	}
	else if (res == 0)
	{
	    printf("Child PID: %d\n", getpid());
	}
	else
	{
	wait(NULL);
	printf("Parent PID: %d\n", getpid());
	}
	return 0;
}
