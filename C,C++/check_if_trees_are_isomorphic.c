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

bool isIsomorphic(struct node * root1, struct node * root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else if (root1->data != root2->data)
    {
        return false;
    }
    else
    {
        return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) 
                || (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
    }
}


int main()
{
    struct node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);

    struct node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->right = newNode(4);

    if(isIsomorphic(root1, root2))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    
    return 0;
}