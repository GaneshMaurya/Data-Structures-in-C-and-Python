#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int array[] = {1, 2, 4, 2, 1, 3, 2, 4, 3};
    int n = sizeof(array)/sizeof(int);
    unordered_set<int> s;
    
    for (int i=0; i<n; i++)
    {
        s.insert(array[i]);
    }

    unordered_set<int>:: iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        cout<<*itr<<" ";
    }
    
    return 0;
}