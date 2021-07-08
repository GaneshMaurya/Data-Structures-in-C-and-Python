#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int maximum(struct node * root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    int res = root->data;
    int left_max = maximum(root->left);
    int right_max = maximum(root->right);

    int max = res;

    if (left_max > max)
    {
        max = left_max;
    }
    
    if (right_max > max)
    {
        max = right_max;
    }

    return max;
}

int minimum(struct node * root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }

    int res = root->data;
    int left_min = minimum(root->left);
    int right_min = minimum(root->right);

    int min = res;

    if (left_min < min)
    {
        min = left_min;
    }
    
    if (right_min < min)
    {
        min = right_min;
    }

    return min;
}


int main()
{
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 

    printf("%d\n", maximum(root));
    printf("%d\n", minimum(root));
    
    return 0;
}