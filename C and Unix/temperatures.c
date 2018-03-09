//This program converts Celsius to Fahrenheit from a starting and 
//stopping degree from the user

#include <stdio.h>

double funct(double conversion);

int main(int argc, char* argv[])
{
    double startDegree = 0;
    double stopDegree = 0;
    double conversion = 0;

    printf("Enter start degree: ");
    scanf("%lf", &startDegree);

    printf("Enter stop degree: ");
    scanf("%lf", &stopDegree);

    double i;
    printf("\nCelsius\tFahrenheit");
    for (i = startDegree; i <= stopDegree; i++)
    {            
        printf("\n%5.1f\t%5.1f", i, funct(i));
    } 
 
    return 0;

}  

double funct(double conversion)
{
    return (9 * conversion / 5) + 32;
}
