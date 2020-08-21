#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_SIZE 101

char stack[MAX_SIZE];
int top = -1;

void Push(char c)
{
    ++top;
    stack[top] = c;
}

void Pop()
{
    top--;
}

int main()
{
    char c[40];
    printf("Enter the expression : ");
    gets(c);

    for (int i=0; i<strlen(c); i++) {
        if (c[i] == '(' || c[i] == '[' || c[i] == '{') {
            Push(c[i]);
        }
        if (c[i] == ')' || c[i] == ']' || c[i] == '}') {
            Pop();
        }
    }

    if (top == -1) {
        printf("Balanced equation.");
    }
    else {
        printf("Unbalanced equation.");
    }
    
    return 0;
}