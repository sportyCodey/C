//This program counts the lines and characters of a text file

/* ************************************************************************************************************ */

#include<stdio.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    int c;
    int lines = 0;
    int characters = 0;
     
    while ((c = fgetc(file)) != EOF)
    {
        characters++;
        if (c == '\n') 
            lines++;      
    }

    printf("Lines: %d\n", lines);
    printf("Characters: %d\n", characters);

    return 0;
}
