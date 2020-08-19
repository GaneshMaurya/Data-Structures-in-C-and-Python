#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void Print(struct node * p)
{
    if (p == NULL) {
        return;
    }
    printf("%d ", p->data);
    Print(p->next);
}

void Insert(int data, int position)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    if (position == 1) {
        new->data = data;
        new->next = head;
        head = new;
        return;
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

void Reverse_Print(struct node * p)
{
    if (p == NULL) {
        return;
    }
    Reverse_Print(p->next);    
    printf("%d ", p->data);
}

int main() 
{
    Insert(3,1);
    Insert(2,2);
    Insert(1,3);
    Insert(4,2);
    Print(head);

    printf("\n");
    Reverse_Print(head);
    
    return 0;
}