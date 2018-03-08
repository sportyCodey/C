//This program dynamically allocates an array of ints from a size

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[])
{
    int * array;
    int i;
    srand(time(NULL));

    array = (int *)malloc(sizeof(int) * atoi(argv[1]));

    for (i = 0; i < atoi(argv[1]); i++)
    {
        array[i] = rand() % 100;
        printf("array[%d] is %d\n" , i, array[i]);
    }

    free(array);

    return 0;
}
