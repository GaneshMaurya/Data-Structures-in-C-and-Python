#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    int priority;
    struct node * next;
};

struct node * front = NULL;

void push(int data, int priority)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));

    new->data = data;
    new->priority = priority;
    
    if (front == NULL)
    {
        new->next = NULL;
        front = new;
    }
    else
    {
        struct node * temp = front;

        while (temp->next != NULL && temp->next->priority < priority)
        {
            temp = temp->next;
        }

        new->next = temp->next;
        temp->next = new;
    }
}

void pop()
{
    struct node * temp = front;
    front = front->next;
    free(temp);
}

int peek()
{
    if (front == NULL)
    {
        return -1;
    }
    else
    {
        return front->data;
    }
}

void display()
{
    struct node * temp = front;

    if (front == NULL)
    {
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


int main()
{
    push(2, 0);
    push(3, 1);
    push(4, 3);
    push(1, 2);
    display();
    pop();
    pop();
    printf("\n");
    display();
    push(5,6);
    printf("\n");
    display();
    printf("\n%d", peek());
    
    return 0;
}