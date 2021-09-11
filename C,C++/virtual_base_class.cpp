#include <iostream>
using namespace std;

class Student
{
protected:
    int roll_number;

public:
    void setNumber(int a)
    {
        roll_number = a;
    }
    void printNumber()
    {
        cout << "Roll No.: " << roll_number << "\n";
    }
};

class Test : virtual public Student
{
protected:
    float math, physics;

public:
    void setMarks(float a, float b)
    {
        math = a;
        physics = b;
    }
    void printMarks()
    {
        cout << "Marks are:\n"
             << "Maths: " << math << "\n"
             << "Physics: " << physics << "\n";
    }
};

class Sports : virtual public Student
{
protected:
    float score;

public:
    void setScore(float sc)
    {
        score = sc;
    }
    void printScore()
    {
        cout << "Score is:\n"
             << score << "\n";
    }
};

class Result : public Sports, public Test
{
private:
    float total;

public:
    void display()
    {
        total = math + physics + score;
        printNumber();
        printMarks();
        printScore();
        cout << "Total is = " << total << "\n";
    }
};

int main()
{
    Result r1;
    r1.setMarks(95.8, 100.0);
    r1.setNumber(420);
    r1.setScore(85);
    r1.display();
    
    return 0;
}