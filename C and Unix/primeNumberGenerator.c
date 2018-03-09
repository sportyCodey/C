//This program generates prime numbers based on how many prime 
//numbers the user wants

#include <stdio.h>

int main(int argc, char* argv[])
{

     int number = 0;
     int displayedSoFar = 0;
     int currentNumber = 2;
     int isPrime = 1;

     printf("Enter the number of prime numbers to be found: ");
     scanf("%d", &number);
      
     while(displayedSoFar < number)
     {
      
          isPrime = 1;
           
          int i; 
          for (i = 2; i < currentNumber; i++)
          {

               if (currentNumber % i == 0)
               {           
                    isPrime = 0;
               }
          }

          if (isPrime == 1)
          {
               printf("%5d ", currentNumber);
               displayedSoFar++;
               if (displayedSoFar % 10 == 0)
               {
                   printf("\n");
               }
          }

          currentNumber++;      

     }

     return 0;

}
