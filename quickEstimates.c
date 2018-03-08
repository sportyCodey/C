//This program outputs the number of digits for the estimated work cost

#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int numEstimatedCosts;   
    int estimatedCosts[100];
    int i;
    int digits[100];
 
    printf("Input\n");   
    scanf("%d" , &numEstimatedCosts);

    for (i = 0; i < numEstimatedCosts; i++)
    {
        scanf("%d" , &estimatedCosts[i]);
        digits[i] = 0;
    }

    printf("Output\n");
    
    for (i = 0; i < numEstimatedCosts; i++)
    {
        if (estimatedCosts[i] == 0)
        {
            estimatedCosts[i] = estimatedCosts[i]/10;
            digits[i]++;
        }
        
        else 
        {
            while (estimatedCosts[i] != 0)
            {
            estimatedCosts[i] = estimatedCosts[i]/10;
            digits[i]++;
            }
        }   
        printf("%d\n" , digits[i]);
    }

    return 0;

}
