#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head;

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

void Insert(int data, int position)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    if (position == 1) {
        new->data = data;
        new->next = head;
        head = new;
    }
    else {
        new->data = data;
        struct node * temp = head;
        for (int i=0; i<position-2; i++) {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
}

void Reverse(struct node * p)
{
    if (p->next == NULL) {
        head = p;
        return;
    }
    Reverse(p->next);
    struct node* q = p->next;
    q->next = p;
    p->next = NULL;
}

int main() 
{
    Insert(3,1);
    Insert(2,2);
    Insert(1,3);
    Insert(4,2);
    Print();

    Reverse(head);
    Print();

    return 0;
}