#include <stdio.h>

struct date 
{
	int month;
	int day;
	int year;
	int N;
};

int main(int arc, char* argv)
{	
	int calculateN(struct date d);

	int result = 0;

	struct date date1;
	struct date date2;

	printf("Enter two dates in the format 00/00/0000:\n");
	scanf("%d/%d/%d", &date1.month, &date1.day, &date1.year);
	scanf("%d/%d/%d", &date2.month, &date2.day, &date2.year);

	date1.N = calculateN(date1);
	date2.N = calculateN(date2);

	if (date1.N > date2.N)
		result = date1.N - date2.N;
	else
		result = date2.N - date1.N;

	printf("The elapsed days are: %d\n", result);

	return 0;
}

int calculateN(struct date d)
{
	int N = 0;

	if (d.month <= 2)
	{
		d.year -= 1;
		d.month += 13;
	}
	else
		d.month += 1;
	
	N = (1461 * d.year) / 4 + (153 * d.month) / 5 + d.day;

	return N;
}
