#include <iostream>
using namespace std;

class Shop
{
    int id;
    float price;
    public:
        void setData(int a, float b)
        {
            id = a;
            price = b;
        }
        void printData()
        {
            cout<<"ID : "<<id<<"\n";
            cout<<"Price : "<<price<<"\n";
        }
};

int main()
{
    int size = 3;
    Shop * ptr = new Shop[size];
    // ptr->setData(5, 23.0);
    // ptr->printData();

    // (ptr+1)->setData(6, 35.5);
    // (ptr+1)->printData();

    // ptr[2].setData(7, 15);
    // ptr[1].printData();

    // *(ptr+3).setData(8, 100);
    // *(ptr+3).printData();
    
    Shop * temp = ptr;
    for (int i=0; i<size; i++)
    {
        int a;
        float b;
        cout<<"Enter ID and Price of Item-"<<i+1<<": \n";
        cin>>a>>b;
        temp->setData(a, b);
        temp++;
    }

    temp = ptr;
    for (int i=0; i<size; i++)
    {
        temp->printData();
        temp++;
    }

    return 0;
}