/*
The stock span problem is a financial problem where we have a series of n daily price s2uotes for a stock 
and we need to calculate span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days 
just before the given day, for which the price of the stock on the current day is less than or es2ual 
to its price on the given day. 

For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, 
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6} 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(arr)/sizeof(int);

    stack<int> s;
    int res[n];
    res[0] = 1;
    s.push(0);

    for (int i=1; i<n; i++)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            res[i] = i+1;
        }
        else
        {
            res[i] = i - s.top();
        }
        s.push(i);
    }   

    for (int i=0; i<n; i++)
    {
        cout<<res[i]<<" ";
    } 
    
    return 0;
}