#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int knapsack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    
    if (dp[n][W] != 0)
    {
        return dp[n][W];
    }

    if (wt[n-1] <= W)
    {
        dp[n][W] = max((val[n-1] + knapsack(wt, val, W-wt[n-1], n-1)), knapsack(wt, val, W, n-1));
        return dp[n][W];
    }
    else
    {
        dp[n][W] = knapsack(wt, val, W, n-1);
        return dp[n][W];
    }
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {9, 4, 5, 7};
    int W = 10;
    int n = sizeof(wt)/sizeof(int);

    cout<<knapsack(wt, val, W, n);
    
    return 0;
}