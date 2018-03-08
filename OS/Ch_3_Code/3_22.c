/***********************************************************************************************************************************************************
This program establishes a shared-memory object between the parent and the child process. The child writes the results from the Collatz function to 
shared-memory and the parent reads from shared-memory and displays the result.
***********************************************************************************************************************************************************/

/* Necessary for others */

#include <stdio.h>
#include <stdlib.h>

/* Necessary for shared memory */

#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

/* Necessary for fork() */

#include <sys/types.h> 
#include <unistd.h>

int Collatz(int n, void *ptr);

int main(int argc, char* argv[])
{
        pid_t pid;

	int input = 0;
	int result = 0;

	const int SIZE = 4096;

	/* name of the shared memory object */
	const char *name = "Drew_Is_Cool";

	int shm_fd;
	void *ptr;
   
        pid = fork();

        if (pid < 0)
        {
                fprintf(stderr, "Fork Failed\n");
                return 1;
        }
        else if (pid == 0)
        {
		printf("Child process\n");	

		shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

		ftruncate(shm_fd, SIZE);

		ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
		if (ptr == MAP_FAILED)
		{
			printf("Map Failed\n");
			return -1;
		}

	      /* Error checking */
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

	      /* Error checking */
		while(input <= 0)
		{
			printf("\nEnter a positive integer!\nTry again from console or run again to input from command line.\n");
			scanf("%d", &input);
		}
		result = Collatz(input, ptr); 
        }
        else
        {
                wait(NULL);
                printf("\nChild complete\n");

		shm_fd = shm_open(name, O_RDONLY, 0666);
		if (shm_fd == -1)
		{
			printf("Shared memory failed\n");
			exit(-1);
		}

		ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
		if (ptr == MAP_FAILED)
		{
			printf("Map failed\n");
			exit(-1);
		}

		printf("%s", ptr);

		shm_unlink(name);
		
		printf("\n\n");
        }
	return 0;
}//end main

int Collatz(int n, void *ptr) 
{
	sprintf(ptr,"%d   ", n);
	ptr += sizeof(n);
	
	if (n == 1) 
		return 1;
	else if (n % 2 == 0)
		return Collatz(n / 2, ptr);
	else
		return Collatz(3 * n + 1, ptr);
}







