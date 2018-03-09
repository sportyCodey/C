//This program displays a dynamically allocated random string

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generate_string(char **string)
{
    int j;
    int i = (rand() % 10) + 1;    

    *string = (char *)malloc(i * sizeof(char));

    for (j = 0; j < i; j++)
    {
        (*string)[j] = 'A' + (rand() % 26);
//        printf("%c" , (*string)[j]);
    }



}

int main(int argc, char *argv[])
{
    char * string;

    srand(time(NULL));

    printf("Random string: ");

    generate_string(&string);

    printf("%s" , string);
    printf("\n");

    free(string);

    return 0;
}

