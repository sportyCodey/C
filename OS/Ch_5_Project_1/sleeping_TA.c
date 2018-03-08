/**********************************************************************************************************************************************************
This program uses POSIX threads, mutex locks, and semaphores to implement a solution that coordinates the activities of the TA and the students to 
solve the sleeping assistant problem
**********************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

/* random number generator for sleep function (generates numbers between 1-4) */
void randomNumber(int *random);

/* ta thread will begin control in this function */
void *ta_Help();

/* students threads will begin control in this function. Student "seeks" help from TA */ 
void *student_Seek(void *student);

/* constant for number of chairs */
#define NUM_OF_CHAIRS 3

/* global variable for number of students chosen by user */
int num_Of_Students = 0;

/* global variable to keep count of the student threads that ended */
int s_end = 0;

/* global boolean variable to end the program */
int going_Home  = 0;

/* global variable to keep count of number of students TA has helped. Ends student threads */
int end = 0;

/* global boolean variable to determine if the chairs are full */
int limit = 0;

/* global array variable to see who the TA is helping */
int teaching[NUM_OF_CHAIRS] = {0, 0, 0};

/* global variable to keep count of the number of students who are waiting for the TA */
int waiting = 0;

/* data type for mutex locks. Global so it can reach scope of functions */
pthread_mutex_t mutex;

/* semaphore data type for students. Global so it can reach scope of functions */
sem_t s_Student;

/* semaphore data type for TA. Global so it can reach scope of functions */
sem_t s_ta;

int main(int argc, char* argv[])
{
	srand(time(NULL));
	int i;

	printf("Enter the number of students: ");
	scanf("%d", &num_Of_Students);

	if (num_Of_Students <= 0)
	{
		fprintf(stderr, "Your input, %d ,must be > 0.\n", num_Of_Students);
		return -1;
	}

	printf("\n");

	/* Unique ID for each student thread */
	int ID[num_Of_Students];

	/* array of threads for students */
	pthread_t students[num_Of_Students];

	/* thread for TA */
	pthread_t ta;

	/* set of thread attributes */
	pthread_attr_t attr;

	/* create the mutex lock */
	pthread_mutex_init(&mutex, NULL);

	/* create the student semaphore and initialize it to 0 */
	sem_init(&s_Student, 0, 0);

	/* create the TA semaphore and initialize it to 1 */
	sem_init(&s_ta, 0, 1);

	/* get the default attributes */
	pthread_attr_init(&attr);

	printf("These students need the TA:\n\n");

	/* create the student threads and fill student ID's */
	for (i = 0; i < num_Of_Students; i++)
	{
		/* i + 1 here so it won't print a zero for any student */
		ID[i] = i + 1;
		pthread_create(&students[i], &attr, student_Seek, &ID[i]);
	}

	/* create the TA thread */
	/* no arguument passed into ta_Help function */
	pthread_create(&ta, &attr, ta_Help, NULL);

	/* wait for the student threads to exit */
	for (i = 0; i < num_Of_Students; i++)
	{
		pthread_join(students[i], NULL);
	}

	/* wait for the TA thread to exit */
	pthread_join(ta, NULL);

	/* message displayed after all threads exit */
	printf("\nAll the students are now gone. The TA is going home to sleep.\n\n");

	return 0;

}//end main

void randomNumber(int *random)
{
	*random = rand() % 4 + 1;
}

