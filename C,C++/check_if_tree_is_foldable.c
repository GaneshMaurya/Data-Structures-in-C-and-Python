#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isMirrorStructure(struct node * root1, struct node * root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        return isMirrorStructure(root1->left, root2->right) && isMirrorStructure(root1->right, root2->left);
    }
}

bool isFoldable(struct node * root)
{
    if (root == NULL)
    {
        return true;
    }

    return isMirrorStructure(root->left, root->right);
}


int main()
{
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->right->right = newNode(8);   

    if(isFoldable(root))
    {
        printf("True");
    } 
    else
    {
        printf("False");
    }
    
    return 0;
}