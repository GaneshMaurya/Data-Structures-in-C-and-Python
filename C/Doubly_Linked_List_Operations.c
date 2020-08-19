#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

void Print()
{
    struct node* temp = head;
    printf("List is : \n");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Reverse_Print()
{
    struct node* temp = head;
    printf("Reverse of List is : \n");
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void Insert(int data, int position)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    if (position == 1) {
        new->data = data;
        new->next = NULL;
        new->prev = NULL;
        head = new;
    }
    else {
        new->data = data;
        struct node * temp = head;
        for (int i=0; i<position-2; i++) {
            temp = temp->next;
        }
        new->prev = temp;
        new->next = temp->next;
        if (temp->next != NULL) {
            (temp->next)->prev = new;
        }
        temp->next = new;
    }
}

int main()
{
    Insert(3,1);
    Insert(2,2);
    Insert(1,3);
    Insert(4,2);
    Print();
    Reverse_Print();

    return 0;
}