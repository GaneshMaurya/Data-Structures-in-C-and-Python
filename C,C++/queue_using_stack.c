#include <stdio.h>

#define MAX_SIZE 100
int top1 = -1;
int top2 = -1;
int stack1[MAX_SIZE];
int stack2[MAX_SIZE];

void push1(int data)
{
    top1++;
    stack1[top1] = data;
}

void push2(int data)
{
    top2++;
    stack2[top2] = data;
}

int pop1()
{
    return stack1[top1--];
}

int pop2()
{
    return stack2[top2--];
}

void enqueue(int data)
{
    push1(data);
}

void dequeue()
{
    while (top1 != -1)
    {
        push2(pop1());
    }

    pop2();

    while (top2 != -1)
    {
        push1(pop2());
    }
}   

void display()
{
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", stack1[i]);
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    dequeue();
    dequeue();

    display();
    
    return 0;
}