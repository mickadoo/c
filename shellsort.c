#include <stdio.h>

void shellsort(int list[], int n);
int getcount(int list[]);

int main()
{
    int list[11] = {4,7,33,23,66,8,32,12,2455,434,232};
    int i;

    printf("\n");
    shellsort(list, 11);

    for (i = 0; i < 11; i++)
        printf("%d ", list[i]);

    printf("\n");
    return 0;

}

    
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
           for (j = i-gap; j>=0 && v[j] > v[j+gap]; j-=gap) {
               temp = v[j];
               v[j] = v[j+gap];
               v[j+gap] = temp;
           }
}
