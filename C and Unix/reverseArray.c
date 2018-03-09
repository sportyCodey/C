//This program gets ten real numbers from the user and 
//then prints them out in the reverse order.

#include <stdio.h>

int main(int argc, char* argv[])
{
    double array[10];

    printf("Enter ten real numbers: ");

    int i;
    for (i = 0; i < 10; i++)
    {
   
        scanf("%lf", &array[i]); 
    }
    
    printf("Reverse order:\n");
    for (i = 9; i >= 0; i--)
    {
        printf("%5.1f", array[i]);
    }

    return 0;

}
