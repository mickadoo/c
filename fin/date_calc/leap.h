int normal_year[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap_year[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int *days_in_months[2] = {normal_year, leap_year};

short is_leap_year(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 100;
}
