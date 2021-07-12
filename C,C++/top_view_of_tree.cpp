#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct node 
{
    int height;
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

void topView(struct node * root)
{   
    if (root == NULL)
    {
        return;
    }

    queue<struct node *> q;
    map<int, int> m;

    q.push(root);

    while (!q.empty())
    {
        struct node * temp = q.front();
        q.pop();
        m.insert(make_pair(temp->height, temp->data));
        int h = temp->height;

        if (m[h] == 0)
        {
            m.insert(make_pair(h, temp->data));
        }

        if (temp->left != NULL)
        {
            temp->left->height = h-1;
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            temp->right->height = h+1;
            q.push(temp->right);
        }
    }

    map<int, int>:: iterator itr;
    for (itr=m.begin(); itr!=m.end(); itr++)
    {
        cout<<itr->second<<" ";
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

    topView(root);
    
    return 0;
}