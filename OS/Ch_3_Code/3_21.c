/**********************************************************************************************************************************************************
This program creates a child process that calculates the Collatz 
conjecture. The parent waits on the child.
***********************************************************************************************************************************************************/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int Collatz(int n);

int main(int argc, char* argv[])
{
        pid_t pid;
	int input = 0;
	int result = 0;

        pid = fork();

        if (pid < 0)
        {
                fprintf(stderr, "Fork Failed\n");
                return 1;
        }
        else if (pid == 0)
        {	
		printf("Child process\n\n");

	      /* Error Checking */
		if (argc == 1)
		{
			printf("\n\nYou forgot to enter a number from the command line!\nTry again from console"
                        " or run again to input from command line.\n");
			scanf("%d", &input);	
		}
		else 
		{
			input = atoi(argv[1]);
		}

	      /* Error Cheking */
		while(input <= 0)
		{
			printf("\nEnter a positive integer!\nTry again from console or run again to input from command line.\n");
			scanf("%d", &input);
		}
		printf("\n\n");
		result = Collatz(input);
		printf("\n\n");
        }
        else
        {
                wait(NULL);
                printf("\nChild complete\n");
        }
        return 0;
}//end main

int Collatz(int n) 
{
	printf("%d  ", n);

	if (n == 1)
		return 1;
	else if (n % 2 == 0)
		return Collatz(n / 2);
	else
		return Collatz(3 * n + 1);
}

