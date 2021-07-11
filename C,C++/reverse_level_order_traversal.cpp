#include <iostream>
#include <queue>
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

void reverseLevelOrder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }
    else 
    {
        queue<struct node *> q;
        q.push(root);

        stack<int> s;

        while (!q.empty())
        {
            struct node * temp = q.front();
            q.pop();

            s.push(temp->data);

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
        }

        while (!s.empty())
        {
            int x = s.top();
            s.pop();
            cout<<x<<" ";
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
    root->left->left->right = newNode(6);

    reverseLevelOrder(root);
    
    return 0;
}