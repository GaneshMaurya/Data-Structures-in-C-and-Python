#include <iostream>
using namespace std;

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

int findLevel(struct node * root, int data, int level)
{
    if (root == NULL)
    {
        return 0;
    }
    int l;
 
    if (root->data == data)
    {
        return level;
    }

    l = findLevel(root->left, data, level+1);
    
    if (l != 0)
    {
        return l;
    }

    l = findLevel(root->right, data, level+1);
    return l;
}


int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<findLevel(root, 5, 1);
    
    return 0;
}