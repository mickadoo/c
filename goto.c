#include <stdio.h>

int main()
{
    int c = getchar();

    if (c == 'x')
        goto secret;
    else
        goto error;

secret:
    printf("you found the secret character\n");
    return 0;

error:
    printf("that is not the secret character\n");
    return 0;
}
