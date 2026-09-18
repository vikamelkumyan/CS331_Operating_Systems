#include <stdio.h>
#include <unistd.h>

int main()
{
	int ret1;
	int ret2;
	int ret3;

	ret1 = fork();

	if (ret1 == -1)
	{
		perror("fork");
		return 1;
	}

	ret2 = fork();

	if (ret2 == -1)
	{
		perror("fork");
		return 1;
	}

	ret3 = fork();

	if (ret3 == -1)
        { 
                perror("fork");
                return 1;
        }
	printf("PID: %d, Parent PID: %d\n", getpid(), getppid());
	sleep(20);
	return 0;
}
