/*
Find minimum number of coins that make a given value
 
Given a value V, if we want to make change for V cents, 
and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, 
what is the minimum number of coins to make the change? 
If it’s not possible to make change, print -1.

Examples:  

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents
*/

#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int sum, int n)
{
    int dp[n+1][sum+1];
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<sum+1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            if (i == 0)
            {
                dp[i][j] = INT_MAX-1;
            }
        }
    }

    for (int j=1; j<sum+1; j++)
    {
        if (j%coins[0] == 0)
        {
            dp[1][j] = j/coins[0];
        }
        else
        {
            dp[1][j] = INT_MAX-1;
        }
    }

    for (int i=2; i<n+1; i++)
    {
        for (int j=1; j<sum+1; j++)
        {
            if (coins[i-1] <= j)
            {
                dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
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
    int coins[] = {1, 2, 3};
    int sum = 5;
    int n = sizeof(coins)/sizeof(int);

    cout<<minCoins(coins, sum, n);
    
    return 0;
}