#include <stdio.h>

int Sum(int array[], int n)
{   
    int sum;
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        sum = Sum(array, n-1) + array[n-1];
        return sum;
    }
}

int main()
{
    int array[] = {1, 2, 5, 3, 7, 8, 10};
    int n = sizeof(array)/sizeof(int);

    int sum = Sum(array, n);

    printf("%d", sum);
    
    return 0;
}