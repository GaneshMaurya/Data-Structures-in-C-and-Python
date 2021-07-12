#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node  * newNode(int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void inorder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

struct node * deleteTree(struct node * root)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    root->left = deleteTree(root->left);
    root->right = deleteTree(root->right);
    
    root = NULL;
    return root;
}


int main()
{
    struct node * root = newNode(1);
    root->left  = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    inorder(root);
    cout<<endl;
    root = deleteTree(root);
    inorder(root);
    
    return 0;
}