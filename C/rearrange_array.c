/*Given an array of elements of length N, ranging from 0 to N – 1. 
All elements may not be present in the array. If the element is not present then there will be -1 present in the array. 
Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int array[] = {19, 7, 0, 3, 18, 15, 12, 6, 1, -12, 11, -11, 9, 5, 13, 20, 2, 14, 24, 4};
    int n = sizeof(array)/sizeof(int);

    for (int i=0; i<n;)
    {
        if (array[i] >= 0 && array[i] < n && array[i] != i)
        {
            swap(&array[i], &array[array[i]]);
        }
        else
        {
            i++;
        }
    }

    for (int i=0; i<n; i++)
    {
        if (array[i] != i)
        {
            array[i] = -1;
        }
    }

    for (int i=0; i<n; i++)
    {
        printf("%d ", array[i]);
    }
    
    return 0;
}