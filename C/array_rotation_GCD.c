#include <stdio.h>

int GCD(int l, int k)
{
    if (k == 0)
    {
        return l;
    }
    else 
    {
        return GCD(k, l%k);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int l = sizeof(arr)/sizeof(int);
    int d = 2 % l;
    int gcd = GCD(l, d);
    int temp, j, k;

    for (int i=0; i<gcd; i++)
    {
        temp = arr[i];
        j = i;

        while(1)
        {
            k = j + d;
            if (k >= l)
            {
                k = k-l;
            }
            if (k == i)
            {
                break;
            }
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }

    for (int i=0; i<l; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}