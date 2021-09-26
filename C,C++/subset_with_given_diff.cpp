/*
Let sum of subset 1 be s1 and subset 2 with s2
s1 - s2 = diff (given)
s1 + s2=sum of array (logical)
Therefore adding both eq we get :
2s1= diff + sum of array
s1= (diff + sum of array)/2;
Problem reduces to find no of subsets with given sum
*/

#include <bits/stdc++.h>
using namespace std;

int countOfSubsets(int arr[], int diff, int n)
{
    int total = 0;
    for (int i=0; i<n; i++)
    {
        total += arr[i];
    }

    int sum = (diff+total)/2;
    int dp[n+1][sum+1];

    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<sum+1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }

    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j<sum+1; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    int arr[] = {1, 1, 2, 3};
    int n = sizeof(arr)/sizeof(int);
    int diff = 1;

    cout<<countOfSubsets(arr, diff, n);
    
    return 0;
}