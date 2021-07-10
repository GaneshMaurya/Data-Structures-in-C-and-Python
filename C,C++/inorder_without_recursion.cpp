#include <iostream>
#include <stack>
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

void inorderWithoutRecur(struct node * root)
{
    struct node * current = root;
    stack<struct node *> s;

    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout<<current->data<<" ";
        current = current->right;
    }
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


int main()
{
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    inorderWithoutRecur(root);
    cout<<endl;
    inorder(root);
    
    return 0;
}