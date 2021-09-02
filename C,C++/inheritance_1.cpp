#include <bits/stdc++.h>
using namespace std;

class Employee
{
    public:
        string name;
        int id;
        float salary;
        
        Employee(){}

        Employee (string inpname, int inpid, float inpsalary)
        {
            name = inpname;
            id = inpid;
            salary = inpsalary;
        }
        
        void display ()
        {
            cout<<name<<" "<<id<<" "<<salary<<"\n";
        }
};

class Programmer : public Employee
{
    public:
        int languageCode;
        Programmer (string inpname, int inpid, float inpsalary)
        {
            name = inpname;
            id = inpid;
            salary = inpsalary;
            languageCode = 9;
        }
};

int main()
{
    Employee per1 = Employee("A", 1, 30);
    Employee per2 = Employee("B", 2, 50);
    Programmer per3 = Programmer("C", 3, 25);
    
    per1.display();
    per2.display();
    per3.display();

    return 0;
}