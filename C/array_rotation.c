#include <stdio.h>

void rotatebyone(int arr[], int l)
{
    for (int i=0; i<l-1; i++)
    {
        arr[i] = arr[i+1];
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int l = sizeof(arr)/sizeof(int);
    int k = 2 % l;

    int temp;

    for (int i=0; i<k; i++)
    {
        temp = arr[0];
        rotatebyone(arr, l);
        arr[l-1] = temp;
    }

    for (int i=0; i<l; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}