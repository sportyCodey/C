//This program concatenates two arrays

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/* *********************************************************************************** */

void concat_array(int **array1, int *size1, int *array2, int size2)
{
    int j;
    int i, k = 0;
    int *newArray1;
    
    array2 = (int*)malloc(sizeof(int) * size2);

    printf("array2 (%p):\n" , array2);

    for (j = 0; j < size2; j++)
    { 
        array2[j] = rand() % 100;
        printf("array[%d] = %d\n" , j , array2[j]);
    }

    printf("\n");

    newArray1 = (int*)malloc(sizeof(int) * (*size1 + size2)); //holds both arrays

    printf("array1 (%p):\n" , newArray1);

    for (j = 0; j < *size1; j++)
    {
        newArray1[j] = (*array1)[j];
    }
    
    for (j = *size1; j < *size1 + size2; j++)
    {
        newArray1[j] = array2[k];
        k++;
    }

    for (j = 0; j < (*size1 + size2); j++)
    {
        printf("array[%d] = %d\n" , j , newArray1[j]);
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int *array1;
    int array2;
    int size1;
    int size2;
    int i;

    printf("Enter array1 size: ");
    scanf("%d" , &size1);

    array1 = (int*)malloc(sizeof(int) * size1);

    printf("array1 (%p):\n" , array1);

    for (i = 0; i < size1; i++)
    {
        array1[i] = rand() % 100;
        printf("array[%d] = %d\n" , i , array1[i]);
    }

    printf("\n");

    printf("Enter array2 size: ");
    scanf("%d" , &size2);    

    concat_array(&array1, &size1, &array2, size2);

    return 0;
}
