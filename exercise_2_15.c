//This program lets the user manipulate bits individually 

#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned int startingBit;
    int command;
    int bitPosition;        

    printf("Number: 0\n");

    printf("Bits: ");

    int i;
    for (i = 31; i >= 0; i--)
    {
        printf("%u", (startingBit & (1 << i)) >> i);
    }
 
    printf("\n");

    
    while(command != 0) {
      printf("Enter a command (1 = set, 2 = clear, 0 = exit): ");
      scanf("%d", &command);

      if (command == 1) {
        printf("Enter a bit position: ");
        scanf("%d", &bitPosition);
        printf("\n");

        startingBit = (startingBit & (1 <<  bitPosition)) >>  bitPosition;
        startingBit = startingBit | (1 << bitPosition);

        printf("Number: %d\n", startingBit);
        printf("Bits: ");
        for (bitPosition = 31; bitPosition >= 0; bitPosition--)
        {
            printf("%u", (startingBit & (1 << bitPosition)) >> bitPosition);
        }

        printf("\n");

      }

      else if (command == 2) {
        printf("Enter a bit position: ");
        scanf("%d", &bitPosition);
        printf("\n");

        startingBit = (startingBit & (1 << bitPosition)) >> bitPosition;
        startingBit = startingBit & (~(1 << bitPosition));

        printf("Number: %d\n", startingBit);
        printf("Bits: ");

        for (bitPosition = 31; bitPosition >= 0; bitPosition--)
        {
            printf("%u", (startingBit & (1 << bitPosition)) >> bitPosition);
        }

        printf("\n");
      }        
      
      else {
      }
  
    }//end while loop

    return 0;


}

    
