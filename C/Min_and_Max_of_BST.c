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

int FindMin(struct node * root)
{
    if (root == NULL)
    {
        printf("Error : Tree is empty");
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    else 
    {
        FindMin(root->left);
    } 
}

int FindMax(struct node * root)
{
    if (root == NULL)
    {
        printf("Error : Tree is empty");
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    else 
    {
        FindMax(root->right);
    } 
}

int main()
{
    struct node * root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);

    int x = 30;
    if (Search(root, x))
    {
        printf("Found.\n");
    }
    else 
    {
        printf("Not Found.\n");
    }

    root = Insert(root, 6);
    root = Insert(root, 25);
    root = Insert(root, 0);

    int minimum;
    minimum = FindMin(root);

    printf("Minimum of the BST is : %d\n", minimum);

    int maximum;
    maximum = FindMax(root);

    printf("Maximum of the BST is : %d\n", maximum);

    root = Insert(root, -35);
    root = Insert(root, 40);
    root = Insert(root, 8);

    int minimum2;
    minimum2 = FindMin(root);

    printf("Minimum of the BST is : %d\n", minimum2);

    int maximum2;
    maximum2 = FindMax(root);

    printf("Maximum of the BST is : %d\n", maximum2);

    return 0;
}