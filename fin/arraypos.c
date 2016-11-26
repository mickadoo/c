#include <stdio.h>

int count(int list[]);
int arraypos(int target, int list[]);

int main()
{
    int list[6] = {2, 44, 56, 94, 134, 139};

    printf("%d\n", arraypos(94, list));
}

int arraypos(int target, int list[])
{
    int min = 0, max = count(list), mid = 0;

    while (min <= max && list[mid] != target) {
        mid = (min + max) / 2;
        if (target > list[mid])
            min = mid + 1;
        else
            max = mid - 1;
    }

    return list[mid] == target ? mid :-1;
}

int count(int list[])
{
    int i = 0;

    while (list[i] != '\0')
        i++;

    return i;
}
