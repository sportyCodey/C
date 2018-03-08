//This program creates my own version of ls

#include<stdio.h>
#include<dirent.h>

/* *********************************************************************************************** */

int main(int argc, char *argv[])
{
    DIR *directory;
    struct dirent *entry;

    /* If the argument count is 1 then open current directory
       since hitting enter is an argument */
    if (argc == 1)
    {
        directory = opendir(".");
    }
    else
    {
        directory = opendir(argv[1]);
    }

    while (1)
    {
        entry = readdir(directory);

        if (entry == NULL)
        {
            break;
        }

        printf("%s\n", entry->d_name);
    }

    return 0;
}
