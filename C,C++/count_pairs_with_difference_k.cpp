#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;

int main()
{
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr)/sizeof(int);
    int target = 3;

    unordered_map<int, bool> m;

    for (int i=0; i<n; i++)
    {
        m[arr[i]] = true;
    }

    int count = 0;

    for (int i=0; i<n; i++)
    {
        if (arr[i]-target >=0 && m[arr[i]-target])
        {
            count++;
        }
        if (arr[i]+target < INT_MAX && m[arr[i]+target])
        {
            count++;
        }
        m[arr[i]] = false;
    }

    cout<<count;
    
    return 0;
}