#include <iostream>
using namespace std;

bool isRotatedVersion(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }
    
    string temp = str1 + str1;

    return (temp.find(str2) != string::npos);
}


int main()
{
    string str1 = "abcd";
    string str2 = "dabc";

    if (isRotatedVersion(str1, str2))
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    
    return 0;
}