#include <iostream>
#include <stack>
using namespace std;

string preToPost(string exp)
{
    stack<string> s;

    for (int i=exp.length()-1; i>=0; i--)
    {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            string x = "";
            x += exp[i];
            s.push(x);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1 + op2 + exp[i];
            s.push(temp);
        }
    }

    return s.top();
}

int main()
{
    string exp = "*-A/BC-/AKL";
    cout<<preToPost(exp);
    return 0;
}