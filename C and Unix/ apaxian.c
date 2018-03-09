//This program compacts a word

#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    char name[250];
    char fill[250];
    int i;
    int j = 0;
    
    scanf("%s" , name);
 
    fill[0] = name[0];
 
    for (i = 1; i < strlen(name); i++)
    {
        if (name[i] != name[i - 1])
        {
            j++;
            fill[j] = name[i];
        }
    }

    fill[j + 1] = '\0';

    printf("%s\n" , fill);

    return 0;

}
