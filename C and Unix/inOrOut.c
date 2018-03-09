//This program tells the user if the point is in the rectangle or not
/* ************************************************************************ */

#include<stdio.h>

typedef struct 
{
    double x;
    double y;
} point_t;

typedef struct
{
    float height;
    float width;
    point_t upper_left_corner;
} rectangle_t;

int is_in(point_t *point , rectangle_t *rectangle)
{
    if (point->x > rectangle->upper_left_corner.x && point->y > rectangle->upper_left_corner.y && point->x <
       rectangle->width + rectangle->upper_left_corner.x && point->y < rectangle->height + rectangle->upper_left_corner.y)
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[])
{
    point_t pointValue; //variable to hold point_t
    rectangle_t rectangleValue; //variable to hold rectangle_t

    double pointX, pointY, pointX2, pointY2 = 0;
    float rectangleWidth, rectangleHeight, x, y = 0;

    printf("Enter a point (x and y): ");
    scanf("%lf %lf" , &pointX, &pointY);

    printf("Enter a rectangle (x, y, width, and height): ");
    scanf("%lf %lf %f %f" , &pointX2 , &pointY2 , &rectangleWidth, &rectangleHeight);

    pointValue.x = pointX; //copying user x and y values
    pointValue.y = pointY;

    rectangleValue.upper_left_corner.x = pointX2; //copying rectangle x and y values
    rectangleValue.upper_left_corner.y = pointY2;

    rectangleValue.width = rectangleWidth; //copying copying rectangle height and width
    rectangleValue.height = rectangleHeight;

    if(is_in(&pointValue ,&rectangleValue) == 1)
    {
        printf("Point is inside the rectangle\n");
    }

    else
    {
        printf("Point is outside the rectangle\n"); 
    }

    return 0;
}
