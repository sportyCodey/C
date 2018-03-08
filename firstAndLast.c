//This program outputs the first and last letter of a string using pass by reference

#include<stdio.h>
#include<string.h>

void first_last(char *string, char *first, char *last)
{           
    *first = string[0];
    *last = string[strlen(string) - 1];
}

int main(int argc, char *argv[])
{
    char stringInput[50];
    char x;
    char y;  
 
    printf("Enter a string: ");
    scanf("%s" , stringInput);

    first_last(stringInput, &x, &y);

    printf("%c and %c\n" , x , y);

    return 0;
}
