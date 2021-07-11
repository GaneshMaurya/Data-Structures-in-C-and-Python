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

void nodeAtLevel(struct node * root, int level)
{
    if (root == NULL)
    {
        return;
    }
    
    if (level == 1)
    {
        printf("%d ", root->data);
        return;
    }

    nodeAtLevel(root->left, level-1);
    nodeAtLevel(root->right, level-1);
}


int main()
{
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->right = newNode(6);

    nodeAtLevel(root, 4);
    
    return 0;
}