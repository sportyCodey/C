//This program resizes a dynamically allocated array

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* ***************************************************************** */

void resize_array(int ** array, int size, int new_size)
{
    int i;
    int *newArray;//variable to copy array

    newArray = (int*)malloc(sizeof(int) * new_size); //copying array using for loop below

    for (i = 0; i < size; i++)
    {
        newArray[i] = (*array)[i];
    }

    for (i = size; i < new_size; i++)
    {
        newArray[i] = rand() % 100;
    }

    printf("\n");

    printf("array (pointing to %p):\n" , newArray);

    for (i = 0; i < new_size; i++)
    {
        printf("array[%d] = %d\n" , i , newArray[i]);
    }    
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int *array;
    int userSize = 0;
    int newUserSize = 0;
    int i;

    printf("Enter size: ");
    scanf("%d" , &userSize);

    array = (int*)malloc(sizeof(int) * userSize);

    printf("array (pointing to %p):\n" , array);

    for (i = 0; i < userSize; i++)
    {
        array[i] = rand() % 100;
        printf("array[%d] = %d\n" , i , array[i]);
    }          

    printf("Enter new size: ");
    scanf("%d" , &newUserSize);

    resize_array(&array, userSize, newUserSize);










    return 0;
}
