/*Create a data structure twoStacks that represents two stacks. Implementation of twoStacks should use only one array, i.e., both stacks should use the same array for storing elements. Following functions must be supported by twoStacks.
push1(int x) –> pushes x to first stack 
push2(int x) –> pushes x to second stack
pop1() –> pops an element from first stack and return the popped element 
pop2() –> pops an element from second stack and return the popped element
Implementation of twoStack should be space efficient.*/

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100
int arr[MAX_SIZE];
int top1 = -1;
int top2 = MAX_SIZE;

void push1(int data)
{
    if (abs(top1 - top2) == 1)
    {
        printf("Overflow in stack 1");
        return;
    }
    top1++;
    arr[top1] = data;
}

void push2(int data)
{
    if (abs(top1 - top2) == 1)
    {
        printf("Overflow in stack 2");
        return;
    }
    top2--;
    arr[top1] = data;
}

int pop1()
{
    if (top1 <= -1)
    {
        printf("Underflow for stack1");
        return;
    }
    int x = arr[top1];
    top1--;
    return x;
}

int pop2()
{
    if (top2 >= MAX_SIZE)
    {
        printf("Underflow for stack2");
        return;
    }
    int x = arr[top2];
    top2++;
    return x;
}

int main()
{
    return 0;
}