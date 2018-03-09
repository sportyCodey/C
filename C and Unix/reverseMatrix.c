//This program generates a 10 by 10 2D array of random integers in 
//the range of 0 to 9, displays it, and then displays it in the 
//reverse order

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{  
    int array[10][10];
    srand(time(NULL));

    printf("Matrix:\n");

    int i; 
    int j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            int numbers = rand() % 10; 
            array[i][j] = numbers;
            printf("%d ", array[i][j]);
        }
                
        printf("\n");        

    }

    printf("\nReversed Matrix:\n");    

    for (i = 9; i >= 0; i--)
    {
        for (j = 9; j >= 0; j--)
        {
            printf("%d ", array[i][j]);
        }

    printf("\n");

    }
    
    return 0;

}

