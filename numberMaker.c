//This program writes numbers to a specified file
/* **************************************************************************************************************** */

#include<stdio.h>

int main(int argc, char *argv[])
{ 
    FILE *file = fopen(argv[4], "w");    
    int i;
    int count = 0;

/* Variable to keep count of intervals */
    int step = atoi(argv[1]);

    for (i = atoi(argv[1]); i < atoi(argv[2]); i++)
    {
        /* This makes sure the first number is displayed */
        if (i == atoi(argv[1]))
        {
            fprintf(file, "%4d" , i);
        }
        else
        {      
            step = step + atoi(argv[3]);

            if (step > atoi(argv[2]))
                break;

            if (count % 10 == 0 && count != 0)
                fprintf(file, "\n");    

            fprintf(file, "%4d" , step); 
        }    
        count++;
    }

    fclose(file);

    return 0;
}
