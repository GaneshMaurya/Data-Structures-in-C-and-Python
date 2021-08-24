#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    string arr[] = {"bite", "tail", "iron", "whip"};
    string attack = "aaaaironirontailbitewhipbiteaaaatailaaaairontailbitewhipbiteaaaatailaaaairontailbitewhip";
    int i = 0;
    int k = 16;
    string temp;

    while (i < attack.length())
    {
        temp = attack.substr(i, k);
        int count = 0;

        while (count < n)
        {
            for (int i=0; i<n; i++)
            {
                size_t found = temp.find(arr[i]);

                if (found != string::npos)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            break;
        }
        
        if (count == n)
        {
            break;
        }
        i++;
    }

    cout<<i;
    
    return 0;
}