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

void spiral(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    stack<struct node *> s1, s2;
    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            struct node * temp = s1.top();
            cout<<temp->data<<" ";
            s1.pop();

            if (temp->right != NULL)
            {
                s2.push(temp->right);
            }

            if (temp->left != NULL)
            {
                s2.push(temp->left);
            }
        }
        cout<<endl;

        while (!s2.empty())
        {
            struct node * temp = s2.top();
            cout<<temp->data<<" ";
            s2.pop();

            if (temp->left != NULL)
            {
                s1.push(temp->left);
            }

            if (temp->right != NULL)
            {
                s1.push(temp->right);
            }
        }
        cout<<endl;
    }
}


int main()
{
    struct node * root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left = newNode(5);
    root->left->right->left->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->right = newNode(9);
    
    spiral(root);

    return 0;
}