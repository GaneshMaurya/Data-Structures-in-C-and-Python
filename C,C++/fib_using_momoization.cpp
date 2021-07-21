#include <iostream>
#include <map>
using namespace std;

map<int, int> memo;

int fib(int n)
{
    if (memo.find(n) != memo.end())
    {
        return memo[n];
    }

    if (n <= 2)
    {
        memo[n] = 1;
        return 1;
    }

    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int main()
{
    cout<<fib(2)<<endl;
    cout<<fib(3)<<endl;
    cout<<fib(7)<<endl;
    cout<<fib(10)<<endl;
    cout<<fib(30)<<endl;
    
    return 0;
}