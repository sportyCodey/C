//This program prints certain characters in the command line from user

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    if (argc < 2 || argc > 6) //checks to make sure there are enough arguments
    {
        printf("Too little or too many arguments\n"); //print statement if arguments are not valid
    }
        for (i = 0; i < argc; i++)
        {
            if (argv[i] == argv[0] || argv[i] == argv[2] || argv[i] == argv[4]) //checks if argv is odd or not
            {
                printf("%c " , argv[i][0]); //print the first character
                
            }
 
            else //if argv is even
            {
                printf("%c " , argv[i][1]); //print the second character
                
            }
        }
    
    return 0;

}
