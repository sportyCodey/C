//This program splits an input string into two output strings

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char name[50], first[25], last[25];
    int i = 0;
    int j = 0;
    int k = 0;

    printf("What is your name? ");
    scanf("%s", name);

    while (name[i] != '\0')
    {
        if (isupper(name[i]) && i == 0)
        {
            first[j] = name[i];
            j++;
            i++;
        }        

        else if (isupper(name[i]) == 0)
        {
            first[j] = name[i];
            j++;
            i++;
        }
       
        else 
        {
            first[j] = '\0';
            break;
        }
    
    }   

    while (name[i] != '\0')
    {
        last[k] = name[i];
        k++;
        i++;
    }

    printf("First Name: %s\n" , first);
  
    printf("Last Name: %s\n" , last);
        
    return 0;

}
