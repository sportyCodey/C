//This program dynamically allocates an array of doubles of a size

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>

/* ******************************************************************** */

void print_array(double * array, int size)
{
    int i;

    array = (double *)malloc(sizeof(double) * size);

    printf("array (%p):\n", array);

    for (i = 0; i < size; i++)
    {
        array[i] = (double)(rand()) / (INT_MAX); //random numbers between 0.0 and 1.0
        printf("array[%d] = %.5f\n" , i, array[i]);
    }        

}

int main(int argc, char *argv[])
{
    srand(time(NULL));    
    double array;
    int userSize;

    printf("Enter size: ");
    scanf("%d", &userSize);

    print_array(&array, userSize);

    return 0;
}
