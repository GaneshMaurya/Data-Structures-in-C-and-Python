/*Given an array of random numbers, Push all the zero’s of a given array to the end of the array. 
For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. 
The order of all other elements should be same. 
Expected time complexity is O(n) and extra space is O(1).*/

#include <stdio.h>

int main()
{
    int arr[] = {0, 0, 1, 2, 0, 0, 0, 3, 6};
    int n = sizeof(arr)/sizeof(int);

    int count = 0;
    int j = 0;

    for (int i=0; i<n; i++)
    {
        if (arr[i] != 0)
        {
            arr[j] = arr[i];
            j++;
        }
        else
        {
            count++;
        }
    }

    for (int i=n-count; i<n; i++)
    {
        arr[i] = 0;
    }

    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}