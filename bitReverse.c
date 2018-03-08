//This program gets a number from the user, displays its bits, and 
//reverses the bits

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{

    unsigned char numberInput = 0;
    unsigned char numberInputRead = 0;
    unsigned char numberInputShiftLeft = 0;

    printf("Enter a number: ");
    scanf("%hhu", &numberInput);

    printf("Bits: ");

    int i;
    int sum = 0;  
    for (i = 7; i >= 0; i--)
    { 
        printf("%hhu", (numberInput & (1 << i)) >> i);

        if ((numberInput & (1 << i)) >> i == 1) { 
          sum += pow(2, 7-i);
        }      
    }
    
    printf("\n");

    printf("Reversed:%u \n", sum);

    printf("Bits: ");

    int N;
    int k;
    for (N = 0; N <= 7; N++)
    {
        for (k = 7; k >= 0; k--)
        {
            unsigned char numberInputRead = (numberInput & (1 << N)) >> N;
            unsigned char numberInputShiftLeft =  numberInput << k;
             
        }     

            printf("%hhu", (numberInput & (1 << N)) >> N);
    }


    return 0;

}





