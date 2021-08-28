#include <bits/stdc++.h>
using namespace std;

class Complex;

class Calculator
{
    public:
        int sumReal(Complex, Complex);
        int sumComp(Complex, Complex);
};

class Complex
{
    int a;
    int b;
    public:
        friend class Calculator;
        void getNumbers(int n1, int n2)
        {
            a = n1;
            b = n2;
        }
};

int Calculator::sumReal(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int Calculator::sumComp(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}


int main()
{
    Complex c1, c2;
    c1.getNumbers(5, 4);
    c2.getNumbers(6, 2);

    Calculator calc;
    int ans1 = calc.sumReal(c1, c2);
    cout<<ans1<<" + ";
    int ans2 = calc.sumComp(c1, c2);
    cout<<ans2<<"i";
    
    return 0;
}