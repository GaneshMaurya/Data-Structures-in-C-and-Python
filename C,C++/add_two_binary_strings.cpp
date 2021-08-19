#include <bits/stdc++.h>
using namespace std;

int main()
{
    string num1 = "11";
    string num2 = "1";

    string res = "";
    int s = 0;
    int i = num1.size()-1;
    int j = num2.size()-1;

    while (i >= 0 || j >= 0 || s == 1)
    {
        s += ((i >= 0)? num1[i] -'0' : 0);
        s += ((j >= 0)? num2[j] -'0' : 0);

        res = char(s%2 + '0') + res;
        s = s/2;

        i--;
        j--;
    }

    cout<<res;
    
    return 0;
}