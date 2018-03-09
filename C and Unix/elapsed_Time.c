//This program shows the time elapsed given input

#include <stdio.h>

struct time
{
	int hour;
	int minute;
	int second;
};

int main(int argc, char* argv) 
{
	/* Prototype */
	struct time elapsed_Time(struct time time1, struct time time2);

	struct time time1;
	struct time time2;
	struct time elapsed;

	printf("Enter two times in the format hh:mm:ss and press enter\n");
	scanf("%d:%d:%d", &time1.hour, &time1.minute, &time1.second);
	scanf("%d:%d:%d", &time2.hour, &time2. minute, &time2.second);

	if (time1.hour > time2.hour)
		elapsed = elapsed_Time(time1, time2);
	else
		elapsed = elapsed_Time(time2, time1);
	
	printf("The elapsed time is: %.2d:%.2d:%.2d\n", elapsed.hour, elapsed.minute, elapsed.second);
		
	return 0;
}

struct time elapsed_Time(struct time time1, struct time time2)
{
	struct time elapsed;
	
	if (time1.second < time2.second)
	{
		time1.minute -= 1;
		time1.second += 60;
		elapsed.second = time1.second - time2.second;
	}
	else
		elapsed.second = time1.second - time2.second;
	if (time1.minute < time2.minute) 
	{
		time1.hour -= 1;
		time1.minute += 60;
		elapsed.minute = time1.minute - time2.minute;
	}
	else
		elapsed.minute = time1.minute - time2.minute;
	elapsed.hour = time1.hour - time2.hour;

	return elapsed;
}
