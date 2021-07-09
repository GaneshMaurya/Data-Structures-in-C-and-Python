#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    m["abc"] = 5;
    m["def"] = 3;
    m["efg"] = 1;

    m.insert(make_pair("hij", 2));
    m.insert({"klm", 4});

    map<string, int>:: iterator itr;

    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }

    cout<<m.at("def")<<endl;
    
    auto it = m.begin();
    cout<<it->first<<" "<<it->second<<endl;

    cout<<m.count("klm")<<endl;
    
    return 0;
}