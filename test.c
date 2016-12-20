#include <stdio.h>

void test(void);

int main()
{
    test();
    test();
}

void test()
{
    int b = 4;

    printf("%d\n", b);

    for (int i = 0; i < 2; i++) {
        if (2 > 1) {
            static int b = 1;
            printf("%d\n", ++b);
        }
    }

    printf("%d\n", b);
}
