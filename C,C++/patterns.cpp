#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;

    for (int row = 1; row <= 2*n-1; row++)
    {
        int numOfColumns = row > n ? 2*n-row : row;
        int numOfSpaces = n - numOfColumns;
        for (int s = 1; s <= numOfSpaces; s++)
        {
            cout<<" ";
        }

        for (int col = 1; col <= numOfColumns; col++)
        {
            cout<<"* ";
        }
        cout<<"\n";
    }
    
    return 0;
}