#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int res = fork();
	if (res == 0)
	{
		execl("/usr/bin/grep", "grep", "main", "test.txt", NULL);
	}

	wait(NULL);
	printf("Parent process completed\n");

	return 0;
}
