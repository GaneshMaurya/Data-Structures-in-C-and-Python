#include <iostream>
using namespace std;

class Media
{
protected:
    string title;
    float price;

public:
    Media(string title, float price)
    {
        this->title = title;
        this->price = price;
    }
    virtual void display() {}
};

class Book : public Media
{
    int pages;

public:
    Book(string title, float price, int pages) : Media(title, price)
    {
        this->pages = pages;
    }
    void display()
    {
        cout << "Title of the Book is - " << title << "\n";
        cout << "Price of the Book is - " << price << "\n";
        cout << "Number of pages in the Book is - " << pages << "\n";
    }
};

class MusicCD : public Media
{
    int time;

public:
    MusicCD(string title, float price, int time) : Media(title, price)
    {
        this->time = time;
    }
    void display()
    {
        cout << "Title of the Music CD is - " << title << "\n";
        cout << "Price of the Music CD is - " << price << "\n";
        cout << "Duration of the Music CD is - " << time << "\n";
    }
};

int main()
{
    Book b("Programming in C++", 650.00, 800);
    MusicCD m("Linkin Park", 500.00, 180);

    Media *list[2];
    list[0] = &b;
    list[1] = &m;

    list[0]->display();
    list[1]->display();

    return 0;
}