#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct node
{
    int data;
    int height;
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

void getVerticalSum(struct node * root)
{   
    if (root == NULL)
    {
        return;
    }
    
    queue<struct node *> q;
    q.push(root);

    map<int, int> m;

    while (!q.empty())
    {
        struct node * temp = q.front();
        q.pop();
        int h = temp->height;

        if (m.find(h) == m.end())
        {
            m.insert(make_pair(h, temp->data));
        }
        else
        {
            auto it = m.find(h);

            if (it != m.end())
            {
                it->second += temp->data;
            }
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

    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout<<itr->second<<endl;
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
    
    getVerticalSum(root);

    return 0;
}