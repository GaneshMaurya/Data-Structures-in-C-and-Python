#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 1, 1, 1, 2, 3, 5, 6};
    int n = sizeof(arr)/sizeof(int);
    int k = 5;

    int i = 0;
    int j = 0;
    int sum = 0;
    int maxi = 0;

    while (j < n)
    {
        sum = sum + arr[j];

        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            if (j-i+1 > maxi)
            {
                maxi = j-i+1;
            }
            j++;
        }
        else
        {
            while (sum > k)
            {
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
    }

    cout<<maxi;
    
    return 0;
}