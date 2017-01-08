#include <stdlib.h>
#include <stdio.h>
#include "leap.h"
 
#define USAGE "arguments: year yearday"

int * get_month_and_day (int year, int day_of_year);

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("%s\n", USAGE);
        return 1;
    }

    int year = atoi(argv[1]);
    int yearday = atoi(argv[2]);
    int *result;
    result = get_month_and_day(year, yearday);

    printf("%d %d\n", result[0], result[1]);
    return 0;
}

/**
 * returns array with month number as first element, day of month as second
 */
int * get_month_and_day (int year, int day_of_year)
{
    short is_leap = is_leap_year(year);
    int month;
    static int result[2];

    for (month = 0; day_of_year > days_in_months[is_leap][month]; month++) {
        day_of_year -= days_in_months[is_leap][month];      
    }

    result[0] = month + 1;
    result[1] = day_of_year; // after all months have been subtracted

    return result;
}
