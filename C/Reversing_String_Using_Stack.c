#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_SIZE 101

char stack[MAX_SIZE];
int top = -1;

void Push(char x)
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
    printf("%c", stack[top]);
    top--;
}

void Reverse(char c[],int n) 
{
    for (int i=0; i<n; i++) {
        Push(c[i]);
    }
    for (int i=0; i<n; i++) {
        Pop();
    }
    
}

int main() 
{
    char c[51];
    printf("Enter a string : ");
    gets(c);

    printf("The reversed string is : ");
    Reverse(c, strlen(c));    
    return 0;
}