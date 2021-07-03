#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    int arr[] = {13, 7, 6, 12};
    int n = sizeof(arr)/sizeof(int);

    int result[n];
    result[n-1] = -1;

    for (int i=0; i<n; i++)
    {
        while (!s.empty() && arr[s.top()] < arr[i])
        {
            result[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    int x;
    for (int i=0; i<n-1; i++)
    {
        x = result[i];
        if (x == 0)
        {
            result[i] = -1;
        }
        else
        {
            result[i] = arr[i+x];
        }
    }

    for (int i=0; i<n; i++)
    {
        cout<<" "<<result[i];
    }
}