#include <iostream>
#include <vector>
#include <map>
using namespace std;

// int gridTraveller(int m, int n)
// {
//     if (m == 1 && n == 1)
//     {
//         return 1;
//     }

//     if (m == 0 || n == 0)
//     {
//         return  0;
//     }

//     return (gridTraveller(m-1, n) + gridTraveller(m, n-1));
// }

map<string, long long int> memo;

long long int gridTraveller(int m, int n)
{
    char c1 = m + '0';
    char c2 = n + '0';
    auto key = std::string(1, c1)+','+c2;

    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }
    if (m == 1 && n == 1)
    {
        return 1;
    }
    if (m == 0 || n == 0)
    {
        return 0;
    }

    memo[key] = gridTraveller(m-1, n) + gridTraveller(m, n-1);
    return memo[key];
}

int main()
{
    cout<<gridTraveller(2, 3)<<endl;
    cout<<gridTraveller(5, 5)<<endl;
    
    return 0;
}