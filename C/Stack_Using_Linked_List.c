#include <stdio.h>
#include <conio.h>

struct node 
{
    int data;
    struct node * next;
};

struct node * top = NULL;

void Push(int data)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = top;
    top = new;
}

void Pop()
{
    struct node * temp;
    if (top == NULL) {
        return;
    }
    temp = top;
    top = top->next;
    free(temp);
}

int main()
{
    return 0;
}