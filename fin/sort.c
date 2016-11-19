#include <stdio.h>

#define MAX_COUNT 10
#define ASC 0
#define DESC 1
#define LF 0x0A

int compare(int a, int b);
void read(int numbers[]);

int strategy = ASC;

/**
 * very basic program to read and sort single digit integers
 */
int main()
{
    int numbers[MAX_COUNT];
    int i = 0, temp;

    read(numbers);
    printf("\n");

    while (numbers[0] != '\0') {
        for (i = 0; numbers[i+1] != '\0'; i++) {
            if (compare(numbers[i], numbers[i+1])) {
                temp = numbers[i+1];
                numbers[i+1] = numbers[i];
                numbers[i] = temp;
             }
        }
        printf("%d ", numbers[i]);
        numbers[i] = '\0';
    }

    printf("\n");
    return 0;
}

int compare(int a, int b) 
{
    extern int strategy;

    switch (strategy) {
        case ASC:
            return a < b;
        case DESC:
            return a > b;
    }
}

void read(int numbers[])
{
    int i = 0, c;

    while(i < MAX_COUNT && (c = getchar()) != EOF) {

        if (c == LF)
            continue;

        numbers[i] = c - '0';
        i++;
    }

    numbers[i] = '\0';
}


