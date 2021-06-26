/*Given an array A of n elements, sort the array according to the following relations :  

A[i] >= A[i-1]           
 

, if i is even.  

A[i] <= A[i-1]           
 

, if i is odd. 
Print the resultant array.*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[] = {1, 2, 2, 1};
    int n = sizeof(arr)/sizeof(int);

    for (int i=1; i<n; i++)
    {
        if ((i+1)%2 == 0)
        {
            if (arr[i] <= arr[i-1])
            {
                swap(&arr[i], &arr[i-1]);
            }
        }
        else
        {
            if (arr[i] >= arr[i-1])
            {
                swap(&arr[i], &arr[i-1]);
            }
        }
    }   

    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    } 
    
    return 0;
}