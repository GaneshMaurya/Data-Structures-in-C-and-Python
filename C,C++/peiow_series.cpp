/*
This series is a mixture of 2 series fail the 
odd terms in this series form a Fibonacci series and 
all the even terms are the prime numbers in ascending order
*/

#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

bool isPrime(int a)
{
    int count = 0;

    for (int i=1; i<=a; i++)
    {
        if (a%i == 0)
        {
            count++;
        }
    }

    if (count == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int prime(int n)
{
    if (n == 0)
    {
        return 2;
    }
    int ans;
    int numPrimes = 0;
    int i = 2;

    while (numPrimes != n)
    {
        if (isPrime(i))
        {
            ans = i;
            numPrimes++;
        }
        i++;
    }

    return ans;
}

int main()
{
    int n = 14;

    if (n%2 == 0)
    {
        cout<<prime(n/2);
    }
    else 
    {
        cout<<fib(n/2);
    }
    
    return 0;
}