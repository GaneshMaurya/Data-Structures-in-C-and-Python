#include <stdio.h>

int top1 = -1;
int top2 = -1;
#define MAX_SIZE 100
int stack1[MAX_SIZE];
int stack2[MAX_SIZE];

void push1(int x)
{
    top1++;
    stack1[top1] = x;
}

int pop1()
{
    int x = stack1[top1]; 
    top1--;
    return x;
}

void push2(int x)
{
    top2++;
    stack2[top2] = x;
}

int pop2()
{
    int x = stack2[top2];
    top2--;
    return x;
}

int peek()
{
    return stack1[top1];
}


int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(int);

    for (int i=0; i<n; i++)
    {
        if (i == 0)
        {
            push1(arr[i]);
        }
        else
        {
            if (arr[i] < peek())
            {
                push1(arr[i]);
            }
            else
            {
                while (arr[i] > peek())
                {
                    push2(pop1());
                    if (top1 == -1)
                    {
                        break;
                    }
                }
                push1(arr[i]);
                while (top2 != -1)
                {
                    push1(pop2());
                }
            }
        }   
    }

    for (int i=0; i<n; i++)
    {
        arr[i] = pop1();
    }

    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}