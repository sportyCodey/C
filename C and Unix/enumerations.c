//This program displays the name of the month

#include<stdio.h>

int main(int argc, char *argv[])
{
    int input;

    enum months
    {
        JANUARY,
        FEBRUARY,
        MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
    };

    printf("Enter a number (0-11) inclusive: ");
    scanf("%d", &input);

    switch(input)
    {
        case JANUARY:
        printf("January\n");
        break;
        
        case FEBRUARY:
        printf("February\n");
        break;

	case MARCH:
	printf("March\n");
        break;

      	case APRIL:
	printf("April\n");
        break;

	case MAY:
	printf("May\n");
        break;

	case JUNE:
	printf("June\n");
        break;

	case JULY:
	printf("July\n");
        break;

	case AUGUST:
	printf("August\n");
        break;

	case SEPTEMBER:
	printf("September\n");
        break;

	case OCTOBER:
	printf("October\n");
        break;

        case NOVEMBER:
	printf("November\n");
        break;

	case DECEMBER:
	printf("December\n");
        break;

        default:
	printf("Invalid option\n");
    }

    return 0;
} 
