//This program prints a random color

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/* *********************************************************** */

typedef struct color
{
    unsigned short int red;
    unsigned short int green;
    unsigned short int  blue;
} color_t; 

void init_color(color_t *color)
{
    color->red = rand() % 255;
    color->green = rand() % 255;
    color->blue = rand() % 255;
}

void print_color(color_t *color)
{
    printf("(red: %d, green: %d, blue: %d)\n" , color->red, color->green, color->blue);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    color_t  *mainColor = NULL; //variable to put array in
    int i;

    mainColor = (color_t*)malloc(1 * sizeof(color_t)); //array to print colors

    for (i = 0; i < 1; i++)
    {
        init_color(&mainColor[i]);
    }

    for (i = 0; i < 1; i++)
    {
        print_color(&mainColor[i]);
    }

    return 0;
}
