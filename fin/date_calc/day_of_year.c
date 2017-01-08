#include <stdlib.h>
#include <stdio.h>
#include "leap.h"

#define USAGE "arguments: YYYY mm dd"

int get_day_of_year(int year, int month, int day);
short is_leap_year(int year);

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("%s\n", USAGE);
        return 1;
    }

    int year = atoi(argv[1]);
    int month = atoi(argv[2]);
    int day = atoi(argv[3]);

    printf("%d\n", get_day_of_year(year, month, day));
    return 0;
}

int get_day_of_year(int year, int month, int day)
{
    int num_days = day;
    short is_leap = is_leap_year(year);

    while (--month > 0)
        num_days += days_in_months[is_leap][month - 1];

    return num_days;
}

