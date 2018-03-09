//This program prints a matrix with random asterisks in them

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* ****************************************************************** */

void print_matrix(char ** matrix, int height, int width)
{
    int i;
    int j;
    int counter = 0;
    srand(time(NULL));
    int k =  height * width * 0.1;

    printf("Asterick Count: %d\n" , k);

    matrix = (char**)malloc(sizeof(char*) * height);

    for (i = 0; i < height; i++)
    {
       matrix[i] = (char*)malloc(sizeof(char) * width);
    }

    for (i = 0; i < height; i++) //puts dots in matrix
    {
        for (j = 0; j < width; j++)
        {
            matrix[i][j] = '.'; 
        }  
    }

    while (counter < k) //puts random astericks in the matrix
    {
        int rand1 = rand() % height;
        int rand2 = rand() % width;
    
        if (matrix[rand1][rand2] == '*')
        {
            int r1 = rand() % height;
            int r2 = rand() % width;
 
            matrix[r1][r2] = '*';
        }
        else
        {
            matrix[rand1][rand2] = '*';
        }
        counter++;
    }

    printf("array (%p):\n " , matrix);
        
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            printf("%2c" , matrix[i][j]);
        }
        printf("\n");
    } 
}

int main(int argc, char * argv[])
{
    char * matrix;
    int height;
    int width;

    printf("Enter height: ");
    scanf("%d" , &height);

    printf("Enter width: ");
    scanf("%d" , &width);

    print_matrix(&matrix, height, width);

    return 0;
}
