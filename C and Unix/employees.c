//This program creates a certain amount of employees

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

/* ********************************************************************************************* */

typedef struct 
{
    char first[10];
    char last[10];
    float salary;
} employee_t;

void init_employee(employee_t *employee)
{
    int i = (rand() % 10) + 1; //first and last can only have 10 letters
    int j;    

    for (j = 0; j < i; j++)
    {
        employee->first[j] = 'A' + (rand() % 26);
        employee->last[j] = 'A' + (rand() % 26);
    }

    employee->first[j] = '\0';
    employee->last[j] = '\0';

    employee->salary = (float) rand() / 1000000;
}

void print_employee(employee_t *employee)
{
    printf("Employee\n");
    printf("\tName: %s, %s\n" , employee->first, employee->last);
    printf("\tSalary: $%.2f\n" , employee->salary);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    employee_t *array = NULL;
    int number = 0;
    int i;
    float total = 0; //adds up all the salaries

    printf("How many employees? ");
    scanf("%d" , &number);

    printf("\n");

    array = (employee_t*)malloc(number * sizeof(employee_t));
    
    for (i = 0; i < number; i++)
    {
        init_employee(&array[i]);
        total+= (&array[i])->salary;
    }
 
    for (i = 0; i < number; i++)
    {
        print_employee(&array[i]);
    }        
  
    printf("\nAverage: $%.2f\n", total/number);

    return 0;
}
