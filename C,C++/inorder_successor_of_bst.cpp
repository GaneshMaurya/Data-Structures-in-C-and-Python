/*
In Binary Tree, Inorder successor of a node is the next node in Inorder traversal of the Binary Tree. 
Inorder Successor is NULL for the last node in Inorder traversal. 
In Binary Search Tree, Inorder Successor of an input node can also be defined as the 
node with the smallest key greater than the key of the input node. 
So, it is sometimes important to find next node in sorted order.
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

struct node * search(struct node * root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == val)
    {
        return root;
    }
    else if (root->data > val)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

struct node * findMin(struct node * root)
{
    if (root == NULL)
    {
        return NULL;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

struct node * inorderSuccessor(struct node * root, int val)
{
    struct node * current = search(root, val);

    if (current == NULL)
    {
        return NULL;
    }
    
    if (current->right != NULL)
    {
        return findMin(current->right);
    }
    else
    {
        struct node * successor = NULL;
        struct node * ancestor = root;

        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}   


int main()
{
    struct node * root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    printTree(root);
    cout<<"\n";

    cout<<inorderSuccessor(root, 2)->data;

    return 0;
}