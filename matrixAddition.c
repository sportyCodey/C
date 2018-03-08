//This program add up two dynamically allocated matrices

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[])
{
    int ** row;
    int ** column;
    int i;
    int j;
    int theRow = atoi(argv[1]);
    int theColumn = atoi(argv[2]);
    srand(time(NULL));

    row = (int **)malloc(sizeof(int *) * theRow);

    for (i = 0; i < theRow; i++) 
    {
        row[i] = (int *)malloc(sizeof(int) * theColumn);
    }

    for (i = 0; i < theRow; i++)
    {
        for (j = 0; j < theColumn; j++)
        {
            row[i][j] = rand() % 10;
        }
    }

    column = (int **)malloc(sizeof(int*) * theRow);

    for (i = 0; i < theRow; i++)
    {
        column[i] = (int *)malloc(sizeof(int) * theColumn);
    }

    for (i = 0; i < theRow; i++)
    {
        for (j = 0; j < theColumn; j++)
        {
            column[i][j] = rand() % 10;
            
        }
    } 

    for (i = 0; i < theRow; i++)
    {
        for (j = 0; j < theColumn; j++)
        {
            printf("%d " , row[i][j]);
	    if (j == theColumn - 1)
	        printf("\n");      
        }
    }

    printf("\n");
    printf("+ \n\n");

    for (i = 0; i < theRow; i++)
    {
        for (j = 0; j < theColumn; j++)
        {
            printf("%d " , column[i][j]);
            if (j == theColumn - 1)
                printf("\n");
        }
    }

    printf("\n");
    printf("= \n\n");

    for (i = 0; i < theRow; i++)
    {
        for (j = 0; j < theColumn; j++)
        {
            printf("%d " , row[i][j] + column[i][j]);
            if (j == theColumn - 1)
                printf("\n");
        }
    }

    free(row);
    free(column);    

    return 0;
}
