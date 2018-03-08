/**********************************************************************************************************************************************************
This program creates a child zombie process that lasts for 10 seconds.
***********************************************************************************************************************************************************/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	pid = fork();

	if (pid < 0) 
	{
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0)
	{
		printf("Child process\n");
		execlp("/bin/ls","ls",NULL);
	}
	else 
	{
    	    /* Creates Zombie */
		sleep(10);
		wait(NULL);
		printf("Child complete\n");
	}
	return 0;	
}//end main
