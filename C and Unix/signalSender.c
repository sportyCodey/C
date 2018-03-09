//This program sends a signal to the child

/* **************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>

int running;

void j(int signum)
{
    printf("Child process received signal: SIGHUP\n");
   
    running = 0;
}
void k(int signum)
{
    printf("Child process received signal: SIGINT\n");
   
    running = 0;
}
void l(int signum)
{
    printf("Child process received signal: SIGFPE\n");
   
    running = 0;
}
void m(int signum)
{
    printf("Child process received signal: SIGSEGV\n");
   
    running = 0;
}
void n(int signum)
{
    printf("Child process received signal: SIGTERM\n");
   
    running = 0;
}

int main(int argc, char *argv[])
{
    int number;
    int i;
    int t;

    i = fork();

    /*Child process*/
    if (i == 0)
    {
        signal(SIGHUP, j);
        signal(SIGINT, k);
        signal(SIGFPE, l);
        signal(SIGSEGV, m);
        signal(SIGTERM, n);
        printf("Child process created!\n");
        running = 1;

        while (running == 1)
        {
            sleep(1);
        }
    }

    /*Parent process*/
    else 
    {
        while (1)
        {
            sleep(1);
	    printf("Enter the number for the signal you want to send.\n");    
    	    printf("\tSIGHUP\t1\n\tSIGINT\t2\n\tSIGFPE\t8\n\tSIGSEGV\t11\n\tSIGTERM\t15\n");
    	    printf("Number: ");
    	    scanf("%d", &number);

    	    if (number == 1)
	    {
                kill(i, SIGHUP);
	    }
	    if (number == 2)
	    {
	        kill(i, SIGINT);
	    }
	    if (number == 8)
	    {
		kill(i, SIGFPE);
	    }
	    if (number == 11)
	    {
		kill(i, SIGSEGV);
	    }
	    if (number == 15)
	    {
		kill(i, SIGTERM);
	    }
	    
 	    t = wait();
	    printf("All done!\n");
	    break;
        }
    }

    return 0;
}
