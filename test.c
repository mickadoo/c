#include <stdio.h>

int getbits(int x, int pos, int len);
int setbits(int x, int y, int pos, int len);
int invert(int x, int pos, int len);
int rightrotate(int x, int times);

int main()
{
    printf("should be 5: %d\n", getbits(20, 4, 3));
    printf("should be 2: %d\n", getbits(10, 3, 2));
    printf("should be 13: %d\n", setbits(10, 5, 2, 3));
    printf("should be 14: %d\n", setbits(10, 5, 2, 1));
    printf("should be 170: %d\n", setbits(0xAB, 0xAA, 5, 6));
}

int getbits(int x, int pos, int len)
{
    return (x >> pos + 1 - len) & ~(~0 << len);
}

int setbits(int x, int y, int pos, int len)
{
    int mask;
    mask = ~((~(~0 << len)) << (pos + 1 - len ));

    return (x & mask) | (getbits(y, len - 1, len) << (pos +1 - len));
}
