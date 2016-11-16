#include <stdio.h>

int getbits(int x, int pos, int len);
int setbits(int x, int y, int pos, int len);
int invert(int x, int pos, int len);
unsigned rightrotate(unsigned  x, int times);
int getmask(int on, int len, int startpos);

int main()
{
    printf("should be 5: %d\n", getbits(20, 4, 3));
    printf("should be 2: %d\n", getbits(10, 3, 2));
    printf("should be 13: %d\n", setbits(10, 5, 2, 3));
    printf("should be 14: %d\n", setbits(10, 5, 2, 1));
    printf("should be 170: %d\n", setbits(0xAB, 0xAA, 5, 6));
    printf("should be 16: %d\n", invert(23, 2, 3));
    printf("should be 28: %d\n", invert(32, 5, 4));
    printf("should be %u %u\n", 1u << 31, rightrotate(1u, 1));
    printf("should be %u %u\n", 1u << 30, rightrotate(1u, 2));
}

/**
 * returns len bits of x starting from pos (counts from right with 0 as first bit)
 */
int getbits(int x, int pos, int len)
{
    return (x >> pos + 1 - len) & ~(~0 << len);
}

/**
 * sets the bits of x starting at pos of length len  with the rightmost bits of y
 */
int setbits(int x, int y, int pos, int len)
{
    return (x & getmask(1, len, pos)) | (getbits(y, len - 1, len) << (pos +1 - len));
}

/*
 * flips the bits of x starting from pos of lenth len
 */
int invert(int x, int pos, int len)
{
    return x ^ getmask(0, len, pos);
}

/**
 * moves n bits from right of x to start, shifts right to replace 0s
 */
unsigned rightrotate(unsigned x, int times)
{
    unsigned leftmost1 = ~((~0u)>>1);

    while (times-- > 0) {
        if (x & 1 == 1) 
            x = (x >> 1) | leftmost1;
        else
            x = (x >> 1);
    }

    return x;
}

/**
 * getmask(1, 2, 3) returns 00001100
 * getmask(0, 3, 4) returns 11100011
 */
int getmask(int on, int len, int startpos)
{
    int mask;

    mask = (~(~0 << len)) << (startpos + 1 - len );

    if (on)
        return ~mask;
    return mask;
}
