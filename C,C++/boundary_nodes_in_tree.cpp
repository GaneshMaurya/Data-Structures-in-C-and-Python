#include <iostream>
#include <queue>
#include <map>
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

void printLeft(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left != NULL)
    {
        cout<<root->data<<" ";
        printLeft(root->left);
    }
    else if (root->right != NULL)
    {
        cout<<root->data<<" ";
        printLeft(root->right);
    }
}

void printLeaf(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    printLeaf(root->left);

    if (root->left == NULL && root->right == NULL)
    {
        cout<<root->data<<" ";
    }

    printLeaf(root->right);
}

void printRight(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->right != NULL)
    {
        cout<<root->data<<" ";
        printRight(root->right);
    }

    else if (root->left != NULL)
    {
        cout<<root->data<<" ";
        printRight(root->left);
    }
}

void boundaryNodes(struct node * root)
{   
    if (root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";

    printLeft(root->left);
    printLeaf(root->left);
    printLeaf(root->right);
    printRight(root->right);
}


int main()
{
    struct node * root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(8);
    root->left->right->left = newNode(5);
    root->left->right->left->left = newNode(10);
    root->right->right = newNode(20);
    root->right->right->right = newNode(25);

    boundaryNodes(root);
    
    return 0;
}