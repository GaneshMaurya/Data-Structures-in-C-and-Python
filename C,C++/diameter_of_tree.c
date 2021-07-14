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

int maximum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int getDiameter(struct node * root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int lh = getDiameter(root->left);
    int rh = getDiameter(root->right);

    int diameter = maximum(diameter, lh+rh+1);

    return maximum(lh, rh) + 1;
}

int main()
{
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->right->right = newNode(8);   

    printf("%d", getDiameter(root));
    
    return 0;
}