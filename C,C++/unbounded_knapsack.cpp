/*
Unbounded Knapsack (Repetition of items allowed)

Given a knapsack weight W and a set of n items with certain value vali and weight wti, 
we need to calculate the maximum amount that could make up this quantity exactly. 
This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.
Examples: 

Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
Output : 100
There are many ways to fill knapsack.
1) 2 instances of 50 unit weight item.
2) 100 instances of 1 unit weight item.
3) 1 instance of 50 unit weight item and 50
   instances of 1 unit weight items.
We get maximum value with option 2.

Input : W = 8
       val[] = {10, 40, 50, 70}
       wt[]  = {1, 3, 4, 5}       
Output : 110 
We get maximum value with one unit of
weight 5 and one unit of weight 3.
*/

#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int wt[], int val[], int W, int n)
{
    int dp[n+1][W+1];
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<W+1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j<W+1; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {10, 40, 50, 70};
    int W = 8;
    int n = sizeof(wt)/sizeof(int);

    cout<<unboundedKnapsack(wt, val, W, n);
    
    return 0;
}