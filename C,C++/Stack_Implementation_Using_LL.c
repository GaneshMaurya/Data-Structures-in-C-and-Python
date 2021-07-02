#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
};

struct node * top = NULL;

void push(int data)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = data;

    if (top == NULL)
    {
        top = new;
        top->next = NULL;
    }
    else
    {
        new->next = top;
        top = new;
    }
}

int isEmpty()
{
    return top == NULL;
}

int peek()
{
    if (!isEmpty())
    {
        return top->data;
    }
    else
    {
        exit(0);
    }
}

void pop()
{
    struct node * temp;

    if (isEmpty())
    {
        printf("Underflow");
    }
    temp = top;
    top = top->next;
    temp->next = NULL;

    free(temp);
}

void display()
{
    struct node * temp;

    if (top == NULL)
    {
        return;
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            int x = temp->data;
            printf("%d ", x);
            temp = temp->next;
        }
    }
    printf("\n");
}


int main()
{
    push(1);
    push(2);
    push(3);
    push(4);

    display();

    pop();
    pop();

    display();
    
    return 0;
}