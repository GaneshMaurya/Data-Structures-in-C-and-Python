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

void maxWidth(struct node * root)
{
    if (root == NULL)
    {
        return;
    }

    queue<struct node *> q;
    q.push(root);

    int max = -1;

    while (true)
    {
        int width = q.size();
        if (width == 0)
        {
            break;
        }

        while (width > 0)
        {
            struct node * temp = q.front();
            q.pop();

            if (width > max)
            {
                max = width;
            }

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            width--;
        }
    }

    cout<<max;
}


int main()
{
    struct node * root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->left = newNode(12);
    root->left->right = newNode(6);
    root->left->right->left = newNode(5);
    root->left->right->right = newNode(11);
    root->right->right = newNode(9);
    root->right->right->left = newNode(4);
    root->right->right->right = newNode(40);

    maxWidth(root);
    
    return 0;
}