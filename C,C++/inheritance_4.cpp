#include <iostream>
using namespace std;

class Base1
{
protected:
    int base1int;

public:
    void getBase1int(int a)
    {
        base1int = a;
    }
};

class Base2
{
protected:
    int base2int;

public:
    void getBase2int(int a)
    {
        base2int = a;
    }
};

class Base3
{
protected:
    int base3int;

public:
    void getBase3int(int a)
    {
        base3int = a;
    }
};

class Derived : public Base1, public Base2, public Base3
{
public:
    void show()
    {
        cout<<"Base-1 integer : "<<base1int<<"\n";
        cout<<"Base-2 integer : "<<base2int<<"\n";
        cout<<"Base-3 integer : "<<base3int<<"\n";
        cout<<"Sum : "<<base1int+base2int+base3int<<"\n";
    }
};

int main()
{
    Derived obj;
    obj.getBase1int(2);
    obj.getBase2int(3);
    obj.getBase3int(6);
    obj.show();
    
    return 0;
}