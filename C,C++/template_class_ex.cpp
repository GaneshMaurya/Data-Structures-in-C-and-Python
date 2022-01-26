#include <bits/stdc++.h>
using namespace std;

template <class T>
class Arithmetic
{
    T a;
    T b;

public:
    Arithmetic(T a, T b);
    T add();
    T multiply();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
    return a + b;
}

template <class T>
T Arithmetic<T>::multiply()
{
    return a * b;
}

int main()
{
    Arithmetic<float> E(10.5, 12.99);
    cout << E.add() << endl;
    cout << E.multiply() << endl;

    return 0;
}