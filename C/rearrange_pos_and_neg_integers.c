/*An array contains both positive and negative numbers in random order. 
Rearrange the array elements so that positive and negative numbers are placed alternatively. 
Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. 
If there are more negative numbers, they too appear in the end of the array.
For example, if the input array is [-1, 2, -3, 4, 5, 6, -7, 8, 9], then the output should be [9, -7, 8, -3, 5, -1, 2, 4, 6]
Note: The partition process changes relative order of elements. 
I.e. the order of the appearance of elements is not maintained with this approach. 
See this for maintaining order of appearance of elements in this problem.
The solution is to first separate positive and negative numbers using partition process of QuickSort. 
In the partition process, consider 0 as value of pivot element so that all negative numbers are placed before positive numbers. 
Once negative and positive numbers are separated, we start from the first negative number and first
 positive number and swap every alternate negative number with next positive number. */

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[] = {-1, 2, -3, 4, -5, 6, -7, 8, -9};
    int n = sizeof(arr)/sizeof(int);

    int pivot = 0;
    int p = 0;

    for (int i=0; i<n; i++)
    {
        if (arr[i] < pivot)
        {
            swap(&arr[p], &arr[i]);
            p++;
        }
    }

    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    int neg = 0;
    int pos = p;

    while(pos < n && neg < pos && arr[neg] < 0)
    {
        swap(&arr[neg], &arr[pos]);
        pos++;
        neg+=2;
    }

    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}