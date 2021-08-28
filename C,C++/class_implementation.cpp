#include <bits/stdc++.h>
using namespace std;

class item
{
    int number;
    float cost;
    static int count;

    public:
        void getData(int a, float b);
        void putData()
        {
            cout<<number<<"\n";
            cout<<cost<<"\n";
        }
        void showCount()
        {
            cout<<count<<"\n";
        }
};

int item::count;

void item::getData(int a, float b)
{
    number = a;
    cost = b;
    count++;
}


int main()
{
    item x;
    x.getData(20, 4.5);
    x.putData();

    x.showCount();
    
    return 0;
}