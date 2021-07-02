#include <stdio.h>
#include <conio.h>
#define MAX_SIZE 101

int stack[MAX_SIZE];
int top = -1;

void Push(int x)
{
    if (top > MAX_SIZE-1) {
        printf("Overflow \n");
    }
    else {
        stack[++top] = x;
    }
}

void Pop()
{
    if (top == -1) {
        printf("Underflow \n");
        return;
    }
    printf("%d \n", stack[top]);
    top--;
}

int main()
{
    Push(1);
    Push(4);
    Push(2);
    Push(3);
    Pop();

    return 0;
}