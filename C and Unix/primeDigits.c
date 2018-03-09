//This program counts the number of occurences of numbers from a file

/* ****************************************************************************************************** */

#include<stdio.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    int c;
    int array[10]; //array to hold the 9 digits
    int i;
    int total = 0; //calculates the total

    for (i = 0; i < 9; i++)
    {
        array[i] = 0; //sets all the digits to 0
    }

    while ((c = fgetc(file)) != EOF)
    {
        if (c == '0')
        {
            array[0]++;
            total++;
        }
        if (c  == '1')
        {   
            array[1]++;
            total ++;
        }
        if (c == '2')
        {
            array[2]++;
            total++;
        }
        if (c == '3')
        {
            array[3]++;
            total ++;
        }
        if (c == '4') 
        {
            array[4]++;
            total++;
        }
        if (c == '5')
        {
            array[5]++;
            total++;
        }
        if (c == '6')
        {
            array[6]++;
            total ++;
        }
        if (c == '7')
        {
            array[7]++;
            total ++;
        }
        if (c == '8')
        {
            array[8]++;
            total++;
        }
        if (c == '9')
        {
            array[9]++;
            total++;
        }
    }

    printf("0s: %d\n", array[0]);
    printf("1s: %d\n", array[1]);
    printf("2s: %d\n", array[2]);
    printf("3s: %d\n", array[3]);
    printf("4s: %d\n", array[4]);
    printf("5s: %d\n" , array[5]);
    printf("6s: %d\n" , array[6]);
    printf("7s: %d\n", array[7]);
    printf("8s: %d\n", array[8]);
    printf("9s: %d\n", array[9]);
    
    printf("Total: %d\n", total);

    fclose(file);

    return 0;
}
