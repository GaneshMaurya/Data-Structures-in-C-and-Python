#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int a;
    int b;

    public:
        void setNumber(int n1, int n2)
        {
            a = n1;
            b = n2;
        }
        void printNumber()
        {
            cout<<a<<" + "<<b<<"i\n";
        }
        friend void sumComplex(Complex o1, Complex o2);
};

void sumComplex(Complex o1, Complex o2)
{
    Complex res;
    res.a = o1.a + o2.a;
    res.b = o1.b + o2.b;

    res.printNumber();
}

int main()
{
    Complex c1, c2, sum;
    c1.setNumber(1, 5);
    c1.printNumber();

    c2.setNumber(3, 4);
    c2.printNumber();

    sumComplex(c1, c2);

    return 0;
}