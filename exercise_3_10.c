//This program "de-vowels" an input string

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{   
    int i = 0;
    int j = 0;
    char input[80];
    char output[80];
    
    printf("Enter a string: ");
    scanf("%s", input);

    while (input[i] != '\0')
    {
        if (input[i] != 'a'&& input[i] != 'e' && input[i] != 'i' && input[i] != 'o' && input[i] != 'u')
        {
            output[j] = input[i];
            j++;            
        }
      
        i++;
    }
  
    printf("Output: %s\n", output);

    return 0;

}
 


