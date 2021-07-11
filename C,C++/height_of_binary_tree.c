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

int heightOfTree(struct node * root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    else 
    {
        if (heightOfTree(root->left) > heightOfTree(root->right))
        {
            return (heightOfTree(root->left) + 1);
        }
        else
        {
            return (heightOfTree(root->right) + 1);
        }
    }
}


int main()
{
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->right = newNode(6);

    printf("%d", heightOfTree(root));
    
    return 0;
}