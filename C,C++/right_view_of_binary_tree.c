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

int maxlevel = 0;

void rightView(struct node * root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level >= maxlevel)
    {
        printf("%d ", root->data);
        maxlevel++;
    }

    rightView(root->right, level+1);
    rightView(root->left, level+1);
}


int main()
{
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->right = newNode(6);
    
    rightView(root, 0);

    return 0;
}