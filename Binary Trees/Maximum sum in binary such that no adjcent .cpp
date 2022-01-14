#include <bits/stdc++.h>
using namespace std;
  
/* A binary tree node structure */
struct node
{
    int data;
    struct node *left, *right;
};
  
/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int GrandChildSum(node *root,map<node *,int>helper)
{
    if(root==nullptr)
    {
        return 0;

    }
    else
    {
        int sum=0;

        if(root->left)
        {
            sum=GrandChildSum(root->left->left,helper)+GrandChildSum(root->left->right,helper);

        }

        if(root->right)
        {
            sum+=GrandChildSum(root->right->left,helper)+GrandChildSum(root->right->right,helper);

        }

        return sum;

    }

}

int getMaxSumAns(node* root,map<node*,int> &helper)
{
    if(root==nullptr)
    {
        return 0;

    }

    if(helper.find(root)!=helper.end())
    {
        return helper[root];
    }
    else
    {
        int inc=root->data+GrandChildSum(root,helper);
        int exc=getMaxSumAns(root->left,helper)+getMaxSumAns(root->right,helper);

        helper[root]=max(inc,exc);

        return helper[root];

    }

}


int getMaxSum(node *root)
{
    if(root==nullptr)
    {
        return 0;

    }
    map<node *,int>helper;

    return getMaxSumAns(root,helper);

}



int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left = newNode(1);
  
    cout << getMaxSum(root) << endl;
    return 0;
}