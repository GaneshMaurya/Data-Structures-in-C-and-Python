/*
Partition problem is to determine whether a given set can be partitioned into two 
subsets such that the sum of elements in both subsets is the same. 

Examples: 

arr[] = {1, 5, 11, 5}
Output: true 
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1, 5, 3}
Output: false 
The array cannot be partitioned into equal sum sets.
*/

#include <bits/stdc++.h>
using namespace std;

bool equalSumSubsetExists(int arr[], int n)
{
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        sum += arr[i];
    }

    if (sum%2 != 0)
    {
        return false;
    }
    else
    {
        sum = sum/2;
        bool dp[n+1][sum+1];

        for (int i=0; i<n+1; i++)
        {
            for (int j=0; j<sum+1; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = false;
                }
                if (j == 0)
                {
                    dp[i][j] = true;
                }
            }
        }

        for (int i=1; i<n+1; i++)
        {
            for (int j=1; j<sum+1; j++)
            {
                if (arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }
}

int main()
{
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr)/sizeof(int);

    if (equalSumSubsetExists(arr, n))
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    
    return 0;
}