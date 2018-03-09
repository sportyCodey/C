//This program prints a file to the console and calculates the average

/* ************************************************************************************************************************ */

#include<stdio.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    char a[50];
    char b[50];
    float c;
    int number = 0; //keeps count of the number of salaries
    double total = 0; //adds up the salaries

    while (fscanf(file, "%s %s %f\n",  a, b, &c) != EOF)
    {   
        printf("%s %s %f\n", a, b, c);
        total += c;
        number++;  
    } 

    printf("Average is $%.2f\n", total/number);

    fclose(file);   
 
    return 0;
}
