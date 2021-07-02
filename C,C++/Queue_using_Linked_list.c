#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
};

struct node * head = NULL;
struct node * rear = NULL;

void Enqueue(int x)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;
    if ((head == NULL) && (rear == NULL))
    {
        head = rear = new;
    }
    else 
    {
        rear->next = new;
        rear = new;
    }
}

void Dequeue()
{
    struct node * temp = head;
    if (head == NULL)
    {
        printf("Dequeue operation cannot be performed.");
        return;
    }
    if (head == rear)
    {
        head = rear = NULL;
    }
    else 
    {
        head = head->next;
    }
    free(temp);
}

void Print() {
	struct node * temp = head;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
    Enqueue(2); 
    Print(); 
	Enqueue(4); 
    Print();
	Enqueue(6); 
    Print();
	Dequeue();  
    Print();
	Enqueue(8); 
    Print();

    return 0;
}