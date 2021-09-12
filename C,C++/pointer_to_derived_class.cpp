#include <iostream>
using namespace std;

class BaseClass
{
public:
    int var_base;
    void display()
    {
        cout << "Variable in base is : " << var_base << "\n";
    }
};

class DerivedClass : public BaseClass
{
public:
    int var_derived;
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

    b_ptr->var_base = 20;
    b_ptr->display();

    DerivedClass *d_ptr = &d_obj;
    d_ptr->var_base = 105;
    d_ptr->var_derived = 98;
    d_ptr->display();

    return 0;
}