#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void Insert(int data)
{
    struct node* new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = head;
    head = new;
}

void Print()
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("List is : ");
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n;
    printf("How many numbers : ");
    scanf("%d", &n);

    for (int i=0; i<n ; i++)
    {
        int x;
        printf("Enter number to be inserted : ");
        scanf("%d", &x);
        Insert(x);
        Print();
    }

    return 0;
}
