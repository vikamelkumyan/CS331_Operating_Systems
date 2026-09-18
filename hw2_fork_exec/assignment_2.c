#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int  res_1 = fork();
	if (res_1 == 0)
	{	printf("in the first child\n");
		execl("/bin/ls", "ls", NULL);
	}
	wait(NULL);

	int res_2 = fork();
	if (res_2 == 0)
	{	printf("in the second child\n");
		execl("/bin/date", "date", NULL);
	}	
	wait(NULL);
	printf("Parent process done\n");

	return 0;
}
