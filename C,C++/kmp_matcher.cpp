#include <iostream>
using namespace std;

void computeLps(string pattern, int m, int* lps)
{
    int len = 0;
    lps[len] = 0;

    int i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string str, string pattern)
{
    int n = str.length();
    int m = pattern.length();

    int lps[m];

    computeLps(pattern, m, lps);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (pattern[j] == str[i])
        {
            j++;
            i++;
        }
        
        if (j == m)
        {
            cout<<"Found at : "<<i-j<<endl;
            j = lps[j-1];
        }
        else if (i < n && pattern[j] != str[i])
        {
            if (j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
}


int main()
{
    string str = "abcdabcdabcdacb";
    string pattern = "dabc";

    KMP(str, pattern);
    
    return 0;
}