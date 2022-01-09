void printLeaves(Node* root,vector<int> &ans)
{
    if (root == NULL)
        return;

    printLeaves(root->left,ans);

    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
        ans.push_back(root->data);

    printLeaves(root->right,ans);
}

// A function to print all left boundary nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printBoundaryLeft(Node* root,vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left) {

        // to ensure top down order, print the node
        // before calling itself for left subtree
        ans.push_back(root->data);
        printBoundaryLeft(root->left,ans);
    }
    else if (root->right) {
        ans.push_back(root->data);
        printBoundaryLeft(root->right,ans);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(Node* root,vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->right) {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        printBoundaryRight(root->right,ans);
        ans.push_back(root->data);
    }
    else if (root->left) {
        printBoundaryRight(root->left,ans);
        ans.push_back(root->data);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// A function to do boundary traversal of a given binary tree
vector <int> boundary(Node *root)
    {
        //Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;

    cout<< root->data << " ";

    // Print the left boundary in top-down manner.
    printBoundaryLeft(root->left,ans);

    // Print all leaf nodes
    printLeaves(root->left,ans);
    printLeaves(root->right,ans);
    // Print the right boundary in bottom-up manner
    printBoundaryRight(root->right,ans);
        return ans;
    }
