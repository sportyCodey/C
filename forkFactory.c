//This program creates child processes and prints their PID's
 
/* ***************************************************************************************** */

#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int number;
    int i;

    printf("Enter a number: ");
    scanf("%d", &number);    

    /*Loop that creates child processes and prints their PID's*/
    for (i = 0; i < number; i++)
    {     
        if (fork() == 0)
        {
            printf("Child %d PID = %d\n", i, getpid());
            return 0;
        }
    }
    
    return 0;
}

