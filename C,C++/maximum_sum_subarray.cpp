#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 5, 1, 8, 2, 9, 1};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;

    int ans = 0;
    for (int i=0; i<k; i++)
    {
        ans += arr[i];
    }

    int prev_sum = ans;
    int curr_sum;
    for (int i=k; i<n; i++)
    {
        curr_sum = prev_sum - arr[i-k] + arr[i];
        ans = max(ans, curr_sum);
        prev_sum = curr_sum;
    }

    cout<<ans;

    return 0;
}