#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * newNode(int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int differenceAtEvenOdd(struct node * root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (root->data - differenceAtEvenOdd(root->left) - differenceAtEvenOdd(root->right));
    }
}


int main()
{
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->right = newNode(3);
    root->left->right = newNode(5);

    printf("%d", differenceAtEvenOdd(root));

    return 0;
}