void *ta_Help()
{
	int random = 0;
	int i;
	
	/* the index of the student waiting */
	int index = 0;

	/* used for swapping */
	int temp = 0;

	do
	{
		/* aquire the semaphore */
		sem_wait(&s_Student);

		/* acquire the mutex lock */
		pthread_mutex_lock(&mutex);

		/* critical section */
		
		/* find the index of first student waiting in the array (chairs) */
		for (i = 0; i < NUM_OF_CHAIRS; i++)
		{
			if (teaching[i] != 0)
			{
				index = i;
				break;
			}
		}

		printf("\nTA is helping student %d.\n\n", teaching[index]);
	
		/* time it takes to help student */	
		randomNumber(&random);
		sleep(random);

		printf("Student %d is leaving.\n\n", teaching[index]);

		/* one chair is now open */
		waiting--;

		/* reset this index in array (chair is now empty) */
		teaching[index] = 0;
		index = 0;

		/* must check if limit is full or not */
		if (waiting < 4)
			limit = 0;
		else
			limit = 1;
	
		/* next two if statement rearrange the order of the students in the chairs to make sure no student is going to indefinite block */
		/* ex. student waiting in chair 3 gets moved to chair 1 ASAP */
		/* ex. this is needed if student in chair 3 is going next but a new student thread enters the array (chairs) making that new student 
		a higher priority, which should not happen because it can lead to indefinite blocking on student waiting in chair 3 */ 
		if (teaching[0] == 0 && teaching[1] != 0)
		{
			temp = teaching[0];
			teaching[0] = teaching[1];
			teaching[1] = temp;
		}

		if (teaching[1] == 0 && teaching[2] != 0)
		{
			temp = teaching[1];
			teaching[1] = teaching[2];
			teaching[2] = temp;
		}

		/* release the mutex lock */
		pthread_mutex_unlock(&mutex);

		/* release the semaphore */
		sem_post(&s_ta);

		/* increment the terminating variable */
		end++;

	/* TA will continue to help until the students all leave (signaled by them all leaving the do while loop in student_Seek function) */
	} while(going_Home == 0);

	pthread_exit(0);
}

void *student_Seek(void *student)
{
	int random = 0;
	int i;

	/* determines when a newline should happen after the next print message. This is just to make things look nicer */
	static int n_Count = 0;

	/* Explicit conversion to int since student receives argument of type void* */
	int s_num = *(int *)student;

	/* message letting us know how many students there are to be seen by TA */
	printf("Student %d needs the TA.\n", s_num);
	n_Count++;

	if (n_Count == num_Of_Students)
		printf("\n");
	
	do
	{
		/* time it takes for student to program */
		randomNumber(&random);
		sleep(random);

		/* acquire the mutex lock */
		pthread_mutex_lock(&mutex);

		/* checks if the chairs are full */
		if (waiting == 3)
			limit = 1;
		
		/* if chairs are not full */
		if (!limit)
		{
			/* one more chair is full */
			waiting++;
	
			/* critical section */

			teaching[waiting - 1] = s_num;

			/* prints the students waiting in the chairs */
			printf("Student %d just arrived.\n", teaching[waiting - 1]);
			for (i = 0; i < NUM_OF_CHAIRS; i++)
			{
				if (teaching[i] == 0)
					printf("Chair #%d is empty\n", i + 1);
				else
					printf("Chair #%d is filled with student %d\n", i + 1, teaching[i]);
			}
			printf("\n");
			
			/* prints how many students are waiting */
			if (waiting == 1)
				printf("There is %d student waiting.\n\n", waiting);
			else
				printf("There are %d students waiting.\n\n", waiting);
	
			/* release the mutex lock */	
			pthread_mutex_unlock(&mutex);

			/* release the semaphore */		
			sem_post(&s_Student);

			/* acquire the semaphore */
			sem_wait(&s_ta);
	
		}

		/* if the chairs are full */
		else
		{
			printf("Student %d is leaving. No more chairs left\n", s_num);
		
			/* release the mutex lock */
			pthread_mutex_unlock(&mutex);
		}
	  /* end < 3 because it gives the program an appropriate amount of time to execute before terminating */
	} while(end < 3);
	
	/* keeps count of every thread that comes out of the do while loop */
	s_end++;

	/* if all the threads are out of the do while loop, the going_Home flag will be turned to true */
	if (s_end == num_Of_Students)
		going_Home = 1;
	
	pthread_exit(0);
}








