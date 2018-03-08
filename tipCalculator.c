//This program calculates a tip

#include <stdio.h>

int main(int argc, char* argv[])
{

    double subtotal;
    double tipRate;
    double tipCalculation;
    double totalCalculation; 

    printf("Enter a subtotal: ");
    scanf("%lf", &subtotal);

    printf("Enter the tip rate: ");
    scanf("%lf", &tipRate);

    tipCalculation = ((tipRate/100) * subtotal);
    totalCalculation = (tipCalculation + subtotal);

    printf("Tip: $%.2f\n", tipCalculation);
    printf("Total: $%.2f\n", totalCalculation);

    return 0;
}
