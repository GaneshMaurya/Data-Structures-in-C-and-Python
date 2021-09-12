#include <iostream>
using namespace std;

class Complex
{
    int real, imaginary;

public:
    void setData(int a, int b)
    {
        real = a;
        imaginary = b;
    }
    void printData()
    {
        cout << "Real = " << real << "\n";
        cout << "Imaginary = " << imaginary << "\n";
    }
};

int main()
{
    // Complex c;
    // Complex * ptr = &c;
    // c.setData(10, 23);
    // c.printData();

    Complex *ptr = new Complex;
    // (*ptr).setData(15, 16);
    // (*ptr).printData();
    ptr->setData(5, 9);
    ptr->printData();

    return 0;
}