#include <iostream>
using namespace std;

class A
{
    int a;

public:
    void setData(int a)
    {
        this->a = a;
    }
    void printData()
    {
        cout << "A = " << a << "\n";
    }
};

int main()
{
    A obj;
    obj.setData(1);
    obj.printData();

    return 0;
}