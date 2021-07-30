/*
Given a Binary Search Tree(BST), find the second largest element. 
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * insert(struct node * root, int data)
{
    if (root == NULL)
    {
        struct node * temp = (struct node *)malloc(sizeof(struct node));

        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void printTree(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

void secondLargest(struct node * root, int &c)
{
    if (root == NULL || c >= 2)
    {
        return;
    }

    secondLargest(root->right, c);
    c++;

    if (c == 2)
    {
        cout<<root->data;
        return;
    }

    secondLargest(root->left, c);
}


int main()
{
    struct node * root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    printTree(root);
    cout<<"\n";

    int c = 0;
    secondLargest(root, c);

    return 0;
}