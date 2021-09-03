#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 6, 2, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    int target = 7;

    unordered_map<int, int> m;
    vector<int> v;

    for (int i=0; i<n; i++)
    {
        if (m.find(target-arr[i]) != m.end())
        {
            v.push_back(m[target-arr[i]]);
            v.push_back(i);
        }
        else
        {
            m[arr[i]] = i;
        }
    }

    for (int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}