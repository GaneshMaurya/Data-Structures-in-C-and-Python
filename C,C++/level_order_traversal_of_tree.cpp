#include <iostream>
#include <queue>
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

void levelOrder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }
    
    queue <struct node *> q;

    q.push(root);

    while (!q.empty())
    {
        struct node * temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}


int main()
{   
    struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    levelOrder(root);
    
    return 0;
}