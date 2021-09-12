#include <iostream>
using namespace std;

class BaseClass
{
public:
    int var_base = 20;
    virtual void display()
    {
        cout << "Variable in base is : " << var_base << "\n";
    }
};

class DerivedClass : public BaseClass
{
public:
    int var_derived = 30;
    void display()
    {
        cout << "Variable in base is : " << var_base << "\n";
        cout << "Variable in derived is : " << var_derived << "\n";
    }
};

int main()
{
    BaseClass *b_ptr;
    BaseClass b_obj;
    DerivedClass d_obj;
    b_ptr = &d_obj;
    b_ptr->display();

    return 0;
}