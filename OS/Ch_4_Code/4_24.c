/**********************************************************************************************************************************************************
This program creates a separate thread that outputs all prime numbers less than or equal to the number entered by the user. 
***********************************************************************************************************************************************************/

#include <pthread.h>
#include <stdio.h>

void *primeNumber(void *n);

int main(int argc, char* argv[])
{
	pthread_t tid;
	pthread_attr_t attr;

	/* Error Checking */
	if (argc != 2)
	{
		fprintf(stderr, "usage: a.out <integer value>\n");
		return -1;
	}

	/* Error Checking */
	if (atoi(argv[1]) < 0)
	{
		fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
		return -1;
	}	

	else
	{

		pthread_attr_init(&attr);
		pthread_create(&tid, &attr, primeNumber, argv[1]);
		pthread_join(tid, NULL);
	}

}//end main

/*The thread will begin control in this function */
void *primeNumber(void *n)
{
	int i, k;
	int primeCount, lineCount = 0;

	printf("\n\n");

	for (i = 2; i <= atoi(n); i++)
	{
		for (k = 2; k <= i; k++)
		{
			if (i % k == 0)
				primeCount++;
		}
		if (primeCount == 1)
		{
			printf("%5d", i);
			lineCount++;
			if (lineCount % 10 == 0)
				printf("\n");
		}
		primeCount = 0;
	} 

	printf("\n\n");

	pthread_exit(0);
}
