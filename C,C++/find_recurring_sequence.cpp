#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 22;
    int den = 11;


    map<int, int> m;
    string result = "";

    int rem = num%den;
    int index = 0;

    while (rem != 0 && (m.find(rem) == m.end()))
    {
        m[rem] = index;
        index++;

        rem = rem*10;
        result += to_string(rem/den);

        rem = rem%den;
    }

    if (rem == 0)
    {
        cout<<num/den;
    }
    else
    {
        cout<<result;
    }

    return 0;
}