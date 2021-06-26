/*Given an array of integers, update every element with multiplication of previous and next elements with following exceptions. 
a) First element is replaced by multiplication of first and second. 
b) Last element is replaced by multiplication of last and second last.*/

#include <stdio.h>

int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(int);

    int temp1 = arr[0];
    int temp2;

    arr[0] = temp1*arr[1];

    for (int i=0; i<n-2; i++)
    {
        temp2 = arr[i+1];
        arr[i+1] = temp1*arr[i+2];
        temp1 = temp2;
    }

    arr[n-1] = temp1*arr[n-1]; 

    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}