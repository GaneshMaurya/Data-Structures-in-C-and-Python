#include <bits/stdc++.h>
using namespace std;

class Y;

class X
{
    int data;
    public:
        void getData(int n)
        {
            data = n;
        }
        friend void Sum(X, Y);
};

class Y
{
    int data;
    public:
        void getData(int n)
        {
            data = n;
        }
        friend void Sum(X, Y);
};

void Sum(X o1, Y o2)
{
    cout<<o1.data+o2.data;
}

int main()
{
    X a;
    a.getData(10);
    
    Y b;
    b.getData(20);

    Sum(a, b);
    
    return 0;
}