/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

Example: 

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.
*/

#include <bits/stdc++.h>
using namespace std;

bool isSubsetPossible(int arr[], int sum, int n)
{
    bool dp[n+1][sum+1];

    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<sum+1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j == 0)
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

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr)/sizeof(int);

    if (isSubsetPossible(arr, sum, n) == true)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }

    return 0;
}