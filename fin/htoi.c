#include <stdio.h>
#include <stdlib.h>

void strip_leading_chars(char hex_str[]);
int hex2dec(char c);

int main()
{
    char hex_str[] = "0x11F3A";
    int i, result = 0;

    strip_leading_chars(hex_str);

    for (i = 0; hex_str[i] != '\0'; ++i) 
        result = ((result * 16) + hex2dec(hex_str[i]));

    printf("%d\n", result);
}

void strip_leading_chars(char hex_str[])
{
    int i;

    if (hex_str[0] != '0')
       return; 
    if (hex_str[1] != 'x' && hex_str[1] != 'X')
        return;
    
    for (i = 2; hex_str[i] != '\0'; ++i) 
        hex_str[i - 2] = hex_str[i];

    hex_str[i - 2] = '\0'; // new end
}

int hex2dec(char c)
{
    if (c >= 'A' && c <= 'Z')
        c = c + 'a' - 'A'; // to lowercase

    if ((c - '0') >= 0 && (c - '0') <= 9)
        return c - '0'; // if int

    if ((c - 'a') > 15) {
        printf("unexpected char %c\n", c);
        exit(1);
    }

    return c + 10 - 'a';
}
