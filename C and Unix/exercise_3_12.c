//This program prints out the suffix of a file name

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

    char filename[75];
    char first[25];
    char suffix[25];
    int i = 0;
    int j = 0;
    int k = 0;

    printf("Enter a filename: ");
    scanf("%s" , filename);
 
    while (filename[i] != '\0')
    {
        if (ispunct(filename[i]) == 0)
        {
            first[j] = filename[i];
            j++;
            i++;
        }            

        else
        { 
            first[j] = '\0';
            break;
        }

    }

    while (filename[i] != '\0')
    {
        if (ispunct(filename[i]) == 0)
        {  
            suffix[k] = filename[i];
            k++;
            i++;        
        }

        else
        {
            i++;   
        }
        
    }

    printf("Suffix: %s\n" , suffix);


    return 0;

}
