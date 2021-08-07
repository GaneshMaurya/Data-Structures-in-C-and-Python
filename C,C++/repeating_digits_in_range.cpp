#include <bits/stdc++.h>
using namespace std;

bool isNotRepeating(int num)
{
    unordered_set<int> s;
    int digits = 0;

    while (num != 0)
    {
        int unit = num%10;

        if (s.find(unit) != s.end())
        {
            return false;
        }

        s.insert(unit);
        num = num/10;
    }

    return true;
}

int repeatingDigits(int l, int r)
{
    int count = 0;

    int i = l;
    while (i != r+1)
    {
        if (isNotRepeating(i))
        {
            count++;
        }
        i++;
    }

    return count;
}


int main()
{
    int l = 101;
    int r = 200;

    cout<<repeatingDigits(l, r);
    
    return 0;
}