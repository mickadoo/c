#include <stdio.h>

#define LOWER   0
#define UPPER   300
#define STEP    20

float fahr2celc(float);

/* print Fahrenheit-celcius table for fahr = 0,20, ... 300 */
int main()
{
    float fahr;

    printf("%3s\t%6s\n", "F", "C");

    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%3.0f\t%6.1f\n", fahr, fahr2celc(fahr));
    }
}

float fahr2celc(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}
