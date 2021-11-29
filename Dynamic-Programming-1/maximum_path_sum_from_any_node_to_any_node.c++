#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->value = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int maxPathSumFromAnyNodeToAnyNode(Node *root, int &result)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = maxPathSumFromAnyNodeToAnyNode(root->left, result);
    int r = maxPathSumFromAnyNodeToAnyNode(root->right, result);

    int tempAns = max(max(l, r) + root->value, root->value);
    int ans = max(tempAns, l + r + root->value);
    result = max(result, ans);

    return tempAns;
}

int maxPathSumFromAnyNodeToAnyNodeUtil(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = INT_MIN;
    maxPathSumFromAnyNodeToAnyNode(root, ans);
    return ans;
}

int main()
{
    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Maximum path sum from any node to any node is " << maxPathSumFromAnyNodeToAnyNodeUtil(root);

    return 0;
}