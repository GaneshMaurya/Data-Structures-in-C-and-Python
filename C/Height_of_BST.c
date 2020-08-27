#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * GetNewNode(int data)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
    
}

struct node * Insert(struct node * root, int data)
{   
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    
    return root;
}

bool Search(struct node * root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else 
    {
        return Search(root->right, data);
    }
}

int Height(struct node * root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);
        if (leftHeight > rightHeight)
        {
            return leftHeight+1;
        }
        else 
        {
            return rightHeight+1;
        }
    }
    
}

int main()
{
    struct node * root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 35);
    root = Insert(root, 5);
    root = Insert(root, 25);
    
    int height = Height(root);
    printf("The height of the tree is : %d\n", height);

    return 0;
}