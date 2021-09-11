#include <iostream>
using namespace std;

class Base1
{
    int data1;

public:
    Base1(int a)
    {
        data1 = a;
        cout << "Base1 class constructor called\n";
    }
    void printDataBase1()
    {
        cout << "Data-1 = " << data1 << "\n";
    }
};

class Base2
{
    int data2;

public:
    Base2(int a)
    {
        data2 = a;
        cout << "Base2 class constructor called\n";
    }
    void printDataBase2()
    {
        cout << "Data-2 = " << data2 << "\n";
    }
};

class Derived : public Base2, public Base1
{
    int derived1, derived2;

public:
    Derived(int a, int b, int c, int d) : Base2(a), Base1(b)
    {
        derived1 = c;
        derived2 = d;
        cout << "Derived class constructor called\n";
    }
    void printDataDerived()
    {
        cout << "Derived-1 = " << derived1 << "\n";
        cout << "Derived-2 = " << derived2 << "\n";
    }
};

int main()
{
    Derived d(1, 2, 3, 4);
    d.printDataBase1();
    d.printDataBase2();
    d.printDataDerived();

    return 0;
}