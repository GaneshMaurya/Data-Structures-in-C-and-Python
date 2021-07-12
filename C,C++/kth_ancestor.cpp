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

struct node * temp = NULL;

struct node * kthancestor(struct node * root, int data, int &k)
{
    if (root == NULL)
    {
        return NULL;
    }

    if ((root->data == data) || (temp = kthancestor(root->left, data, k)) || (temp = kthancestor(root->right, data, k)))
    {
        if (k > 0)
        {
            k--;
        }
        else if (k == 0)
        {
            cout<<root->data;
            return NULL;
        }
        return root;
    }      
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

    int k = 2;
    int data = 5;
    struct node * parent = kthancestor(root, data, k);

    if (parent)
    {
        cout<<"-1";
    }
    
    return 0;
}