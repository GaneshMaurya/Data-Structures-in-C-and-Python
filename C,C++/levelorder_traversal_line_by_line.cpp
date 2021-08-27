#include <bits/stdc++.h>
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

struct node * insertNode(struct node * root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    else
    {
        queue<struct node *> q;
        q.push(root);

        while (!q.empty())
        {
            struct node * temp = q.front();
            q.pop();

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            else
            {
                temp->left = newNode(data);
                return root;
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            else
            {
                temp->right = newNode(data);
                return root;
            }
        }

        return root;
    }
}

void inorder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

        return;
    }
}

void levelorderLinebyLine(struct node * root)
{
    if (root == NULL)
    {
        return;
    }
    else 
    {
        queue<struct node *> q;
        q.push(root);
        q.push(NULL);

        while (q.size() > 1)
        {
            struct node * temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                q.push(NULL);
                cout<<"\n";
            }
            else
            {
                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }

                cout<<temp->data<<" ";
            }
        }
    }
}


int main()
{
    struct node * root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 60);

    inorder(root);
    cout<<"\n";
    levelorderLinebyLine(root);

    return 0;
}