#include <bits/stdc++.h>
using namespace std;

int maximum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int knapsack(int v[], int w[], int n, int total)
{
    if (total == 0 || n == -1)
    {
        return 0;
    }

    if (w[n-1] > total)
    {
        return knapsack(v, w, n-1, total);
    }
    else
    {
        int a, b;
        a = v[n-1] + knapsack(v, w, n-1, total - w[n-1]);
        b = knapsack(v, w, n-1, total);

        return maximum(a, b);
    }
}

int main()
{
    int v[] = {60, 100, 120};
    int w[] = {10, 20, 30};
    int n = sizeof(v)/sizeof(int);
    int total = 50;

    cout<<knapsack(v, w, n, total);

    return 0;
}