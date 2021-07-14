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

void printlevel(struct node * root, int level)
{
    if (root == NULL)
    {
        return;
    }

    queue<struct node *> q;
    q.push(root);

    int l = 1;

    while (true)
    {
        int h = q.size();

        if (h == 0 || l > level)
        {
            break;
        }

        while (h > 0)
        {
            struct node * temp = q.front();
            q.pop();

            if (l == level)
            {
                cout<<temp->data<<" ";
            }

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            h--;
        }
        l++;
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

    int level = 3;
    printlevel(root, level);
    
    return 0;
}