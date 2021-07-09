#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<string> s;

    s.insert("abc");
    s.insert("xyz");
    s.insert("pqr");

    set<string>:: iterator itr;

    for (itr = s.begin(); itr != s.end(); itr++)
    {
        cout<<*itr<<endl;
    }
}