#include <stdio.h>
#include <unistd.h>
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
	printf("Parent PID: %d\n", getpid());
	}
	return 0;
}
