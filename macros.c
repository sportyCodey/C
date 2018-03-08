//This program converts celsius to fahrenheit and vice verse

#include<stdio.h>

int main(int argc, char *argv[])
{
    float number;

    #define CELSIUS_TO_FAHRENHEIT(number) (((number) * 9/5) + 32)
    #define FAHRENHEIT_TO_CELSIUS(number) ((number - 32) * 5/9)

    printf("Enter a number: ");
    scanf("%f", &number);

    printf("%.1f F in C is: %.1f\n", number, FAHRENHEIT_TO_CELSIUS(number));
    printf("%.1f C in F is: %.1f\n", number, CELSIUS_TO_FAHRENHEIT(number));

    return 0;
}
