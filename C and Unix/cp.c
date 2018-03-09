//This program copies text from one file to another

/* ****************************************************************************************************** */

#include<stdio.h>

int main(int argc, char *argv[])
{
    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "w");
    int c;

    while ((c = fgetc(file1)) != EOF)
    {
        fprintf(file2,"%c", c);    
    }

    return 0;
}
