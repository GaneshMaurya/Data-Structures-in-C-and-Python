#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node * front = NULL;
int count = 0;

void enqueue(int data)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));

    if (front == NULL)
    {
        new->data = data;
        new->next = new;
        front = new;
        count++;
    }
    else
    {
        struct node * temp = front;

        while (temp->next != front)
        {
            temp = temp->next;
        }

        new->data = data;
        temp->next = new;
        new->next = front;

        count++;
    }
}

void dequeue()
{
    struct node * temp = front;

    while (temp->next != front)
    {
        temp = temp->next;
    }

    temp->next = front->next;
    temp = front;
    front = front->next;

    count--;

    free(temp);
}

void display()
{
    struct node * temp = front;

    for (int i=0; i<count; i++)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    dequeue();
    dequeue();

    display();
    
    return 0;
}