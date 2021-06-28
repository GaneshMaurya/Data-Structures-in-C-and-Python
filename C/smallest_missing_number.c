/*Given a sorted array of n distinct integers where each integer is in the range from 0 to m-1 and m > n. 
Find the smallest number that is missing from the array. */

/*
Input: {0, 1, 2, 6, 9}, n = 5, m = 10 
Output: 3

Input: {4, 5, 10, 11}, n = 4, m = 12 
Output: 0

Input: {0, 1, 2, 3}, n = 4, m = 5 
Output: 4

Input: {0, 1, 2, 3, 4, 5, 6, 7, 10}, n = 9, m = 11 
Output: 8
*/

#include <stdio.h>

int main()
{
    int arr[] = {0, 1, 2, 3};
    int n = sizeof(arr)/sizeof(int);
    int m = 10;

    for (int i=0; i<n; i++)
    {
        if (arr[i] != i)
        {
            printf("%d", i);
            break;
        }
        else if (arr[i] == i && n!=m)
        {
            printf("%d", n);
            break;
        }
    }

    return 0;
}