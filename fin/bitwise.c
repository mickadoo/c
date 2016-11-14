#include <stdio.h>

void set_on(int pos);
void set_off(int pos);
int is_on(int pos);
void print_b();

int status = 0;

int main(void)
{  
    print_b();
    set_on(0);
    set_on(5);
    print_b();
    set_on(2);
    set_off(5);
    set_off(5);
    print_b();
}

int is_on(int pos)
{
    extern int status;

    return (status & (1<<pos)) != 0;
}

void set_on(int pos)
{
    extern int status;

    status = (status | (1<<pos));
}

void set_off(int pos)
{
    extern int status;

    status = status &(~(1<<pos));
}

void print_b()
{
    extern int status;
    int i;

    for (i = 7; i >=0; i--)
        printf("%d", (status & (1<<i)) != 0);
    printf("\n");
}
