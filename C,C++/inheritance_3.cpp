#include <iostream>
using namespace std;

class Student
{
protected:
    int roll_number;

public:
    void setNumber(int);
    void getNumber();
};

void Student :: setNumber(int r)
{
    roll_number = r;
}

void Student :: getNumber()
{
    cout<<roll_number<<"\n";
}

class Exam : public Student
{
protected:
    float maths;
    float physics;
public:
    void setMarks(float, float);
    void getMarks();
};

void Exam :: setMarks(float m, float p)
{
    maths = m;
    physics = p;
}

void Exam :: getMarks()
{
    cout<<maths<<"\n";
    cout<<physics<<"\n";
}

class Result : public Exam
{
    float percent;
public:
    void display();
};

void Result :: display()
{
    getNumber();
    getMarks();
    percent = (maths+physics)/2;
    cout<<percent<<"%"<<"\n";
}

int main()
{
    Result per;
    per.setNumber(1);
    per.setMarks(90.0, 85.0);
    per.display();
    
    return 0;
}