//This program computes the sum of all the digits of the number the user inputs


#include <stdio.h>

int main(int argc, char* argv[])
{

    int number;
    int sum = 0;
    
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    while(number > 0)
    {
    
        sum = sum + (number % 10);
        number = number / 10;
   
    }
   
    printf("Sum of all digits is %d\n", sum);

    return 0;

} 


