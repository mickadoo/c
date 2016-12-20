#include <stdio.h>

void qsort(int v[], int left, int right);
void printv(int v[]);

int main()
{
    int v[] = {4, 6, 8, 9, 1, 2, 3, 5, '\0'};
    qsort(v, 0, 7);
    printv(v);
}

void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return; // do nothing if array contains less than 2 elements
    
    // move partition element to v[0]
    
    printf("moving partition element %d to start\n", v[(left + right) / 2]);
    swap(v, left, (left + right) / 2); 
    last = left; 

    printv(v);
    printf("doing partition\n");
    
    // do partition
    for (i = left+1; i <= right; i++)
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }

    printv(v);

    printf("restoring partition element\n");
    swap(v, left, last); // restore partition element

    printv(v);

    // do recursive for two partitions
    printf("doing recursive sort from %d to %d\n", left, last - 1);
    qsort(v, left, last - 1);
    printf("doing recursive sort from %d to %d\n", last + 1, right);
    qsort(v, last+1, right);
}

void swap(int v[], int i, int j)
{
    printf("swapping %d and %d\n", v[i], v[j]);
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void printv(int v[])
{
    for (int i = 0; v[i] != '\0'; ++i)
        printf("%d ", v[i]);

    printf("\n");
}
