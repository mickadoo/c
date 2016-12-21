#include <stdio.h>

void itoa(int num, char str[]);

int main()
{
    char str[5];
    itoa(45446, str); 
    printf("%s\n", str);

    return 0;
}

void itoa(int num, char str[])
{
    static int pos;

    if (num / 10) 
        itoa(num / 10, str);

    str[pos++] = (num % 10) + '0';
    str[pos+1] = '\0'; // reset array end
}
