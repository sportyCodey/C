//Andrew Hudson

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[])
{
    int numTestCases = 0;
    char string[50];
    char string2[50];
    char compare[50];
    int i = 0;
    int k = 0;
    int j = 0;

    scanf("%d" , &numTestCases);

    for (i = 0; i < numTestCases; i++)
    {
        scanf("%s %s" , string, string2);
        j = 0;
    
        for (k = 0; k < strlen(string); k++)
        {
            if (string[k] != string2[k])
            {
                compare[j] = '*';
                j++;
            }    
            else
            {
                compare[j] = '.';
                j++;
            }
        }  
        compare[j] = '\0';
        printf("\n%s\n%s\n" , string, string2);
        printf("%s\n\n" , compare);

    }
    
    return 0;


}
